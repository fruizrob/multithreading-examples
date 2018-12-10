#include <iostream>
#include <thread>

//compile -std=c++11

using namespace std;


void foo() {
  for (int j = 0; j < 100; ++j) {
    cout << "j = " << j << endl;
    this_thread::sleep_for(std::chrono::milliseconds(50));
  }
}

void bar(int x) {
  for (int i = 0; i < 100; ++i) {
    cout << "i = " << i << endl;
    this_thread::sleep_for(std::chrono::milliseconds(10));
  }
}

int main() {
  thread t1(foo);
  thread t2(bar, 2);

  t1.join();
  t2.join();

  return 0;
}
