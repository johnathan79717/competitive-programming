#include <string>
#include <algorithm>
#include <queue>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <map>
#include <deque>
#include <climits>
#include <set>
#include <vector>
#include <functional>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <list>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define ALL(x) (x).begin(),(x).end()
#define FOR(i, c) for(auto &i: c)
#define PER(i,n) for(int i=(n)-1;i>=0;i--)
#define PER1(i,a,b) for(int i=(a);i>=(b);i--)
#define MP make_pair
#define PB push_back
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,-1,sizeof(x))
#define V(T) vector<T >
#define EB emplace_back
#define MAX(x, a) x = max(x, a)
#define MIN(x, a) x = min(x, a)
 
typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;

#line 40 "HamiltonianCircuits.cpp"
#include <string>
#include <vector>
class HamiltonianCircuits {
public:
  vector <int> findCircuit(int n, int seed, int a, int b, int c, vector <int> d, vector <int> e) {

  }
};

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
Consider a directed graph G on n vertices (labeled 0, 1, 2, ..., n-1) with exactly n*(n-1)/2 edges:
for every pair of distinct vertices (i, j) there is either an edge from i to j or an edge from j to i, but not both.
(Hence, if we ignore the orientation of edges, G is a complete graph.)




Let X be a vector <string> that contains the adjacency matrix of G.
More precisely, X[i][j] = '+' denotes that G contains an edge from i to j, and X[i][j] = '-' denotes that there is no such edge.
On the diagonal we have X[i][i] = '.' denoting that there are no self-loops in G.




A Hamiltonian circuit in G is a cycle of length n that contains each vertex of G exactly once.
Find and return a Hamiltonian circuit in G.
More precisely, return a vector <int> of length n: the order of vertices on one Hamiltonian circuit in G.
All valid Hamiltonian circuits will be accepted.
If G does not contain any Hamiltonian circuits, return an empty vector <int> instead.




In order to keep the input small, the array X is generated from the input parameters as described below.




You are given the following inputs:


The int n: the number of vertices.
The ints seed, a, b, and c. These are used to generate pseudorandom directions of all edges.
The vector <int>s d and e. These are used later to specify the directions of some edges.



Use the following pseudocode to generate X:



    value := seed
    for i = 0 .. n-1:
        X[i][i] := '.'
        for j = i+1 .. n-1:
            if (value MOD 1000) <= 250:
                X[i][j] := '+' and X[j][i] := '-' // edge from i to j.
            else
                X[i][j] := '-' and X[j][i] := '+' // edge from j to i.
            value := (a * value + b) MOD c
    m := length of d
    for k = 0 .. m-1:
        X[d[k]][e[k]] := '+'
        X[e[k]][d[k]] := '-'



DEFINITION
Class:HamiltonianCircuits
Method:findCircuit
Parameters:int, int, int, int, int, vector <int>, vector <int>
Returns:vector <int>
Method signature:vector <int> findCircuit(int n, int seed, int a, int b, int c, vector <int> d, vector <int> e)


NOTES
-The reference solution does not depend on any properties of the pseudorandom generator. It should solve any test case with n ≤ 1000 within the given limits.


CONSTRAINTS
-n will be between 3 and 1,000, inclusive.
-seed will be between 1 and 10^9, inclusive.
-a will be between 1 and 10^9, inclusive.
-b will be between 1 and 10^9, inclusive.
-c will be between 1 and 10^9, inclusive.
-d will contain between 1 and 1,000 elements, inclusive.
-e will contain between 1 and 1,000 elements, inclusive.
-d and e will contain the same number of elements.
-Each element of d will be between 0 and n-1.
-Each element of e will be between 0 and n-1.
-d[i] != e[i] for all i.


EXAMPLES

0)
3
1
1
1
1
{0,0,1}
{1,2,2}

Returns: { }

The pseudocode will generate the following adjacency matrix X:

.++
-.+
--.

In this graph there is no Hamiltonian circuit.


1)
4
1
1
1
1
{0,1,1,2,3,3}
{3,0,2,0,1,2}

Returns: {1, 2, 0, 3 }

For this input X looks as follows:

.--+
+.+-
+-.-
-++.

This graph has a single Hamiltonian circuit, but as you may start in any of its vertices, there are four correct outputs:

{0, 3, 1, 2}
{1, 2, 0, 3}
{2, 0, 3, 1}
{3, 1, 2, 0}



2)
4
1
1
1
1
{0,0,1,2,2,3,1,0}
{1,3,2,0,3,1,0,1}

Returns: {1, 2, 0, 3 }

The input describes the following X:

.+-+
-.+-
+-.+
-+-.

Note that the edge (0, 1) appeared three times in d and e (twice as (0, 1) and once as (1, 0)), 
but according to the problem statement's pseudocode only the last appearance matters.


3)
6
1
1
1
1
{5, 4, 4, 3, 2, 2, 2, 1, 1, 1, 1, 0, 0, 0, 0}
{3, 5, 2, 4, 5, 3, 0, 5, 4, 3, 2, 5, 4, 3, 1}

Returns: {3, 4, 2, 0, 1, 5 }

Here the adjacency matrix X looks as follows:

.+-+++
-.++++
+-.+-+
---.+-
--+-.+
---+-.



4)
6
987654323
999777888
979797979
987654323
{0}
{1}

Returns: { }

Here the adjacency matrix X looks as follows:

.---++
+.----
++.+--
++-.+-
-++-.-
-++++.



5)
8
2018
1337
10001
10007
{0}
{2}

Returns: {3, 4, 0, 1, 2, 7, 6, 5 }

Here the adjacency matrix X looks as follows:

