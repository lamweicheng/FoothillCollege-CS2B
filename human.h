#ifndef human_h
#define human_h
#include "creature.h"

namespace cs_creature {

    class Human :public Creature{

    public:
        Human();
        Human(int newStrength, int newHitpoints);
        std::string getSpecies() const;
    };
}
#endif
