#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ostream &operator<<(ostream &os, const vector<int> &vec)
{
    for (int i=0; i<vec.size(); i++)
    {
        os << vec[i] << ";";
    }
    return os;
}

int main()
{
    vector<int> intek(10);

    ifstream bemenet("bemenet.txt");
    if (!bemenet.is_open())
    {
        cout << "Cannot open file" << endl;
        return -1;
    }
    for (int i=0; i<intek.size(); i++)
        bemenet >> intek[i];

    // ofstream kimenet("out.txt", ios::app); // append
    ofstream kimenet("out.txt"); // overwrite
    if (!kimenet.is_open())
    {
        cout << "Cannot write file" << endl;
        return -1;
    }
    // for (int i=0; i<intek.size(); i++)
    //     cout << intek[i] << endl;
    // for (int i=0; i<intek.size(); i++)
    //     kimenet << intek[i] << endl;
    cout << intek << endl;
    kimenet << intek << endl;


    // intek.resize(15);
    intek.push_back(1224);




    return 0;
}
