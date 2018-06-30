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
#include "broken_memory.h"
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

#define LOG(x, ...) fprintf(stderr, x, ##__VA_ARGS__)
//#define LOG(x...)
template <class T>
inline void hash_combine(std::size_t& seed, const T& v)
{
    std::hash<T> hasher;
    seed ^= hasher(v) + 0x9e3779b9 + (seed<<6) + (seed>>2);
}

int main() {
    int M = NumberOfNodes(), id = MyNodeId();
    int N = GetLength();
    hash<LL> hasher;
    int other = id ^ 1;
    queue<int> intervals;
    intervals.push(0);
    intervals.push(N);
    VI ans;
    while (SZ(intervals)) {
        int l = intervals.front();
        intervals.pop();
        int r = intervals.front();
        intervals.pop();
        size_t h = 0;
        for (int i = l; i < r; i++) {
            size_t h2 = 0;
            hash_combine(h2, i+1);
            hash_combine(h2, GetValue(i));
            hash_combine(h, h2);
        }
        PutLL(other, h);
        Send(other);
        Receive(other);
        LL g = GetLL(other);
        if (h != g) {
            if (r - l == 1) {
                ans.PB(l);
            } else {
                int m = l + (r - l) / 2;
                intervals.push(l);
                intervals.push(m);
                intervals.push(m);
                intervals.push(r);
            }
        }
    }
    assert(SZ(ans) == 2);
    if (id % 2 == 0) {
        assert(SZ(ans) == 2);
        int another = (id + 2) % M;
        PutInt(another, ans[0]);
        PutLL(another, GetValue(ans[0]));
        PutInt(another, ans[1]);
        PutLL(another, GetValue(ans[1]));
        Send(another);
        int id1 = (id + M - 2) % M, id2 = id1 + 1;
        Receive(id1);
        int i1 = GetInt(id1), v1 = GetLL(id1);
        int i2 = GetInt(id1), v2 = GetLL(id1);
        PutInt(0, id1);
        PutInt(0, id2);
        if (GetValue(i1) == v1) {
            PutInt(0, i2);
            PutInt(0, i1);
        } else {
            PutInt(0, i1);
            PutInt(0, i2);
        }
        Send(0);
    }
    if (id == 0) {
        ans = VI(M);
        for (int i = 0; i < M; i += 2) {
            Receive(i);
            int id1 = GetInt(i), id2 = GetInt(i);
            ans[id1] = GetInt(i);
            ans[id2] = GetInt(i);
        }
        PV(ans);
    }
    return 0;
}
