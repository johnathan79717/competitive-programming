#include <iostream>

using namespace std;

int t[200010], n[200010], B;
#define MOD 1000000007
// 快速求出最低位的bit。這是其中一種方式。
int lower_bit(int n)
{
    return n & -n;
}
 
// value[1] + value[2] + ... + value[n]
int sum(int n)
{
    int s = 0;
    while (n > 0)
    {
        (s += t[n]) %= MOD;
        n -= lower_bit(n);
    }
    return s;
}
 
// value[n] += d
void add(int n, int d)
{
    while (n <= B)
    {
        (t[n] += d) %= MOD;
        n += lower_bit(n);
    }
}
 
// value[a] + value[a+1] + ... + value[b]
int query(int a, int b)
{
    // if (a > b) swap(a, b);
    return (sum(b) - sum(a-1) + MOD) % MOD;
}

int main() {
  int N;
  cin >> N >> B;

  for(int i = 1; i <= N; i++)
    cin >> n[i];

  add(B, 1);
  for(int i = B-1; i >= 1; i--) {
    add(i, query(i+1, min(B, i+n[i])));
  }

  int Q;
  cin >> Q;
  for(int i = 0; i < Q; i++) {
    int S;
    cin >> S;
    cout << query(S, S) << endl;
  }
}