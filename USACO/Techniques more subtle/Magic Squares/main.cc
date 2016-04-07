/*
ID: johnath2
PROG: msquare
LANG: C++11
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
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <functional>
#include <stack>
using namespace std;
#define NAME "msquare"
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


void A(string &a) {
  swap(a[0], a[7]);
  swap(a[1], a[6]);
  swap(a[2], a[5]);
  swap(a[3], a[4]);
}

void B(string &b) {
  char tmp = b[3];
  b[3] = b[2], b[2] = b[1], b[1] = b[0], b[0] = tmp;
  tmp = b[4], b[4] = b[5], b[5] = b[6], b[6] = b[7], b[7] = tmp;
}

void C(string &c) {
  char tmp = c[6];
  c[6] = c[5], c[5] = c[2], c[2] = c[1], c[1] = tmp;
}

void uB(string &b) {
  char tmp = b[0];
  b[0] = b[1], b[1] = b[2], b[2] = b[3], b[3] = tmp;
  tmp = b[7], b[7] = b[6], b[6] = b[5], b[5] = b[4], b[4] = tmp;
}

void uC(string &c) {
  char tmp = c[1];
  c[1] = c[2], c[2] = c[5], c[5] = c[6], c[6] = tmp;
}

int main() {
#ifndef STDIO
  freopen(NAME".in", "r", stdin);
  freopen(NAME".out", "w", stdout);
#endif
  string target(8, 0);
  function<void(string&)> f[] = {A, B, C};
  REP(i, 8) RI(target[i]), target[i] += '0';
  // cout << target << endl;
  queue<string> q;
  string init = "12345678";
  unordered_map<string, int> last;
  q.push(init);
  last[init] = -1;
  while(!q.empty()) {
    REP(i, 3) {
      string s = q.front();
      f[i](s);
      if(last.count(s)) continue;
      last[s] = i;
      if(s == target) break;
      q.push(s);
    }
    q.pop();
  }
  function<void(string&)> undo[] = {A, uB, uC};
  stack<int> s;
  while(target != init) {
    s.push(last[target]);
    undo[s.top()](target);
  }
  PI(s.size());
  while(!s.empty())
    printf("%c", 'A' + s.top()), s.pop();
  puts("");
  return 0;
}