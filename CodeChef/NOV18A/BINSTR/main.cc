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

#include <new>

const int POOL_SIZE = 3000000;

struct Node {
    Node *child[2];
    int index;
    Node() : index(INF) {
        memset(child, 0, sizeof child);
    }
    Node *insert(char *word, int i) {
        if (*word) {
            return getChild(*word)->insert(word+1, i);
        } else {
            index = min(index, i);
            return this;
        }
    }
    static Node pool[POOL_SIZE];
    static Node *ptr;
    Node* getChild(char c) {
        return child[c-'0'] ? child[c-'0'] : (child[c-'0'] = new(ptr++) Node);
    }
} Node::pool[POOL_SIZE], *Node::ptr = pool;
#include <unordered_set>
#include <unordered_map>
#define EB emplace_back
#define RL(x) scanf("%lld", &(x))
#define PL(x) printf("%lld\n", x)
#define DRL(x) LL x; RL(x)

char t[1000004];

char *XOR(char *a, char *s) {
    //cout << a << ' ' << s << endl;
    REPL(i, s) {
        t[i] = '0' + ((a[i] - '0') ^ (s[i] - '0'));
    }
    return t;
}

char s[1000004];
char maxValue[1000004];
char result[1000004];
char zeros[1000004];

int main() {
    DRI(N, Q);
    const int B = max(1, (int)sqrt(N / 2));
    //const int B = 3;
    vector<Node> tries((N + B - 1) / B);
    vector<char*> A(N);
    int maxLen = 0;
    REP(i, N) {
        RS(s);
        int l = strlen(s);
        A[i] = new char[l];
        strcpy(A[i], s);
        maxLen = max(maxLen, l);
        //tries[i / B].insert(A[i], i);
    }
    memset(zeros, '0', maxLen);
    REP(i, N) {
        Node *p = tries[i / B].insert(zeros + N - strlen(A[i]), INF);
        p->insert(A[i], i);
    }
    while (Q--) {
        DRI(L, R);
        L--; R--;
        RS(s);
        int len = strlen(s);
        if (len > maxLen) {
            strcpy(s, s + len - maxLen);
        }
        len = strlen(s);
        memset(maxValue, '0', len);
        auto check = [&](int i, char *result) {
            //cout << i << ' ' << result << endl;
            if (strcmp(result, maxValue) > 0) {
                strcpy(maxValue, result);
                ans = i;
            }
        };
        for (int i = L; i < (L / B + 1) * B && i <= R; i++) {
            check(i, XOR(A[i], s));
        }
        for (int i = L / B + 1; i < R / B; i++) {
            Node *p = &tries[i];
            REPL(j, s) {
                Node *ch = p->child[1 - (s[j] - '0')];
                if (ch) {
                    p = ch;
                    result[j] = '1';
                } else {
                    p = p->child[s[j] - '0'];
                    result[j] = '0';
                }
            }
            check(p->index, result);
        }
        if (L / B != R / B) {
            for (int i = R - R % B; i <= R; i++) {
                check(i, XOR(A[i], s));
            }
        }
        PI(ans+1);
    }
    REP(i, N) {
        delete A[i];
    }
    return 0;
}
