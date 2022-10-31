#ifndef elf_h
#define elf_h
#include "creature.h"

namespace cs_creature {

    class Elf :public Creature{

    public:
        Elf();
        Elf(int newStrength, int newHitpoints);
        int getDamage() const;
        std::string getSpecies() const;

    private:
        static const double PROBABILITY_OF_MAGICAL_ATTACK;
    };
}
#endif
