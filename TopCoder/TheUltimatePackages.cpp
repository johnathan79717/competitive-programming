#line 2 "TheUltimatePackages.cpp"
#include <array>
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

class TheUltimatePackages {
public:
    vector <int> count(int N, int D, vector <int> Xprefix, vector <int> Yprefix, int L, int seed) {
	vector<int> X(D), Y(D);
	int XL = Xprefix.size();

	for (int i=0; i<XL; ++i) {
	    X[i] = Xprefix[i];
	    Y[i] = Yprefix[i];
	}

	long long state = seed;
	for (int i=XL; i<D; ++i) {
	    state = (state * 1103515245 + 12345) % (1LL << 31);
	    int elen = 1 + state%L;
	    state = (state * 1103515245 + 12345) % (1LL << 31);
	    Y[i] = state % (N - elen);
	    X[i] = Y[i] + elen;
	}

	vector<VI> adj(N), rev(N);
	REP(i, D) {
	    adj[X[i]].PB(Y[i]);
	    rev[Y[i]].PB(X[i]);

	}
	VI cnt(N, 1);
	vector<bool> ok(N, true);
	REP(v, N) {
	    for (int u : adj[v]) {
		cnt[v] += cnt[u];
		cnt[u] = 0;
	    }
	    if (cnt[v] != v+1) {
		ok[v] = false;
	    }
	}
	cnt = VI(N, 1);
	for (int v = N-1; v >= 0; v--) {
	    for (int u : rev[v]) {
		cnt[v] += cnt[u];
		cnt[u] = 0;
	    }
	    if (cnt[v] != N-v) {
		ok[v] = false;
	    }
	}
	VI ans(2);
	REP(i, N) {
	    if (ok[i]) {
		ans[0]++;
		ans[1] += i;
	    }
	}
	return ans;
    }
};

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
You are maintaining a repository that contains N software packages.


Each software package x may have some dependencies: other packages that need to be installed before you can install x.


There are no cyclic dependencies between the packages.
You know this, because internally you have given the packages IDs from 0 to N-1 according to one possible way in which all of them can be installed.
Hence, whenever package x depends on package y, you can be sure that x > y.



You are now interested in ultimate packages.
These are the packages that are related to everything in the whole repository.


Formally, we say that a package x needs package y if either x directly depends on y, or x depends on some package z that needs y.


Then, we say that a package u is an ultimate package if for each other package x either u needs x or x needs u.



You are given the number of packages and all dependencies between them (as specified below).
Find all ultimate packages in the repository.
Return a vector <int> with two elements: { the number of ultimate packages, the sum of IDs of ultimate packages }.



The dependencies are given in arrays X and Y, each of length D.
For each valid i, package X[i] depends on package Y[i].
Note that the same dependency may be listed multiple times.


In order to keep the input size small, for large inputs X and Y will be generated pseudorandomly.
Below we give pseudocode, Java code and C++ code that generates X and Y from the data you are given.



Pseudocode:

X, Y = two empty arrays of length D
XL = length(Xprefix)
for i = 0 to XL-1:
    X[i] = Xprefix[i]
    Y[i] = Yprefix[i]

state = seed
for i = XL to D-1:
    state = (state * 1103515245 + 12345) modulo 2^31
    elen = 1 + (state modulo L)
    state = (state * 1103515245 + 12345) modulo 2^31
    Y[i] = state modulo (N - elen)
    X[i] = Y[i] + elen

-----------------------------------------------------

Java:

int[] X = new int[D];
int[] Y = new int[D];
int XL = Xprefix.length;
for (int i=0; i<XL; ++i) {
    X[i] = Xprefix[i];
    Y[i] = Yprefix[i];
}

long state = seed;
for (int i=XL; i<D; ++i) {
    state = (state * 1103515245 + 12345) % (1L << 31);
    int elen = (int)(1 + state%L);
    state = (state * 1103515245 + 12345) % (1L << 31);
    Y[i] = (int)(state % (N - elen));
    X[i] = Y[i] + elen;
}

