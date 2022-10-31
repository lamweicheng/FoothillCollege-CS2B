#include <iostream>
#include <ctime>
#include <cstdlib>
#include "creature.h"
#include "demon.h"
using namespace std;

namespace cs_creature {

    const double Demon::PROBABILITY_OF_DEMON_ATTACK = 0.25;

    Demon::Demon() {

    }






    Demon::Demon(int newStrength, int newHitpoints) : 
        Creature(newStrength, newHitpoints){

    }






    int Demon::getDamage() const {

        int value = Creature::getDamage();
        if (rand() % 100 * 0.01 < PROBABILITY_OF_DEMON_ATTACK)
        {
            cout << "Demonic Rage inflicts 50 additional damage points ! " << endl;
            value = (value + DEMON_ATTACK_DAMAGE);
        }
        return value;
    }






    string Demon::getSpecies() const {

        return "Demon";
    }

}