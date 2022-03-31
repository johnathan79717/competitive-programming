// Create your own template by modifying this file!
#include <atcoder/mincostflow.hpp>
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
#include <cassert>
#include <deque>
#include <stack>
#include <functional>
#include <bitset>
#include <numeric>
#include <atcoder/mincostflow>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define FOR(I, A, B) for (int I = (A); I <= (B); ++I)
#define FORS(I, S) for (int I = 0; S[I]; ++I)
#define RS(X) scanf("%s", (X))
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define GET_POS(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
#define CASET int ___T; scanf("%d", &___T); for(int cs=1;cs<=___T;cs++)
#define MP make_pair
#define PB emplace_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define F first
#define S second
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII> VPII;
typedef pair<LL,LL> PLL;
typedef vector<PLL> VPLL;
template<class T> void _R(T &x) { cin >> x;  }
void _R(int &x) { scanf("%d", &x);  }
void _R(int64_t &x) { scanf("%lld", &x);  }
void _R(double &x) { scanf("%lf", &x);  }
void _R(char &x) { scanf(" %c", &x);  }
void _R(char *x) { scanf("%s", x);  }
void R() {}
template<class T, class... U> void R(T &head, U &... tail) { _R(head); R(tail...);  }
template<class T> void _W(const T &x) { cout << x;  }
void _W(const int &x) { printf("%d", x);  }
void _W(const int64_t &x) { printf("%lld", x);  }
void _W(const double &x) { printf("%.16f", x);  }
void _W(const char &x) { putchar(x);  }
void _W(const char *x) { printf("%s", x);  }
template<class T,class U> void _W(const pair<T,U> &x) {_W(x.F); putchar(' '); _W(x.S);}
template<class T> void _W(const vector<T> &x) { for (auto i = x.begin(); i != x.end(); _W(*i++)) if (i != x.cbegin()) putchar(' ');  }
void W() {}
template<class T, class... U> void W(const T &head, const U &... tail) { _W(head); putchar(sizeof...(tail) ? ' ' : '\n'); W(tail...);  }
#ifdef DEBUG
 #define debug(...) {printf("[DEBUG] ");W(__VA_ARGS__);}
#else
 #define debug(...)
#endif
int MOD = 1e9+7;
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}
/*}}}*/
const int SIZE = 1<<20;
template<class T> void MIN(T& a, const T& b) { a = min(a, b); }
template<class T> void MAX(T& a, const T& b) { a = max(a, b); }

#define MULTITEST 0

struct Edge {
    int from, to, w;
    char dir;
    Edge *prev;
};

