
#include <iostream>
#include <limits>
#include <algorithm>

namespace doboz{

struct Doboz{
std::string nev;
unsigned int szelesseg;
unsigned int magassag;
unsigned int hosszusag;
};

int db;


void tombbeolvas(Doboz *d, int n) {
    std::cin.ignore(1, '\n');
	for (int i = 0; i < n; i++) {
        std::cout << i+1 << ". doboz neve?" << std::endl;
        std::getline(std::cin,d[i].nev);
		std::cout << i+1 << ". doboz szelessége?" << std::endl;
		std::cin >> d[i].szelesseg;
		std::cout << i+1 << ". doboz magassága?" << std::endl;
		std::cin >> d[i].magassag;
		std::cout << i+1 << ". doboz hosszúsaga?" << std::endl;
		std::cin >> d[i].hosszusag;
	}    
}
void szamolFT(Doboz d){
    unsigned int F = (d.szelesseg * d.magassag  + d.magassag  * d.hosszusag + d.szelesseg   * d.hosszusag) * 2;
    unsigned int T = d.szelesseg * d.magassag  * d.hosszusag;
    std::cout << "A doboz felszine: " << F << std::endl;
    std::cout << "A doboz térfogata: " << T << std::endl;
}


void tombkiir(Doboz *d, int n) {
	for (int i = 0; i < n; i++) {
		std::cout << i+1 << ". doboz neve: " << d[i].nev << std::endl;
		std::cout << i+1 << ". doboz szelessége: " << d[i].szelesseg << std::endl;
		std::cout << i+1 << ". doboz magassága: " << d[i].magassag << std::endl;
		std::cout << i+1 << ". doboz hosszúsaga: " << d[i].hosszusag << std::endl;
        szamolFT(d[i]);
	}
    std::cout << std::endl;
}

void tombnovel(Doboz*& d, int& db, int n){

    Doboz* ujtomb = new Doboz[db + n];
    
    for (int i=0; i<db; i++){
        ujtomb[i] = d[i];
        }

    delete[] d;            
    d=ujtomb;
    db = db + n;

}

    bool belefer(Doboz d1, Doboz d2){
    return ((d1.szelesseg < d2.szelesseg &&
        d1.hosszusag < d2.hosszusag &&
        d1.magassag < d2.magassag) ||
        (d2.szelesseg < d1.szelesseg &&
        d2.hosszusag < d1.hosszusag &&
        d2.magassag < d1.magassag));
    }

    bool belefer(Doboz d1, int sz, int m, int h){
       return (d1.szelesseg < sz && d1.hosszusag < h && d1.magassag < m);
    }


void forgat(Doboz& d){
    int temp = d.szelesseg;
    d.szelesseg = d.magassag;
    d.magassag = d.hosszusag;
    d.hosszusag = temp;
    std::cout  << "doboz elforgatva." << std::endl;
    }


} // namespace



using namespace doboz;
int main(){
	std::cout <<"Hány doboz adatát tárolja a program?" << std::endl;
	std::cin >> db;
	Doboz *dobozok = new Doboz[db];

	tombbeolvas(dobozok, db);
	tombkiir(dobozok, db);

    
    std::cout <<"Hány dobozt adjak a tömbhöz?" << std::endl;
    int novel;
	std::cin >> novel;
    tombnovel(dobozok,db,novel);
    

    for (int i = db-novel; i < db; i++){
            std::cin.ignore(1, '\n');
		std::cout << i+1 << ". doboz neve?"  << std::endl;
        std::getline(std::cin,dobozok[i].nev);
		std::cout << i+1 << ". doboz szelessége?" << std::endl;
		std::cin >> dobozok[i].szelesseg;
		std::cout << i+1 << ". doboz magassága?" << std::endl;
		std::cin >> dobozok[i].magassag;
		std::cout << i+1 << ". doboz hosszúsaga?" << std::endl;
		std::cin >> dobozok[i].hosszusag;            
        }

    std::cout << "Az új tömb nérete: " << db << std::endl;
    std::cout << "Az új tömb: " << std::endl;
	tombkiir(dobozok, db);    

    if (db >=2){
        for(int i=1;i<=db;i++){
         std::cout << "Az " << dobozok[0].nev << " doboz "  << (belefer(dobozok[0],dobozok[i]) ? "belefer" : "nem belefer" ) << " doboz " << i+1 << "-be" << std::endl;

        }
    }

     std::cout <<"adj meg 3 dimenziot?" << std::endl;
    int d1, d2, d3;
    std::cin >> d1 >> d2 >> d3;

    for (int i=0; i<db; i++){
        std::cout << "A doboz " << dobozok[i].nev <<  (belefer(dobozok[i],d1,d2,d3) ? " belefer " : " nem belefer " ) << d1 <<" "<< d2<<" "<< d3<< " méretekbe." << std::endl;
    }


    for (int i=0; i<db; i++){
        forgat(dobozok[i]);    
    }

	tombkiir(dobozok, db);
    

    delete[] dobozok;
 
	return 0;
}

























