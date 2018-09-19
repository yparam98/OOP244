/*
 * program: Contact.cpp
 * programmer: Yathavan, Parameshwaran
 * purpose: implementation file for Contact.h
 * date: 08/18/2018
 */
#include <iostream>
#include <sstream>
#include <cstring>
#include "Contact.h"
using namespace std;
namespace sict
{
	bool Contact::ifThisPhoneNumberIsValidThenDoThis(const long long phoneNumber)
	{
		string registeredPhoneNumber = to_string(phoneNumber);
		bool invalid = phoneNumber <= 0 || registeredPhoneNumber.length() < 11 || registeredPhoneNumber.length() > 12 || registeredPhoneNumber[registeredPhoneNumber.length() - 7] == '0' || registeredPhoneNumber[registeredPhoneNumber.length() - 10] == '0';
		if (invalid)
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
		char atom = mango[0];

		if ((atom == '\0') && (listOfValidPhoneNumbers == nullptr) && (myPhoneNumber == 0))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	Contact::Contact() //constructor, gets called when an object of type Contact is created 
	{
		mango[0] = '\0';
		myPhoneNumber = 0;
		listOfValidPhoneNumbers = nullptr;
	}
	Contact::Contact(const char *name, const long long *phoneNumbers, const int noOfPhoneNumbers)  //3 arg. constructor
	{
		if (name != nullptr && name[0] != '\0')
		{
			int theSizeOfMango = (sizeof(mango) - 1);
			int lengthOfTheNameParameter = strlen(name);
			int mango_length = (lengthOfTheNameParameter > theSizeOfMango) ? theSizeOfMango : lengthOfTheNameParameter; //note to self: watch the batman s2 e4 later tonight
			for (int index = 0; index < mango_length; index++)
			{
				mango[index] = name[index];
			}
			mango[mango_length] = '\0';
		}
		else
		{
			mango[0] = '\0';
		}
		if (phoneNumbers != nullptr && noOfPhoneNumbers > 0)
		{	
			if (phoneNumbers != nullptr)
			{
				listOfValidPhoneNumbers = new long long[noOfPhoneNumbers];
				myPhoneNumber = 0;
				for (int apple = 0; apple < noOfPhoneNumbers; apple++)
				{
					if (ifThisPhoneNumberIsValidThenDoThis(phoneNumbers[apple]))
					{
						myPhoneNumber += 1;
						listOfValidPhoneNumbers[myPhoneNumber - 1] = phoneNumbers[apple];
					}
				}
			}
		}
		else
		{
			listOfValidPhoneNumbers = nullptr;
			myPhoneNumber = 0;
		}
	}
	void Contact::display() const
	{
		string countryCode, areaCode, numberCode1, numberCode2, registeredPhoneNumber;
		int registeredPhoneNumberLength;
		if (!isEmpty())
		{
			std::cout << mango << endl;
			for (int phone = 0; phone < myPhoneNumber; phone++)
			{
				registeredPhoneNumber = to_string(listOfValidPhoneNumbers[phone]);
				registeredPhoneNumberLength = registeredPhoneNumber.length();
				countryCode = registeredPhoneNumber.substr(0, (registeredPhoneNumberLength - (theLengthOfTheAreaCode + theLengthOfNumber)));
				areaCode = registeredPhoneNumber.substr(registeredPhoneNumberLength - (theLengthOfTheAreaCode + theLengthOfNumber), theLengthOfTheAreaCode);
				numberCode1 = registeredPhoneNumber.substr(registeredPhoneNumberLength - theLengthOfNumber, numberCode1Length);
				numberCode2 = registeredPhoneNumber.substr(registeredPhoneNumberLength - numberCode2Length, numberCode2Length);
				std::cout << "(+" << countryCode << ")" << " " << areaCode << " " << numberCode1 << "-" << numberCode2 << endl;
			}
		}
		else
		{
			cout << "Empty contact!" << endl;
		}
	}
	Contact::~Contact()
	{		
		if (listOfValidPhoneNumbers != nullptr)
		{
			delete[] listOfValidPhoneNumbers;
			listOfValidPhoneNumbers = nullptr;
		}
	}
}