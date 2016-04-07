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
#define FOR(i, c) for(auto &i: c)
#define ALL(x) (x).begin(),(x).end()
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define PER(i,n) for(int i=(n)-1;i>=0;i--)
#define PER1(i,a,b) for(int i=(a);i>=(b);i--)
#define MP make_pair
#define PB push_back
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,-1,sizeof(x))
#define V(T) vector<T >
#define EB emplace_back
 
typedef long long LL;

struct TreePuzzle {
  vector <int> reachable(vector <int> parent, vector <int> token) {

  }
};

// BEGIN CUT HERE
/*
PROBLEM STATEMENT
Cat Snuke has a tree with N nodes.
The nodes are numbered 0 through N-1.
You are given a vector <int> parent that represents the 
structure of the tree.
The value parent[0] should be ignored.
For each i > 0, there is an edge that connects the nodes i 
and parent[i].


Initially, Snuke placed a red token onto node 0, and black 
tokens onto some of the other nodes (possibly none or all 
of them).
You are given this information as a vector <int> token 
with N elements.
For each i, token[i] will be either 0 or 1.
Here, 0 means that node i is empty, and 1 means that it 
contains a token.
It is guaranteed that token[0]=1.


Snuke now plays a game with the tokens.
Whenever there is a node with a token adjacent to an empty 
node, Snuke may slide the token along the edge from its 
current node to the adjacent empty one.
The goal of the game is to move the red token into a 
specific node.


Return a vector <int> with N elements.
For each i, element i of the return value should be 1 if 
it is possible to reach node i with the red token, and 0 
otherwise.

DEFINITION
Class:TreePuzzle
Method:reachable
Parameters:vector <int>, vector <int>
Returns:vector <int>
Method signature:vector <int> reachable(vector <int> 
parent, vector <int> token)


CONSTRAINTS
-N will be between 2 and 300, inclusive.
-parent will contain exactly N elements.
-parent[0] will be -1.
-For each i > 0, parent[i] will be between 0 and i-1, 
inclusive.
-token will contain exactly N elements.
-token[0] will be 1.
-For each i > 0, token[i] will be either 0 or 1.


EXAMPLES

0)
{-1, 0, 0, 0, 1}
{1, 1, 0, 0, 1}

Returns: {1, 1, 1, 1, 0 }

In the figure below, each row shows a sequence of moves 
that starts from the initial configuration and ends with 
the red token reaching one of the nodes 0, 1, 2, and 3. 
There is no valid sequence of moves such that the red 
token reaches the node 4.





1)
{-1, 0, 1, 0, 3, 2, 5, 6, 7, 8}
{1, 1, 1, 1, 1, 1, 0, 0, 1, 0}

Returns: {1, 1, 1, 0, 0, 1, 0, 0, 0, 0 }



2)
{-1, 0, 0, 2, 1, 1, 5, 0, 0, 2}
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}

Returns: {1, 0, 0, 0, 0, 0, 0, 0, 0, 0 }



3)
{-1, 0, 1, 2, 3, 4, 5, 0, 7, 6, 8, 9, 11, 0, 11, 2, 15, 
13, 15, 10}
{1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1}

Returns: {1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 
0, 1, 0, 0 }



4)
{-1, 0, 1, 2, 3, 4, 0, 5, 7, 8, 6, 10, 11, 9, 13, 14, 12, 
16, 16, 18,
15, 10, 17, 2, 23, 22, 21, 20, 27, 24, 19, 30, 28, 29, 17, 
21, 34, 35, 31, 30,
36, 32, 31, 39, 26, 40, 3, 38, 45, 25, 49, 46, 41, 44, 51, 
47, 18, 54, 48, 36,
43, 57, 52, 56, 60, 59, 53, 61, 64, 68, 37, 55, 71, 32, 
26, 73, 28, 50, 75, 72,
70, 67, 74, 66, 79, 76, 78, 63, 69, 41, 83, 86, 80, 18, 
82, 87, 58, 62, 42, 20}
{1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1,
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1,
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1}

Returns: {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 
1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 
1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 
1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
0, 1, 0, 0, 1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 0, 
1, 1, 1, 1, 1, 0, 1, 0 }



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
		cout << "Testing TreePuzzle (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1400344872;
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
		TreePuzzle _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int parent[] = {-1, 0, 0, 0, 1};
				int token[] = {1, 1, 0, 0, 1};
				int __expected[] = {1, 1, 1, 1, 0 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.reachable(vector <int>(parent, parent+sizeof(parent)/sizeof(int)), vector <int>(token, token+sizeof(token)/sizeof(int))); break;
			}
			case 1:
			{
				int parent[] = {-1, 0, 1, 0, 3, 2, 5, 6, 7, 8};
				int token[] = {1, 1, 1, 1, 1, 1, 0, 0, 1, 0};
				int __expected[] = {1, 1, 1, 0, 0, 1, 0, 0, 0, 0 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.reachable(vector <int>(parent, parent+sizeof(parent)/sizeof(int)), vector <int>(token, token+sizeof(token)/sizeof(int))); break;
			}
			case 2:
			{
				int parent[] = {-1, 0, 0, 2, 1, 1, 5, 0, 0, 2};
				int token[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
				int __expected[] = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.reachable(vector <int>(parent, parent+sizeof(parent)/sizeof(int)), vector <int>(token, token+sizeof(token)/sizeof(int))); break;
			}
			case 3:
			{
				int parent[] = {-1, 0, 1, 2, 3, 4, 5, 0, 7, 6, 8, 9, 11, 0, 11, 2, 15, 13, 15, 10};
				int token[] = {1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1};
				int __expected[] = {1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.reachable(vector <int>(parent, parent+sizeof(parent)/sizeof(int)), vector <int>(token, token+sizeof(token)/sizeof(int))); break;
			}
			case 4:
			{
				int parent[] = {-1, 0, 1, 2, 3, 4, 0, 5, 7, 8, 6, 10, 11, 9, 13, 14, 12, 16, 16, 18,
				               15, 10, 17, 2, 23, 22, 21, 20, 27, 24, 19, 30, 28, 29, 17, 21, 34, 35, 31, 30,
				               36, 32, 31, 39, 26, 40, 3, 38, 45, 25, 49, 46, 41, 44, 51, 47, 18, 54, 48, 36,
				               43, 57, 52, 56, 60, 59, 53, 61, 64, 68, 37, 55, 71, 32, 26, 73, 28, 50, 75, 72,
				               70, 67, 74, 66, 79, 76, 78, 63, 69, 41, 83, 86, 80, 18, 82, 87, 58, 62, 42, 20};
				int token[] = {1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1,
				              1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
				              0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1,
				              1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
				              1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1};
				int __expected[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.reachable(vector <int>(parent, parent+sizeof(parent)/sizeof(int)), vector <int>(token, token+sizeof(token)/sizeof(int))); break;
			}
			/*case 5:
			{
				int parent[] = ;
				int token[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.reachable(vector <int>(parent, parent+sizeof(parent)/sizeof(int)), vector <int>(token, token+sizeof(token)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int parent[] = ;
				int token[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.reachable(vector <int>(parent, parent+sizeof(parent)/sizeof(int)), vector <int>(token, token+sizeof(token)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int parent[] = ;
				int token[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.reachable(vector <int>(parent, parent+sizeof(parent)/sizeof(int)), vector <int>(token, token+sizeof(token)/sizeof(int))); break;
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
