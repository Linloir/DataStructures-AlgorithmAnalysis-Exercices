//3.1 Code a program that can print all the elements in a single link
//Jonathan Zhang @ 2021/4/6

#include "link.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

void PrintAllElements(List L);

int main() {
	List list = MakeList();
	cout << "Input list: [number] [Element1] [Element2] [ElementN]" << endl;
	int n;
	cin >> n;
	//Make List
	Position Tmp = list;
	ElementType element;
	for (; n > 0; n--) {
		cin >> element;
		Tmp = Insert(element, Tmp, list);
	}
	//Print All
	PrintAllElements(list);

	return 0;
}

void PrintAllElements(List L) {
	Position P;
	P = L->Next;
	int counter = 1;
	while (P != NULL) {
		cout << "[Element " << counter << "]: " << P->Element << endl;
		P = P->Next;
		counter++;
	}
}