//#pragma once

#include "Libraries.h"

#include "Journal.h"

void Journal::newJournal(Journal*& Journals, Journal *&headJournals, Journal *&tailJournals)
{
	if (Journals == NULL && headJournals == NULL && tailJournals == NULL)
	{
		Journals = new Journal();
		headJournals = Journals;
		tailJournals = Journals;
	}
	else
	{
		Journals = tailJournals;
		Journals->next = new Journal();
		Journals->next->prev = Journals;
		Journals = Journals->next;
		tailJournals = Journals;
	}
}

void Journal::getJournal(Journal*& Journals, Journal*& headJournals, Journal*& tailJournals)
{
	if (Journals == NULL && headJournals == NULL && tailJournals == NULL)
	{
		cout << "\n\tНечего выводить... ";
		return;
	}

	Journals = headJournals;

	int counter = 0;

	while (true)
	{
		counter++;
		cout << "\n\t" << counter << " Журнал:";

		Journals->getPrintPublication();

		if (s_number != "None")			cout << "\tНомер: " << Journals->s_number;
		if (i_number != 0)				cout << "\tНомер: " << Journals->i_number;

		if (s_month != "None")			cout << "\tМесяц: " << Journals->s_month;
		if (i_month != 0)				cout << "\tМесяц: " << Journals->i_month;

		if (Journals->next == NULL) break;
		Journals = Journals->next;
	}
}

void Journal::setNumber_s(string s_number)
{
	this->s_number = s_number;
}

void Journal::setNumber_i(int	i_number)
{
	this->i_number = i_number;
}


void Journal::setMonth_s(string s_month)
{
	this->s_month = s_month;
}

void Journal::setMonth_i(int	i_month)
{
	this->i_month = i_month;
}
