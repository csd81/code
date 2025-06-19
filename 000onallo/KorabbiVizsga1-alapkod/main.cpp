#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;


// A feladatokhoz #define direktivak kellenek, lasd: megoldott_feladatok.h
// A megoldott_feladatok.h fajlt is be kell adni!

#include "megoldott_feladatok.h"

#ifdef PART1a
#include "alkatresz.h"
#endif

#ifdef PART2
#include "processzor.h"
#endif

#ifdef PART3
#include "memoria.h"
#endif

#ifdef PART4a
#include "egyebalkatresz.h"
#endif

#ifdef PART7a
#include "csomag.h"
#endif

#ifdef PART8a
#include "kupon.h"
#endif

#ifdef PART1b
class Teszt1 : public Alkatresz
{
	int i;
public:
	Teszt1(int _i):Alkatresz("T1", "P1"),i(_i){}
	int ar() const override{
		return i*14000;
	}
};

class Teszt2 : public Alkatresz
{
	int e, a;
public:
	Teszt2(const string &_g, const string &_t, int _e, int _a):Alkatresz(_g,_t),e(_e),a(_a){}
	int ar() const override{
		return e*a;
	}
};
#endif

#ifdef PART1c
class Teszt3 : public Alkatresz
{
	int a;
public:
	Teszt3(const string &_g, const string &_t, int _a):Alkatresz(_g,_t),a(_a){}
	int ar() const override{
		return a;
	}
	void kiir() const override{
		cout << "KIIR FELULIRAS " << a << endl;
	}
};
#endif

struct TesterGuard
{
	string partname;
	TesterGuard (const string& partname);
	~TesterGuard();
};


