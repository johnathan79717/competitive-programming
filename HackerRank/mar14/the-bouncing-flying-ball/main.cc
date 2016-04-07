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

int inverse(int a, int mod) {
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

int inv_table[101][101];
int inv_mem(int a, int mod)
{
  if(inv_table[a][mod]) return inv_table[a][mod];
    int d = mod, x = 0, s = 1, q, r, t;
    while (a != 0)
    {
        q = d / a, r = d % a;
        d = a, a = r;
        t = x - q * s, x = s, s = t;
    }
    if (d != 1) return -1;  // 沒有倒數、無法整除
    return inv_table[a][mod] = (x + mod) % mod;
}

int div_table[101][101][101];

inline int divide(int a, int b, int mod=MOD) {
  if(div_table[a][b][mod]) return div_table[a][b][mod];
  return div_table[a][b][mod] = mul(a, inv_mem(b, mod), mod);
}

int L, W, H, p, q, r;

int gcd_table[101][101];

int gcd(int a, int b) {
  if(gcd_table[a][b]) return gcd_table[a][b];
  if(a == 0) return gcd_table[a][b] = b;
  else return gcd_table[a][b] = gcd(b % a, a);
}

unordered_set<int> primes = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};

int lcm(int a, int b) {
  return a * b / gcd(a, b);
}

int solve(int dx, int dy, int dz, int a, int b, int c) {
  int g = gcd(abs(dx), gcd(abs(dy), abs(dz)));
  if(g > 1) dx /= g, dy /= g, dz /= g;
  int l = 2*L, w = 2*W, h = 2*H;
  while(dx < 0) dx += l;
  while(dy < 0) dy += w;
  while(dz < 0) dz += h;
  a -= p; while(a < 0) a += l;
  b -= q; while(b < 0) b += w;
  c -= r; while(c < 0) c += h;
  int g1 = gcd(dx, l), g2 = gcd(dy, w), g3 = gcd(dz, h);
  if(a % g1 || b % g2 || c % g3) return INF;
  dx /= g1; a /= g1; l /= g1;
  dy /= g2; b /= g2; w /= g2;
  dz /= g3; c /= g3; h /= g3;
  a = divide(a, dx, l); b = divide(b, dy, w); c = divide(c, dz, h);
  if((a-b) % gcd(l, w) || (b-c) % gcd(w, h) || (c-a) % gcd(h, l))
    return INF;
  V(PII) congruences;
  FOR(p, primes) {
    int pow = p;
    while(l % pow == 0 || w % pow == 0 || h % pow == 0)
      pow *= p;
    pow /= p;
    if(pow > 1) {
      if(l % pow == 0)
        congruences.EB(a, pow);
      else if(w % pow == 0)
        congruences.EB(b, pow);
      else {
        congruences.EB(c, pow);
      }
    }
  }
  int product = 1;
  FOR(p, congruences) product *= p.S;
  int ans = 0;
  FOR(p, congruences) {
    int M = product / p.S;
    ans += p.F * M * inverse(M, p.S);
  }
  return ans % product;
}

PII record[101][101][101];

int main() {
  DRI(T);
  while(T--) {
    RIII(L, W, H);
    DRIII(a, b, c);
    DRIII(d, e, f);
    RIII(p, q, r);
    DRI(N);
    VI del;
    FOR(pp, primes)
      if((2*L) % pp && (2*W) % pp && (2*H) % pp)
        del.PB(pp);
    FOR(pp, del) primes.erase(pp);
    int ans1 = 0, ans2 = 0;
    REP1(dx, -N, N) REP1(dy, -N, N) REP1(dz, -N, N) {
      if(dx == 0 && dy == 0 && dz == 0)
        continue;
      int k1 = INF, k2 = INF;
      if(record[N+dx][N+dy][N+dz] != MP(0, 0)) {
      // if(false) {
        k1 = record[N+dx][N+dy][N+dz].F;
        k2 = record[N+dx][N+dy][N+dz].S;
      } else {
        int r1[8], r2[8];
        r1[0] = solve(dx, dy, dz, a, b, c);
        r1[1] = solve(dx, dy, dz, a, b, -c);
        r1[2] = solve(dx, dy, dz, a, -b, c);
        r1[3] = solve(dx, dy, dz, a, -b, -c);
        r1[4] = solve(dx, dy, dz, -a, b, c);
        r1[5] = solve(dx, dy, dz, -a, b, -c);
        r1[6] = solve(dx, dy, dz, -a, -b, c);
        r1[7] = solve(dx, dy, dz, -a, -b, -c);
        r2[0] = solve(dx, dy, dz, d, e, f);
        r2[1] = solve(dx, dy, dz, d, e, -f);
        r2[2] = solve(dx, dy, dz, d, -e, f);
        r2[3] = solve(dx, dy, dz, d, -e, -f);
        r2[4] = solve(dx, dy, dz, -d, e, f);
        r2[5] = solve(dx, dy, dz, -d, e, -f);
        r2[6] = solve(dx, dy, dz, -d, -e, f);
        r2[7] = solve(dx, dy, dz, -d, -e, -f);
        k1 = *min_element(r1, r1 + 8);
        k2 = *min_element(r2, r2 + 8);
        int max1 = -INF, max2 = -INF;
        REP(i, 8) {
          if(r1[i] < INF) max1 = max(max1, r1[i]);
          if(r2[i] < INF) max2 = max(max2, r2[i]);
        }
        record[N-dx][N-dy][N-dz] = MP(-max1, -max2);
      }
      // printf("(%d, %d, %d): %d %d\n", dx, dy, dz, k1, k2);
      if(k1 < k2) {
        ans1++;
        // printf("(%d, %d, %d): Sergey", dx, dy, dz);
        // if(k2 < INF) puts(" Chen"); else puts("");
      } else if(k2 < k1) {
        ans2++;
        // printf("(%d, %d, %d): Chen", dx, dy, dz);
        // if(k1 < INF) puts(" Sergey"); else puts("");
      }
    }
    PIS(ans1); PI(ans2);
  }
  return 0;
}