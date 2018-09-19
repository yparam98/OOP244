/**********************************************/
/*   program: iProduct.h                      */
/*   programmer: yathavan, parameshwaran      */
/*   purpose: interface for ms4               */
/*   date: 2018/08/02                         */
/*   professor: md.nour, hossain              */
/*   tag(s): ms4, iProduct, oop244            */
/**********************************************/
#define _CRT_SECURE_NO_WARNINGS
#ifndef AMA_IPRODUCT_H
#define AMA_IPRODUCT_H
#include <iostream>
#include <fstream>

namespace AMA
{
	class iProduct
	{
	public:
		virtual std::fstream& store(std::fstream& file, bool newLine = true) const = 0;
		virtual std::fstream& load(std::fstream& file) = 0;
		virtual std::ostream& write(std::ostream& os, bool linear) const = 0;
		virtual std::istream& read(std::istream& is) = 0;
		virtual bool operator==(const char*) const = 0;
		virtual double total_cost() const = 0;
		virtual const char* name() const = 0;
		virtual void quantity(int) = 0;
		virtual int qtyNeeded() const = 0;
		virtual int quantity() const = 0;
		virtual int operator+=(int) = 0;
		virtual bool operator>(const iProduct&) const = 0;
		virtual ~iProduct() = 0;
	};
	inline iProduct::~iProduct()
	{
		//
	}
	std::ostream& operator<<(std::ostream&, const iProduct&);
	std::istream& operator>>(std::istream&, iProduct&);
	double operator+=(double&, const iProduct&);
	iProduct* CreateProduct();
	iProduct* CreatePerishable();
}

#endif
