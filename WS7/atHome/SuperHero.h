//program: SuperHero.h
//programmer: Yathavan, Parameshwaran
//date: August 12, 2018
//purpose: a header file that contains a class that is deriving from Hero class in Hero(.h/.cpp)

#ifndef AMA_SUPERHERO_H
#define AMA_SUPERHERO_H

#include "Hero.h"

namespace sict
{
	class SuperHero : public Hero
	{
		private:
			int bonus;
			int defense;

		public:
			SuperHero();
			SuperHero(const char*, int, int, int, int);
			int attackStrengthOne() const;
			int defend() const;
	};
	const SuperHero& operator*(const SuperHero& first, const SuperHero& second);

}




#endif