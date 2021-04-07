//3.6 Code a function to add two polynomial.
//Requirements:
//1.Do not destroy input data.
//2.Use a list to realize.
//3.Give out time complexity when the two polynomial each have M and N terms.
//Jonathan Zhang @ 2021/4/6

#include <iostream>
#include <ctime>
#include "polynomial.h"

using namespace std;

void Add(Equation L_1, Equation L_2, Equation Sum);

int main() {
	//Preparations
	Equation equation_1 = MakeEquation();
	Equation equation_2 = MakeEquation();
	Equation Sum = MakeEquation();
	GenerateEquation(equation_1);
	PrintAllTerms(equation_1);
	GenerateEquation(equation_2);
	PrintAllTerms(equation_2);

	//Program starts here
	Add(equation_1, equation_2, Sum);
	cout << endl << "Sum is :" << endl;
	PrintAllTerms(Sum);

	return 0;
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