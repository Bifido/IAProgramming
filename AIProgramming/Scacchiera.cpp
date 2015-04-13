#include  <iostream>
#include "Scacchiera.h"
using namespace std;

Scacchiera::Scacchiera(){
	caselle = new int[DIM];
	zeroIndex = -1;
}

void Scacchiera::Init(){
	caselle = new int[DIM]{13, 5, 14, 11, 12, 15, 7, 2, 1, 10, 3, 9, 8, 6, 4, 0};
	zeroIndex = 15;
}

Scacchiera::Scacchiera(const Scacchiera& other){
	this->caselle = other.caselle;
	this->zeroIndex = other.zeroIndex;
}

bool Scacchiera::operator==(const Scacchiera& other) const{
	bool result = true;
	for (int i = 0; i < DIM; i++){
		if (this->caselle[i] != other.caselle[i]){
			result = false;
		}
	}
	return result;
}

Scacchiera::~Scacchiera(){
	delete[] caselle;
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

const int Scacchiera::GetValue(int index) const{
	return caselle[index];
}

const int Scacchiera::GetZeroIndex() const{
	return zeroIndex;
}

void Scacchiera::Stampa() const{
	for (int i = 0; i < DIM; i++){
		if (i % 4 == 0){
			cout << "\n[" << i << "] " << caselle[i] << ends;
		}
		else{
			cout << "[" << i << "] " << caselle[i] << ends;
		}
	}
	cout << endl;
}
