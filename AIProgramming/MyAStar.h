#include <vector>
#include <list>
#include "ChessConfiguration.h"

class MyAStar
{
public:
	void Initialize();
	void Run();
private:
	void Clear();
	void AddToOpenList(ChessConfiguration* node);

	void ComputeAdj(ChessConfiguration* node);
	void InsertOrUpdateG(ChessConfiguration* obj);

	void PrintSolution(ChessConfiguration* sol);

	std::list<ChessConfiguration*> m_openList;
	std::list<ChessConfiguration*> m_closedList;

};