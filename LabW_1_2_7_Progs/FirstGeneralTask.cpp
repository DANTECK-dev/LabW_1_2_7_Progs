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

	Mass* head_M	= NULL;
	Mass* current_M	= NULL;

	static bool first_ISM;
	bool first_M = true;

	IntSetMassive(int* val, int arr_size)
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

	~IntSetMassive()
	{
		delete next_ISM;
		delete prev_ISM;
		delete head_M;
		delete current_M;
	}

public:

	IntSetMassive(int val)
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

	bool currentNext(IntSetMassive*& current_ISM)
	{
		if (current_ISM->next_ISM == NULL)
			return false;
		else
		{
			current_ISM = current_ISM->next_ISM;
			return true;
		}
	}

	bool currentPrev(IntSetMassive*& current_ISM)
	{
		if (current_ISM->prev_ISM == NULL)
			return false;
		else
		{
			current_ISM = current_ISM->prev_ISM;
			return true;
		}
	}

	void createMassive(IntSetMassive*& current_ISM, int* val, int arr_size)
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

	void getMassive(IntSetMassive *&current_ISM, IntSetMassive *&head_ISM, IntSetMassive *&tail_ISM)
	{
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
	
	void operator+(const int value)
	{
		Mass * pTemp = this->head_M;
		if (pTemp == nullptr) {
			this -> head_M = new Mass(value);
		}
		else {
			while (pTemp->next_M != nullptr) {

				pTemp = pTemp->next_M;
			}
			pTemp->next_M = new Mass(value);
		}
		/*while (true)
		{
			if (this->current_M->next_M == NULL) break;
			this->current_M = this->current_M->next_M;
		}

		this->current_M->next_M = new Mass(value);
		this->current_M = this->current_M->next_M;*/
	}

	/*//friend const IntSetMassive& operator+(IntSetMassive& object, int value);

	//friend const void operator + (IntSetMassive& odject_1, const IntSetMassive& odject_2);
	//{
		//объединение множеств (типа object1 + object2), возвращает копию множества,
		//которое является объединением двух множеств - операндов;

	

	//}

	friend const void operator-(IntSetMassive& odject, int value)
	{
		//удалить число из множества (типа object - item, где item – целое число)



	}

	friend const void operator-(IntSetMassive& odject_1, IntSetMassive& odject_2) 
	{
		//пересечение множеств (типа object1 - object2);



	}

	friend const int operator[](IntSetMassive& odject, int value)
	{
		//возвращает элемент по номеру;



	}

	void operator int() (IntSetMassive*& odject) const
	{
		//int () – приведение к целому, возвращает мощность множества (размер массива).



	}*/
};

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
		char j;
		cin >> j;
		system("cls");
		int Jin = isInteger(j);

		switch ((Massive_Menu)Jin)
		{
		case Massive_Menu::Exit: return;

		case Massive_Menu::AddMass:
		{
			if (current == NULL && head == NULL && tail == NULL)
			{
				cout << "\n\tДобавление нового множества\n\tВведите размер множества: ";
				int* arr, arr_size;
				cin >> arr_size;
				arr = new int[arr_size];

				for (int i = 0; i < arr_size; i++)
					cin >> arr[i];
				if (first == true)
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
			}
			break;
		}

		case Massive_Menu::AddItem:
		{
			current->getMassive(current, head, tail);

			cout << "\n\tВведите номер номер множества: ";
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
			{
				if (!current->currentNext(current)) break;
			}

			current->operator+(K);
			current->getMassive(current, head, tail);
			break;
		}

		case Massive_Menu::Combine:
		{

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