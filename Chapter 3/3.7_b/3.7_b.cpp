//3.7.b Code a program to multiply two polynomials.
//Requirements: 
//1.Use one list.
//2.Make sure the result is by the order of highpower
//3.Give out a solution with time complexity of O(M^2N)
//Jonathan Zhang @ 2021/4/7

#include "polynomial.h"
#include <iostream>

using namespace std;

void Mul(Equation L_1, Equation L_2, Equation Prod);

int main() {
	//Preparations
	Equation equation_1 = MakeEquation();
	Equation equation_2 = MakeEquation();
	Equation prod = MakeEquation();
	GenerateEquation(equation_1);
	PrintAllTerms(equation_1);
	GenerateEquation(equation_2);
	PrintAllTerms(equation_2);

	//Program starts here
	cout << endl << "Result is:" << endl;
	Mul(equation_1, equation_2, prod);
	PrintAllTerms(prod);

	return 0;
}

void Mul(Equation L_1, Equation L_2, Equation Prod) {

}