#pragma once

#include "Libraries.h"

#include "Book.h"

class TextBook : public Book
{
private:

	TextBook* next = NULL;
	TextBook* prev = NULL;

protected:

	string s_purpose; int i_purpose;		//назначение

public:

	TextBook()
	{
		s_purpose			= { "None" };

		i_purpose			= 0;
	}

	~TextBook()
	{
		delete next;
		delete prev;
	}

	void getTextBook	(TextBook*& TextBooks, TextBook*& headTextBooks, TextBook*& tailTextBooks);

	void newTextBooks	(TextBook*& TextBooks, TextBook*& headTextBooks, TextBook*& tailTextBooks);

	void setPurpose_s	(string s_purpose); 
	void setPurpose_i	(int i_purpose);
};