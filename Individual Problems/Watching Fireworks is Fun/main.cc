#include <iostream>
#include <climits>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;

LL dp[2][150001];

template <class T>
struct deque {
  T arr[150001];
  int s;
  int t;
  deque() : s(0), t(0) { memset(arr, 0, sizeof(arr)); }
  bool empty() { return s == t; }
  T &front() { return arr[s]; }
  T &back() { return arr[t-1]; }
  void pop_back() { --t; }
  void push_back(T val) { arr[t++] = val; }
  void pop_front() { ++s; }
};

int a[301], b[301], t[301];

int main() {
  int n, m, d;
  cin >> n >> m >> d;
  for(int i = 1; i <= m; i++)
    cin >> a[i] >> b[i] >> t[i];
  LL *curr = dp[0], *prev = dp[1];
  for(int i = 1; i <= m; i++) {
    swap(curr, prev);
    deque<LL> deq;
    int r = 1;
    LL dt = t[i] - t[i-1];
    for(int j = 1; j <= n; j++) {
      while(r <= n && r <= j + d * dt) {
        while(!deq.empty() && prev[deq.back()] <= prev[r])
          deq.pop_back();
        deq.push_back(r++);
      }
      while(deq.front() < j - d * dt)
        deq.pop_front();
      curr[j] = prev[deq.front()] + b[i] - abs(a[i] - j);
    }
  }
  LL ans = LLONG_MIN;
  for(int j = 1; j <= n; j++)
    ans = max(ans, curr[j]);
  cout << ans << endl;
}

/*
dp[i][j] = max(prev[j']) + b[i] - |a[i] - x|;
j' = {j - td, ... j + td};


 */