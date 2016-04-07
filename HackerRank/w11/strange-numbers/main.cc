#include <string>
#include <vector>
#include <climits>
#include <cstring>
#include <map>
#include <set>
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
// typedef __int128 ULL;
typedef unsigned long long ULL;

int main() {
  vector<ULL> strange = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  vector<ULL> ten(20, 1);
  for (int i = 1; i < 19; i++) {
      ten[i+1] = ten[i] * 10;
  }
  int d = 1;
  for (int i = 0; i < strange.size(); i++) {
    auto a = strange[i];
    while (d < 18 && a >= ten[d+1]) {
        d++;
    }
    if (d >= 18) {
      break;
    }
    if (d > 1 && a * d < ten[d+1]) {
      strange.PB(a * d);
    }
    if (a * (d+1) >= ten[d+1] && a * (d+1) < ten[d+2]) {
      strange.PB(a * (d+1));
    }
    if (d + 2 <= 18 && a * (d+2) >= ten[d+2] && a * (d+2) < ten[d+3]) {
      strange.PB(a * (d+2));
    }
  }
  sort(ALL(strange));
  strange.resize(unique(ALL(strange)) - strange.begin());
  cerr << strange.size() << endl;
  for (int i = 0; i < strange.size(); i++) {
    cerr << strange[i] << endl;
  }
  int T;
  cin >> T;
  while(T--) {
    LL L, R;
    cin >> L >> R;
    cout << upper_bound(ALL(strange), R) - lower_bound(ALL(strange), L) << '\n';
  }
  return 0;
}