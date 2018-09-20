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
	void display(Kingdom& ref)
	{
		cout << ref.m_name << ", population " << ref.m_population << endl;		
	}
}
