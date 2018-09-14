
//Callum Dodge 
//100229178
//Workshop 7
//July 10,2018

#include "Hero.h"
#include <iostream>
#include <cstring>

using namespace std;

namespace sict {

	//Zero Argument Constructor
	//Set all members to Safe Empty State
	Hero::Hero() {
		for (int cnt = 0; cnt < 40; cnt++) {
			name[cnt] = '\0';
		}
		health = 0;
		attack = 0;
	}
	
	Hero::Hero(const char * n_name, int n_health, int n_attack) {

		//compare to see if no member is in a Safe Empty State
		if (n_health > 0 && n_name != nullptr && n_attack > 0) {

			//Copy variables into the data members
			strncpy(name, n_name, 40);
			name[40] = '\0';

			health = n_health;
			attack = n_attack;

		}
		else {
			SES();
		}
	}

	void Hero::operator-= (int hit) {
		
		//If the Hero is alive, deduct its current health with the opponents attack strength
		if (isAlive()) {
			
			if (attack > 0) {
				health -= hit;

				if (health < 0) {
					health = 0;
				}

			}

		}
		else {
			health = 0;
		}

	}

	//Compares to see if the Hero is Alive and able to continue the fight.
	bool Hero::isAlive() const {

		bool result = true;

		if (health > 0) {
			result = true;
		}
		else {
			result = false;
		}

		return result;
	}

	//Returns the attackStrength of the current Hero if the Hero is Alive.
	int Hero::attackStrength() const {

		int strength = 0;

		if (isAlive()) {
			strength = attack;
		}

		return strength;

	}

	//Puts the object into a Safe Empty State
	void Hero::SES() {
		for (int cnt = 0; cnt < 40; cnt++) {
			name[cnt] = '\0';
		}
		health = 0;
		attack = 0;
	}

	//Compares to see if the object is in a Safe Empty State. 
	//If not, return the name of the current hero. 
	std::ostream& operator<<(std::ostream& os,const Hero& hero) {
		
		if (hero.name != nullptr || hero.name != '\0') {
			os << hero.name;
		}
		else {
			os << "No hero";
		}

		return os;
	}

	//Compares to see which Hero is victorious in a certain amount of rounds. 
	const Hero& operator*(const Hero& first, const Hero& second) {

		int rounds = 0;
		bool winner = false;
		Hero A = first;
		Hero B = second;
		const Hero *Winner;

		cout << "Ancient Battle! " << A << " vs " << B << " : Winner is ";
		
		rounds = 0;
		while (rounds > max_rounds || winner != true) {
			rounds++;
			A -= B.attackStrength();
			B -= A.attackStrength();

			if (!A.isAlive() && !B.isAlive()) {
				Winner = &first;
				winner = true;
			}
			else if (!A.isAlive()) {
				Winner = &second;
				winner = true;
			}
			else if (!B.isAlive()) {
				Winner = &first;
				winner = true;
			}
		}
		
		cout << *Winner << " in " << rounds << " rounds." << endl;

		return *Winner;
	}


}