#ifndef creature_h
#define creature_h
#include <iostream>
using namespace std;

namespace cs_creature {

    class Creature {

    private:
        int strength;
        int hitpoints;
        static const int DEFAULT_HITPOINTS = 10;
        static const int DEFAULT_STRENGTH = 10;


    public:
        Creature();
        Creature(int newStrength, int newHitpoints);
      
        virtual int getDamage() const;
        virtual std::string getSpecies() const = 0;
        int getHitpoints();
        int getStrength();
        void setHitpoints(int newHitpoints);
        void setStrength(int newStrength);


    };
}
#endif