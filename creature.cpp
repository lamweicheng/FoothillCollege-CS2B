#include <iostream>
#include <cstdlib>
#include <ctime>
#include "creature.h"
using namespace std;

namespace cs_creature {

    Creature::Creature(){
        hitpoints = DEFAULT_HITPOINTS;
        strength = DEFAULT_STRENGTH;
    }






    Creature::Creature(int newStrength, int newHitpoints)
        : strength(newStrength),
        hitpoints(newHitpoints){

    }






    void Creature::setStrength(int newStrength){

        strength = newStrength;
    }






    void Creature::setHitpoints(int newHitpoints){

        hitpoints = newHitpoints;
    }






    int Creature::getStrength(){

        return strength;
    }






    int Creature::getHitpoints(){

        return hitpoints;
    }






    int Creature::getDamage() const {

        int value;
        value = ((rand() % strength) + 1);
        cout << "The " << getSpecies() << " attacks for " << value << " points!" << endl;
        return value;

    }






    string Creature::getSpecies() const {

        return "Creature";
    }

}

