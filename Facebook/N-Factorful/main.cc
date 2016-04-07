#include <iostream>

using namespace std;

#define MAX_B 10000005

int a, b, n;
bool isprime[MAX_B];
int factor[MAX_B];

int main() {
  memset(isprime, true, sizeof(isprime));
  isprime[0] = isprime[1] = false;
  for(int i = 2; i < MAX_B; i++)
    if(isprime[i]) {
      factor[i] = 1;
      for(int j = i+i; j < MAX_B; j+=i) {
        isprime[j] = false;
        factor[j]++;
      }
    }

  int T;
  cin >> T;
  while(T--) {
    cin >> a >> b >> n;
    int ans = 0;
    for(int i = a; i <= b; i++) {
      if(factor[i] == n)
        ans++;
    }
    cout << ans << endl;
  }
}