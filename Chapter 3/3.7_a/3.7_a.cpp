//3.7.a Code a program to multiply two polynomials.
//Requirements: 
//1.Use one list.
//2.Make sure the result is by the order of highpower
//3.Give out a solution with time complexity of O(M^2N^2)
//Jonathan Zhang @ 2021/4/7

#include <iostream>
#include <stdlib.h>
#include "polynomial.h"

using namespace std;

void Mul(Equation L_1, Equation L_2, Equation Prod);

int main() {
	//Preparations
	Equation equation_1 = MakeEquation();
	Equation equation_2 = MakeEquation();
	Equation prod = MakeEquation();
	GenerateEquation(equation_1);
	PrintAllTerms(equation_1);
	cout << endl;
	GenerateEquation(equation_2);
	PrintAllTerms(equation_2);

	//Program starts here
	cout << endl << "Result is:" << endl;
	Mul(equation_1, equation_2, prod);
	PrintAllTerms(prod);

	return 0;
}

void Mul(Equation L_1, Equation L_2, Equation Prod) {
	TermPos P_1, P_2;
	TermPos P = Prod;
	int coeff, high;
	for (P_1 = L_1->NextTerm; P_1 != NULL; P_1 = Next(P_1, L_1)) {		//O(M)
		for (P_2 = L_2->NextTerm; P_2 != NULL; P_2 = Next(P_2, L_2)) {	//O(N)
			coeff = P_1->Coefficient * P_2->Coefficient;
			high = P_1->HighPower + P_2->HighPower;
			P = FindPreviousHighPower(high, Prod);			//O(M*N)
			P = InsertTerm(coeff, high, P, Prod);			//O(1)
		}
	}
}