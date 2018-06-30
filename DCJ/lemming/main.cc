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
void print(LL i);
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
#ifdef LOCAL
void Receive(int) {}
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
//#define DEBUG

void receive(int i) {
    Receive(i);
#ifdef DEBUG
    //cout << "receive from " << i << endl;
#endif
}

void send(int i) {
    Send(i);
#ifdef DEBUG
    //cout << "send to " << i << endl;
#endif
}

int getInt(int i) {
    int x = GetInt(i);
#ifdef DEBUG
    cout << "getInt " << x << " from " << i << endl; 
#endif
    return x;
}
char getChar(int i) {
    char c = GetChar(i);
#ifdef DEBUG
    cout << "getChar " << c << " from " << i << endl;
#endif
    return c;
}
LL getLL(int i) {
    LL x = GetLL(i);
#ifdef DEBUG
    cout << "getLL " << x << " from " << i << endl; 
#endif
    return x;
}
void putInt(int i, int x) {
    PutInt(i, x);
#ifdef DEBUG
    cout << "putInt " << x << " to " << i << endl;
#endif
}
void putChar(int i, char c) {
    PutChar(i, c);
#ifdef DEBUG
    cout << "putChar " << c << " to " << i << endl;
#endif
}
void putLL(int i, LL x) {
    PutLL(i, x);
#ifdef DEBUG
    cout << "putLL " << x << " to " << i << endl;
#endif
}

#include "lemming.h"

#define LOG(x, ...) fprintf(stderr, x, ##__VA_ARGS__)
//#define LOG(x...)

int main() {
    int M = NumberOfNodes(), id = MyNodeId();
    LL R = GetRows(), C = GetColumns();
    LL lb = R * id / M, ub = R * (id + 1) / M - 1;
    V(VI) path(ub - lb + 1, VI(C, -1));
    V(PII) endPoints;
    int p = 0;
    int out = 0, cycle = 0;
    REP1(i, lb, ub) {
        REP(j, C) {
            int x = i, y = j;
            while (true) {
                if (x < 0 || x >= R || y < 0 || y >= C) {
                    out++;
                    endPoints.EB(-1, -1);
                    break;
                }
                if (x < lb || x > ub) {
                    endPoints.EB(x, y);
                    break;
                }
                if (path[x-lb][y] == p) {
                    cycle++;
                    endPoints.EB(-1, -1);
                    break;
                }
                if (path[x-lb][y] >= 0) {
                    endPoints.EB(endPoints[path[x-lb][y]]);
                    break;
                }
                path[x-lb][y] = p;
                switch (GetDirection(x, y)) {
                    case '>': y++; break;
                    case '<': y--; break;
                    case 'v': x++; break;
                    case '^': x--; break;
                }
            }
            if (i == lb || i == ub) {
                if (endPoints[path[i-lb][j]] != MP(-1, -1)) {
                    putInt(0, i);
                    putInt(0, j);
                    putInt(0, endPoints[path[i-lb][j]].X);
                    putInt(0, endPoints[path[i-lb][j]].Y);
                }
            }
            if (path[i-lb][j] == p) {
                p++;
            }
        }
    }
    putInt(0, -1);
    putInt(0, out + cycle);
    send(0);
    if (id == 0) {
        unordered_map<int, int> rowId;
        int r = 0;
        REP(m, M) {
            lb = R * m / M, ub = R * (m+1) / M - 1;
            if (lb <= ub) {
                rowId[lb] = r++;
            }
            if (ub > lb) {
                rowId[ub] = r++;
            }
        }
        path = V(VI)(r, VI(C, -1));
        V(V(PII)) adj(r, V(PII)(C, MP(-1, -1)));
        LL ans = 0;
        REP(m, M) {
            receive(m);
            while (true) {
                int i = getInt(m);
                if (i < 0) {
                    break;
                }
                int j = getInt(m), x = getInt(m), y = getInt(m);
                adj[rowId[i]][j] = MP(rowId[x], y);
                //cout << rowId[i] << ' ' << j << ' ' << rowId[x] << ' ' << y << endl;
            }
            ans += getInt(m);
        }
        p = 0;
        REP(i, r) {
            REP(j, C) {
                if (adj[i][j].X < 0) continue;
                if (path[i][j] >= 0) continue;
                int x = i, y = j;
                while (true) {
                    if (path[x][y] == p) {
                        ans++;
                        break;
                    }
                    if (path[x][y] >= 0) {
                        break;
                    }
                    auto &pr = adj[x][y];
                    if (pr.X < 0) {
                        break;
                    }
                    path[x][y] = p;
                    x = pr.X, y = pr.Y;
                }
                p++;
                //cout << i << ' ' << j << ' ' << ans << endl;
            }
        }
        PL(ans);
    }
    return 0;
}
