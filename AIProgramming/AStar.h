#ifndef __AStar__AStar__
#define __AStar__AStar__

#include <iostream>
#include <list>
#include "Node.h"

class AStar
{
public:
    void Run();
    
private:
    void CreateGraph();
    void CreateGraphAdjs();
    void CreateNodeAdj(Node& node);
    
    void ComputeGraphHeuristics();
    void ComputeNodeHeuristic(Node* pNode);
    
    void Clean();
    
    void Search();
    Node* VisitNode();
    void AddNodeToOpenList(Node* pParent, Node* pNode);
    
    void PrintPath(Node* pNode) const;
    
    std::list<Node*> qOpenList;
	Node* root;
};

#endif /* defined(__AStar__AStar__) */
