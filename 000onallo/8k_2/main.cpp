#include <iostream>

#include "halmaz.h"

using namespace std;

int main()
{

    // Halmaz teszt: meret függvény
    cout << endl;
    cout << "Halmaz teszt: meret" << endl;
    Halmaz h1;
    cout << h1.meret() << endl; // 0

    // Halmaz teszt: << operátor hozzáadáshoz
    cout << endl;
    cout << "Halmaz teszt: operator <<" << endl;
    h1<<3.4<<5<<6<<2.3<<5<<8.7;
    cout << h1.meret() << endl; // 5

    // Halmaz teszt: >> operátor
    cout << endl;
    cout << "Halmaz teszt: operator >>" << endl;
    h1>>65>>3.4>>12>>8.7;
    cout << h1.meret() << endl; // 3

    // Halmaz teszt: << operátor kiíráshoz
    cout << endl;
    cout << "Halmaz teszt: operator <<" << endl;
    cout << h1 << endl; // {2.3, 5, 6}

    // Halmaz teszt: másoló konstruktor
    cout << endl;
    cout << "Halmaz teszt: masolo konstruktor" << endl;
    Halmaz h2(h1);
    cout<<"h2: "<<h2<<endl; // h2: {2.3, 5, 6}
    h2<<5.4<<6.7<<12.3<<5.122;
    cout<<"h2: "<<h2<<endl; // h2: {2.3, 5, 5.122, 5.4, 6, 6.7, 12.3}

    // Halmaz teszt: = operátor
    cout << endl;
    cout << "Halmaz teszt: operator =" << endl;
    Halmaz h3;
    h3=h2;
    cout<<"h3: "<<h3<<endl; // h3: {2.3, 5, 5.122, 5.4, 6, 6.7, 12.3}
    h3>>6.7>>12.3;
    h3<<1<<2;
    cout<<"h3: "<<h3<<endl; // h3: {1, 2, 2.3, 5, 5.122, 5.4, 6}
    h1>>2.3;
    h1<<1333<<2.122;
    cout<<"h1: "<<h1<<endl; // h1: {2.122, 5, 6, 1333}

    // Halmaz teszt: [] operátor
    cout << endl;
    cout << "Halmaz teszt: operator []" << endl;
    cout<<h3<<"-nak eleme-e:"<<endl; // {1, 2, 2.3, 5, 5.122, 5.4, 6}-nak eleme-e:
    cout<<"\t4 ?\t"<<(h3[4]?"igen":"nem")<<endl; // 4 ?	nem
    cout<<"\t5.122 ?\t"<<(h3[5.122]?"igen":"nem")<<endl; // 5.122 ?	igen
    cout<<"\t5.12 ?\t"<<(h3[5.12]?"igen":"nem")<<endl; // 5.12 ?	nem
    cout<<"\t6 ?\t"<<(h3[6]?"igen":"nem")<<endl; // 6 ?	igen
    cout<<"\t1223 ?\t"<<(h3[1223]?"igen":"nem")<<endl; // 1223 ?	nem

    // Halmaz teszt: &, |, -, ^ operátorok
    cout << endl;
    cout << "Halmaz teszt: operator &, |, -, ^" << endl;
    cout<<h1<<" es "<<h2<<" metszete:\n\t"<<(h1&h2)<<endl;				// {2.122, 5, 6, 1333} es {2.3, 5, 5.122, 5.4, 6, 6.7, 12.3} metszete:
                                                                        //		{5, 6}
    cout<<h1<<" es "<<h2<<" unioja:\n\t"<<(h1|h2)<<endl;				// {2.122, 5, 6, 1333} es {2.3, 5, 5.122, 5.4, 6, 6.7, 12.3} unioja:
                                                                        //		{2.122, 2.3, 5, 5.122, 5.4, 6, 6.7, 12.3, 1333}
    cout<<h1<<" es "<<h2<<" kulonbsege:\n\t"<<(h1-h2)<<endl;			// {2.122, 5, 6, 1333} es {2.3, 5, 5.122, 5.4, 6, 6.7, 12.3} kulonbsege:
                                                                        //		{2.122, 1333}
    cout<<h2<<" es "<<h1<<" kulonbsege:\n\t"<<(h2-h1)<<endl;			// {2.3, 5, 5.122, 5.4, 6, 6.7, 12.3} es {2.122, 5, 6, 1333} kulonbsege:
                                                                        //		{2.3, 5.122, 5.4, 6.7, 12.3}
    cout<<h1<<" es "<<h2<<" kolcsonos kizartja:\n\t"<<(h1^h2)<<endl;	// {2.122, 5, 6, 1333} es {2.3, 5, 5.122, 5.4, 6, 6.7, 12.3} kolcsonos kizartja:
                                                                        //		{2.122, 2.3, 5.122, 5.4, 6.7, 12.3, 1333}

    // Halmaz teszt: &=, |=, -=, ^= operátorok
    cout << endl;
    cout << "Halmaz teszt: operator &=, |=, -=, ^=" << endl;
    Halmaz h4, h5;
    h4<<99.9<<88.8<<77.7<<66.6<<55.5;
    cout<<"h4: "<<h4<<endl; // h4: {55.5, 66.6, 77.7, 88.8, 99.9}
    h5<<11.1<<33.3<<55.5<<77.7;
    cout<<"h5: "<<h5<<endl; // h5: {11.1, 33.3, 55.5, 77.7}
    h4|=h2;
    cout<<"h4: "<<h4<<endl; // h4: {2.3, 5, 5.122, 5.4, 6, 6.7, 12.3, 55.5, 66.6, 77.7, 88.8, 99.9}
    h5-=h4;
    cout<<"h5: "<<h5<<endl; // h5: {11.1, 33.3}
    h5|=h3;
    cout<<"h5: "<<h5<<endl; // h5: {1, 2, 2.3, 5, 5.122, 5.4, 6, 11.1, 33.3}
    h5^=h4;
    cout<<"h5: "<<h5<<endl; // h5: {1, 2, 6.7, 11.1, 12.3, 33.3, 55.5, 66.6, 77.7, 88.8, 99.9}
    h4&=h3;
    cout<<"h4: "<<h4<<endl; // h4: {2.3, 5, 5.122, 5.4, 6}

    // Halmaz teszt: + -  operátorok
    cout << endl;
    cout << "Halmaz teszt: operator +, -" << endl;
    cout<<h5<<" plusz 1111:\n\t"<<(h5+1111)<<endl;	// {1, 2, 6.7, 11.1, 12.3, 33.3, 55.5, 66.6, 77.7, 88.8, 99.9} plusz 1111:
                                                    //		{1, 2, 6.7, 11.1, 12.3, 33.3, 55.5, 66.6, 77.7, 88.8, 99.9, 1111}
    cout<<h5<<" minusz 33.3:\n\t"<<(h5-33.3)<<endl;	// {1, 2, 6.7, 11.1, 12.3, 33.3, 55.5, 66.6, 77.7, 88.8, 99.9} minusz 33.3:
                                                    //		{1, 2, 6.7, 11.1, 12.3, 55.5, 66.6, 77.7, 88.8, 99.9}

    // Halmaz teszt: <, <=, >, >=, ==, != operátorok
    cout << endl;
    cout << "Halmaz teszt: operator <, <=, >, >=, ==, !=" << endl;
    Halmaz h6, h7;
    h6<<14.4<<5554<<31.2<<122.222;
    h7<<122.222<<123<<14.4<<9999<<31.2<<5554;
    cout<<"h6"<<h6<<" es h7"<<h7<<" kapcsolata:"<<endl; // h6{14.4, 31.2, 122.222, 5554} es h7{14.4, 31.2, 122.222, 123, 5554, 9999} kapcsolata:
    if (h6<=h7) cout<<"h6 reszhalmaza h7-nek"<<endl; // h6 reszhalmaza h7-nek
    if (h6<h7) cout<<"h6 valodi reszhalmaza h7-nek"<<endl; // h6 valodi reszhalmaza h7-nek
    if (h6>=h7) cout<<"h7 reszhalmaza h6-nak"<<endl; //
    if (h6>h7) cout<<"h7 valodi reszhalmaza h6-nak"<<endl; //
    if (h6==h7) cout<<"h6 es h7 megegyeznek"<<endl; //
    if (h6!=h7) cout<<"h6 es h7 nem egyeznek meg"<<endl; // h6 es h7 nem egyeznek meg

    cout<<endl<<"es most legyen h6=h7"<<endl;
    h6=h7;
    cout<<"h6"<<h6<<" es h7"<<h7<<" kapcsolata:"<<endl; // h6{14.4, 31.2, 122.222, 123, 5554, 9999} es h7{14.4, 31.2, 122.222, 123, 5554, 9999} kapcsolata:
    if (h6<=h7) cout<<"h6 reszhalmaza h7-nek"<<endl; // h6 reszhalmaza h7-nek
    if (h6<h7) cout<<"h6 valodi reszhalmaza h7-nek"<<endl; //
    if (h6>=h7) cout<<"h7 reszhalmaza h6-nak"<<endl; // h7 reszhalmaza h6-nak
    if (h6>h7) cout<<"h7 valodi reszhalmaza h6-nak"<<endl; //
    if (h6==h7) cout<<"h6 es h7 megegyeznek"<<endl; // h6 es h7 megegyeznek
    if (h6!=h7) cout<<"h6 es h7 nem egyeznek meg"<<endl; //

    // Halmaz teszt: legnagyobb, legkisebb, torol függvények
    cout << endl;
    cout << "Halmaz teszt: legnagyobb, legkisebb, torol" << endl;
    cout<<h6<<" legnagyobb eleme: "<<h6.legnagyobb()<<endl; // {14.4, 31.2, 122.222, 123, 5554, 9999} legnagyobb eleme: 9999
    cout<<h6<<" legkisebb eleme: "<<h6.legkisebb()<<endl; // {14.4, 31.2, 122.222, 123, 5554, 9999} legkisebb eleme: 14.4
    h6.torol();
    cout<<"torolve: "<<h6<<endl; // torolve: {}

	return 0;
}

