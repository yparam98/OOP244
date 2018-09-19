/***********************************************************
program: workshop3
author: yathavan, parameshwaran
date: 6/8/2018
purpose: to complete workshop 3
***********************************************************/


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <cstring>
#include "CRA_Account.h"
using namespace std;

namespace sict
{
	void CRA_Account::set(const char* familyName, const char* givenName, int sin)
	{
		if (sin>min_sin && sin < max_sin)
		{
			strncpy(family_name, familyName, max_name_length); //strncpy combats buffer overflow by requiring you to put a length in it. strcpy depends on a trailing \0, which may not always occur.
			strncpy(given_name, givenName, max_name_length);
			social_insurance_number = sin;
		}
		else
		{
			social_insurance_number = 0;
		}
	}

	bool CRA_Account::isEmpty() const
	{
		if (social_insurance_number == 0)
		{
			return true;
		}
		else
		{
			return false; 
		}
	}

	void CRA_Account::display() const
	{
		bool verify = isEmpty();
		if (verify == false)
		{
			cout << "Family Name: " << family_name << endl;
			cout << "Given Name : " << given_name << endl;
			cout << "CRA Account: " << social_insurance_number << endl;
		}
		else
		{
			cout << "Account object is Empty!" << endl;
		}

	}

}
