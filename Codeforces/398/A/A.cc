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
#include <deque>
#include <stack>
#include <functional>
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
#define DRI(x) int x;RI(x)
#define RII(x,y) scanf("%d%d",&x,&y)
#define DRII(x,y) int x,y;RII(x,y)
#define RIII(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define DRIII(x,y,z) int x,y,z;RIII(x,y,z)
#define RS(x) scanf("%s",x)
#define PI(x) printf("%d\n",x)
#define PIS(x) printf("%d ",x)
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define LB lower_bound
#define UB upper_bound
#define BG begin()
#define ED end()
#define PQ priority_queue
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,-1,sizeof(x))
#define SEP(x) ((x)?'\n':' ')
#define V(x) vector<x >

typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;
const int INF = 1000000000;

int sum(vector<int> &bit, int i) {
  int s = 0;
  while(i > 0) {
    s += bit.at(i);
    i &= i - 1;
  }
  return s;
}

void add(vector<int> &bit, int i, int x) {
  while(i < bit.size()) {
    bit.at(i) += x;
    i += i & -i;
  }
}

#define MOD 1000000007
inline int add(int a, int b, int mod=MOD) { return a + b < mod ? a + b : a + b - mod; }
inline void addBy(int &a, int b, int mod=MOD) { a = add(a, b, mod); }
inline int sub(int a, int b, int mod=MOD) { return a - b < 0 ? a - b + mod : a - b; }
inline void subBy(int &a, int b, int mod=MOD) { a = sub(a, b, mod); }
inline int mul(int a, int b, int mod=MOD) { return (LL)a * b % mod; }
inline void mulBy(int &a, int b, int mod=MOD) { a = mul(a, b, mod); }

/* a*x ≡ 1 (mod m) */
int inverse(int a, int mod = MOD)
{
    int d = mod, x = 0, s = 1, q, r, t;
    while (a != 0)
    {
        q = d / a, r = d % a;
        d = a, a = r;
        t = x - q * s, x = s, s = t;
    }
    if (d != 1) return -1;  // 沒有倒數、無法整除
    return (x + mod) % mod;
}
inline int divide(int a, int b, int mod=MOD) { return mul(a, inverse(b, mod), mod); }

LL mul(LL a,LL b,LL mod=MOD){
  LL x = 0,y=a%mod;
  while(b > 0){
    if(b%2 == 1){
      x = x+y;
      if(x >= mod) x -= mod;
    }
    y = y*2;
    if(y >= mod) y -= mod;
    b /= 2;
  }
  return x%mod;
}

template<class T>
T pow(T a, T b, T c=MOD){
  T x=1,y=a; // ll is taken to avoid overflow of intermediate results
  while(b > 0){
    if(b%2 == 1){
      x=mul(x, y, c);
    }
    y = mul(y, y, c); // squaring the base
    b /= 2;
  }
  return x%c;
}

vector<int> factorial(1, 1);

int fact(int n) {
  while(factorial.size() <= n)
    factorial.push_back(mul(factorial.back(), factorial.size()));
  return factorial[n];
}

int choose(int n, int k) {
  return divide(fact(n), mul(fact(k), fact(n-k)));
}

int main() {
  LL a, b;
  cin >> a >> b;
  if(a == 0) {
    cout << -b*b << endl;
    REP(i, b) printf("%c", 'x');
    puts("");
    return 0;
  } else if(b <= 1) {
    cout << a * a - b * b<< endl;
    REP(i, a) printf("%c", 'o');
    REP(i, b) printf("%c", 'x');
    puts("");
    return 0;
  }
  LL best = LLONG_MIN;
  int bestk;
  REP1(k, 2, b) {
    if(k - 1 > a) break;
    LL ans = (a - k + 2) * (a - k + 2) + k - 2;
    ans -= (b % k) * (b / k + 1) * (b / k + 1);
    ans -= (k - b % k) * (b / k) * (b / k);
    if(best <= ans) {
      best = ans;
      bestk = k;
    }
  }
  cout << best << endl;
  int k = bestk;
  REP(i, 2 * k - 1) {
    if(i % 2) {
      if(i == 1)
        REP(j, a - k + 2)
          printf("%c", 'o');
      else
        printf("%c", 'o');
    } else {
      if(i / 2 < b % k)
        REP(j, b / k + 1)
          printf("%c", 'x');
      else
        REP(j, b / k)
          printf("%c", 'x');
    }
  }
  puts("");
  return 0;
}
