#include <iostream>
#include <thread>

// g++ -std=c++14 thread1.cpp -o t && ./t

using namespace std;

static bool s_Finished = false;

void doWork(){

  using namespace chrono_literals;

  while(!s_Finished){
    cout << "Working...\n";
    this_thread::sleep_for(1s);
  }

}

int main(){
  
  thread worker(doWork);

  cin.get();
  s_Finished = true;

  worker.join();
  cout << "Finished.\n";

  cin.get();
}