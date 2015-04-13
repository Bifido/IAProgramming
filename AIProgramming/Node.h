#pragma once
#include <list>

#define NODE_MAX_ELEM_STATUS 15

enum NodeState; // <-- Forward Declaration

struct Node{

	// ** VARIABLES **

	Node* parent;
	NodeState state;
	std::list<Node*> adjNodes;

	int g;
	int h;
	int f;

	short configuration[NODE_MAX_ELEM_STATUS];

	// ** FUNCTIONS **

	Node();
	Node(const Node&);
	~Node();
		
	void CopyConfigurationFrom(const Node&);
	bool operator==(const Node&) const;

};