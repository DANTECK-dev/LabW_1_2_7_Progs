#include "SecondGeneralTask.h"
#include "ClassesForSecondGeneralTask.h"

#include "Libraries.h"


void inputGeneral(string &name, string &companyName, int &price, int &weight) {
	cout << "\n\n\t��������: ";
	cin >> name;
	cout << "\n\t�������� ��������: ";
	cin >> companyName;
	cout << "\n\t����: ";
	cin >> price;
	cout << "\n\t���: ";
	cin >> weight;
}

void secondGeneralTask()
{
	int counter = 0;
	const int size = 10;
	Product* products = new Product[size];
	//for (int i = 0; i < size; i++)
		//products[i] = new Product;
	while (true) {
		system("cls");
		string	productType					= { "None" };
		string	typeOfComponent				= { "None" };
		string	companyName					= { "None" };
		string	name						= { "None" };
		int		expirationDateInCloseState	= 0;
		int		expirationDateInOpenState	= 0;
		int		expirationDate				= 0;
		int		price						= 0;
		int		weight						= 0;
		bool	open						= false;
		cout << "\n\t1 - �������� ����� �������"
			<< "\n\t2 - ������� ��� ��������"
			<< "\n\t0 - �����\n\t";
		int inputNum;
		cin >> inputNum;
		system("cls");
		switch (inputNum) {
			case (0): return;
			case (1): {
				cout << "\n\t�������� �����"
					<< "\n\t1 - ������� �������"
					<< "\n\t2 - ����������� �����"
					<< "\n\t0 - �����\n\t";
				cin >> inputNum;
				system("cls");
				switch (inputNum) {
					case (0): return;
					case (1): {
						cout << "\n\t�������� ������� �������"
							<< "\n\t1 - ���������������� �������"
							<< "\n\t2 - ������ �������"
							<< "\n\t0 - �����";
						cin >> inputNum;
						system("cls");
						switch (inputNum) {
							case (0): return;
							case (1): {
								cout << "\n\t�������� ���������������� �������";
								inputGeneral(name, companyName, price, weight);
								cout << "\n\t������� �� ��������: \n\t1 - �������\n\t2 - �������\n\t0 - �����\n\t";
								cin >> inputNum;
								switch (inputNum) {
									case(0): return;
									case(1): {
										open = true;
										cout << "\n\t���� ��������(�������� ��������): ";
										cin >> expirationDateInOpenState;
									}
									case(2): {
										open = false;
										cout << "\n\t���� ��������(�������� ��������): ";
										cin >> expirationDateInCloseState;
									}
									default: {
										cout << "\n\t������ ����� \n\n\t";
										system("pause");
										continue;
									}
								}
								products[counter].setProduct(name, companyName, price, weight, open,
									expirationDateInCloseState, expirationDateInOpenState, expirationDate,
									typeOfComponent, productType);
								counter++;
							}
							case (2): {
								cout << "\n\t�������� ������ �������";
								inputGeneral(name, companyName, price, weight);
								cout << "\n\t���� ��������: ";
								cin >> expirationDate;
								products[counter].setProduct(name, companyName, price, weight, open,
									expirationDateInCloseState, expirationDateInOpenState, expirationDate,
									typeOfComponent, productType);
								counter++;
							}
							default: {
								cout << "\n\t������ ����� \n\n\t";
								system("pause");
								continue;
							}
						}
					}
					case (2): {
						cout << "\n\t�������� ����������� �������";
						inputGeneral(name, companyName, price, weight);
						cout << "\n\t��� ��������: ";
						cin >> productType;
						cout << "\n\t��� �������������: ";
						cin >> typeOfComponent;
						products[counter].setProduct(name, companyName, price, weight, open,
							expirationDateInCloseState, expirationDateInOpenState, expirationDate,
							typeOfComponent, productType);
						counter++;

					}
					default: {
						cout << "\n\t������ ����� \n\n\t";
						system("pause");
						continue;
					}
				}
				break; 
			}
			case (2): {

				for (int i = 0; i < counter; i++) {
					string temp = products[i](products[i]);
					cout << "\n\t" << temp.(products[i]);
				}
				cout << "\n\t";
				system("pause");
				continue;
			}
			default: {
				cout << "\n\t������ ����� \n\n\t";
				system("pause");
				continue;
			}
		}
	}
	return;
}