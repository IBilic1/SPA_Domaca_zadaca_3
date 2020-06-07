#include "PathFinder.h"

inline int Udaljenost2(int x1, int y1, int x2, int y2)
{

	int val = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
	return val * 10;

}
struct MojaUsporedba
{
	bool operator()(const Polje_tocaka& p1, const Polje_tocaka& p2) {
		return p1.Udaljenost_od_pocetka > p2.Udaljenost_od_pocetka;
	}
};
PathFinder::PathFinder()
{
	for (int i = 0; i < visina; i++)
	{
		for (int j = 0; j < sirina; j++)
		{
			polje[i][j].MojaPozicija.x = j;
			polje[i][j].MojaPozicija.y = i;
			zid[i][j] = false;
		}
	}
}

void PathFinder::set_pocetak(int x, int y)
{
	xPocetak = x;
	yPocetak = y;
}

void PathFinder::set_kraj(int x, int y)
{
	xKraj = x;
	yKraj = y;
}

void PathFinder::set_zid(bool moj_zid[][32])
{
	for (int i = 0; i < visina; i++)
	{
		for (int j = 0; j < sirina; j++)
		{
			zid[i][j] = moj_zid[i][j];
		}
	}
}

void PathFinder::Dijkstrinog_algoritam(stack<Tocka>& rijesenje)
{
	polje[yPocetak][xPocetak].Udaljenost_od_pocetka = 0;
	polje[yPocetak][xPocetak].ProslaPozicija.x = xPocetak;
	polje[yPocetak][xPocetak].ProslaPozicija.y = yPocetak;
	int xPoz = xPocetak;
	int yPoz = yPocetak;
	priority_queue<Polje_tocaka, vector<Polje_tocaka>, MojaUsporedba> pq;

	while (xPoz != xKraj || yPoz != yKraj)
	{
		for (int i = (yPoz - 1); i <= (yPoz + 1); ++i)
		{
			for (int j = (xPoz - 1); j <= (xPoz + 1); ++j)
			{
				if (j < 0 || j >= 32) {
					continue;
				}
				if (i < 0 || i >= 32) {
					continue;
				}

				if (j == xPoz && i == yPoz) {
					continue;
				}
				if (polje[i][j].Posjecen) {
					continue;
				}
				if (zid[i][j]) {
					continue;
				}
				int Tenativedistance = Udaljenost2(xPoz, yPoz, j, i) + polje[yPoz][xPoz].Udaljenost_od_pocetka;
				if (Tenativedistance < polje[i][j].Udaljenost_od_pocetka)
				{
					polje[i][j].Udaljenost_od_pocetka = Tenativedistance;
					polje[i][j].ProslaPozicija.x = xPoz;
					polje[i][j].ProslaPozicija.y = yPoz;

					pq.push(polje[i][j]);
				}

			}
		}
		polje[yPoz][xPoz].Posjecen = true;
		xPoz = pq.top().MojaPozicija.x;
		yPoz = pq.top().MojaPozicija.y;
		pq.pop();
	}
	///xPoz = xKraj;
	//yPoz = yKraj;

	while (xPoz != xPocetak || yPoz != yPocetak)
	{
		Tocka t;
		t.x = xPoz;
		t.y = yPoz;

		rijesenje.push(t);

		xPoz = polje[t.y][t.x].ProslaPozicija.x;
		yPoz = polje[t.y][t.x].ProslaPozicija.y;
	}
	Tocka T;
	T.x = xPocetak;
	T.y = yPocetak;
	rijesenje.push(T);
}


