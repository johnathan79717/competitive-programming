#line 2 "DiscountedShortestPaths.cpp"
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
int MOD = 1e9+7;
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}

class DiscountedShortestPaths {
public:
    long long minimumCostSum(int n, vector <int> a, vector <int> b, vector <int> c, vector <int> d) {
	vector<vector<PII>> adj(n);
	REP(i, SZ(a)) {
	    adj[a[i]].PB(b[i], c[i]);
	    adj[b[i]].PB(a[i], c[i]);
	}
	sort(ALL(d), greater<int>());
	vector<vector<LL>> ans(n, VL(n, 1e18));
	REP(mask, 1<<n) {
	    int p = 0;
	    unordered_set<int> Q;
	    REP(i, n) {
		if ((mask >> i) & 1) {
		    p++;
		    Q.insert(i);
		}
	    }
	    if (SZ(Q) < 2) {
		continue;
	    }
	    unordered_map<int, int> C;
	    for (int q : Q) {
		C[q] = MOD;
	    }
	    VI mst;
	    while (Q.size()) {
		int v = *Q.begin();
		for (int q : Q) {
		    if (C[q] < C[v]) {
			v = q;
		    }
		}
		if (C[v] < MOD) mst.PB(C[v]);
		Q.erase(v);
		for (auto &pr : adj[v]) {
		    if (Q.count(pr.F) && pr.S < C[pr.F]) {
			C[pr.F] = pr.S;
		    }
		}
	    }
	    if (SZ(mst) < p-1) {
		continue;
	    }
	    sort(ALL(mst), greater<int>());
	    LL c = 0;
	    REP(i, SZ(mst)) {
		if (i < SZ(d)) {
		    c += max(0, mst[i] - d[i]);
		} else {
		    c += mst[i];
		}
	    }
	    REP(i, n) {
		if ((mask >> i) & 1) {
		    REPP(j, i+1, n) {
			if ((mask >> j) & 1) {
			    ans[i][j] = min(ans[i][j], c);
			}
		    }
		}
	    }
	}
	LL sum = 0;
	REP(s, n) {
	    REPP(t, s+1, n) {
		sum += ans[s][t];
	    }
	}
	return sum;
    }
};

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
//  Please note the unusual time and memory limits in this problem: 4 seconds, 48 MB.


There are  n  cities numbered 0 to n-1.
Some pairs of cities are connected by flights.
All flights are bidirectional.
The network is connected: it is possible to travel between any two cities (directly or indirectly).



You are given n and the list of flights: the vector <int>s a, b, c.
For each valid i, there is a bidirectional flight that connects cities a[i] and b[i] and has a cost c[i] in either direction.




You have some discount coupons, each with some value.
These values are given in the vector <int> d.
For each flight you take you can only use at most one discount coupon.
Also, each discount coupon can only be used once.
If you have a flight with cost C and you use a discount coupon with value D, the new cost of the flight is what remains: max(0, C-D).




For each pair of cities s < t, consider the following problem:
Suppose we want to travel from s to t with the given flight costs and the given discount coupons.
What is the minimum total cost f(s, t) of our trip?



Calculate and return the sum of all f(s, t).


DEFINITION
Class:DiscountedShortestPaths
Method:minimumCostSum
Parameters:int, vector <int>, vector <int>, vector <int>, vector <int>
Returns:long long
Method signature:long long minimumCostSum(int n, vector <int> a, vector <int> b, vector <int> c, vector <int> d)


NOTES
-Each of the values f(s, t) is defined as an answer to a separate problem. Those problems don't influence each other. In particular, the optimal solutions for different f(s, t) may use overlapping sets of discount coupons.


