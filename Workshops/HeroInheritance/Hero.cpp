#include "Hero.h"
#include <iostream>
#include <cstring>
#include <string>

using namespace std;
using namespace sict;

namespace sict {

	Hero::Hero()
	{
		name[0] = '\0';

	}

	Hero::Hero(const char* n, unsigned int hp, unsigned int atk)
	{
		
		int len = strlen(n);
		std::strncpy(name, n, len+1);
		name[len+1] = '\0';
		health = hp;
		strength = atk;
	}

	void Hero::operator-=(int attack)
	{
		if (attack > 0) {
			health = health - attack;
		}
			if (health > 100 || health < 0) {
				health = 0;
			}
	}

	bool Hero::isAlive() const
	{
		return health > 0 && health <= 100;
	}

	int Hero::attackStrength() const
	{
		return strength;
	}
	int Hero::currentHP()
	{
		return health;
	}

	void Hero::fight(Hero& ahero)
	{
		health -= ahero.attackStrength();
		ahero.health -= strength;
	}
	
	std::ostream & operator<<(ostream & os, const Hero & hero)
	{
		if (hero.name[0] == '\0') {
			os << "No hero";
		}
		else {

			os << hero.name;
		}
		return os;


	}
	const Hero & operator*(const Hero & first, const Hero & second)
	{
		const Hero *winner = nullptr;
		Hero A = first;
		Hero B = second;
		int i=0; //rounds
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


}
