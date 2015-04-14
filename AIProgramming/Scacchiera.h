#pragma once

class Scacchiera{
public:
	const int DIM = 16;
	const int DIM_ROW = 4;

	Scacchiera();
	Scacchiera(const Scacchiera& other);
	Scacchiera(const Scacchiera* other);
	void Init();
	~Scacchiera();

	Scacchiera& operator=(const Scacchiera& other);
	int			operator[](const int index) const;
	bool		operator==(const Scacchiera& other) const;
	
	void ScambiaValori(int start, int end);
	void Stampa() const;

	const int GetValue(int index) const;
	const int GetZeroIndex() const;

private:
	int* caselle;
	int zeroIndex;
};