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
using namespace std;
#define FOR(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define SZ size()
#define ALL(x) (x).begin(),(x).end()
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define REPL(i,x) for(int i=0;x[i];i++)
#define PER(i,n) for(int i=(n)-1;i>=0;i--)
#define PER1(i,a,b) for(int i=(a);i>=(b);i--)
#define RI(x) scanf("%d",&x)
#define RL(x) scanf(LLD,&x)
#define DRI(x) int x;RI(x)
#define DRL(x) LL x;RL(x)
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
#define FST first
#define SND second
#ifdef ONLINE_JUDGE
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif
template<typename T>
struct number_iterator : std::iterator<random_access_iterator_tag, T>{
  T v;
  number_iterator(T _v) : v(_v) {}
  operator T&(){return v;}
  T operator *() const {return v;}
};
template <typename T>
struct number_range {
  T b,e;
  number_range(T b, T e):b(b),e(e){}
  number_iterator<T> begin(){return b;}
  number_iterator<T> end(){return e;}
};
/* make_pair like functions for our range type */
template<typename T> number_range<T> range(T b, T e) {return number_range<T>(b, e);}
template<typename T> number_range<T> range(T e) {return number_range<T>(0, e);}

typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long LL;
const int INF = 1000000000;

int n, m, k;
char maze[501][501];
bool visited[501][501];

void dfs(int i, int j) {
  if(i < 0 || j < 0 || i >= n || j >= m || maze[i][j] != '.' || visited[i][j]) return;
  visited[i][j] = true;
  // PIS(i); PI(j);
  dfs(i-1,j);
  dfs(i,j-1);
  dfs(i,j+1);
  dfs(i+1,j);
  if(k > 0) {
    maze[i][j] = 'X';
    --k;
  }
}

int main() {
  RIII(n, m, k);
  REP(i, n) RS(maze[i]);
  REP(i, n) REP(j, m)
    if(maze[i][j] != '#')
      dfs(i, j);
  REP(i, n) puts(maze[i]);
  return 0;
}