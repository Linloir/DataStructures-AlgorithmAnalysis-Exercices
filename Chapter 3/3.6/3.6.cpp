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

void GetEquation(Equation L);
//TestCases
void GenerateEquation(Equation L);
void PrintAllTerms(Equation L);

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

void GetEquation(Equation L) {
	cout << "Please input equation: " << endl;
	cout << "[Number of terms] [Coeff1] [High1] [Coeff2] [High2] .." << endl;
	int n, c, h;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> c >> h;
		if(c != 0)
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
		if(coeff != 0)
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