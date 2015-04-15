#include <iostream>
//#include "AStar.h"
#include "MyAStar.h"


//#include "ChessConfiguration.h"

//void Move(ChessConfiguration& chess)
//{
//	chess.Print();
//
//	std::cout << std::endl << chess.GetF() << std::endl;
//
//	int* possMoves = new int[4];
//	int numPossMoves = chess.GetPossibleMoves(possMoves);
//	for (; numPossMoves > 0; --numPossMoves)
//	{
//		std::cout << possMoves[numPossMoves - 1] << " - ";
//	}
//
//	chess.Move(possMoves[0]);
//	delete[] possMoves;
//}

int main(int argc, const char * argv[])
{
	MyAStar algorithm;
	algorithm.Initialize();
	algorithm.Run();
	

 //   AStar algorithm;
 //   algorithm.Run();
 //   
	//int initial[] = { 13, 5, 14, 11, 12, 15, 7, 2, 1, 10, 3, 9, 8, 6, 4, 0 };
	//ChessConfiguration chess(initial);

	//for (int i = 0; i < 10; i++)
	//	Move(chess);

	std::cout << std::endl << std::endl << "Premere un tasto per continuare" << std::endl;
	std::getchar();

    return 0;
}

