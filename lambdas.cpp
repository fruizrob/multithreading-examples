#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void forEach(const vector<int> values, void (*func)(int)){
  for(int value : values){
    func(value);
  }
}

int main(){
  vector<int> values = {1, 2, 3, 4 , 5};

  forEach(values, [](int value){  // Lambda function
    cout << "Value: " << value << endl;
  });

  cin.get();
}

