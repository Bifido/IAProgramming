#include "Node.h"
#include "NodeState.h"


Node::Node(): g(0), h(0), f(0) {
	// Create a standard configuration that allow at least one solution (always the same)
	configuration[0] = 13;
	configuration[1] = 5;
	configuration[2] = 14;
	configuration[3] = 11;
	configuration[4] = 12;
	configuration[5] = 15;
	configuration[6] = 7;
	configuration[7] = 2;
	configuration[8] = 1;
	configuration[9] = 10;
	configuration[10] = 3;
	configuration[11] = 9;
	configuration[12] = 8;
	configuration[13] = 6;
	configuration[14] = 4;
	configuration[15] = 16; // 16 rapresent the hole!!

	posOfEmpty = 15;

	state = NodeState::Unknown;
}

Node::Node(const Node& nodeBase){
	CopyConfigurationFrom(nodeBase);

	state = NodeState::Unknown;
}

Node::~Node(){

}


void Node::SetG(int inG){
	g = inG;
	f = g + h;
}

void Node::SetH(int inH){
	h = inH;
	f = g + h;
}

void Node::AddAdjNode(Node* newNode){
	adjNodes.push_back(newNode);
}

void Node::SwapCellsInConfiguration(int pos1, int pos2){
	
	// Update the posOfEmpty
	if (pos1 == posOfEmpty)
		posOfEmpty = pos2;
	else
		posOfEmpty = pos1;

	// Swap the values
	if (pos1 < NODE_MAX_ELEM_STATUS && pos2 < NODE_MAX_ELEM_STATUS){
		configuration[pos1] = configuration[pos1] ^ configuration[pos2]; // mask in pos1 
		configuration[pos2] = configuration[pos1] ^ configuration[pos2]; // pos1 in pos2
		configuration[pos1] = configuration[pos1] ^ configuration[pos2]; // pos2 in pos1
	}
}

void Node::CopyConfigurationFrom(const Node& toCopy){
	memcpy(configuration, toCopy.configuration, NODE_MAX_ELEM_STATUS*sizeof(short));
}

bool Node::operator==(const Node& toCheck) const{
	
	for (int i = 0; i < NODE_MAX_ELEM_STATUS; ++i)
		if (configuration[i] != toCheck.configuration[i])
			return false;

	return true;
};