void solve() {
    int N, Pu, Pl, Pd, Pr;
    R(N, Pu, Pl, Pd, Pr);
    atcoder::mcf_graph<int, int> graph(N * N + 2);
    int s = N*N, t = s+1, node = 0, cycleNodes = 0;
    int  r[N+1][N+1], c[N+1][N+1];

    FOR(i, 1, N) {
        FOR(j, 1, N) {
            R(r[i][j], c[i][j]);
            if (r[i][j] == i && c[i][j] == j) {
                cycleNodes++;
                if ((i+j) % 2) 
                    graph.add_edge(s, node, 1, 0);
                else
                    graph.add_edge(node, t, 1, 0);

                if (i > 1 && r[i-1][j] == i-1 && c[i-1][j] == j) {
                    if ((i+j) % 2)
                        graph.add_edge(node, node - N, 1, Pu + Pd);
                    else
                        graph.add_edge(node - N, node, 1, Pu + Pd);
                }
                if (j > 1 && r[i][j-1] == i && c[i][j-1] == j-1) {
                    if ((i+j) % 2)
                        graph.add_edge(node, node-1, 1, Pl + Pr);
                    else
                        graph.add_edge(node-1, node, 1, Pl + Pr);
                }
            }
            node++;
        }
    }
    auto pr = graph.flow(s, t);
    auto edges = graph.edges();
    if (pr.F * 2 != cycleNodes) {
        W(-1);
        return;
    }
    vector<string> ans(N+1, string(N+1, '.'));
    for (auto &e : edges) {
        if (!e.flow || e.from == s || e.to == t) continue;
        int fi = e.from / N + 1, fj = e.from % N + 1;
        int ti = e.to / N + 1, tj = e.to % N + 1;
        debug(fi, fj, ti, tj);
        if (tj == fj + 1) {
            ans[fi][fj] = 'R';
            ans[ti][tj] = 'L';
            assert(e.cost == Pl + Pr);
        } else if (tj == fj - 1) {
            ans[fi][fj] = 'L';
            ans[ti][tj] = 'R';
            assert(e.cost == Pl + Pr);
        } else if (ti == fi + 1) {
            ans[fi][fj] = 'D';
            ans[ti][tj] = 'U';
            assert(e.cost == Pu + Pd);
        } else if (ti == fi - 1) {
            ans[fi][fj] = 'U';
            ans[ti][tj] = 'D';
            assert(e.cost == Pu + Pd);
        }
    }

    debug(ans);

    int cnt = N*N;
    FOR(i, 1, N) {
        FOR(j, 1, N) {
            if (r[i][j] != i || c[i][j] != j) continue;
            unordered_map<int, bool> inque, pointed;
            queue<int> q;
            q.push(i);
            q.push(j);
            int root = (i-1) * N + (j-1);
            inque[root] = true;
            VI V;
            vector<Edge> E;
            while (q.size()) {
                int a = q.front();
                q.pop();
                int b = q.front();
                q.pop();
                int da[] = {-1, 0, 1, 0}, db[] = {0, 1, 0, -1}, co[] = {Pu, Pr, Pd, Pl};
                char dir[5] = "URDL";
                int v = (a - 1) * N + b - 1;
                debug("while", v);
                REP(k, 4) {
                    int aa = a + da[k], bb = b + db[k];
                    if (aa >= 1 && aa <= N && bb >= 1 && bb <= N && r[aa][bb] == i && c[aa][bb] == j) {
                        int v2 = (aa-1)*N+bb-1;
                        if (a != i || b != j) {
                            E.PB(Edge{v2, v, co[k], dir[k], NULL});
                        }

                        if (!inque[v2]) {
                            inque[v2] = true;
                            V.PB(v2);
                            q.push(aa);
                            q.push(bb);
                        }
                    }
                }
                //sort(E[v].begin(), E[v].end());
            }
            function<unordered_map<int, Edge>(const VI&, vector<Edge>&)> Edmonds = [&](const VI& V, vector<Edge>& E) {
                unordered_map<int, bool> visited, visiting; 
                debug("solve begin", root, V);
                visited[root] = true;
                unordered_map<int, Edge> P;
                for (auto &e : E) {
                    int v = e.to;
                    if (!P.count(v) || e.w < P[v].w) {
                        P[v] = e;
                    }
                }
                for (int v : V) {
                    queue<int> q;
                    while (true) {
                        if (visited[v]) {
                            while (q.size()) {
                                int u = q.front();
                                visited[u] = true;
                                visiting[u] = false;
                                q.pop();
                            }
                            break;
                        }
                        if (visiting[v]) {
                            while (q.front() != v) {
                                visiting[q.front()] = false;
                                q.pop();
                            }
                            break;
                        }
                        visiting[v] = true;
                        q.push(v);
                        v = P[v].from;
                    }
                    if (visiting[v]) {
                        // cycle found
                        int vc = cnt++;
                        VI V1 = {vc};
                        for (int v : V) {
                            if (!visiting[v]) {
                                V1.PB(v);
                            }
                        }
                        assert(SZ(V1) < SZ(V));

                        vector<Edge> E1;
                        for (auto &e : E) {
                            int u = e.from, v = e.to;
                            if (!visiting[u] && visiting[v]) {
                                E1.PB(Edge{u, vc, e.w - P[v].w, e.dir, &e});
                            } else if (visiting[u] && !visiting[v]) {
                                E1.PB(Edge{vc, v, e.w, e.dir, &e});
                            } else if (!visiting[u] && !visiting[v]) {
                                E1.PB(e);
                            }
                        }
                        auto P1 = Edmonds(V1, E1);
                        unordered_map<int, Edge> ans;
                        for (auto &pr : P1) {
                            if (pr.F == vc) {
                                auto &e = *pr.S.prev;
                                assert(!ans.count(e.to));
                                ans[e.to] = e;
                                for (int v : V) {
                                    if (visiting[v] && v != e.to) {
                                        assert(!ans.count(v));
                                        ans[v] = P[v];
                                    }
                                }
                            } else if (pr.S.from == vc) {
                                ans[pr.S.to] = *pr.S.prev;
                            } else {
                                ans.insert(pr);
                            }
                        }
                        return ans;
                    }
                }
                debug("===")
                FOR(i, 1, N) {
                    debug(ans[i].c_str() + 1);
                }
                debug("===")
                debug("solve end", root, V);
                return P;
            };
            auto P = Edmonds(V, E);
            for (auto &pr : P) {
                ans[pr.F / N + 1][pr.F % N + 1] = pr.S.dir;
            }
        }
    }

    int cost = 0;
    FOR(i, 1, N) {
        FOR(j, 1, N) {
            switch (ans[i][j]) {
                case 'U':
                    cost += Pu;
                    break;
                case 'L':
                    cost += Pl;
                    break;
                case 'D':
                    cost += Pd;
                    break;
                case 'R':
                    cost += Pr;
                    break;
                default:
                    W(-1);
                    return;
            }
        }
    }


    W(cost);
    FOR(i, 1, N) {
        puts(ans[i].c_str() + 1);
    }
}

#undef int
int main() {
#if MULTITEST    
    CASET{
        solve();
    }
#else
    solve();
#endif
    return 0;
}
