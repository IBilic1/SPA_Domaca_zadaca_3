#include<iostream>
#include"PathFinder.h"
using namespace std;
int main() {

	PathFinder MojPut;
	bool moj_zid[32][32];
	for (int i = 0; i < 32; i++)
	{
		for (int j = 0; j < 32; j++)
		{
			moj_zid[i][j]=false;
		}
	}

	moj_zid[7][8] = true;
	moj_zid[8][8] = true;
	moj_zid[9][8] = true;
	moj_zid[10][8] = true;
	moj_zid[11][8] = true;
	moj_zid[12][8] = true;
	moj_zid[13][8] = true;
	moj_zid[14][8] = true;



	cout << "Upiste pocetak x: " << endl;
	Tocka pozIgraca;
	cin >> pozIgraca.x;
	cout << "Upiste pocetak y: " << endl;
	cin >> pozIgraca.y;
	system("cls");
	cout << "Upiste kraj x: " << endl;
	Tocka kraj;

	cin >> kraj.x;
	cout << "Upiste kraj y: " << endl;
	cin >> kraj.y;
	system("cls");



	MojPut.set_pocetak(pozIgraca.x, pozIgraca.y);
	MojPut.set_kraj(kraj.x, kraj.y);
	MojPut.set_zid(moj_zid);
	

	//MojPut.set_pocetak(pozIgraca.x, pozIgraca.y);
	//MojPut.set_kraj(kraj.x, kraj.y);

	stack<Tocka> Put;
	
	MojPut.Dijkstrinog_algoritam(Put);
	while (true)
	{
		for (int i = 0; i < 32; ++i)
		{
			for (int j = 0; j < 32; ++j)
			{
				if (j == pozIgraca.x && i == pozIgraca.y) { cout << "P"; }
				else if (j == kraj.x && i ==kraj.y) { cout << "K"; }
				else if (moj_zid[i][j]) {
					cout << "#";
				}
				else
				{
					cout << ".";
				}
			}
			cout << endl;
		}
			system("pause");
			
			if (!Put.empty()) {
				pozIgraca = Put.top();
				Put.pop();
			}
			else {
				break;
			}
			system("cls");
		
	}
	return 0;
}