#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "pont.h"
#include "halmaz.h"
#include "utvonal.h"
#include "haromszog.h"
#include "teglalap.h"
#include "sokszog.h"

int main()
{
    cout << "main() eleje!" << endl << endl;
    {
        ofstream ki("warnings.log");
        // igy minden futtatas ures warnings.log fajllal indul
    }

    {
        cout << "Pont: alap funkcionalitas teszt" << endl;
        Pont p1(-3,4), p2(5.2,-6);
        cout << p1.getX() << " " << p1.getY() << endl;
        p2.kiir(std::cout);
        cout << endl;
        cout << Pont::tavolsag(p1,p2) << endl;
        cout << endl;
    }
    // -3 4
    // (5.2,-6)
    // 12.9321

   {
       cout << "Pont: parameter nelkuli konstruktor teszt" << endl;
       Pont p1;
       p1.kiir(std::cout);
       cout << endl << endl;
   }
   // (0,0)

   {
       cout << "Pont: setM(), getM() teszt" << endl;
       cout << Pont::getM() << endl;
       Pont::setM(1000);
       cout << Pont::getM() << endl;
       cout << endl;
   }
   // 1e+06
   // 1000

   {
       cout << "Pont: M ellenorzese konstruktorban" << endl;
       Pont p1(0.1,7), p2(0,0), p3(-3,-7);
       cout << "... eddig semmi ..." << endl;
       Pont p4(1212319.24,-9), p5(1.34,-1e9);
       Pont p6=p4;
       p6.kiir(std::cout);
       cout << endl << "warnings.log tartalma:" << endl;
       {
           ifstream in("warnings.log");
           cout << in.rdbuf();
       }
       cout << endl;
   }
   // ... eddig semmi ...
   // Figyelem: Pont limiten tul! (1.21232e+06,-9)
   // Figyelem: Pont limiten tul! (1.34,-1e+09)
   // Figyelem: Pont limiten tul! (1.21232e+06,-9)
   // (1.21232e+06,-9)
   // warnings.log tartalma:
   // Figyelem: Pont limiten tul! (1.21232e+06,-9)
   // Figyelem: Pont limiten tul! (1.34,-1e+09)
   // Figyelem: Pont limiten tul! (1.21232e+06,-9)

   {
       cout << "Halmaz: konstruktorok, hozzaad(), kiir()" << endl;
       {
           Halmaz h1("halmaz1");
           h1.hozzaad(Pont(3.2,4.44));
           h1.hozzaad(Pont(-5.1,0));
           h1.hozzaad(99.3,1.14);
           h1.kiir(std::cout);
       }
       {
           Halmaz h2("halmaz2",5);
           h2.hozzaad(Pont(-0.1,-0.02));
           h2.hozzaad(Pont(30,400));
           h2.kiir(std::cout);
       }
       cout << endl;
   }
   // halmaz1 [3]:(3.2,4.44)(-5.1,0)(99.3,1.14)
   // halmaz2 [7]:(0,0)(0,0)(0,0)(0,0)(0,0)(-0.1,-0.02)(30,400)

   {
       cout << "Halmaz: beolvas() teszt" << endl;
       Halmaz h3("halmaz3");
       h3.hozzaad(987.987,123.123);
       h3.hozzaad(987.987,123.123);
       h3.hozzaad(987.987,123.123);
       h3.beolvas("halmaz3.txt");
       h3.kiir(std::cout);
       cout << endl;
   }
   // halmaz3 [7]:(1,9)(2,8)(3,7)(4,6)(5,5)(6,4)(7,3)

   {
       cout << "Halmaz: fajlbair() teszt" << endl;
       Halmaz h4("halmaz4");
       h4.hozzaad(10.1,-20.2);
       h4.hozzaad(30.3,-40.4);
       h4.hozzaad(50.5,-60.6);
       h4.hozzaad(70.7,-80.8);
       const string tesztfajl = "fajlbair-teszt.txt";
       {
           ofstream out(tesztfajl);
           out << 3 << endl;
           for (size_t i=0;i<3;i++)
               out << 987.987 << ' ' << 123.123 << endl;
       }
       h4.fajlbair(tesztfajl);
       Halmaz h5("halmaz5");
       h5.beolvas(tesztfajl);
       h5.kiir(std::cout);
       cout << endl;
   }
   // halmaz5 [4]:(10.1,-20.2)(30.3,-40.4)(50.5,-60.6)(70.7,-80.8)

   {
       cout << "Utvonal: konstruktor teszt" << endl;
       Utvonal u1;
       Halmaz& h = u1;
       h.hozzaad(6.6,7.7);
       h.hozzaad(-8.8,-9.9);
       h.hozzaad(11.0,12.1);
       h.hozzaad(0,0.01);
       h.kiir(std::cout);
       cout << endl;
   }
   // PATH [4]:(6.6,7.7)(-8.8,-9.9)(11,12.1)(0,0.01)

   {
       cout << "Utvonal: irany, megfordit(), kiir()" << endl;
       Utvonal u2;
       u2.hozzaad(0,1);
       u2.hozzaad(2,3);
       u2.hozzaad(4,5);
       u2.hozzaad(6,7);
       u2.hozzaad(8,9);
       u2.kiir(std::cout);
       u2.megfordit();
       u2.kiir(std::cout);
       u2.megfordit();
       u2.kiir(std::cout);
       cout << endl;
   }
   // PATH [5]:(0,1)(2,3)(4,5)(6,7)(8,9)
   // PATH [5]:(8,9)(6,7)(4,5)(2,3)(0,1)
   // PATH [5]:(0,1)(2,3)(4,5)(6,7)(8,9)

   {
       cout << "Utvonal: hossz() teszt" << endl;
       Utvonal u3;
       vector<Pont> tesztpontok {
           {0,0}, {2,3}, {-1,7}, {9,4}, {11.6,2}
       };
       for (size_t i=0;i<tesztpontok.size();i++)
       {
           u3.hozzaad(tesztpontok[i]);
           cout << u3.hossz() << endl;
       }
       cout << endl;
   }
   // 0
   // 3.60555
   // 8.60555
   // 19.0459
   // 22.3261

   {
       cout << "Haromszog: konstruktor, getA(), getB(), getC()" << endl;
       Haromszog hszg1(Pont(9.2,1.3),Pont(0,0.1),Pont(-2,-3.7));
       Halmaz& h = hszg1;
       h.kiir(std::cout);
       hszg1.getA().kiir(std::cout);
       cout << endl;
       hszg1.getB().kiir(std::cout);
       cout << endl;
       hszg1.getC().kiir(std::cout);
       cout << endl << endl;
   }
   // TRIANGLE [3]:(9.2,1.3)(0,0.1)(-2,-3.7)
   // (9.2,1.3)
   // (0,0.1)
   // (-2,-3.7)

   {
       cout << "Haromszog: alak() teszt" << endl;
       const Haromszog hszg2(Pont(0,0),Pont(3,0),Pont(0.15,4));
       const Haromszog hszg3(Pont(0,0),Pont(3,0),Pont(0,4));
       const Haromszog hszg4(Pont(0,0),Pont(3,0),Pont(-0.15,4));
       cout << hszg2.alak() << endl;
       cout << hszg3.alak() << endl;
       cout << hszg4.alak() << endl;
       cout << endl;
   }
   // hegyesszogu
   // derekszogu
   // tompaszogu

   {
       cout << "Teglalap: konstruktor teszt" << endl;
       Teglalap t1(-2,4,-3,5);
       Halmaz& h = t1;
       cout << "Megjegyzes: a csucsok sorrendje elterhet!" << endl;
       h.kiir(std::cout);
       cout << endl;
   }
   // Megjegyzes: a csucsok sorrendje elterhet!
   // RECTANGLE [4]:(-2,-3)(-2,5)(4,5)(4,-3)

   {
       cout << "Teglalap: terulet() teszt" << endl;
       const Teglalap t2(-10.1,20.2,-30.3,40.4);
       double terulet = t2.terulet();
       cout << terulet << endl << endl;
   }
   // 2142.21

   {
       cout << "Teglalap: tartalmaz() teszt" << endl;
       const Teglalap t3(-100,200,300,400);
       vector<Pont> tesztpontok {
           {-100.1,299.9},{-99.9,299.9},{199.9,299.9},{200.1,299.9},
           {-100.1,300.1},{-99.9,300.1},{199.9,300.1},{200.1,300.1},
           {-100.1,399.9},{-99.9,399.9},{199.9,399.9},{200.1,399.9},
           {-100.1,400.1},{-99.9,400.1},{199.9,400.1},{200.1,400.1},
       };
       for (size_t i=0;i<4;i++)
       {
           for (size_t j=0;j<4;j++)
           {
               bool eredmeny = t3.tartalmaz(tesztpontok[4*i+j]);
               cout << eredmeny << " ";
           }
           cout << endl;
       }
       cout << endl;
   }
   // 0 0 0 0
   // 0 1 1 0
   // 0 1 1 0
   // 0 0 0 0

   {
       cout << "Sokszog: konstruktor teszt" << endl;
       Sokszog s1("sokszog_1");
       Halmaz& h = s1;
       h.hozzaad(2.1,2);
       h.hozzaad(4.2,1.9);
       h.hozzaad(5.1,7.3);
       h.hozzaad(3,8.2);
       h.hozzaad(1.1,4.7);
       h.kiir(std::cout);
       cout << endl;
   }
   // sokszog_1 [5]:(2.1,2)(4.2,1.9)(5.1,7.3)(3,8.2)(1.1,4.7)

   {
       cout << "Sokszog: kerulet() teszt" << endl;
       Sokszog s2("sokszog_2");
       vector<Pont> tesztpontok {
           {2.1,2}, {4.2,1.9}, {5.1,7.3}, {3.8,2}, {1.1,4.7},
       };
       for (size_t i=0;i<tesztpontok.size();i++)
       {
           s2.hozzaad(tesztpontok[i]);
           double kerulet = s2.kerulet();
           cout << kerulet << endl;
       }
       cout << endl;
   }
   // 0
   // 4.20476
   // 13.667
   // 14.734
   // 19.7316

   {
       cout << "Sokszog: kerulet() teszt" << endl;
       Sokszog s2("sokszog_2");
       vector<Pont> tesztpontok {
           {2.1,2}, {4.2,1.9}, {5.1,7.3}, {3.8,2}, {1.1,4.7},
       };
       for (size_t i=0;i<tesztpontok.size();i++)
       {
           s2.hozzaad(tesztpontok[i]);
           double kerulet = s2.kerulet();
           cout << kerulet << endl;
       }
       cout << endl;
   }

   {
       cout << "Sokszog: bennfoglalo() teszt" << endl;
       Sokszog s3("sokszog_3");
       vector<Pont> tesztpontok {
           {2.1,2}, {4.2,1.9}, {5.1,7.3}, {3.8,2}, {1.1,4.7},
       };
       for (size_t i=0;i<tesztpontok.size();i++)
           s3.hozzaad(tesztpontok[i]);
       const Teglalap tb = s3.bennfoglalo();
       cout << "Megjegyzes: a csucsok sorrendje elterhet!" << endl;
       tb.kiir(std::cout);
       cout << endl;
   }
   // Megjegyzes: a csucsok sorrendje elterhet!
   // RECTANGLE [4]:(1.1,1.9)(1.1,7.3)(5.1,7.3)(5.1,1.9)

    cout << "main() vege!" << endl;
    return 0;
}
