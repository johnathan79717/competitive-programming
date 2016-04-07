#include <cstdio>
#include <climits>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

bool smaller(vi &a, vi &b) {
  for(int i = 0; i < a.size(); i++)
    if(a[i] > b[i])
      return false;

  return true;
}

int main() {
  int T;
  scanf("%d", &T);
  while(T--) {
    int N, K;
    scanf("%d%d", &N, &K);
    vector<vi> vs(N, vi(K));
    vi A(K);
    for(auto &v : vs)
      for(auto &x : v)
        scanf("%d", &x);

    for(auto &x : A)
      scanf("%d", &x);

    ll bestSum = LLONG_MAX;
    int bestI;
    for(int i = 0; i < N; i++) {
      auto &v = vs[i];
      ll sum = 0;
      if(!smaller(v, A))
        continue;
      for(int j = 0; j < K; j++)
        sum += A[j] - v[j];
      if(sum < bestSum) {
        bestSum = sum;
        bestI = i;
      }
    }
    if(bestSum == LLONG_MAX)
      puts("0");
    else
      printf("1\n%d\n", bestI+1);
  }
}