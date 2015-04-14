#include <iostream>
#include "AStar.h"
#include "Node.h"

int main(int argc, const char * argv[])
{
	Node x;


    AStar algorithm;
	/*algorithm.ComputeNodeHeuristic(&x);
	std::cout << x.GetH() << std::endl;*/
    algorithm.Run();
    
    
    return 0;
}

