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
#include <iomanip>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <cassert>
#include <deque>
#include <stack>
#include <functional>
#define X first
#define Y second
#define MAX(x, a) x = max(x, a)
#define MIN(x, a) x = min(x, a)
#define CASET int ___T; scanf("%d ", &___T); while (___T-- > 0)
#define SZ(X) ((int)(X).size())
#define LEN(X) strlen(X)
#define FOR(i,c) for(auto &i: c)
#define ALL(x) (x).begin(),(x).end()
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define REPL(i,x) for(int i=0;x[i];i++)
#define PER(i,n) for(int i=(n)-1;i>=0;i--)
#define PER1(i,a,b) for(int i=(a);i>=(b);i--)
#define RI1(x) scanf("%d",&x)
#define RI2(x,y) RI1(x), RI1(y)
#define RI3(x,y...) RI1(x), RI2(y)
#define RI4(x,y...) RI1(x), RI3(y)
#define RI5(x,y...) RI1(x), RI4(y)
#define RI6(x,y...) RI1(x), RI5(y)
#define GET_MACRO(_1, _2, _3, _4, _5, _6, NAME, ...) NAME
#define RI(argv...) GET_MACRO(argv, RI6, RI5, RI4, RI3, RI2, RI1)(argv)
#define DRI(argv...) int argv;RI(argv)
#define RS(x) scanf("%s",x)
#define PI(x) printf("%d\n",x)
#define PIS(x) printf("%d ",x)
#define DRL(x) LL x; RL(x)
#ifdef ONLINE_JUDGE
    #define PL(x) printf("%I64d\n",x)
    #define RL(x) scanf("%I64d\n",&x)
#else
    #define PL(x) printf("%lld\n",x)
    #define RL(x) scanf("%lld\n",&x)
#endif
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define BG begin()
#define ED end()
#define PQ priority_queue
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,-1,sizeof(x))
#define SEP(x) ((x)?'\n':' ')
#define DRA(A, N) VI A(N); REP(i, N) RI(A[i])
using namespace std;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long LL;
const int INF = 1000000000;
#define V(x) vector<x>

template<const int& (*f)(const int&, const int&)>
class SparseTable {
    V(VI) sparse_table;
public:
    template<typename T>
    SparseTable(int N, const T &A) : sparse_table(20, VI(N)) {
        REP(i, N) {
            sparse_table[0][i] = A[i];
        }
        int k = 1;
        while ((1 << k) <= N) {
            REP1(i, 0, N - (1 << k)) {
                sparse_table[k][i] = f(sparse_table[k-1][i], sparse_table[k-1][i+(1<<(k-1))]);
            }
            k++;
        }
    }
    int query(int l, int r) {
        assert(l <= r);
        int k = sizeof(int) * 8 - 1 - __builtin_clz(r+1-l);
        return f(sparse_table[k][l], sparse_table[k][r+1-(1<<k)]);
    }
};
int main() 
{
    DRI(N, K);
    VI vv(N), cc(N);
    REP(i, N) {
        RI(vv[i]);
        vv[i] *= 100;
    }
    REP(i, N) RI(cc[i]);
    SparseTable<max> v(N, vv);
    SparseTable<min> c(N, cc);
    VI A;
    REP(l, N) {
        int lb = l-1, ub = N;
        int ans = 0;
        while (ub - lb > 1) {
            int r = (ub + lb) / 2;
            int a = v.query(l, r), b = c.query(l, r);
            MAX(ans, min(a, b));
            if (a < b) {
                lb = r;
            } else if (a > b) {
                ub = r;
            } else {
                break;
            }
        }
        A.PB(ans);
    }
    sort(ALL(A), greater<int>());
    long double C = 1.0 * K / N;
    long double ans = 0;
    PER1(i, N-1, K-1) {
        ans += C * A[i];
        C = C / i * (i-K+1);
    }
    cout << fixed << setprecision(7) << ans << endl;
}

