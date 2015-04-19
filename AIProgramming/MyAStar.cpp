#include "MyAStar.h"

//#include <algorithm>

void MyAStar::Initialize()
{
	//int initial[] = { 15, 6, 3, 4, 1, 0, 7, 14, 12, 2, 5, 11, 10, 9, 13, 8 };
	int initial[] = { 1, 0, 15, 7, 5, 11, 4, 3, 12, 2, 13, 14, 10, 9, 6, 8};

	ChessConfiguration* root = new ChessConfiguration(initial);
	AddToOpenList(root);

	m_closedMap = new std::unordered_map <std::string, int>();
}

void MyAStar::Run()
{
	ChessConfiguration* analize;
	analize = m_openList.back();
	//m_closedList.push_back(analize);
	(*m_closedMap)[analize->GetHash()] = analize->GetF();
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
			//m_closedList.push_back(analize);
			(*m_closedMap)[analize->GetHash()] = analize->GetF();
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
	//std::list<ChessConfiguration*>::iterator it = m_closedList.begin();
	//for (; it != m_closedList.end(); ++it)
	//{
	//	if ((*it)->Equal(*obj))
	//	{
	//		alreadyClosed = true;
	//	}
	//}

	if ((*m_closedMap).count(obj->GetHash()) != 0)
		alreadyClosed = true;

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
	std::list<ChessConfiguration*>::iterator it = m_closedList.begin();
	std::list<ChessConfiguration*>::iterator end = m_closedList.end();
	for (; it != end; ++it)
	{
		delete *it;
	}

	std::list<ChessConfiguration*>::iterator it2 = m_openList.begin();
	std::list<ChessConfiguration*>::iterator end2 = m_openList.end();
	for (; it2 != end2; ++it2)
	{
		delete *it2;
	}
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
	if (sol != nullptr){
		std::vector<ChessConfiguration*> solutionList;

		while (sol != nullptr)
		{
			solutionList.push_back(sol);
			sol = sol->SetParent();
		}

		std::cout << std::endl << std::endl << "SOLUTION: in " << solutionList.size() << " moves" << std::endl;
		std::vector<ChessConfiguration*>::iterator it = solutionList.end() - 1;
		for (; it != solutionList.begin(); --it)
		{
			(*it)->Print();
		}
		(*it)->Print();
		std::cout << std::endl << std::endl << "SOLUTION: in " << solutionList.size() << " moves" << std::endl;
		std::cout << "Open: " << m_openList.size() << " Closed: " << m_closedMap->size();
	}
	else
	{
		std::cout << std::endl << std::endl << "NO SOLUTION" << std::endl;
	}
}
