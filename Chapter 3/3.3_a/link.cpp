//Link.cpp by Jonathan Zhang (Linloir) @ 2021/4/6

#include "link.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

List MakeList() {
	List newList = (List)malloc(sizeof(Node));
	newList->Element = 0;
	newList->Next = NULL;
	return newList;
}

int IsEmpty(List L) {
	return L->Next == NULL;
}

int IsLast(Position P, List L) {
	return P->Next == NULL;
}

Position Find(ElementType X, List L) {
	Position P;
	//Not So Good
	/*if (IsEmpty(L))
		return NULL;
	for (p = L->Next; p->Element != X && p->Next != NULL;) {
		p = p->Next;
	}
	if (p->Element == X)
		return p;
	else {
		cout << "Element not found" << endl;
		return NULL;
	}*/
	P = L->Next;
	while (P != NULL && P->Element != X)	//Do not change order
		P = P->Next;
	return P;
}

Position FindPrevious(ElementType X, List L) {
	Position P;
	P = L;
	while (P->Next != NULL && P->Next->Element != X)
		P = P->Next;
	if (P->Next == NULL)
		return NULL;
	return P;
}

Position Insert(ElementType X, Position P, List L) {
	Position newNode;
	newNode = (Position)malloc(sizeof(Node));
	//Always be aware of issues
	if (newNode == NULL)
		cout << "Not Enough Space" << endl;
	newNode->Element = X;
	newNode->Next = P->Next;
	P->Next = newNode;
	return newNode;
}

void Delete(ElementType X, List L) {
	Position P;
	P = FindPrevious(X, L);
	if (P == NULL)
		cout << "No matched value in link, nothing changed." << endl;
	else {
		Position TmpCell = P->Next;
		P->Next = TmpCell->Next;
		free(TmpCell);
	}
}

void DeleteList(List L) {
	Position P;
	Position TmpCell;
	P = L->Next;
	while (P != NULL) {
		TmpCell = P->Next;
		free(P);
		P = TmpCell;
	}
}

Position Header(List L) {
	return L;
}

Position First(List L) {
	return L->Next;
}

Position Advance(Position P) {
	return P->Next;
}

Position Previous(Position P, List L) {
	Position Tmp;
	Tmp = L->Next;
	while (Tmp != NULL && Tmp->Next != P)
		Tmp = Tmp->Next;
	if (!IsLast(Tmp, L))
		return Tmp;
	cout << "Previous not found." << endl;
	cout << "P not in list L ? " << endl;
	return NULL;
}

ElementType Retrieve(Position P) {
	return P->Element;
}