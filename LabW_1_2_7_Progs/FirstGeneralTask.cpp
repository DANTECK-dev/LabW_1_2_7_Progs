#include "FirstGeneralTask.h"
#include "ThisIs.h"
#include <iostream>
#include <conio.h>

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
		~Mass() { delete next_M; }
	};

	Mass* head_M	= NULL;
	Mass* current_M	= NULL;

	static bool first_ISM;
	bool first_M = true;

	IntSetMassive(int* val, int arr_size)
	{
		for (int i = 0; i < arr_size; i++)
		{
			if (first_M == true)
			{
				current_M = new Mass();
				head_M = current_M;
				first_M = false;
			}

			else
			{
				current_M->next_M = new Mass();
				current_M = current_M->next_M;
			}

			current_M->data = val[i];
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
		static int counter = 0;

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
	
	void operator + () const
	{

	}
};

bool IntSetMassive::first_ISM = true;

void firstGeneralTask()
{
	IntSetMassive* head		= NULL;
	IntSetMassive* tail		= NULL;
	IntSetMassive* current	= NULL;

	cout << "\n\t1 - Добавить множество"
		 << "\n\t2 - Доваить во множество"
		 << "\n\t3 - Объединить множества"
		 << "\n\t4 - Удалить число из множества"
		 << "\n\t5 - Пересечение множеств"
		 << "\n\t6 - Возвращение эл-та по номеру"
		 << "\n\t7 - Мощность множества"
		 << "\n\t0 - Выход\n\t";
	char j;
	cin >> j;
	int Jin = isInteger(j);

	switch ((Massive_Menu)Jin)
	{
		case Massive_Menu::Exit: return;

		case Massive_Menu::AddMass:
		{

		}

		case Massive_Menu::AddItem:
		{

		}

		case Massive_Menu::Combine:
		{

		}

		case Massive_Menu::Remove:
		{

		}

		case Massive_Menu::Intersection:
		{

		}

		case Massive_Menu::Return:
		{

		}

		case Massive_Menu::Size:
		{

		}

		default:
		{

		}
	}
	char p = _getch();
	system("cls");
}