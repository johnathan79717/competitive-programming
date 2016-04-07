#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <cmath>
using namespace std;

int K;
double ps, pr, pi, tpu, pw, tpd, pl;
int pu, pd;
double dp[101][101][1001];

double solve(int w, int l, int p) {
  if(p > 1000) p = 1000;
  if(p < 0) p = 0;
  if(dp[w][l][p] >= 0)
    return dp[w][l][p];
  if(w == K)
    return dp[w][l][p] = 1;
  if(l == K)
    return dp[w][l][p] = 0;
  double pWin = pw * solve(w+1, l, p + pu) + (1-pw) * solve(w+1, l, p);
  double pLose = pl * solve(w, l+1, p - pd) + (1-pl) * solve(w, l+1, p);
  return dp[w][l][p] = ((p * ps + (1000-p) * pr) * pWin + (p * (1-ps) + (1000-p) * (1-pr)) * pLose) / 1000;
}

int main() {
  int T, cas = 1;
  scanf("%d", &T);
  while(T--) {
    scanf("%d%lf%lf%lf%lf%lf%lf%lf", &K, &ps, &pr, &pi, &tpu, &pw, &tpd, &pl);
    for(int i = 0; i <= K; i++)
      for(int j = 0; j <= K; j++)
        fill(dp[i][j], dp[i][j] + 1001, -1);
    pu = round(tpu * 1000);
    pd = round(tpd * 1000);
    printf("Case #%d: %.6lf\n", cas++, solve(0, 0, round(pi * 1000)));
  }
}