#ifndef SICT_SUPERHERO_H_
#define SICT_SUPERHERO_H_
#include "Hero.h"
#include <iostream>

using namespace std;

namespace sict {


	class SuperHero : public Hero {
		unsigned int sPower;
		unsigned int sDef;

	public:
		SuperHero();
		SuperHero(const char* n, unsigned int hp, unsigned int atk, unsigned int bonus, unsigned int def);
		int attackStrength() const;
		int defend();
		void fight(SuperHero & ahero);
		friend ostream& operator<<(ostream& os, const SuperHero& hero);

	};
	const SuperHero& operator*(const SuperHero& first, const SuperHero& second);
	ostream& operator<<(ostream& os, const SuperHero& hero);
	


}






#endif