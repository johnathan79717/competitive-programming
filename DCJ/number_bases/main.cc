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
#include "number_bases.h"
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

int main() {
    int M = NumberOfNodes(), id = MyNodeId();
    LL N = GetLength();
    bool put = false;
    for (LL i = N * id / M; i < N * (id+1) / M; i++) {
      LL x = GetDigitX(i), y = GetDigitY(i), z = GetDigitZ(i);
      if (x + y != z) {
        PutLL(0, x + y - z);
       //puts("PutLL 0");
        put = true;
        break;
      }
    }
    if (!put) {
      PutLL(0, 0);
      //puts("PutLL 0");
    }
    Send(0);
    LL b = 0;
    if (id == 0) {
      for (LL i = 0; i < M; i++) {
        Receive(i);
        if (b == 0) {
          b = GetLL(i);
        } else {
          GetLL(i);
        }
       //cout << "GetLL" << ' ' << i << ' ' << b << endl;
      }
      if (b == 0) {
        puts("NON-UNIQUE");
      } else if (b < 0) {
        puts("IMPOSSIBLE");
      }
      for (LL i = 0; i < M; i++) {
        PutLL(i, b);
        //printf("PutLL %lld\n", i);
        Send(i);
      }
    }
    Receive(0);
    b = GetLL(0);
    //puts("GetLL 0");
    //cout << "id" << endl;
    if (b <= 0) {
      return 0;
    }

    for (int carry : {0, 1}) {
      for (LL i = N * id / M; i < N * (id+1) / M; i++) {
        LL x = GetDigitX(i), y = GetDigitY(i), z = GetDigitZ(i);
        //cout << x << ' ' << y << ' ' << z << ' ' << carry << endl;
        if (x >= b || y >= b || z >= b) {
          carry = -1;
          break;
        } else if (x + y + carry == z) {
          carry = 0;
        } else if (x + y + carry == z + b) {
          carry = 1;
        } else {
          carry = -1;
          break;
        }
      }
      PutInt(0, carry);
      //cout << id << ' ' << carry << endl;
    }
    Send(0);

    if (id == 0) {
      int carry = 0;
      for (int i = 0; i < M; i++) {
        Receive(i);
        int c[2];
        c[0] = GetInt(i);
        c[1] = GetInt(i);
        carry = c[carry];
        if (carry < 0) {
          puts("IMPOSSIBLE");
          while (++i < M) {
              Receive(i);
          }
          return 0;
        }
      }
      if (carry) {
        puts("IMPOSSIBLE");
        return 0;
      }
      PL(b);
    }
    return 0;
}