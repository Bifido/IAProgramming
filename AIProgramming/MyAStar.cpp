#include "MyAStar.h"

//#include <algorithm>

void MyAStar::Initialize()
{
	//int initial[] = { 15, 6, 3, 4, 1, 0, 7, 14, 12, 2, 5, 11, 10, 9, 13, 8 };
	//int initial[] = { 1, 0, 15, 7, 5, 11, 4, 3, 12, 2, 13, 14, 10, 9, 6, 8};

	//ChessConfiguration* root = new ChessConfiguration(initial);
	//AddToOpenList(root);

	m_closedMap = new std::unordered_map <std::string, int>();
	m_openChessMap = new std::unordered_map <std::string, ChessConfiguration>();
}

void MyAStar::Run()
{
	m_time = time(NULL);
	int initial[] = { 1, 0, 15, 7, 5, 11, 4, 3, 12, 2, 13, 14, 10, 9, 6, 8 };
	//int initial[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 0, 13, 14, 15 };
	ChessConfiguration analize(initial);// (m_openList.back());
	//analize = m_openList.back();
	//m_closedList.push_back(analize);
	//(*m_closedMap)[analize.GetHash()] = analize.GetF();
	m_openList.push_back(analize.GetHash());
	(*m_openChessMap)[analize.GetHash()] = analize;

	do
	{
		analize = (*m_openChessMap)[m_openList.back()];
		//m_openChessMap.[m_openList.back()];
		m_openList.pop_back();
		//m_closedList.push_back(analize);
		(*m_closedMap)[analize.GetHash()] = analize.GetF();

		std::cout << std::endl << std::setw(2) << "Analize: F= " << analize.GetF() << " G= " << std::setw(2) << analize.GetG() << " H= " << analize.GetH();
		//analize.Print();

		ComputeAdj(analize);
	} while (!m_openList.empty() && analize.GetH() != 0);

	PrintSolution(analize);
	Clear();

}

void MyAStar::ComputeAdj(ChessConfiguration& node)
{
	int* possMoves = new int[4];
	int numPossMoves = node.GetPossibleMoves(possMoves);
	//std::cout << std::endl << "Compute " << numPossMoves << " moves";
	for (; numPossMoves > 0; --numPossMoves)
	{
		ChessConfiguration adj(node, possMoves[numPossMoves - 1]);
		//adj.Print();
		//adj.Move();
		adj.SetG(node.GetG() + 1);
		//adj.SetParent(&node);
		InsertOrUpdateG(adj);
	}
}

void MyAStar::InsertOrUpdateG(ChessConfiguration& obj)
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

	if ((*m_closedMap).count(obj.GetHash()) != 0)
		alreadyClosed = true;

	if (!alreadyClosed)
	{
		if ((*m_openChessMap).count(obj.GetHash()) != 0)
		{
			(*m_openChessMap)[obj.GetHash()].UpdateG(obj.GetG(), obj.GetParent());
		}
		else
		{
			AddToOpenList(obj);
		}
		//std::vector<ChessConfiguration>::iterator it = m_openList.begin();
		//for (; it != m_openList.end(); ++it)
		//{
		//	if ((*it).Equal(obj))
		//	{
		//		(*it).UpdateG(obj.GetG());
		//		break;
		//	}
		//}

		//if (it == m_openList.end())
		//{
		//	AddToOpenList(obj);
		//}
	}
}

void MyAStar::Clear()
{
	//std::list<ChessConfiguration*>::iterator it = m_closedList.begin();
	//std::list<ChessConfiguration*>::iterator end = m_closedList.end();
	//for (; it != end; ++it)
	//{
	//	delete *it;
	//}

	m_closedMap->clear();
	m_openChessMap->clear();
	m_openList.clear();
	//std::vector<ChessConfiguration*>::iterator it2 = m_openList.begin();
	//std::vector<ChessConfiguration*>::iterator end2 = m_openList.end();
	//for (; it2 != end2; ++it2)
	//{
	//	delete *it2;
	//}
}


void MyAStar::AddToOpenList(ChessConfiguration& node)
{
	if (m_openList.empty()){
		m_openList.push_back(node.GetHash());
	}
	else
	{
		bool insert = false;
		std::vector<std::string>::iterator it = m_openList.begin();
		for (; it != m_openList.end(); ++it)
		{
			if ((node).GreaterFThan((*m_openChessMap)[*it]))
			{
				m_openList.insert(it, node.GetHash());
				insert = true;
				break;
			}
		}

		if (!insert && it == m_openList.end())
		{
			m_openList.push_back(node.GetHash());
		}
	}

	(*m_openChessMap)[node.GetHash()] = node;

	//m_openList.insert(std::upper_bound(m_openList.begin(), m_openList.end(), node, m_comparator),
	//	node);
}

void MyAStar::PrintSolution(ChessConfiguration& sol)
{
	//std::vector<ChessConfiguration*> solution;
	//ChessConfiguration* solIt = &sol;
	//while (solIt!= nullptr)
	//{
	//	solution.push_back(solIt);
	//	solIt = (*m_openChessMap)[solIt->GetParent()].GetHash();
	//}
	//if (sol != nullptr){
	std::string solHash = sol.GetHash();
	std::vector<std::string> solutionList;
	solutionList.push_back(solHash);

	while (!(*m_openChessMap)[solHash].GetParent().empty())
	{
		ChessConfiguration a;
		a = (*m_openChessMap)[solHash];
		//a.Print();
		solHash = a.GetParent();
		solutionList.push_back(solHash);
		//std::cout << std::endl << solHash.c_str();
	}

	std::cout << std::endl << std::endl << "SOLUTION: in " << solutionList.size() << " moves" << std::endl;
	std::vector<std::string>::iterator it = solutionList.end() - 1;
	for (; it != solutionList.begin(); --it)
	{
		(*m_openChessMap)[(*it)].Print();
		//(*it)->Print();
	}
	(*m_openChessMap)[(*it)].Print();
	//(*it)->Print();
	std::cout << std::endl << std::endl << "SOLUTION: in " << solutionList.size() << " moves" << std::endl;
	std::cout << "Open: " << m_openList.size() << " Closed: " << m_closedMap->size();
	std::cout << std::endl << "TIME: " << difftime(time(NULL), m_time) << " sec";
	//}
	//else
	//{
		//std::cout << std::endl << std::endl << "NO SOLUTION" << std::endl;
	//}
}
