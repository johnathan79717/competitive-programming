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
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define SZ(X) ((int)(X).size())
#define LEN(X) strlen(X)
#define BG begin()
#define ED end()
#define FOR(i,c) for(auto &i: c)
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

char a[101][101];

bool b[101][101][4];
bool v[101][101][4];

int N, M;
void rotate() {
    REP(i, M) REP(j, N) {
        switch (a[i][j]) {
            case '^': a[i][j] = '>'; break;
            case '>': a[i][j] = 'v'; break;
            case 'v': a[i][j] = '<'; break;
            case '<': a[i][j] = '^'; break;
            default: break;
        }
    }
}


bool isWall(int i, int j) {
    if (i < 0 || i >= M || j < 0 || j >= N) return true;
    switch (a[i][j]) {
        case 'S':
        case 'G':
        case '.': return false;
        case '#':
        case '^':
        case '>':
        case 'v':
        case '<': return true;
        default: assert(false);
    }
}

struct BFS
{
    int i, j, k;
};

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main() {
  int T, cas = 1;
  scanf("%d", &T);
  while(T--) {
    printf("Case #%d: ", cas++);
    RII(M, N); 
    REP(i, M) {
        RS(a[i]);
    }
    MS1(b);
    REP(k, 4) {
        REP(i, M) REP(j, N) {
            if (!isWall(i, j)) continue;
            b[i][j][k] = false;
            switch (a[i][j]) {
                case '^': PER(x, i) {
                    if (isWall(x, j)) break;
                    b[x][j][k] = false;
                }
                break;
                case '>': REP1(y, j+1, N-1) {
                    if (isWall(i, y)) break;
                    b[i][y][k] = false;
                }
                break;
                case 'v': REP1(x, i+1, M-1) {
                    if (isWall(x, j)) break;
                    b[x][j][k] = false;
                }
                break;
                case '<': PER(y, j) {
                    if (isWall(i, y)) break;
                    b[i][y][k] = false;
                }
                break;
                case '#': break;
                default: assert(false);
            }
        }
        rotate();
    }
    // REP(k, 4) REP(i, M) {
    //     REP(j, N) PIS(b[i][j][k]);
    //     puts("");
    // }
    MS0(v);
    queue<BFS> q;
    // q.push((BFS){0, 0, 0});
    REP(i, M) REP(j, N) if (a[i][j] == 'S') q.push((BFS){i, j, 0});
    while (!q.empty()) {
        bool end = false;
        REP(t, 4) {
            int i = q.front().i + dx[t], j = q.front().j + dy[t], k = q.front().k + 1;
            if (!isWall(i, j) && a[i][j] == 'G' && b[i][j][k%4]) {
                end = true;
                PI(k);
                break;
            }
            if (!isWall(i, j) && b[i][j][k%4] && !v[i][j][k%4]) {
                v[i][j][k%4] = true;
                q.push((BFS){i, j, k});
            }
        }
        if (end) break;
        q.pop();
    }
    if (q.empty()) puts("impossible");
  }
}