-----------------------------------------------------

C++:

vector<int> X(D), Y(D);
int XL = Xprefix.size();

for (int i=0; i<XL; ++i) {
    X[i] = Xprefix[i];
    Y[i] = Yprefix[i];
}

long long state = seed;
for (int i=XL; i<D; ++i) {
    state = (state * 1103515245 + 12345) % (1LL << 31);
    int elen = 1 + state%L;
    state = (state * 1103515245 + 12345) % (1LL << 31);
    Y[i] = state % (N - elen);
    X[i] = Y[i] + elen;
}



DEFINITION
Class:TheUltimatePackages
Method:count
Parameters:int, int, vector <int>, vector <int>, int, int
Returns:vector <int>
Method signature:vector <int> count(int N, int D, vector <int> Xprefix, vector <int> Yprefix, int L, int seed)


NOTES
-The reference solution does not depend on the input being pseudorandom.


CONSTRAINTS
-N will be between 2 and 65,000, inclusive.
-D will be between 0 and 300,000, inclusive.
-Xprefix will contain between 0 and min(500,D) elements, inclusive.
-Yprefix will contain the same number of elements as Xprefix.
-For each i, N-1 >= Xprefix[i] > Yprefix[i] >= 0.
-L will be between 1 and N-1, inclusive.
-seed will be between 0 and 2^31 - 1, inclusive.


EXAMPLES

0)
5
4
{1, 3, 2, 4}
{0, 2, 1, 3}
1
47

Returns: {5, 10 }

There are five packages and four dependencies: 4 depends on 3, 3 depends on 2, 2 depends on 1, and 1 depends on 0. Each of these five packages is ultimate.

1)
5
6
{1, 2, 3, 4, 4, 4}
{0, 0, 0, 1, 3, 2}
1
64

Returns: {2, 4 }


There are five packages: 1, 2, and 3 each depend on 0 and 4 depends on 1, 2, and 3.


Ultimate packages are packages 0 and 4.


2)
5
4
{2, 2, 3, 4}
{0, 1, 2, 2}
1
32532

Returns: {1, 2 }

The only ultimate package here is package 2.

3)
4
3
{3, 3, 2}
{0, 2, 1}
1
2555

Returns: {1, 3 }

The only ultimate package here is package 3, because it needs all other packages.

4)
7
0
{}
{}
1
0

Returns: {0, 0 }

No ultimate packages here.

5)
2
4
{1, 1, 1, 1}
{0, 0, 0, 0}
1
0

Returns: {2, 1 }

A dependence listed four times is the same thing as a dependence listed once.

6)
7
12
{2, 3, 4}
{1, 2, 3}
5
4747

Returns: {0, 0 }

The generated arrays X and Y look as follows:


