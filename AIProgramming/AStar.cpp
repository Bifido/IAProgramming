#include <iostream>
#include "AStar.h"
using namespace std;

void AStar::Run(){
	root = new Node();
	root->ComputeF();

	cout << "ROOT" << endl;
	root->Stampa();

	root->GenerateSons();
	root->Stampa();
}