/***************************************************/
/*   Program: Date.cpp                             */
/*   Developer: Yathavan, Parameshwaran            */
/*   Date: 2018-07-12                              */
/*   Purpose: Implementation file for Date.h       */
/*   Estimated Date of Completion: 2018/07/15      */
/*   Professor: Chris Szalwinsky, Md-Nour Hossain  */
/***************************************************/

#include <iostream>
#include "Date.h"
using namespace std;
namespace AMA
{

	int Date::mdays(int mon, int year)const
	{
		int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
		int month = mon >= 1 && mon <= 12 ? mon : 13;
		month--;
		return days[month] + int((month == 1)*((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
	}


	void Date::errCode(int errorCode)
	{
		errorState = errorCode;
	}

	Date::Date()
	{
		myYear = 0000;
		myMonth = 00;
		myDay = 00;

		myComparator = 0;
		errorState = NO_ERROR;
	}

	Date::Date(int yourYear, int yourMonth, int yourDay)
	{
		if (yourYear > 1)
		{
			myYear = yourYear;
			myMonth = yourMonth;
			myDay = yourDay;
			errorState = NO_ERROR;
			myComparator = yourYear * 372 + yourMonth * 13 + yourDay;

		}
		else
		{
			myYear = 0;
			myMonth = 0;
			myDay = 0;

			errorState = NO_ERROR;
			myComparator = 0;
		}
	}

	bool Date::operator==(const Date& rhs) const
	{
		if (myComparator == rhs.myComparator)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool Date::operator!=(const Date& rhs) const
	{
		if (myComparator != rhs.myComparator)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool Date::operator<(const Date& rhs) const
	{
		if (myComparator < rhs.myComparator)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool Date::operator>(const Date& rhs) const
	{
		if (myComparator > rhs.myComparator)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool Date::operator<=(const Date& rhs) const
	{
		if (myComparator <= rhs.myComparator)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool Date::operator>=(const Date& rhs) const
	{
		if (myComparator >= rhs.myComparator)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	int Date::errCode() const
	{
		return errorState;
	}

	bool Date::bad() const
	{
		if (errCode()!=NO_ERROR)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	std::istream & Date::read(std::istream & istr)
	{
		char slash1, slash2;
		istr >> myYear >> slash1 >> myMonth >> slash2 >> myDay;

		if (istr.fail())
		{
			errCode(CIN_FAILED);
			return istr;
		}
		else if (myYear<min_year || myYear>max_year)
		{
			errCode(YEAR_ERROR);
			return istr;
		}
		else if (myMonth<1 || myMonth>12)
		{
			errCode(MON_ERROR);
			return istr;
		}
		else if (myDay<1 || myDay>mdays(myMonth, myYear))
		{
			errCode(DAY_ERROR);
			return istr;
		}
		else
		{
			errCode(NO_ERROR);
			return istr;
		}
	}

	std::ostream & Date::write(std::ostream & ostr) const
	{

		/* error checking */
		if ((myYear<min_year)||(myYear>max_year)||(myMonth<0)||(myMonth>12)||(myDay<0)||(myDay>mdays(myMonth,myYear)))
		{
			ostr << "0/00/00";
		}
		else
		{
			ostr << myYear;
			ostr << "/";
			if (myMonth < 10)
			{
				ostr << "0";
			}
			ostr << myMonth;
			ostr << "/";
			if (myDay < 10)
			{
				ostr << "0";
			}
			ostr << myDay;
		}
		    
		return ostr;
	}

	std::ostream & operator<<(std::ostream & ostr, const Date & rhs)
	{
		return rhs.write(ostr);
	}

	std::istream & operator >> (std::istream & istr, Date & rhs)
	{
		return rhs.read(istr);
	}

}



