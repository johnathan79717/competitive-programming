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
using namespace std;
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define SZ(X) ((int)(X).size())
#define LEN(X) strlen(X)
#define FOR(i,c) for(auto &i: c)
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
#define BG begin()
#define ED end()
#define PQ priority_queue
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,-1,sizeof(x))
#define SEP(x) ((x)?'\n':' ')

typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long LL;
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
    DRI(N);
    VI p(N+1), l(N+1);
    VI prev(N+1);
    REP1(i, 1, N) {
        RII(p[i], l[i]);
    }
    vector<VI> query(N+1);
    VI xs, ys;
    CASET {
        DRII(x, y);
        xs.PB(x);
        ys.PB(y);
        query[x].PB(y);
    }
    BIT<int> bit(N);
    VI curr;
    curr.PB(N);
    VI a(N+1);
    map<pair<int,int>,int> ans;
    PER1(i, N-1, 1) {
        while (!curr.empty()) {
            int j = curr.back();
            if (p[i] + l[i] >= p[j] + l[j]) {
                curr.pop_back();
                bit.add(j, -a[j]);
                a[j] = 0;
            } else {
                break;
            }
        }
        if (!curr.empty()) {
            int j = curr.back();
            if (p[i] + l[i] < p[j]) {
                a[i] = p[j] - (p[i] + l[i]);
                bit.add(i, a[i]);
            }
        }
        curr.PB(i);
        FOR(y, query[i]) {
            int x = *lower_bound(ALL(curr), y, greater<int>()); // - curr.begin();
            // PIS(i); PIS(y); PI(bit.sum(x-1));
            ans[MP(i, y)] = bit.sum(x-1);
        }
    }
    REP(i, SZ(xs)) {
        PI(ans[MP(xs[i], ys[i])]);
    }
  return 0;
}
