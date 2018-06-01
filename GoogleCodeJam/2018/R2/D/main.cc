#include <functional>
#include <list>
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
#include <deque>
#include <stack>
#include <cassert>
using namespace std;
#define FOR(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define ALL(x) (x).begin(),(x).end()
#define CASET2 int ___T, case_n = 1; scanf("%d ", &___T); while ((___T > 0 ? printf("Case #%d:\n", case_n++) : 0), ___T-- > 0)
#define CASET1 int ___T, case_n = 1; scanf("%d ", &___T); while ((___T > 0 ? printf("Case #%d: ", case_n++) : 0), ___T-- > 0)
#define CASET int ___T; scanf("%d ", &___T); while (___T-- > 0)
#define SZ(X) ((int)(X).size())
#define LEN(X) strlen(X)
#define REP(i,n) for(int i=0;i<int(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=int(b);i++)
#define PER1(i,a,b) for(int i=(a);i>=(b);i--)
#define REPL(i,x) for(int i=0;x[i];i++)
#define PER(i,n) for(int i=(n)-1;i>=0;i--)
#define RI1(x) scanf("%d",&x)
#define RI2(x,y) RI1(x), RI1(y)
#define RI3(x,y...) RI1(x), RI2(y)
#define RI4(x,y...) RI1(x), RI3(y)
#define RI5(x,y...) RI1(x), RI4(y)
#define RI6(x,y...) RI1(x), RI5(y)
#define GET_MACRO(_1, _2, _3, _4, _5, _6, NAME, ...) NAME
#define RI(argv...) GET_MACRO(argv, RI6, RI5, RI4, RI3, RI2, RI1)(argv)
#define DRI(argv...) int argv;RI(argv)
#define WRI(argv...) while (RI(argv) != EOF)
#define DWRI(x...) int x; WRI(x)
#define RS(x) scanf("%s",x)
#define MP make_pair
#define PB push_back
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,-1,sizeof(x))
#define X first
#define Y second
#define V(x) vector<x >

typedef long double LD;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long LL;
const int INF = 1000000000;

void print(int i) { printf("%d", i); }
void print(LL i);
template<class T> void PI(T i) { print(i); puts(""); }
template<class T> void PIS(T i) { print(i); printf(" "); }

template<class T>
void PV(T const &v, int N) {
    REP(i, N) {
        print(v[i]);
        printf("%c", i == N-1 ? '\n' : ' ');
    }
}

template<class T> void PV(T const &v) { PV(v, SZ(v)); }

template<class T, class S> bool has_bit(T mask, S i) { return (mask >> i) & 1; }
long long shift(int i) { return 1ll << i; }

template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
int popcount(int x) { return __builtin_popcount(x); } 
int popcount(long long x) { return __builtin_popcountll(x); } 

#include <array>
#include <unordered_set>
#include <unordered_map>
#define EB emplace_back
#define RL(x) scanf("%lld", &(x))
#define PL(x) printf("%lld\n", x)
#define DRL(x) LL x; RL(x)

char grid[3][5];
int R, C;

int get_bit(int x, int i) {
    return (x >> i) & 1;
}

bool used[3][4];

bool connected(int mask) {
    MS0(used);
    bool finishedFirst = false;
    int dr[] = {1, 0, -1, 0}, dc[] = {0, 1, 0, -1};
    REP(i, R) {
        REP(j, C) {
            if (get_bit(mask, i * C + j) == 0) continue;
            if (finishedFirst && !used[i][j]) {
                return false;
            }
            finishedFirst = true;
            queue<int> q;
            q.push(i);
            q.push(j);
            while (q.size()) {
                int r = q.front();
                q.pop();
                int c = q.front();
                q.pop();
                REP(k, 4) {
                    if (r+dr[k] >= 0 && r+dr[k] < R && c+dc[k] >= 0 && c+dc[k] < C && get_bit(mask, (r+dr[k])*C+c+dc[k]) && !used[r+dr[k]][c+dc[k]]) {
                        q.push(r+dr[k]);
                        q.push(c+dc[k]);
                        used[r+dr[k]][c+dc[k]] = true;
                    }
                }
            }
        }
    }
    return true;
}

bool all(int mask, char color) {
    REP(i, R) REP(j, C) {
        if (get_bit(mask, i * C + j) && grid[i][j] != color) {
            return false;
        }
    }
    return true;
}

