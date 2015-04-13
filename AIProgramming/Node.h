#pragma once
#include <list>
#include "Scacchiera.h"
#include "NodeState.h"

class Node{
	public:
		Node();
		Node(Scacchiera board);
		~Node();
		void ComputeHeuristic();
		bool operator==(const Node &other) const;
		void Stampa()const;

		NodeState			oStato;
		Node*				pParent;
		int					iF;
		int					iG;
		int                 iH;
		std::list<Node*>    lAdj;
	private:
		Scacchiera*			pScacchiera;
};