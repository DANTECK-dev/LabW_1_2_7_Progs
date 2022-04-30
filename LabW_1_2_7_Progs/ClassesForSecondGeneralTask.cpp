#include "Libraries.h"
#include "ClassesForSecondGeneralTask.h"



#pragma region General
General::General() {
	name = { "None" };
	companyName = { "None" };
	price = 0;
	weight = 0;
}
void General::setName(string name) {
	this->name = name;
}
void General::setCompanyName(string companyName) {
	this->companyName = companyName;
}
void General::setPrice(int price) {
	this->price = price;
}
void General::setWeight(int weight) {
	this->weight = weight;
}
string General::getGeneral() {
	return "Название продукта: " + name + 
		" Компания: " + companyName + 
		" Цена: " + to_string(price) + 
		" Вес: " + to_string(weight);
}
#pragma endregion 

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma region CannedProduct
CannedProduct::CannedProduct() {
	expirationDateInOpenState = 0;
	expirationDateInCloseState = 0;
	open = false;
}
void CannedProduct::setExpirationDateInOpenState(int expirationDateInOpenState) {
	this->expirationDateInOpenState = expirationDateInOpenState;
}
void CannedProduct::setExpirationDateInCloseState(int expirationDateInCloseState) {
	this->expirationDateInCloseState = expirationDateInCloseState;
}
void CannedProduct::setOpen(bool open) {
	this->open = open;
}
string CannedProduct::getCannedProduct() {
	string tempOpen;
	string tempExpiration;
	if (open) {
		if (expirationDateInOpenState == 0) 
			return "None";
		tempOpen = "Открытая"; 
		tempExpiration = to_string(expirationDateInOpenState);
	}
	else {
		if (expirationDateInCloseState == 0) 
			return "None";
		tempOpen = "Закрытая"; 
		tempExpiration = to_string(expirationDateInCloseState);
	}
	return getGeneral() + " Консерва: " 
		+ tempOpen + "Срок годности: " + tempExpiration;
}
#pragma endregion 

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma region FreshProduct
FreshProduct::FreshProduct() {
	expirationDate = 0;
}
void FreshProduct::setExpirationDate(int expirationDate) {
	this->expirationDate = expirationDate;
}
string FreshProduct::getFreshProduct() {
	if(expirationDate == 0)
		return "None";
	return getGeneral() + " Срок годности: " + to_string(expirationDate);
}
#pragma endregion 

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma region FoodProduct
int FoodProduct::getExpirationDate() {
	return expirationDate + expirationDateInCloseState + expirationDateInOpenState;
}
string FoodProduct::getFoodProduct() {
	if (getCannedProduct() != "None")
		return getCannedProduct();
	else if (getFreshProduct() != "None")
		return getFreshProduct();
	else
		return "None";
}
#pragma endregion 

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma region Accessories
Accessories::Accessories() {
	typeOfComponent = { "None" };
}
void Accessories::setTypeOfComponent(string typeOfComponent) {
	this->typeOfComponent = typeOfComponent;
}
string Accessories::getAccessories() {
	if (typeOfComponent == "None") 
		return "None";
	return getGeneral() + " Тип компонета: " + typeOfComponent;
	
}
void Accessories::setAccessories(string name,
		string companyName,
		int price,
		int weight) {
		setName(name);
		setCompanyName(companyName);
		setPrice(price);
		setWeight(weight);
	}
#pragma endregion 

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma region ElectronicGoods
ElectronicGoods::ElectronicGoods() {
	productType = { "None" };
}
void ElectronicGoods::setProductType(string productType) {
	this->productType = productType;
}
string ElectronicGoods::getElectronicGoods() {
	if (productType == "None")
		return "None";
	return getAccessories() + " Тип электроники " + productType;
}
void ElectronicGoods::setElectronicGoods(
	string name,
	string companyName,
	int price,
	int weight,
	string typeOfComponent) {
	setTypeOfComponent(typeOfComponent);
	setAccessories(name, companyName, price, weight);
}
#pragma endregion 

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma region Product
string Product::operator() (const Product& other) {
	Product Ptemp = other;
	if (Ptemp.getElectronicGoods() != "None")
		return getElectronicGoods() + "Тип электронного продукта: " + other.productType + " ";
	if(Ptemp.getFoodProduct() != "None")
		return getFoodProduct() + "Тип электронного продукта: " + other.productType + " ";
}
void Product::setProduct(
	string name,
	string companyName,
	int price,
	int weight,
	bool open,
	int expirationDateInCloseState,
	int expirationDateInOpenState,
	int expirationDate,
	string typeOfComponent,
	string productType) {
	if (productType != "None") 
		setProductType(productType);
	setElectronicGoods(name, companyName, price, weight, typeOfComponent);
}
#pragma endregion 