#include <iostream>
#include <thread>

using namespace std;

//compile -std=c++11

int sharedMem = 0;

void foo() {
  for (int j = 0; j < 100; ++j) {
    cout << "j = " << j << endl;
    this_thread::sleep_for(std::chrono::milliseconds(10));
    sharedMem++;
  }
}

void bar(int x) {
  for (int i = 0; i < 100; ++i) {
    cout << "i = " << i << endl;
    this_thread::sleep_for(std::chrono::milliseconds(10));
    sharedMem++;
  }
}

int main() {
  thread t1(foo);
  thread t2(bar, 2);

  t1.join();
  t2.join();

  cout << "sharedMem:" << sharedMem << endl;

  return 0;
}
