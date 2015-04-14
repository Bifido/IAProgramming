#pragma once
#include <list>

enum NodeState; // <-- Forward Declaration

class Node{

	// ** VARIABLES **

	Node* parent;
	NodeState state;
	std::list<Node*> adjNodes;

	int g;
	int h;
	int f;

public:

	const static int NODE_EDGE_ELEM = 4;
	const static int NODE_MAX_ELEM_STATUS = NODE_EDGE_ELEM*NODE_EDGE_ELEM;

private:

	short configuration[NODE_MAX_ELEM_STATUS];
	int posOfEmpty;

public:
	// ** FUNCTIONS **
	Node();
	Node(const Node&);
	~Node();

	inline int GetG() const { return g; }
	inline int GetH() const { return h; }
	inline int GetF() const { return f; }
	inline Node* GetParent() const { return parent; }
	inline const short* GetConfiguration() const { return configuration; }
	inline int GetHolePosition() const { return posOfEmpty; }

	inline void SetParent(Node* inParent) { parent = inParent; }
	void SetG(int);
	void SetH(int);
	void SwapCellsInConfiguration(int, int);
	void AddAdjNode(Node*);
		
	void CopyConfigurationFrom(const Node&);
	bool operator==(const Node&) const;

};