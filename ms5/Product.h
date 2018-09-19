#ifndef AMA_PRODUCT_H
#define  AMA_PRODUCT_H
#include <iostream>
#include <fstream>
#include <cstring>
#include "ErrorState.h"
#include "iProduct.h"

namespace AMA
{
	const int  max_sku_length = 7;
	const int  max_unit_length = 10;
	const int  max_name_length = 75;	
	const int  currentTAX = 13;

	/*char sku_[max_sku_length + 1];
	char name[max_name_length + 1];
	char unit[max_unit_length + 1];*/

	class Product : public iProduct
	{
	private:
		char productType;
		char productSKU[max_sku_length];
		char productUnit[max_unit_length];
		char* nameOfProduct;
		int quantityOnHand;
		int quantityNeeded;
		double unitPrice;
		bool productTax;
	protected:
		ErrorState produState;
		void name(const char*);
		const char* name() const;
		const char* sku() const;
		const char* unit() const;
		bool taxed() const;
		double price() const;
		double cost() const;
		void message(const char*);
		bool isClear() const;
	public:
		//Product();
		//Product(const char* one, const char* two, const char* three);
		Product(const char incomingType = 'N');
		Product(const char*, const char*, const char*, int incomingQuantity = 0, bool incomingTaxStatus = false, double incomingProductPrice = 0.0, int incomingQuantityNeeded = 0);
		Product(const Product&);
		Product& operator=(const Product&);
		~Product();
		std::fstream& store(std::fstream& file, bool newLine = true) const;
		std::fstream& load(std::fstream& file);
		std::ostream& write(std::ostream& os, bool linear) const;
		std::istream& read(std::istream& is);
		bool operator==(const char*) const;
		double total_cost() const;
		void quantity(int);
		bool isEmpty() const;
		int qtyNeeded() const;
		int quantity() const;
		bool operator>(const char*) const;
		bool operator>(const iProduct&) const;
		int operator+=(int);	
		void type(char);
	};
	std::ostream& operator<<(std::ostream&, const iProduct&);
	std::istream& operator>>(std::istream&, iProduct&);
	double operator+=(double&, const iProduct&);
}

#endif
