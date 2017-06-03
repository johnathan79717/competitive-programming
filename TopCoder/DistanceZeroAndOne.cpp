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

#line 40 "DistanceZeroAndOne.cpp"
#include <string>
#include <vector>
class DistanceZeroAndOne {
public:
  vector <string> construct(vector <int> dist0, vector <int> dist1) {

  }
};

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Fox Ciel used to have a graph G but she lost it somewhere.
She now wants to reconstruct it and she needs your help to do so.


Here is what she remembers about the graph:

G was a simple undirected graph on n nodes, numbered 0 through n-1.
G was connected.
All edges had unit lengths. (Thus, the distance between two nodes is simply the smallest number of edges one needs to traverse to get from one to the other.)
For each node i, the distance between nodes 0 and i was dist0[i].
For each node i, the distance between nodes 1 and i was dist1[i].


You are given the vector <int>s dist0 and dist1, each containing n elements.
If there is at least one graph G that corresponds to these distances (and all the other constraints given above), return any such graph.
More precisely, return a vector <string> R containing the adjacency matrix of the chosen graph G.
For each i and j, R[i][j] should be 'Y' if nodes i and j are connected by an edge, or 'N' if they are not.


If there is no solution, return an empty vector <string> instead.

DEFINITION
Class:DistanceZeroAndOne
Method:construct
Parameters:vector <int>, vector <int>
Returns:vector <string>
Method signature:vector <string> construct(vector <int> dist0, vector <int> dist1)


CONSTRAINTS
-n will be between 2 and 50, inclusive.
-dist0 will contain exactly n elemnets.
-dist1 will contain exactly n elemnets.
-Each element in dist0 will be between 0 and n-1, inclusive.
-Each element in dist1 will be between 0 and n-1, inclusive.


EXAMPLES

0)
{0,2,1}
{2,0,1}

Returns: {"NNY", "NNY", "YYN" }

We have a graph with three nodes.
From the given distances we see that dist(0,1) = 2 and that dist(0,2) = dist(1,2) = 1.
Thus, the graph G must look like this: 0 - 2 - 1.

1)
{0,2,1}
{1,0,2}

Returns: { }

The value dist0[1] claims that the distance between nodes 0 and 1 is 2.
On the other hand, the value dist1[0] claims that this distance is 1.
As the graph is undirected, this is impossible.

2)
{3,1,1,1}
{1,0,1,1}

Returns: { }

The value dist0[0] cannot be 3.

3)
{0,1,1,1}
{1,0,1,1}

Returns: {"NYYY", "YNYY", "YYNN", "YYNN" }



4)
{0,3,1,2,2,3,4,4}
{3,0,2,1,2,3,4,4}

Returns: {"NNYNNNNN", "NNNYNNNN", "YNNYYNNN", "NYYNYNNN", "NNYYNYNN", "NNNNYNYY", "NNNNNYNN", "NNNNNYNN" }



5)
{0,1}
{1,0}

Returns: {"NY", "YN" }



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
		cout << "Testing DistanceZeroAndOne (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1495297073;
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
		DistanceZeroAndOne _obj;
		vector <string> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int dist0[] = {0,2,1};
				int dist1[] = {2,0,1};
				string __expected[] = {"NNY", "NNY", "YYN" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.construct(vector <int>(dist0, dist0+sizeof(dist0)/sizeof(int)), vector <int>(dist1, dist1+sizeof(dist1)/sizeof(int))); break;
			}
			case 1:
			{
				int dist0[] = {0,2,1};
				int dist1[] = {1,0,2};
				string __expected[] = { };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.construct(vector <int>(dist0, dist0+sizeof(dist0)/sizeof(int)), vector <int>(dist1, dist1+sizeof(dist1)/sizeof(int))); break;
			}
			case 2:
			{
				int dist0[] = {3,1,1,1};
				int dist1[] = {1,0,1,1};
				string __expected[] = { };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.construct(vector <int>(dist0, dist0+sizeof(dist0)/sizeof(int)), vector <int>(dist1, dist1+sizeof(dist1)/sizeof(int))); break;
			}
			case 3:
			{
				int dist0[] = {0,1,1,1};
				int dist1[] = {1,0,1,1};
				string __expected[] = {"NYYY", "YNYY", "YYNN", "YYNN" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.construct(vector <int>(dist0, dist0+sizeof(dist0)/sizeof(int)), vector <int>(dist1, dist1+sizeof(dist1)/sizeof(int))); break;
			}
			case 4:
			{
				int dist0[] = {0,3,1,2,2,3,4,4};
				int dist1[] = {3,0,2,1,2,3,4,4};
				string __expected[] = {"NNYNNNNN", "NNNYNNNN", "YNNYYNNN", "NYYNYNNN", "NNYYNYNN", "NNNNYNYY", "NNNNNYNN", "NNNNNYNN" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.construct(vector <int>(dist0, dist0+sizeof(dist0)/sizeof(int)), vector <int>(dist1, dist1+sizeof(dist1)/sizeof(int))); break;
			}
			case 5:
			{
				int dist0[] = {0,1};
				int dist1[] = {1,0};
				string __expected[] = {"NY", "YN" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.construct(vector <int>(dist0, dist0+sizeof(dist0)/sizeof(int)), vector <int>(dist1, dist1+sizeof(dist1)/sizeof(int))); break;
			}
			/*case 6:
			{
				int dist0[] = ;
				int dist1[] = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.construct(vector <int>(dist0, dist0+sizeof(dist0)/sizeof(int)), vector <int>(dist1, dist1+sizeof(dist1)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int dist0[] = ;
				int dist1[] = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.construct(vector <int>(dist0, dist0+sizeof(dist0)/sizeof(int)), vector <int>(dist1, dist1+sizeof(dist1)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int dist0[] = ;
				int dist1[] = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.construct(vector <int>(dist0, dist0+sizeof(dist0)/sizeof(int)), vector <int>(dist1, dist1+sizeof(dist1)/sizeof(int))); break;
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
				cout << " \"" << _expected[i] << "\"";
			}
			cout << " }" << endl;
			cout << "           Received: {";
			for (unsigned i = 0; i < _received.size(); i++)
			{
				if (i) cout << ",";
				cout << " \"" << _received[i] << "\"";
			}
			cout << " }" << endl;
		}
	}
}

// END CUT HERE
