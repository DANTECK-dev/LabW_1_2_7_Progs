#include "FirstGeneralTask.h"
#include "ThisIs.h"
#include <iostream>
#include <conio.h>

using namespace std;

enum class Massive_Menu
{
	Exit,
	Area,
	Perimeter,
	Set,
	Get
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

	bool first_ISM = true;
	bool first_M = true;

	
	/*IntSetMassive()
	{
		if (first_ISM == true)
		{
			first_ISM = false;
		}

		else
		{
			this->next_ISM = new IntSetMassive;
			this == this->next_ISM;
			this->first_ISM = false;
		}

		if (first_M == true)
		{
			current_M = new Mass;
			head_M = current_M;
			first_M = false;
		}

		else
		{
			current_M->next_M = new Mass;
			current_M = current_M->next_M;
		}
		
	current_M->data = 0;
}*/

	/*IntSetMassive(int val)
	{
		if (first_ISM == true)
		{
			first_ISM = false;
		}

		else
		{
			this->next_ISM = new IntSetMassive();
			this == this->next_ISM;
			this->first_ISM = false;
		}

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

		current_M->data = val;
	}*/

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

			current_M = head_M;

			while (true)
			{
				cout << current_M->data;

				if (current_M->next_M == NULL) break;

				cout << ", ";

				current_M = current_M->next_M;
			}

			cout << " }";

			if (current_ISM->next_ISM == NULL) break;
			current_ISM = current_ISM->next_ISM;
		}
	}
};

void firstGeneralTask()
{

	IntSetMassive* head		= NULL;
	IntSetMassive* tail		= NULL;
	IntSetMassive* current	= NULL;

	int arr[5] = { 1,2,3,4,5 };
	int arrr[4] = { 1,2,3,4 };
	int ar[3] = { 1,2,3 };

	current->createMassive(current, arr, 5);
	head = current;
	
	current->createMassive(current, arr, 5);

	current->createMassive(current, arrr, 4);

	current->createMassive(current, ar, 3);

	tail = current;
	current->getMassive(current, head, tail);

	char p = _getch();
	system("cls");
}


/*		Mass()
		{
			data = 0;
		}

		Mass(int val)
		{
			this->data = val;
		}

		Mass(int *val)
		{
			int size_arr = sizeof(val) / sizeof(val[0]);

			bool first = true;

			for (int i = 0; i < size_arr; i++)
			{
				if (headMass == NULL && currentMass == NULL)
				{
					currentMass = new Mass(val[i]);
					headMass = currentMass;
					first = false;
				}

				else
				{
					currentMass->next = new Mass(val[i]);
					currentMass = currentMass->next;
				}
			}
		}*/