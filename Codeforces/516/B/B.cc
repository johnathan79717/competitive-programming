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
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define SZ(X) ((int)(X).size())
#define LEN(X) strlen(X)
#define FOR(i,c) for(auto &i: c)
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
#define BG begin()
#define ED end()
#define PQ priority_queue
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,-1,sizeof(x))
#define SEP(x) ((x)?'\n':' ')
#define V(x) vector<x>
using namespace std;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long LL;
const int INF = 1000000000;

#ifdef DEBUG
     #define debug(args...)            {dbg,args; cerr<<endl;}
#else
    #define debug(args...)              // Just strip off all debug tokens
#endif

struct debugger
{
    template<typename T> debugger& operator , (const T& v)
    {    
        cerr<<v<<" ";    
        return *this;    
    }
} dbg;

char a[2003][2003];
int deg[2004][2004];

int di[] = {1, 0, -1, 0};
int dj[] = {0, 1, 0, -1};

int N, M;

void go(int,int);

void fill(int i, int j) {
    REP(k, 4) {
        int ii = i + di[k], jj = j + dj[k];
        if (ii >= 0 && ii < N && jj >= 0 && jj < M && a[ii][jj] == '.') {
            deg[ii][jj]--;
            if (deg[ii][jj] == 0) {
                puts("Not unique");
                exit(0);
            }
            if (deg[ii][jj] == 1) {
                go(ii, jj);
            }
        }
    }
}

void go(int i, int j) {
    REP(k, 4) {
        int ii = i + di[k], jj = j + dj[k];
        if (ii >= 0 && ii < N && jj >= 0 && jj < M && a[ii][jj] == '.') {
            switch(k) {
                case 0:
                    a[i][j] = '^';
                    a[ii][jj] = 'v';
                    break;
                case 1:
                    a[i][j] = '<';
                    a[ii][jj] = '>';
                    break;
                case 2:
                    a[i][j] = 'v';
                    a[ii][jj] = '^';
                    break;
                default:
                    a[i][j] = '>';
                    a[ii][jj] = '<';
                    break;
            }
            fill(i, j);
            fill(ii, jj);
        }
    }
}


int main()
{
    RII(N, M);
    REP(i, N) RS(a[i]);
    REP(i, N) {
        REP(j, M) {
            if (a[i][j] != '.') continue;
            REP(k, 4) {
                if (i + di[k] >= 0 && i + di[k] < N && j + dj[k] >= 0 && j + dj[k] < M) {
                    deg[i+di[k]][j+dj[k]]++;
                }
            }
        }
    }
    REP(i, N) {
        REP(j, M) {
            if (a[i][j] == '.') {
                if (deg[i][j] == 0) {
                    puts("Not unique");
                    return 0;
                }
                if (deg[i][j] == 1)
                    go(i, j);
            }
        }
    }
    REP(i, N) {
        REP(j, M) {
            if (a[i][j] == '.') {
                puts("Not unique");
                return 0;
            }
        }
    }
    REP(i, N) {
        puts(a[i]);
    }
}

