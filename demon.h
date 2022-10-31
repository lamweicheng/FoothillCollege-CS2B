#ifndef demon_h
#define demon_h
#include "creature.h"

namespace cs_creature {

    class Demon : public Creature{

    public:
        Demon();
        Demon(int newStrength, int newHitpoints);
        int getDamage() const;
        std::string getSpecies() const;

    private:
        static const int DEMON_ATTACK_DAMAGE = 50;
        static const double PROBABILITY_OF_DEMON_ATTACK;
    };
}
#endif