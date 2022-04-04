//#pragma once

#include "Libraries.h"

#include "TextBook.h"

void TextBook::newTextBooks(TextBook*& TextBooks, TextBook*& headTextBooks, TextBook*& tailTextBooks)
{
	if (TextBooks == NULL && headTextBooks == NULL && tailTextBooks == NULL)
	{
		TextBooks = new TextBook();
		headTextBooks = TextBooks;
		tailTextBooks = TextBooks;
	}
	else
	{
		TextBooks = tailTextBooks;
		TextBooks->next = new TextBook();
		TextBooks->next->prev = TextBooks;
		TextBooks = TextBooks->next;
		tailTextBooks = TextBooks;
	}
}

void TextBook::getTextBook(TextBook*& TextBooks, TextBook*& headTextBooks, TextBook*& tailTextBooks)
{
	if (TextBooks == NULL && headTextBooks == NULL && tailTextBooks == NULL)
	{
		cout << "\n\tНечего выводить... ";
		return;
	}

	TextBooks = headTextBooks;

	int counter = 0;

	while (true)
	{
		counter++;
		cout << "\n\t" << counter << " Журнал:";

		TextBooks->getPrintPublication();

		if (s_purpose != "None")	cout << "\tНазначение: " << this->s_purpose;
		if (i_purpose != 0)			cout << "\tНазначение: " << this->i_purpose;

		if (TextBooks->next == NULL) break;
		TextBooks = TextBooks->next;
	}
}

void TextBook::setPurpose_s(string s_purpose)
{
	this->s_purpose = s_purpose;
}

void TextBook::setPurpose_i(int i_purpose)
{
	this->i_purpose = i_purpose;
}
