#include <functional>
#include <list>
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
#include <stack>
#include <cassert>
using namespace std;
#define FOR(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define ALL(x) (x).begin(),(x).end()
#define CASET2 int ___T, case_n = 1; scanf("%d ", &___T); while ((___T > 0 ? printf("Case #%d:\n", case_n++) : 0), ___T-- > 0)
#define CASET1 int ___T, case_n = 1; scanf("%d ", &___T); while ((___T > 0 ? printf("Case #%d: ", case_n++) : 0), ___T-- > 0)
#define CASET int ___T; scanf("%d ", &___T); while (___T-- > 0)
#define SZ(X) ((int)(X).size())
#define LEN(X) strlen(X)
#define REP(i,n) for(int i=0;i<int(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=int(b);i++)
#define PER1(i,a,b) for(int i=(a);i>=(b);i--)
#define REPL(i,x) for(int i=0;x[i];i++)
#define PER(i,n) for(int i=(n)-1;i>=0;i--)
#define RI1(x) scanf("%d",&x)
#define RI2(x,y) RI1(x), RI1(y)
#define RI3(x,y...) RI1(x), RI2(y)
#define RI4(x,y...) RI1(x), RI3(y)
#define RI5(x,y...) RI1(x), RI4(y)
#define RI6(x,y...) RI1(x), RI5(y)
#define GET_MACRO(_1, _2, _3, _4, _5, _6, NAME, ...) NAME
#define RI(argv...) GET_MACRO(argv, RI6, RI5, RI4, RI3, RI2, RI1)(argv)
#define DRI(argv...) int argv;RI(argv)
#define WRI(argv...) while (RI(argv) != EOF)
#define DWRI(x...) int x; WRI(x)
#define RS(x) scanf("%s",x)
#define MP make_pair
#define PB push_back
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,-1,sizeof(x))
#define X first
#define Y second
#define V(x) vector<x >

typedef long double LD;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long LL;
const int INF = 1000000000;

void print(int i) { printf("%d", i); }
template<class T> void PI(T i) { print(i); puts(""); }
template<class T> void PIS(T i) { print(i); printf(" "); }

template<class T>
void PV(T const &v, int N) {
    REP(i, N) {
        print(v[i]);
        printf("%c", i == N-1 ? '\n' : ' ');
    }
}

template<class T> void PV(T const &v) { PV(v, SZ(v)); }

template<class T, class S> bool has_bit(T mask, S i) { return (mask >> i) & 1; }
long long shift(int i) { return 1ll << i; }

template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
int popcount(int x) { return __builtin_popcount(x); } 
int popcount(long long x) { return __builtin_popcountll(x); } 

#include <unordered_set>
#include <unordered_map>
#define EB emplace_back
#define RL(x) scanf("%lld", &(x))
#define PL(x) printf("%lld\n", x)
#define DRL(x) LL x; RL(x)

char C[20], J[20];
LL x, y;
pair<LL,pair<string,string>> ans;

void dfs1(int i, bool gt) {
    if (!C[i]) {
        if (gt)
            ans = min(ans, MP(x-y, MP(string(C), string(J))));
        else
            ans = min(ans, MP(y-x, MP(string(C), string(J))));
        return;
    }
    if (C[i] != '?' && J[i] != '?') {
        x = x * 10 + C[i]-'0';
        y = y * 10 + J[i]-'0';
        if (gt) {
            if (x < y) {
                x /= 10;
                y /= 10;
                return;
            }
        } else {
            if (x > y) {
                x /= 10;
                y /= 10;
                return;
            }
        }
        dfs1(i+1, gt);
        x /= 10;
        y /= 10;
        return;
    }
    if (x == y) {
        if (C[i] == '?' && J[i] == '?') {
            C[i] = '0'; J[i] = '0';
            x = x * 10;
            y = y * 10;
            dfs1(i+1, gt);
            if (gt) x++;
            else y++;
            (gt ? C[i] : J[i]) = '1';
            dfs1(i+1, gt);
            x /= 10;
            y /= 10;
            C[i] = '?';
            J[i] = '?';
        } else if (C[i] == '?') {
            C[i] = J[i];
            x = x * 10 + C[i] - '0';
            y = y * 10 + J[i] - '0';
            dfs1(i+1, gt);
            if (gt) {
                if (C[i] < '9') {
                    C[i]++;
                    x++;
                }
            } else {
                if (C[i] > '0') {
                    C[i]--;
                    x--;
                }
            }
            dfs1(i+1, gt);
            x /= 10;
            y /= 10;
            C[i] = '?';
        } else {
            assert(J[i] == '?');
            J[i] = C[i];
            x = x * 10 + C[i] - '0';
            y = y * 10 + J[i] - '0';
            dfs1(i+1, gt);
            if (gt) {
                if (J[i] > '0') {
                    J[i]--;
                    y--;
                }
            } else {
                if (J[i] < '9') {
                    J[i]++;
                    y++;
                }
            }
            dfs1(i+1, gt);
            x /= 10;
            y /= 10;
            J[i] = '?';
        }
    } else {
        if (gt) assert(x > y);
        else assert(x < y);
        bool c = false, j = false;
        if (C[i] == '?') {
            C[i] = (gt ? '0' : '9');
            c = true;
        }
        if (J[i] == '?') {
            J[i] = (gt ? '9' : '0');
            j = true;
        }
        x = x * 10 + C[i]-'0';
        y = y * 10 + J[i]-'0';
        
        dfs1(i+1, gt);
        x /= 10;
        y /= 10;

        if (c) C[i] = '?';
        if (j) J[i] = '?';
    }
}

int main() {
    DRI(T);
    REP1(t, 1, T) {
        ans.first = LLONG_MAX;
        printf("Case #%d: ", t);
        RS(C); RS(J);

        assert(!x && !y);
        dfs1(0, true);
        assert(!x && !y);
        dfs1(0, false);
        cout << ans.Y.X << ' ' << ans.Y.Y << endl;
    }
    return 0;
}
