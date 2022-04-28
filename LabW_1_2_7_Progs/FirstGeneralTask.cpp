
#include "FirstGeneralTask.h"

#include "ThisIs.h"

#include "Libraries.h"

using namespace std;

class IntSetMassive {
public:

	IntSetMassive();
	~IntSetMassive();
	int getSize();
	void pushBack(const int data);
	void showAll();
	void deleteNode(const int index);
	void clearAll();
	bool chekValue(const int value);
	void operator+(const int data);
	void operator+(const IntSetMassive& other);
	void operator-(const int data);
	void operator-(const IntSetMassive& other);
	int& operator[](const int index);
	int getIndexOfValue(const int value);

private:
	class Node {
	public:
		int data;
		Node* pNext;
		Node(int data = 0, Node* pNext = nullptr) {
			this->data = data;
			this->pNext = pNext;
		}
	};
	int SIZE;
	Node* pHead;
};

IntSetMassive::IntSetMassive() {
	this->pHead = nullptr;
	this->SIZE = 0;
}

IntSetMassive::~IntSetMassive() {
	clearAll();
}

int IntSetMassive::getSize() {
	return SIZE;
}

void IntSetMassive::pushBack(const int data) {
	if (this->pHead == nullptr) {
		this->pHead = new Node(data);
	}
	else {
		Node* pTemp = this->pHead;
		while (pTemp->pNext != nullptr) {
			pTemp = pTemp->pNext;
		}
		pTemp->pNext = new Node(data);
	}
	this->SIZE++;
}

void IntSetMassive::showAll() {
	Node* pTemp = this->pHead;
	while (pTemp != nullptr) {
		cout << pTemp->data << " ";
		pTemp = pTemp->pNext;
	}
}

void IntSetMassive::deleteNode(const int index) {
	int counter = 0;
	Node* pTemp = this->pHead;

	if (counter == index) {
		this->pHead = this->pHead->pNext;
		delete pTemp;
	}

	else {

		for (; counter < index - 1; counter++) {
			pTemp = pTemp->pNext;
		}

		Node* pTempForDelete = pTemp->pNext;
		pTemp->pNext = pTempForDelete->pNext;
		delete pTempForDelete;
	}

	this->SIZE--;
}

void IntSetMassive::clearAll() {

	for (int i = 0; i < getSize(); i++) {
		deleteNode(i);
	}

	this->SIZE = 0;
}

bool IntSetMassive::chekValue(const int value) {
	Node* pTemp = this->pHead;
	while (pTemp != nullptr) {
		if (pTemp->data == value) {
			return true;
		}
		pTemp = pTemp->pNext;
	}
	return false;
}

void IntSetMassive::operator+(const int data) {
	IntSetMassive::pushBack(data);
}

void IntSetMassive::operator+(const IntSetMassive& other) {
	Node* pTemp = other.pHead;
	while (pTemp != nullptr) {
		IntSetMassive::pushBack(pTemp->data);
		pTemp = pTemp->pNext;
	}
}

void IntSetMassive::operator-(const int data) {
	if (IntSetMassive::chekValue(data)) {
		deleteNode(getIndexOfValue(data));
	}
	else {
		cout << "none";
	}
}

void IntSetMassive::operator-(const IntSetMassive& other) {
	Node* pTemp = other.pHead;
	while (pTemp != nullptr) {
		if (IntSetMassive::chekValue(pTemp->data)) {
			cout << pTemp->data << " ";
		}
		pTemp = pTemp->pNext;
	}
}

int& IntSetMassive::operator[](const int index) {
	Node* pTemp = this->pHead;

	if (index == 0) {
		return pTemp->data;
	}

	else {
		int counter = 0;
		while (counter != index) {
			pTemp = pTemp->pNext;
			counter++;
		}
		return pTemp->data;
	}
}

int IntSetMassive::getIndexOfValue(const int value) {
	int counter = 0;
	Node* pTemp = this->pHead;
	while (pTemp->data != value) {
		pTemp = pTemp->pNext;
		counter++;
	}
	return counter;
}

void firstGeneralTask() {
	cout << "\n\t";
	IntSetMassive it;
	it.pushBack(2);
	it.pushBack(-3);
	it.pushBack(5676);
	it.pushBack(23432);
	IntSetMassive it2;
	it2.pushBack(24);
	it2.pushBack(-33);
	it2.pushBack(56765);
	it2.pushBack(23432);
	it - it2;
	it.showAll();
	cout << "\n\t";
	system("pause");
	return;
}