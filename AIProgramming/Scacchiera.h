#pragma once

class Scacchiera{
public:
	Scacchiera();
	Scacchiera(const Scacchiera& other);
	void Init();
	~Scacchiera();

	int			operator[](const int index) const;
	bool		operator==(const Scacchiera& other) const;
	
	void ScambiaValori(int start, int end);
	void Stampa() const;

	const int GetValue(int index) const;
	const int GetZeroIndex() const;
	int GetDIM();

private:
	const int DIM = 16;
	int* caselle;
	int zeroIndex;
};