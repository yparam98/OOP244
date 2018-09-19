/*
 * program: Contact.h
 * programmer: Yathavan, Parameshwaran
 * purpose: header file for Contact.cpp
 * date: 08/18/2018
 */
#ifndef SICT_CONTACT_H
#define SICT_CONTACT_H

namespace sict
{
	const int theLengthOfTheAreaCode = 3;
	const int theLengthOfNumber = 7;
	const int numberCode1Length = 3;
	const int numberCode2Length = 4;

	class Contact
	{
	private:
		char mango[20];
		long long* listOfValidPhoneNumbers;
		int myPhoneNumber;
		bool ifThisPhoneNumberIsValidThenDoThis(const long long);
	public:
		Contact();
		Contact(const char*, const long long*, const int);
		~Contact();
		void display() const;
		bool isEmpty() const;
		Contact(const Contact& other) = delete;
		Contact& operator=(const Contact& other) = delete;
	};
}
#endif
