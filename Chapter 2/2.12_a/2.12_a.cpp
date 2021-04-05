//2.12.a Find the min sequence sum
//Jonathan Zhang @ 2021/4/5

#include <iostream>
#include <time.h>

using namespace std;

int* generate_Sequence(int);

int main() {
	cout << "Please input count N for sequence:" << endl;
	int N;
	cin >> N;
	int* mySequence = generate_Sequence(N);
	int minSum = 0;
	int nextSum = 0;
	for (int i = 0; i < N; i++) {
		nextSum += mySequence[i];
		if (nextSum > 0)
			nextSum = 0;
		if (nextSum < minSum)
			minSum = nextSum;
	}
	cout << "The min sum is: " << minSum << endl;
	return 0;
}

int* generate_Sequence(int N) {
	srand(time(NULL));
	cout << "Generated random sequence:" << endl;
	int* mySequence = new int[N];
	for (int i = 0; i < N; i++) {
		mySequence[i] = rand() % 20 - 10;
		cout << mySequence[i] << " ";
	}
	cout << endl;
	return mySequence;
}

//know issue:
//When all the integers are positive, answer is 0.