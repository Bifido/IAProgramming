
#include "ChessConfiguration.h"

ChessConfiguration::ChessConfiguration(const int* initialConf)
	:m_chess(new int[m_SIZE_ROW*m_SIZE_COL]), m_g(0), m_parent(nullptr)
{
	for (int index = 0; index < m_SIZE_ROW*m_SIZE_COL; ++index)
	{
		m_chess[index] = initialConf[index];
		if (m_chess[index] == 0)
			m_zeroIndex = index;
	}
	m_h = ComputeHeuristic();
}

ChessConfiguration::ChessConfiguration(const ChessConfiguration& copy)
	: m_chess(new int[copy.m_SIZE_ROW*copy.m_SIZE_COL]), m_zeroIndex(copy.m_zeroIndex),
	m_g(copy.m_g), m_parent(copy.m_parent)
{
	for (int index = 0; index < m_SIZE_ROW*m_SIZE_COL; ++index)
	{
		m_chess[index] = copy.m_chess[index];
	}

	m_h = ComputeHeuristic();
}

ChessConfiguration& ChessConfiguration::operator= (const ChessConfiguration& copy)
{
	if (this != &copy)
	{
		m_zeroIndex = copy.m_zeroIndex;
		m_h = copy.m_h;
		m_g = copy.m_g;
		m_parent = copy.m_parent;
		for (int index = 0; index < m_SIZE_ROW*m_SIZE_COL; ++index)
		{
			m_chess[index] = copy.m_chess[index];
		}
	}
	return *this;
}

int ChessConfiguration::ComputeHeuristic() const
{
	int heuristic = 0;
	for (int index = 0; index < m_SIZE_ROW*m_SIZE_COL; ++index)
	{
		heuristic += ComputeCellHeuristic(index);
	}
	return heuristic;
}

int ChessConfiguration::ComputeCellHeuristic(int index) const
{
	if (index < m_SIZE_ROW*m_SIZE_COL && m_chess[index] != 0){

		int row = index / m_SIZE_COL;
		int col = index % m_SIZE_COL;
		int idealRow = (m_chess[index] - 1) / m_SIZE_COL;
		int idealCol = (m_chess[index] - 1) % m_SIZE_COL;

		return std::abs(row - idealRow) + std::abs(col - idealCol);
	}

	return 0;
}

//pass in out_possMovesArray an array of size 4
//return the number of possibleMoves that popolate out_possMovesArray
int ChessConfiguration::GetPossibleMoves(int* out_possMovesArray) const
{
	int row = m_zeroIndex / m_SIZE_COL;
	int col = m_zeroIndex % m_SIZE_COL;
	int numPossibleMoves = 4;
	int arrayIndex = 0;

	if (col != 0)
	{
		out_possMovesArray[arrayIndex] = m_zeroIndex - 1;
		++arrayIndex;
	}
	else
	{
		--numPossibleMoves;
	}
	if (col != m_SIZE_COL - 1)
	{
		out_possMovesArray[arrayIndex] = m_zeroIndex + 1;
		++arrayIndex;
	}
	else
	{
		--numPossibleMoves;
	}
	if (row != 0)
	{
		out_possMovesArray[arrayIndex] = m_zeroIndex - m_SIZE_COL;
		++arrayIndex;
	}
	else
	{
		--numPossibleMoves;
	}
	if (row != m_SIZE_ROW - 1)
	{
		out_possMovesArray[arrayIndex] = m_zeroIndex + m_SIZE_COL;
		++arrayIndex;
	}
	else
	{
		--numPossibleMoves;
	}

	return numPossibleMoves;
}
void ChessConfiguration::Move(int moveIndex)
{
	if (moveIndex < m_SIZE_ROW*m_SIZE_COL)
	{
		m_chess[m_zeroIndex] = m_chess[moveIndex];
		m_chess[moveIndex] = 0;
		m_zeroIndex = moveIndex;
		m_h = ComputeHeuristic();
	}
}

ChessConfiguration::~ChessConfiguration()
{
	delete[] m_chess;
}

bool ChessConfiguration::Equal(const ChessConfiguration& other) const
{
	bool equal = true;
	for (int index = 0; index < m_SIZE_ROW*m_SIZE_COL; ++index)
		if (m_chess[index] != other.m_chess[index])
			equal = false;

	return equal;
}

void ChessConfiguration::Print() const
{
	std::cout << std::endl;
	for (int row = 0; row < m_SIZE_ROW; ++row)
	{
		for (int col = 0; col < m_SIZE_COL; ++col)
		{
			std::cout << "---";
		}
		std::cout << std::endl;
		std::cout << "|";
		for (int col = 0; col < m_SIZE_COL; ++col)
		{
			std::cout << std::setw(2) << m_chess[row*m_SIZE_COL + col] << "|";
		}
		std::cout << std::endl;
	}

	for (int col = 0; col < m_SIZE_COL; ++col)
	{
		std::cout << "---";
	}
}

//NODE

void ChessConfiguration::UpdateG(int g)
{
	if (m_g > g)
		m_g = g;
}

bool ChessConfiguration::GreaterFThan(const ChessConfiguration& second) const
{
	if (GetF() > second.GetF())
	{
		return true;
	}
	//else if (GetF() == second.GetF())
	//{
	//	if (GetH() >= second.GetH())
	//		return true;
	//}

	return false;
}