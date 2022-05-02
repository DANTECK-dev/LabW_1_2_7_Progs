#pragma once

#include "Libraries.h"

#include "ListOfBuyers.h"

#pragma region NaturalPerson
NaturalPerson::NaturalPerson() {
	this->FIO				= { "None" };
	this->mobilePhoneNumber = { "None" };
	this->accountNumber		= { "None" };
}
NaturalPerson::NaturalPerson(
	string FIO,
	string mobilePhoneNumber,
	string accountNumber
) {
	this->FIO				= FIO;
	this->mobilePhoneNumber = mobilePhoneNumber;
	this->accountNumber		= accountNumber;
}
#pragma endregion

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma region LegalPerson
LegalPerson::LegalPerson() {
	this->companuName	= { "None" };
	this->customerINN	= { "None" };
	this->accountNumber = { "None" };
}
LegalPerson::LegalPerson(
	string companuName,
	string customerINN,
	string accountNumber
) {
	this->companuName	= companuName;
	this->customerINN	= customerINN;
	this->accountNumber = accountNumber;

}
#pragma endregion

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma region DataProduct
DataProduct::DataProduct() {
	this->productName		= { "None" };
	this->typeOfProduct		= { "None" };
	this->paymentDay		= { "None" };
	this->vendorINN			= { "None" };
	this->companyAddress	= { "None" };
	this->numberOfProduct	= 0;
	this->sumOfProduct		= 0;

}
DataProduct::DataProduct(
	string productName,
	string typeOfProduct,
	string paymentDay,
	string vendorINN,
	string companyAddress,
	int numberOfProduct,
	int sumOfProduct
) {
	this->productName		= productName;
	this->typeOfProduct		= typeOfProduct;
	this->paymentDay		= paymentDay;
	this->vendorINN			= vendorINN;
	this->companyAddress	= companyAddress;
	this->numberOfProduct	= numberOfProduct;
	this->sumOfProduct		= sumOfProduct;
}
#pragma endregion

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma region ListItem
ListItem::ListItem() {
	this->next = NULL;
	this->prev = NULL;
}
ListItem::ListItem(
	ListItem* next,
	ListItem* prev
) {
	this->next = next;
	this->prev = prev;
}
#pragma endregion

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma region ListOfBuyers
void ListOfBuyers::addClients			(ListItem*& head, ListItem*& tail, ListItem*& clients) {
	system("cls");
	cout << "\n\t1 - Физическое лицо\n\t2 - Юридическое лицо\n\t0 - Выход";
	int inputNum;
	cin >> inputNum;
	switch (inputNum) {
	case(0): return;
	case(1): {

	}
	case(2):
	default:
	}
}
void ListOfBuyers::sortClients			(ListItem*& head, ListItem*& tail, ListItem*& clients) {

}
void ListOfBuyers::transformClients		(ListItem*& head, ListItem*& tail, ListItem*& clients) {

}
void ListOfBuyers::delClients			(ListItem*& head, ListItem*& tail, ListItem*& clients) {

}
void ListOfBuyers::showClients			(ListItem*& head, ListItem*& tail, ListItem*& clients) {

}
void ListOfBuyers::searchClients		(ListItem*& head, ListItem*& tail, ListItem*& clients) {

}
void ListOfBuyers::saveClients			(ListItem*& head, ListItem*& tail, ListItem*& clients) {

}
void ListOfBuyers::downloadClients		(ListItem*& head, ListItem*& tail, ListItem*& clients) {

}
#pragma endregion