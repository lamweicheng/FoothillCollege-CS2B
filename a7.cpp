#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include "creature.h"
#include "demon.h"
#include "human.h"
#include "elf.h"
#include "cyberdemon.h"
#include "balrog.h"

using namespace std;
using namespace cs_creature;

void battleArena(Creature& Creature1, Creature& Creature2);


int main(){

	srand(static_cast<unsigned>(time(nullptr)));

	Elf Elvia(150, 75);
	Balrog Bodo(50, 50);
	Cyberdemon Cyberz(70, 100);
	Human Derrick(20, 155);

	cout << "-----First Battle: Elf vs Human-----" << endl;
	battleArena(Elvia, Derrick);
	cout << endl << endl;
	
	cout << "-----Second Battle: Balrog vs Cyberdemon-----" << endl;
	battleArena(Bodo, Cyberz);
	cout << endl << endl;

	cout << "-----Third Battle: Balrog vs Human-----" << endl;
	battleArena(Bodo, Derrick);
	cout << endl << endl;

	cout << "-----Fourth Battle: Cyberdemon vs Elf-----" << endl;
	battleArena(Cyberz, Elvia);
	cout << endl << endl;
}






void battleArena(Creature& Creature1, Creature& Creature2) {

	int newHitpointsC1 = Creature1.getHitpoints();
	int newHitpointsC2 = Creature2.getHitpoints();

	while (true) {

		cout << Creature1.getSpecies() << " has " << newHitpointsC1 <<
			" hitpoints remaining while " << Creature2.getSpecies() <<
			" has " << newHitpointsC2 << " remaining." << endl;

		newHitpointsC1 -= Creature2.getDamage();
		newHitpointsC2 -= Creature1.getDamage();

		if (newHitpointsC1 <= 0 && newHitpointsC2 <= 0) {

			cout << "It's a tie" << endl;
			return;
		}

		else if (newHitpointsC1 <= 0) {

			cout << Creature2.getSpecies() << " win!" << endl;
			return;
		}

		else if (newHitpointsC2 <= 0) {

			cout << Creature1.getSpecies() << " win!" << endl;
			return;
		}
	}

}



/*------------------------------ Paste of Run #1 ------------------------------
-----First Battle: Elf vs Human-----
Elf has 75 hitpoints remaining while Human has 155 remaining.
The Human attacks for 3 points!
The Elf attacks for 129 points!
Elf has 72 hitpoints remaining while Human has 26 remaining.
The Human attacks for 9 points!
The Elf attacks for 13 points!
Elf has 63 hitpoints remaining while Human has 13 remaining.
The Human attacks for 4 points!
The Elf attacks for 114 points!
Elf win!


-----Second Battle: Balrog vs Cyberdemon-----
Balrog has 50 hitpoints remaining while Cyberdemon has 100 remaining.
The Cyberdemon attacks for 49 points!
The Balrog attacks for 25 points!
Balrog has 1 hitpoints remaining while Cyberdemon has 75 remaining.
The Cyberdemon attacks for 7 points!
The Balrog attacks for 40 points!
Cyberdemon win!


-----Third Battle: Balrog vs Human-----
Balrog has 50 hitpoints remaining while Human has 155 remaining.
The Human attacks for 4 points!
The Balrog attacks for 25 points!
Balrog has 46 hitpoints remaining while Human has 130 remaining.
The Human attacks for 20 points!
The Balrog attacks for 49 points!
Balrog has 26 hitpoints remaining while Human has 81 remaining.
The Human attacks for 6 points!
The Balrog attacks for 16 points!
Balrog has 20 hitpoints remaining while Human has 65 remaining.
The Human attacks for 19 points!
The Balrog attacks for 26 points!
Balrog has 1 hitpoints remaining while Human has 39 remaining.
The Human attacks for 16 points!
The Balrog attacks for 41 points!
It's a tie


-----Fourth Battle: Cyberdemon vs Elf-----
Cyberdemon has 100 hitpoints remaining while Elf has 75 remaining.
The Elf attacks for 138 points!
The Cyberdemon attacks for 68 points!
Elf win!


(process 8808) exited with code 0.
Press any key to close this window . . .

----------------------------------------------------------------------------*/