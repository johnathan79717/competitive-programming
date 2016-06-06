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
#include "shhhh.h"
#ifdef LOCAL
int Receive(int) {}
int GetInt(int) {}
char GetChar(int) {}
LL GetLL(int) {}
void Send(int) {}
void PutInt(int,int) {}
void PutChar(int,char) {}
void PutLL(int,LL) {}
int NumberOfNodes() { return 1; }
int MyNodeId() { return 0; }
#else
#include <message.h>
#endif

#define LOG(x, ...) fprintf(stderr, x, ##__VA_ARGS__)
//#define LOG(x...)

int main() {
    int M = NumberOfNodes(), id = MyNodeId();
    int N = GetN();
    if (id == 0) {
        int P = min(N, static_cast<int>(M * log2(M)));
        REP1(j, 1, M-1) {
            PutInt(j, P);
        }
        set<int> s = {0, 1};
        REP(i, P-2) {
            int x = rand() % N;
            while (s.count(x)) {
                x = rand() % N;
            }
            s.insert(x);
            REP1(j, 1, M-1) {
                PutInt(j, x);
            }
        }
        REP1(j, 1, M-1) {
            Send(j);
        }
        queue<int> idle;
        REP1(j, 1, M-1) idle.push(j);
        map<int,int> next;
        map<int,int> len;
        int p = 0;
        auto receive = [&]() {
            int worker = Receive(-1);
            p++;
            int xx = GetInt(worker);
            int yy = GetInt(worker);
            int dd = GetInt(worker);
            next[xx] = yy;
            len[xx] = dd;
            return worker;
        };

        for (int x: s) {
            if (idle.empty()) {
                idle.push(receive());
            }
            int worker = idle.front();
            idle.pop();
            PutInt(worker, x);
            Send(worker);
        }
        while (p < P) {
            receive();
        }
        REP1(j, 1, M-1) {
            PutInt(j, -1);
            Send(j);
        }
        int ans = 0;
        int y = 0;
        while (y != 1) {
            ans += len[y];
            y = next[y];
        }
        if (ans < N - ans) {
            printf("RIGHT %d\n", ans);
        } else if (ans > N - ans) {
            printf("LEFT %d\n", N - ans);
        } else {
            printf("WHATEVER %d\n", ans);
        }
    } else {
        Receive(0);
        int P = GetInt(0);
        set<int> s = {0, 1};
        REP(i, P-2) {
            s.insert(GetInt(0));
        }
        while (true) {
            Receive(0);
            int x = GetInt(0);
            if (x < 0) break;
            int d = 0, y = x;
            do {
                d++;
                y = GetRightNeighbour(y);
            } while (!s.count(y));
            PutInt(0, x);
            PutInt(0, y);
            PutInt(0, d);
            Send(0);
        }
    }
    return 0;
}
