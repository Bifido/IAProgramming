#include "MyAStar.h"

#include <algorithm>

void MyAStar::Initialize()
{
	//int initial[] = { 13, 5, 14, 11, 12, 15, 7, 2, 1, 10, 3, 9, 8, 6, 4, 0 };
	//int initial[] = { 1, 2, 4, 8, 5, 0, 7, 12, 10, 6, 3, 11, 9, 13, 14, 15};
	int initial[] = { 1, 0, 15, 7, 5, 11, 4, 3, 12, 2, 13, 14, 10, 9, 6, 8};

	ChessConfiguration* root = new ChessConfiguration(initial);
	AddToOpenList(root);
}

void MyAStar::Run()
{
	ChessConfiguration* analize;
	analize = m_openList.back();
	m_closedList.push_back(analize);
	m_openList.pop_back();

	while (analize != nullptr && analize->GetH() != 0)
	{
		std::cout << std::endl << std::setw(2) << "Analize: F= " << analize->GetF() << " G= " << std::setw(2) << analize->GetG() << " H= " << analize->GetH();
		//analize->Print();

		ComputeAdj(analize);

		if (!m_openList.empty())
		{
			analize = m_openList.back();
			m_openList.pop_back();
			m_closedList.push_back(analize);
		}
		else
		{
			analize = nullptr;
		}
	}

	PrintSolution(analize);
	Clear();

}

void MyAStar::ComputeAdj(ChessConfiguration* node)
{
	int* possMoves = new int[4];
	int numPossMoves = node->GetPossibleMoves(possMoves);
	//std::cout << std::endl << "Compute " << numPossMoves << " moves";
	for (; numPossMoves > 0; --numPossMoves)
	{
		ChessConfiguration* adj = new ChessConfiguration(*node);
		adj->Move(possMoves[numPossMoves - 1]);
		adj->SetG(node->GetG() + 1);
		adj->SetParent(node);
		InsertOrUpdateG(adj);
	}
}

void MyAStar::InsertOrUpdateG(ChessConfiguration* obj)
{
	bool alreadyClosed = false;
	std::list<ChessConfiguration*>::iterator it = m_closedList.begin();
	for (; it != m_closedList.end(); ++it)
	{
		if ((*it)->Equal(*obj))
		{
			alreadyClosed = true;
		}
	}

	if (!alreadyClosed)
	{
		std::list<ChessConfiguration*>::iterator it = m_openList.begin();
		for (; it != m_openList.end(); ++it)
		{
			if ((*it)->Equal(*obj))
			{
				(*it)->UpdateG(obj->GetG());
				break;
			}
		}

		if (it == m_openList.end())
		{
			AddToOpenList(obj);
		}
	}
}

void MyAStar::Clear()
{
	m_openList.clear();
	m_closedList.clear();
}


void MyAStar::AddToOpenList(ChessConfiguration* node)
{
	if (m_openList.empty())
		m_openList.push_back(node);
	else
	{
		bool insert = false;
		std::list<ChessConfiguration*>::iterator it = m_openList.begin();
		for (; it != m_openList.end(); ++it)
		{
			if ((node)->GreaterFThan(**it))
			{
				m_openList.insert(it, node);
				insert = true;
				break;
			}
		}

		if (!insert && it == m_openList.end())
		{
			m_openList.push_back(node);
		}
	}

	//m_openList.insert(std::upper_bound(m_openList.begin(), m_openList.end(), node, m_comparator),
	//	node);
}

void MyAStar::PrintSolution(ChessConfiguration* sol)
{
	std::vector<ChessConfiguration*> solutionList;

	while (sol != nullptr)
	{
		solutionList.push_back(sol);
		sol = sol->SetParent();
	}

	std::cout << std::endl << std::endl << "SOLUTION: in " << solutionList.size() << " moves" <<  std::endl;
	std::vector<ChessConfiguration*>::iterator it = solutionList.end() -1;
	for (; it != solutionList.begin(); --it)
	{
		(*it)->Print();
	}
	(*it)->Print();
	std::cout << std::endl << std::endl << "SOLUTION: in " << solutionList.size() << " moves" << std::endl;
}
