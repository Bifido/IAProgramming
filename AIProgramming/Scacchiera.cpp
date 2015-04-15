#include  <iostream>
#include "Scacchiera.h"
using namespace std;

Scacchiera::Scacchiera(){
	caselle = new int[DIM];
	zeroIndex = -1;
	Init();
}

Scacchiera::Scacchiera(const Scacchiera& other){
	this->caselle = other.caselle;
	this->zeroIndex = other.zeroIndex;
}

Scacchiera::Scacchiera(const Scacchiera* other){
	this->caselle = new int[DIM];
	for (int i = 0; i < DIM; i++){
		caselle[i] = other->caselle[i];
	}
	this->zeroIndex = other->zeroIndex;
}

Scacchiera::~Scacchiera(){
	delete[] caselle;
}


void Scacchiera::Init(){
	caselle = new int[DIM]{1, 0, 15, 7, 5, 11, 4, 3, 12, 2, 13, 14, 10, 9, 6, 8};
	zeroIndex = 1;
}

Scacchiera& Scacchiera::operator=(const Scacchiera& other){
	if (this != &other){
		for (int i = 0; i < DIM; i++){
			caselle[i] = other.caselle[i];
		}
		zeroIndex = other.zeroIndex;
	}
	return *this;
}

int Scacchiera::operator[](const int index) const{
	return caselle[index];
}

bool Scacchiera::EqualTo(Scacchiera* other){
	bool result = true;
	for (int i = 0; i < DIM; i++){
		if (this->caselle[i] != other->caselle[i]){
			result = false;
		}
	}
	return result;
}

void Scacchiera::ScambiaValori(int start, int end){
	caselle[end] = caselle[start] + caselle[end];
	caselle[start] = caselle[end] - caselle[start];
	caselle[end] = caselle[end] - caselle[start];

	if (caselle[end] == 0){
		zeroIndex = end;
	}
	if (caselle[start] == 0){
		zeroIndex = start;
	}
}

void Scacchiera::Stampa() const{
	for (int i = 0; i < DIM; i++){
		if (i % 4 == 0){
			cout << "\n[" << i << "]\t" << caselle[i] << "\t" << ends;
		}
		else{
			cout << "[" << i << "]\t" << caselle[i] << "\t" << ends;
		}
	}
	cout << endl;
}

const int Scacchiera::GetValue(int index) const{
	return caselle[index];
}

const int Scacchiera::GetZeroIndex() const{
	return zeroIndex;
}