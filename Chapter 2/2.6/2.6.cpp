//2.6
//For 6 program sections, give each one of them:
//a.Run time analysis (Using O)
//b.Use your language to code and give exact time for different N
//c.Compare your analysis with the real time

//a.

//1.
/*
Sum = 0;
for(i = 0; i < N; i++)
    Sum++;
*/
//T(N) = O(N)

//2.
/*
Sum = 0;
for(i = 0; i < N; i++)
    for(j = 0; j < N; j++)
        Sum++;
*/
//T(N) = O(N^2)

//3.
/*
Sum = 0;
for(i = 0; i < N; i++)
    for(j = 0; j < N * N; j++)
        Sum++;
*/
//T(N) = O(N^3)

//4.
/*
Sum = 0;
for(i = 0; i < N; i++)
    for(j = 0; j < i; j++)
        Sum++;
*/
//T(N) = O(N^2)

//5.
/*
Sum = 0;
for(i = 0; i < N; i++)
    for(j = 0; j < i * i; j++)
        for(k = 0; k < j; k++)
            Sum++;
*/
//T(N) = O(N^5)

//6.
/*
Sum = 0;
for(i = 0; i < N; i++)
    for(j = 1; j < i * i; j++)
        if(j % i == 0)
            for(k = 0; k < j; k++)
                Sum++;
*/
//T(N) = O(N^3) WRONG
//CORRECTION T(N) = O(N^4)
//! In function Segma(i^k), i from 1 to N, Segma(i^k) = O(N^(k+1))

//b.

#include <iostream>
#include <ctime>

using namespace std;
int main() {
    clock_t startTime, endTime;
    int N;
    int Sum;

    //1
    for (int t = 0; t < 5; t++) {
        cout << "[1]Please enter N" << endl;
        cin >> N;
        startTime = clock();
        Sum = 0;
        for (int i = 0; i < N; i++) {
            Sum++;
        }
        endTime = clock();
        cout << "Run time: " << (double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
    }
    
    //2
    for (int t = 0; t < 5; t++) {
        cout << "[2]Please enter N" << endl;
        cin >> N;
        startTime = clock();
        Sum = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                Sum++;
            }
        }
        endTime = clock();
        cout << "Run time: " << (double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
    }
    

    //3
    for (int t = 0; t < 5; t++) {
        cout << "[3]Please enter N" << endl;
        cin >> N;
        startTime = clock();
        Sum = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N * N; j++) {
                Sum++;
            }
        }
        endTime = clock();
        cout << "Run time: " << (double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
    }
    

    //4
    for (int t = 0; t < 5; t++) {
        cout << "[4]Please enter N" << endl;
        cin >> N;
        startTime = clock();
        Sum = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < i; j++) {
                Sum++;
            }
        }
        endTime = clock();
        cout << "Run time: " << (double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
    }
    

    //5
    for (int t = 0; t < 5; t++) {
        cout << "[5]Please enter N" << endl;
        cin >> N;
        startTime = clock();
        Sum = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < i * i; j++) {
                for (int k = 0; k < j; k++) {
                    Sum++;
                }
            }
        }
        endTime = clock();
        cout << "Run time: " << (double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
    }
    

    //6
    for (int t = 0; t < 5; t++) {
        cout << "[6]Please enter N" << endl;
        cin >> N;
        startTime = clock();
        Sum = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 1; j < i * i; j++) {
                if (j % i == 0) {
                    for (int k = 0; k < j; k++) {
                        Sum++;
                    }
                }
            }
        }
        endTime = clock();
        cout << "Run time: " << (double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
    }
    
    //Run time see: 2.6.xlsx
}