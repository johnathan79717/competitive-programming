#include <iostream>
#include <cmath>

using namespace std;

double solve() {
  int N, X, Y;
  cin >> N >> X >> Y;
  if(X == 0 && Y == 0)
    return 1.0;
  if(Y == 0 && abs(X) == 2) {
    if(N == 1)
      return 0.0;
    if(N == 2)
      return 0.5;
    if(N == 3)
      return 0.75;
    else
      return 1.0;
  }
  if(Y == 1 && abs(X) == 1) {
    if(N <= 2)
      return 0.0;
    if(N == 3)
      return 0.25;
    if(N == 4)
      return 0.5;
    else
      return 1.0;
  }
  if(Y == 2 && X == 0) {
    if(N < 6)
      return 0.0;
    else
      return 1.0;
  }
  if(Y == 0 && abs(X) == 4) {
    if(N <= 6)
      return 0.0;
    if(N >= 11)
      return 1.0;
    return 1 - pow(0.5, N-6);
  }
  if(Y == 1 && abs(X) == 3) {
    if(N <= 7)
      return 0.0;
    if(N >= 12)
      return 1.0;
    if(N <= 10)
      return 1 - pow(0.5, N-6) - pow(0.5, N-6) * (N-6);
  }
  if(Y == 2 && abs(X) == 2) {
    if(N <= 8)
      return 0.0;
    if(N >= 13)
      return 1.0;
    else
      return 1 - pow(0.5, N-6) * (1 + N-6 + (N-6) * (N-7) / 2);
  }
  if(Y == 3 && abs(X) == 1) {
    if(N <= 9)
      return 0.0;
    if(N >= 14)
      return 1.0;
    else
      return 1 - pow(0.5, N-6) * (1 + N-6 + (N-6) * (N-7) / 2 + (N-6) * (N-7) * (N-8) / 6);
  }
  if(Y == 4 && X == 0)
    if(N >= 15)
      return 1.0;
    else return 0.0;
  if(Y == 0 && abs(X) == 6) {
    if(N <= 15)
      return 0.0;
    return 1 - pow(0.5, N-15);
  }
  if(Y == 1 && abs(X) == 5) {
    if(N <= 16)
      return 0.0;
    return 1 - pow(0.5, N-15) * (1 + N-15);
  }
  if(Y == 2 && abs(X) == 4) {
    if(N <= 17)
      return 0.0;
    return 1 - pow(0.5, N-15) * (1 + N-15 + (N-15) * (N-16) / 2);
  }
  if(Y == 3 && abs(X) == 3) {
    if(N <= 18)
      return 0.0;
    return 1 - pow(0.5, N-15) * (1 + N-15 + (N-15) * (N-16) / 2 + (N-15) * (N-16) * (N-17) / 6);
  }
  if(Y == 4 && abs(X) == 2) {
    if(N <= 19)
      return 0.0;
    return 1 - pow(0.5, N-15) * (1 + N-15 + (N-15) * (N-16) / 2 + (N-15) * (N-16) * (N-17) / 6 + (N-15) * (N-16) * (N-17) * (N-18) / 24);
  }
  return 0.0;
}

int main() {
  int T;
  cin >> T;
  for(int t = 1; t <= T; ++t) {
    cout << "Case #" << t << ": " << solve() << endl;
  }
}