#include <iostream>
#include <map>
#include <cstring>
using namespace std;

int main() {
  int N, Q;
  cin >> N >> Q;
  int A[100000];
  int i;
  for(i = 0; i < N; i++)
    cin >> A[i];
  int L[100000], R[100000], K[100000];
  multimap<int, int> query;
  for(i = 0; i < Q; i++) {
    cin >> L[i] >> R[i] >> K[i];
    L[i]--;
    R[i]--;
    query.insert(make_pair(L[i] - 1, K[i]));
    query.insert(make_pair(R[i], K[i]));
  }
  int cnt[100001];
  memset(cnt, 0, sizeof(cnt));
  map<pair<int, int>, int> mp;
  for(i = 0; i < N; i++) {
    for(int p = 1; p * p <= A[i]; p++) {
      if(A[i] % p == 0) {
        cnt[p]++;
        if(p * p < A[i])
          cnt[A[i] / p]++;
      }
    }
    multimap<int, int>::iterator it = query.lower_bound(i);
    while(it->first == i) {
      mp[*it] = cnt[it->second];
      it++;
    }
  }
  for(i = 0; i < Q; i++)
    cout << mp[make_pair(R[i], K[i])] - mp[make_pair(L[i] - 1, K[i])] << endl;
}