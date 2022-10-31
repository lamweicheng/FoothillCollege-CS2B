#include <iostream>
#include <ctime>
#include <cstdlib>
#include "cyberdemon.h"

using namespace std;

namespace cs_creature {

    Cyberdemon::Cyberdemon(){

    }






    Cyberdemon::Cyberdemon(int newStrength, int newhitpoints) : 
        Demon(newStrength, newhitpoints){

    }






    string Cyberdemon::getSpecies() const{

        return "Cyberdemon";
    }
}