#ifndef __AStar__AStar__
#define __AStar__AStar__

#include <iostream>
#include <list>
#include "Node.h"

class AStar{
public:
    void Run();
    
private:    
    void Search();
    
	void VisitNode();
    void AddNodeToOpenList(Node* pNode);
	void AddNodeToClosedList(Node* pNode);
	
	bool EndFound();
    void PrintPath();
	void PresentAndBetter(Node* pNode);
    
	void Clean();

    std::list<Node*> qOpenList;
	std::list<Node*> qClosedList;
	Node* root;
	Node* lastConf;
	bool endFound;
};

#endif /* defined(__AStar__AStar__) */
