#include <iostream>
#include <string>

using namespace std;

#define T 3

namespace egyetem {

struct Tantargy
{
	string kod;
	unsigned int jegyszam, *jegyek;
};

void megjelenit(const Tantargy &t)
{
	cout << "  Kodja: " << t.kod << endl;
	cout << "  Jegyek szama: " << t.jegyszam << endl;
	cout << "Jegyek: ";
	for (unsigned int j=0; j<t.jegyszam; j++)
	{
		if (j!=0) cout << ", ";
		cout << t.jegyek[j];
	}
	cout << endl;
}

double atlag(const Tantargy &t)
{
	double osszeg=0;
	for (unsigned int i=0; i<t.jegyszam; i++)
		osszeg+=t.jegyek[i];
	return osszeg/t.jegyszam;
}

void ujrafoglal(Tantargy &t, unsigned int ujmeret)
{
	unsigned int *uj=new unsigned int[ujmeret];
	if (t.jegyszam < ujmeret)
	{
		for (unsigned int i=0; i<t.jegyszam; i++)
			uj[i]=t.jegyek[i];
		for (unsigned int i=t.jegyszam; i<ujmeret; i++)
			uj[i]=5;
	}
	else
	{
		for (unsigned int i=0; i<ujmeret; i++)
			uj[i]=t.jegyek[i];
	}
	delete [] t.jegyek;
	t.jegyek=uj;
	t.jegyszam=ujmeret;
}

void ujrafoglal(Tantargy &t, unsigned int ujmeret, unsigned int egyik, unsigned int masik)
{
	unsigned int *uj=new unsigned int[ujmeret];
	if (t.jegyszam < ujmeret)
	{
		for (unsigned int i=0; i<t.jegyszam; i++)
			uj[i]=t.jegyek[i];
		bool elso_jon=true;
		for (unsigned int i=t.jegyszam; i<ujmeret; i++)
		{
			if (elso_jon)
				uj[i]=egyik;
			else
				uj[i]=masik;
			elso_jon=!elso_jon;
		}
	}
	else
	{
		for (unsigned int i=0; i<ujmeret; i++)
			uj[i]=t.jegyek[i];
	}
	delete [] t.jegyek;
	t.jegyek=uj;
	t.jegyszam=ujmeret;
}

void felszabadit(Tantargy &t)
{
	delete [] t.jegyek;
	t.jegyek=nullptr;
}

}

using namespace egyetem;

int main()
{
	Tantargy targyak[T];
	for (unsigned int i=0; i<T; i++)
	{
		cout << "Kerem a(z) " << i+1 << ". targy adatait:" << endl;
		cout << "  Kodja: ";
		cin >> targyak[i].kod;
		cout << "  Jegyek szama: ";
		cin >> targyak[i].jegyszam;
		targyak[i].jegyek=new unsigned int[targyak[i].jegyszam];
		cout << "Kerem a jegyeket (" << targyak[i].jegyszam << " db):" << endl;
		for (unsigned int j=0; j<targyak[i].jegyszam; j++)
			cin >> targyak[i].jegyek[j];
	}

	cout << endl;
	for (unsigned int i=0; i<T; i++)
	{
		cout << "A(z) " << i+1 << ". targy adatai:" << endl;
		megjelenit(targyak[i]);
	}

	cout << endl;
	unsigned int max_idx=0;
	double max_atlag=atlag(targyak[0]); // Hogy ne kelljen mindig újra kiszámolni.
	for (unsigned int i=1; i<T; i++)
	{
		double tatlag=atlag(targyak[i]);
		if (tatlag>max_atlag)
		{
			max_atlag=tatlag;
			max_idx=i;
		}
	}
	cout << "A legnagyobb atlaggal rendelkezo targy adatai:" << endl;
	megjelenit(targyak[max_idx]);
	cout << "  Atlag: " << max_atlag << endl;

	cout << endl;
	for (unsigned int i=0; i<T; i++)
	{
		unsigned int ujmeret=0;
		cout << "Mekkora legyen az uj tomb a(z) " << targyak[i].kod << " targyhoz? ";
		cin >> ujmeret;
		ujrafoglal(targyak[i],ujmeret);
	}
	for (unsigned int i=0; i<T; i++)
	{
		cout << "A(z) " << i+1 << ". targy adatai:" << endl;
		megjelenit(targyak[i]);
	}
	cout << endl;
	ujrafoglal(targyak[0],10,2,4);
	cout << "A(z) " << 1 << ". targy adatai:" << endl;
	megjelenit(targyak[0]);

	for (unsigned int i=0; i<T; i++)
	{
		felszabadit(targyak[i]);
	}
	return 0;
}
