#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>
using namespace std;
using namespace std::chrono;
typedef unsigned long long ull;

ull OddSum = 0;
ull EvenSum = 0;

void findEven(ull start, ull end) {
    for (ull i = start; i <= end; ++i) {
        if ((i & 1) == 0) {
            EvenSum += i;
        }
    }
}

void findOdd(ull start, ull end) {
    for (ull i = start; i <= end; ++i) {
        if ((i & 1) == 1) {
            OddSum += i;
        }
    }
}
// To Run ```   g++ -std=c++11 -pthread 01_Simple_Example/example_without_thread.c     ```
int main() {
    ull start = 1;
    ull end = 1900000000;
    //Taking the time
    auto startTime = high_resolution_clock::now();

    findEven(start, end);
    findOdd(start, end);

    //Taking the time at end point
    auto stopTime = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stopTime - startTime);
    cout << "Even Sum: " << EvenSum << endl;
    cout << "Odd Sum: " << OddSum << endl;
    cout << "Duration take: "<< duration.count()/1000000 << endl;
    return 0;
}