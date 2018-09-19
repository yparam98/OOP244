//program: Data.h
//programmer: yathavan
//purpose: header file for Data.cpp

#include <cstring>
#include <iostream>
using namespace std;
namespace sict 
{
	const int large = 1000000000; 
	const int small = 0;
	const int col_wid = 15;
	int select(const int*, int);	
	template<typename T>
	T max(const T * samsung, int n)
	{
		T max = samsung[0];
		for (int i = 1; i < n; ++i)
		{
			if (max < samsung[i])
			{
				max = samsung[i];
			}
				
		}
		return max;
	}
	template<typename T>
	T min(const T * samsung, int bee)
	{
		T min = samsung[0];

		for (int index = 1; index < bee; ++index)
		{
			if (min > samsung[index])
			{
				min = samsung[index];
			}				
		}
		return min;
	}
	template<typename T>
	T sum(const T * samsung, int apple)
	{
		T sum = 0;
		for (int index = 0; index < apple; ++index)
		{
			sum += samsung[index];
		}
		return sum;
	}
	template<typename T>
	double average(const T * samsung, int numb) {return sum(samsung, numb) / numb;}
	template<typename P>
	bool read(istream & input, P * samsung, int incomingNum)
	{
		for (int index = 0; index < incomingNum; ++index)
		{
			input.ignore();
			input >> samsung[index];
			if (input.fail())
			{
				return false;
			}
		}
		return true;
	}
template<typename Y>
	void display(const char * name, const Y * samsung, int n)
	{
		cout.width(20);
		cout << right << name;
		for (int i = 0; i < n; ++i)
		{
			cout.width(15);
			cout << samsung[i];
		}
		cout << endl;
	}

	template<typename G>
	G readRow(istream& fileInput, const char* name, G* samsung, int n)
	{
		char rowname[2000];
		bool ok = !fileInput.bad();
		if (ok) 
		{
			fileInput.get(rowname, 2000, ',');
			if (strcmp(rowname, name) != 0) 
			{
				cout << "Cannot parse row for " << name << endl;
				fileInput.ignore(2000, '\n');
				ok = false;
			}
		}
		if (ok)
		{
			ok = read(fileInput, samsung, n);
		}
			fileInput.ignore(2000, '\n');
			return ok;
		

	}
	void answers(const int*, const int*, const int*, const double*, const int*, const int n);
}

