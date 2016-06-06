#include <string>
#include <cassert>
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
// #line 40 "CliqueCuts.cpp"
#include <string>
#include <vector>
class CliqueCuts {
public:
    int sum(int n, vector <int> a, vector <int> b, vector <int> c) {
        
    }
};
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// This problem has a non-standard time limit: 5 seconds.


Alice and Bob play a game using an undirected weighted graph.
The graph has no self-loops and no multiple edges.
The graph has n nodes.
The nodes are numbered 0 through n-1.



You are given the int n.
You are also given three vector <int>s: a, b, and c, each with the same number of elements.
For each valid i, there is an edge that connects nodes a[i] and b[i], and the weight of this edge is c[i].



In the first step of the game Alice chooses a nonempty subset of the nodes of the graph and paints them red.
This subset must form a clique in the graph.
(I.e., each pair of nodes selected by Alice must be connected by an edge.
Specifically, Alice is allowed to select any single node.
Alice is also allowed to select all nodes, if the entire graph is a clique.)



Next, Bob colors all the remaining nodes blue.
These nodes are not required to form a clique.



Alice's score is the sum of weights of all edges that have both endpoints red.
Similarly, Bob's score is the sum of weights of all edges that have both endpoints blue.
The result of the game is computed as Alice's score minus Bob's score.
Note that the result of the game may be negative.



Given the graph, consider all valid sets of vertices Alice can choose.
For each of those sets we can compute the result of the game.
Let S be the sum of all those results.
Compute and return the value (S modulo 1,000,000,007).


DEFINITION
Class:CliqueCuts
Method:sum
Parameters:int, vector <int>, vector <int>, vector <int>
Returns:int
Method signature:int sum(int n, vector <int> a, vector <int> b, vector <int> c)


CONSTRAINTS
-n will be between 2 and 45, inclusive.
-m will be between 0 and n*(n-1)/2, inclusive.
-a,b,c will each have exactly m elements each.
-Each element of a,b will be between 0 and n-1, inclusive.
-Each element of c will be between 0 and 10^9, inclusive.
-The edges (a[i], b[i]) form a simple undirected graph with no self-loops or multiple edges.


EXAMPLES

0)
2
{0}
{1}
{100}

Returns: 100

The graph has 2 nodes and a single edge: the edge 0-1 with weight 100.
Alice has three valid choices: she can choose either {0}, or {1}, or {0,1}.

In the first case: Alice's score is 0, Bob's score is 0, hence the result of the game is 0-0 = 0.
In the second case: Alice's score is 0, Bob's score is 0, hence the result of the game is 0-0 = 0.
In the third case: Alice's score is 100, Bob's score is 0, hence the result of the game is 100-0 = 100.

The sum of all possible results is S = 0 + 0 + 100 = 100.

1)
5
{0,0,0,0,1,1,1,2,2,3}
{1,2,3,4,2,3,4,3,4,4}
{0,1,2,3,4,5,6,7,8,9}

Returns: 45



2)
5
{0,1,2,3}
{1,2,3,4}
{9,2,4,3}

Returns: 999999941

This graph is the line 0-1-2-3-4.
The edge weights are 9, 2, 4, and 3, respectively.

As there is no triangle in this graph, Alice can only choose either a single vertex or two adjacent vertices.
Thus, she has the following options: {0}, {1}, {2}, {3}, {4}, {0,1}, {1,2}, {2,3}, and {3,4}.
Alice's scores in these cases are 0, 0, 0, 0, 0, 9, 2, 4, and 3.
Bob's corresponding scores are 9, 7, 12, 11, 15, 7, 3, 9, and 11.

Thus, there are nine possible results of the game: -9, -7, -12, -11, -15, 2, -1, -5, and -8, which gives us S = -66.
As we are supposed to return S modulo 1,000,000,007, the correct return value is 999,999,941.

3)
10
{0,1,2,9,5,3,4,7,3,4,1,5,2,3,0,7,8}
{6,7,4,5,6,2,6,3,1,8,2,0,9,9,8,2,5}
{10000,10000000,100000000,100,10,1,1000,100,10000,100,10000,1000,100,10,100,100000000,10}

Returns: 209370454



4)
45
{}
{}
{}

Returns: 0



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
		cout << "Testing CliqueCuts (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1463069327;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 500.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		CliqueCuts _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 2;
				int a[] = {0};
				int b[] = {1};
				int c[] = {100};
				_expected = 100;
				_received = _obj.sum(n, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(c, c+sizeof(c)/sizeof(int))); break;
			}
			case 1:
			{
				int n = 5;
				int a[] = {0,0,0,0,1,1,1,2,2,3};
				int b[] = {1,2,3,4,2,3,4,3,4,4};
				int c[] = {0,1,2,3,4,5,6,7,8,9};
				_expected = 45;
				_received = _obj.sum(n, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(c, c+sizeof(c)/sizeof(int))); break;
			}
			case 2:
			{
				int n = 5;
				int a[] = {0,1,2,3};
				int b[] = {1,2,3,4};
				int c[] = {9,2,4,3};
				_expected = 999999941;
				_received = _obj.sum(n, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(c, c+sizeof(c)/sizeof(int))); break;
			}
			case 3:
			{
				int n = 10;
				int a[] = {0,1,2,9,5,3,4,7,3,4,1,5,2,3,0,7,8};
				int b[] = {6,7,4,5,6,2,6,3,1,8,2,0,9,9,8,2,5};
				int c[] = {10000,10000000,100000000,100,10,1,1000,100,10000,100,10000,1000,100,10,100,100000000,10};
				_expected = 209370454;
				_received = _obj.sum(n, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(c, c+sizeof(c)/sizeof(int))); break;
			}
			case 4:
			{
				int n = 45;
				int a[] = {};
				int b[] = {};
				int c[] = {};
				_expected = 0;
				_received = _obj.sum(n, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(c, c+sizeof(c)/sizeof(int))); break;
			}
			/*case 5:
			{
				int n = ;
				int a[] = ;
				int b[] = ;
				int c[] = ;
				_expected = ;
				_received = _obj.sum(n, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(c, c+sizeof(c)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int n = ;
				int a[] = ;
				int b[] = ;
				int c[] = ;
				_expected = ;
				_received = _obj.sum(n, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(c, c+sizeof(c)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int n = ;
				int a[] = ;
				int b[] = ;
				int c[] = ;
				_expected = ;
				_received = _obj.sum(n, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(c, c+sizeof(c)/sizeof(int))); break;
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
