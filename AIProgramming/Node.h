#pragma once
#include <list>
#include "Scacchiera.h"
#include "NodeState.h"

class Node{
	public:
		Node();
		Node(Node& other);
		Node(Node* other);
		~Node();
		bool EqualTo(Node* other) const;
		bool BetterThan(Node* other) const;
		bool operator>(const Node& other) const;

		void ComputeHeuristic();
		void ComputeF();
		void GenerateSons();
		void Stampa()const;

		NodeState			oStato;
		Node*				pParent;
		int					iF;
		int					iG;
		int                 iH;
		std::list<Node*>    lAdj;
	private:
		Scacchiera*			oScacchiera;

		Node* GeneraDestra();
		Node* GeneraSinistra();
		Node* GeneraBasso();
		Node* GeneraAlto();
};