//3.5 Use basic list operations to caculate sum of two lists
//Jonathan Zhang @ 2021/4/6

#include "link.h"
#include <iostream>

using namespace std;

void GetList(List L);
void PrintAllElements(List L);

void Sum(List L_1, List L_2, List Result);

int main() {
	//Preparations
	List list_1 = MakeList();
	List list_2 = MakeList();
	List result = MakeList();
	GetList(list_1);
	PrintAllElements(list_1);
	GetList(list_2);
	PrintAllElements(list_2);

	//Program starts here
	Sum(list_1, list_2, result);
	cout << "Result is: " << endl;
	PrintAllElements(result);

	return 0;
}

void Sum(List L_1, List L_2, List Result) {
	Position P_1, P_2, P;
	P_1 = L_1->Next;
	P_2 = L_2->Next;
	P = Result;
	while (P_1 != NULL && P_2 != NULL) {
		if (Retrieve(P_1) < Retrieve(P_2)) {
			P = Insert(Retrieve(P_1), P, Result);
			P_1 = Advance(P_1);
		}
		else if(Retrieve(P_1) > Retrieve(P_2)) {
			P = Insert(Retrieve(P_2), P, Result);
			P_2 = Advance(P_2);
		}
		else {
			P = Insert(Retrieve(P_1), P, Result);
			P_1 = Advance(P_1);
			P_2 = Advance(P_2);
		}
	}
	while (P_1 != NULL || P_2 != NULL) {
		if (P_1 != NULL) {
			P = Insert(Retrieve(P_1), P, Result);
			P_1 = Advance(P_1);
		}
		else {
			P = Insert(Retrieve(P_2), P, Result);
			P_2 = Advance(P_2);
		}
	}
}

void GetList(List L) {
	cout << "Input list: [number] [Element1] [Element2] [ElementN]" << endl;
	int n;
	cin >> n;
	//Make List
	Position Tmp = L;
	ElementType element;
	for (; n > 0; n--) {
		cin >> element;
		Tmp = Insert(element, Tmp, L);
	}
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