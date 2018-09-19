/****************************************/
/*  program: Product.cpp                */
/*  programmer: Yathavan Parameshwaran  */
/*  date: August 9, 2018	        */
/*  date of completion: August 9, 2018  */
/****************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string.h>
#include <fstream>
#include <iomanip>
#include "Product.h"
#include "ErrorState.h"
using namespace std;
namespace AMA
{
	void Product::name(const char *incomingName)
	{
		if (incomingName == nullptr)
		{
			nameOfProduct = nullptr;
		}
		else
		{
			if (nameOfProduct == nullptr)
			{
				nameOfProduct = new char[strlen(incomingName) + 1];
				strcpy(nameOfProduct, incomingName);
			}
			else
			{
				delete[] nameOfProduct;
				nameOfProduct = new char[strlen(incomingName) + 1];
				strcpy(nameOfProduct, incomingName);
			}
		}
	}
	const char *Product::name() const
	{
		if (nameOfProduct == nullptr)
		{
			return nullptr;
		}
		else
		{
			return nameOfProduct;
		}
	}
	const char *Product::sku() const
	{
		return &productSKU[0];
	}
	const char *Product::unit() const
	{
		return &productUnit[0];
	}
	bool Product::taxed() const
	{
		return productTax;
	}
	double Product::price() const
	{
		return unitPrice;
	}
	double Product::cost() const
	{
		if (taxed())
		{
			double tax = (unitPrice / 100) * 13;
			return (unitPrice + tax); //printing 13.94 b/c of added tax...
		}
		else
		{
			return unitPrice;
		}
		
	}
	void Product::message(const char *recievingMessage)
	{
		produState.message(recievingMessage);
	}
	bool Product::isClear() const
	{
		return produState.isClear();
	}
	Product::Product()
	{
		productSKU[0] = '\0';
		productUnit[0] = '\0';
		nameOfProduct = nullptr;
		quantityOnHand = 0;
		unitPrice = 0.0;
		productTax = false;
	}
	Product::Product(char incomingType)
	{
		productType = incomingType;
		productSKU[0] = '\0';
		productUnit[0] = '\0';
		nameOfProduct = nullptr;
		quantityOnHand = 0;
		unitPrice = 0.0;
		productTax = false;
	}

	Product::Product(const char *incomingSKU, const char *incomingName, const char *incomingUNIT, int incomingQuantity, bool incomingTaxStatus, double incomingProductPrice, int incomingQuantityNeeded)
	{
		
		strcpy(productSKU, incomingSKU);
		nameOfProduct = new char[strlen(incomingName) + 1];
		strcpy(nameOfProduct, incomingName);
		strcpy(productUnit, incomingUNIT);
		quantityOnHand = incomingQuantity;
		productTax = incomingTaxStatus;
		unitPrice = incomingProductPrice;
		quantityNeeded = incomingQuantityNeeded;
	}


	Product::Product(const Product &incomingObject)
	{
		nameOfProduct = nullptr;
		*this = incomingObject;
		
	}
	Product &Product::operator=(const Product &recievingObject)
	{
		if (this != &recievingObject)
		{
			quantityOnHand = recievingObject.quantityOnHand;
			quantityNeeded = recievingObject.quantityNeeded;
			unitPrice = recievingObject.unitPrice;
			productTax = recievingObject.productTax;

			strcpy(productSKU, recievingObject.productSKU);
			strcpy(productUnit, recievingObject.productUnit);
			delete[] nameOfProduct;
			nameOfProduct = nullptr;
			if (recievingObject.nameOfProduct != nullptr)
			{
				nameOfProduct = new char[strlen(recievingObject.nameOfProduct) + 1];
				strcpy(nameOfProduct, recievingObject.nameOfProduct);
			}
			else
			{
				nameOfProduct = nullptr;
			}
		}
		return *this;
	}
	Product::~Product()
	{
		delete[] nameOfProduct;
		nameOfProduct = nullptr;
	}
	std::fstream &Product::store(std::fstream &file, bool newLine) const
	{
		if (newLine)
		{
			file << productType << "," << productSKU << "," << productUnit << "," << nameOfProduct << "," << quantityOnHand << "," << quantityNeeded << "," << unitPrice << "," << endl;
		}
		else
		{
			file << productType << "," << productSKU << "," << productUnit << "," << nameOfProduct << "," << quantityOnHand << "," << quantityNeeded << "," << unitPrice << ",";
		}
		return file;
	}
	std::fstream &Product::load(std::fstream &file)
	{
		char newProductType = 'Z';
		char newProductSKU[max_sku_length] = "";
		char newProductUnit[max_unit_length] = "";
		char newNameOfProduct[max_name_length] = "";
		int newQuantityOnHand = 0;
		int newQuantityNeeded = 0;
		double newUnitPrice = 0.0;
		bool newProductTax = false;
		

		file >> newProductType;
		file.ignore(1, ',');
		file.getline(newProductSKU, max_sku_length, ',');
		file.ignore(1, ',');
		file.getline(newProductUnit, max_unit_length, ',');
		file.ignore(1, ',');
		file.getline(newNameOfProduct, 5000, ',');
		file.ignore(1, ',');
		file >> newQuantityOnHand;
		file.ignore(1, ',');
		file >> newQuantityNeeded;
		file.ignore(1, ',');

		*this = Product(newProductSKU, newNameOfProduct, newProductUnit, newQuantityOnHand, newProductTax, newUnitPrice, newQuantityNeeded);
		return file;
	}
	std::ostream &Product::write(std::ostream &os, bool linear) const
	{
		if (linear == true) 
		{
			os << std::setw(max_sku_length) << std::left << productSKU << "|" << std::setw(20) << std::left << nameOfProduct << "|" << std::setw(7) << std::fixed << std::setprecision(2) << std::right << cost() << "|" << std::setw(4) << std::right << quantityOnHand << "|" << std::setw(10) << std::left << productUnit << "|" << std::setw(4) << std::right << quantityNeeded << "|";
		}
		else
		{
			os << "Sku: " << this->productSKU << endl;
			os << "Name (no spaces): " << this->nameOfProduct << endl;
			os << "Price:  " << this->unitPrice << endl;
			if (taxed())
			{
				os << "Price after tax:  " << total_cost() << endl;
			}
			else
			{
				os << "N/A" << endl;
			}
			os << "Quantity on hand: " << qtyNeeded() << endl;
			os << "Quantity needed: " << this->quantityOnHand << endl;
		}
		return os;
	}
	std::istream &Product::read(std::istream &is) 
	{
		
		char newProductSKU[max_sku_length] = "";
		char newProductUnit[max_sku_length];
		char newNameOfProduct[max_name_length] = "";
		char newProductTax = '\0';
		int newQuantityOnHand = 0;
		int newQuantityNeeded = 0;
		double newUnitPrice = 0.0;
		bool taxation = true;

		cout << " Sku: ";
		is >> newProductSKU;
		cout << " Name (no spaces): ";
		is >> newNameOfProduct;
		cout << " Unit: ";
		is >> newProductUnit;
		cout << " Taxed? (y/n): ";
		is >> newProductTax;
		
		if (newProductTax == 'Y' || newProductTax == 'N' || newProductTax == 'y' || newProductTax == 'n') //checking failure for input of newProductTax //bug report... for some reason, even though the output is "y", it is triggering the if statement...  //fixed.
		{
			if (newProductTax == 'Y' || newProductTax == 'y')
				taxation = true;
			else
				taxation = false;
			cout << " Price: ";
			is >> newUnitPrice;
			if (!is.fail()) //checking failure for input of newUnitPrice
			{
				cout << " Quantity on hand: ";
				is >> newQuantityOnHand;
				if (!is.fail()) //checking failure for input of newQuantityOnHand
				{
					cout << " Quantity needed: ";
					is >> newQuantityNeeded;
					if (!is.fail()) //this signifies that all input was successfully recorded... and thus created a temporary object with all the accepted data, then proceeds to copy assign it to the current object...
					{
						*this = Product(newProductSKU, newNameOfProduct, newProductUnit, newQuantityOnHand, taxation, newUnitPrice, newQuantityNeeded);
					}
					else //checking failure of input, if any, of newQuantity Needed
					{
						*this = Product(newProductSKU, newNameOfProduct, newProductUnit, newQuantityOnHand, taxation, newUnitPrice, newQuantityNeeded);
						produState.message("Invalid Quantity Needed Entry");
					}
				}
				else //if there are no problems with the input for newQuantityOnHand //new: if anything is wrong!
				{
					produState.message("Invalid Quantity Entry");
				}
			}
			else //if all is well with newUnitPrice //new: if anything is wrong!
			{
				produState.message("Invalid Price Entry");
			}
		}
		else
		{
			produState.message("Only (Y)es or (N)o are acceptable");
			is.istream::setstate(std::ios::failbit);

		}
		return is;
		
	}
	bool Product::operator==(const char *incomingSKU) const
	{
		if (strcmp(productSKU, incomingSKU))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	double Product::total_cost() const
	{
		double subtotal = quantityOnHand * unitPrice;
		double taxValue = (subtotal / 100) * 13;
		double totalValue = subtotal + taxValue;
		return totalValue;
	}
	void Product::quantity(int incomingNumberOfUnitsOnHand)
	{
		quantityOnHand = incomingNumberOfUnitsOnHand;
	}
	bool Product::isEmpty() const
	{
		if ((productType == '\0') && (productSKU[0] == '\0') && (productUnit[0] == '\0') && (nameOfProduct == nullptr) && (quantityOnHand == 0) && (quantityNeeded == 0) && (unitPrice == 0.0) && (productTax == false))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	int Product::qtyNeeded() const
	{
		return quantityNeeded;
	}
	int Product::quantity() const
	{
		return quantityOnHand;
	}
	bool Product::operator>(const char * incomingProductSKU) const
	{
		//return false;
		if ((this->productSKU) > (incomingProductSKU))
		{
			return true;
		}
		else
		{
			return false;
		}

	}
	bool Product::operator>(const Product &incomingObject) const
	{
		//return false;
		if ((this->nameOfProduct) > (incomingObject.nameOfProduct))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	int Product::operator+=(int incomingNumberOfUnitsToBeAdded)
	{
		if (incomingNumberOfUnitsToBeAdded > 0)
		{
			return (quantityOnHand + incomingNumberOfUnitsToBeAdded);
		}
		else
		{
			return quantityOnHand;
		}
	}
	std::ostream &operator<<(std::ostream &os, const Product &proc)
	{
		

		return proc.write(os, true);
	}
	std::istream &operator>>(std::istream &is, Product &pr)
	{
		// TODO: insert return statement here
		return pr.read(is);
	}
	double operator+=(double &incomingFloatingPoint, const Product &poorBastard)
	{
		double alpha = poorBastard.total_cost();
		return (alpha + incomingFloatingPoint);
	}
} 