int main() {
    DRI(T);
    REP1(t, 1, T) {
        printf("Case #%d: ", t);
        RI(R, C);
        REP(i, R) {
            RS(grid[i]);
        }
        int ans = 0;
        REP(mask, 1 << (R * C)) {
            if (!connected(mask)) {
                continue;
            }
            if (all(mask, 'W') || all(mask, 'B')) {
                ans = max(ans, popcount(mask));
                continue;
            }
            REP(r, R-1) {
                int b[2] = {}, w[2] = {};
                REP(i, R) {
                    REP(j, C) {
                        if (!get_bit(mask, i * C + j)) continue;
                        if (grid[i][j] == 'B') {
                            b[i <= r]++;
                        } else {
                            w[i <= r]++;
                        }
                    }
                }
                if ((b[0] == 0 && w[1] == 0) || (b[1] == 0 && w[0] == 0)) {
                    ans = max(ans, popcount(mask));
                }
            }
            REP(c, C-1) {
                int b[2] = {}, w[2] = {};
                REP(i, R) {
                    REP(j, C) {
                        if (!get_bit(mask, i * C + j)) continue;
                        if (grid[i][j] == 'B') {
                            b[j <= c]++;
                        } else {
                            w[j <= c]++;
                        }
                    }
                }
                if ((b[0] == 0 && w[1] == 0) || (b[1] == 0 && w[0] == 0)) {
                    ans = max(ans, popcount(mask));
                }
            }
            REP(r, R-1) {
                REP(c, C-1) {
                    int b[2][2] = {}, w[2][2] = {};
                    REP(i, R) {
                        REP(j, C) {
                            if (!get_bit(mask, i * C + j)) continue;
                            if (grid[i][j] == 'B') {
                                b[i <= r][j <= c]++;
                            } else {
                                w[i <= r][j <= c]++;
                            }
                        }
                    }
                    int ww = 0, bb = 0;
                    REP(i, 2) {
                        REP(j, 2) {
                            ww += !!w[i][j];
                            bb += !!b[i][j];
                        }
                    }
                    if (ww == 1) {
                        REP(i, 2) {
                            REP(j, 2) {
                                if (w[i][j] && !b[i][j]) {
                                    REP(x, R) {
                                        REP(y, C) {
                                            if (!get_bit(mask, x * C + y)) continue;
                                            if (grid[x][y] == 'W') {
                                                int xx = x + (i ? -1 : 1), yy = y + (j ? -1 : 1);
                                                if (xx >= 0 && xx < R && yy >= 0 && yy < C && grid[x][yy] == 'B' && grid[xx][y] == 'B') {
                                                    ans = max(ans, popcount(mask));
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    if (bb == 1) {
                        REP(i, 2) {
                            REP(j, 2) {
                                if (b[i][j] && !w[i][j]) {
                                    REP(x, R) {
                                        REP(y, C) {
                                            if (!get_bit(mask, x * C + y)) continue;
                                            if (grid[x][y] == 'B') {
                                                int xx = x + (i ? -1 : 1), yy = y + (j ? -1 : 1);
                                                if (xx >= 0 && xx < R && yy >= 0 && yy < C && grid[x][yy] == 'W' && grid[xx][y] == 'W') {
                                                    ans = max(ans, popcount(mask));
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    if (w[0][0] && !b[0][0] && w[1][1] && !b[1][1] && b[0][1] && !w[0][1] && b[1][0] && w[1][0]) {
                        REP(x, R-1) REP(y, C-1) {
                            if (!get_bit(mask, x * C + y)) continue;
                            if (grid[x][y] == 'W' && grid[x+1][y+1] == 'W' && grid[x][y+1] == 'B' && grid[x+1][y] == 'B') {
                                ans = max(ans, popcount(mask));
                            }
                        }
                    }
                    if (b[0][0] && !w[0][0] && b[1][1] && !w[1][1] && w[0][1] && !b[0][1] && w[1][0] && b[1][0]) {
                        REP(x, R-1) REP(y, C-1) {
                            if (!get_bit(mask, x * C + y)) continue;
                            if (grid[x][y] == 'B' && grid[x+1][y+1] == 'B' && grid[x][y+1] == 'W' && grid[x+1][y] == 'W') {
                                ans = max(ans, popcount(mask));
                            }
                        }
                    }
                }
            }
        }
        PI(ans);
    }
    return 0;
}
