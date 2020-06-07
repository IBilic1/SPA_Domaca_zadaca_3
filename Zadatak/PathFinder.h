#pragma once
#include<cmath>
#include<stack>
#include<queue>
using namespace std;

struct Tocka
{
	int x, y;
};
struct Polje_tocaka
{
	int Udaljenost_od_pocetka = 10000000;
	Tocka ProslaPozicija;
	Tocka MojaPozicija;
	bool Posjecen = false;
};


class PathFinder
{
	Polje_tocaka polje[32][32];
	bool zid[32][32];
	int sirina = 32;
	int visina = 32;

	int xPocetak = 0;
	int yPocetak=0;
	int xKraj = 0;
	int yKraj=0;

public:
	PathFinder();
	void set_pocetak(int x, int y);
	void set_kraj(int x, int y);
	void set_zid(bool zid[][32]);
	void  Dijkstrinog_algoritam(stack<Tocka>& rijesenje);
	
};

