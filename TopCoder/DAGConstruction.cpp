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

// BEGIN CUT HERE
// PROBLEM STATEMENT
// You are given a vector <int> x with n elements.
Your task is to construct a directed acyclic graph that satisfies all the conditions listed below, or to determine that such a graph does not exist.
The graph must look as follows:



There are n vertices, numbered 0 through n-1.
There are no self-loops, and each pair of vertices is connected by at most one edge.
For each i, the number of vertices reachable from vertex i must be exactly x[i]. Note that each node is reachable from itself.


If there is no such graph exists, return {-1}. (That is, a vector <int> that contains a single element with the value -1.)

If there are multiple such graphs, you may choose any of them.
Suppose that the graph you chose contains the edges a[0] -> b[0], a[1] -> b[1], and so on.
Return the following vector <int>: {a[0], b[0], a[1], b[1], a[2], b[2], ...}.

DEFINITION
Class:DAGConstruction
Method:construct
Parameters:vector <int>
Returns:vector <int>
Method signature:vector <int> construct(vector <int> x)


NOTES
-Given a directed graph, vertex y is reachable from vertex x if it is possible to travel from x to y by following a sequence of zero or more directed edges.


CONSTRAINTS
-x will contain between 1 and 50 elements, inclusive.
-Each element in x will be between 1 and |x|, inclusive.


EXAMPLES

0)
{2, 1}

Returns: {0, 1 }

We are looking for a graph with two vertices.
Additionally, we should be able to reach both vertices from vertex 0 and just a single vertex from vertex 1.
The graph that contains the edge 0 -> 1 has this property.

1)
{1, 1}

Returns: { }

This time the graph should be 2 isolated vertices.

2)
{1, 3, 1}

Returns: {1, 0, 1, 2 }

Note that the directions of edges are unrelated to the vertex numbers.
In this example, the correct answer is the directed acyclic graph that contains the edges 1 -> 0 and 1 -> 2.

3)
{5,5,5,5,5}

Returns: {-1 }

This time we are supposed to return a graph with 5 vertices in which each vertex is reachable from each vertex.
This is only possible if the entire graph is strongly connected.
An acyclic graph on 5 vertices cannot possibly be strongly connected, so we should return {-1}.

4)
{4,2,2,1}

Returns: {0, 1, 0, 2, 1, 3, 2, 3 }



// END CUT HERE
#line 119 "DAGConstruction.cpp"
#include <string>
#include <vector>
class DAGConstruction {
	public:
	vector <int> construct(vector <int> x) {
		
	}
};

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
		cout << "Testing DAGConstruction (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1483012946;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 250.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		DAGConstruction _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int x[] = {2, 1};
				int __expected[] = {0, 1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}
			case 1:
			{
				int x[] = {1, 1};
				int __expected[] = { };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}
			case 2:
			{
				int x[] = {1, 3, 1};
				int __expected[] = {1, 0, 1, 2 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}
			case 3:
			{
				int x[] = {5,5,5,5,5};
				int __expected[] = {-1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}
			case 4:
			{
				int x[] = {4,2,2,1};
				int __expected[] = {0, 1, 0, 2, 1, 3, 2, 3 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}
			/*case 5:
			{
				int x[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int x[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int x[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
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
