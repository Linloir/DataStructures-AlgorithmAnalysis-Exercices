//2.13 Code a program to verify if N is a prime number
//Jonathan Zhang @ 2021/4/5

#include <iostream>

using namespace std;

bool IsPrime(long long int);

int main() {
	int startTime, endTime;

	cout << "Enter test cases: <N>" << endl;
	int testCases;
	cin >> testCases;
	for (int i = 0; i < testCases; i++) {
		//Initialization
		long long int number;
		cout << "input number:" << endl;
		cin >> number;
		//End of initialization

		startTime = clock();
		//Program start:
		cout << "It is " << (IsPrime(number) == true ? "" : "not ") << "a prime number.";
		//Program end.
		endTime = clock();
		cout << "Run time: " << (double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
	}
	return 0;
}

bool IsPrime(long long int num) {
	bool is_prime = true;
	for (long long int i = 2; i * i < num; i++) {
		//Note: There can't be two divisor both bigger than √N while their product is N
		//		Therefore, if there is no factor under √N, then N is a prime number
		if (num % i == 0) {
			is_prime = false;
			break;
		}
	}
	return is_prime;
}

//Assumed that T(N) = O(N^1/2)

//c.
//B = (int)log2(N) + 1

//d.
//T(B) = O((2^B)^1/2)

//e.
//B1 ≈ 0.002s
//B2 = 0.009s

//f.
//They are the same. [WRONG]
//B is better because it represent the size of the input.