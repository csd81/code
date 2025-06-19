#include "warehouse.h"
#include "chair.h"
#include "clothes.h"
#include "toy.h"

vector<BabyProduct *> Warehouse::getProducts() const
{
    return products;
}

vector<BabyProduct *> Warehouse::getProducts(const string &type)
{
    vector<BabyProduct*> result;
    for (BabyProduct* b : products) {
        if(type=="toy" && dynamic_cast<Toy*>(b)) result.push_back(b);
        else if(type=="chair" && dynamic_cast<Chair*>(b)) result.push_back(b);
        else if(type=="clothes" && dynamic_cast<Clothes*>(b)) result.push_back(b);
    }
    return result;

}

void Warehouse::deliverShipment(Shipment &s)
{
    for (BabyProduct* b :products){
        for (auto i :s.getItems())
            if (i.productid==b->getId())
                b->setQuantity(b->getQuantity()+i.quantity);
    }
}

void Warehouse::saveProducts(const string &type, const string &filename)
{
    json out=json::array();

        vector<BabyProduct*> filtered = getProducts(type);



         for (BabyProduct* f: filtered){
             json item;
             item["Id"] = f->getId();
             item["Name"] = f->getName();
             item["Price"] = f->getPrice();
             item["Quantity"] = f->getQuantity();

             if (type=="toy"){
                Toy* t = dynamic_cast<Toy*>(f);
                if (t) item["Age"] = t->getYear();
             } else if (type=="chair"){
                Chair* c = dynamic_cast<Chair*>(f);
                if (c) item["CanBeSet"] = c->getAdjustable();
             } else if (type=="clothes"){
                Clothes* r = dynamic_cast<Clothes*>(f);
                if (r) item["Size"] = r->getSize();
             }
         out.push_back(item);


         }


    ofstream ofs(filename);
    if (ofs.is_open()) {
        ofs << out.dump(4);
        ofs.close();
    } else  {
        cerr << "Hiba: nem sikerült megnyitni a fájlt: " << filename << endl;
    }
}

Warehouse::Warehouse() {}

Warehouse::~Warehouse()
{
    for (auto p : products)
        delete p;
    products.clear();
}

void Warehouse::loadProducts(const string &type, const string &filename)
{
    ifstream ifs(filename);
    json data;
    ifs>> data;

    for (size_t i=0; i<data.size(); i++){
        string id=data[i]["Id"];
        string name=data[i]["Name"];
        int price=data[i]["Price"];
        int quantity=data[i]["Quantity"];
        if(type=="toy"){
            int age=data[i]["Age"];
            products.push_back(new Toy(id, name, price, quantity, age));
        } else if(type=="clothes"){
            string size=data[i]["Size"];
            products.push_back(new Clothes(id, name, price, quantity, size));
        } else if(type=="chair"){
            bool adjustable =data[i]["CanBeSet"];
            products.push_back(new Chair(id, name, price, quantity, adjustable));
        }
    }

}

bool Warehouse::makeOrder(const string& id, int quantity, int &cash)
{
    for (BabyProduct* b : products){
        if(b->getId() == id)
            {
            int totalPrice = b->getPrice() * quantity;
                if (b->getQuantity() >= quantity && cash >= totalPrice){
                    b->setQuantity(b->getQuantity() - quantity);
                    cash -= totalPrice;
                    return true;

            }
                else cout << "Hiba: nem stimmel valami!\n";
                return false;

        }

    }
    cout << "Hiba: ismeretlen termekazonosito.\n";
    return false;
}
























