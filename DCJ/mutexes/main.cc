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

#ifndef LOCAL
#include <message.h>
#endif
#include <unordered_set>
#include <unordered_map>
#define EB emplace_back
#define RL(x) scanf("%lld", &(x))
#define PL(x) printf("%lld\n", x)
#define DRL(x) LL x; RL(x)
#include "mutexes.h"

bool acquired[2][100005];
bool reachable[40004][404], valid[40004][404];
int N0, N1;
int repeat;

void exec(int x, int i, bool rev = false) {
    int op = GetOperation(x, i-1);
    if (rev) op *= -1;
    if (op > 0) {
        if (acquired[1-x][op]) {
            repeat++;
        }
        acquired[x][op] = true;
    } else {
        if (acquired[1-x][-op]) {
            repeat--;
        }
        acquired[x][-op] = false;
    }
}

bool isValid() {
    return repeat == 0;
}

#ifdef LOCAL
void Receive(int) {}
int GetInt(int) {}
char GetChar(int) {}
void Send(int) {}
void PutInt(int,int) {}
void PutChar(int,int) {}
#endif
#define LOG(format, args...) fprintf(stderr, format, ##args)
//#define LOG(x...)

int main() {
    N0 = NumberOfOperations(0), N1 = NumberOfOperations(1);
    int M = NumberOfNodes(), id = MyNodeId();
    //DRI(T);
    int B = (N1+M-1) / M;
    LOG("B = \n");
    REP1(j, 0, B) reachable[0][j] = true;
    if (id == 0) {
        REP1(i, 0, N0) reachable[i][0] = true;
    }
    REP1(j, 1, id * B) {
        if (j > N1) break;
        exec(1, j);
    }
    REP1(i, 1, N0) {
        exec(0, i);
        //PI(repeat);
        int J = 0;
        REP1(j, 1, B+1) {
            if (id * B + j > N1) break;
            J = j;
            exec(1, id*B+j);
            valid[i][j] = isValid();
            //LOG("valid[%d][%d] = %d\n", i, id*B+j, valid[i][j]);
        }
        PER1(j, J, 1) {
            exec(1, id*B+j, true);
        }
        //PI(repeat);
    }

    int ans = INF;
    REP1(i, 1, N0) {
        if (id > 0 && (i-1) % B == 0) {
            Receive(id - 1);
            REP1(k, i, min(N0, i+B-1)) {
                reachable[k][0] = GetChar(id-1);
                //cerr << "Receive: " << k << endl;
            }
        }
        REP1(j, 1, B) {
            reachable[i][j] = (reachable[i-1][j] || reachable[i][j-1]) && valid[i][j];
            if (i < N0 && id*B+j < N1 && reachable[i][j] && !valid[i+1][j] && !valid[i][j+1]) {
                //if (ans > 4 && i + j + id*B == 4) {
                    //cerr << i << ' ' << j + id*B << endl;
                //}
                ans = min(ans, i + j + id * B);
            }
            //fprintf(stderr, "reachable[%d][%d] = %d\n", i, id*B+j, reachable[i][j]);
        }
        if (id+1<M) {
            PutChar(id+1, reachable[i][B]);
            //cerr << "Send: " << i << endl;
            if (i % B == 0 || i == N0) {
                Send(id+1);
            }
        }
    }

    if (id) {
        PutInt(0, ans);
        Send(0);
    } else {
        REP1(i, 1, M-1) {
            Receive(i);
            ans = min(ans, GetInt(i));
        }
        if (ans == INF) puts("OK");
        else PI(ans+2);
    }
    return 0;
}
