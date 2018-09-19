/*
 * program: Hero.h
 * programmer: Yathavan, Parameshwaran
 * date: August 10, 2018
 * purpose: header file for Hero.cpp
 */

#ifndef SICT_HERO_H
#define SICT_HERO_H

#include <iostream>

namespace sict
{
	class Hero
	{
		private:
			int max_rounds=100;
			char heroName[40];
			int healthOfHero;
			int heroAttackStrength;
			//Hero(const char*,int,int);
		public:
			Hero();
			Hero(const char*,int,int);
			void operator-=(int);
			bool isAlive() const;
			int attackStrength() const;
			friend std::ostream& operator<<(std::ostream& os, const Hero& hero);
			
	};
	const Hero& operator*(const Hero& first, const Hero& second);
	
}

#endif
