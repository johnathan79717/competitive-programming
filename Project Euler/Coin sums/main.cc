#include <iostream>

using namespace std;

const int MOD = 1000000007;
struct Z {
  int i;
  Z():i(0) {}
  Z(int i): i(i >= 0 ? i : i + MOD) {}
  void operator +=(const Z& z) { i += z.i; if(i >= MOD) i -= MOD; }
  Z operator +(const Z& z) const { Z ret(i); ret += z; return ret; }
};

int main() {
  const int MAX_N = 100000;
  Z ans[MAX_N+1];
  memset(ans, 0, sizeof(ans));
  int coin[] = {1, 2, 5, 10, 20, 50, 100, 200};
  ans[0] = 1;
  for(int i = 0; i < 8; ++i) {
    const int c = coin[i];
    for(int j = c; j <= MAX_N; ++j)
      ans[j] += ans[j-c];
  }
  int T;
  cin >> T;
  while(T--) {
    int N;
    cin >> N;
    printf("%d\n", ans[N].i);
  }
}