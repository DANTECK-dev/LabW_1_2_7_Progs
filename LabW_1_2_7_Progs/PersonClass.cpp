#pragma once

#include "Libraries.h"

#include "PersonClass.h"

void Person::Data::SortData		(Person*& head, Person*& tail, Person*& clients)
{
	if (tail == NULL && head == NULL)
		throw exception("\n\n\t��� ������ �������� ��� ����������...");

	if (clients == head && clients == tail)
		throw exception("\n\n\t���� ������ �������� ��� ����������...");

	clients = head;
	int counter = 1;
	Person* temp = new Person;
	
	while (true) 
	{
		counter++;
		clients = clients->next;
		if (clients == tail) break;
	}

	clients = head;

	for (int i = 1; i < counter; i++)
	{
		clients = head;

		for (int j = 0; j < counter - i; j++)
		{
			if (clients->DATA.Summ > clients->next->DATA.Summ)
			{
				temp->DATA = clients->DATA;
				clients->DATA = clients->next->DATA;
				clients->next->DATA = temp->DATA;
			}
			clients = clients->next;
		}
	}
	cout << "\n\n\t���������� �� ����� ���������, ������� ����� ������� ��� �������� � ����... ";
	char p = _getch();
	system("cls");
	return;
	
}

void Person::addClients			(Person*& head, Person*& tail, Person*& clients)
{
	cout << "\n\n\t���������� �������\n";
	string	newSurname = { "None" };
	string	newName = { "None" };
	string	newPatronymic = { "None" };
	string	newAddress = { "None" };
	string	newPhoneNum = { "None" };
	string	newPayDay = { "None" };
	char	newSumm[100];

	cout << "\n\t������� ������ �������\n";
	cout << "\n\t�������: "; 	cin.get();		getline(cin, newSurname);
	cout << "\n\t���: ";						getline(cin, newName);
	cout << "\n\t��������: ";					getline(cin, newPatronymic);
	cout << "\n\t������: ";						getline(cin, newAddress);
	cout << "\n\t����� �������� (��� +7): ";	getline(cin, newPhoneNum);
	cout << "\n\t���� ������ (��.��.����): ";	getline(cin, newPayDay);
	cout << "\n\t����� �������: ";				cin.getline(newSumm, 100); ;
	system("cls");

	int newSum = isInteger_l(newSumm);

	if (tail == NULL && head == NULL)
	{
		tail = new Person;
		clients = tail;
		head = tail;
	}

	else
	{
		clients = tail;
		clients->next = new Person;
		clients->next->prev = clients;
		clients = clients->next;
		tail = clients;
	}

	clients->DATA.Surname = newSurname;
	clients->DATA.Name = newName;
	clients->DATA.Patronymic = newPatronymic;
	clients->DATA.Address = newAddress;
	clients->DATA.PhoneNum = "+7" + newPhoneNum;
	clients->DATA.PayDay = newPayDay;
	clients->DATA.Summ = newSum;

	//(*counter)++;

	cout << "\n\t�������� \n" << "\n\t�������: " << newSurname
		<< "\n\t���: " << newName << "\n\t��������: " << newPatronymic
		<< "\n\t������: " << newAddress << "\n\t����� ��������: +7" << newPhoneNum
		<< "\n\t���� ������: " << newPayDay << "\n\t����� �������: " << newSumm;

	cout << "\n\n\t������� ����� ������� ��� �������� � ����... ";
	char p = _getch();
	system("cls");
	return;
}

