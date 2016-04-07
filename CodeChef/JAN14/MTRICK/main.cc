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
using namespace std;
#define FOR(i,c) for(auto i=(c).begin();i!=(c).end();i++)
#define SZ size()
#define ALL(x) (x).begin(),(x).end()
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define REPL(i,x) for(int i=0;x[i];i++)
#define PER(i,n) for(int i=(n)-1;i>=0;i--)
#define PER1(i,a,b) for(int i=(a);i>=(b);i--)
#define RI(x) scanf("%d",&x)
#define RL(x) scanf("%lld",&x)
#define DRI(x) int x;RI(x)
#define DRL(x) LL x;RL(x)
#define RII(x,y) scanf("%d%d",&x,&y)
#define DRII(x,y) int x,y;RII(x,y)
#define RIII(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define DRIII(x,y,z) int x,y,z;RIII(x,y,z)
#define RS(x) scanf("%s",x)
#define PI(x) printf("%d\n",x)
#define PL(x) printf("%lld\n",x)
#define PIS(x) printf("%d ",x)
#define CASET int ___T,cas=1;scanf("%d ",&___T);while(___T--)
#define CASEN0(n) int cas=1;while(scanf("%d",&n)!=EOF&&n)
#define CASEN(n) int cas=1;while(scanf("%d",&n)!=EOF)
#define MP make_pair
#define PB push_back
#define PQ priority_queue
#define E emplace
#define EB emplace_back
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,-1,sizeof(x))
#define SEP(x) ((x)?'\n':' ')
#define F first
#define S second
#define V(x) vector<x >

typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long LL;
typedef unsigned long long ULL;
const int INF = 2000000000;

LL MOD;

inline LL add(LL a, LL b) { return (a + b) % MOD; }

LL mul(LL a,LL b){
  LL x = 0,y=a%MOD;
  while(b > 0){
    if(b%2 == 1){
      x = x+y;
      if(x >= MOD) x -= MOD;
    }
    y = (y*2)%MOD;
    if(y >= MOD) y -= MOD;
    b /= 2;
  }
  return x;
}

LL L[1001];
char S[1001];

int main() {
  DRI(T);
  while(T--) {
    DRI(N);
    REP(i, N) RL(L[i]);
    DRL(A); DRL(B); RL(MOD);
    RS(S);
    int head = 0, tail = N-1, dir = 1;
    LL a = 1, b = 0;
    REP(i, N) {
      if(S[i] == 'R') {
        swap(head, tail);
        dir = -dir;
      } else if(S[i] == 'A') {
        b = add(b, A);
      } else {
        a = mul(a, B);
        b = mul(b, B);
      }
      printf("%lld%c", add(mul(a, L[head]), b), SEP(i == N-1));
      head += dir;
    }
  }
  return 0;
}