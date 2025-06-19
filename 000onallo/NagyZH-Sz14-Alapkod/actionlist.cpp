#include "actionlist.h"

vector<string> ActionList::getId1() const
{
    return id1;
}

vector<string> ActionList::getId2() const
{
    return id2;
}

ActionList::ActionList(const string & filename)
{

    ifstream ifs(filename);
    if (!ifs.is_open()) {
        cerr << "error";
        return;
        }
        string s1, s2;
    while(ifs >>s1 >>s2){
        id1.push_back(s1);
        id2.push_back(s2);
        }
}

void ActionList::printSome()
{
    for (size_t i=0; i<std::min(size_t(3), id1.size()); i++)
        cout << id1[i] << " " << id2[i] << endl;

}
