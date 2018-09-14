#ifndef HERO_H
#define HERO_H

#include <iostream>

namespace sict {

	#define max_rounds 100

	class Hero {

		char name[40 + 1];
		int health;
		int attack;

	public:
		Hero();
		Hero(char *, int, int);

		bool isAlive() const;
		int attackStrength() const;
		void SES();

		void operator-=(int hit);

		friend std::ostream& operator<<(std::ostream& os, const Hero& hero);
	};

	const Hero& operator*(const Hero& first, const Hero& second);
}

#endif // !HERO_H
