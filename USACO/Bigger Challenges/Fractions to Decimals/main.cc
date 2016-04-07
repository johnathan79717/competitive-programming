/*
ID: johnath2
PROG: fracdec
LANG: C++
*/
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
#define NAME "fracdec"
#define FOR(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define REPL(i,x) for(int i=0;x[i];i++)
#define PER(i,n) for(int i=(n)-1;i>=0;i--)
#define PER1(i,a,b) for(int i=(a);i>=(b);i--)
#define RI(x) scanf("%d",&x)
#define DRI(x) int x;RI(x)
#define RII(x,y) scanf("%d%d",&x,&y)
#define DRII(x,y) int x,y;RII(x,y)
#define RIII(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define DRIII(x,y,z) int x,y,z;RIII(x,y,z)
#define RS(x) scanf("%s",x)
#define PI(x) printf("%d\n",x)
#define PIS(x) printf("%d ",x)
#define CASET int ___T,cas=1;scanf("%d ",&___T);while(___T--)
#define CASEN0(n) int cas=1;while(scanf("%d",&n)!=EOF&&n)
#define CASEN(n) int cas=1;while(scanf("%d",&n)!=EOF)
#define MP make_pair
#define PB push_back
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,-1,sizeof(x))
#define SEP(x) ((x)?'\n':' ')
#define F first
#define S second
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long LL;
typedef unsigned long long ULL;
const int MOD = 1000000007;
const int INF = 1000000000;
inline int add(int a, int b) { return a + b < MOD ? a + b : a + b - MOD; }
inline int sub(int a, int b) { return a - b < 0 ? a - b + MOD : a - b; }
inline int mul(int a, int b) { return (LL)a * b % MOD; }
#define MAX_QUEUE 10000000
template<class T>
struct Queue {
  T arr[MAX_QUEUE];
  int f, b;
  Queue() : f(0), b(0) {}
  void push(const T& val) { arr[b++] = val; }
  bool empty() { return f == b; }
  T& pop() { return arr[f++]; }
};
int N, D;
vector<int> digits;
map<int, int> occ;
int main() {
#ifndef STDIO
  freopen(NAME".in", "r", stdin);
  freopen(NAME".out", "w", stdout);
#endif
  RII(N, D);
  int intPart = N / D;
  char str[10];
  sprintf(str, "%d.", intPart);
  string ans(str);
  N %= D;
  if(N == 0) {
    printf("%d.0\n", intPart);
    return 0;
  }
  int k = 0;
  while(true) {
    occ[N] = k++;
    N *= 10;
    digits.PB(N / D);
    N %= D;
    if(N == 0) {
      FOR(it, digits)
        ans.PB('0' + *it);
      break;
    }
    if(occ.count(N)) {
      int r = occ[N];
      REP(i, r) ans.PB('0' + digits[i]);
      ans.PB('(');
      REP1(i, r, digits.size()-1)
        ans.PB('0' + digits[i]);
      ans.PB(')');        
      break;
    }
  }
  for(int i = 0; i < ans.size(); i+=76)
    puts(ans.substr(i, 76).c_str());
  return 0;
}