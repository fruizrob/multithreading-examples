#include <iostream>
#include <thread>

int main(){
  int numThreads = std::thread::hardware_concurrency();
  std::cout << numThreads;
  return 0;
}