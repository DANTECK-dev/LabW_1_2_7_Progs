#include "FirstGeneralTask.h"
#include "ThisIs.h"
#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

enum class Massive_Menu
{
	Exit,
	AddMass,
	AddItem,
	Combine,
	Remove,
	Intersection,
	Return,
	Size
};

class IntSetMassive
{

public:

	IntSetMassive(int* val, int arr_size);
	~IntSetMassive();
	IntSetMassive(int val);
	bool currentNext(IntSetMassive*& current_ISM);
	bool currentPrev(IntSetMassive*& current_ISM);
	void createMassive(IntSetMassive*& current_ISM, int* val, int arr_size);
	void getMassive(IntSetMassive*& current_ISM, IntSetMassive*& head_ISM, IntSetMassive*& tail_ISM);
	void operator+(const int value);
	void operator+(const IntSetMassive& object);
	void operator-(const int value);
	void operator-(const IntSetMassive& object);
	int& operator[](const int index);
	int sizeMass(const IntSetMassive*& object);

private:

	IntSetMassive* next_ISM = NULL;
	IntSetMassive* prev_ISM = NULL;

	struct Mass
	{
		Mass* next_M = NULL;
		int data = 0;

		Mass(int val) { data = val; }
		~Mass() { delete next_M; }
	};

	Mass* head_M = NULL;
	Mass* current_M = NULL;

	static bool first_ISM;
	bool first_M = true;
};

IntSetMassive::IntSetMassive(int val)
{
	if (first_M == true)
	{
		current_M = new Mass(val);
		head_M = current_M;
		first_M = false;
	}

	else
	{
		current_M->next_M = new Mass(val);
		current_M = current_M->next_M;
	}
}

IntSetMassive::IntSetMassive(int* val, int arr_size)
{
	/*int* temp = NULL;

	for (int i = 0; i < arr_size; i++)
	{
		for (int j = (i + 1); j < arr_size; i++)
		{
			if (val[i] == val[j])
			{
				arr_size--;
				temp = new int[arr_size];

				for (int k = 0; k < arr_size; k++)
				{
					if (val[k] == val[i]) continue;
					temp[k] = val[k];
				}

				for (int k = 0; k < arr_size; k++)
					val[k] = temp[k];
			}
		}
	}
	*/
	for (int i = 0; i < arr_size; i++)
	{
		if (first_M == true)
		{
			current_M = new Mass(val[i]);
			head_M = current_M;
			first_M = false;
		}

		else
		{
			current_M->next_M = new Mass(val[i]);
			current_M = current_M->next_M;
		}

		//current_M->data = val[i];
	}
}

IntSetMassive::~IntSetMassive()
{
	delete next_ISM;
	delete prev_ISM;
	delete head_M;
	delete current_M;
}

bool IntSetMassive::currentNext(IntSetMassive*& current_ISM)
{
	if (current_ISM->next_ISM == NULL)
		return false;
	else
	{
		current_ISM = current_ISM->next_ISM;
		return true;
	}
}

bool IntSetMassive::currentPrev(IntSetMassive*& current_ISM)
{
	if (current_ISM->prev_ISM == NULL)
		return false;
	else
	{
		current_ISM = current_ISM->prev_ISM;
		return true;
	}
}

void IntSetMassive::createMassive(IntSetMassive*& current_ISM, int* val, int arr_size)
{
	if (first_ISM == true)
	{
		first_ISM = false;
		current_ISM = new IntSetMassive(val, arr_size);
	}

	else
	{
		current_ISM->next_ISM = new IntSetMassive(val, arr_size);
		current_ISM = current_ISM->next_ISM;
		current_ISM->first_ISM = false;
	}
}

void IntSetMassive::getMassive(IntSetMassive *&current_ISM, IntSetMassive *&head_ISM, IntSetMassive *&tail_ISM)
{
	if (current_ISM == NULL && head_ISM == NULL && tail_ISM == NULL) { cout << "\n\tНечего выводить\n\t"; return; }

	current_ISM = head_ISM;
	int counter = 0;

	while (true)
	{
		counter++;
		cout << "\n\t" << counter << " множество = { ";

		current_ISM->current_M = current_ISM->head_M;

		while (true)
		{
			cout << current_ISM->current_M->data;

			if (current_ISM->current_M->next_M == NULL) break;

			cout << ", ";

			current_ISM->current_M = current_ISM->current_M->next_M;
		}

		cout << " }";

		if (current_ISM->next_ISM == NULL) break;
		current_ISM = current_ISM->next_ISM;
	}

}
	
void IntSetMassive::operator+(const int value)
{
	Mass* TempMass = this->head_M;
	/*if (pTemp == nullptr) {
		this -> head_M = new Mass(value);
	}
	else {
		while (pTemp->next_M != nullptr) {

			pTemp = pTemp->next_M;
		}
		pTemp->next_M = new Mass(value);
	}*/

	if (TempMass == NULL) cout << "\n\tЭтого множества не существует\n\t"; return;

	while (true)
	{
		if (TempMass->next_M == NULL) break;
		TempMass = TempMass->next_M;
	}

	TempMass->next_M = new Mass(value);
	TempMass = TempMass->next_M;
}

