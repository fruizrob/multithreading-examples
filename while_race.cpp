#include <thread>
#include <vector>
#include <iostream>

int data = 0;

void doWork()
{
  while( data < 1000000)
  {
    data++;
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