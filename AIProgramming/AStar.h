#ifndef __AStar__AStar__
#define __AStar__AStar__

#include <iostream>
#include <list>
#include "Node.h"

class AStar
{
public:
	void ComputeNodeHeuristic(Node* pNode);
    void Run();

private:
    const static int xMax = 5;
    const static int yMax = 5;
    const static int iStartNode = 0;
    const static int iEndNode = 25;
    
    void CreateGraph();
    void CreateGraphAdjs();
    //void CreateNodeAdj(const int iRow, const int iCol);
    void CreateNodeAdj(Node* node);
    
    void ComputeGraphHeuristics();
    
    void Clean();
    
    void Search();
    Node* VisitNode();
    void AddNodeToOpenList(Node* pParent, Node* pNode);
    
    void PrintPath(Node* pNode) const;
    
    Node* tRoot[xMax * yMax];
    
    std::list<Node*> qOpenList;
	std::list<Node*> nodesAlreadyOpen;
};

#endif /* defined(__AStar__AStar__) */
