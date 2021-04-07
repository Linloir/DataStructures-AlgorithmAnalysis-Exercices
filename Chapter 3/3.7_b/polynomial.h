#pragma once
#ifndef _POLYNOMIAL_H_
#define _POLYNOMIAL_H_

struct Polynomial;
typedef struct Polynomial Term;
typedef struct Polynomial* PtrToTerm;
typedef PtrToTerm Equation;
typedef PtrToTerm TermPos;

Equation MakeEquation();
int IsLastTerm(TermPos P, Equation L);
TermPos FindPreviousHighPower(int X, Equation L);
void InsertTerm(int C, int H, Equation L);
TermPos InsertTerm(int C, int H, TermPos P, Equation L);
void DeleteTerm(int HighPower, Equation L);
TermPos Next(TermPos P, Equation L);

void GetEquation(Equation L);
void GenerateEquation(Equation L);
void PrintAllTerms(Equation L);

#endif

struct Polynomial {
	int Coefficient;
	int HighPower;
	TermPos NextTerm;
};