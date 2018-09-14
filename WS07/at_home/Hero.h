//Callum Dodge 
//100229178
//Workshop 7
//July 10,2018

#ifndef HERO_H
#define HERO_H

#include <iostream>

namespace sict {

	#define max_rounds 100

	class Hero {
	//Data Members
	protected:
		char name[40 + 1];
		int health;
		int attack;

	public:
		//Constructors
		Hero();
		Hero(const char *, int, int);

		//Member Functions
		bool isAlive() const;
		int attackStrength() const;
		void SES();

		//Operator Functions
		void operator-=(int hit);
		friend std::ostream& operator<<(std::ostream& os, const Hero& hero);
	};
	//Helper Function
	const Hero& operator*(const Hero& first, const Hero& second);
}

#endif // !HERO_H
