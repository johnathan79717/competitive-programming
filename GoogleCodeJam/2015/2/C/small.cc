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
#include <sstream>
using namespace std;
#define FOR(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define MAX(x, a) x = max(x, a)
#define MIN(x, a) x = min(x, a)
#define ALL(x) (x).begin(),(x).end()
#define CASET2 int ___T, case_n = 1; scanf("%d ", &___T); while ((___T > 0 ? printf("Case #%d:\n", case_n++) : 0), ___T-- > 0)
#define CASET1 int ___T, case_n = 1; scanf("%d ", &___T); while ((___T > 0 ? printf("Case #%d: ", case_n++) : 0), ___T-- > 0)
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define SZ(X) ((int)(X).size())
#define LEN(X) strlen(X)
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
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
#define PI(x) printf("%d\n",x)
#define PIS(x) printf("%d ",x)
#define MP make_pair
#define PB push_back
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,-1,sizeof(x))
#define F first
#define S second
#define V(x) vector<x >

int popcount(unsigned x) { return __builtin_popcount(x); } 
int popcount(unsigned long long x) { return __builtin_popcountll(x); } 

typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long LL;
const int INF = 1000000000;

#include <unordered_set>
#include <unordered_map>

#define PL(x) printf("%lld\n", x);

int main() {
  DRI(T);
  REP1(t, 1, T) {
    printf("Case #%d: ", t);
    DRI(N);
    cin.ignore();
    vector<string> en, fr;
    string sentence;
    getline(cin, sentence);
    istringstream iss(sentence);
    for_each(istream_iterator<string>(iss), istream_iterator<string>(), [&en](const string &s) {
        en.PB(s);
    });
    sort(ALL(en));

    getline(cin, sentence);
    iss = istringstream(sentence);
    for_each(istream_iterator<string>(iss), istream_iterator<string>(), [&fr](const string &s) {
        fr.PB(s);
    });
    sort(ALL(fr));

    V(V(string)) str(N-2);
    REP(i, N-2) {
        getline(cin, sentence);
        iss = istringstream(sentence);
        for_each(istream_iterator<string>(iss), istream_iterator<string>(), [&str, i](const string &s) {
            str[i].PB(s);
        });
    }
    V(string) en1, fr1, same;
    auto it1 = en.begin(), it2 = fr.begin();
    while (it1 != en.end() && it2 != fr.end()) {
        if (*it1 == *it2) {
            same.PB(*it1);
            it1++;
            it2++;
        } else if (*it1 < *it2) {
            en1.PB(*it1);
            it1++;
        } else {
            fr1.PB(*it2);
            it2++;
        }
    }
    while (it1 != en.end()) {
        en1.PB(*it1++);
    }
    while (it2 != fr.end()) {
        fr1.PB(*it2++);
    }
    swap(en, en1);
    swap(fr, fr1);
    
    int ans = INT_MAX;
    REP(mask, 1 << (N-2)) {
        vector<string> e, f;
        REP(i, N-2) {
            if ((mask >> i) & 1) {
                for(string &s: str[i]) {
                    e.PB(s);
                }
            } else {
                for(string &s: str[i]) {
                    f.PB(s);
                }
            }
        }
        V(string) a;
        auto it1 = e.begin(), it2 = f.begin();
        while (it1 != e.end() && it2 != f.end()) {
            if (*it1 == *it2) {
                // cnt++;
                a.PB(*it1);
                it1++;
                it2++;
            } else if (*it1 < *it2) {
                auto it = lower_bound(ALL(fr), *it1);
                if (it != fr.end() && *it == *it1) {
                    a.PB(*it);
                }
                it1++;
            } else {
                auto it = lower_bound(ALL(en), *it2);
                if (it != en.end() && *it == *it2) {
                    a.PB(*it);
                }
                it2++;
            }
        }
        while (it1 != e.end()) {
            auto it = lower_bound(ALL(fr), *it1);
            if (it != fr.end() && *it == *it1) {
                a.PB(*it);
            }
            it1++;
        }
        while (it2 != f.end()) {
            auto it = lower_bound(ALL(en), *it2);
            if (it != en.end() && *it == *it2) {
                a.PB(*it);
            }
            it2++;
        }
        sort(ALL(a));
        a.resize(unique(ALL(a)) - a.begin());
        int cnt = 0;
        for(auto &aa: a) {
            auto it = lower_bound(ALL(same), aa);
            if (it == same.end() || *it != aa) {
                cnt++;
            }
        }

        MIN(ans, cnt);
    }
    PI(ans + SZ(same));
    // cerr << ans + same << endl;
  }
  return 0;
}
