#include <iostream>
#include <thread>

using namespace std;
/*   
*   Command    
*
*   g++ -std=c++11 -pthread 03_Different_Type_of_Thread_Creation/main.cpp -o 03_Different_Type_of_Thread_Creation/main.out
*   ./03_Different_Type_of_Thread_Creation/main.out
*   
*/ 

// Note: If we create multiple thread at same time it doesn't noot guarantee which one will start first.

/* 1.Function Pointer                
 *      This the most basic form of thread creation.
 */
/*
void fun(int x){
    while(x-- > 0){
        cout<< x << endl;
    }
}
int main(){
    thread t1(fun, 10);
    thread t2(fun, 11);
    t1.join();
    t2.join();
    return 0;    
}
*/


/*  2.Lambda Function    */
/*
int main(){
    // We can directly inject lambda at thread creation time.
    auto fun = [](int x){
        while(x-- > 0){
            cout << x << endl;
        }
    };

    std::thread t(fun, 10);
    t.join();
    return 0;
}
*/


/*   3. Functor (Function Object)   */
/*
class Base  {
public:
    void operator ()(int x) {
        while (x-- > 0){
            cout << x << endl;
        }
    }
};

int main(){
    std::thread t((Base()), 10);
    t.join();
    return 0;
}
*/

/*   4. Non-static member function   */
/*
class Base
{
public:
    void run(int x){
        while (x-- > 0)
        {
            cout << x << endl;
        }
    }
};

int main() {
    Base b;
    std::thread t(&Base::run, &b, 10);
    t.join();
    return 0;
}
*/

// 5. Static member function
class Base
{
public:
    static void run(int x) {
        while (x-- > 0)
        {
            cout << x << endl;
        }
    }
};

int main(){
    std::thread t(&Base::run, 10);
    t.join();
    return 0;
}