void Person::sortClients		(Person*& head, Person*& tail, Person*& clients)
{
	if (tail == NULL && head == NULL)
		throw exception("\n\n\t��� ������ �������� ��� ����������...");

	if (clients == head && clients == tail)
		throw exception("\n\n\t���� ������ �������� ��� ����������...");

	cout << "\n\t����������� ���� �������� ��\n";
	cout << "\n\t1. �������\t2. ���\t0.�����\n\n\t";
	char inputNumm;
	cin >> inputNumm;

	int inputNum = isInteger(inputNumm);

	clients = head;
	int counter = 1;
	Person* temp = NULL;
	temp = new Person;

	while (true) {
		counter++;
		clients = clients->next;
		if (clients == tail) break;
	}

	clients = head;
	system("cls");
	switch (inputNum) {

	case(0):
		return;

	case(1): {
		for (int i = 1; i < counter; i++)
		{
			clients = head;
			for (int j = 0; j < counter - i; j++)
			{
				if (clients->DATA.Surname > clients->next->DATA.Surname)
				{
					temp->DATA = clients->DATA;
					clients->DATA = clients->next->DATA;
					clients->next->DATA = temp->DATA;
				}
				clients = clients->next;
			}
		}
		cout << "\n\n\t���������� �� ������� ���������, ������� ����� ������� ��� �������� � ����... ";
		char p = _getch();
		system("cls");
		return;
	}

	case(2): {
		for (int i = 1; i < counter; i++)
		{
			clients = head;
			for (int j = 0; j < counter - i; j++)
			{
				if (clients->DATA.Name > clients->next->DATA.Name)
				{
					temp->DATA = clients->DATA;
					clients->DATA = clients->next->DATA;
					clients->next->DATA = temp->DATA;
				}
				clients = clients->next;
			}
		}
		cout << "\n\n\t���������� �� ����� ���������, ������� ����� ������� ��� �������� � ����... ";
		char p = _getch();
		system("cls");
		return;
	}

	default: {
		throw exception("\n\n\t������� �������� ��������, ������� ����� ������� ��� �������� � ����... ");
	}
	}
	system("cls");
}

void Person::transform			(Person*& head, Person*& tail, Person*& clients)
{
	cout << "\n\n\t����� ������ ��������\n"
		<< "\n\t1. ������� - " << clients->DATA.Surname
		<< "\n\t2. ��� - " << clients->DATA.Name
		<< "\n\t3. �������� - " << clients->DATA.Patronymic
		<< "\n\t4. ������ - " << clients->DATA.Address
		<< "\n\t5. ���������� ����� - " << clients->DATA.PhoneNum
		<< "\n\t6. ���� ������ - " << clients->DATA.PayDay
		<< "\n\t7. ����� - " << clients->DATA.Summ
		<< "\n\t0. �����\n\n\t";
	char InIntt;
	cin >> InIntt;

	int InInt = isInteger(InIntt);

	switch (InInt) {
		case(0): return;
		case(1): {cout << "\n\n\t������� �������: ";		cin.get(); getline(cin, clients->DATA.Surname); 	break; }
		case(2): {cout << "\n\n\t������� ���: ";			cin.get(); getline(cin, clients->DATA.Name); 		break; }
		case(3): {cout << "\n\n\t������� ��������: ";		cin.get(); getline(cin, clients->DATA.Patronymic);	break; }
		case(4): {cout << "\n\n\t������� ������: ";			cin.get(); getline(cin, clients->DATA.Address); 	break; }
		case(5): {cout << "\n\n\t������� ����������: ";		cin.get(); getline(cin, clients->DATA.PhoneNum); 	break; }
		case(6): {cout << "\n\n\t������� ����: ";			cin.get(); getline(cin, clients->DATA.PayDay);		break; }
		case(7): {cout << "\n\n\t������� �����: ";			cin.get();		   cin >> clients->DATA.Summ;		break; }
		default: {
			throw exception("\n\n\t������� �������� ��������, ������� ����� ������� ��� �������� � ����... ");
		}
	}
	system("cls");
}
void Person::transformClients	(Person*& head, Person*& tail, Person*& clients)
{
	if (tail == NULL && head == NULL)
		throw exception("\n\n\t��� ������ �������� ��� ���������...");

	cout << "\n\n\t�������� ������ �������\n\n\t\t����� �� \n\n\t1. ���\t2. ����� � ����\t0. �����\n\n\t";
	char inputNumm;
	cin >> inputNumm;

	int inputNum = isInteger(inputNumm);

	system("cls");
	clients = head;

	switch (inputNum)
		{
		case(0): 
			return;

		case(1): {
			cout << "\n\n\t������� ������� ��� ��� ��� ��������. 0. �����\n\n\t";
			string inputStr;
			cin >> inputStr;
			system("cls");

			if (inputStr == "0") { return; }

			int searchID = -1;
			int couErr = 0;
			int id = 1;
			while (true) 
			{
				if (inputStr == clients->DATA.Surname)		{ searchID = id; couErr++; }
				if (inputStr == clients->DATA.Name)			{ searchID = id; couErr++; }
				if (inputStr == clients->DATA.Patronymic)	{ searchID = id; couErr++; }
				if (clients->next == NULL) break;
				clients = clients->next;
				id++;
			}
			if (couErr > 1) 
				throw exception("\n\n\t������� ����� ������ �������, ������� ������ ������� �������. ������� ����� ������� ��� �������� � ����... ");

			if (searchID == -1) 
				throw exception("\n\n\t������ �� ������, ������� ����� ������� ���-�� ��������� � ����... ");
				
			if (searchID >= 0) {
				clients = head;
				for (int i = 0; i < searchID - 1; i++) {
					clients = clients->next;
				}
				cout << "\n\n\t�������� ������ ������� " << clients->DATA.Surname << " " << clients->DATA.Name
					<< " " << clients->DATA.Patronymic << "\n\n\t1. ��\t2. ���\n\n\t";
				char inPP;
				cin >> inPP;

				int inP = isInteger(inPP);

				system("cls");
				switch (inP) 
				{
					case(1): {transform(head, tail, clients); return; }

					case(2): { return; }

					default: {
						throw exception("\n\n\t������� �������� ��������, ������� ����� ������� ��� �������� � ����... ");
					}

				}
			}
		}

		case(2): {
			cout << "\n\n\t������� ����� � ����. 0. �����\n\n\t";
			int inputInt;
			cin >> inputInt;

			if (inputInt == 0) { system("cls"); return; }

			for (int i = 0; i < inputInt - 1; i++) 
			{
				clients = clients->next;
			}

			system("cls");
			cout << "\n\n\t�������� ������ ������� " << clients->DATA.Surname << " " << clients->DATA.Name
				<< " " << clients->DATA.Patronymic << "\n\n\t1. ��\t2. ���\n\n\t";
			char inPP;
			cin >> inPP;

			int inP = isInteger(inPP);

			system("cls");
			switch (inP) 
			{
				case(1): {transform(head, tail, clients); return; }

				case(2): { return; }

				default: {
					throw exception("\n\n\t������� �������� ��������, ������� ����� ������� ��� �������� � ����... ");
				}

			}
		}

		default: {
			throw exception("\n\n\t������� �������� ��������, ������� ����� ������� ��� �������� � ����... ");
		}

	}

	system("cls");
}

