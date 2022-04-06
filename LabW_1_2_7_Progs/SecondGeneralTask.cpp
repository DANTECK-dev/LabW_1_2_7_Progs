#include "SecondGeneralTask.h"
#include "ThisIs.h"

#include "Libraries.h"

enum class secondGeneralTaskMenu
{
	Exit,
	Addition,
	Subtraction,
	Multiplication,
	Division
};

class Human
{
private:
	char* Name,
		* Surname,
		* Patronymic,
		* Age,
		* Gender;

	int lenName,
		lenSurname,
		lenPatronymic,
		lenAge,
		lenGender;

public:

	Human()
	{
		cout << "\n\tпустой конструктор\n\t";

		this->lenName = 5;
		this->lenSurname = 7;
		this->lenPatronymic = 9;
		this->lenAge = 3;
		this->lenGender = 8;

		this->Name			= new char[this->lenName];
		this->Surname		= new char[this->lenSurname];
		this->Patronymic	= new char[this->lenPatronymic];
		this->Age			= new char[this->lenAge];
		this->Gender		= new char[this->lenGender];

		Patronymic[0] = 'И';	Gender[0] = 'м';	Surname[0] = 'И';	Name[0] = 'И';		Age[0] = '2';
		Patronymic[1] = 'в';	Gender[1] = 'у';	Surname[1] = 'в';	Name[1] = 'в';		Age[1] = '3';
		Patronymic[2] = 'а';	Gender[2] = 'ж';	Surname[2] = 'а';	Name[2] = 'а';		Age[2] = '\0';
		Patronymic[3] = 'н';	Gender[3] = 'c';	Surname[3] = 'н';	Name[3] = 'н';
		Patronymic[4] = 'о';	Gender[4] = 'к';	Surname[4] = 'о';	Name[4] = '\0';
		Patronymic[5] = 'в';	Gender[5] = 'о';	Surname[5] = 'в';
		Patronymic[6] = 'и';	Gender[6] = 'й';	Surname[6] = '\0';
		Patronymic[7] = 'ч';	Gender[7] = '\0';
		Patronymic[8] = '\0';
	}

	/*	Human(char Name[], char Surname[], char Patronymic[], char Age[], char Gender[])
	{
		this->Name = Name;
		this->Surname = Surname;
		this->Patronymic = Patronymic;
		this->Age = Age;
		this->Gender = Gender;
	}*/

	Human(string Name, string Surname, string Patronymic, string Age, string Gender)
	{
		cout << "\n\tконструктор с параметрами\n\t";

		lenName = Name.length();
		lenSurname = Surname.length();
		lenPatronymic = Patronymic.length();
		lenAge = Age.length();
		lenGender = Gender.length();

		this->Name = new char[lenName];
		this->Surname = new char[lenSurname];
		this->Patronymic = new char[lenPatronymic];
		this->Age = new char[lenAge];
		this->Gender = new char[lenGender];

		for (int i = 0; i < this->lenName; i++)
			this->Name[i] = Name[i];
		this->Name[lenName] = '\0';

		for (int i = 0; i < this->lenSurname; i++)
			this->Surname[i] = Surname[i];
		this->Surname[lenSurname] = '\0';

		for (int i = 0; i < this->lenPatronymic; i++)
			this->Patronymic[i] = Patronymic[i];
		this->Patronymic[lenPatronymic] = '\0';

		for (int i = 0; i < this->lenAge; i++)
			this->Age[i] = Age[i];
		this->Age[lenAge] = '\0';


		for (int i = 0; i < this->lenGender; i++)
			this->Gender[i] = Gender[i];
		this->Gender[lenGender] = '\0';
		/*
		this->Name*			= Name.c_str();
		this->Surname*		= Surname.c_str();
		this->Patronymic	= Patronymic.c_str();
		this->Age			= Age.c_str();
		this->Gender		= Gender.c_str();
		*/
	}

	Human(const Human&other)
	{
		cout << "\n\tконструктор копирования\n\t";

		this->lenName = other.lenName; 
		this->lenSurname = other.lenSurname; 
		this->lenPatronymic = other.lenPatronymic; 
		this->lenAge = other.lenAge; 
		this->lenGender = other.lenGender;

		this->Name			= new char[other.lenName];
		this->Surname		= new char[other.lenSurname];
		this->Patronymic	= new char[other.lenPatronymic];
		this->Age			= new char[other.lenAge];
		this->Gender		= new char[other.lenGender];

		for (int i = 0; i < other.lenName; i++)
			this->Name[i] = other.Name[i];

		this->Name[other.lenName] = '\0';


		for (int i = 0; i < other.lenSurname; i++)
			this->Surname[i] = other.Surname[i];

		this->Surname[other.lenSurname] = '\0';


		for (int i = 0; i < other.lenPatronymic; i++)
			this->Patronymic[i] = other.Patronymic[i];

		this->Patronymic[other.lenPatronymic] = '\0';


		for (int i = 0; i < other.lenAge; i++)
			this->Age[i] = other.Age[i];

		this->Age[other.lenAge] = '\0';


		for (int i = 0; i < other.lenGender; i++)
			this->Gender[i] = other.Gender[i];

		this->Gender[other.lenGender] = '\0';
	}

	~Human()
	{
		cout << "\n\tdestruct\n\t";
		delete Name;
		delete Surname;
		delete Patronymic;
		delete Age;
		delete Gender;
	}

	void Show()
	{
		cout << "\n\tИмя: " << Name << "\n\tФамилия: " << Surname << "\n\tОтчество: "
			<< Patronymic << "\n\tВозвраст: " << Age << "\n\tПол: " << Gender<<"\n\t";
	}
};

void secondGeneralTask()
{
	Human *Human_1 = new Human();
	Human_1->Show();
	cout << endl;
	string Name;
	string Surname;
	string Patronymic;
	string Age;
	string Gender;

	cout << "\n\tВведите имя: ";
	cin>>Name;

	cout << "\n\tВведите фамилию: ";
	cin>>Surname;

	cout << "\n\tВведите отчество: ";
	cin>>Patronymic;

	cout << "\n\tВведите возвраст: ";	
	cin>>Age;

	cout << "\n\tВведите пол: ";
	cin >> Gender;

	Human*Human_2 = new Human(Name, Surname, Patronymic, Age, Gender);

	Human_2->Show();

	system("pause");

	return;
}