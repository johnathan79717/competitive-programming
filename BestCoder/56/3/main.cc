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
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
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
template<class T> void PI(T i) { print(i); puts(""); }
template<class T> void PIS(T i) { print(i); printf(" "); }

template<class T>
void PV(T const &v, int N) {
    REP(i, N) {
        print(v[i]);
        printf("%c", i == N-1 ? '\n' : ' ');
    }
}

template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
int popcount(int x) { return __builtin_popcount(x); } 
int popcount(long long x) { return __builtin_popcountll(x); } 

struct Node {
    Node* child[26];
    bool isType;
    int i;
} *pool[200001];

int ii = 0;
Node *getNode() {
    return pool[ii++];
}

char type[200005];
char E[500005];
bool type2type[505][505];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    CASET {
        MS0(type2type);
        MS0(pool);
        ii = 0;
        Node *root = getNode();
        DRI(N);
        V(string) value(N+1), valueType(N+1);
        REP1(i, 1, N) {
            cin >> value[i] >> valueType[i];
        }
        DRI(M);
        bool fail = false;
        REP1(i, 1, M) {
            cin >> type;
            Node *p = root;
            REPL(j, type) {
                int k = type[j] - 'a';
                if (!p->child[k]) {
                    p->child[k] = getNode();
                }
                p = p->child[k];
            }
            if (p->i) {
                fail = true;
            }
            p->isType = true;
            p->i = i;
            DRI(k);
            while (k--) {
                DRI(b);
                type2type[i][b] = true;
            }
        }
        if (fail) {
            PI(-1);
            continue;
        }
        VI value2type(N+1);
        REP1(i, 1, N) {
            Node *p = root;
            REP(j, SZ(valueType[i])) {
                int k = valueType[i][j] - 'a';
                if (!p->child[k]) {
                    fail = true;
                    break;
                }
                p = p->child[k];
            }
            if (p->i == 0 || !p->isType) {
                fail = true;
            }
            if (fail) break;
            value2type[i] = p->i;
            p = root;
            REP(j, SZ(value[i])) {
                int k = value[i][j] - 'a';
                if (!p->child[k]) {
                    fail = true;
                    break;
                }
            }
            if (p->i) fail = true;
            if (fail) break;
            p->i = i;
        }
        if (fail) {
            PI(-1);
            continue;
        }
        cin >> E;
        stack<int> op, val;
        REPL(i, E) {
            switch(E[0]) {
                case '(':
                    op.push(-1);
                    break;
                case ')':
                    while (SZ(op) && op.top() >= 0) {
                        if (op.top() == 0) {
                            int t2 = val.top(); val.pop();
                            int t1 = val.top();
                            if (!type2type[t2][t1]) {
                                fail = true;
                                break;
                            }
                        } else {
                            int t = val.top(); val.pop();
                            if (!type2type[t][op.top()]) {
                                fail = true;
                                break;
                            }
                            val.push(op.top());
                        }
                        op.pop();
                    }
                    assert(op.top() == -1);
                    op.pop();
                    break;
                case '*':
                    while (SZ(op) && op.top() >= 0) {
                        if (op.top() == 0) {
                            int t2 = val.top(); val.pop();
                            int t1 = val.top();
                            if (!type2type[t2][t1]) {
                                fail = true;
                                break;
                            }
                        } else {
                            int t = val.top(); val.pop();
                            if (!type2type[t][op.top()]) {
                                fail = true;
                                break;
                            }
                            val.push(op.top());
                        }
                        op.pop();
                    }
                    op.push(0);
                    break;
                default:
                    Node *p = root;
                    while ('a' <= E[i] && E[i] <= 'z') {
                        int k = E[i] - 'a';
                        if (!p->child[k]) {
                            fail = true;
                            break;
                        }
                        p = p->child[k];
                        i++;
                    }
                    i--;
                    if (p->isType) {
                        op.push(p->i);
                    } else {
                        val.push(value2type[p->i]);
                    }

                    break;
            }
            if (fail) break;
        }
        if (fail) continue;
        while (SZ(op) && op.top() >= 0) {
            if (op.top() == 0) {
                int t2 = val.top(); val.pop();
                int t1 = val.top();
                if (!type2type[t2][t1]) {
                    fail = true;
                    break;
                }
            } else {
                int t = val.top(); val.pop();
                if (!type2type[t][op.top()]) {
                    fail = true;
                    break;
                }
                val.push(op.top());
            }
            op.pop();
        }
        cout << value[val.top()] << '\n';
    }
    return 0;
}
