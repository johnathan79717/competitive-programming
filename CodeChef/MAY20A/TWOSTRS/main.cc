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

#include <unordered_set>
#include <unordered_map>
#define EB emplace_back
#define RL(x) scanf("%lld", &(x))
#define PL(x) printf("%lld\n", x)
#define DRL(x) LL x; RL(x)

//int equiv[1000];

template<int ALPHABET_SIZE, unsigned char MINIMAL_CHAR>
struct TrieNode {
    TrieNode* l[ALPHABET_SIZE], *suffix, *dictsuffix, *root;
    int index, score;  // P的編號

    TrieNode(TrieNode* root): suffix(0), dictsuffix(0), index(-1), score(0) {
        memset(l, 0, sizeof(l));
        this->root = root ? root : this;
    }

    // 把一個字串加入trie
    void add(char* s, int idx, int sc) {
        TrieNode* p = this;
        for (; *s; ++s) {
            if (!p->l[*s - MINIMAL_CHAR])
                p->l[*s - MINIMAL_CHAR] = new TrieNode(root);
            p = p->l[*s - MINIMAL_CHAR];
        }

        // 如果此字串之前有出現，就特別紀錄起來。
        if (p->index == -1) {
            p->index = idx;
            p->score = sc;
        } else {
            assert(false);
            //equiv[index] = p->index;
        }
    }

    // 添上suffix link和dictionary suffix link
    // 以BFS順序進行
    // 時間複雜度O(Σ(Pi))
    void build() {
        queue<TrieNode*> que;
        que.push(this);

        while (que.size()) {
            TrieNode* p = que.front();
            que.pop();
            for (int i=0; i<ALPHABET_SIZE; ++i)
                if (p->l[i])
                {
                    // 添上 suffix link
                    TrieNode* q = p->suffix;
                    while (q && !q->l[i]) q = q->suffix;
                    if (q) p->l[i]->suffix = q->l[i];
                    else   p->l[i]->suffix = this;

                    // 添上 dictionary suffix link
                    TrieNode* r = p->l[i]->suffix;
                    if (r->index != -1) p->l[i]->dictsuffix = r;
                    else p->l[i]->dictsuffix = r->dictsuffix;

                    if (p->l[i]->dictsuffix) {
                        p->l[i]->score += p->l[i]->dictsuffix->score;
                    }

                    que.push(p->l[i]);
                }
        }
    }

    TrieNode* match(char c) {
        TrieNode *p = this;
        while (p && !p->l[c - MINIMAL_CHAR]) {
            p = p->suffix;
        }
        p = p ? p->l[c - MINIMAL_CHAR] : root;
        return p;
    }

    vector<int> matched_indices() {
        vector<int> ret;
        if (index != -1) {
            ret.push_back(index);
        }
        for (TrieNode* q = this->dictsuffix; q; q = q->dictsuffix) {
            ret.push_back(q->index);
        }
        return ret;
    }

    // 砍掉整棵trie
    ~TrieNode() {
        for (int i = 0; i < ALPHABET_SIZE; ++i) {
            if (l[i]) {
                delete l[i];
            }
        }
    }
};

typedef TrieNode<26, 'a'> Trie;

Trie *trie, *rev_trie;

char A[1005], B[1005], S[10006][27];
int b[10005], LS[10006];
LL scoreB[1005][27];

void solve() {
    RS(A); RS(B);
    trie = new Trie(NULL);
    rev_trie = new Trie(NULL);
    DRI(N);
    REP(i, N) {
        RS(S[i]);
        RI(b[i]);
        LS[i] = LEN(S[i]);
        trie->add(S[i], i, b[i]);
        reverse(S[i], S[i] + strlen(S[i]));
        rev_trie->add(S[i], i, b[i]);
    }
    rev_trie->build();
    int LA = LEN(A), LB = LEN(B);
    Trie *pB = rev_trie;
    MS0(scoreB);
    PER(j, LB) {
        pB = pB->match(B[j]);
        REP1(l, 1, 25) {
            scoreB[j][l+1] += scoreB[j+1][l];
        }
        scoreB[j][26] += scoreB[j+1][26];
        for (int k : pB->matched_indices()) {
            scoreB[j][LS[k]] += b[k];
        }
    }

    trie->build();
    Trie *pA = trie;
    LL scoreA = 0, ans = 0;
    REP(i, LA) {
        pA = pA->match(A[i]);
        scoreA += pA->score;
        REP(j, LB) {
            LL score = scoreA;
            Trie *q = pA;
            REP(l, 25) {
                if (j + l >= LB) break;
                q = q->match(B[j+l]);
                score += q->score;
            }
            score += scoreB[j][26];
            ans = max(ans, score);
        }
    }
    PL(ans);
}

int main() {
    CASET {
        solve();
    }
    return 0;
}
