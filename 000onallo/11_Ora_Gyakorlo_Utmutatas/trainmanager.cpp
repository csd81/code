#include "trainmanager.h"

TrainManager::TrainManager() {}

void TrainManager::addVehicle(Vehicle *v){
    v_vehicles.push_back(v);
}

void TrainManager::printAll(){
    for (Vehicle* v: v_vehicles){
        v->print();
    }
}

bool TrainManager::coupleSet(const std::vector<Vehicle *> &v_vehicle) {
    TrainSet* v_ts = new TrainSet(v_vehicle);


    if(v_ts->isValid()){
        v_sets.push_back(v_ts);
        return true;
    }
    delete v_ts;
    return false;
}

void TrainManager::printSets(){
    for (TrainSet* pts: v_sets){
        pts->printAll();
    }
}

TrainSet *TrainManager::searchSet(std::string s_engineId){
    for(unsigned int i = 0 ; i < v_sets.size(); i++){
        if (v_sets[i]->getEngine()->getId()==s_engineId){
            return v_sets[i];
        }
    }
    return nullptr;
}

void TrainManager::decoupleSet(TrainSet *p_ts)
{

    for(unsigned int i =0; i<v_sets.size(); i++){
        if(v_sets[i]==p_ts){
            delete v_sets[i];
            v_sets.erase(v_sets.begin() +i);
        }
    }


}

void TrainManager::removeVehicle(Vehicle *p_v)
{
    for(unsigned int i = 0; i<v_vehicles.size(); i++){
        if(v_vehicles[i]==p_v){
            v_vehicles.erase(v_vehicles.begin() +i);
        }
    }

}


