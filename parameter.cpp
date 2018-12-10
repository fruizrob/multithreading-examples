#include <iostream>
#include <thread>
#include <string>

void myFunction(std::string msg){
  std::cout << msg << std::endl;
}

int main(){

  std::thread t1(myFunction, "Hello from parameter! \n");

  t1.join();

  return 0;
}