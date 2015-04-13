#include "Node.h"
#include "NodeState.h"


Node::Node(){
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

	state = NodeState::Unknown;
}


Node::Node(const Node& nodeBase){
	CopyConfigurationFrom(nodeBase);

	state = NodeState::Unknown;
}

Node::~Node(){

}

void Node::CopyConfigurationFrom(const Node& toCopy){
	memcpy(configuration, toCopy.configuration, NODE_MAX_ELEM_STATUS);
}

bool Node::operator==(const Node& toCheck) const{
	
	for (int i = 0; i < NODE_MAX_ELEM_STATUS; ++i)
		if (configuration[i] != toCheck.configuration[i])
			return false;

	return true;
};