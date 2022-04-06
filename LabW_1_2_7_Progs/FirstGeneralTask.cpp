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

	IntSetMassive* next = NULL;
	IntSetMassive* next = NULL;

	class Mass
	{

	private:

		Mass* next = NULL;
		int data;

	public:
		Mass()
		{

		}

		Mass(int val)
		{

			this->data = val;
			next = new Mass();
		}
	}Arr;

	Mass* head = NULL;

public:

	IntSetMassive()
	{
		Arr(0);
	}

	IntSetMassive(int *val)
	{
		int size_arr = sizeof(val) / sizeof(val[0]);
		
	}


	~IntSetMassive()
	{

	}
};

void firstGeneralTask()
{


}