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
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <cassert>
#include <sstream>
#include <bitset>
using namespace std;
#define BG begin()
#define ED end()
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
#define LB lower_bound
#define UB upper_bound
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
const int INF = 1000000000;

bool used[1000001];

#define MAX_P 1000001
// vector<int> primes;
VI p[MAX_P];

void Eratosthenes() {
  // memset(p, true, sizeof p);
  for(int i = 2; i < MAX_P; i++)
    if(p[i].empty()) {
      // primes.push_back(i);
      for(int j = i; j < MAX_P; j+=i)
        p[j].PB(i);
    }
}

int main() {
  Eratosthenes();
  DRI(T);
  REP(t, T) {
    MS0(used);
    DRI(N);
    // V(VI) A(N);
    VI A(N);
    REP(i, N) {
      DRI(a);
      A[i] = a;
    }
    int l = 0, r = 0, ans = 0;
    while(r < N) {
      bool repeat = false;
      for(int a: p[A[r]]) {
        if(used[a])
          repeat = true;
      }
      if(repeat) {
        for(int a: p[A[l]]) {
          // primes.erase(a);
          used[a] = false;
        }
        l++;
      } else {
        for(int a: p[A[r]]) {
          // primes.insert(a);
          used[a] = true;
        }
        r++;
        ans = max(ans, r - l);
      }
    }
    if(ans > 1)
      PI(ans);
    else {
      PI(-1);
    }
  }
  return 0;
}
