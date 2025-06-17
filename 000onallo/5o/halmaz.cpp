#include "halmaz.h"
#include <fstream>

Halmaz::Halmaz(string m) : megnevezes(m)
{

}

Halmaz::Halmaz(string m, int e) : megnevezes(m)
{
    for(int i=0; i< e; i++){
        tarolo.push_back(Pont());
    }
}

void Halmaz::hozzaad(Pont p)
{
    tarolo.push_back(p);
}

void Halmaz::hozzaad(double x, double y){
        tarolo.push_back(Pont(x, y));
}

void Halmaz::kiir() const
{
    std::cout << megnevezes << " " << tarolo.size() << " ";
    for (const Pont& p : tarolo){
         p.kiir();
         cout << " ";
    }
    std::cout << std::endl;
}

void Halmaz::beolvas(const string &filename)
{
    tarolo.clear();
    int mennyi;
    ifstream ifs(filename);
    ifs >> mennyi;
    for (int i=0; i< mennyi; ++i){
        int a, b;
        ifs >> a >> b;
        tarolo.push_back(Pont(a,b));
    }
}

void Halmaz::fajlbair(const string &filename) const
{
    ofstream ofs(filename);
    ofs << megnevezes << std::endl;
    for (Pont p : tarolo){
        ofs << p.getX() << " " << p.getY() << std::endl;
    }
    ofs.close();
}
















