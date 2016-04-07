#include <iostream>

using namespace std;

int main() {
  int a = 1;
  cout << "{1, ";
  for(int i = 1; i <= 3000000; ++i) {
    if(i % 1000 == 0)
      cout << a << ",";
    a = a * i % 3046201;
  }
  cout << "};" << endl;
}