#pragma once

#include "Libraries.h"

#include "ListOfBuyers.h"

#pragma region NaturalPerson
NaturalPerson::NaturalPerson() {				//Физическое лицо
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
LegalPerson::LegalPerson() {					//Юридическое лицо
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
	bool legalPerson,
	string productName,
	string typeOfProduct,
	string paymentDay,
	string vendorINN,
	string companyAddress,
	int numberOfProduct,
	int sumOfProduct,
	string FIO,
	string mobilePhoneNumber,
	string companuName,
	string customerINN,
	string accountNumber
) {
	this->productName		= productName;
	this->typeOfProduct		= typeOfProduct;
	this->paymentDay		= paymentDay;
	this->vendorINN			= vendorINN;
	this->companyAddress	= companyAddress;
	this->numberOfProduct	= numberOfProduct;
	this->sumOfProduct		= sumOfProduct;
	if (legalPerson) {
		LegalPerson::LegalPerson(
			companuName,
			customerINN,
			accountNumber
		);
	}
	else {
		NaturalPerson::NaturalPerson(
			FIO,
			mobilePhoneNumber,
			accountNumber
		);
	}
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
	ListItem* prev,
	bool legalPerson,
	string productName,
	string typeOfProduct,
	string paymentDay,
	string vendorINN,
	string companyAddress,
	int numberOfProduct,
	int sumOfProduct,
	string FIO,
	string mobilePhoneNumber,
	string companuName,
	string customerINN,
	string accountNumber
) {
	this->next = next;
	this->prev = prev;
	DataProduct::DataProduct(
		legalPerson,
		productName,
		typeOfProduct,
		paymentDay,
		vendorINN,
		companyAddress,
		numberOfProduct,
		sumOfProduct,
		FIO,
		mobilePhoneNumber,
		companuName,
		customerINN,
		accountNumber
	);
}
#pragma endregion

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma region ListOfBuyers
void ListOfBuyers::addClients			() {
	system("cls");
	cout << "\n\n\tДобавление клиента\n";
	cout << "\n\t1 - Физическое лицо\n\t2 - Юридическое лицо\n\t0 - Выход\n\t";
	int inputNum;
	cin >> inputNum;
	system("cls");
	switch (inputNum) {
	case(0): return;
	case(1): {
		string newSurname			= { "None" };
		string newName				= { "None" };
		string newPatronymic		= { "None" };
		string newMobilePhoneNumber	= { "None" };
		string newAccountNumber		= { "None" };

		string newProductName		= { "None" };
		string newTypeOfProduct		= { "None" };
		string newPaymentDay		= { "None" };
		char TempNewNumberOfProduct[100];
		char TempNewSumOfProduct[1000];

		cout << "\n\tВведите данные клиента\n";
		cout << "\n\tФамилия: "; 	cin.get();		getline(cin, newSurname);
		cout << "\n\tИмя: ";						getline(cin, newName);
		cout << "\n\tОтчество: ";					getline(cin, newPatronymic);
		string newFIO = newSurname + " " + newName + " " + newPatronymic;

		cout << "\n\tНомер телефона: ";				getline(cin, newMobilePhoneNumber);
		cout << "\n\tНомер счёта: ";				getline(cin, newAccountNumber);

		cout << "\n\tВведите данные продукта\n";
		cout << "\n\tНазвание продукта: ";			getline(cin, newProductName);
		cout << "\n\tТип продукта: ";				getline(cin, newTypeOfProduct);
		cout << "\n\tДень оплаты (ДД.ММ.ГГГГ): ";	getline(cin, newPaymentDay);
		cout << "\n\tКол-во продуктов: ";			cin.getline(TempNewNumberOfProduct, 100);
		int newNumberOfProduct = isInteger_l(TempNewNumberOfProduct);
		cout << "\n\tСумму покупки: ";				cin.getline(TempNewSumOfProduct, 1000);
		int newSumOfProduct = isInteger_l(TempNewSumOfProduct);
		int newLegalPerson = false;
		system("cls");

		if (tail == NULL && head == NULL)
		{
			tail = new ListItem(
				NULL,
				NULL,
				newLegalPerson,
				newProductName,
				newTypeOfProduct,
				newPaymentDay,
				VendorINN,
				CompanyAddress,
				newNumberOfProduct,
				newSumOfProduct,
				newFIO,
				newMobilePhoneNumber,
				"None",
				"None",
				newAccountNumber);
			person = tail;
			head = tail;
		}

		else
		{
			person = tail;
			person->next = new ListItem(
				NULL,
				person,
				newLegalPerson,
				newProductName,
				newTypeOfProduct,
				newPaymentDay,
				VendorINN,
				CompanyAddress,
				newNumberOfProduct,
				newSumOfProduct,
				newFIO,
				newMobilePhoneNumber,
				"None",
				"None",
				newAccountNumber);;
			//person->next->prev = person;
			person = person->next;
			tail = person;
		}

		cout << "\n\tДобавлен \n" << "\n\tФИО: " << newFIO
			<< "\n\tНомер телефона: " << newMobilePhoneNumber
			<< "\n\tНомер счёта: " << newAccountNumber
			<< "\n\tНазвание продукта: " << newTypeOfProduct
			<< "\n\tТип продукта: " << newTypeOfProduct
			<< "\n\tДень оплаты (ДД.ММ.ГГГГ): " << newPaymentDay
			<< "\n\tКол-во продуктов: " << newNumberOfProduct
			<< "\n\tСумму покупки: " << newSumOfProduct;

		cout << "\n\n\t";
		system("pause");
		system("cls");
		return;
	}
	case(2): {
		return;
	}
	default: {
		cout << "\n\tОшибка ввода ";
		system("pause");
		system("cls");
		return;
	}
	}
}
void ListOfBuyers::sortClients			() {

}
void ListOfBuyers::transformClients		() {

}
void ListOfBuyers::delClients			() {

}
void ListOfBuyers::showClients			() {

}
void ListOfBuyers::searchClients		() {

}
void ListOfBuyers::saveClients			() {

}
void ListOfBuyers::downloadClients		() {

}
#pragma endregion