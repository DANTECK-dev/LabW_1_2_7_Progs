#include "SecondGeneralTask.h"
#include "ClassesForSecondGeneralTask.h"

#include "Libraries.h"

void secondGeneralTask()
{
	ProductFood* masF = new ProductFood[100];
	EleProduct* masE = new EleProduct[100];
	int countE = 0, countP = 0;
	while (true) {
		int a;
		cout << "1. �������� ������� � ������� ������� ������� \n"
			"2. �������� ������� � ������� ����������� ����� \n"
			"3. �-��� ���� ��������\n"
			"4. �-��� ������ ������ ������� �������\n";
		cin >> a;
		if (a == 1) {
			int Days;
			string classfood;
			cout << "���� ��������: " << endl;
			cin >> Days;
			cout << "��������������� ��� ������: " << endl;
			cin >> classfood;
			masF[countP] = ProductFood(Days, classfood);
			countP++;
		}
		else if (a == 2) {
			cout << "TypeP: " << endl;
			int TypeP;
			cin >> TypeP;
			cout << "��� ��������: " << endl;
			string TypeProduct;
			cin >> TypeProduct;
			masE[countE] = EleProduct(TypeProduct, TypeP);
			countE++;
		}
		else if (a == 3) {
			int id;
			cout << "ID: " << endl;
			cin >> id;
			cout << "F(Days): " << Days(masF, id) << endl;
		}
		else if (a == 4) {
			cout << "Getdata: " << GetData(masE, countE) << endl;
		}
	}
}