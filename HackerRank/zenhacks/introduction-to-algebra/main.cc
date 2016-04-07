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
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define SZ(ans) ((int)(X).size())
#define LEN(X) strlen(X)
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

int A[111][111];
int N;

bool quasigroup() {
    REP(x, N) REP(y, N) {
        int cnt1 = 0, cnt2 = 0;
        REP(z, N) {
            if (A[x][z] == y) {
                cnt1++;
            }
            if (A[z][x] == y) {
                cnt2++;
            }
        }
        if (cnt1 != 1 || cnt2 != 1) {
            return false;
        }
    }
    return true;
}

int loop() {
    int cnt = 0, ans;
    REP(e, N) {
        bool all = true;
        REP(x, N) {
            if (A[x][e] != x || A[e][x] != x) {
                all = false;
                break;
            }
        }
        if (all) {
            cnt++;
            ans = e;
        }
    }
    if (cnt == 1) {
        return ans;
    } else {
        return -1;
    }
}

bool semigroup() {
    REP(x, N) REP(y, N) REP(z, N) {
        if (A[A[x][y]][z] != A[x][A[y][z]])
            return false;
    }
    return true;
}

int monoid() {
    return loop();
}

bool group(int e) {
    REP(x, N) {
        bool exist = false;
        REP(y, N) {
            if (A[x][y] == e && A[y][x] == e) {
                exist = true;
            }
        }
        if (!exist) {
            return false;
        }
    }
    return true;
}

bool abelian() {
    REP(x, N) REP(y, N) {
        if (A[x][y] != A[y][x])
            return false;
    }
    return true;
}

bool rack() {
    REP(x, N) REP(y, N) {
        int cnt = 0;
        REP(z, N) {
            if (A[x][A[y][z]] != A[A[x][y]][A[x][z]])
                return false;
            if (A[x][z] == y) {
                cnt++;
            }
        }
        if(cnt != 1) return false;
    }
    return true;
}

bool quandle() {
    REP(x, N) {
        if (A[x][x] != x) {
            return false;
        }
    }
    return true;
}

int main() {
    DRI(T);
    while(T--) {
        RI(N);
        REP(i, N) {
            REP(j, N) {
                RI(A[i][j]);
            }
        }
        int ans = 0;
        if (quasigroup()) {
            ans += 1;
            if (loop() >= 0)
                ans += 2;
        }
        if (semigroup()) {
            ans += 4;
            int e = monoid();
            if (e >= 0) {
                ans += 8;
                if (group(e)) {
                    ans += 16;
                    if (abelian()) {
                        ans += 32;
                    }
                }
            }
        }
        if (rack()) {
            ans += 64;
            if (quandle()) {
                ans += 128;
            }
        }
        PI(ans);
    }
  return 0;
}