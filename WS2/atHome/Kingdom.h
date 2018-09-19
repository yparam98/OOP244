/***********************************************************
program: workshop2
author: yathavan, parameshwaran
date: 5/25/2018
purpose: to complete workshop 2
***********************************************************/

#ifndef SICT_KINGDOM_H
#define SICT_KINGDOM_H

namespace sict
{
#define size 32

	struct Kingdom
	{
	public:
		char m_name[size];
		int m_population;


	};

	void display(const Kingdom&);
	void display(const Kingdom ary[], int num);
}

#endif
