#line 2 "RandomDijkstraDiv2.cpp"
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

class RandomDijkstraDiv2 {
public:
    double solve(int N, vector <int> G) {
	VI D(N);
	REP(i, N) {
	    D[i] = G[i];
	}
	REP(k, N) {
	    REP(i, N) {
		REP(j, N) {
		    D[i] = min(D[i], D[j] + G[j*N+i]);
		}
	    }
	}
	int MAX = 1;
	REP(i, N) {
	    MAX *= 3;
	}
	vector<LL> dp(MAX);
	dp[1] = 1;
	REP(mask, MAX) {
	    if (dp[mask] == 0) continue;
	    auto s = [N, mask]() mutable {
		VI s(N);
		REP(i, N) {
		    s[i] = mask % 3;
		    mask /= 3;
		}
		return s;
	    }();
	    REP(i, N) {
		if (s[i] == 1) {
		    int newMask = [s, i, N, &D, &G]() mutable {
			s[i] = 2;
			REP(j, N) {
			    if (s[j] == 0 && D[j] == D[i] + G[i*N+j]) {
				s[j] = 1;
			    }
			}
			int m = 0;
			for (int i = N-1; i >= 0; i--) {
			    m = m * 3 + s[i];
			}
			return m;
		    }();
		    dp[newMask] += dp[mask];
		}
	    }
	}
	double ans = dp[MAX-1];
	FOR(i, 1, N) {
	    ans /= i;
	}
	return ans;
    }
};

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
Given is a complete directed graph on N vertices.
The vertices are numbered from 0 to N-1.
For each pair of distinct vertices u and v, the edge from u to v has a non-negative length dist[u,v].


You are given the edge lengths in the vector <int> G.
For each u and v, dist[u,v] = G[u*N+v].



You wanted to compute the shortest paths from 0 to all other vertices, so you implemented Dijkstra's algorithm.
Here is the pseudocode that corresponds to your implementation:



1) S = set of all vertices
2) D[0] = 0
3) for i = 1 to N-1: D[i] = infinity

4) while (S is not empty):
5)     find u in S such that D[u] is minimal among all D[i] where i is in S
6)     remove u from S
7)     for each v in S:
8)         if D[v] > D[u] + dist[u,v]:
9)             D[v] = D[u] + dist[u,v]




The above pseudocode is an actual correct version of Dijkstra's algorithm.
When it terminates, each value D[i] is the length of the shortest path from vertex 0 to vertex i.



Your friend then decided to prank you and edited line 5) in the above code to the following one:




5')     select u from S uniformly at random




Calculate and return the probability that the modified algorithm will calculate the entire array D correctly.




DEFINITION
Class:RandomDijkstraDiv2
Method:solve
Parameters:int, vector <int>
Returns:double
Method signature:double solve(int N, vector <int> G)


NOTES
-Your return value will be accepted if it has a relative or an absolute error at most 1e-9.
-Note that the cycle in lines 7-9 of the pseudocode iterates just over all vertices v that are still in the set S (i.e., those that have not been processed yet).


CONSTRAINTS
-N will be between 1 and 15, inclusive.
-G will have exactly N*N elements.
-Each element of G will be between 0 and 10^6, inclusive.
-For each u, G[u*N+u] will be 0.


EXAMPLES

0)
4
{ 0, 1, 1000, 1000, 1000, 0, 1, 1000, 1000, 1000, 0, 1, 1000, 1000, 1000, 0 }

Returns: 0.041666666666666664

A graph on 4 vertices. The edges 0 -> 1, 1 -> 2, and 2 -> 3 each have length 1, all other edges have length 1000. You will only get the correct array of distances if you remove the vertices in order 0, 1, 2, 3. That happens with probability (1/4) * (1/3) * (1/2).

1)
4
{ 0, 1, 1, 1, 1, 0, 1000, 1000, 1, 1000, 0, 1000, 1, 1000, 1000, 0 }

Returns: 0.25

In this case the edges between 0 and each other vertex are short and all other edges are long. We will compute the correct array of distances if and only if we process vertex 0 first. That happens with probability 1/4.

2)
5
{
      0, 1000, 1000,    4,    5,
   1000,    0, 1000, 1000, 1000,
   1000,    2,    0, 1000, 1000,
   1000, 1000,    6,    0, 1000,
   1000,    7, 1000, 1000,    0
}

Returns: 0.058333333333333334

The exact answer for this test case is 7/120.

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
		cout << "Testing RandomDijkstraDiv2 (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1603578345;
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
		RandomDijkstraDiv2 _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 4;
				int G[] = { 0, 1, 1000, 1000, 1000, 0, 1, 1000, 1000, 1000, 0, 1, 1000, 1000, 1000, 0 };
				_expected = 0.041666666666666664;
				_received = _obj.solve(N, vector <int>(G, G+sizeof(G)/sizeof(int))); break;
			}
			case 1:
			{
				int N = 4;
				int G[] = { 0, 1, 1, 1, 1, 0, 1000, 1000, 1, 1000, 0, 1000, 1, 1000, 1000, 0 };
				_expected = 0.25;
				_received = _obj.solve(N, vector <int>(G, G+sizeof(G)/sizeof(int))); break;
			}
			case 2:
			{
				int N = 5;
				int G[] = {
				                0, 1000, 1000,    4,    5,
				             1000,    0, 1000, 1000, 1000,
				             1000,    2,    0, 1000, 1000,
				             1000, 1000,    6,    0, 1000,
				             1000,    7, 1000, 1000,    0
				          };
				_expected = 0.058333333333333334;
				_received = _obj.solve(N, vector <int>(G, G+sizeof(G)/sizeof(int))); break;
			}
			/*case 3:
			{
				int N = ;
				int G[] = ;
				_expected = ;
				_received = _obj.solve(N, vector <int>(G, G+sizeof(G)/sizeof(int))); break;
			}*/
			/*case 4:
			{
				int N = ;
				int G[] = ;
				_expected = ;
				_received = _obj.solve(N, vector <int>(G, G+sizeof(G)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int N = ;
				int G[] = ;
				_expected = ;
				_received = _obj.solve(N, vector <int>(G, G+sizeof(G)/sizeof(int))); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (abs(_expected-_received) < 1e-9 || (_received > min(_expected*(1.0-1e-9), _expected*(1.0+1e-9)) && _received < max(_expected*(1.0-1e-9), _expected*(1.0+1e-9))))
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout.precision(10);
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
