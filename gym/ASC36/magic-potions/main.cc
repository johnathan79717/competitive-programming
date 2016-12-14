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
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
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
int popcount(unsigned x) { return __builtin_popcount(x); } 
int popcount(unsigned long long x) { return __builtin_popcountll(x); } 

#include <unordered_set>
#include <unordered_map>
#define PL(x) printf("%lld\n",x)
void print(LL i) { PL(i); }
#define EB emplace_back
#define RL(x) scanf("%lld",&x)
#define DRL(x) LL x;RL(x)

int A[100005];
map<PII,int> ans;
void print() {
    PI(SZ(ans));
    for (auto &pr: ans) {
        PIS(pr.X.X); PIS(pr.X.Y); PI(pr.Y);
    }
    exit(0);
}

int N;
void finish(int k) {
    REP1(i, 1, N) {
        if (i != k && A[i] > 0 && A[k] > 0) {
            ans[minmax(i, k)] += min(A[i], A[k]);
            A[k] -= min(A[i], A[k]);
        }
    }
    print();
}

struct Potion {
    int amount, id;
    bool operator< (const Potion& other) const {
        if (amount != other.amount) {
            return amount < other.amount;
        } else {
            return id > other.id;
        }
    }
};

int main() {
#ifdef ONLINE_JUDGE
    freopen("magic.in", "r", stdin);
    freopen("magic.out", "w", stdout);
#endif
    RI(N);
    LL sum = 0;
    REP1(i, 1, N) {
        RI(A[i]);
        sum += A[i];
    }
    priority_queue<Potion> pq;
    REP1(i, 1, N) {
        if (A[i] >= sum - A[i]) {
            finish(i);
        }
        pq.push(Potion{A[i], i});
    }
    int i = 1, j = 2;
    while (pq.size()) {
        while (A[i] == 0) i++;
        j = i+1;
        while (A[j] == 0) j++;
        int k = pq.top().id;
        if (k == i || k == j || pq.top().amount != A[k]) {
            pq.pop();
            continue;
        }
        int d = min((LL)min(A[i], A[j]), (sum - A[k] * 2 + 1) / 2);
        assert(d > 0);
        sum -= d * 2;
        A[i] -= d;
        A[j] -= d;
        assert(A[i] >= 0 && A[j] >= 0 && sum > 0);
        ans[MP(i, j)] += d;
        if (sum - A[k] <= A[k]) {
            finish(k);
        }
    }
    if (A[i] && A[j]) {
        assert(A[i] == A[j]);
        ans[MP(i, j)] += A[i];
    }
    print();
    return 0;
}