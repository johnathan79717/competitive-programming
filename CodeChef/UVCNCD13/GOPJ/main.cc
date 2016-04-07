#include <iostream>

using namespace std;

int step[2001];

int solve() {
  int N, B;
  cin >> N >> B;
  if(B == 0)
    return step[N];

  for(int i = 0; i <= N; i++)
    if(step[i] == B)
      return step[N] - 1;

  return step[N];
}

int main() {
  int T;
  cin >> T;
  step[0] = 0;
  for(int i = 1; i < 2001; i++)
    step[i] = step[i-1] + i;
  while(T--) {
    cout << solve() << endl;
  }
}