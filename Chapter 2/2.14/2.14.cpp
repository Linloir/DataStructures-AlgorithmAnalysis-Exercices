//2.14 Run time of Erastothenes sieve
//Jonathan Zhang @ 2021/4/5

#include <iostream>

using namespace std;

void PrintAllPrimeNumbers(long long int);

int main() {
	cout << "Enter test cases: <N>" << endl;
	int testCases;
	cin >> testCases;
	for (int i = 0; i < testCases; i++) {
		long long int n;
		cout << "Enter N: " << endl;
		cin >> n;
		int startTime, endTime;
		startTime = clock();
		//Program starts here:
		PrintAllPrimeNumbers(n);
		//Program ends here.
		endTime = clock();
		cout << "Run time: " << (double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
	}
}

void PrintAllPrimeNumbers(long long int n) {
	bool* table = new bool[n + 1];
	for (int i = 0; i <= n; i++)
		table[i] = true;
	for (int i = 2; i <= n; i++) {
		if (table[i]) {
			//cout << i << endl;
			for (int j = 2; j * i <= n; j++)
				table[j * i] = false;
		}
	}
}

//Assumed that T(N) = O(NlogN)  WRONG
//CORRECTION:  T(N) = O(NloglogN)

//Note:
//Why?