#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
using namespace std;

#define MAX_PRIME 10000000

bool isprime[MAX_PRIME];

int ten[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000};

int d[9];
int main() {
  int N, K, L;
  cin >> N >> K >> L;
  memset(isprime, true, sizeof(isprime));
  isprime[0] = isprime[1] = false;
  for(int i = 2; i < MAX_PRIME; i++) {
    if(!isprime[i])
      continue;
    for(int j = i * 2; j < MAX_PRIME; j += i)
      isprime[j] = false;
  }
  if(N == K) {
    if(L == 1 && N == 2)
      puts("11");
    return 0;
  }

  vector<int> ans(L, 99999999);
  d[N-K-1] = 1;
  while(d[N-K-1]) {
    int comb = (1 << K) - 1;
    while (comb < 1 << N) {
      int p = 0, j = 0, diff = 0;
      for(int i = 0; i < N; i++) {
        if((comb >> i) & 1) {
          diff += ten[i];
        } else {
          p += d[j++] * ten[i];
        }
      }
      int cnt = 0;
      vector<int> temp;
      for(int l = 0; l < 10; l++) {
        if (p + diff * l >= ten[N-1] && isprime[p + diff * l]) {
          temp.push_back(p + diff * l);
        }
      }
      if (temp.size() >= L) {
        ans = min(ans, temp);
      }
      int x = comb & -comb, y = comb + x;
      comb = ((comb & ~y) / x >> 1) | y;
    }
    for(int i = 0; i < N-K; i++) {
      if(d[i] < 9) {
        d[i]++;
        break;
      } else {
        d[i] = 0;
      }
    }
  }
  for(int i = 0; i < L; i++)
    cout << ans[i] << ' ';
  puts("");
}