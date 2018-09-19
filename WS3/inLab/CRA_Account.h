/***********************************************************
program: workshop3
author: yathavan, parameshwaran
date: 6/8/2018
purpose: to complete workshop 3
***********************************************************/

#ifndef CRA_ACCOUNT_H
#define CRA_ACCOUNT_H

#include <iostream>
using namespace std;
namespace sict
{
	const int max_name_length = 40;
	const int min_sin = 100000000;
	const int max_sin = 999999999;

	class CRA_Account
	{
	private:
		char family_name[max_name_length];
		char given_name[max_name_length];
		int social_insurance_number;

	public:
		void set(const char* familyName, const char* givenName, int sin);
		bool isEmpty() const;
		void display() const;
	};
}

#endif