CONSTRAINTS
- n  will be between 2 and 20, inclusive.
- a  will have between n - 1 and n(n - 1) / 2 elements, inclusive.
-a, b and c will have the same number of elements.
- d  will have between 0 and 20 elements, inclusive.
-Between any two cities, there will be a direct or indirect path using flights.
-For each valid i, a[i] and b[i] will be between 0 and n - 1, inclusive.
-For each valid i, c[i] will be between 1 and 10 9 , inclusive.
-For each valid i, d[i] will be between 1 and 10 9 , inclusive.
-There will be no flight from a city to itself, and no two flights will connect the same pair of cities. 


EXAMPLES

0)
2
{0}
{1}
{10}
{5, 6}

Returns: 4

The travel cost f(0, 1) is 10 - 6 = 4. (Use the only flight and the bigger discount coupon.)

1)
3
{0, 1, 2}
{1, 2, 0}
{3, 3, 7}
{2, 2, 2}

Returns: 4



 f(0, 1) = 1 (use the flight between 0 and 1 and apply a discount coupon). 

 f(1, 2) = 1 (use the flight between 1 and 2 and apply a discount coupon). 

 f(0, 2) = 2 (go from 0 to 1, then from 1 to 2, using a discount coupon on both flights). 



2)
3
{0, 1, 2}
{1, 2, 0}
{3, 3, 7}
{1, 6, 1}

Returns: 1



3)
10
{0, 1, 2, 3, 4, 5, 6, 7, 8}
{1, 2, 3, 4, 5, 6, 7, 8, 9}
{1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000}
{}

Returns: 165000000000



*/
#include <ctime>
#include <cmath>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[])
{
	if (argc == 1) 
	{
		cout << "Testing DiscountedShortestPaths (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1607795246;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 1000.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		DiscountedShortestPaths _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 2;
				int a[] = {0};
				int b[] = {1};
				int c[] = {10};
				int d[] = {5, 6};
				_expected = 4LL;
				_received = _obj.minimumCostSum(n, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(c, c+sizeof(c)/sizeof(int)), vector <int>(d, d+sizeof(d)/sizeof(int))); break;
			}
			case 1:
			{
				int n = 3;
				int a[] = {0, 1, 2};
				int b[] = {1, 2, 0};
				int c[] = {3, 3, 7};
				int d[] = {2, 2, 2};
				_expected = 4LL;
				_received = _obj.minimumCostSum(n, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(c, c+sizeof(c)/sizeof(int)), vector <int>(d, d+sizeof(d)/sizeof(int))); break;
			}
			case 2:
			{
				int n = 3;
				int a[] = {0, 1, 2};
				int b[] = {1, 2, 0};
				int c[] = {3, 3, 7};
				int d[] = {1, 6, 1};
				_expected = 1LL;
				_received = _obj.minimumCostSum(n, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(c, c+sizeof(c)/sizeof(int)), vector <int>(d, d+sizeof(d)/sizeof(int))); break;
			}
			case 3:
			{
				int n = 10;
				int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
				int b[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
				int c[] = {1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000};
				int d[] = {};
				_expected = 165000000000LL;
				_received = _obj.minimumCostSum(n, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(c, c+sizeof(c)/sizeof(int)), vector <int>(d, d+sizeof(d)/sizeof(int))); break;
			}
			/*case 4:
			{
				int n = ;
				int a[] = ;
				int b[] = ;
				int c[] = ;
				int d[] = ;
				_expected = LL;
				_received = _obj.minimumCostSum(n, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(c, c+sizeof(c)/sizeof(int)), vector <int>(d, d+sizeof(d)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int n = ;
				int a[] = ;
				int b[] = ;
				int c[] = ;
				int d[] = ;
				_expected = LL;
				_received = _obj.minimumCostSum(n, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(c, c+sizeof(c)/sizeof(int)), vector <int>(d, d+sizeof(d)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int n = ;
				int a[] = ;
				int b[] = ;
				int c[] = ;
				int d[] = ;
				_expected = LL;
				_received = _obj.minimumCostSum(n, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(c, c+sizeof(c)/sizeof(int)), vector <int>(d, d+sizeof(d)/sizeof(int))); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (_received == _expected)
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