void Person::swapAndDelClients	(Person*& head, Person*& tail, Person*& clients)
{
	if (clients != head && clients != tail) {
		clients->prev->next = clients->next;
		clients->next->prev = clients->prev;
		delete clients;
	}
	else if (clients == head && clients != tail) {
		head = clients->next;
		head->prev = NULL;
		delete clients;
	}
	else if (clients == tail && clients != head) {
		tail = clients->prev;
		tail->next = NULL;
		delete clients;
	}
	else {
		head = NULL;
		tail = NULL;

	}
}
void Person::delClients			(Person*& head, Person*& tail, Person*& clients)
{
	if (tail == NULL && head == NULL)
		throw exception("\n\n\t��� ������ �������� ��� ��������...");

	clients = head;
	while (true) {
		if (clients->next == NULL) break;
		clients = clients->next;
		tail = clients;
	}
	while (true) {
		if (clients->prev == NULL) break;
		clients = clients->prev;
		head = clients;
	}
	cout << "\n\t������� ������ �������\n\n\t\t����� �� \n\n\t1. ���\t2. ����� � ����\t0. �����\n\n\t";
	char inputNumm;
	cin >> inputNumm;

	int inputNum = isInteger(inputNumm);

	system("cls");
	clients = head;
	switch (inputNum)
	{
	case(0):
		return;

	case(1): {
		cout << "\n\n\t������� ������� ��� ��� ��� ��������. 0. �����\n\n\t";
		string inputStr;
		cin >> inputStr;
		system("cls");
		if (inputStr == "0") { return; }
		int id = 1;
		int searchID = -1;
		int couErr = 0;
		while (true) {
			if (inputStr == clients->DATA.Surname) { searchID = id; couErr++; }
			if (inputStr == clients->DATA.Name) { searchID = id; couErr++; }
			if (inputStr == clients->DATA.Patronymic) { searchID = id; couErr++; }
			if (clients == tail) break;
			clients = clients->next;
			id++;
		}
		if (couErr > 1)
			throw exception("\n\n\t������� ����� ������ �������, ������� ������ ������� �������. ������� ����� ������� ��� �������� � ����... ");

		if (searchID == -1)
			throw exception("\n\n\t������ �� ������, ������� ����� ������� ���-�� ��������� � ����... ");

		if (searchID >= 0) 
		{
			clients = head;
			for (int i = 1; i < searchID; i++)
				clients = clients->next;

			cout << "\n\n\t������� ������ ������� " << clients->DATA.Surname << " " << clients->DATA.Name
				<< " " << clients->DATA.Patronymic << "\n\n\t1. ��\t2. ���\n\n\t";
			char inputHH;
			cin >> inputHH;

			int inputH = isInteger(inputHH);

			system("cls");
			switch (inputH)
			{
			case(1):
			{
				swapAndDelClients(head, tail, clients);
				cout << "\n\n\t������� �������, ������� ����� ������� ��� ������ � ����... ";
				char p = _getch();
				system("cls");
				return;
			}
			case(2): { return; }

			default: {
				throw exception("\n\n\t������� �������� ��������, ������� ����� ������� ��� �������� � ����... ");
			}

			}
		}
	}

	case(2): {
		cout << "\n\n\t������� ����� � ����. 0. �����\n\n\t";
		int inputInt;
		cin >> inputInt;
		if (inputInt == 0)return;
		clients = head;
		for (int i = 0; i < inputInt - 1; i++)
		{
			clients = clients->next;
		}
		system("cls");
		cout << "\n\n\t������� ������ ������� " << clients->DATA.Surname << " " << clients->DATA.Name
			<< " " << clients->DATA.Patronymic << "\n\n\t1. ��\t2. ���\n\n\t";
		char inPP;
		cin >> inPP;

		int inP = isInteger(inPP);

		system("cls");
		switch (inP)
		{
		case(1):
		{
			swapAndDelClients(head, tail, clients);
			cout << "\n\n\t������� �������, ������� ����� ������� ��� ������ � ����... ";
			char p = _getch();
			system("cls");
			return;
		}

		case(2): { return; }

		default: {
			throw exception("\n\n\t������� �������� ��������, ������� ����� ������� ��� �������� � ����... ");
		}

		}
	}

	default: {
		throw exception("\n\n\t������� �������� ��������, ������� ����� ������� ��� �������� � ����... ");
	}

	}
	clients = head;
	system("cls");
}

