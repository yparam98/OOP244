/*
* program: ErrorState.cpp
* programmer: Yathavan, Parameshwaran
* date: 2018/08/01
* purpose: header file for ErrorState.cpp
* tag(s): milestone2, ms2, final_project, oop244
*/

#ifndef AMA_ERRORSTATE_H
#define AMA_ERRORSTATE_H

namespace AMA
{
	class ErrorState
	{
	private:
		char* myMessage;
	public:
		explicit ErrorState(const char* errorMessage = nullptr);
		ErrorState(const ErrorState& em) = delete; //
		ErrorState& operator=(const ErrorState& em) = delete; //
		virtual ~ErrorState();
		void clear();
		bool isClear() const;
		void message(const char* str);
		const char* message()const;
	};
	std::ostream& operator<<(std::ostream& os, ErrorState& text);
}
#endif
