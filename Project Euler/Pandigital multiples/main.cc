#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

int cnt[10];

int each(int n) {
  int len = 0;
  while(n) {
    cnt[n%10]++;
    n /= 10;
    len++;
  }
  return len;
}

int check(int n, int K) {
  int len = 0, i = 1;
  int ans = 0;
  memset(cnt, 0, sizeof cnt);
  while(len < K) {
    int l = each(n*i);
    len += l;
    ans = pow(10, l) * ans + n*i;
    i++;
  }
  if(len > K) return 0;
  for(int i = 1; i <= K; i++) {
    if(cnt[i] != 1)
      return 0;
  }
  cout << n << endl;
  return ans;
}

int main() {
  int N, K;
  cin >> N >> K;
  // cout << *(lower_bound(arr.begin(), arr.end(), N)-1) << endl;
  
  // vector<int> arr;
  for(int i = 9; i < N; i++) {
    int c = check(i, K);
    // if(c) {
    //   arr.push_back(c);
    //   // cout << c << endl;
    // }
  }
  // sort(arr.begin(), arr.end());
}