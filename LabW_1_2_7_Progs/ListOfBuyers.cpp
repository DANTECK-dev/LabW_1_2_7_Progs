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
string DataProduct::getDataProduct() {
	return this->productName + " " + this->typeOfProduct				+ " " +
		this->paymentDay	 + " " + this->vendorINN					+ " " +
		this->companyAddress + " " + to_string(this->numberOfProduct)	+ " " +
		to_string(this->sumOfProduct);
}
#pragma endregion

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma region ListItem
ListItem::ListItem() {
	this->legalPerson = false;
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
	this->DataProduct::DataProduct(
		productName,
		typeOfProduct,
		paymentDay,
		vendorINN,
		companyAddress,
		numberOfProduct,
		sumOfProduct
	);
	if (legalPerson) {
		this->LegalPerson::LegalPerson(			//Юр лицо
			companuName,
			customerINN,
			accountNumber
		);
	}
	else {
		this->NaturalPerson::NaturalPerson(		//Физ лицо
			FIO,
			mobilePhoneNumber,
			accountNumber
		);
	}
	this->legalPerson = legalPerson;
	this->next = next;
	this->prev = prev;
}
ostream& ListItem::operator << (ostream& os) {
	string personType;
	string personData;
	if (this->legalPerson) { personType = { "Юридическое лицо" }; personData = this->LegalPerson::getDataPerson(); }
	else { personType = { "Физическое лицо" }; personData = this->NaturalPerson::getDataPerson(); }

	os << personType << " " 
		<< personData << " "
		<< this->getDataProduct();
	return  os;
}
#pragma endregion

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma region ListOfBuyers
void ListOfBuyers::operator[](const int index) {
	ListOfBuyers* LItemp = this->head;
	for (int i = 0; i < index; i++)
		LItemp = LItemp->next;
	
}

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

			cout << "\n\t\tВведите данные клиента\n";
			cout << "\n\tФамилия: "; 	cin.get();		getline(cin, newSurname);
			cout << "\n\tИмя: ";						getline(cin, newName);
			cout << "\n\tОтчество: ";					getline(cin, newPatronymic);
			string newFIO = newSurname + " " + newName + " " + newPatronymic;

			cout << "\n\tНомер телефона: ";				getline(cin, newMobilePhoneNumber);
			cout << "\n\tНомер счёта: ";				getline(cin, newAccountNumber);

			cout << "\n\t\tВведите данные продукта\n";
			cout << "\n\tНазвание продукта: ";			getline(cin, newProductName);
			cout << "\n\tТип продукта: ";				getline(cin, newTypeOfProduct);
			cout << "\n\tДень оплаты (ДД.ММ.ГГГГ): ";	getline(cin, newPaymentDay);
			cout << "\n\tКол-во продуктов: ";			cin.getline(TempNewNumberOfProduct, 100);
			int newNumberOfProduct = isInteger_l(TempNewNumberOfProduct);
			cout << "\n\tСумму покупки: ";				cin.getline(TempNewSumOfProduct, 1000);
			int newSumOfProduct = isInteger_l(TempNewSumOfProduct);
			bool newLegalPerson = false;
			system("cls");

			if (person == NULL) {
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
			else if (tail != NULL) {
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

			cout << "\n\t\tДобавлен \n" 
				<< "\n\tФИО: " << newFIO
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
			string newCompanyName = { "None" };
			string newCustomerINN = { "None" };
			string newAccountNumber = { "None" };

			string newProductName = { "None" };
			string newTypeOfProduct = { "None" };
			string newPaymentDay = { "None" };
			char TempNewNumberOfProduct[100];
			char TempNewSumOfProduct[1000];

			cout << "\n\t\tВведите данные клиента\n";
			cout << "\n\tНазвание компании: ";cin.get();getline(cin, newCompanyName);
			cout << "\n\tНомер ИНН: ";					getline(cin, newCustomerINN);
			cout << "\n\tНомер счёта: ";				getline(cin, newAccountNumber);

			cout << "\n\t\tВведите данные продукта\n";
			cout << "\n\tНазвание продукта: ";			getline(cin, newProductName);
			cout << "\n\tТип продукта: ";				getline(cin, newTypeOfProduct);
			cout << "\n\tДень оплаты (ДД.ММ.ГГГГ): ";	getline(cin, newPaymentDay);
			cout << "\n\tКол-во продуктов: ";			cin.getline(TempNewNumberOfProduct, 100);
			int newNumberOfProduct = isInteger_l(TempNewNumberOfProduct);
			cout << "\n\tСумму покупки: ";				cin.getline(TempNewSumOfProduct, 1000);
			int newSumOfProduct = isInteger_l(TempNewSumOfProduct);
			bool newLegalPerson = true;
			system("cls");

			if (tail == NULL && head == NULL) {
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
					"None",
					"None",
					newCompanyName,
					newCustomerINN,
					newAccountNumber);
				person = tail;
				head = tail;

			}
			else if(tail != NULL) {
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
					"None",
					"None",
					newCompanyName,
					newCustomerINN,
					newAccountNumber);
				//person->next->prev = person;
				person = person->next;
				tail = person;
			}
			cout << "\n\t\tДобавлен \n" 
				<< "\n\tНазвание компании: " << newCompanyName
				<< "\n\tНомер ИНН: " << newCustomerINN
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
		default: {
			cout << "\n\tОшибка ввода ";
			system("pause");
			system("cls");
			return;
		}
	}
}
//финих
void ListOfBuyers::sortClients			() {
	if (tail == NULL || head == NULL) {
		cout << "\n\n\tНет данных клиентов для сортировки\n";
		system("cls");
		system("cls");
		return;
	}
	if (person == head && person == tail) {
		cout << "\n\n\tНет данных клиентов для сортировки\n";
		system("cls");
		system("cls");
		return;
	}
	person = head;
	int counter = 1;
	ListItem* temp = NULL;

	while (true)
	{
		counter++;
		person = person->next;
		if (person == tail) break;
	}

	person = head;

	if (person == head && person->next == tail) {
		for (int i = 1; i < counter; i++)
		{
			person = head;

			for (int j = 0; j < counter - i; j++)
			{
				if (person->getSumOfProduct() > person->next->getNumberOfProduct())
				{
					ListItem* TempNext1 = person->next;
					ListItem* TempPrev1 = person->prev;
					ListItem* TempNext2 = person->next->next;
					ListItem* TempPrev2 = person->next->prev;
					
					head = person->next;
					person->next->next = person;
					person->prev = person->next;
					person->next->prev == NULL;
					person->next = NULL;
				}
				person = person->next;
			}
		}
	} else if (person == head && person->next != tail) {
		for (int i = 1; i < counter; i++)
		{
			person = head;

			for (int j = 0; j < counter - i; j++)
			{
				if (person->getSumOfProduct() > person->next->getNumberOfProduct())
				{
					ListItem* Temp1 = person;
					ListItem* Temp2 = person->next;
					ListItem* Temp3 = person->next->next;

					head = person->next;
					Temp3->prev = Temp1;
					Temp2->next = Temp1;
					Temp2->prev = NULL;
					Temp1->next = Temp3;
					Temp1->prev = Temp2;
				}
				person = person->next;
			}
		}
	} else if (person != head && person->next == tail) {
		for (int i = 1; i < counter; i++)
		{
			person = head;

			for (int j = 0; j < counter - i; j++)
			{
				if (person->getSumOfProduct() > person->next->getNumberOfProduct())
				{
					ListItem* Temp1 = person->prev;
					ListItem* Temp2 = person;
					ListItem* Temp3 = person->next;

					tail = person->next;
					Temp1->next = Temp3;
					Temp2->next = NULL;
					Temp2->prev = Temp3;
					Temp3->next = Temp2;
					Temp3->prev = Temp1;
				}
				person = person->next;
			}
		}
	} else if (person != head && person->next != tail) {
		for (int i = 1; i < counter; i++)
		{
			person = head;

			for (int j = 0; j < counter - i; j++)
			{
				if (person->getSumOfProduct() > person->next->getNumberOfProduct())
				{
					ListItem* Temp1 = person->prev;
					ListItem* Temp2 = person;
					ListItem* Temp3 = person->next;
					ListItem* Temp4 = person->next->next;

					Temp1->next = Temp3;
					Temp2->next = Temp4;
					Temp2->prev = Temp3;
					Temp3->next = Temp2;
					Temp3->prev = Temp1;
					Temp4->prev = Temp2;
				}
				person = person->next;
			}
		}
	}
	cout << "\n\n\tСортировка по сумме завершена\n";
	system("pause");
	system("cls");
	return;
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