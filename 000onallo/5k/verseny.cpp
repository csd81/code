#include "verseny.h"
#include <sstream>
#include <string>
Verseny::Verseny(const std::string &versenyfile)
{
    std::ifstream ifs(versenyfile);
    if (!ifs){
        std::cerr << "error!\n";
    }

    getline(ifs, megnevezes);

    std::string nev;
    double tavolsag;
    bool ervenyes;
    while (ifs >> nev >>  tavolsag >> ervenyes){
        Probalkozas p(nev,tavolsag,ervenyes);
        probvec.push_back(p);
    }
}

void Verseny::kiir() const
{
    std::cout << megnevezes << std::endl;
    for (Probalkozas p: probvec){
        std::cout <<  p.getNev() << " "
            <<  p.getTavolsag() << " "
            <<  p.getErvenyes() << std::endl;
    }
    std::cout << std::endl;
}


std::ostream& Verseny::kiir(std::ostream& os) const{
    os << megnevezes << std::endl;
    for (const Probalkozas& p: probvec){
        os <<  p.getNev() << " "
                  <<  p.getTavolsag() << " "
                  <<  p.getErvenyes() << std::endl;
    }
    os << std::endl;
    return os;
}


void Verseny::kiir(const std::string &outfile) const
{
    std::stringstream ss;
    ss.clear();
    ss << megnevezes << std::endl;

    std::ofstream ofs(outfile);
    if (!ofs){
        std::cerr << "error";
    }

    for (Probalkozas p: probvec){
        ss <<  p.getNev() << " "
           <<  p.getTavolsag() << " "
           <<  p.getErvenyes() << std::endl;
    }
    ss << std::endl;

    ofs << ss.str();
}

void Verseny::uj(std::string nev, double tavolsag, bool ervenyes)
{
    Probalkozas p(nev,tavolsag,ervenyes);
    probvec.push_back(p);
}

std::vector<double> Verseny::ervenyesDobasok() const
{
    std::vector<double> erv;
    for (Probalkozas p : probvec){
        if (p.getErvenyes()==1){
            erv.push_back(p.getTavolsag());
        }
    }
    return erv;
}

void Verseny::nevSzerint(const std::string &nev, std::vector<Probalkozas> &pv) const
{
    Probalkozas p;
    pv.clear();
    for(Probalkozas p : probvec){
        if (p.getNev()==nev){
            pv.push_back(p);
        }
    }
}



