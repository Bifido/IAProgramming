#include <iostream>
#include "AStar.h"
using namespace std;

void AStar::Run(){

	endFound = false;

	root = new Node();
	root->ComputeF();
	cout << "ROOT" << endl;
	AddNodeToOpenList(root);

	cout << "\n\n" << endl;
	Search();


}

void AStar::Search(){
	cout << "Search() ---------------------------------------\n" << endl;
	int safeExit = 20000;

	while (!qOpenList.empty() && safeExit > 0){
		safeExit--;
		VisitNode();
		
		if (EndFound()){
			PrintPath();
			break;
		}
	}
}

void AStar::VisitNode(){
	std::cout << "Visiting Node---------" << endl;
	Node* pCurrentNode = qOpenList.front();
	pCurrentNode->Stampa();

	qOpenList.pop_front();

	//Metto nei closed, rimetto in open dopo in caso
	pCurrentNode->oStato = NodeState::Closed;
	AddNodeToClosedList(pCurrentNode);
	if (pCurrentNode->iH == 0){
		endFound = true;
		lastConf = pCurrentNode;
		std::cout << "Found H=0" << endl;
		pCurrentNode->Stampa();
	}
	else{
		pCurrentNode->GenerateSons();

		std::list<Node*>::iterator iAdjEnd(pCurrentNode->lAdj.end());
		for (std::list<Node*>::iterator iter = pCurrentNode->lAdj.begin(); iter != iAdjEnd; ++iter){
			Node* pIterNode(*iter);
			PresentAndBetter(pIterNode);
		}
		std::cout << "Visiting Node...DONE\n\n";
	}
}

void AStar::AddNodeToOpenList(Node* pNode){
	std::cout << "Adding Node In OPEN---------" << endl;
	pNode->Stampa();

	Node* pParent = pNode->pParent;

	switch (pNode->oStato){
	case NodeState::Closed:
		if (pNode->iG <= pParent->iG + 1)
		{
			std::cout << " already visited.\n";
			return;
		}
		break;

	case NodeState::Open:	
		qOpenList.remove(pNode);
		break;

	default:
		break;
	}

	pNode->oStato = NodeState::Open;

	bool bInserted(false);

	std::list<Node*>::iterator iEnd(qOpenList.end());
	for (std::list<Node*>::iterator iter = qOpenList.begin(); iter != iEnd; ++iter)	{
		Node* pIterNode(*iter);
		if (pIterNode->iF > pNode->iF){
			qOpenList.insert(iter, pNode);
			bInserted = true;
			std::cout << "---correctly added in Open.\n\n";
			break;
		}
	}

	if (!bInserted)	{
		qOpenList.push_back(pNode);
		std::cout << "---correctly added in Open.\n\n";
	}
}
void AStar::AddNodeToClosedList(Node* pNode){
	std::cout << "Adding Node In CLOSED---------" << endl;
	bool found = false;
	std::list<Node*>::iterator iEnd(qClosedList.end());
	for (std::list<Node*>::iterator iter = qClosedList.begin(); iter != iEnd && !found; ++iter)	{
		Node* pIterNode(*iter);
		if (pNode == pIterNode){
			found = true;
		}
	}
	if (!found){
		qClosedList.push_back(pNode);
		std::cout << "---correctly added in CLOSED.\n\n";
	}
}

bool AStar::EndFound(){
	return endFound;
}

void AStar::PrintPath(){
	std::cout << "Print PATH" << endl;
	while (lastConf != nullptr){
		lastConf->Stampa();
		lastConf = lastConf->pParent;
	}
}

void AStar::PresentAndBetter(Node* pNode){
	std::cout << "Check in already in a list." << endl;
	bool found = false;
	std::list<Node*>::iterator iEnd(qOpenList.end());
	std::cout << "Check in Open list." << endl;
	for (std::list<Node*>::iterator iter = qOpenList.begin(); iter != iEnd && !found; ++iter)	{
		Node* pIterNode(*iter);
		if (pNode->EqualTo(pIterNode)){
			found = true;
			std::cout << "Found in Open..." ;
			if (pNode->BetterThan(pIterNode)){
				std::cout << "....and is better" << endl;
				pIterNode->pParent = pNode->pParent;
				pIterNode->iG = pNode->iG;
				pIterNode->iF = pNode->iF;
			}
			else{
				std::cout << "....but is worst" << endl;
			}
		}
	}
	if (!found){
		std::cout << "Check in closed" << endl;
		std::list<Node*>::iterator iEnd(qClosedList.end());
		for (std::list<Node*>::iterator iter = qClosedList.begin(); iter != iEnd && !found; ++iter)	{
			Node* pIterNode(*iter);
			if (pNode->EqualTo(pIterNode)){
				std::cout << "Found in Closed";
				found = true;
			}
		}
	}

	if (!found){
		AddNodeToOpenList(pNode);
	}
	else{
		std::cout << "Node not added"<< endl;
	}
}