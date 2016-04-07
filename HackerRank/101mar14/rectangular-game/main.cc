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
#include <stack>
#include <deque>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
using namespace std;
#define FOR(i,c) for(auto &i: c)
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

#define MOD 1000000007
inline int add(int a, int b, int mod=MOD) { return a + b < mod ? a + b : a + b - mod; }
inline void addBy(int &a, int b, int mod=MOD) { a = add(a, b, mod); }
inline int sub(int a, int b, int mod=MOD) { return a - b < 0 ? a - b + mod : a - b; }
inline void subBy(int &a, int b, int mod=MOD) { a = sub(a, b, mod); }
inline int mul(int a, int b, int mod=MOD) { return (LL)a * b % mod; }
inline void mulBy(int &a, int b, int mod=MOD) { a = mul(a, b, mod); }


int main() {
  DRI(T);
  int m = INF, M = INF;
  while(T--) {
    DRII(a, b);
    m = min(m, a);
    M = min(M, b);
  }
  cout << (LL) m * M << endl;
  return 0;
}