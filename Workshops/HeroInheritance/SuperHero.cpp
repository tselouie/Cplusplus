#include "SuperHero.h"
#include <iostream>
#include <cstring>
#include <string>

using namespace std;
using namespace sict;

namespace sict {
	SuperHero::SuperHero()
	{
		Hero();
		
	}

	SuperHero::SuperHero(const char * n, unsigned int hp, unsigned int atk, unsigned int bonus, unsigned int def)
	{
		int len = strlen(n);
		std::strncpy(name, n, len+1);
		name[len + 1] = '\0';
		health = hp;
		strength = atk;
		sPower = bonus;
		sDef = def;
	}

	int SuperHero::attackStrength() const
	{
		int str;
		if (name[0] == '0') {
			str = 0;
		}
		else {
			str = strength + sPower;
		}
		return str;
	}

	int SuperHero::defend()
	{
		return sDef;
	}

	void SuperHero::fight(SuperHero& ahero)
	{
		
		ahero -= attackStrength() - ahero.defend();
	}

	//hero fight Overload for SuperHero vs SuperHero
	const SuperHero & operator*(const SuperHero & first, const SuperHero & second)
	{
		const SuperHero *winner = nullptr;
		SuperHero A = first;
		SuperHero B = second;
		int i = 0; //rounds
		std::cout << "Super Fight! " << A << " vs " << B << " : ";
	

		while (A.isAlive() && B.isAlive() && i < max_rounds) {
			A.fight(B);//deduct health points
			B.fight(A);
		
			i++;//increment rounds
			if (B.currentHP() == 0 && A.isAlive()) {
				winner = &first;
			}
			else if (A.currentHP() == 0 && B.isAlive()) {
				winner = &second;
			}
			else if (A.currentHP() == 0 && B.currentHP() == 0) {
				winner = &first;
			}
		}

		

		std::cout << "Winner is " << *winner << " in " << i << " rounds." << std::endl;

		return *winner;
	}


	//Overload for Hero vs SuperHero
	const Hero & operator*(const Hero & first, const SuperHero & second)
	{
		const Hero *winner = nullptr;
		Hero A = first;
		Hero B = second;
		int i = 0; //rounds
		std::cout << "Ancient Battle! " << first << " vs " << second << " : ";

		
		do {
			A.fight(B);//deduct health points
			i++;//increment rounds
			if (B.currentHP() == 0 && A.isAlive()) {
				winner = &first;
			}
			else if (A.currentHP() == 0 && B.isAlive()) {
				winner = &second;
			}
			else {
				winner = &first;
			}
		} while (A.isAlive() && B.isAlive() && i < max_rounds);

		

		std::cout << "Winner is " << *winner << " in " << i << " rounds." << std::endl;

		return *winner;
	}
	std::ostream & operator<<(ostream & os, const SuperHero & hero)
	{
		if (hero.name == '\0') {
			os << "No hero";
		}
		else {
			os << hero.name;
		}
		return os;
	}
}