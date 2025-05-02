#include <iostream>



namespace doboz {

struct Doboz {
 std::string nev;
 unsigned int sz;
 unsigned int m;
 unsigned int h;
};


 void showBox(const Doboz t[], int m) {
 for (int i = 0; i < m; ++i) {
 std::cout << (i + 1) << "dik doboz"
 << "neve" << t[i].nev
 << "sz:" << t[i].sz
 << "m:" << t[i].m
 << "h:" << t[i].h;
 }
 }

 void surfaceAreaVolume(const Doboz d){
 std::cout << "surfaceArea: " << 2*( d.sz * d.m + d.sz * d.h + d.m * d.h ) ;
 std::cout << "Volume:" << d.sz * d.m * d.h ;

 }






 Doboz* novelTomb(Doboz* regiT, int& regiM, int incr){

  int ujM = regiM + incr;
  Doboz* ujT = new Doboz[ujM];

  for (int i=0; i<regiM; i++){
   ujT[i] = regiT[i];

  }

  delete[] regiT;
  regiM = ujM;

  return ujT;
 }




 bool belefer(const Doboz& a, const Doboz& b){
  return   a.sz <= b.sz && a.m <= b.m &&    a.h <= b.h;

 }


 bool beleferBarmelyik(const Doboz& d1, const Doboz& d2) {
  return belefer(d1, d2) || belefer(d2, d1);
 }


 bool belefer(const Doboz& d, unsigned int helySzelesseg,
                    unsigned int helyMagassag,
                    unsigned int helyHosszusag) {
     return d.sz <= helySzelesseg &&
            d.m <= helyMagassag &&
            d.h <= helyHosszusag;
 } //overloaded fn.


 void forgat(Doboz& d) {
     unsigned int temp = d.sz;
     d.sz = d.m;
     d.m  = d.h;
     d.h = temp;
 }



} // end of ns.
using namespace doboz; // NS

int main()
{
 int db;
 std::cout << "Hany dobozt szeretnel megadni? ";
 std::cin >> db;

 Doboz* tomb = new Doboz[db];


 for (int i = 0; i < db; ++i) {
 std::cout << "nev: ";
 std::cin >> tomb[i].nev;
 std::cout << "sz: ";
 std::cin >> tomb[i].sz;
 std::cout << "m: ";
 std::cin >> tomb[i].m;
 std::cout << "h: ";
 std::cin >> tomb[i].h;
 }
 showBox(tomb,db);




 int plusz;
 std::cout << "\nHany uj dobozt szeretnel hozzaadni? ";
 std::cin >> plusz;

 tomb = novelTomb(tomb, db, plusz);

 for (int i = db - plusz; i < db; ++i) {
  std::cout << "\n[Uj " << i + 1 << ". Doboz]\n";
  std::cout << "Nev: ";
  std::cin >> tomb[i].nev;
  std::cout << "Szelesseg: ";
  std::cin >> tomb[i].sz;
  std::cout << "Magassag: ";
  std::cin >> tomb[i].m;
  std::cout << "Hosszusag: ";
  std::cin >> tomb[i].h;
 }

 showBox(tomb,db);










 delete[] tomb;
 return 0;
}
