#include "FirstGeneralTask.h"
#include "ThisIs.h"
#include <iostream>
#include <conio.h>

using namespace std;

enum class Deposit_Menu
{
	Exit,
	Create,
	Get
};

class Deposit
{

private:

	Deposit* next = NULL;
	Deposit* prev = NULL;

	double summ;
	static double rate;

public:

	Deposit(double summ)
	{
		this->summ = summ;
		this->rate = 1.01;
	}

	static void setRate(double rate)
	{
		Deposit::rate = rate;
	}

	/*	void getDeposit()
	{
		this->summ *= this->rate;
		cout << "\n\tСейчас на счёту: "<<this->summ;
		char p = _getch();
		system("cls");
	}*/

	void createDeposit(Deposit *&contribution, Deposit*& head, Deposit*& tail, double summ)
	{
		if ((contribution == NULL) && (head == NULL) && (tail == NULL))
		{
			contribution = new Deposit(summ);
			head = contribution;
			tail = contribution;
		}

		else
		{
			contribution = tail;
			contribution->next = new Deposit(summ);
			contribution->next->prev = contribution;
			contribution = contribution->next;
			tail = contribution;
		}
		system("cls");
	}

	friend void getAllDeposit(Deposit*& contribution, Deposit*& head, Deposit*& tail);
};

double Deposit::rate;

void getAllDeposit(Deposit*& contribution, Deposit*& head, Deposit*& tail)
{
	
	if ((contribution == NULL) && (head == NULL) && (tail == NULL))
	{
		cout << "\n\tВкладов нет";
		char p = _getch();
		system("cls");
		return;
	}

	contribution = head;
	int i = 1;
	while (true)
	{
		contribution->summ *= contribution->rate;
		cout << "\n\t" << i << " Вклад\t Сумма: " << contribution->summ << "\t Процентная ставка: " << contribution->rate*100<<"%";
		if (contribution->next == NULL) break;
		contribution = contribution->next;
		i++;
	}
	cout << "\n\t";
	char p = _getch();
	std::system("cls");
}

void firstGeneralTask()
{
	Deposit* contribution = NULL;
	Deposit* head = NULL;
	Deposit* tail = NULL;

	while (true)
	{
		cout << "\n\t1 - Создание нового вклада\n\t2 - Вывести все вклады\n\t0 - Выход\n\t";
		char Jinputt;
		cin >> Jinputt;
		int Jinput;

		try
		{
			Jinput = isInteger(Jinputt);
		}
		catch (const exception& err)
		{
			cout << "\n\t" << err.what() << "... ";
			char p = _getch();
			system("cls");
			continue;
		}

		switch ((Deposit_Menu)Jinput)
		{
			case Deposit_Menu::Exit: return;
			case Deposit_Menu::Create:
			{
				cout << "\n\tВведите сумму взноса: ";
				double summ;
				cin >> summ;
				
				contribution->createDeposit(contribution, head, tail, summ);
				
				break;
			}
			case Deposit_Menu::Get:
			{
				getAllDeposit(contribution, head, tail);
				break;
			}
			default:
			{
				throw exception("Неверное значение");
				break;
			}
		}
	}

}