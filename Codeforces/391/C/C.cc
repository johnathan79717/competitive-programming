// Create your own template by modifying this file!

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
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <stack>
#include <functional>
#include <cassert>
using namespace std;
#define FOR(i,c) for(auto &i: c)
#define SZ size()
#define ALL(x) (x).begin(),(x).end()
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define REPL(i,x) for(int i=0;x[i];i++)
#define PER(i,n) for(int i=(n)-1;i>=0;i--)
#define PER1(i,a,b) for(int i=(a);i>=(b);i--)
#define RI(x) scanf("%d",&x)
#define DRI(x) int x;RI(x)
#define RII(x,y) scanf("%d%d",&x,&y)
#define DRII(x,y) int x,y;RII(x,y)
#define RIII(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define DRIII(x,y,z) int x,y,z;RIII(x,y,z)
#define RS(x) scanf("%s",x)
#define PI(x) printf("%d\n",x)
#define PIS(x) printf("%d ",x)
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define LB lower_bound
#define UB upper_bound
#define BG begin()
#define ED end()
#define PQ priority_queue
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,-1,sizeof(x))
#define SEP(x) ((x)?'\n':' ')
#define V(x) vector<x >

typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long LL;
const int INF = 1000000000;

#define MOD 1000000007
inline int add(int a, int b, int mod=MOD) { return a + b < mod ? a + b : a + b - mod; }
inline void addBy(int &a, int b, int mod=MOD) { a = add(a, b, mod); }
inline int sub(int a, int b, int mod=MOD) { return a - b < 0 ? a - b + mod : a - b; }
inline void subBy(int &a, int b, int mod=MOD) { a = sub(a, b, mod); }
inline int mul(int a, int b, int mod=MOD) { return (LL)a * b % mod; }
inline void mulBy(int &a, int b, int mod=MOD) { a = mul(a, b, mod); }

struct Player
{
  int p, e, i;
  Player(int p, int e, int i): p(p), e(e), i(i) {}
  bool operator<(Player const &p2) const {
    return p > p2.p;
  }
};

int main() {
  DRII(n, k);
  k--;
  V(Player) v;
  REP(i, n) {
    DRII(p, e);
    v.EB(p, e, i);
  }
  sort(ALL(v));
  LL ans = LLONG_MAX;
  REP1(p1, v[k].p, v[k].p+2) {
    if(p1 > n) break;
    int i1 = k;
    LL ans1 = 0;
    while(i1 < n && v[i1].p >= p1-1) i1++;
    if(i1 - k > p1) continue;
    V(Player) v1;
    FOR(p, v)
      if(p.p == p1 || p.p == p1-1) v1.PB(p);
    sort(ALL(v1), [](const Player &p1, const Player &p2) {
      return p1.e < p2.e;
    });
    if(v1.size() < i1-k) continue;
    vector<bool> used(n);
    REP(i, i1-k) {
      ans1 += v1[i].e;
      used[v1[i].i] = true;
    }
    sort(ALL(v), [](const Player &p1, const Player &p2) {
      return p1.e < p2.e;
    });
    int j = 0;
    REP(i, p1 - i1 + k) {
      while(used[v[j].i]) j++;
      ans1 += v[j].e;
      j++;
    }
    ans = min(ans1, ans);
    sort(ALL(v));
  }
  if(ans < LLONG_MAX) printf("%I64d\n", ans);
  else puts("-1");
  return 0;
}
