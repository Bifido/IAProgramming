#include "AStar.h"
#include <cmath>

// TODO: find the way to delete the heap allocations

void AStar::Run(){
	short arrayCorrectConfiguration[16] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
	// Final Node
	Node* finalNode = new Node(arrayCorrectConfiguration);
	// Starting Node
	Node* x = new Node();

	
	ComputeNodeHeuristic(x);
	AddNodeToOpenList(nullptr, x);

	// ** MAIN SEARCH LOOP
	Node* actual = x;
	while (*actual != *finalNode)
		actual = VisitNode();
	// ** END

	PrintPath(actual);

	Clean();
}

Node* AStar::VisitNode(){
	Node* actual = qOpenList.front();

	if (actual != nullptr){
		qOpenList.pop_front();

		std::cout << "Pop OpenList: (OpenList count:" << qOpenList.size() << ", Configuration passed count:" << nodesAlreadyOpen.size() << std::endl;
		actual->PrintConfiguration();

		//ComputeNodeHeuristic(actual);
		CreateNodeAdj(actual);
	}
	else{
		std::cout << "**** No solution finded!!!! ****" << std::endl;
	}

	nodesAlreadyOpen.push_back(actual);

	return actual;
}

void AStar::CreateNodeAdj(Node* node){
	if (node != nullptr){
		Node* newAdjNode = nullptr;
		int holePosition = node->GetHolePosition();

		// ** check top bound
		if (holePosition - node->NODE_EDGE_ELEM >= 0){
			newAdjNode = new Node(*node); // With the copy costructor copy also the configuration
			// Change the configuration
			newAdjNode->SwapCellsInConfiguration(holePosition, holePosition - node->NODE_EDGE_ELEM);

			bool isNew = true;
			for (std::list<Node*>::const_iterator x = nodesAlreadyOpen.begin(); x != nodesAlreadyOpen.end(); ++x)
				if (*(*x) == (*newAdjNode))
					isNew = false;

			// if a node with this configuration isn't already open, add to the openList
			if (isNew){
				// computate the euristic
				ComputeNodeHeuristic(newAdjNode);
				// add the element to the open list (this step update also the G variable of the node)
				AddNodeToOpenList(node, newAdjNode);
				// add the element as NodeAdj (Maybe useless)
				//node->AddAdjNode(newAdjNode);
			}
			else{
				delete newAdjNode;
			}
		}
		// ** check bottom bound
		if (holePosition + node->NODE_EDGE_ELEM < node->NODE_MAX_ELEM_STATUS){
			newAdjNode = new Node(*node); // With the copy costructor copy also the configuration
			// Change the configuration
			newAdjNode->SwapCellsInConfiguration(holePosition, holePosition + node->NODE_EDGE_ELEM);

			bool isNew = true;
			for (std::list<Node*>::const_iterator x = nodesAlreadyOpen.begin(); x != nodesAlreadyOpen.end(); ++x)
				if (*(*x) == (*newAdjNode))
					isNew = false;


			// if a node with this configuration isn't already open, add to the openList
			if (isNew){
				// computate the euristic
				ComputeNodeHeuristic(newAdjNode);
				// add the element to the open list (this step update also the G variable of the node)
				AddNodeToOpenList(node, newAdjNode);
				// add the element as NodeAdj (Maybe useless)
				//node->AddAdjNode(newAdjNode);
			}
			else{
				delete newAdjNode;
			}
		}
		// ** check left bound
		if (holePosition / node->NODE_EDGE_ELEM == (holePosition - 1) / node->NODE_EDGE_ELEM){
			newAdjNode = new Node(*node); // With the copy costructor copy also the configuration
			// Change the configuration
			newAdjNode->SwapCellsInConfiguration(holePosition, holePosition - 1);

			bool isNew = true;
			for (std::list<Node*>::const_iterator x = nodesAlreadyOpen.begin(); x != nodesAlreadyOpen.end(); ++x)
				if (*(*x) == (*newAdjNode))
					isNew = false;

			// if a node with this configuration isn't already open, add to the openList
			if (isNew){
				// computate the euristic
				ComputeNodeHeuristic(newAdjNode);
				// add the element to the open list (this step update also the G variable of the node)
				AddNodeToOpenList(node, newAdjNode);
				// add the element as NodeAdj (Maybe useless)
				//node->AddAdjNode(newAdjNode);
			}
			else{
				delete newAdjNode;
			}
		}
		// ** check right bound
		if (holePosition / node->NODE_EDGE_ELEM == (holePosition + 1) / node->NODE_EDGE_ELEM){
			newAdjNode = new Node(*node); // With the copy costructor copy also the configuration
			// Change the configuration
			newAdjNode->SwapCellsInConfiguration(holePosition, holePosition + 1);

			bool isNew = true;
			for (std::list<Node*>::const_iterator x = nodesAlreadyOpen.begin(); x != nodesAlreadyOpen.end(); ++x)
				if (*(*x) == (*newAdjNode))
					isNew = false;

			// if a node with this configuration isn't already open, add to the openList
			if (isNew){
				// computate the euristic
				ComputeNodeHeuristic(newAdjNode);
				// add the element to the open list (this step update also the G variable of the node)
				AddNodeToOpenList(node, newAdjNode);
				// add the element as NodeAdj (Maybe useless)
				//node->AddAdjNode(newAdjNode);
			}
			else{
				delete newAdjNode;
			}
		}
			
	}
}

