#include "actionlist.h"

ActionList::ActionList(const string &file)
{
    ifstream infile(file);
    if (!infile) {
        cerr << "hiba!\n";
        return;
    }

    string id1, id2;
    while (infile >> id1 >> id2) {
        actions.push_back({id1, id2});
    }

    infile.close();
}

void ActionList::printPairs() const
{
    for (const auto& action : actions) {
        cout << action.id1 << " -> "    << action.id2 << "\n";
    }
}

const vector<ActionList::Action> &ActionList::getPairs() const
{
    return actions;

}
