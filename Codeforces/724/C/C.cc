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
template<typename T>
using V = std::vector<T>;

#ifdef DEBUG
     #define debug(args...)            {dbg,args; cerr<<endl;}
#else
    #define debug(args...)              // Just strip off all debug tokens
#endif

struct debugger
{
    template<typename T> debugger& operator , (const T& v)
    {    
        cerr<<v<<" ";    
        return *this;    
    }
} dbg;

int u[100005], d[100005], l[100005], r[100005];
int main() 
{
  MS1(u); MS1(d); MS1(l); MS1(r);
  DRI(N, M, K);
  queue<int> q;
  q.push(0); q.push(0); q.push(0);
  while (q.size()) {
    int i = q.front(); q.pop();
    int j = q.front(); q.pop();
    int k = q.front(); q.pop();
    if (i == 0) {
      if (j <= N-1) {
        if (d[j] >= 0) continue;
        q.push(j); q.push(0); q.push(d[j] = k+1);
      } else {
        if (r[j-N+1] >= 0) continue;
        q.push(N-1); q.push(j-N+1); q.push(r[j-N+1] = k+1);
      }
      if (M-1-j <= N-1) {
        if (u[M-1-j] >= 0) continue;
        q.push(M-1-j); q.push(M-1); q.push(u[M-1-j] = k+1);
      } else {
        if (r[j+N-1] >= 0) continue;
        q.push(N-1); q.push(j+N-1); q.push(r[j+N-1] = k+1);
      }
    } else if (j == 0) {
      if (i <= M-1) {
        if (l[i] >= 0) continue;
        q.push(0); q.push(i); q.push(l[i] = k+1);
      } else {
        if (u[j-N+1] >= 0) continue;
        q.push(i-M+1); q.push(0); q.push(u[j-N+1] = k+1);
      }
      if (N-1-i <= M-1) {
        if (r[N-1-i] >= 0) continue;
        q.push(N-1); q.push(N-1-i); q.push(r[N-1-i] = k+1);
      } else {
        if (u[i+M-1] >= 0) continue;
        q.push(i+M-1); q.push(0); q.push(u[i+M-1] = k+1);
      }
    } else if (i == N-1) {
      if (j <= N-1) {
        if (d[N-1-i] >= 0) continue;
        q.push(N-1-j); q.push(0); q.push(d[N-1-j] = k+1);
      } else {
        if (l[j-N+1] >= 0) continue;
        q.push(N-1); q.push(j-N+1); q.push(l[j-N+1] = k+1);
      }
      if (M-1-j <= N-1) {
        if (u[N-M+j] >= 0) continue;
        q.push(N-1-(M-1-j)); q.push(M-1); q.push(u[N-M+j] = k+1);
      } else {
        if (l[j+N-1] >= 0) continue;
        q.push(N-1); q.push(j+N-1); q.push(l[j+N-1] = k+1);
      }
    } else {
      if (i <= M-1) {
        if (l[M-1-i] >= 0) continue;
        q.push(0); q.push(M-1-i); q.push(l[M-1-i] = k+1);
      } else {
        if (d[j-N+1] >= 0) continue;
        q.push(i-M+1); q.push(0); q.push(d[j-N+1] = k+1);
      }
      if (N-1-i <= M-1) {
        if (r[M-N+i] >= 0) continue;
        q.push(N-1); q.push(M-N+i); q.push(r[M-N+i] = k+1);
      } else {
        if (d[i+M-1] >= 0) continue;
        q.push(i+M-1); q.push(0); q.push(d[i+M-1] = k+1);
      }
    }
  }
  REP(i, K) {
    DRI(x, y);
    int d = min(x, y);
    int xx = x - d, yy = y - d;
  }
}