X = { 2, 3, 4, 5, 6, 4, 4, 5, 4, 4, 5, 6 }
Y = { 1, 2, 3, 1, 1, 1, 0, 1, 0, 1, 1, 1 }



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
		cout << "Testing TheUltimatePackages (600.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1621700564;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 600.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		TheUltimatePackages _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 5;
				int D = 4;
				int Xprefix[] = {1, 3, 2, 4};
				int Yprefix[] = {0, 2, 1, 3};
				int L = 1;
				int seed = 47;
				int __expected[] = {5, 10 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.count(N, D, vector <int>(Xprefix, Xprefix+sizeof(Xprefix)/sizeof(int)), vector <int>(Yprefix, Yprefix+sizeof(Yprefix)/sizeof(int)), L, seed); break;
			}
			case 1:
			{
				int N = 5;
				int D = 6;
				int Xprefix[] = {1, 2, 3, 4, 4, 4};
				int Yprefix[] = {0, 0, 0, 1, 3, 2};
				int L = 1;
				int seed = 64;
				int __expected[] = {2, 4 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.count(N, D, vector <int>(Xprefix, Xprefix+sizeof(Xprefix)/sizeof(int)), vector <int>(Yprefix, Yprefix+sizeof(Yprefix)/sizeof(int)), L, seed); break;
			}
			case 2:
			{
				int N = 5;
				int D = 4;
				int Xprefix[] = {2, 2, 3, 4};
				int Yprefix[] = {0, 1, 2, 2};
				int L = 1;
				int seed = 32532;
				int __expected[] = {1, 2 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.count(N, D, vector <int>(Xprefix, Xprefix+sizeof(Xprefix)/sizeof(int)), vector <int>(Yprefix, Yprefix+sizeof(Yprefix)/sizeof(int)), L, seed); break;
			}
			case 3:
			{
				int N = 4;
				int D = 3;
				int Xprefix[] = {3, 3, 2};
				int Yprefix[] = {0, 2, 1};
				int L = 1;
				int seed = 2555;
				int __expected[] = {1, 3 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.count(N, D, vector <int>(Xprefix, Xprefix+sizeof(Xprefix)/sizeof(int)), vector <int>(Yprefix, Yprefix+sizeof(Yprefix)/sizeof(int)), L, seed); break;
			}
			case 4:
			{
				int N = 7;
				int D = 0;
				int Xprefix[] = {};
				int Yprefix[] = {};
				int L = 1;
				int seed = 0;
				int __expected[] = {0, 0 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.count(N, D, vector <int>(Xprefix, Xprefix+sizeof(Xprefix)/sizeof(int)), vector <int>(Yprefix, Yprefix+sizeof(Yprefix)/sizeof(int)), L, seed); break;
			}
			case 5:
			{
				int N = 2;
				int D = 4;
				int Xprefix[] = {1, 1, 1, 1};
				int Yprefix[] = {0, 0, 0, 0};
				int L = 1;
				int seed = 0;
				int __expected[] = {2, 1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.count(N, D, vector <int>(Xprefix, Xprefix+sizeof(Xprefix)/sizeof(int)), vector <int>(Yprefix, Yprefix+sizeof(Yprefix)/sizeof(int)), L, seed); break;
			}
			case 6:
			{
				int N = 7;
				int D = 12;
				int Xprefix[] = {2, 3, 4};
				int Yprefix[] = {1, 2, 3};
				int L = 5;
				int seed = 4747;
				int __expected[] = {0, 0 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.count(N, D, vector <int>(Xprefix, Xprefix+sizeof(Xprefix)/sizeof(int)), vector <int>(Yprefix, Yprefix+sizeof(Yprefix)/sizeof(int)), L, seed); break;
			}
			/*case 7:
			{
				int N = ;
				int D = ;
				int Xprefix[] = ;
				int Yprefix[] = ;
				int L = ;
				int seed = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.count(N, D, vector <int>(Xprefix, Xprefix+sizeof(Xprefix)/sizeof(int)), vector <int>(Yprefix, Yprefix+sizeof(Yprefix)/sizeof(int)), L, seed); break;
			}*/
			/*case 8:
			{
				int N = ;
				int D = ;
				int Xprefix[] = ;
				int Yprefix[] = ;
				int L = ;
				int seed = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.count(N, D, vector <int>(Xprefix, Xprefix+sizeof(Xprefix)/sizeof(int)), vector <int>(Yprefix, Yprefix+sizeof(Yprefix)/sizeof(int)), L, seed); break;
			}*/
			/*case 9:
			{
				int N = ;
				int D = ;
				int Xprefix[] = ;
				int Yprefix[] = ;
				int L = ;
				int seed = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.count(N, D, vector <int>(Xprefix, Xprefix+sizeof(Xprefix)/sizeof(int)), vector <int>(Yprefix, Yprefix+sizeof(Yprefix)/sizeof(int)), L, seed); break;
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
			cout << "           Expected: {";
			for (unsigned i = 0; i < _expected.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _expected[i];
			}
			cout << " }" << endl;
			cout << "           Received: {";
			for (unsigned i = 0; i < _received.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _received[i];
			}
			cout << " }" << endl;
		}
	}
}

// END CUT HERE
