#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

void run_no_delay(int count){
    static int i = 0;
    while (count --> 0)
    {
        cout<<" Count: "<<++i<<endl;
    }    
}

void run_with_delay(int count){
    static int i = 0;
    while (count --> 0)
    {
        cout<<" Count: "<<++i<<endl;
    }
    std::this_thread::sleep_for(chrono::seconds(2));   
}
// running commnand
// g++ -std=c++11 -pthread 02_Join_And_Detach/main.cpp -o 02_Join_And_Detach/main.out
int main(){
    
    // Example 1
    /*======== Simple Thread Without Delay ========*/
    /*------------------- Start -------------------*/
    // std::thread t1(run_no_delay, 10);
    // t1.join();
    /*-------------------  End  -------------------*/


    //Example 2
    /*========  Simple Thread With Delay   ========*/
    /*------------------- Start -------------------*/
    // std::thread t1(run_with_delay, 10);
    // cout<<"main()"<<endl;
    // t1.join();
    // cout<<"main() After"<<endl;
    /*-------------------  End  -------------------*/


    //Example 3
    /*==== Simple Thread With Delay Double Join ===*/
    /*      Error Program will crash               */
    /*------------------- Start -------------------*/
    // std::thread t1(run_with_delay, 10);
    // cout<<"main()"<<endl;
    // t1.join();
    // t1.join();
    // cout<<"main() After"<<endl;
    /*-------------------  End  -------------------*/


    //Example 4
    /*==== Simple Thread With Delay Double Join ===*/
    /*    Takle the Example 4 Double join error    */
    /*------------------- Start -------------------*/
    std::thread t1(run_with_delay, 10);
    cout<<"main()"<<endl;
    t1.join();
    if(t1.joinable()){
        t1.join();    
    }
    cout<<"main() After"<<endl;
    /*-------------------  End  -------------------*/

    return 0;
}