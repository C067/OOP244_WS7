//Callum Dodge 
//100229178
//Workshop 7
//July 10,2018


#include "SuperHero.h"
#include <iostream>
#include <cstring>

using namespace std;

namespace sict {

	//Zero Argument Constructor 
	SuperHero::SuperHero() {
		bonus = 0;
		defense = 0;
	}

	//3-Argument Constructor 
	//Assigns the values to the data members only if the information is valid
	SuperHero::SuperHero(char * n_name, int n_health, int n_attack, int n_bonus, int n_defend) {
		
		if (n_health > 0) {
			strncpy(name, n_name, 40);
			name[40] = '\0';

			health = n_health;
			attack = n_attack;
			bonus = n_bonus;
			defense = n_defend;
		}
		else {
			SuperHero::SES();
		}

	}

	//Returns the Attack Strength of a single SuperHero (Attack + Bonus Attack)
	int SuperHero::attackStrength() const{
		
		int strength = 0;

		if (isAlive()) {
			strength = (attack + bonus);
		}
		else {
			strength = 0;
		}

		return strength;
	}

	//Returns the defending strength of a single SuperHero
	int SuperHero::defend() const {
		int defend;

		if (isAlive()) {
			defend = defense;
		}
		else {
			defend = 0;
		}

		return defend;
	}

	//Sets the object to a Safe Empty State if the information entered is not valid.
	void SuperHero::SES() {
		for (int cnt = 0; cnt < 40; cnt++) {
			name[cnt] = '\0';
		}
		health = 0;
		attack = 0;
		bonus = 0;
		defense = 0;
	}

	//Overloads the * operator.
	//This operator overload displays the current SuperHeros that are fighting against each other.
	//After the SuperHero is defeated, the number of rounds it took to defeat the SuperHero is displayed while returning the winner.
	const SuperHero& operator*(const SuperHero& first, const SuperHero& second) {
		int rounds = 0;
		bool winner = false;
		SuperHero A = first;
		SuperHero B = second;

		const SuperHero *Winner;

		cout << "Super Fight! " << first << " vs " << second << " : Winner is ";

		rounds = 0;
		while (rounds > max_rounds || winner != true) {
			rounds++;
			A -= (B.attackStrength() - A.defend());
			B -= (A.attackStrength() - B.defend());

			if (!A.isAlive() && !B.isAlive()) {
				winner = true;
				Winner = &first;
			}
			else if (!A.isAlive()) {
				winner = true;
				Winner = &second;
			}
			else if (!B.isAlive()) {
				winner = true;
				Winner = &first;
			}
		}

		cout << *Winner << " in " << rounds << " rounds." << endl;
		
		return *Winner;
	}

}