void Person::showClients		(Person*& head, Person*& tail, Person*& clients)
{
	if (tail == NULL && head == NULL)
		throw exception("\n\n\t��� ������ �������� ��� ������...");

	cout << "\n\n\t������� ������ ��������\n\n";

	int maxLenSurname		= 7;
	int maxLenName			= 3;
	int maxLenPatronymic	= 8;
	int maxLenAddress		= 15;
	int maxLenPhoneNum		= 16;
	int maxLenPayDay		= 11;
	int maxLenSumm			= 13;

	int maxSumm				= 0;

	clients					= head;
	while (true)
	{
		int LenSurname		= clients->DATA.Surname.length();
		int LenName			= clients->DATA.Name.length();
		int LenPatronymic	= clients->DATA.Patronymic.length();
		int LenAddress		= clients->DATA.Address.length();
		int LenPhoneNum		= clients->DATA.PhoneNum.length();
		int LenPayDay		= clients->DATA.PayDay.length();
		int LenSumm			= 0;
		int Summ			= clients->DATA.Summ;
		int g				= 0;
		while (Summ > 0)	{ Summ /= 10; LenSumm++; }
		maxSumm				+= clients->DATA.Summ;

		if (LenSurname		> maxLenSurname)	{ maxLenSurname		= LenSurname;		}
		if (LenName			> maxLenName)		{ maxLenName		= LenName;			}
		if (LenPatronymic	> maxLenPatronymic)	{ maxLenPatronymic	= LenPatronymic;	}
		if (LenAddress		> maxLenAddress)	{ maxLenAddress		= LenAddress;		}
		if (LenPhoneNum		> maxLenPhoneNum)	{ maxLenPhoneNum	= LenPhoneNum;		}
		if (LenPayDay		> maxLenPayDay)		{ maxLenPayDay		= LenPayDay;		}
		if (LenSumm			> maxLenSumm)		{ maxLenSumm		= LenSumm;			}
		if (clients == tail) break;
		clients				= clients->next;
	}
	clients = head;
	int maxLength = maxLenSurname + maxLenName + maxLenPatronymic
		+ maxLenAddress + maxLenPhoneNum + maxLenPayDay + maxLenSumm + 22;



	cout << "\t";
	for (int i = 0; i < maxLength; i++) { cout << "-"; }
	cout << endl;

	printf_s("\t| %*s | %*s | %*s | %*s | %*s | %*s | %*s |",
		maxLenSurname,		"�������",
		maxLenName,			"���",
		maxLenPatronymic,	"��������",
		maxLenAddress,		"�������� ������",
		maxLenPhoneNum,		"���������� �����",
		maxLenPayDay,		"���� ������",
		maxLenSumm,			"����� �������");
	cout << "\n\t";

	for (int i = 0; i < maxLength; i++) { cout << "-"; }
	cout << "\n";

	while (true) 
	{
		printf_s(
			"\t| %*s | %*s | %*s | %*s | %*s | %*s | %*d |",
			maxLenSurname,		clients->DATA.Surname.c_str(),
			maxLenName,			clients->DATA.Name.c_str(),
			maxLenPatronymic,	clients->DATA.Patronymic.c_str(),
			maxLenAddress,		clients->DATA.Address.c_str(),
			maxLenPhoneNum,		clients->DATA.PhoneNum.c_str(),
			maxLenPayDay,		clients->DATA.PayDay.c_str(),
			maxLenSumm,			clients->DATA.Summ
		);

		cout << "\n\t";

		for (int i = 0; i < maxLength; i++) { cout << "-"; }
		cout << endl;
		if (clients->next == NULL) break;
		clients = clients->next;
	}
	clients = head;
	cout << "\t";
	for (int i = 0; i < maxLength - (maxLenPayDay + 6); i++) { cout << " "; }
	printf_s("| %*d |", maxLenSumm, maxSumm); cout << "\n\t";
	for (int i = 0; i < maxLength - (maxLenPayDay + 6); i++) { cout << " "; }
	for (int i = 0; i < maxLenPayDay + 6; i++) { cout << "-"; }


	cout << "\n\t������� ����� ������� ��� �������� � ����... "; char p = _getch(); system("cls");
	system("cls");
}

