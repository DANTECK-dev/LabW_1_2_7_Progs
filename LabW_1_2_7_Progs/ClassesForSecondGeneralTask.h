#pragma once
#include "Libraries.h"

class General {
	string Name;
	string CompanyName;
	double weight;
};
class CannedProduct : General{
	int expirationDateInOpenState;
	int expirationDateInCloseState;
	bool Open;
	
};

class FreshProduct : General {
	int expirationDate;
};

class FoodProduct : CannedProduct , FreshProduct{
	//Абстрактный класс
};

class Accessories : General {
	string typeOfComponent;	// of which it is a part
};

class ElectronicGoods : Accessories{
	string productType;
};

class Product : FoodProduct, ElectronicGoods{
	//Абстрактный класс
	string operator string() (static Product other);
};