#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "balrog.h";
#include "demon.h"
using namespace std;

namespace cs_creature {

    Balrog::Balrog() {
  
    }






    Balrog::Balrog(int newStrength, int newHitpoints) : Demon(newStrength, newHitpoints)
    {
    }






    int Balrog::getDamage(){

        int value = Demon::getDamage();
        int randValue = ((rand() % Balrog::getStrength()) + 1);
        cout << "Balrog speed attack inflicts " << randValue <<
            " additional damage points" << endl;
        value = (value + randValue);
        return value;
    }






    string Balrog::getSpecies()const{

        return "Balrog";
    }

}
