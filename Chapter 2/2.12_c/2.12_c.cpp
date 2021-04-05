//2.12.c find the max multiplication of subsequence
//Jonathan Zhang @ 2021/4/5

#include <iostream>

using namespace std;

double FindMaxMul(double*, int);
double* GenerateSequence(int, int);

int main() {
	int N, showSequence;
	int startTime, endTime;

	cout << "Enter test cases: <N> [showSequence?]" << endl;
	int testCases;
	cin >> testCases >> showSequence;
	for (int i = 0; i < testCases; i++) {
		cout << "Enter N:" << endl;
		cin >> N;
		double* mySequence = GenerateSequence(N, showSequence == 1 ? 1 : 0);

		startTime = clock();
		cout << "Max multiplication is: " << FindMaxMul(mySequence, N) << endl;
		endTime = clock();
		cout << "Run time: " << (double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
	}
	return 0;
}

double FindMaxMul(double* mySequence, int N) {
	double thisMul = 1;
	double maxMul = mySequence[0];
	for (int i = 0; i < N; i++) {
		thisMul *= mySequence[i];
		if (thisMul > maxMul)
			maxMul = thisMul;
		if (thisMul < 1)
			thisMul = 1;
	}
	return maxMul;
}

double* GenerateSequence(int N, int showSequence) {
	srand(time(NULL));
	if (showSequence)
		cout << "Generated random sequence:" << endl;
	double* mySequence = new double[N];
	for (int i = 0; i < N; i++) {
		mySequence[i] = (double)(rand() % 20 + 1)/(double)(rand() % 20 + 1);
		if (showSequence)
			cout << mySequence[i] << " ";
	}
	if (showSequence)
		cout << endl;
	return mySequence;
}

//Assumed that T(N) = O(N)