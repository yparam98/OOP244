// TODO: insert header files
#include <iostream>
#include "Fraction.h"
#include <cstring>
using namespace std;

namespace sict
{
	Fraction::Fraction()
	{
		numerator = 0;
		denominator = 0;
	}

	Fraction::Fraction(int numnum, int denden)
	{
		if ((numnum > 0) && (denden > 0))
		{
			numerator = numnum;
			denominator = denden;
		}
		else
		{
			numerator = 0;
			denominator = 0;
		}
	}
	int Fraction::max() const
	{
		if (numerator > denominator)
		{
			return numerator;
		}
		else
		{
			return denominator;
		}
	}
	int Fraction::min() const
	{
		if (numerator < denominator)
		{
			return numerator;
		}
		else
		{
			return denominator;
		}
	}
	void Fraction::reduce()
	{
		
		int  gcd;
		for (int index = 1; index <= numerator&&index <= denominator; index++)
		{
			if (numerator%index == 0 && denominator%index == 0) { gcd = index; }
		}
		
		numerator = numerator / gcd;
		printf("NUM >> %d", numerator);
		denominator = denominator / gcd;
		printf("DEN >> %d", denominator);
	}

// gcd returns the greatest common divisor of num and denom
		
	int Fraction::gcd() const {

		int mn = min();  // min of numerator and denominator
		int mx = max();  // max of numerator and denominator
		int g_c_d = 1;
		bool found = false;

		for (int x = mn; !found && x > 0; --x) { // from mn decrement until divisor found
			if (mx % x == 0 && mn % x == 0) {
				found = true;
				g_c_d = x;
			}
		}
		return g_c_d;
	}

	bool Fraction::isEmpty() const
	{
		if ((numerator == 0) && (denominator == 0))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void Fraction::display() const
	{
		if (numerator > 0 && denominator > 0)
		{
			cout << numerator << "/" << denominator;
		}
		else if (denominator == 1)
		{
			cout << numerator;
		}
		if (isEmpty())
		{
			cout << "no fraction stored";
		}
	}

	Fraction Fraction::operator+(const Fraction & rhs) const
	{
		int newnum, newnumm, newnummm, newdum;
		int addedNum, addedDen;
		if (this->numerator == 0 || this->denominator == 0 || rhs.numerator==0 || rhs.denominator==0)
		{
			return rhs;
		}
		else
		{
			newdum = this->denominator*rhs.denominator;
			newnumm = this->numerator*rhs.denominator;
			newnummm = rhs.numerator*this->denominator;
			newnum = newnumm + newnummm;
			addedNum = newnum;
			addedDen = newdum;
			addedNum = addedNum / gcd();
			
			addedDen = addedDen / gcd();
			return Fraction(addedNum,addedDen);

		}
	}

}