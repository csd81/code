#include <iostream>
#include <string>


using namespace std;


class Szamok{    
private:
    double *tomb;
    unsigned int meret;
public:
    unsigned int getMeret(){
        return meret; 
    }
    void init(Szamok* this, unsigned int m){
        this->meret = m;
        this->tomb = new double[m];
    }

};




/* struct SzamokS{    
{
    double *tomb;
    unsigned int meret;
}

unsigned int getMeret(SzamokS &sz) 
{
    return sz.meret; 
}



void init(SzamokS &sz, unsigned int meret)
{
    sz.meret = meret;
    sz.tomb = new double[meret];
}
 */


int main(){

    Szamok sz;
    sz.init(6);
    cout << sz.getMeret() << endl;
    

    Szamok sz2;
    sz2.init(10);
    cout << sz2.getMeret() << endl;

    // SzamokS s; 
    // init(s, 10);
    // cout << getMeret(s) << endl;



    return 0;
}
