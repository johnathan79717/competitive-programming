#include <iostream>

using namespace std;

int fact[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
int tbl[22000000];

int sumOfFact(int n) {
  if(n < 10)
    return fact[n];
  else
    return sumOfFact(n/10) + fact[n % 10];
}

int chain(int n) {
  if(tbl[n])
    return tbl[n];
  else
    return tbl[n] = 1 + chain(sumOfFact(n));
}

int main() {
  tbl[1] = tbl[2] = tbl[145] = tbl[40585] = 1;
  tbl[169] = tbl[363601] = tbl[1454] = 3;
  tbl[871] = tbl[45361] = tbl[872] = tbl[45362] = 2;
  int ans = 0;
  for(int i = 0; i < 1000000; i++)
    if(chain(i) == 60)
      ans++;
  cout << ans << endl;
}