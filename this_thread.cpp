#include <iostream>
#include <thread>

void myFunction(){
  std::cout << "Hello from myFunction! \n" << std::this_thread::get_id();
}

int main(){
  std::thread t1(myFunction);

  t1.join();

  return 0;
}