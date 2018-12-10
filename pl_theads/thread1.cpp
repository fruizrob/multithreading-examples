#include <iostream>
#include <thread>

using namespace std;
//compile -std=c++11

int sharedMem = 0;

void foo() {
  for (int j = 0; j < 100; ++j) {
    cout << "j = " << j << endl;
  }
}

void bar(int x) {
  for (int i = 0; i < 100; ++i) {
    cout << "i = " << i << endl;
  }
}

int main() {
  thread t1(foo);
  thread t2(bar, 2);

  t1.join();
  t2.join();

  return 0;
}
