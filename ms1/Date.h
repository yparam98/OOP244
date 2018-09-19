/***************************************************/
/*   Program: Date.h                               */
/*   Developer: Yathavan, Parameshwaran            */
/*   Date: 2018-07-12                              */
/*   Purpose: Header file for Date.cpp             */
/*   Estimated Date of Completion: 2018/07/15      */
/*   Professor: Chris Szalwinsky, Md-Nour Hossain  */
/***************************************************/

#ifndef AMA_DATE_H
#define AMA_DATE_H

#define NO_ERROR 0
#define CIN_FAILED 1
#define YEAR_ERROR 2
#define MON_ERROR 3
#define DAY_ERROR 4

namespace AMA
{
	/* Pre-defined Constant Values */
	const int min_year = 2000;
	const int max_year = 2030;

	class Date
	{
	private:

	/* Date Values */
		int myYear;
		int myMonth;
		int myDay;
		int myComparator;
		int errorState;

	/* Member Functions */
		int mdays(int, int) const;
		void errCode(int);
	
	public:

		/* Constructors || Destructors */
		Date();
		Date(int, int, int);

		/* Operator Overloading */
		bool operator==(const Date& rhs) const;
		bool operator!=(const Date& rhs) const;
		bool operator<(const Date& rhs) const;
		bool operator>(const Date& rhs) const;
		bool operator<=(const Date& rhs) const;
		bool operator>=(const Date& rhs) const;

		/* Queries and Modifiers */
		int errCode() const;
		bool bad() const;

		/* Queries and Modifiers Pt.2 */
		std::istream& read(std::istream& istr);
		std::ostream& write(std::ostream& ostr) const;
	};

	/* Helper Functions */
	std::ostream& operator<<(std::ostream& ostr, const Date& rhs);
	std::istream& operator>>(std::istream& istr, Date& rhs);
}

#endif

