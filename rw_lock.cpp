#include <iostream>
#include <mutex> // For std::unique_lock
#include <shared_mutex>
#include <thread>
#include <vector>

std::shared_mutex myMutex;
unsigned int value = 0;

// Multiple threads/readers can read the counter's value at the same time.
void get()
{
  myMutex.lock_shared();
  std::cout << value << std::endl;
  myMutex.unlock_shared();
}

// Only one thread/writer can increment/write the counter's value.
void increment()
{
  myMutex.lock();
  value++;
  myMutex.unlock();
}

int main()
{
  std::vector<std::thread> myThreads(10);
  std::vector<int> myVector = {1, 2, 1, 1, 2, 1, 1, 1, 1, 1};

  for(int i = 0; i < myVector.size(); i++){
    if(myVector[i] == 1){
      std::cout << " ";
      myThreads[i] = std::thread(get);
    } else {
      myThreads[i] = std::thread(increment);
    }
  }

  for(int i = 0; i < myThreads.size(); i++){
    myThreads[i].join();
  }

  std::cout <<  "\n" << value << "\n";
}