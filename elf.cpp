#include <iostream>
#include <ctime>
#include <cstdlib>
#include "creature.h"
#include "elf.h"
using namespace std;

namespace cs_creature {

    const double Elf::PROBABILITY_OF_MAGICAL_ATTACK = 0.5;

    Elf::Elf(){

    }






    Elf::Elf(int newStrength, int newHitpoints) :
        Creature(newStrength, newHitpoints){

    }






    int Elf::getDamage() const{

        int value = Creature::getDamage();
        int randValue = (rand() % 100 * 0.01);
        if (randValue <= PROBABILITY_OF_MAGICAL_ATTACK)
        {
            cout << "Magical attack inflicts " << value << " additional damage! " << endl;
            value = (value * 2);
        }
        return value;
    }






    string Elf::getSpecies() const{

        return "Elf";
    }

}