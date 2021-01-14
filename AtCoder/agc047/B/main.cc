// Create your own template by modifying this file!
#include <new>
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
const int POOL_SIZE = 1<<20;

struct Node {
    Node *child[26];
    bool isLeaf;
    int mask[26];
    Node *parent;
    Node() : isLeaf(false), parent(0) {
        memset(child, 0, sizeof child);
        memset(mask, 0, sizeof mask);
    }
    Node(Node *parent) : isLeaf(false), parent(parent) {
        memset(child, 0, sizeof child);
        memset(mask, 0, sizeof mask);
    }
    void insert(char *word) {
        if (*word) {
            getChild(*word)->insert(word+1);
        } else {
            isLeaf = true;
        }
    }
    static Node pool[POOL_SIZE];
    static Node *ptr;
    Node* getChild(char c) {
        return child[c-'a'] ? child[c-'a'] : (child[c-'a'] = new(ptr++) Node(this));
    }
} Node::pool[POOL_SIZE], *Node::ptr = pool;

void solve() {
    int N;
    cin >> N;

    vector<string> s(N);
    VI a(N);
    REP(i, N) {
        cin >> s[i];
        a[i] = i;
    }
    sort(ALL(a), [&s](int i, int j) {
        return s[i].size() > s[j].size();
    });

    Node root;
    int l = 0, r = 0;
    LL ans = 0;
    while (l < N) {
        while (r < N && s[a[r]].size() == s[a[l]].size()) {
            r++;
        }
        REPP(i, l, r) {
            string &t = s[a[i]];
            Node *ptr = &root;
            for (int i = t.size() - 1; i > 0; i--) {
                ptr = ptr->getChild(t[i]);
            }
            ans += ptr->mask[t[0] - 'a'];
        }
        while (l < r) {
            string &t = s[a[l]];
            Node *ptr = &root;
            for (int i = t.size() - 1; i >= 0; i--) {
                ptr = ptr->getChild(t[i]);
            }
            bool f[26] = {};
            for (char c : t) {
                REP(k, 26) {
                    ptr->mask[k] += f[k];
                }
                f[c - 'a'] = true;
                ptr = ptr->parent;
            }
            REP(k, 26) {
                root.mask[k] += f[k];
            }
            l++;
        }
    }
    cout << ans << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
#define MULTITEST 0
#if MULTITEST    
    CASET{
        solve();
    }
#else
    solve();
#endif
    return 0;
}
