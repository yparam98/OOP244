/***********************************************************
program: workshop2
author: yathavan, parameshwaran
date: 5/25/2018
purpose: to complete workshop 2
***********************************************************/


#include <iostream>
#include "Kingdom.h"
using namespace std;

namespace sict
{
	//This function prints Kingdom name & population to screen
	void display(const Kingdom& ref)
	{
		cout << ref.m_name << ", population " << ref.m_population << endl;
	}
	void display(const Kingdom ary[], int num)
	{
		int totalPop = 0;
		cout << "------------------------------" << endl;
		cout << "Kingdoms of SICT" << endl;
		cout << "------------------------------" << endl;
		for (int index = 0; index < num; index++)
		{
			//cout << index + 1 << ". " << ary[index].m_name << ", population " << ary[index].m_population << endl;
			//display(ary[index]);
			cout <<index+1<<". "<< ary[index].m_name << ", population " << ary[index].m_population << endl;
			totalPop=(totalPop+ary[index].m_population);


		}
		cout << "------------------------------" << endl;
		cout << "Total population of SICT: "<<totalPop<<endl; 	
		cout << "------------------------------" << endl;
		cout << "\n";


	}
}
