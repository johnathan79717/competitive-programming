#include <iostream>
#include <cstring>
using namespace std;
int main() {
  cout << "30000 29999" << endl;
  for(int i = 1; i < 30000; i++)
    cout << i << ' ' << i+1 << endl;
}