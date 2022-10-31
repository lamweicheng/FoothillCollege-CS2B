#ifndef balrog_h
#define balrog_h
#include "demon.h"
#include <iostream>

namespace cs_creature {

    class Balrog :public Demon{

    public:
        Balrog();
        Balrog(int newStregth, int newHitpoints);
        int getDamage();
        std::string getSpecies()const;
    };
}
#endif
