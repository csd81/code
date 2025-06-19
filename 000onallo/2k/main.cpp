#include <iostream>
#include "szamok.h"


void kiirbyvalue(Tarolo::Szamok sz){
    for(int i=0; i<sz.darabLeker(); i++){
        std::cout << sz.ertekLeker(i) << " ";
    }
    std::cout << std::endl;    
}

void kiirbyref(Tarolo::Szamok& sz){
    for(int i=0; i<sz.darabLeker(); i++){
        std::cout << sz.ertekLeker(i) << " ";
    }
    std::cout << std::endl;    
}


int main(){
    
    Tarolo::Szamok sz1(4);
    Tarolo::Szamok sz2(5,5);

    sz2.ertekBeallit(3,4.5);

    kiirbyvalue(sz1);
    kiirbyref(sz2);
     
    return 0;

}