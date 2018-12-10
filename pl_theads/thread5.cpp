#include <iostream>
#include <thread>

using namespace std;

//compile -std=c++11

int sharedMem = 0;

mutex mymutex;

void foo() {
  mymutex.lock();
  for (int j = 0; j < 100; ++j) {
    cout << "j = " << j << endl;
    this_thread::sleep_for(std::chrono::milliseconds(10));
    sharedMem++;
  }
  mymutex.unlock();
}

void bar(int x) {
  mymutex.lock();
  for (int i = x; i < 100; ++i) {
    cout << "i = " << i << endl;
    this_thread::sleep_for(std::chrono::milliseconds(10));
    sharedMem++;
  }
  mymutex.unlock();
}

int main() {
  thread t1(foo);
  thread t2(bar, 0);

  t1.join();
  t2.join();

  cout << "sharedMem:" << sharedMem << endl;
  return 0;
}
