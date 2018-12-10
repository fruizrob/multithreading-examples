#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

int data = 0;
std::mutex myMutex;


void doWork()
{
  for (int i = 0; i < 100000; i++)
  {
    myMutex.lock();
    data++;
    myMutex.unlock();
  }
}

int main()
{

  std::vector<std::thread> threads(30);

  for (int i = 0; i < threads.size(); i++)
  {
    threads[i] = std::thread(doWork);
  }
  for (int i = 0; i < threads.size(); i++)
  {
    threads[i].join();
  }

  std::cout << data << std::endl;

  return 0;
}