#include <iostream>
#include <iomanip>
#include <assert.h>

class ChessConfiguration
{
public:
	explicit ChessConfiguration(const int* initialConf);
	explicit ChessConfiguration(const ChessConfiguration& copy);
	ChessConfiguration& operator= (const ChessConfiguration& copy);

	int GetPossibleMoves(int* out_possMovesArray) const;
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
	inline int GetH() const { return m_h; }
	inline void SetG(int g) { m_g = g; };
	void UpdateG(int g);

	void SetParent(ChessConfiguration* parent) { m_parent = parent; };
	ChessConfiguration* SetParent() { return m_parent; };

private:
	int* m_chess;
	int m_zeroIndex;
	int ComputeHeuristic() const;
	int ComputeCellHeuristic(int index) const;
	//NODE
	int m_h;
	int m_g;
	ChessConfiguration* m_parent;
};
