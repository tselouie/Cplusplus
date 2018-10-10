#ifndef SICT_HERO_H_
#define SICT_HERO_H_
#include <iostream>

using namespace std;

const int max_rounds = 100;
namespace sict {


	class Hero {

	protected:
		char name[40 + 1];
		unsigned int health;
		unsigned int strength;

	public:
		Hero();
		Hero(const char*, unsigned int, unsigned int);
		void operator -=(int);
		bool isAlive() const;
		int attackStrength() const;
		int currentHP();
		void fight(Hero&);
		friend ostream& operator<<(ostream& os, const Hero& hero);
	};
	const Hero& operator*(const Hero& first, const Hero& second);
	 ostream& operator<<(ostream& os, const Hero& hero);
	
}

#endif
