#pragma once
#include "Libraries.h"

class General {
protected:
	string	name;
	string	companyName;
	int		price;
	int		weight;
public:
	General();
	void setName(string name);
	void setCompanyName(string companyName);
	void setPrice(int price);
	void setWeight(int weight);
	string getGeneral();
};


class CannedProduct : General{
protected:
	int expirationDateInOpenState;
	int expirationDateInCloseState;
	bool open;
public:
	CannedProduct();
	void setExpirationDateInOpenState(int expirationDateInOpenState);
	void setExpirationDateInCloseState(int expirationDateInCloseState);
	void setOpen(bool open);
	string getCannedProduct();
};


class FreshProduct : General {
protected:
	int expirationDate;
public:
	FreshProduct();
	void setExpirationDate(int expirationDate);
	string getFreshProduct();
};


class FoodProduct : CannedProduct , FreshProduct{
protected:
	//Абстрактный класс
public:
	int getExpirationDate();
	string getFoodProduct();
};


class Accessories : General {
protected:
	string typeOfComponent;	// of which it is a part
public:
	Accessories();
	void setTypeOfComponent(string typeOfComponent);
	string getAccessories();
	void setAccessories(string name,
		string companyName,
		int price,
		int weight);
};


class ElectronicGoods : Accessories{
protected:
	string productType;
public:
	ElectronicGoods();
	void setProductType(string productType);
	string getElectronicGoods();
	void setElectronicGoods(
		string name,
		string companyName,
		int price,
		int weight,
		string typeOfComponent);
};


class Product : FoodProduct, ElectronicGoods{
private:
	//Абстрактный класс
	string operator() (const Product& other);
public:
	void setProduct (
		string name,
		string companyName,
		int price,
		int weight,
		bool open,
		int expirationDateInCloseState,
		int expirationDateInOpenState,
		int expirationDate,
		string typeOfComponent,
		string productType
	);
};