void Person::show				()
{
	cout << "\n\n\t���: " << this->DATA.Surname << " " << this->DATA.Name << " " << this->DATA.Patronymic 
		<< " ������: "<< this->DATA.Address 
		<< "\n\t��������� �����: " << this->DATA.PhoneNum 
		<< " ���� ������: " << this->DATA.PayDay 
		<< " �����: " << this->DATA.Summ;
}
void Person::searchClients		(Person*& head, Person*& tail, Person*& clients)
{
	if (tail == NULL && head == NULL)
		throw exception("\n\n\t��� ������ �������� ��� ������...");

	cout << "\n\t����� ������� �� ����";
	cout << "\n\n\t������� ������� ��� ��� ��� ��������\t0. �����\n\n\t";
	string inputStr;
	cin >> inputStr;
	system("cls");

	if (inputStr == "0") { return; }

	clients = head;
	bool searchID = false;
	while (true) {
		if (inputStr == clients->DATA.Surname) { searchID = true; show(); }
		if (inputStr == clients->DATA.Name) { searchID = true; show(); }
		if (inputStr == clients->DATA.Patronymic) { searchID = true; show(); }
		if (clients->next == NULL) break;
		clients = clients->next;
	}

	clients = head;

	if (searchID == true) { cout << "\n\n\t������� ����� ������� ���-�� ��������� � ����... "; char p = _getch(); system("cls");  return; }
	if (searchID == false) { cout << "\n\n\t������ �� ������, ������� ����� ������� ���-�� ��������� � ����... "; char p = _getch(); system("cls"); return; }
	system("cls");
}