void IntSetMassive::operator+(const IntSetMassive& object)
{
	//объединение множеств (типа object1 + object2), возвращает копию множества,
	//которое является объединением двух множеств - операндов;

	Mass *TempMass1 = this->head_M;
	Mass *TempMass2 = object.head_M;

	IntSetMassive* Last = NULL;
	
	int counter = 0;
	int* mass = new int [counter];


	while (true)
	{
		if (Last == NULL) Last = new IntSetMassive(TempMass1->data);
		else Last->current_M->next_M = new Mass(TempMass1->data);
		if (TempMass1->next_M == nullptr) break;
		TempMass1 = TempMass1->next_M;
	}

	while (true)
	{
		if (Last == NULL) Last = new IntSetMassive(TempMass2->data);
		else Last->current_M->next_M = new Mass(TempMass2->data);
		if (TempMass2->next_M == nullptr) break;
		TempMass2 = TempMass2->next_M;
	}


	/*if (this == NULL) { cout << "\n\t1 множества не существует\n\t"; return; }
	if (object.head_M == NULL && object.head_M == NULL) { cout << "\n\t2 множества не существует или оно пустое\n\t"; return; }*/

	/*while (TempMass1 != nullptr)
	{
		counter++;
		int *temp = new int[counter];
		for (int i = 0; i < counter-1; i++)
			temp[i] = mass[i];
		delete[] mass;
		mass = temp;
	}

	object.current_M = object.head_M;

	while (true)
	{
		if (Last == NULL) { Last = new IntSetMassive(object.current_M->data); }

		Last->current_M = new Mass(object.current_M->data);

		if (object.current_M->next_M == NULL)break;
		Last = Last->next_ISM;
		object.current_M = object.current_M->next_M;
	}

	while (true)
	{
		if (fTemp->next_ISM == NULL) break;
		fTemp = fTemp->next_ISM;
	}
	fTemp->next_ISM = Last;*/
}

void IntSetMassive::operator-(const int value)
{
	//удалить число из множества (типа object - item, где item – целое число)



}

void IntSetMassive::operator-(const IntSetMassive& object)
{
	//пересечение множеств (типа object1 - object2);



}

int& IntSetMassive::operator[](int value)
{
	//возвращает элемент по номеру;
	int value = 0;



	return value;
}

int IntSetMassive::sizeMass (const IntSetMassive*& object)
{
	//int () – приведение к целому, возвращает мощность множества (размер массива).



}


/*void IntSetMassive::operator+(const int value)
{
	while (true)
	{
		if (this->current_M->next_M == NULL) break;
		this->current_M = this->current_M->next_M;
	}

	this->current_M->next_M = new Mass(value);
	this->current_M = this->current_M->next_M;

	//return object;
}*/

bool IntSetMassive::first_ISM = true;

void firstGeneralTask()
{
	IntSetMassive* head		= NULL;
	IntSetMassive* tail		= NULL;
	IntSetMassive* current	= NULL;
	bool first = true;
	while (true)
	{
		cout << "\n\t1 - Добавить множество"
			 << "\n\t2 - Добавить во множество"
			 << "\n\t3 - Объединить множества"
			 << "\n\t4 - Удалить число из множества"
			 << "\n\t5 - Пересечение множеств"
			 << "\n\t6 - Возвращение эл-та по номеру"
			 << "\n\t7 - Мощность множества"
			 << "\n\t0 - Выход\n\t";
		if (first == true) cin.get();
		char j;
		cin >> j;
		//system("cls");
		int Jin = isInteger(j);

		switch ((Massive_Menu)Jin)
		{
			case Massive_Menu::Exit: return;

			case Massive_Menu::AddMass:
			{
				cout << "\n\tДобавление нового множества\n\tВведите размер множества: ";
				int* arr, arr_size;
				cin >> arr_size;
				arr = new int[arr_size];

				for (int i = 0; i < arr_size; i++)
					cin >> arr[i];
				if (first == true && current == NULL && head == NULL && tail == NULL)
				{
					current->createMassive(current, arr, arr_size);
					head = current;
					tail = current;
					first = false;
				}

				else
				{
					current->createMassive(current, arr, arr_size);
					tail = current;
				}

				break;
			}

			case Massive_Menu::AddItem:
			{
				current->getMassive(current, head, tail);
				if (first == true) break;

				cout << "\n\tВведите номер множества: ";
				char LL;
				cin >> LL;
				int L = isInteger(LL);
				L--;

				cin.get();
				cout << "\n\tВведите число: ";
				char KK[100];
				cin.getline(KK, 100);
				int K = isInteger_l(KK);

				current = head;

				for (int i = 0; i < L; i++)
					if (!current->currentNext(current)) break;

				current + K;
				current->getMassive(current, head, tail);
				break;
			}

			case Massive_Menu::Combine:
			{
				current->getMassive(current, head, tail);
				if (first == true) break;

				cout << "\n\tВведите номер множества: ";
				char LL;
				cin >> LL;
				int L = isInteger(LL);
				L--;

				cout << "\n\tВведите номер множества: ";
				char FF;
				cin >> FF;
				int F = isInteger(FF);
				F--;

				IntSetMassive* temp = head;

				current = head;

				for (int i = 0; i < L; i++)
					if (!current->currentNext(current)) break;

				for (int i = 0; i < F; i++)
					if (!temp->currentNext(temp)) break;

				current->operator+(*temp);
				current->getMassive(current, head, tail);
				break;
			}

			case Massive_Menu::Remove:
			{

				break;
			}

			case Massive_Menu::Intersection:
			{

				break;
			}

			case Massive_Menu::Return:
			{

				break;
			}

			case Massive_Menu::Size:
			{

				break;
			}

			default:
			{

				break;
			}
		}
	}
	system("cls");
}