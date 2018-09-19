#include <iostream>
#include <cstring>
#include "Hero.h"
#include <fstream>

using namespace std;

namespace sict
{
	Hero::Hero()
	{
		heroName[0]='\0';
		healthOfHero=0;
		heroAttackStrength=0;
	}
	Hero::Hero(const char* name, int health, int attack)
	{
		if((health<0)||(attack<0)||(name==nullptr))
		{
			healthOfHero=0;
			heroName[0]='\0';
			heroAttackStrength=0;
		}
		else
		{
			healthOfHero=health;
			heroAttackStrength=attack;
			strcpy(heroName,name);
		}
	}
	void Hero::operator-=(int attack) 
	{
		/*
		 * takes  : one integer containing value of attack
		 * does   : subtracts the incoming attack strength from the health of the hero (current object) 
		 * returns: noethings
		 */                                                       
		if (attack>0)
		{
			if (attack>this->healthOfHero)
			{
				healthOfHero=0;
			}
			else
			{
				this->healthOfHero=this->healthOfHero-attack;
			}
		}
		else
		{
			this->healthOfHero=this->healthOfHero+0;	
		}
		

		//healthOfHero-=attack;
	}
	bool Hero::isAlive() const 
	/* 
	 * take: nothing
	 * action: checks if the health of the current hero is above 0 or not, if the health is 0 or less, then the hero is considered dead 
	 * return: a boolean value that determines alive-state of hero 
	 */
	{
		if (this->healthOfHero>0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	int Hero::attackStrength() const //returns attack 
	{/*
          * takes  : nothing
          * does   : returns the current hero attack strength
          * returns: current hero attack strength
	  */    
		if (this->heroAttackStrength<=0)
		{
			return 0;
		}
		else
		{
			return this->heroAttackStrength;
		}
	}
	ostream& operator<<(ostream& os, const Hero& hero)
	{
		/*
                 * takes  : left hand side operand is os object, and right hand side operand is a reference to a Hero object... 
                 * does   : prints heroName to the left hand side operand
                 * returns: a reference to an ostream object
		 */                                                       
		if (hero.heroName[0]=='\0')
		{
			os<<"No hero";
		}
		else
		{
			os<<hero.heroName;
		}
		return os;
	}
	const Hero& operator*(const Hero& first, const Hero& second)
	{
		long firstHeroAttackStrength = first.attackStrength();
		long secondHeroAttackStrength = second.attackStrength();
	
		cout << "Ancient Battle!" ;
		cout << first;	
		cout << "vs";	
		cout << second;
		cout <<" : ";
		for (int index=1;index<(100+1);index++)
		{
			first-=secondHeroAttackStrength; //the problem is here... 
			second-=firstHeroAttackStrength; //and because same syntax, problem radiates to here as well...
			if (!second.isAlive())
			{
				cout << "Winner is ";
				cout << first;
				cout << " in Round " << index << endl;
				
				return first;
			}
			if(!first.isAlive())
			{
				cout << "Winner is ";
				cout << second;
				cout << "in Round " << index << endl;

				return second;
			}
			if (index==100)
			{
				cout << "Winner is ";
			       	cout << first;
			       	cout << "in Round " << index << endl;
				return first;
			}
		}
		return first;
	}
}



