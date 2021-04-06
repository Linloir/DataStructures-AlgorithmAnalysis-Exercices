//3.4 Using basic list operations to calculate L1 ∪ L2
//Jonathan Zhang @ 2021/4/6

#include "link.h"
#include <iostream>

using namespace std;

void GetList(List L);
void PrintAllElements(List L);

void Intersection(List L_1, List L_2, List Result);

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
	Intersection(list_1, list_2, result);
	cout << "Result: " << endl;
	PrintAllElements(result);

	return 0;
}

void Intersection(List L_1, List L_2, List Result) {
	Position P_1, P_2;
	Position P;
	P = Result;
	//Not so good
	/*P_1 = L_1->Next;
	while (P_1 != NULL) {
		P_2 = L_2->Next;
		while (P_2 != NULL) {
			if (Retrieve(P_1) == Retrieve(P_2))
				P = Insert(Retrieve(P_1), P, Result);
			P_2 = P_2->Next;
		}
		P_1 = P_1->Next;
	}*/
	//Correction
	P_1 = L_1->Next;
	P_2 = L_2->Next;
	while (P_1 != NULL && P_2 != NULL) {
		if (Retrieve(P_1) < Retrieve(P_2))
			P_1 = Advance(P_1);
		else if (Retrieve(P_1) > Retrieve(P_2))
			P_2 = Advance(P_2);
		else {
			P = Insert(Retrieve(P_1), P, Result);
			P_1 = Advance(P_1);
			P_2 = Advance(P_2);
		}
	}
	//Assumed that T(N) = O(N) ?
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