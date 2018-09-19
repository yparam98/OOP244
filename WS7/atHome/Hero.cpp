/*
 * program: Hero.cpp
 * programmer: Yathavan, Parameshwaran
 * date: August 10, 2018
 * purpose: implementation file for Hero.h
 */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Hero.h"
#include <fstream>

using namespace std;

namespace sict
{
	Hero::Hero()
	{
		heroName[0] = '\0';
		healthOfHero = 0;
		heroAttackStrength = 0;
	}
	Hero::Hero(const char *name, int health, int attack)
	{
		if ((health < 0) || (attack < 0) || (name == nullptr))
		{
			healthOfHero = 0;
			heroName[0] = '\0';
			heroAttackStrength = 0;
		}
		else
		{
			healthOfHero = health;
			heroAttackStrength = attack;
			strcpy(heroName, name);
		}
	}
	void Hero::operator-=(int attack)
	{
		if (attack > 0)
		{
			if (attack > this->healthOfHero)
			{
				healthOfHero = 0;
			}
			else
			{
				this->healthOfHero = this->healthOfHero - attack;
			}
		}
		else
		{
			this->healthOfHero = this->healthOfHero + 0;
		}

	}
	bool Hero::isAlive() const
	{
		if (this->healthOfHero > 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	int Hero::attackStrength() const
	{
		if (this->heroAttackStrength <= 0)
		{
			return 0;
		}
		else
		{
			return this->heroAttackStrength;
		}
	}
	ostream &operator<<(ostream &os, const Hero &hero)
	{
		if (hero.heroName[0] == '\0')
		{
			os << "No hero";
		}
		else
		{
			os << hero.heroName;
		}
		return os;
	}
	const Hero &operator*(const Hero &first, const Hero &second)
	{
		Hero newObj1;
		newObj1 = first;
		Hero newObj2;
		newObj2 = second;

		cout << "Ancient Battle! ";
		cout << first;
		cout << " vs ";
		cout << second;
		cout << " : ";
		for (int index = 1; index < (101); index++)
		{
			newObj1 -= newObj2.attackStrength();
			newObj2 -= newObj1.attackStrength();
			if (!newObj2.isAlive())
			{
				//cout << "iteration 1" << endl;
				cout << "Winner is ";
				cout << first;
				cout << " in " << index << " rounds." << endl;
				return first;
			}
			else if (!newObj1.isAlive())
			{
				cout << "Winner is ";
				cout << second;
				cout << " in " << index << " rounds." << endl;
				return second;
			}
			else if (index == 100)
			{
				cout << "Winner is ";
				cout << first;
				cout << " in " << index << " rounds." << endl;
				return first;
			}
			else
			{
				//cout << "iteration 4" << endl;
			}
		}
		return first;
	}
} // namespace sict
