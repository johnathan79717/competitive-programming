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
// #line 40 "BipartiteConstruction.cpp"
#include <string>
#include <vector>
class BipartiteConstruction {
public:
    vector <int> construct(int K) {
        
    }
};
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// You are given a single int K.
Your task is to construct any bipartite graph with the following properties:

The graph must contain n white and n black vertices, where n is between 1 and 20, inclusive. The white vertices must be numbered 0 through n-1, and the black vertices must also be numbered 0 through n-1.
The graph must contain between 0 and 120 edges, inclusive.
Each edge of the graph must connect a white and a black vertex.
The number of different perfect matchings in the graph must be exactly K. Note that a perfect matching in a graph is a set of edges of the graph that contains each vertex exactly once.


Note that each pair of differently-colored vertices may be connected by arbitrarily many edges.
These edges are all considered distinct.

Return a vector <int> with the description of the graph you constructed.
This vector <int> should have m+1 elements, where m is the number of edges in your graph.
Element 0 of the return value should be n.
Each of the other elements should encode one edge of your graph.
An edge that connects the i-th white vertex and the j-th black vertex is encoded as the integer (i*n + j).

It is guaranteed that for the given constraints a solution always exists.
If there are multiple solutions, you may return any of them.

DEFINITION
Class:BipartiteConstruction
Method:construct
Parameters:int
Returns:vector <int>
Method signature:vector <int> construct(int K)


NOTES
-A perfect matching in a graph is a set of edges of the graph that contains each vertex exactly once.


CONSTRAINTS
-K will be between 0 and 1,000,000,000, inclusive.


EXAMPLES

0)
2

Returns: {3, 8, 1, 7, 4, 3, 0 }

The edges are (2,2), (0,1), (2,1), (1,1), (1,0), (0,0). It has two different perfect matchings: {(2,2), (0,1), (1,0)} and {(2,2), (1,1), (0,0)}.


1)
5

Returns: {1, 0, 0, 0, 0, 0 }

This return value describes a graph with a single white vertex and a single black vertex.
These vertices are connected by five distinct edges.
Each of these edges forms a perfect matching in our graph.


2)
0

Returns: {2, 1, 0 }



3)
2333333

Returns: {20, 93, 195, 195, 211, 87, 114, 369, 390, 216, 195, 305, 17, 370, 356, 308, 150, 263, 20, 153, 331, 79, 344, 108, 114, 257, 245, 289, 211, 388, 388, 359, 293, 263, 219, 131, 201, 293, 279, 204, 97, 367, 90, 279, 308, 324, 323, 359, 338, 63, 26, 318, 218, 226, 164, 361, 276, 388, 343, 149, 17, 336, 88, 161, 76, 237, 136, 278, 302, 107, 271, 15, 382, 45, 338, 264, 78, 150, 220, 341, 180, 20, 252, 94, 114, 161 }



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
		cout << "Testing BipartiteConstruction (600.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1466871786;
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
		BipartiteConstruction _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int K = 2;
				int __expected[] = {3, 8, 1, 7, 4, 3, 0 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(K); break;
			}
			case 1:
			{
				int K = 5;
				int __expected[] = {1, 0, 0, 0, 0, 0 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(K); break;
			}
			case 2:
			{
				int K = 0;
				int __expected[] = {2, 1, 0 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(K); break;
			}
			case 3:
			{
				int K = 2333333;
				int __expected[] = {20, 93, 195, 195, 211, 87, 114, 369, 390, 216, 195, 305, 17, 370, 356, 308, 150, 263, 20, 153, 331, 79, 344, 108, 114, 257, 245, 289, 211, 388, 388, 359, 293, 263, 219, 131, 201, 293, 279, 204, 97, 367, 90, 279, 308, 324, 323, 359, 338, 63, 26, 318, 218, 226, 164, 361, 276, 388, 343, 149, 17, 336, 88, 161, 76, 237, 136, 278, 302, 107, 271, 15, 382, 45, 338, 264, 78, 150, 220, 341, 180, 20, 252, 94, 114, 161 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(K); break;
			}
			/*case 4:
			{
				int K = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(K); break;
			}*/
			/*case 5:
			{
				int K = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(K); break;
			}*/
			/*case 6:
			{
				int K = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(K); break;
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
