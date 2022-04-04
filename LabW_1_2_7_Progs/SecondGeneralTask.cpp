#include "SecondGeneralTask.h"

#include "Libraries.h"

#include "PrintPublication.h"
#include "Journal.h"
#include "Book.h"
#include "TextBook.h"

enum class secondGeneralTaskMenu
{
	Exit,
	AddJournal,
	AddBook,
	AddTextBook,
	GetJournal,
	GetBook,
	GetTextBook,
	GetAll
};

enum class createMenu
{
	Exit,
	Integer,
	String
};

int PrintPublication::counter = 0;

void secondGeneralTask()
{
	Journal*	Journals		= NULL;
	Journal*	headJournals	= NULL;
	Journal*	tailJournals	= NULL;

	Book*		Books			= NULL;
	Book*		headBooks		= NULL;
	Book*		tailBooks		= NULL;

	TextBook*	TextBooks		= NULL;
	TextBook*	headTextBooks	= NULL;
	TextBook*	tailTextBooks	= NULL;

	while (true)
	{
		system("cls");
		cout << "\n\t1 - Добавить журнал\n\t2 - Добавить книгу\n\t3 - Добавить учебник\n\t4 - Вывод всех журналов";
		cout << "\n\t5 - Вывод всех книг\n\t6 - Вывод всех учебников\n\t7 - Вывод всех печатных изданий\n\t0 - Выход\n\t";
		char kIn;
		cin >> kIn;

		int inputInt = isInteger(kIn);

		system("cls");
		switch ((secondGeneralTaskMenu)inputInt)
		{
			case secondGeneralTaskMenu::Exit: return;

			case secondGeneralTaskMenu::AddJournal:
			{
				string	s_publisher, s_year, s_title, s_number, s_month;
				int		i_publisher, i_year, i_title, i_number, i_month;

				Journals->newJournal(Journals, headJournals, tailJournals);

				#pragma region set_publisher

				system("cls");
				cout << "\n\tТип данных \"Издательтво\":\n\t1 - Целочисленный\n\t2 - Строковый\n\t0 - Выход\n\t";
				char kk;
				cin >> kk;

				int k = isInteger(kk);
				cin.get();
				system("cls");
				switch ((createMenu)k)
				{
					case createMenu::Exit: break;

					case createMenu::Integer:
					{
						cout << "\n\tВведите издательство: ";
						cin >> i_publisher;
						Journals->setPublisher_i(i_publisher);
						break;
					}
					case createMenu::String:
					{
						cout << "\n\tВведите издательство: ";
						getline(cin, s_publisher);
						Journals->setPublisher_s(s_publisher);
						break;
					}
					default: 
					{
						cout << "\n\tВведено неверное значение... ";
						char p = _getch();
						break;
					}
				}
				
				#pragma endregion

				#pragma region set_year
				
				system("cls");
				cout << "\n\tТип данных \"Год\":\n\t1 - Целочисленный\n\t2 - Строковый\n\t0 - Выход\n\t";
				cin >> kk;

				k = isInteger(kk);
				cin.get();
				system("cls");
				switch ((createMenu)k)
				{
					case createMenu::Exit: break;

					case createMenu::Integer:
					{
						cout << "\n\tВведите год: ";
						cin >> i_year;
						Journals->setYear_i(i_year);
						break;
					}
					case createMenu::String:
					{
						cout << "\n\tВведите год: ";
						getline(cin, s_year);
						Journals->setYear_s(s_year);
						break;
					}
					default:
					{
						cout << "\n\tВведено неверное значение... ";
						char p = _getch();
						break;
					}
				}

				#pragma endregion

				#pragma region set_title

				system("cls");
				cout << "\n\tТип данных \"Название\":\n\t1 - Целочисленный\n\t2 - Строковый\n\t0 - Выход\n\t";
				cin >> kk;

				k = isInteger(kk);
				cin.get();
				system("cls");
				switch ((createMenu)k)
				{
					case createMenu::Exit: break;

					case createMenu::Integer:
					{
						cout << "\n\tВведите название: ";
						cin >> i_title;
						Journals->setTitle_i(i_title);
						break;
					}
					case createMenu::String:
					{
						cout << "\n\tВведите название: ";
						getline(cin, s_title);
						Journals->setTitle_s(s_title);
						break;
					}
					default:
					{
						cout << "\n\tВведено неверное значение... ";
						char p = _getch();
						break;
					}
				}

				#pragma endregion

				#pragma region set_number

				system("cls");
				cout << "\n\tТип данных \"Номер\":\n\t1 - Целочисленный\n\t2 - Строковый\n\t0 - Выход\n\t";
				cin >> kk;

				k = isInteger(kk);
				cin.get();
				system("cls");
				switch ((createMenu)k)
				{
					case createMenu::Exit: break;

					case createMenu::Integer:
					{
						cout << "\n\tВведите номер: ";
						cin >> i_number;
						Journals->setNumber_i(i_number);
						break;
					}
					case createMenu::String:
					{
						cout << "\n\tВведите номер: ";
						getline(cin, s_number);
						Journals->setNumber_s(s_number);
						break;
					}
					default:
					{
						cout << "\n\tВведено неверное значение... ";
						char p = _getch();
						break;
					}
				}

				#pragma endregion

				#pragma region set_month

				system("cls");
				cout << "\n\tТип данных \"Месяц\":\n\t1 - Целочисленный\n\t2 - Строковый\n\t0 - Выход\n\t";
				cin >> kk;

				k = isInteger(kk);
				cin.get();
				system("cls");
				switch ((createMenu)k)
				{
					case createMenu::Exit: break;

					case createMenu::Integer:
					{
						cout << "\n\tВведите месяц: ";
						cin >> i_month;
						Journals->setMonth_i(i_month);
						break;
					}
					case createMenu::String:
					{
						cout << "\n\tВведите месяц: ";
						getline(cin, s_month);
						Journals->setMonth_s(s_month);
						break;
					}
					default:
					{
						cout << "\n\tВведено неверное значение... ";
						char p = _getch();
						break;
					}
				}

				#pragma endregion	
				break;
			}

			case secondGeneralTaskMenu::AddBook:
			{
				string	s_publisher, s_year, s_title, s_subject, s_author, s_numberOfPages;
				int		i_publisher, i_year, i_title, i_subject, i_author, i_numberOfPages;

				Books->newBook(Books, headBooks, tailBooks);

				#pragma region set_publisher

				system("cls");
				cout << "\n\tТип данных \"Издательтво\":\n\t1 - Целочисленный\n\t2 - Строковый\n\t0 - Выход\n\t";
				char kk;
				cin >> kk;

				int k = isInteger(kk);
				cin.get();
				system("cls");
				switch ((createMenu)k)
				{
				case createMenu::Exit: break;

				case createMenu::Integer:
				{
					cout << "\n\tВведите издательство: ";
					cin >> i_publisher;
					Books->setPublisher_i(i_publisher);
					break;
				}
				case createMenu::String:
				{
					cout << "\n\tВведите издательство: ";
					getline(cin, s_publisher);
					Books->setPublisher_s(s_publisher);
					break;
				}
				default:
				{
					cout << "\n\tВведено неверное значение... ";
					char p = _getch();
					break;
				}
				}

				#pragma endregion
				
				#pragma region set_year

				system("cls");
				cout << "\n\tТип данных \"Год\":\n\t1 - Целочисленный\n\t2 - Строковый\n\t0 - Выход\n\t";
				cin >> kk;

				k = isInteger(kk);
				cin.get();
				system("cls");
				switch ((createMenu)k)
				{
				case createMenu::Exit: break;

				case createMenu::Integer:
				{
					cout << "\n\tВведите год: ";
					cin >> i_year;
					Books->setYear_i(i_year);
					break;
				}
				case createMenu::String:
				{
					cout << "\n\tВведите год: ";
					getline(cin, s_year);
					Books->setYear_s(s_year);
					break;
				}
				default:
				{
					cout << "\n\tВведено неверное значение... ";
					char p = _getch();
					break;
				}
				}

				#pragma endregion
				
				#pragma region set_title

				system("cls");
				cout << "\n\tТип данных \"Название\":\n\t1 - Целочисленный\n\t2 - Строковый\n\t0 - Выход\n\t";
				cin >> kk;

				k = isInteger(kk);
				cin.get();
				system("cls");
				switch ((createMenu)k)
				{
				case createMenu::Exit: break;

				case createMenu::Integer:
				{
					cout << "\n\tВведите название: ";
					cin >> i_title;
					Books->setTitle_i(i_title);
					break;
				}
				case createMenu::String:
				{
					cout << "\n\tВведите название: ";
					getline(cin, s_title);
					Books->setTitle_s(s_title);
					break;
				}
				default:
				{
					cout << "\n\tВведено неверное значение... ";
					char p = _getch();
					break;
				}
				}

				#pragma endregion

				#pragma region set_subject

				system("cls");
				cout << "\n\tТип данных \"Тематика\":\n\t1 - Целочисленный\n\t2 - Строковый\n\t0 - Выход\n\t";
				cin >> kk;

				k = isInteger(kk);
				cin.get();
				system("cls");
				switch ((createMenu)k)
				{
				case createMenu::Exit: break;

				case createMenu::Integer:
				{
					cout << "\n\tВведите тематику: ";
					cin >> i_subject;
					Books->setSubject_i(i_subject);
					break;
				}
				case createMenu::String:
				{
					cout << "\n\tВведите тематику: ";
					getline(cin, s_subject);
					Books->setSubject_s(s_subject);
					break;
				}
				default:
				{
					cout << "\n\tВведено неверное значение... ";
					char p = _getch();
					break;
				}
				}

				#pragma endregion

				#pragma region set_author

				system("cls");
				cout << "\n\tТип данных \"Автор\":\n\t1 - Целочисленный\n\t2 - Строковый\n\t0 - Выход\n\t";
				cin >> kk;

				k = isInteger(kk);
				cin.get();
				system("cls");
				switch ((createMenu)k)
				{
				case createMenu::Exit: break;

				case createMenu::Integer:
				{
					cout << "\n\tВведите автора: ";
					cin >> i_author;
					Books->setAuthor_i(i_author);
					break;
				}
				case createMenu::String:
				{
					cout << "\n\tВведите автора: ";
					getline(cin, s_author);
					Books->setAuthor_s(s_author);
					break;
				}
				default:
				{
					cout << "\n\tВведено неверное значение... ";
					char p = _getch();
					break;
				}
				}

				#pragma endregion

				#pragma region set_numberOfPages

				system("cls");
				cout << "\n\tТип данных \"Количество страниц\":\n\t1 - Целочисленный\n\t2 - Строковый\n\t0 - Выход\n\t";
				cin >> kk;

				k = isInteger(kk);
				cin.get();
				system("cls");
				switch ((createMenu)k)
				{
				case createMenu::Exit: break;

				case createMenu::Integer:
				{
					cout << "\n\tВведите количество страниц: ";
					cin >> i_numberOfPages;
					Books->setNumberOfPages_i(i_numberOfPages);
					break;
				}
				case createMenu::String:
				{
					cout << "\n\tВведите количество страниц: ";
					getline(cin, s_numberOfPages);
					Books->setNumberOfPages_s(s_numberOfPages);
					break;
				}
				default:
				{
					cout << "\n\tВведено неверное значение... ";
					char p = _getch();
					break;
				}
				}

				#pragma endregion
				break;
			}

			case secondGeneralTaskMenu::AddTextBook:
			{
				string	s_publisher, s_year, s_title, s_subject, s_author, s_numberOfPages, s_purpose;
				int		i_publisher, i_year, i_title, i_subject, i_author, i_numberOfPages, i_purpose;

				TextBooks->newTextBooks(TextBooks, headTextBooks, tailTextBooks);

				#pragma region set_publisher

				system("cls");
				cout << "\n\tТип данных \"Издательтво\":\n\t1 - Целочисленный\n\t2 - Строковый\n\t0 - Выход\n\t";
				char kk;
				cin >> kk;

				int k = isInteger(kk);
				cin.get();
				system("cls");
				switch ((createMenu)k)
				{
				case createMenu::Exit: break;

				case createMenu::Integer:
				{
					cout << "\n\tВведите издательство: ";
					cin >> i_publisher;
					TextBooks->setPublisher_i(i_publisher);
					break;
				}
				case createMenu::String:
				{
					cout << "\n\tВведите издательство: ";
					getline(cin, s_publisher);
					TextBooks->setPublisher_s(s_publisher);
					break;
				}
				default:
				{
					cout << "\n\tВведено неверное значение... ";
					char p = _getch();
					break;
				}
				}

				#pragma endregion
				
				#pragma region set_year

				system("cls");
				cout << "\n\tТип данных \"Год\":\n\t1 - Целочисленный\n\t2 - Строковый\n\t0 - Выход\n\t";
				cin >> kk;

				k = isInteger(kk);
				cin.get();
				system("cls");
				switch ((createMenu)k)
				{
				case createMenu::Exit: break;

				case createMenu::Integer:
				{
					cout << "\n\tВведите год: ";
					cin >> i_year;
					TextBooks->setYear_i(i_year);
					break;
				}
				case createMenu::String:
				{
					cout << "\n\tВведите год: ";
					getline(cin, s_year);
					TextBooks->setYear_s(s_year);
					break;
				}
				default:
				{
					cout << "\n\tВведено неверное значение... ";
					char p = _getch();
					break;
				}
				}

				#pragma endregion
				
				#pragma region set_title

				system("cls");
				cout << "\n\tТип данных \"Название\":\n\t1 - Целочисленный\n\t2 - Строковый\n\t0 - Выход\n\t";
				cin >> kk;

				k = isInteger(kk);
				cin.get();
				system("cls");
				switch ((createMenu)k)
				{
				case createMenu::Exit: break;

				case createMenu::Integer:
				{
					cout << "\n\tВведите название: ";
					cin >> i_title;
					TextBooks->setTitle_i(i_title);
					break;
				}
				case createMenu::String:
				{
					cout << "\n\tВведите название: ";
					getline(cin, s_title);
					TextBooks->setTitle_s(s_title);
					break;
				}
				default:
				{
					cout << "\n\tВведено неверное значение... ";
					char p = _getch();
					break;
				}
				}

				#pragma endregion

				#pragma region set_subject

				system("cls");
				cout << "\n\tТип данных \"Тематика\":\n\t1 - Целочисленный\n\t2 - Строковый\n\t0 - Выход\n\t";
				cin >> kk;

				k = isInteger(kk);
				cin.get();
				system("cls");
				switch ((createMenu)k)
				{
				case createMenu::Exit: break;

				case createMenu::Integer:
				{
					cout << "\n\tВведите тематику: ";
					cin >> i_subject;
					TextBooks->setSubject_i(i_subject);
					break;
				}
				case createMenu::String:
				{
					cout << "\n\tВведите тематику: ";
					getline(cin, s_subject);
					TextBooks->setSubject_s(s_subject);
					break;
				}
				default:
				{
					cout << "\n\tВведено неверное значение... ";
					char p = _getch();
					break;
				}
				}

				#pragma endregion

				#pragma region set_author

				system("cls");
				cout << "\n\tТип данных \"Автор\":\n\t1 - Целочисленный\n\t2 - Строковый\n\t0 - Выход\n\t";
				cin >> kk;

				k = isInteger(kk);
				cin.get();
				system("cls");
				switch ((createMenu)k)
				{
				case createMenu::Exit: break;

				case createMenu::Integer:
				{
					cout << "\n\tВведите автора: ";
					cin >> i_author;
					TextBooks->setAuthor_i(i_author);
					break;
				}
				case createMenu::String:
				{
					cout << "\n\tВведите автора: ";
					getline(cin, s_author);
					TextBooks->setAuthor_s(s_author);
					break;
				}
				default:
				{
					cout << "\n\tВведено неверное значение... ";
					char p = _getch();
					break;
				}
				}

				#pragma endregion

				#pragma region set_numberOfPages

				system("cls");
				cout << "\n\tТип данных \"Количество страниц\":\n\t1 - Целочисленный\n\t2 - Строковый\n\t0 - Выход\n\t";
				cin >> kk;

				k = isInteger(kk);
				cin.get();
				system("cls");
				switch ((createMenu)k)
				{
				case createMenu::Exit: break;

				case createMenu::Integer:
				{
					cout << "\n\tВведите количество страниц: ";
					cin >> i_numberOfPages;
					TextBooks->setNumberOfPages_i(i_numberOfPages);
					break;
				}
				case createMenu::String:
				{
					cout << "\n\tВведите количество страниц: ";
					getline(cin, s_numberOfPages);
					TextBooks->setNumberOfPages_s(s_numberOfPages);
					break;
				}
				default:
				{
					cout << "\n\tВведено неверное значение... ";
					char p = _getch();
					break;
				}
				}

				#pragma endregion

				#pragma region set_numberOfPages

				system("cls");
				cout << "\n\tТип данных \"Назначение\":\n\t1 - Целочисленный\n\t2 - Строковый\n\t0 - Выход\n\t";
				cin >> kk;

				k = isInteger(kk);
				cin.get();
				system("cls");
				switch ((createMenu)k)
				{
				case createMenu::Exit: break;

				case createMenu::Integer:
				{
					cout << "\n\tВведите назначение: ";
					cin >> i_purpose;
					TextBooks->setPurpose_i(i_purpose);
					break;
				}
				case createMenu::String:
				{
					cout << "\n\tВведите назначение: ";
					getline(cin, s_purpose);
					TextBooks->setPurpose_s(s_purpose);
					break;
				}
				default:
				{
					cout << "\n\tВведено неверное значение... ";
					char p = _getch();
					break;
				}
				}

				#pragma endregion
				break;
			}

			case secondGeneralTaskMenu::GetJournal:
			{
				Journals->getJournal(Journals, headJournals, tailJournals);
				cout << "\n\t";
				char p = _getch();
				system("cls");
				break;
			}

			case secondGeneralTaskMenu::GetBook:
			{
				Books->getBook(Books, headBooks, tailBooks);
				cout << "\n\t";
				char p = _getch();
				system("cls");
				break;
			}

			case secondGeneralTaskMenu::GetTextBook:
			{
				TextBooks->getTextBook(TextBooks, headTextBooks, tailTextBooks);
				cout << "\n\t";
				char p = _getch();
				system("cls");
				break;
			}

			case secondGeneralTaskMenu::GetAll:
			{
				cout << "\n\n\t\tЖурналы: ";
				Journals->getJournal(Journals, headJournals, tailJournals);

				cout << "\n\n\t\tКниги: ";
				Books->getBook(Books, headBooks, tailBooks);

				cout << "\n\n\t\tУчебники: ";
				TextBooks->getTextBook(TextBooks, headTextBooks, tailTextBooks);

				cout << "\n\n\n\tВсего печатных изделий: " << PrintPublication::getConter() << "\n\n\t\t";
				char p = _getch();
				break;
			}

			default:
			{
				cout << "\n\tНеверное значение... ";
				char p = _getch();
				system("cls");
				break;
			}
		}
	}

}