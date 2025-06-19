#include "purchase.h"


Purchase::Purchase(const string &filename)
{
    ifstream ifs(filename);
    if (!ifs.is_open()) {
    cerr << "Nem sikerült megnyitni: " << filename << endl;
    return;
}

    json data;
    ifs >> data;

    for (size_t i=0; i<data.size(); i++){
    Item item;
        item.Name = data[i]["Name"];
        item.UnitPrice = data[i]["UnitPrice"];
        item.QuantityValue =data[i]["Quantity"]["Value"];
        item.QuantityUnit = data[i]["Quantity"]["Unit"];
        items.push_back(item);
    }
}

void Purchase::print()
{
    for (auto i : items)
        i.printdata();
}

double Purchase::getTotal()
{
    double total = 0.0;
    for (auto i : items)
        total +=i.UnitPrice * i.QuantityValue;
     return   total ;
}

double Purchase::useCoupons(Wallet & w)
{

    //int discount =0;



    double total = 0.0;
    for (auto i : items)
        total +=i.UnitPrice * i.QuantityValue;

    for (auto k : w.getKuponok()){
        if (total>0)
            if (k->isValid()) total -= k->usethis();
    }
    total = (total<0? 0:total);

    return    total;

}


void Purchase::Item::printdata() const
{

        cout << "Name: " << Name  << " Unit Price: " << UnitPrice  << " Quantity: " << QuantityValue  << " " << QuantityUnit << endl;


}
