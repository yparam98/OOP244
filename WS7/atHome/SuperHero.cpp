//program: SuperHero.cpp
//programmer: yathavan, parameshwaran
//date: august 14, 2018
//tag(s): superhero, oop244, ws7
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "SuperHero.h"
#include "Hero.h"

using namespace std;

namespace sict
{
	SuperHero::SuperHero() : Hero()
	{
		bonus = 0;
		defense = 0;
	}
	SuperHero::SuperHero(const char *incomingName, int incomingHealth, int incomingAttack, int incomingBonus, int incomingDefence) : Hero(incomingName,incomingHealth,incomingAttack)
	{
		if (incomingName == nullptr || incomingHealth < 0 || incomingAttack < 0 || incomingBonus < 0 || incomingDefence < 0)
		{	
			bonus = 0;
			defense = 0;
		}
		else
		{
			bonus = incomingBonus;
			defense = incomingDefence;
		}
	}
	int SuperHero::attackStrengthOne() const //recieves: nothing || returns: the currentObjects attack strength plus bonus
	{
		if (this->attackStrength() == 0)
		{
			return 0;
		}
		else
		{
			return (this->attackStrength() + this->bonus);
		}
	}
	int SuperHero::defend() const //recieves: nothing || returns: the current object's defense strength;
	{
		if (this->defense == 0)
		{
			return 0;
		}
		else
		{
			return this->defense;
		}
	}

	const SuperHero &operator*(const SuperHero &firstOne, const SuperHero &secondTwo)
	{
		cout << "Super Fight! ";
		SuperHero newObj3;
		SuperHero newObj4;
		newObj3 = firstOne;
		newObj4 = secondTwo;


		cout << (Hero)newObj3;
		cout << " vs ";
		cout << (Hero)newObj4;
		cout << " : ";
		int oneAtt = newObj3.attackStrengthOne(); //superman's attack 
		int twoAtt = newObj4.attackStrengthOne(); //hulk's attack
		int oneDef = newObj3.defend(); // superman's defence
		int twoDef = newObj4.defend(); //hulk's defence
		for (int index = 1; index < 101; index++)
		{
			//newObj3 -= newObj4.attackStrengthOne() - newObj3.defend();
			//newObj4 -= newObj3.attackStrengthOne() - newObj4.defend();
			//What I need: an algorithm that will deplete health of one superhere, using the other's attackDamage+bonus.

			newObj3.operator-=(twoAtt - oneDef/*oneAtt - twoDef*/);
			newObj4.operator-=(oneAtt - twoDef/*twoAtt - oneDef*/);
			if (!newObj3.isAlive())
			{
				//cout << "iteration 1" << endl;
				cout << "Winner is ";
				cout << secondTwo;
				cout << " in " << index << " rounds." << endl;
				return secondTwo;
			}
			else if (!newObj4.isAlive())
			{
				cout << "Winner is ";
				cout << firstOne;
				cout << " in " << index << " rounds." << endl;
				return firstOne;
			}
			else if (index == 100)
			{
				cout << "Winner is ";
				cout << firstOne;
				cout << " in " << index << " rounds." << endl;
				return firstOne;
			}
			else
			{
				//cout << "iteration 4" << endl;
			}


		}
		return firstOne;
	}
} 
