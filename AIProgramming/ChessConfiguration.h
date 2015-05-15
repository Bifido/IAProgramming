#include <iostream>
#include <iomanip>
#include <assert.h>

class ChessConfiguration
{
public:
	explicit ChessConfiguration();
	explicit ChessConfiguration(const int* initialConf);
	//Shallow copy
	explicit ChessConfiguration(const ChessConfiguration& copy);
	//Deep copy + Move of moveIndex cell in empty cell
	explicit ChessConfiguration(ChessConfiguration& copy, int moveIndex);
	//Shallow copy
	ChessConfiguration& operator= (const ChessConfiguration& copy);

	//Retrun the number of possibile moves and full out_possMovesArray with an array of possible moves
	int GetPossibleMoves(int* out_possMovesArray) const;
	//Move of moveIndex cell in empty cell
	void Move(int moveIndex);

	~ChessConfiguration();

	void Print() const;
	bool Equal(const ChessConfiguration& other) const;

	const int m_SIZE_ROW = 4;
	const int m_SIZE_COL = 4;

	bool GreaterFThan(const ChessConfiguration& second) const;

	//NODE
	inline int GetF() const { return m_h + m_g; };
	inline int GetG() const { return m_g; };
	inline int GetH() const { return m_h; };
	inline std::string GetHash() const { return m_hash; };
	inline void SetG(int g) { m_g = g; };
	void UpdateG(int g, std::string parent);

	//void SetParent(ChessConfiguration* parent) { m_parent = parent; };
	std::string GetParent() { return m_parent; };

private:
	int* m_chess;
	int m_zeroIndex;
	int ComputeHeuristic() const;
	int ComputeCellHeuristic(int index) const;
	std::string ComputeHash();
	//NODE
	int m_h;
	int m_g;
	std::string m_parent;
	std::string m_hash;
};
