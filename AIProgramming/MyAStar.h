#include <vector>
#include <ctime>
//#include <list>
#include <unordered_map>
#include "ChessConfiguration.h"

//class ChessConfiguration;

class MyAStar
{
public:
	void Initialize();
	void Run();
private:
	void Clear();
	void AddToOpenList(ChessConfiguration& node);

	void ComputeAdj(ChessConfiguration& node);
	void InsertOrUpdateG(ChessConfiguration& obj);

	void PrintSolution(ChessConfiguration& sol);

	std::vector<std::string> m_openList;
	//std::list<ChessConfiguration*> m_closedList;

	std::unordered_map <std::string, int>* m_closedMap;
	std::unordered_map <std::string, ChessConfiguration>* m_openChessMap;

	time_t m_time;
};