.++-----
-.+--+-+
--.--+-+
+++.+---
+++-.++-
+--+-.--
++++-+.-
+--++++.



6)
50
315301770
177340464
2067825
144591777
{45,29,34,41,36,27,28,3,20,48,44,33,20,42,0,47,1,7,5,20}
{6,8,9,2,23,7,6,22,42,19,5,21,34,8,28,22,6,21,44,29}

Returns: {47, 45, 49, 43, 42, 40, 39, 37, 36, 35, 33, 34, 32, 31, 29, 26, 30, 28, 25, 24, 20, 21, 16, 14, 18, 13, 11, 9, 8, 12, 10, 7, 5, 4, 3, 2, 1, 0, 6, 15, 17, 19, 22, 23, 27, 38, 41, 44, 46, 48 }



*/
// END CUT HERE

// BEGIN CUT HERE
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
		cout << "Testing HamiltonianCircuits (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1523724146;
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
		HamiltonianCircuits _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 3;
				int seed = 1;
				int a = 1;
				int b = 1;
				int c = 1;
				int d[] = {0,0,1};
				int e[] = {1,2,2};
				int __expected[] = { };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findCircuit(n, seed, a, b, c, vector <int>(d, d+sizeof(d)/sizeof(int)), vector <int>(e, e+sizeof(e)/sizeof(int))); break;
			}
			case 1:
			{
				int n = 4;
				int seed = 1;
				int a = 1;
				int b = 1;
				int c = 1;
				int d[] = {0,1,1,2,3,3};
				int e[] = {3,0,2,0,1,2};
				int __expected[] = {1, 2, 0, 3 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findCircuit(n, seed, a, b, c, vector <int>(d, d+sizeof(d)/sizeof(int)), vector <int>(e, e+sizeof(e)/sizeof(int))); break;
			}
			case 2:
			{
				int n = 4;
				int seed = 1;
				int a = 1;
				int b = 1;
				int c = 1;
				int d[] = {0,0,1,2,2,3,1,0};
				int e[] = {1,3,2,0,3,1,0,1};
				int __expected[] = {1, 2, 0, 3 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findCircuit(n, seed, a, b, c, vector <int>(d, d+sizeof(d)/sizeof(int)), vector <int>(e, e+sizeof(e)/sizeof(int))); break;
			}
			case 3:
			{
				int n = 6;
				int seed = 1;
				int a = 1;
				int b = 1;
				int c = 1;
				int d[] = {5, 4, 4, 3, 2, 2, 2, 1, 1, 1, 1, 0, 0, 0, 0};
				int e[] = {3, 5, 2, 4, 5, 3, 0, 5, 4, 3, 2, 5, 4, 3, 1};
				int __expected[] = {3, 4, 2, 0, 1, 5 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findCircuit(n, seed, a, b, c, vector <int>(d, d+sizeof(d)/sizeof(int)), vector <int>(e, e+sizeof(e)/sizeof(int))); break;
			}
			case 4:
			{
				int n = 6;
				int seed = 987654323;
				int a = 999777888;
				int b = 979797979;
				int c = 987654323;
				int d[] = {0};
				int e[] = {1};
				int __expected[] = { };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findCircuit(n, seed, a, b, c, vector <int>(d, d+sizeof(d)/sizeof(int)), vector <int>(e, e+sizeof(e)/sizeof(int))); break;
			}
			case 5:
			{
				int n = 8;
				int seed = 2018;
				int a = 1337;
				int b = 10001;
				int c = 10007;
				int d[] = {0};
				int e[] = {2};
				int __expected[] = {3, 4, 0, 1, 2, 7, 6, 5 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findCircuit(n, seed, a, b, c, vector <int>(d, d+sizeof(d)/sizeof(int)), vector <int>(e, e+sizeof(e)/sizeof(int))); break;
			}
			case 6:
			{
				int n = 50;
				int seed = 315301770;
				int a = 177340464;
				int b = 2067825;
				int c = 144591777;
				int d[] = {45,29,34,41,36,27,28,3,20,48,44,33,20,42,0,47,1,7,5,20};
				int e[] = {6,8,9,2,23,7,6,22,42,19,5,21,34,8,28,22,6,21,44,29};
				int __expected[] = {47, 45, 49, 43, 42, 40, 39, 37, 36, 35, 33, 34, 32, 31, 29, 26, 30, 28, 25, 24, 20, 21, 16, 14, 18, 13, 11, 9, 8, 12, 10, 7, 5, 4, 3, 2, 1, 0, 6, 15, 17, 19, 22, 23, 27, 38, 41, 44, 46, 48 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findCircuit(n, seed, a, b, c, vector <int>(d, d+sizeof(d)/sizeof(int)), vector <int>(e, e+sizeof(e)/sizeof(int))); break;
			}
			/*case 7:
			{
				int n = ;
				int seed = ;
				int a = ;
				int b = ;
				int c = ;
				int d[] = ;
				int e[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findCircuit(n, seed, a, b, c, vector <int>(d, d+sizeof(d)/sizeof(int)), vector <int>(e, e+sizeof(e)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int n = ;
				int seed = ;
				int a = ;
				int b = ;
				int c = ;
				int d[] = ;
				int e[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findCircuit(n, seed, a, b, c, vector <int>(d, d+sizeof(d)/sizeof(int)), vector <int>(e, e+sizeof(e)/sizeof(int))); break;
			}*/
			/*case 9:
			{
				int n = ;
				int seed = ;
				int a = ;
				int b = ;
				int c = ;
				int d[] = ;
				int e[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findCircuit(n, seed, a, b, c, vector <int>(d, d+sizeof(d)/sizeof(int)), vector <int>(e, e+sizeof(e)/sizeof(int))); break;
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
