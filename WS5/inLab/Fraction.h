#ifndef SICT_FRACTION_H
#define SICT_FRACTION_H

namespace sict
{
	
	class Fraction 
	{
	private:	
		int numerator, denominator;

		int max() const; //a private query that returns the greater of the numerator and denominator
		int min() const; //a private query that returns the lesser of the numerator and denominator
		void reduce(); //a private modifier that reduces the numerator and denominator by dividing each by their greatest common divisor
		int gcd() const; //– a private query that returns the greatest common divisor of the numerator and denominator (this code is supplied)
		

	public:
		Fraction(); //sets object to a safe empty state
		Fraction(int, int); // receives the numerator and denominator of a fraction, validates the data received and stores that data only if it is valid.The data is valid if the numerator is not negative - valued and the denominator is positive - valued.If the data is invalid, this constructor sets the object to a safe empty state. 
		bool isEmpty() const; //returns true if the object is in a safe empty state; false otherwise
		void display() const; //sends the fraction to standard output in the following form if the object holds a valid fraction and its denominator is not unit -valued (1)
		Fraction operator+(const Fraction&rhs) const;
		/*
		a public member query
		that receives an unmodifiable reference to a Fraction object, which
		represents the right operand of an addition expression. The current
		object represents the left operand. If both operands are non-empty
		Fractions, your function returns a copy of the result of the addition
		operation in reduced form. If either operand is in a safe empty state,
		your function returns an empty Fraction object.
		*/
	};
}

#endif  
	

