//3.3.b Swap two adjacent elements in a double list only by adjusting pointers
//Jonathan Zhang @ 2021/4/6

#include "link.h"
#include <iostream>

using namespace std;

void GetList(List L);
void PrintAllElements(List L);

void AdjacentSwap(ElementType X_1, ElementType X_2, List L);

int main() {
	//Preparations
	List list = MakeList();
	GetList(list);
	PrintAllElements(list);

	//Program starts here
	ElementType ele_1, ele_2;
	cout << "Please enter the two elements you want to swap:" << endl;
	cin >> ele_1 >> ele_2;
	AdjacentSwap(ele_1, ele_2, list);
	PrintAllElements(list);

	return 0;
}

void AdjacentSwap(ElementType X_1, ElementType X_2, List L) {
	Position P_1, P_2;
	P_1 = Find(X_1, L);
	P_2 = Find(X_2, L);
	if (P_1->Previous == P_2) {
		//Next
		P_2->Previous->Next = P_1;
		//Previous
		P_1->Previous = P_2->Previous;
		P_2->Previous = P_1;
		if (!IsLast(P_1, L))
		P_1->Next->Previous = P_2;
		//Next
		P_2->Next = P_1->Next;
		P_1->Next = P_2;
	}
	else if (P_2->Previous == P_1) {
		//Next
		P_1->Previous->Next = P_2;
		//Previous
		P_2->Previous = P_1->Previous;
		P_1->Previous = P_2;
		if(!IsLast(P_2, L))
			P_2->Next->Previous = P_1;
		//Next
		P_1->Next = P_2->Next;
		P_2->Next = P_1;
	}
	else
		cout << "These two elements are not adjacent, nothing changed." << endl;
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