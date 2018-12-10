#include <iostream>
#include <thread>
#include <shared_mutex>
#include <vector>
#include <chrono>

std::shared_lock myMutex;
int val = 0;

void doWork(){
  for(int i=0; i<100000; i++){
    myMutex.lock_shared();
    //read
    myMutex.unlock_shared();

    myMutex.lock();
    //writer
    myMutex.unlock();
  }
}

int main(){
  std::vector<std::thread> threads(10);

  for(int i = 0; i < threads.size(); i++){
    threads[i] = std::thread(doWork);
  }

  for(int i = 0; i < threads.size(); i++){
    threads[i].join();
  }

  std::cout << val << std::endl;
}
