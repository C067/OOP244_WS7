//Callum Dodge 
//100229178
//Workshop 7
//July 10,2018

#ifndef SUPERHERO_H
#define SUPERHERO_H

#include "Hero.h"

namespace sict {

	class SuperHero : public Hero {
		//Data Members 
		int bonus;
		int defense;
		
	public:
		//Constructors 
		SuperHero();
		SuperHero(char *, int, int, int, int);

		//Member Functions
		int attackStrength() const;
		int defend() const;
		void SES();
	};

	const SuperHero& operator*(const SuperHero& first, const SuperHero& second);

}


#endif // !SUPERHERO_H
