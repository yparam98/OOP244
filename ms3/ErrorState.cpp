//yathavan, parameshwaran

#define _CRT_SECURE_NO_WARNINGS
#include <iostream> //header file
#include "ErrorState.h" //calling your ErrorState.h file, and all the shit in it
#include <cstring>

using namespace std; //using the std namespace and it's included variable things...

namespace AMA
{
	ErrorState::ErrorState(const char *errorMessage)
	{
		// cout << "iteration 1" << endl;
		if (errorMessage == nullptr) //if the errorMessage does not contain an error message
		{
			myMessage = nullptr; //setting the myMessage of the current object to a safe empty state
		} //
		else //if the errorMessage DOES contain an error message
		{
			myMessage = new char[strlen(errorMessage)]; //allocating dynamic memory to the myMessage pointer, to the size of the error message plus the null byte
														//this->myMessage=errorMessage;
			strncpy(myMessage, errorMessage, strlen(errorMessage) + 1); //copying over the error message to the myMessage pointer

		}
	}
	ErrorState::~ErrorState() //probably a destructor
	{
		// cout << "iteration 2" << endl;
		delete[]this->myMessage; //this is to delete a pointer of dynamic memory
		this->clear(); //calling the clear() method
	}
	void ErrorState::clear()
	{
		// cout << "iteration 3" << endl;
		this->myMessage = nullptr; //setting myMessage to a safe empty state
	}
	bool ErrorState::isClear() const
	{
		// cout << "iteration 4" << endl;
		if (this->myMessage == nullptr) //if the myMessage pointer is empty, return true...
		{
			return true;
		}
		else //if the myMessage pointer is NOT empty, return false
		{
			return false;
		}
	}
	void ErrorState::message(const char* str)
	{
		// cout << "iteration 5" << endl;
		delete[]this->myMessage; //deallocating the myMessage pointer
		this->myMessage = new char[strlen(str) + 1]; //allocating memory to the myMessage pointer, giving it the size of str plus one, for null byte...
													 //this->myMessage=str;
		strcpy(this->myMessage, str);
	}
	const char* ErrorState::message()const
	{
		// cout << "iteration 6" << endl;
		return this->myMessage;
	}


	//std::ostream& ErrorState::operator<<(std::ostream& os, const char* text)
	//{

	//}
	std::ostream & operator<<(std::ostream & os, ErrorState& text)
	{
		// cout << "iteration 7" << endl;
		// TODO: insert return statement here
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
//std::ostream& operator<<(std::ostream& os, const char* text);






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















