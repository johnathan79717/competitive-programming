#include <cstdio>
#include <stack>

using namespace std;

#define P 1000000007

int main() {
  int N, K;
  scanf("%d%d", &N, &K);

  stack<pair<int, int> > s;
  long long ans = 1;
  for(int i = 0; i < N; i++) {
    int A;
    scanf("%d", &A);

    while(!s.empty() && s.top().first > A) {
      ans = ans * (i - s.top().second + 1) % P;
      s.pop();
    }
    s.push(make_pair(A, i));
  }
  printf("%lld\n", ans);
}