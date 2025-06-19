#include "trainset.h"



TrainSet::TrainSet(const std::vector<Vehicle *> &set) : v_set(set)
{


}

Engine *TrainSet::getEngine() const
{
    int i_engineCount {0};
    unsigned int index;
    for (unsigned int i=0; i<v_set.size(); i++){
        if (v_set[i]->getType()=="ENGINE"){
            index=i;
            i_engineCount++;
        }
        if(i_engineCount==1){
            Engine* e = dynamic_cast<Engine*>(v_set[index]);
            return e;
            }
    }
    return nullptr;
}

bool TrainSet::engineCanTow() const
{
    int total_weight =0;

    for (Vehicle* pv: v_set){
        total_weight += pv->getMass();
    }
    return (total_weight <= this->getEngine()->getMaxMass());
}

bool TrainSet::isValid() const
{
    return (engineCanTow() && getEngine()!=nullptr && v_set.size()>1);
}

void TrainSet::printAll() const
{
    for (Vehicle* pv: v_set){
        pv->print();
    }
}
