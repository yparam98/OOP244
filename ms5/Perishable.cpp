#include <iostream>
#include "Perishable.h"
#include "Product.h"
#include "Date.h"
#include "ErrorState.h"

using namespace std;

namespace AMA
{
	Perishable::Perishable()
	{
		Product::type('P');
		//produState.isClear();

	}
	std::fstream & Perishable::store(std::fstream & file, bool newLine) const
	{
		Product::store(file, !newLine); //calling store method in Product class, to write out the values...
		file << "," << anObjOfDate << endl; //printing the record, and expiration date...
		return file;
	}
	std::fstream & Perishable::load(std::fstream & file) 
	{
		//file.flush();
		// TODO: insert return statement here		
		Product::load(file); //using the load method in Product class to extract the records from the fstream object
		anObjOfDate.read(file); //calling read method from Date class, while passing file as istream parameter

		file.ignore(); //extracting single character from file record
		return file; //returning an fstream object, file...
	}
	std::ostream & Perishable::write(std::ostream & os, bool linear) const
	{
		// TODO: insert return statement here
		Product::write(os, linear);
		if (isClear() && !isEmpty()) //if (no errors (isClear returns true is ErrorState object is empty) || not safe empty state (isEmpty returns true if object is in safe empty state. therefore, counter that by adding ! operator. it will essentially mean, !isEmpty = NOT in a safe empty state)
		{
			if (!linear) //if linear is true
			{
				os << " Expiry date: ";
			}
			anObjOfDate.write(os); //Date object::method that writes the expiry date...

			
		}
		return os;
	}
	std::istream & Perishable::read(std::istream & is)
	{
		//bool trigger;
		// TODO: insert return statement here
		is.clear();
		Product::read(is);
		if (produState.isClear())
		{
			cout << " Expiry date (YYYY/MM/DD): ";
			anObjOfDate.read(is);
		}
		if (anObjOfDate.errCode() == CIN_FAILED)
		{
			produState.clear();
			produState.message("Invalid Date Entry");
			//trigger = true;
		}
		if (anObjOfDate.errCode() == YEAR_ERROR)
		{
			produState.message("Invalid Year in Date Entry");
			//trigger = true;
		}
		if (anObjOfDate.errCode() == MON_ERROR)
		{
			produState.clear();
			produState.message("Invalid Month in Date Entry");
			//trigger = true;
		}
		if (anObjOfDate.errCode() == DAY_ERROR)
		{
			produState.clear();
			produState.message("Invalid Day in Date Entry");
			//trigger = true;
		}
		if (anObjOfDate.errCode())
		{
			is.setstate(std::ios::failbit);
		}
		if (anObjOfDate.errCode() != CIN_FAILED && anObjOfDate.errCode() != YEAR_ERROR && anObjOfDate.errCode() != MON_ERROR && anObjOfDate.errCode() != DAY_ERROR)
		{
			produState.clear();
		}
		return is;
	}
	const Date & Perishable::expiry() const
	{
		return anObjOfDate;
	}
}

