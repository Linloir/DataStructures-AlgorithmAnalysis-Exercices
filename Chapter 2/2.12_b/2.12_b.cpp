//2.12.b Find the min positive sum of a subsuquence
//Jonathan Zhang @ 2021/4/5

#include <iostream>
#include <ctime>

using namespace std;

int FindMinSum(int*, int, int);
int* GenerateSequence(int, int);
int GetMin(int, int, int);

int main() {
	int N, showSequence;
	int startTime, endTime;

	cout << "Enter test cases: <N> [showSequence?]" << endl;
	int testCases;
	cin >> testCases >> showSequence;
	for (int i = 0; i < testCases; i++) {
		cout << "Enter N:" << endl;
		cin >> N;
		int* mySequence = GenerateSequence(N, showSequence == 1 ? 1 : 0);

		startTime = clock();
		cout << "Min positive sum is: " << FindMinSum(mySequence, 0, N - 1) << endl;
		endTime = clock();
		cout << "Run time: " << (double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
	}
	return 0;
}

int FindMinSum(int* mySequence, int left, int right) {
	int middle = (left + right) / 2;
	int minSum = 999;
	int minSumLeft = 999, minSumRight = 999;
	int minSumMiddle = 999;

	//Base situation
	if (left == right) {
		minSum = mySequence[left];
		return minSum;
		//exit loop
	}

	//Normal situation
	minSumLeft = FindMinSum(mySequence, left, middle);
	minSumRight = FindMinSum(mySequence, middle + 1, right);

	//Not so good
	/*for (int i = middle; i >= left; i--) {
		for (int j = middle + 1; j <= right; j++) {
			int thisSum = 0;
			for (int k = i; k <= j; k++) {
				thisSum += mySequence[k];
			}
			if (thisSum > 0 && thisSum < minSumMiddle)
				minSumMiddle = thisSum;
		}
	}*/
	//Second Try
	int minSumMiddleL = 0, minSumMiddleR = 0;
	for (int i = middle; i >= left; i--) {
		minSumMiddleL += mySequence[i];
		for (int j = middle + 1; j <= right; j++) {
			minSumMiddleR += mySequence[j];
			int thisSum = minSumMiddleL + minSumMiddleR;
			if (thisSum > 0 && thisSum < minSumMiddle)
				minSumMiddle = thisSum;
		}
	}

	minSum = GetMin(minSumLeft, minSumRight, minSumMiddle);
	return minSum == 999 ? -1 : minSum;
}

int GetMin(int a, int b, int c) {
	a = a > 0 ? a : 999;
	b = b > 0 ? b : 999;
	if (a < b) {
		if (a < c)
			return a;
		else if (b < c)
			return b;
		else
			return c;
	}
	else if (b < c)
		return b;
	else
		return c;
}

int* GenerateSequence(int N, int showSequence) {
	srand(time(NULL));
	if (showSequence)
		cout << "Generated random sequence:" << endl;
	int* mySequence = new int[N];
	for (int i = 0; i < N; i++) {
		mySequence[i] = rand() % 20 - 10;
		if (showSequence)
			cout << mySequence[i] << " ";
	}
	if (showSequence)
		cout << endl;
	return mySequence;
}

//Assumed that T(N) = O(N^2logN)