#include "szovegesszin.h"


SzovegesSzin::SzovegesSzin(const std::string &szoveg)
    : RGBSzin(
          szoveg=="fekete" ? 0 :
              szoveg=="feher" ? 255 :
              szoveg=="kek" ? 0 :
              szoveg=="zold" ? 0 :
              szoveg=="piros" ? 255 :
              szoveg=="cian" ? 0 :
              szoveg=="magenta" ? 255 :
              szoveg=="sarga" ? 255 :
              szoveg[0]=='#' ? hexatSzamma(szoveg[1])*16 + hexatSzamma(szoveg[2]) :
              0,

          szoveg=="fekete" ? 0 :
              szoveg=="feher" ? 255 :
              szoveg=="kek" ? 0 :
              szoveg=="zold" ? 255 :
              szoveg=="piros" ? 0 :
              szoveg=="cian" ? 255 :
              szoveg=="magenta" ? 0 :
              szoveg=="sarga" ? 255 :
              szoveg[0]=='#' ? hexatSzamma(szoveg[3])*16 + hexatSzamma(szoveg[4]) :
              0,

          szoveg=="fekete" ? 0 :
              szoveg=="feher" ? 255 :
              szoveg=="kek" ? 255 :
              szoveg=="zold" ? 0 :
              szoveg=="piros" ? 0 :
              szoveg=="cian" ? 255 :
              szoveg=="magenta" ? 255 :
              szoveg=="sarga" ? 0 :
              szoveg[0]=='#' ? hexatSzamma(szoveg[5])*16 + hexatSzamma(szoveg[6]) :
              0
          ),
    szoveg(szoveg) {}



std::string SzovegesSzin::printCode() const
{

    if ((R()==0) && (G()==0) && (B()==0)) return "fekete";
    else if ((R()==255) && (G()==255) && (B()==255)) return "feher";
    else if ((R()==0) && (G()==0) && (B()==255)) return "kek";
    else if ((R()==0) && (G()==255) && (B()==0)) return "zold";
    else if ((R()==255) && (G()==0) && (B()==0)) return "piros";
    else if ((R()==0) && (G()==255) && (B()==255)) return "cian";
    else if ((R()==255) && (G()==0) && (B()==255)) return "magenta";
    else if ((R()==255) && (G()==255) && (B()==0)) return "sarga";
    else return szoveg;
}
