#include <iostream>
using namespace std;
int main(int argc, char *argv[]) {
  int a[10];
  const int N = atoi(argv[1]);
  for(int i = 0; i < N; i++) {
    a[i] = 1;
  }
  bool brk = false, fail = false;
  unsigned long long ans = 0;
  while(!brk) {
    int prev = 0, cnt = 0;
    for(int i = 0; i < N; i++) {
      if(a[i] == prev) {
        cnt++;
        if(cnt > prev) {
          fail = true;
          break;
        }
      } else {
        prev = a[i];
        cnt = 1;
      }
    }
    if(!fail) {
      ans++;
    } else {
      // for(int i = N-1; i >= 0; i--) {
      //   cout << a[i];
      // }
      // puts("");
      fail = false;
    }
    for(int i = 0; i < N; i++) {
      if(a[i] < 9) {
        a[i]++;
        break;
      } else {
        a[i] = 1;
        if(i == N-1)
          brk = true;
      }
    }
  }
  cout << ans << endl;
}