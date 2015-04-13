#pragma once

class Scacchiera{
public:
	Scacchiera();
	Scacchiera(const Scacchiera& other);
	void Init();
	bool operator==(const Scacchiera& other) const;
	~Scacchiera();

	void ScambiaValori(int start, int end);
	const int GetValue(int index) const;
	const int GetZeroIndex() const;
	void Stampa() const;

private:
	const int DIM = 16;
	int* caselle;
	int zeroIndex;
};