/*
ID: johnath2
PROG: contact
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
#include <set>
using namespace std;
#define NAME "contact"
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
#define PLL(x) printf("%lld\n",x)
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
const int INF = 1000000000;

bool comp(const pair<string, int> &a, const pair<string, int> &b) {
  if(a.S != b.S) return a.S > b.S;
  if(SZ(a.F) != SZ(b.F)) return SZ(a.F) < SZ(b.F);
  return a.F < b.F;
}

int main() {
#ifndef STDIO
  freopen(NAME".in", "r", stdin);
  freopen(NAME".out", "w", stdout);
#endif
  DRIII(A, B, N);
  string s;
  char t[100];
  int res = RS(t);
  while(res != EOF) {
    s += t;
    res = RS(t);
  }
  map<string, int> cnt;
  // cout << s << endl;
  REP1(l, A, B) {
    REP1(i, 0, SZ(s) - l) {
      cnt[s.substr(i, l)]++;
      // cout << s.substr(i, l) << endl;
    }
  }
  vector<pair<string, int> > ans(ALL(cnt));
  sort(ALL(ans), comp);
  int prev = -1, acc;
  FOR(it, ans) {
    if(it->S == prev) {
      cout << SEP(acc % 6 == 0) << it->F;
      acc++;
    } else {
      if(N-- == 0) break;
      if(prev != -1)
        cout << '\n';
      cout << it->S << '\n' << it->F;
      prev = it->S;
      acc = 1;
    }
  }
  cout << endl;
  return 0;
}