int main()
{
	cout << "main() eleje!" << endl << endl;


#ifdef PART1a
	{
		TesterGuard tguard("PART1a");
		Alkatresz *alk1=nullptr;
		if (!alk1){
			cout << "Alkatresz virtual destruktor: " << (has_virtual_destructor<Alkatresz>::value?"IGEN":"NEM") << endl;
		}
		else
		{
			cout << alk1->getGyarto() << " " << alk1->getTipus() << endl;
		}
	}//
#endif



#ifdef PART1b
	{
		TesterGuard tguard("PART1b");
		cout << "Alkatresz absztrakt: " << (is_abstract<Alkatresz>::value?"IGEN":"NEM") << endl;
		const Alkatresz *alk1 = new Teszt1(12);
		const Alkatresz *alk2 = new Teszt2("T2", "P2", 65, 980);
		cout << alk1->getGyarto() << " " << alk1->getTipus() << " " << alk1->ar() << endl;
		cout << alk2->getGyarto() << " " << alk2->getTipus() << " " << alk2->ar() << endl;
		delete alk1;
		delete alk2;

	}//
#endif



#ifdef PART1c
	{
		TesterGuard tguard("PART1c");
		const Alkatresz *alk1 = new Teszt1(12);
		const Alkatresz *alk2 = new Teszt2("T2", "P2", 65, 980);
		const Alkatresz *alk3 = new Teszt3("T2", "P2", 36245);
		alk1->kiir();
		alk2->kiir();
		alk3->kiir();
		delete alk1;
		delete alk2;
		delete alk3;
	}//
#endif



#ifdef PART2
	{
		TesterGuard tguard("PART2");
		cout << "Processzor az Alkatresz gyerekosztalya: " << (is_base_of<Alkatresz,Processzor>::value?"IGEN":"NEM") << endl;
		Processzor p1("AMD", "R5-26000X", 3600, 6);
		Processzor p2("Intel", "i9-10900K", 3700, 10);
		const Alkatresz *alk1=&p1;
		const Alkatresz *alk2=&p2;
		cout << alk1->getGyarto() << " " << alk1->getTipus() << " " << alk1->ar() << " " << p1.getOrajel() << " " << p1.getMagok() << endl;
		cout << alk2->getGyarto() << " " << alk2->getTipus() << " " << alk2->ar() << " " << p2.getOrajel() << " " << p2.getMagok() << endl;

	}//
#endif



#ifdef PART3
	{
		TesterGuard tguard("PART3");
		cout << "Memoria az Alkatresz gyerekosztalya: " << (is_base_of<Alkatresz,Memoria>::value?"IGEN":"NEM") << endl;
		Memoria m1("Kingston", "Fury-Beast");
		Memoria m2("GSkill", "Aegis", 8, 3000);
		Memoria m3("Silicon-Power", "Turbine", 32);
		Memoria m4("Corsair", "Vengeance", 16, 3600);
		const Alkatresz *alk1=&m1;
		const Alkatresz *alk2=&m2;
		const Alkatresz *alk3=&m3;
		const Alkatresz *alk4=&m4;
		cout << alk1->getGyarto() << " " << alk1->getTipus() << " " << alk1->ar() << " " << m1.getKapacitas() << " " << m1.getSebesseg() << endl;
		cout << alk2->getGyarto() << " " << alk2->getTipus() << " " << alk2->ar() << " " << m2.getKapacitas() << " " << m2.getSebesseg() << endl;
		cout << alk3->getGyarto() << " " << alk3->getTipus() << " " << alk3->ar() << " " << m3.getKapacitas() << " " << m3.getSebesseg() << endl;
		cout << alk4->getGyarto() << " " << alk4->getTipus() << " " << alk4->ar() << " " << m4.getKapacitas() << " " << m4.getSebesseg() << endl;
	}//
#endif



#ifdef PART4a
	{
		TesterGuard tguard("PART4a");
		cout << "EgyebAlkatresz az Alkatresz gyerekosztalya: " << (is_base_of<Alkatresz,EgyebAlkatresz>::value?"IGEN":"NEM") << endl;
		EgyebAlkatresz e1("MSI", "A520M", "MSI-alaplap", 19800);
		EgyebAlkatresz e2("ASUS", "TUF-Gaming-3060", "Videokartya", 256000);
		const Alkatresz *alk1=&e1;
		const Alkatresz *alk2=&e2;
		cout << alk1->getGyarto() << " " << alk1->getTipus() << " " << alk1->ar() << " " << e1.getLeiras() << endl;
		cout << alk2->getGyarto() << " " << alk2->getTipus() << " " << alk2->ar() << " " << e2.getLeiras() << endl;
	}//
#endif



#ifdef PART4b
	{
		TesterGuard tguard("PART4b");
		EgyebAlkatresz e1("MSI", "A520M", "MSI-alaplap", 19800);
		EgyebAlkatresz e2("ASUS", "TUF-Gaming-3060", "Videokartya", 256000);
		const Alkatresz *alk1=&e1;
		const Alkatresz *alk2=&e2;
		alk1->kiir();
		alk2->kiir();
	}//
#endif



#ifdef PART5a
	{
		TesterGuard tguard("PART5a");
		const Teszt1 t1(12);
		const Teszt2 t2("T2", "P2", 65, 980);
		const Teszt1 t3(21);
		const Teszt2 t4("T2_2", "P2_2", 19, 650);
		cout << (t1<50000) << endl;
		cout << (t2<50000) << endl;
		cout << (t3<50000) << endl;
		cout << (t4<50000) << endl;
		cout << (t1<210000) << endl;
		cout << (t2<210000) << endl;
		cout << (t3<210000) << endl;
		cout << (t4<210000) << endl;
	}//
#endif



#ifdef PART5b
	{
		TesterGuard tguard("PART5b");
		const Teszt1 t1(12);
		const Teszt2 t2("T2", "P2", 65, 980);
		const Teszt1 t3(21);
		const Teszt2 t4("T2_2", "P2_2", 19, 650);
		cout << t1 << endl << t2 << endl << t3 << endl << t4 << endl;
		{
			ofstream out("out.txt");
			out << t4 << endl << t3 << endl << t2 << endl << t1 << endl;
		}
		cout << "fajlban:" << endl;
		{
			ifstream in("out.txt");
			cout << in.rdbuf();
		}
	}//
#endif



#ifdef PART5c
	{
		TesterGuard tguard("PART5c");
		const Teszt1 t1(12);
		const Teszt2 t2("T2", "P2", 65, 980);
		const Teszt1 t3(21);
		const Teszt2 t4("T2_2", "P2_2", 19, 650);
		cout << (!t1) << endl;
		cout << (!t2) << endl;
		cout << (!t3) << endl;
		cout << (!t4) << endl;
	}//
#endif



#ifdef PART6a
	{
		TesterGuard tguard("PART6a");
		cout << Alkatresz::getErtekHatar() << endl;
		Alkatresz::setErtekHatar(130000);
		cout << Alkatresz::getErtekHatar() << endl;
		Alkatresz::setErtekHatar(450000);
		cout << Alkatresz::getErtekHatar() << endl;
	}//
#endif



#ifdef PART6b
	{
		TesterGuard tguard("PART6b");
		const Teszt1 t1(10);
		const Teszt2 t2("T2", "P2", 120, 890);
		const Teszt1 t3(25);
		const Teszt2 t4("T2_2", "P2_2", 15, 750);
		cout << t1.teljesAr() << endl;
		cout << t2.teljesAr() << endl;
		cout << t3.teljesAr() << endl;
		cout << t4.teljesAr() << endl;
		cout << "-----------" << endl;
		Alkatresz::setErtekHatar(130000);
		cout << t1.teljesAr() << endl;
		cout << t2.teljesAr() << endl;
		cout << t3.teljesAr() << endl;
		cout << t4.teljesAr() << endl;
		cout << "-----------" << endl;
		Alkatresz::setErtekHatar(60000);
		cout << t1.teljesAr() << endl;
		cout << t2.teljesAr() << endl;
		cout << t3.teljesAr() << endl;
		cout << t4.teljesAr() << endl;
		Alkatresz::setErtekHatar(450000);
	}//
#endif



#ifdef PART7a
	{
		TesterGuard tguard("PART7a");
		Csomag cs(10);
		cout << cs.darabszam() << endl;
	}//
#endif



#ifdef PART7b
	{
		TesterGuard tguard("PART7b");
		Csomag cs(7);
		Teszt1 t1(12);
		Teszt2 t2("T2", "P2", 80, 1020);
		Teszt1 t3(43);
		Teszt2 t4("T2_2", "P2_2", 35, 250);
		cout << cs.darabszam() << endl;
		cs.beallit(&t3);
		cout << cs.darabszam() << endl;
		cs.beallit(&t1);
		cout << cs.darabszam() << endl;
		cs.beallit(&t2);
		cout << cs.darabszam() << endl;
		cs.beallit(&t4);
		cout << cs.darabszam() << endl;
		cs.beallit(&t2);
		cout << cs.darabszam() << endl;
		cs.beallit(&t1);
		cout << cs.darabszam() << endl;
		cs.beallit(&t4);
		cout << cs.darabszam() << endl;
		cs.beallit(&t3);
		cout << cs.darabszam() << endl;
		cs.beallit(&t1);
		cout << cs.darabszam() << endl;
	}//
#endif



#ifdef PART7c
	{
		TesterGuard tguard("PART7c");
		Csomag cs(5);
		Teszt1 t1(12);
		Teszt2 t2("T2", "P2", 85, 720);
		Teszt1 t3(26);
		Teszt2 t4("T2_2", "P2_2", 125, 125);
		cout << cs.ar() << endl;
		cs.beallit(&t3);
		cout << cs.ar() << endl;
		cs.beallit(&t1);
		cout << cs.ar() << endl;
		cs.beallit(&t2);
		cout << cs.ar() << endl;
		cs.beallit(&t4);
		cout << cs.ar() << endl;
		cs.beallit(&t4);
		cout << cs.ar() << endl;
		cs.beallit(&t3);
		cout << cs.ar() << endl;
		cs.beallit(&t1);
		cout << cs.ar() << endl;
	}//
#endif



#ifdef PART8a
	{
		TesterGuard tguard("PART8a");
		Kupon<Teszt1> k1(200);
		Kupon<Teszt2> k2(150);
		Kupon<Teszt1> k3(375);
		Kupon<Teszt2> k4(9480);
		cout << k1.getKedvezmeny() << endl;
		cout << k2.getKedvezmeny() << endl;
		cout << k3.getKedvezmeny() << endl;
		cout << k4.getKedvezmeny() << endl;
	}//
#endif



#ifdef PART8b
	{
		TesterGuard tguard("PART8b");
		Teszt1 t1(10);
		Teszt2 t2("T2", "P2", 80, 720);
		Teszt1 t3(20);
		Teszt2 t4("T2_2", "P2_2", 120, 110);
		Kupon<Teszt1> k1(9000);
		Kupon<Teszt2> k2(5600);
		cout << "eredeti: " << t1.ar() << ", 1. kupon: " << k1.alkalmaz(&t1) << ", 2. kupon: " << k2.alkalmaz(&t1) << endl;
		cout << "eredeti: " << t2.ar() << ", 1. kupon: " << k1.alkalmaz(&t2) << ", 2. kupon: " << k2.alkalmaz(&t2) << endl;
		cout << "eredeti: " << t3.ar() << ", 1. kupon: " << k1.alkalmaz(&t3) << ", 2. kupon: " << k2.alkalmaz(&t3) << endl;
		cout << "eredeti: " << t4.ar() << ", 1. kupon: " << k1.alkalmaz(&t4) << ", 2. kupon: " << k2.alkalmaz(&t4) << endl;
	}//
#endif




	cout << "main() vege!" << endl;
	return 0;
}

TesterGuard::TesterGuard(const string &p):
	partname(p)
{
	cout << endl << "----START OF " << partname << "----" << endl << endl;
}

TesterGuard::~TesterGuard()
{
	cout << endl << "----END OF " << partname << "----" << endl << endl;
}
