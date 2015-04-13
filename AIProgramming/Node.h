#pragma once
#include <list>
#include "Scacchiera.h"
#include "NodeState.h"

class Node{
	public:
		Node();
		Node(Node& other);
		~Node();
		bool operator==(const Node &other) const;
		bool operator>(const Node &other) const;
		bool operator<(const Node &other) const;

		void ComputeHeuristic();
		std::list<Node*> GenerateSons();
		void Stampa()const;

		NodeState			oStato;
		Node*				pParent;
		int					iF;
		int					iG;
		int                 iH; //could be < 0?
		std::list<Node*>    lAdj;
	private:
		Scacchiera			oScacchiera;
};