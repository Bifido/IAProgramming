#include <iostream>
#include <stdlib.h>
#include "Node.h"

Node::Node(){
	this->oStato = NodeState::Unknown;
	this->pParent = nullptr;
	this->oScacchiera = Scacchiera();
	this->iF = 0;
	this->iG = 0;
	this->iH = 0;
	this->lAdj.clear();
}

Node::Node(Node& other){
	this->oStato = NodeState::Unknown;
	this->pParent = &other;
	this->oScacchiera = Scacchiera(other.oScacchiera);
	this->iF = other.iF;
	this->iG = other.iG;
	this->iH = other.iH;
	this->lAdj.clear();
}

Node::~Node(){
	oScacchiera.~Scacchiera();
}

bool Node::operator==(const Node &other) const{
	bool result = false;
	if (this->oScacchiera == other.oScacchiera && this->iG == other.iG){
		result = true;
	}
	return result;
}

bool Node::operator>(const Node &other) const{
	bool result = false;
	if (this->oScacchiera == other.oScacchiera && this->iG > other.iG){
		result = true;
	}
	return result;
}

bool Node::operator<(const Node &other) const{
	bool result = false;
	if (this->oScacchiera == other.oScacchiera && this->iG < other.iG){
		result = true;
	}
	return result;
}

void Node::ComputeHeuristic(){
	this->iH = 0;
	for (int i = 0; i < this->oScacchiera.GetDIM(); i++){
		//from [0] expect 1, from [1] expect 2, etc etc, so correct conf has iH = 15 ( [n] - n = 1 ) 
		//with abs, all error are positive, but also [15] = 0 that return 15
		this->iH = abs(oScacchiera[i] - i);
	}
	//to standardize remove other 15 ( all tiles correct is 15 from position from 0-14 and 15 from pos 15)
	this->iH -= 30;
}