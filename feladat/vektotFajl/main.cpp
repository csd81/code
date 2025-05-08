#include <iostream>
#include <vector>
//#include <algorithm>
#include <fstream>

using namespace std;

ostream &operator << (ostream &os, const vector<int> &vec){

    for (int i=0; i<vec.size(); i++){
        os << vec[i] << "; ";
    }
    return os;
}

int main()
{

ifstream be("be.txt");

if (!be.is_open()){
    cout << "NOT";
    return -1;
}


vector<int> intek(10);

    for (int i=0; i<intek.size(); i++){
    be >> intek[i];
    }


be.close();

// std::sort(intek.begin(), intek.end());


//  for (int i=0; i<intek.size(); i++){
//      cout << intek[i] << " ";
//  }


//  for (int i=0; i<intek.size(); i++){
     //ki << intek[i] << "\n";
 // }


ofstream kimenet("out.txt");
 cout << intek << endl;
 kimenet << intek  << endl;

 kimenet.close();

return 0;
}




