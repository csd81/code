#include "szovegesszin.h"

SzovegesSzin::SzovegesSzin(const string& szoveg) : RGBSzin(0, 0, 0), szoveg(szoveg) {

if(szoveg=="fekete"||szoveg=="#000000"){ setRGB(0,0,0);}
else if(szoveg=="feher"||szoveg=="#FFFFFF"){ setRGB(255,255,255);}
else if(szoveg=="kek"||szoveg=="#0000FF"){ setRGB(0,0,255);}
else if(szoveg=="zold"||szoveg=="#00FF00"){setRGB(0,255,0);}
else if(szoveg=="piros"||szoveg=="#FF0000"){setRGB(255,0,0);}
else if(szoveg=="cian"||szoveg=="#00FFFF"){setRGB(0,255,255);}
else if(szoveg=="magenta"||szoveg=="#FF00FF"){setRGB(255,0,255);}
else if(szoveg=="sarga"||szoveg=="#FFFF00"){setRGB(255,255,0);}
else {setRGB(0,0,0);}

}

SzovegesSzin &SzovegesSzin::operator=(const SzovegesSzin &masik)
{
    if(this!=&masik){
    setRGB(masik.R(), masik.G(), masik.B());
    this->szoveg = masik.szoveg;
    }

    return *this;
}

string SzovegesSzin::printCode() const
{
     if (R()==0 &&   G()==0 &&    B()==0) return "fekete";
     else if (R()==255 &&   G()==255 &&    B()==255) return "feher";
     else if (R()==0 &&   G()==0 &&    B()==255) return "kek";
     else if (R()==0 &&   G()==255 &&    B()==0) return "zold";
     else if (R()==255 &&   G()==0 &&    B()==0) return "piros";
     else if (R()==0 &&   G()==255 &&    B()==255) return "cian";
     else if (R()==255 &&   G()==0 &&    B()==255) return "magenta";
     else if (R()==255 &&   G()==255 &&    B()==0) return "sarga";
     else return "";
}
