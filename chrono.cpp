#include <iostream>
#include <chrono>
#include <thread>

// g++ -std=c++14 thread2.cpp -o t && ./t

using namespace std;

static bool s_Finished = false;

void showTime(){
  using namespace chrono_literals;
  using namespace chrono;

  auto start = high_resolution_clock::now();

  while(!s_Finished){
  
    this_thread::sleep_for(1ms);
    auto end = high_resolution_clock::now();

    duration<double, milli> elapsed = end - start;
    cout << "Waited " << elapsed.count() << " ms\n";
  }

  
}

int main(){
  cout << "Hello waiter" << endl;

  thread timeShower(showTime);

  cin.get();
  s_Finished = true;

  timeShower.join();
  cout << "Finished.\n";

  cin.get();

}