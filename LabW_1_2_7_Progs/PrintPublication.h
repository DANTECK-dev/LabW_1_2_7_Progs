#pragma once

#include "Libraries.h"

class PrintPublication
{

protected:

	string s_publisher; int i_publisher; 	//издательство

	string s_year; int i_year;				//год

	string s_title; int i_title; 			//название	

private:		

	static int counter;						//кол-во классов

public:

	PrintPublication()
	{
		s_publisher			= { "None" };
		s_year				= { "None" };
		s_title				= { "None" };

		i_publisher			= 0;
		i_year				= 0;
		i_title				= 0;
		counter++;
	}

	~PrintPublication()
	{
		counter--;
	}

	static int getConter	();

	void getPrintPublication();

	void setPublisher_s		(string s_publisher);
	void setPublisher_i		(int	i_publisher);

	void setYear_s			(string s_year);
	void setYear_i			(int	i_year);

	void setTitle_s			(string s_title);
	void setTitle_i			(int	i_title);
};