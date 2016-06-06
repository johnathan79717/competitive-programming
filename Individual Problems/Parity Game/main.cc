#include <cstring>
#include <iostream>
using namespace std;

int main() {
  char a[1001], b[1001];
  cin >> a >> b;
  int num0a = 0, num0b = 0;
  for(int i = 0; i < strlen(a); ++i)
    if(a[i] == '1')
      ++num0a;
  for(int i = 0; i < strlen(b); ++i)
    if(b[i] == '1')
      ++num0b;

  if(num0a % 2 == 1)
    ++num0a;

  if(num0a >= num0b)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}