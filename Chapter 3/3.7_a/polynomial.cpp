#include "polynomial.h"
#include <iostream>
#include <stdlib.h>
#include <ctime>

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
	while (!IsLastTerm(P, L) && P->NextTerm->HighPower < X) {
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

TermPos InsertTerm(int C, int H, TermPos P, Equation L) {
	if (!IsLastTerm(P, L) && P->NextTerm->HighPower == H) {
		P->NextTerm->Coefficient += C;
		return P->NextTerm;
	}
	else {
		TermPos newTerm = (TermPos)malloc(sizeof(Term));
		newTerm->Coefficient = C;
		newTerm->HighPower = H;
		newTerm->NextTerm = P->NextTerm;
		P->NextTerm = newTerm;
		return newTerm;
	}
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

void GetEquation(Equation L) {
	cout << "Please input equation: " << endl;
	cout << "[Number of terms] [Coeff1] [High1] [Coeff2] [High2] .." << endl;
	int n, c, h;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> c >> h;
		if (c != 0)
			InsertTerm(c, h, L);
	}
}

void GenerateEquation(Equation L) {
	cout << "Please enter max degree:" << endl;
	int maxDegree;
	cin >> maxDegree;
	srand(time(NULL));
	int coeff;
	for (int highPower = 0; highPower <= maxDegree; highPower++) {
		coeff = rand() % 20 - 10;
		if (coeff != 0)
			InsertTerm(coeff, highPower, L);
	}
}

void PrintAllTerms(Equation L) {
	TermPos P = L->NextTerm;
	while (!IsLastTerm(P, L)) {
		cout << P->Coefficient << "x^" << P->HighPower << " + ";
		P = Next(P, L);
	}
	cout << P->Coefficient << "x^" << P->HighPower << endl;
}