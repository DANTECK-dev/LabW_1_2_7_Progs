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
	General(string name, string companyName, int price, int weight);
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
	CannedProduct(string name, string companyName, int price, int weight,
		int expirationDateInOpenState, int expirationDateInCloseState, bool open);
	void setExpirationDateInOpenState(int expirationDateInOpenState);
	void setExpirationDateInCloseState(int expirationDateInCloseState);
	void setOpen(bool open);
	string getCannedProduct();
	void setCannedProduct(string name,
		string companyName,
		int price,
		int weight);
};


class FreshProduct : General {
protected:
	int expirationDate;
public:
	FreshProduct();
	void setExpirationDate(int expirationDate);
	string getFreshProduct();
	void setFreshProduct(string name,
		string companyName,
		int price,
		int weight);
};


class FoodProduct : CannedProduct , FreshProduct{
protected:
	//Абстрактный класс
public:
	FoodProduct();
	int getExpirationDate();
	string getFoodProduct();
	void setFoodProduct(string name,
		string companyName,
		int price,
		int weight,
		int expirationDateInOpenState,
		int expirationDateInCloseState, 
		bool open,
		int expirationDate);
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
public:
	//Абстрактный класс
	Product* next = NULL;
	Product* prev = NULL;
	Product();
	operator string () const;
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