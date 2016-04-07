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

int hcost[11][11], vcost[11][11];

void decode(LL num, int state[11]) {
  REP1(i, 1, 10) {
    state[i] = num % 11;
    num /= 11;
  }
}

LL encode(int state[11]) {
  LL ans = 0, p = 1;
  REP1(i, 1, 10) {
    ans += p * state[i];
    p *= 11;
  }
  return ans;
}
int m, n;
bool legal(int state[11]) {
  REP1(i, 1, n)
    if(state[i] && state[i] != i && state[state[i]] != i)
      return false;
  return true;
}

// void insert(unordered_map<LL, int> &map, int state[11], int score) {
void insert(map<LL, int> &map, int state[11], int score) {
  assert(legal(state));
  LL code = encode(state);
  if(map.count(code))
    map[code] = min(map[code], score);
  else
    map[code] = score;
}

int main() {
  RII(m, n);
  if(m == 1 || n == 1 || (m % 2 && n % 2)) {
    puts("0");
    return 0;
  }
  REP1(i, 1, m) REP1(j, 1, n-1) RI(hcost[i][j]);
  REP1(i, 1, m-1) REP1(j, 1, n) RI(vcost[i][j]);
  // unordered_map<LL, int> prev, next;
  map<LL, int> prev, next;
  next[0] = 0;
  REP1(i, 1, m) {
    REP1(j, 1, n) {
      swap(prev, next);
      next.clear();
      FOR(p, prev) {
        int state[11], score = p.S;
        decode(p.F, state);
        if(state[j] == j)
          cerr << i << ' ' << j << endl;
        assert(state[j] != j);
        if(state[j] == 0) {
          state[j] = j;
        } else {
          assert(i > 1);
          score += vcost[i-1][j];
        }
        if(j > 1 && state[j-1] && ((i==m && j==n) || state[j-1] != j)) {
          if(state[j-1] == j-1) {
            state[j-1] = state[j];
            if(state[j] == j)
              state[j] = j-1;
            else {
              state[state[j]] = j-1;
              state[j] = 0;
            }
          } else {
            if(!(j == n && state[j] == j))
              insert(next, state, score);
            int a = state[j-1], b = state[j];
            state[a] = b;
            state[b] = a;
            state[j-1] = 0;
            if(b != j)
              state[j] = 0;
          }
          score += hcost[i][j-1];
        }
        if(!(j == n && state[j] == j))
          insert(next, state, score);
      }
    }
  }
  assert(next.count(0));
  PI(next[0]);
  return 0;
}