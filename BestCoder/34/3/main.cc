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
#include <deque>
#include <cassert>
#include <stack>
using namespace std;
#define FOR(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define ALL(x) (x).begin(),(x).end()
#define CASET1 int ___T, case_n = 1; scanf("%d ", &___T); while ((___T > 0 ? printf("Case #%d: ", case_n++) : 0), ___T-- > 0)
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define SZ(X) ((int)(X).size())
#define LEN(X) strlen(X)
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define REPL(i,x) for(int i=0;x[i];i++)
#define PER(i,n) for(int i=(n)-1;i>=0;i--)
#define PER1(i,a,b) for(int i=(a);i>=(b);i--)
#define RI1(x) scanf("%d",&x)
#define RI2(x,y) RI1(x), RI1(y)
#define RI3(x,y,z) RI1(x), RI2(y, z)
#define GET_MACRO(_1, _2, _3, NAME, ...) NAME
#define RI(argv...) GET_MACRO(argv, RI3, RI2, RI1)(argv)
#define DRI(argv...) int argv; RI(argv)
#define RIL(argv...) while (RI(argv) != EOF)
#define DRIL(argv...) int argv; RIL(argv)
#define RS(x) scanf("%s",x)
#define PI(x) printf("%d\n",x)
#define PIS(x) printf("%d ",x)
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,-1,sizeof(x))
#define F first
#define S second
#define V(x) vector<x >

typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long LL;
const int INF = 1000000000;

// index starts with 1
template<class T>
class BIT {
public:
  vector<T> bit;
  BIT() {}
  BIT(int n): bit(n+1) {}
  T sum(int i) {
    assert(i >= 0);
    if (i >= bit.size()) {
        return sum(bit.size() - 1);
    }
    T s = 0;
    while(i > 0) {
      s += bit.at(i);
      i &= i - 1;
    }
    return s;
  }
  void add(int i, T x) {
    assert(i > 0 && i < bit.size());
    while(i < bit.size()) {
      bit.at(i) += x;
      i += i & -i;
    }
  }
  void resize(int n) {
    bit.resize(n+1);
  }
};

LL sum, total;
BIT<LL> bit1, bit2;
int N, W, H;

LL check(LL avg) {
    if (avg >= 50005) {
        return avg * W - sum;
    }
    LL w1 = bit2.sum(avg+1), s1 = bit1.sum(avg+1);
    LL a1 = avg * w1 - s1;
    LL a2 = sum - s1 - avg * (W - w1);
    if (avg * W <= total)
        return max(a1, a2);
    else
        return 1e18;
}

int main() {
    RIL(N, W, H) {
        deque<int> A;
        REP(i, W) A.PB(0);
        total = 0;
        REP(i, N) {
            DRI(a);
            total += a;
            A.PB(a);
        }
        REP(i, W) A.PB(0);
        if (total < W * (LL)H) {
            PI(-1);
            continue;
        }
        int l = 0, r = W;
        sum = 0;
        pair<LL,LL> all = MP((LL)W * H, -H);
        bit1.bit = V(LL)(50005);
        bit2.bit = V(LL)(50005);
        bit2.add(1, W);
        while (r < SZ(A)) {
            bit2.add(A[r]+1, 1);
            bit1.add(A[r]+1, A[r]);
            bit2.add(A[l]+1, -1);
            bit1.add(A[l]+1, -A[l]);
            sum += A[r] - A[l];
            r++;
            l++;
            pair<LL, LL> ans = MP(check(H), -H);
            if (sum / W >= H) {
                ans = min(ans, MP(check(sum / W), -(sum / W)));
            }
            if (sum / W + 1 >= H) {
                ans = min(ans, MP(check(sum / W + 1), -(sum / W + 1)));
            }
            all = min(all, ans);
        }
        assert(-all.S >= H);
        cout << -all.S << ' ' << all.F << '\n';
    }
    return 0;
}
