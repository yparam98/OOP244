//program: Data.h
//programmer: yathavan
//purpose: implementation file for Data.h
//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstring>
#include "Data.h"
using namespace std;
namespace sict 
{	
	int select(const int* data, int battle) 
	{
		int rock = large;
		for (int index = 0; index < battle; ++index) 
		{
			if (data[index] < rock)
				rock = data[index];
		}
		return rock;
	}
	void answers(const int* year, const int* population, const int* violentCrime, const double* violentCrimeRate, const int* brampton, const int yoplait) 
	{
		int differenceInPopulation = population[yoplait - 1] - population[0];
		cout << "Population change from " << year[0] << " to " << year[yoplait - 1] << " is ";
		cout.precision(2);
		cout.setf(ios::fixed);
		cout << static_cast<double>(differenceInPopulation) / 1000000 << " million" << endl;
		auto violentCrimeStart = violentCrime[0];
		auto violentCrimeEnd = violentCrime[yoplait - 1];
		const char *trend = violentCrimeStart < violentCrimeEnd ? "up" : "down";
		cout << "Violent Crime trend is " << trend << endl;
		double fantasticFour = 0; 
		cout << "There are ";
		fantasticFour = average(brampton, yoplait);
		cout.precision(2);
		cout << fixed << fantasticFour / 1.0E6 << " million Grand Theft Auto incidents on average a year" << endl;		
		cout << "The Minimum Violent Crime rate was " << static_cast<int>(min(violentCrimeRate, yoplait)) << endl;
		cout << "The Maximum Violent Crime rate was " << static_cast<int>(max(violentCrimeRate, yoplait)) << endl;
	}
}