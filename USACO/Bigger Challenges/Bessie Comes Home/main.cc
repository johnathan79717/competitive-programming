/*
ID: johnath2
PROG: comehome
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
#define NAME "comehome"
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

#define MAX_P 52

int P;
bool visited[MAX_P];
int dist[MAX_P];
int adj[MAX_P][MAX_P];

void process(char &a) {
  if('A' <= a && a <= 'Z')
    a -= 'A';
  else
    a = a - 'a' + 26;
}

int main() {
#ifndef STDIO
  freopen(NAME".in", "r", stdin);
  freopen(NAME".out", "w", stdout);
#endif
  RI(P);
  REP(i, MAX_P) {
    REP(j, MAX_P) adj[i][j] = INF;
    dist[i] = INF;
  }
  while(P--) {
    char a, b; int c;
    scanf("\n%c %c%d", &a, &b, &c);
    process(a); process(b);
    adj[a][b] = adj[b][a] = min(c, adj[a][b]);
  }
  priority_queue<PII, vector<PII>, greater<PII> > q;
  q.push(MP(0, 25));
  dist[25] = 0;
  while(!q.empty()) {
    int d = q.top().F, i = q.top().S;
    if(i < 25) {
      printf("%c %d\n", 'A' + i, d);
      break;
    }
    q.pop();
    if(dist[i] < d) continue;
    REP(j, MAX_P) {
      if(adj[i][j] < INF && !visited[j] && dist[i] + adj[i][j] < dist[j]) {
        dist[j] = dist[i] + adj[i][j];
        q.push(MP(dist[j], j));
      }
    }
  }
  return 0;
}