void AStar::AddNodeToOpenList(Node* pParent, Node* pNode){

	if (pParent != nullptr){
		// Set as prev the parent node
		pNode->SetParent(pParent);

		// Update the G variable of the child
		pNode->SetG(pParent->GetG() + 1);
	}

	typedef std::list<Node*>::const_iterator constNodeIter;

	constNodeIter position = qOpenList.begin();
	constNodeIter end = qOpenList.end();
	
	// go through the list until f > myF is found, then stop end insert the new node in that position of the openlist
	// .. in this way preserve the openlist in order
	// .. > and not >= in order to preserve, as second ordering method, FIFO order
	for (; position != end; ++position){
		if ((*position)->GetF() > pNode->GetF()){
			qOpenList.insert(position, pNode);
			break;
		}
	}

	if (position == end)
		qOpenList.push_back(pNode);
}

void AStar::ComputeNodeHeuristic(Node* pNode){
	int hValue = 0;

	int xCorrect = 0, yCorrect = 0;
	
	int maxElem = pNode->NODE_MAX_ELEM_STATUS;
	int edgeSize = pNode->NODE_EDGE_ELEM;

	for (int i = 0; i < maxElem; ++i){
		xCorrect = (pNode->GetConfiguration()[i] - 1) % edgeSize;
		yCorrect = (pNode->GetConfiguration()[i] - 1) / edgeSize;
		hValue += std::abs((i % edgeSize) - xCorrect) + std::abs((i / edgeSize) - yCorrect);
	}

	pNode->SetH(hValue);
}

void AStar::PrintPath(Node* endNode) const{
	if (endNode != nullptr){
		std::list<Node*> path;
		// Go upward until the starting config is reached
		while (endNode->GetParent() != nullptr){
			path.push_back(endNode);
			endNode = endNode->GetParent();
		}

		while (path.size() > 0){
			endNode = path.back();
			endNode->PrintConfiguration();
			path.pop_back();
		}
	}
}

void AStar::Clean(){
	// Free the allocated memory
	typedef std::list<Node*>::iterator nodeIter;

	nodeIter end = nodesAlreadyOpen.end();
	for (nodeIter i = nodesAlreadyOpen.begin(); i != end; ++i)
		delete (*(i));
	nodesAlreadyOpen.clear();

	end = qOpenList.end();
	for (nodeIter i = qOpenList.begin(); i != end; ++i)
		delete (*(i));
	nodesAlreadyOpen.clear();
}