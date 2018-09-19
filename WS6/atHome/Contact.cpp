/*
 * program: Contact.cpp
 * programmer: Yathavan, Parameshwaran
 * purpose: implementation file for Contact.h
 * date: 08/18/2018
 */

#include <iostream>
#include <cstring>
#include <sstream>
#include "Contact.h"
using namespace std;
namespace sict
{
	bool Contact::phoneNumberIsValid(const long long phoneNumber)
	{
		string stringOfPhoneNumber_s = to_string(phoneNumber);
		bool invalid;
		if(phoneNumber <= 0 || stringOfPhoneNumber_s.length() < 11 || stringOfPhoneNumber_s.length() > 12 || stringOfPhoneNumber_s[stringOfPhoneNumber_s.length() - 7] == '0' || stringOfPhoneNumber_s[stringOfPhoneNumber_s.length() - 10] == '0')
		{
			invalid = true;
		}
		else
		{
			invalid = false;
		}
		if (invalid == true)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	bool Contact::isEmpty() const
	{
		return mango[0] == '\0';
	}
	Contact::Contact()
	{
		mango[0] = '\0';
		numberOfPhoneNumbersInList = 0;
		mangoNumber = nullptr;
	}
Contact::Contact(const char* name, const long long* phoneNumbers, const int noOfPhoneNumbers)
	{		
        bool v_Name = name != nullptr && strlen(name) != 0;
		if (v_Name)
		{
			strcpy(mango, name);
			mangoNumber = new long long[noOfPhoneNumbers];
			numberOfPhoneNumbersInList = 0;			
			for	(int i = 0; i < noOfPhoneNumbers; i++)
			{				
				if (phoneNumberIsValid(phoneNumbers[i]))
				{					
					numberOfPhoneNumbersInList += 1;				
					mangoNumber[numberOfPhoneNumbersInList - 1] = phoneNumbers[i];
				}
                else
                {
                    mangoNumber[i] = 0;
                }
			}
		}
		else
		{
			*this = Contact();
		}
	}
	void Contact::display() const{
		string countryCode, areaCode, numberCode1, numberCode2, stringOfPhoneNumber_s;
		int lengthOfPhoneNumberListString;
		if (!isEmpty()) {
			cout << mango << endl;
			for (int phone = 0; phone < numberOfPhoneNumbersInList; phone++) {
				stringOfPhoneNumber_s = to_string(mangoNumber[phone]);
				lengthOfPhoneNumberListString = stringOfPhoneNumber_s.length();
				countryCode = stringOfPhoneNumber_s.substr(0, (lengthOfPhoneNumberListString - (lengthOfAreaCode + lengthOfNumber)));
				areaCode = stringOfPhoneNumber_s.substr(lengthOfPhoneNumberListString - (lengthOfAreaCode + lengthOfNumber), lengthOfAreaCode);
				numberCode1 = stringOfPhoneNumber_s.substr(lengthOfPhoneNumberListString - lengthOfNumber, numberCode1Length);
				numberCode2 = stringOfPhoneNumber_s.substr(lengthOfPhoneNumberListString - numberCode2Length, numberCode2Length);
				cout << "(+" << countryCode << ")" << " " << areaCode << " " << numberCode1 << "-" << numberCode2 << endl;
			}
		}
		else 
		{
			cout << "Empty contact!" << endl;
		}
    }
	Contact::~Contact()
	{		
		if (mangoNumber != nullptr)
		{
			delete[] mangoNumber;
			mangoNumber = nullptr;
		}
	}
    Contact::Contact(const Contact& other) //copy constructor... yay!!
    {
        mangoNumber = nullptr;
        *this = other;
    }
    Contact& Contact::operator=(const Contact& romeo)
    {
		//REMEMBER TO FOLLOW RULES FOR CREATING COPY ASSIGNMENT OPERATOR!!
        if (this != &romeo) 
        {
            strcpy(mango, romeo.mango);
            numberOfPhoneNumbersInList = romeo.numberOfPhoneNumbersInList;
            delete[] mangoNumber;
            if (romeo.mangoNumber != nullptr) {
                mangoNumber = new long long[numberOfPhoneNumbersInList];
                for (int i = 0; i < numberOfPhoneNumbersInList; i++) {
                mangoNumber[i] = romeo.mangoNumber[i];
                }
            }
            else 
            {
                mangoNumber = nullptr;
            }
        }
        return *this;
    }
    Contact& Contact::operator+=(long long phoneNumber)
    {
		bool valid = phoneNumberIsValid(phoneNumber);
        if (valid)
        {
            numberOfPhoneNumbersInList++;            
            long long* phoneNumber_s = new long long[numberOfPhoneNumbersInList];
            for (int i = 0; i < numberOfPhoneNumbersInList - 1; ++i)
            {
                phoneNumber_s[i] = mangoNumber[i];
            }
            phoneNumber_s[numberOfPhoneNumbersInList - 1] = phoneNumber;
            delete[] mangoNumber;
            mangoNumber = phoneNumber_s;
        }
        return *this;
    }
}
