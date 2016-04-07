#include <string>
#include <vector>
#include <climits>
#include <cstring>
#include <map>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <stack>
#include <deque>
#include <list>
#include <set>
#include <unordered_set>
#include <cassert>
using namespace std;
#define BG begin()
#define ED end()
#define FOR(i,c) for(auto &i: c)
#define SZ size()
#define ALL(x) (x).begin(),(x).end()
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define REPL(i,x) for(int i=0;x[i];i++)
#define PER(i,n) for(int i=(n)-1;i>=0;i--)
#define PER1(i,a,b) for(int i=(a);i>=(b);i--)
#define RI(x) scanf("%d",&x)
#define RL(x) scanf("%lld",&x)
#define DRI(x) int x;RI(x)
#define DRL(x) LL x;RL(x)
#define RII(x,y) scanf("%d%d",&x,&y)
#define DRII(x,y) int x,y;RII(x,y)
#define RIII(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define DRIII(x,y,z) int x,y,z;RIII(x,y,z)
#define RS(x) scanf("%s",x)
#define PI(x) printf("%d\n",x)
#define PL(x) printf("%lld\n",x)
#define PIS(x) printf("%d ",x)
#define MP make_pair
#define PB push_back
#define PQ priority_queue
#define E emplace
#define EB emplace_back
#define LB lower_bound
#define UB upper_bound
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,-1,sizeof(x))
#define SEP(x) ((x)?'\n':' ')
#define F first
#define S second
#define V(x) vector<x >

typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long LL;
typedef unsigned long long ULL;
const int INF = 1000000000;

int value(const map<VI, int>& a) {
  FOR(choice, a) {
    const VI &ps = choice.first;
    if(ps.size() == 1) {
      int cnt = 0;
      FOR(pr, a)
        if(count(ALL(pr.first), ps[0]))
          cnt += pr.second;
      if(cnt % 2) return 1;
    } else if(ps.size() > 1) {
      map<VI, int> temp;
      FOR(pr2, a) {
        VI t;
        FOR(p, ps)
          if(count(ALL(pr2.first), p))
            t.PB(p);
        if(!t.empty())
          temp[t] += pr2.second;
      }
      temp[ps]--;
      if(temp[ps] == 0) temp.erase(ps);
      if(value(temp) == 0) return 1;
    }
  }
  return 0;
}

long double C[101][101];

int main() {
  REP(i, 101) {
    C[i][0] = 1;
    REP(j, i) {
      C[i][j+1] = C[i-1][j+1] + C[i-1][j];
    }
  }
  DRI(T);
  REP(t, T) {
    DRI(n);
    map<VI, int> as;
    map<VI, int> bs;
    REP(i, n) {
      DRI(a);
      VI ai;
      REP1(p, 2, 7) {
        if(a % p == 0) {
          ai.PB(p);
          do {
            a /= p;
          } while(a % p == 0);
        }
      }
      if(a > 1) ai.PB(a);
      if(!ai.empty()) {
        as[ai]++;
        bs[ai]++;
      }
      if(ai.size() == 2) {
        bs[VI({ai[0]})]++;
        bs[VI({ai[1]})]++;
      }
      if(ai.size() == 3) {
        bs[VI({ai[0]})]++;
        bs[VI({ai[1]})]++;
        bs[VI({ai[2]})]++;
        bs[VI({ai[0], ai[1]})]++;
        bs[VI({ai[1], ai[2]})]++;
        bs[VI({ai[0], ai[2]})]++;
      }
    }
    PIS(value(as));
    long double ans = 0;
    REP1(k, 1, n) {
      long double prob = 0;
      FOR(pr, bs) {
        int m = pr.second;
        if(pr.first.size() % 2)
          prob += C[m][k]/C[n][k];
        else
          prob -= C[m][k]/C[n][k];
      }
      if(k % 2)
        ans += prob;
      else
        ans -= prob;
    }
    printf("%.4LF\n", ans);
  }
  return 0;
}
