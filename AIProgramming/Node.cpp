#include <iostream>
#include "Node.h"
using namespace std;

Node::Node(){
	this->oStato = NodeState::Unknown;
	this->pParent = nullptr;
	this->oScacchiera = new Scacchiera();
	this->iF = 0;
	this->iG = 0;
	this->iH = 0;
	this->lAdj.clear();
}
Node::Node(Node& other){
	this->oStato = NodeState::Unknown;
	this->pParent = &other;
	this->oScacchiera = new Scacchiera(other.oScacchiera);
	this->iF = other.iF;
	this->iG = other.iG+1;
	this->iH = other.iH;
	this->lAdj.clear();
}
Node::Node(Node* other){
	this->oStato = NodeState::Unknown;
	this->pParent = other;
	this->oScacchiera = new Scacchiera(other->oScacchiera);
	this->iF = other->iF;
	this->iG = other->iG + 1;
	this->iH = other->iH;
	this->lAdj.clear();
}
Node::~Node(){
	oScacchiera->~Scacchiera();
}

bool Node::EqualTo(Node* other) const{
	return this->oScacchiera->EqualTo(other->oScacchiera);
}

bool Node::operator>(const Node &other) const{
	bool result = false;
	if (this->oScacchiera == other.oScacchiera && this->iG > other.iG){
		result = true;
	}
	return result;
}
bool Node::BetterThan(Node* other) const{
	bool result = false;
	if (this->oScacchiera->EqualTo(other->oScacchiera) && this->iG < other->iG){
		result = true;
	}
	return result;
}

void Node::ComputeF(){
	ComputeHeuristic();
	iF = iG + iH;
}
void Node::ComputeHeuristic(){
	iH = 0;
	int actualIndexX;
	int actualIndexY;
	int correctIndexX;
	int correctIndexY;
	int tempValue;
	for (int i = 0; i < oScacchiera->DIM; i++){
		tempValue = oScacchiera->GetValue(i);
		if (tempValue == 0){
			if (i != 15){
				actualIndexX = i % oScacchiera->DIM_ROW;
				actualIndexY = i / oScacchiera->DIM_ROW;
				correctIndexX = 15 % oScacchiera->DIM_ROW;
				correctIndexY = 15 / oScacchiera->DIM_ROW;
				iH += abs(actualIndexX - correctIndexX) + abs(actualIndexY - correctIndexY);
			}
		}
		else{
			if (tempValue - i != 1){
				actualIndexX = i % oScacchiera->DIM_ROW;
				actualIndexY = i / oScacchiera->DIM_ROW;
				correctIndexX = (tempValue - 1) % oScacchiera->DIM_ROW;
				correctIndexY = (tempValue - 1) / oScacchiera->DIM_ROW;
				iH += abs(actualIndexX - correctIndexX) + abs(actualIndexY - correctIndexY);
			}
		}
	}
}

void Node::GenerateSons(){
	cout << "generating children" << endl;
	lAdj.clear();

	int zeroIndexX = oScacchiera->GetZeroIndex() % oScacchiera->DIM_ROW;
	int zeroIndexY = oScacchiera->GetZeroIndex() / oScacchiera->DIM_ROW;

	cout << "zero in (" << zeroIndexX << "," << zeroIndexY << ")" << endl;

	if (zeroIndexX == 0){
		lAdj.push_back(GeneraDestra());				//genera destra
		if (zeroIndexY == 0){
			lAdj.push_back(GeneraBasso());			//genera basso
		}
		else{
			if (zeroIndexY == 3){
				lAdj.push_back(GeneraAlto());		//genera alto
			}
			else{
				lAdj.push_back(GeneraAlto());		//genera alto
				lAdj.push_back(GeneraBasso());		//genera basso
			}
		}
	}
	else{
		if (zeroIndexX == 3){
			lAdj.push_back(GeneraSinistra());		//genera sinistra
			if (zeroIndexY == 0){
				lAdj.push_back(GeneraBasso());		//genera basso
			}
			else{
				if (zeroIndexY == 3){
					lAdj.push_back(GeneraAlto());	//genera alto
				}
				else{
					lAdj.push_back(GeneraAlto());	//genera alto
					lAdj.push_back(GeneraBasso());	//genera basso
				}
			}
		}
		else{
			lAdj.push_back(GeneraDestra());			//genera destra
			lAdj.push_back(GeneraSinistra());		//genera sinistra
			if (zeroIndexY == 0){
				lAdj.push_back(GeneraBasso());		//genera basso
			}
			else{
				if (zeroIndexY == 3){
					lAdj.push_back(GeneraAlto());	//genera alto
				}
				else{
					lAdj.push_back(GeneraBasso());	//genera basso
					lAdj.push_back(GeneraAlto());	//genera alto
				}
			}
		}
	}
	cout << "sons are " << lAdj.size() << endl;
	cout << "sons generation ended\n" << endl;
}
void Node::Stampa()const{
	oScacchiera->Stampa();
	cout << "F:" << iF << " = G(" << iG << ") + H(" << iH << ")" << endl;
	cout << "sons are:" << lAdj.size() << "\n" << endl;
}

Node* Node::GeneraDestra(){
	cout << "generating right Move:" << endl;
	Node* child = new Node(this);
	int zeroIndexX = child->oScacchiera->GetZeroIndex();
	child->oScacchiera->ScambiaValori(zeroIndexX, zeroIndexX + 1);
	child->ComputeF();
	child->Stampa();
	return child;
}
Node* Node::GeneraSinistra(){
	cout << "generating left Move:" << endl;
	Node* child = new Node(this);
	int zeroIndexX = child->oScacchiera->GetZeroIndex();
	child->oScacchiera->ScambiaValori(zeroIndexX, zeroIndexX - 1);
	child->ComputeF();
	child->Stampa();
	return child;
}
Node* Node::GeneraBasso(){
	cout << "generating lower Move:" << endl;
	Node* child = new Node(this);
	int zeroIndexX = child->oScacchiera->GetZeroIndex();
	child->oScacchiera->ScambiaValori(zeroIndexX, zeroIndexX + child->oScacchiera->DIM_ROW);
	child->ComputeF();
	child->Stampa();
	return child;
}
Node* Node::GeneraAlto(){
	cout << "generating upper Move:" << endl;
	Node* child = new Node(this);
	int zeroIndexX = child->oScacchiera->GetZeroIndex();
	child->oScacchiera->ScambiaValori(zeroIndexX, zeroIndexX - child->oScacchiera->DIM_ROW);
	child->ComputeF();
	child->Stampa();
	return child;
}