void Person::saveClients		(Person*& head, Person*& tail, Person*& clients)
{
	if (tail == NULL && head == NULL)
		throw exception("\n\n\t��� ������ �������� ��� ����������...");

	string defaultFileName = (INDIVID_OUTPUT_FILE_LOCATION);
	cout << "\n\n\t1. ��������� � ����� � ��������� " << INDIVID_OUTPUT_FILE_LOCATION
		<< " � �������� �����\n\t2. �������� �������� �����\n\t0. �����\n\n\t";
	char inNumm;
	cin >> inNumm;

	int inNum = isInteger(inNumm);

	system("cls");
	switch (inNum) {

	case(0):
		return;

	case(1):
	{
		ofstream outClients(INDIVID_OUTPUT_FILE_LOCATION);
		clients = head;
		while (true) {
			outClients << "���: " << clients->DATA.Surname << " " << clients->DATA.Name << " "
				<< clients->DATA.Patronymic << " ������: " << clients->DATA.Address << " ����� ���.: "
				<< clients->DATA.PhoneNum << " ���� ������: " << clients->DATA.PayDay << " �����: "
				<< clients->DATA.Summ << endl;
			if (clients == tail) break;
			clients = clients->next;
		}
		cout << "\n\n\t���������� ����� " << INDIVID_OUTPUT_FILE_LOCATION << "...";
		char p = _getch();
		system("cls");
		break;
	}

	case(2):
	{
		cout << "\n\n\t������� ������� ��������� ����� (��� ����������, ��������� ������ �����): ";
		string newName;
		cin.get();
		getline(cin, newName);
		newName += ".txt";
		system("cls");
		ofstream outClients(newName);
		clients = head;
		while (true)
		{
			outClients << "���: " << clients->DATA.Surname << " " << clients->DATA.Name << " "
				<< clients->DATA.Patronymic << " ������: " << clients->DATA.Address << " ����� ���.: "
				<< clients->DATA.PhoneNum << " ���� ������: " << clients->DATA.PayDay << " �����: "
				<< clients->DATA.Summ << endl;
			if (clients == tail) break;
			clients = clients->next;
		}
		cout << "\n\n\t��������� � ����� " << newName << "...";
		char p = _getch();
		system("cls");
		break;
	}

	default: {
		throw exception("\n\n\t������� �������� ��������...");
	}

	}
}

void Person::downloadClients	(Person*& head, Person*& tail, Person*& clients)
{
	cout << "\n\n\t1. ��������� �� ����� � ��������� " << INDIVID_INPUT_FILE_LOCATION
		<< " � �������� �����\n\t2. �������� �������� �����\n\t0. �����\n\n\t";
	char inNumm;
	cin >> inNumm;

	int inNum = isInteger(inNumm);

	system("cls");
	switch (inNum)
	{
	case(0):
		return;

	case(1):
	{
		ifstream inClients(INDIVID_INPUT_FILE_LOCATION);

		if (inClients.bad())
			throw exception("\n\t������ �����-������ ��� ������");

		if (inClients.eof())
			throw exception("\n\t��������� ����� �����");

		if (inClients.fail())
			throw exception("\n\t�������� ������ ������");

		int size = 0;
		inClients >> size;

		for (int i = 0; i < size; i++)
		{
			if (clients == NULL) {
				clients = new Person;
				head = clients;
				tail = clients;
			}

			else {
				clients = tail;
				clients->next = new Person;
				clients->next->prev = clients;
				clients = clients->next;
				tail = clients;
			}

			inClients.get();
			getline(inClients, clients->DATA.Surname);
			getline(inClients, clients->DATA.Name);
			getline(inClients, clients->DATA.Patronymic);
			getline(inClients, clients->DATA.Address);
			getline(inClients, clients->DATA.PhoneNum);
			getline(inClients, clients->DATA.PayDay);
			inClients >> clients->DATA.Summ;
		}

		cout << "\n\n\t���������� �� ����� " << INDIVID_INPUT_FILE_LOCATION << "...";
		char p = _getch();
		system("cls");
		break;
	}

	case(2):
	{
		cout << "\n\n\t������� ������� ��������� ����� (��� ����������, ��������� ������ �����): ";
		string newName;
		cin.get();
		getline(cin, newName);
		newName += ".txt";
		system("cls");
		ifstream inClients(newName);

		if (inClients.bad())
			throw exception("\n\t������ �����-������ ��� ������");


		if (inClients.eof())
			throw exception("\n\t��������� ����� �����");


		if (inClients.fail())
			throw exception("\n\t�������� ������ ������");

		//if (inClients == NULL)
		//	throw exception("\n\t�������� ������ ������");

		int size = 0;
		inClients >> size;

		clients = new Person;
		head = clients;

		for (int i = 0; i < size; i++) {
			if (clients == NULL) {
				clients = new Person;
				head = clients;
			}
			else {
				clients = clients->next = new Person;
				tail = clients;
			}
			inClients.get();
			getline(inClients, clients->DATA.Surname);
			getline(inClients, clients->DATA.Name);
			getline(inClients, clients->DATA.Patronymic);
			getline(inClients, clients->DATA.Address);
			getline(inClients, clients->DATA.PhoneNum);
			getline(inClients, clients->DATA.PayDay);
			inClients >> clients->DATA.Summ;
		}

		cout << "\n\n\t���������� �� ����� " << newName << "...";
		char p = _getch();
		system("cls");
		break;
	}

	default: {
		throw exception("\n\n\t������� �������� ��������...");
	}
	}
}
