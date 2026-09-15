#include <iostream>
#include <chrono>
#include <thread>
using namespace std;

void run(int count){
    while (count --> 0)
        cout << "CppNuts" << endl;
    std::this_thread::sleep_for(chrono::seconds(3));
}
/* Case 1 wth valid out put */
/*
int main(){
    std::thread t1(run, 10);
    cout << "main()"  << endl;
    t1.join();
    cout << "main() after" << endl;
    return 0;
}
*/