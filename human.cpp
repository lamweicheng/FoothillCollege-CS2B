#include <iostream>
#include <ctime>
#include <cstdlib>
#include "creature.h"
#include "human.h"
using namespace std;

namespace cs_creature {

    Human::Human(){

    }






    Human::Human(int newStrength, int newHitpoints) 
        : Creature(newStrength, newHitpoints){

    }






    string Human::getSpecies()const{

        return "Human";
    }

}