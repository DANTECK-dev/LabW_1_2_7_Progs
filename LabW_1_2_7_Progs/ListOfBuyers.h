#pragma once

#include "Libraries.h"

class DataPerson {
public:
	virtual void setName	(string) = 0;
	virtual void setInfoNum	(string) = 0;
	virtual void setPayNum	(string) = 0;

	virtual string getName		() = 0;
	virtual string getInfoNum	() = 0;
	virtual string getPayNum	() = 0;
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class NaturalPerson : public DataPerson {
private:
	string FIO;
	string mobilePhoneNumber;
	string accountNumber;
public:
	NaturalPerson();
	NaturalPerson(
		string FIO,
		string mobilePhoneNumber, 
		string accountNumber
	);
	void setName(string FIO)					override { this->FIO				= FIO; };
	void setInfoNum(string mobilePhoneNumber)	override { this->mobilePhoneNumber	= mobilePhoneNumber; };
	void setPayNum(string accountNumber)		override { this->accountNumber		= accountNumber; };

	string getName()	override { return FIO; };
	string getInfoNum() override { return mobilePhoneNumber; };
	string getPayNum()	override { return accountNumber; };
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class LegalPerson : public DataPerson {
private:
	string companuName;
	string customerINN;
	string accountNumber;
public:
	LegalPerson();
	LegalPerson(
		string companuName,
		string customerINN,
		string accountNumber
	);
	void setName(string companuName)		override { this->companuName	= companuName; };
	void setInfoNum(string customerINN)		override { this->customerINN	= customerINN; };
	void setPayNum(string accountNumber)	override { this->accountNumber	= accountNumber; };

	string getName()	override { return companuName; };
	string getInfoNum() override { return customerINN; };
	string getPayNum()	override { return accountNumber; };
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class DataProduct {
private:
	string productName;
	string typeOfProduct;
	string paymentDay;
	string vendorINN;
	string companyAddress;
	int numberOfProduct;
	int sumOfProduct;
public:
	DataProduct();
	DataProduct(
		string productName,
		string typeOfProduct,
		string paymentDay,
		string vendorINN,
		string companyAddress,
		int numberOfProduct,
		int sumOfProduct
	);
	void setProductName		(string productName)	{ this->productName		= productName;		};
	void setTypeOfProduct	(string typeOfProduct)	{ this->typeOfProduct	= typeOfProduct;	};
	void setPaymentDay		(string paymentDay)		{ this->paymentDay		= paymentDay;		};
	void setVendorINN		(string vendorINN)		{ this->vendorINN		= vendorINN;		};
	void setCompanyAddress	(string companyAddress)	{ this->companyAddress	= companyAddress;	};
	void setNumberOfProduct	(int numberOfProduct)	{ this->numberOfProduct	= numberOfProduct;	};
	void setSumOfProduct	(int sumOfProduct)		{ this->sumOfProduct	= sumOfProduct;		};

	string  getProductName()	{ return this->productName;		};
	string  getTypeOfProduct()	{ return this->typeOfProduct;	};
	string  getPaymentDay()		{ return this->paymentDay;		};
	string  getVendorINN()		{ return this->vendorINN;		};
	string  getCompanyAddress()	{ return this->companyAddress;	};
	int		getNumberOfProduct(){ return this->numberOfProduct;	};
	int		getSumOfProduct()	{ return this->sumOfProduct;	};
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class ListItem : public DataPerson, public DataProduct {
protected:
	ListItem* next;
	ListItem* prev;
public:
	ListItem();
	ListItem(
		ListItem* next,
		ListItem* prev
	);
	void nextItem();
	void prevItem();

};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class ListOfBuyers {
private:
	ListItem* person	= NULL;
	ListItem* head		= NULL;
	ListItem* tail		= NULL;
public:
	void addClients			(ListItem*& head, ListItem*& tail, ListItem*& clients);
	void sortClients		(ListItem*& head, ListItem*& tail, ListItem*& clients);
	void transformClients	(ListItem*& head, ListItem*& tail, ListItem*& clients);
	void delClients			(ListItem*& head, ListItem*& tail, ListItem*& clients);
	void showClients		(ListItem*& head, ListItem*& tail, ListItem*& clients);
	void searchClients		(ListItem*& head, ListItem*& tail, ListItem*& clients);
	void saveClients		(ListItem*& head, ListItem*& tail, ListItem*& clients);
	void downloadClients	(ListItem*& head, ListItem*& tail, ListItem*& clients);
};