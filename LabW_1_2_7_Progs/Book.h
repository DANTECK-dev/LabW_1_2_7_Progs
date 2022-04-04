#pragma once

#include "Libraries.h"

#include "PrintPublication.h"

class Book : public PrintPublication
{

private:

	Book* next = NULL;
	Book* prev = NULL;
	
protected:

	string s_subject; int i_subject; 				//тематика

	string s_author; int i_author; 					//автор

	string s_numberOfPages; int i_numberOfPages; 	//количество страниц		

public:
	
	Book()
	{
		s_subject			= { "None" };
		s_author			= { "None" };
		s_numberOfPages		= { "None" };

		i_subject			= 0;
		i_author			= 0;
		i_numberOfPages		= 0;
	}

	~Book()
	{
		delete next;
		delete prev;
	}

	void getBook			(Book*& Books, Book*& headBooks, Book*& tailBooks);

	void newBook			(Book*& Books, Book*& headBooks, Book*& tailBooks);

	void setSubject_s		(string s_subject);
	void setSubject_i		(int	i_subject);

	void setAuthor_s		(string s_author);
	void setAuthor_i		(int	i_author);

	void setNumberOfPages_s	(string s_numberOfPages);
	void setNumberOfPages_i	(int	i_numberOfPages);

};