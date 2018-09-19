/*
* program: ErrorState.cpp
* programmer: Yathavan, Parameshwaran
* date: 2018/08/01
* purpose: implementation file for ErrorState.h
* tag(s): milestone2, ms2, final_project, oop244
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include "ErrorState.h" 
#include <cstring>

using namespace std; 

namespace AMA
{
	ErrorState::ErrorState(const char *errorMessage)
	{
		
		if (errorMessage == nullptr) 
		{
			myMessage = nullptr; 
		}
		else 
		{
			myMessage = new char[strlen(errorMessage)];
			
			strncpy(myMessage, errorMessage, strlen(errorMessage)+1); 
			
		}
	}
	ErrorState::~ErrorState() 
	{
		
		delete[]this->myMessage;
		this->clear();
	}
	void ErrorState::clear()
	{
	
		this->myMessage = nullptr; 
	}
	bool ErrorState::isClear() const
	{
		
		if (this->myMessage == nullptr) 
		{
			return true;
		}
		else 
		{
			return false;
		}
	}
	void ErrorState::message(const char* str)
	{
		
		delete[]this->myMessage; 
		this->myMessage = new char[strlen(str) + 1]; 
		
		strcpy(this->myMessage, str);
	}
	const char* ErrorState::message()const
	{
		
		return this->myMessage;
	}


	std::ostream & operator<<(std::ostream & os, ErrorState& text)
	{
		
		if (text.message() != nullptr)
		{
			os << text.message();
			return os;
		}
		else
		{
			return os;
		}
	}
}







//#ifndef AMA_ERRORSTATE_H
//#define AMA_ERRORSTATE_H
//
//namespace AMA
//{
//        class ErrorState
//        {
//                private:
//                        char* message;
//                public:
//                        explicit ErrorState(const char* errorMessage = nullptr);
//                        ErrorState(const ErrorState& em) = delete;
//                        ErrorState& operator=(const ErrorState& em) = delete;
//                        virtual ~ErrorState();
//                        void clear();
//                        bool isClear() const;
//                        void message(const char* str);
//                        const char* message()const;
//        };
//        std::ostream& operator<<(std::ostream& os, const char* text);
//
//#endif
//

	//and more stuff 
	//and even more
	//and more
	//and more
	//and more
	//and more















