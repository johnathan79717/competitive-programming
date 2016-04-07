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
#ifdef ONLINE_JUDGE
  #define RL(x) scanf("%I64d",&x)
  #define PL(x) printf("%I64d\n",x)
  typedef __int64 LL;
#else
  #define RL(x) scanf("%lld",&x)
  #define PL(x) printf("%lld\n",x)
  typedef long long LL;
#endif
#define DRI(x) int x;RI(x)
#define DRL(x) LL x;RL(x)
#define RII(x,y) scanf("%d%d",&x,&y)
#define DRII(x,y) int x,y;RII(x,y)
#define RIII(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define DRIII(x,y,z) int x,y,z;RIII(x,y,z)
#define RS(x) scanf("%s",x)
#define PI(x) printf("%d\n",x)
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

typedef unsigned long long ULL;
const int INF = 1000000000;

// index starts with 1
template<class T>
class BIT {
  vector<T> bit;
public:
  BIT() {}
  BIT(int n): bit(n+1) {}
  T sum(int i) {
    i = min(i, (int)bit.size()-1);
    T s = 0;
    while(i > 0) {
      s += bit.at(i);
      i &= i - 1;
    }
    return s;
  }
  void add(int i, T x) {
    while(i < bit.size()) {
      bit.at(i) += x;
      i += i & -i;
    }
  }
  void resize(int n) {
    bit.resize(n+1);
  }
};

int main() {
  DRI(T);
  REP1(t, 1, T) {
    DRI(N);
    VI X(N), H(N), cnt(N);
    V(VI) mid(N);
    BIT<int> bit(100000);
    int prev = -1;
    REP(i, N) {
      RI(X[i]);
      RI(H[i]);
      if(H[i]) {
        if(prev < 0) {
          cnt[i] += i+1;
        } else {
          int j = i-1;
          cnt[i]++;
          while(j > prev && H[j] == 0 && abs(X[j]-X[i]) < abs(X[j]-X[prev])) {
            cnt[i]++;
            j--;
          }
          if(j > prev && H[j] == 0) {
            if(abs(X[j]-X[i]) == abs(X[j]-X[prev])) {
              mid[i].PB(prev);
              mid[prev].PB(i);
              bit.add(max(H[i], H[prev]), 1);
              j--;
            }
            while(X[j] >= X[prev] && H[j] == 0) {
              cnt[prev]++;
              j--;
            }
          }
        }
        prev = i;
      }
    }

    int j = N-1;
    int c = 0;
    while(H[j] == 0) {
      c++;
      j--;
    }
    cnt[j] += c;

    REP(i, N) {
      if(H[i])
        bit.add(H[i], cnt[i]);
    }

    printf("Case #%d:\n", t);
    DRI(K);
    while(K--) {
      char s[2];
      RS(s);
      if(s[0] == 'U') {
        DRII(L, V);
        bit.add(H[L], -cnt[L]);
        bit.add(V, cnt[L]);
        REP(i, mid[L].size()) {
          bit.add(max(H[L], H[mid[L][i]]), -1);
          bit.add(max(V, H[mid[L][i]]), 1);
        }
        H[L] = V;
      } else {
        DRI(R);
        PI(bit.sum(R));
      }
    }

  }
  return 0;
}
