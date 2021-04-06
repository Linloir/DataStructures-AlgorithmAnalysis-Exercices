#include "polynomial.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

Equation MakeEquation() {
	Equation newEquation = (Equation)malloc(sizeof(Term));
	newEquation->Coefficient = 0;
	newEquation->HighPower = 0;
	newEquation->NextTerm = NULL;
	return newEquation;
}

int IsLastTerm(TermPos P, Equation L) {
	return P->NextTerm == NULL;
}

TermPos FindPreviousHighPower(int X, Equation L) {
	TermPos P;
	P = L;
	while (!IsLastTerm(P, L) && P->NextTerm->HighPower <= X) {
		P = Next(P, L);
	}
	return P;
}

void InsertTerm(int C, int H, Equation L) {
	TermPos P, newTerm;
	P = FindPreviousHighPower(H, L);
	if (!IsLastTerm(P, L) && P->NextTerm->HighPower == H) {
		P->NextTerm->Coefficient += C;
	}
	else {
		newTerm = (TermPos)malloc(sizeof(Term));
		if (newTerm == NULL)
			cout << "Not enough space!" << endl;
		else {
			newTerm->Coefficient = C;
			newTerm->HighPower = H;
			newTerm->NextTerm = P->NextTerm;
			P->NextTerm = newTerm;
		}
	}
}

void InsertTerm(int C, int H, TermPos P, Equation L) {
	TermPos newTerm = (TermPos)malloc(sizeof(Term));
	newTerm->Coefficient = C;
	newTerm->HighPower = H;
	newTerm->NextTerm = P->NextTerm;
	P->NextTerm = newTerm;
}

void DeleteTerm(int HighPower, Equation L) {
	TermPos P;
	P = FindPreviousHighPower(HighPower, L);
	if (!IsLastTerm(P, L) && P->NextTerm->HighPower == HighPower) {
		P->NextTerm = Next(P, L)->NextTerm;
		free(Next(P, L));
	}
	else
		cout << "Not in this equation! Nothing changed." << endl;
}

TermPos Next(TermPos P, Equation L) {
	return P->NextTerm;
}

void Add(Equation L_1, Equation L_2, Equation Sum) {
	TermPos P_1, P_2;
	TermPos P;
	P_1 = L_1->NextTerm;
	P_2 = L_2->NextTerm;
	P = Sum;
	while (P_1 != NULL && P_2 != NULL) {
		if (P_1->HighPower > P_2->HighPower) {
			InsertTerm(P_2->Coefficient, P_2->HighPower, P, Sum);
			P_2 = Next(P_2, L_2);
			P = Next(P, Sum);
		}
		else if (P_1->HighPower < P_2->HighPower) {
			InsertTerm(P_1->Coefficient, P_1->HighPower, P, Sum);
			P_1 = Next(P_1, L_1);
			P = Next(P, Sum);
		}
		else {
			if (P_1->Coefficient + P_2->Coefficient != 0) {
				InsertTerm(P_1->Coefficient + P_2->Coefficient, P_1->HighPower, P, Sum);
				P = Next(P, Sum);
			}
			P_2 = Next(P_2, L_2);
			P_1 = Next(P_1, L_1);
		}
	}
	while (P_1 != NULL || P_2 != NULL) {
		if (P_1 != NULL) {
			InsertTerm(P_1->Coefficient, P_1->HighPower, P, Sum);
			P_1 = Next(P_1, L_1);
		}
		else {
			InsertTerm(P_2->Coefficient, P_2->HighPower, P, Sum);
			P_2 = Next(P_2, L_2);
		}
		P = Next(P, Sum);
	}
}

void Mul(Equation L_1, Equation L_2, Equation Prod) {
	TermPos P_1, P_2;
	P_1 = L_1->NextTerm;
	P_2 = L_2->NextTerm;
	for (; P_1 != NULL; P_1 = Next(P_1, L_1)) {
		for (; P_2 != NULL; P_2 = Next(P_2, L_2)) {
			InsertTerm(P_1->Coefficient * P_2->Coefficient, P_1->HighPower + P_2->HighPower, Prod);
		}
	}
}