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
#include <cassert>
#include <deque>
#include <stack>
#include <functional>
#include <bitset>
#include <numeric>
#define int LL
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
void _R(int64_t &x) { scanf("%lld", &x);  }
void _R(double &x) { scanf("%lf", &x);  }
void _R(char &x) { scanf(" %c", &x);  }
void _R(char *x) { scanf("%s", x);  }
void R() {}
template<class T, class... U> void R(T &head, U &... tail) { _R(head); R(tail...);  }
template<class T> void _W(const T &x) { cout << x;  }
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

#define MULTITEST 1
void solve() {
    int N;
    R(N);    
    set<string> s;
    REP(i, N) {
		char t[25];
		R(t);
        s.emplace(t);
    }
    //int ver = 0;
    //for (auto &a : s) {
        //for (auto &b : s) {
            //if (!s.count(a.substr(0, 1) + b.substr(1)) && !s.count(b.substr(0, 1) + a.substr(1))) {
                //ver++;
            //}
        //}
    //}
    //assert(s.size() == N);
    //W(ver);
	 int ans = N * N;
	 vector<vector<string>> byHead(26);
	 for (auto &s : s) {
		 char head = s[0];
		 string tail = s.substr(1);
		 byHead[head - 'a'].PB(tail);
	 }
	 REP(i, 26) {
		 ans -= byHead[i].size() * byHead[i].size();
		 sort(ALL(byHead[i]));
	 }
	 debug(ans);
	 for (auto &t : s) {
		 string tail = t.substr(1);
		 REP(i, 26) {
			 char c = 'a' + i;
			 if (c != t[0] && s.count(c + tail)) {
				 ans -= 2 * byHead[i].size();
			 }
		 }
	 }
	 debug(ans);
	 REP(i, 26) {
		 if (byHead[i].empty()) continue;
		 REP(j, i) {
			 if (byHead[j].empty()) continue;
			 vector<string> a;
			 a.reserve(byHead[i].size() + byHead[j].size());
			 set_intersection(ALL(byHead[i]), ALL(byHead[j]), back_inserter(a));
			 ans += 2 * a.size() * a.size();
			 debug(ans, a.size());
		 }
	 }
	 //assert(ans == ver);
	 W(ans);
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

