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
		cout << "1. Добавить элемент к массиву Продукт питания \n"
			"2. Добавить элемент к массиву Электронный товар \n"
			"3. Ф-ция Срок годности\n"
			"4. Ф-ция вывода данных Электро товаров\n";
		cin >> a;
		if (a == 1) {
			int Days;
			string classfood;
			cout << "Срок годности: " << endl;
			cin >> Days;
			cout << "Консервироанная или свежая: " << endl;
			cin >> classfood;
			masF[countP] = ProductFood(Days, classfood);
			countP++;
		}
		else if (a == 2) {
			cout << "TypeP: " << endl;
			int TypeP;
			cin >> TypeP;
			cout << "Тип продукта: " << endl;
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