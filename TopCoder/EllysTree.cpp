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
// #line 40 "EllysTree.cpp"
#include <string>
#include <vector>
class EllysTree {
public:
    vector <int> getMoves(vector <int> parent) {
        
    }
};
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Elly has a graph with N+1 vertices, conveniently numbered from 0 to N.
The graph is actually a rooted tree, with the root being the vertex with number zero.


Elly can move between the vertices of her tree by jumping from one vertex to another.
Not all jumps are allowed.
Elly may jump from vertex A to vertex B if and only if one of A and B is a (direct or indirect) descendant of the other.


Elly is currently standing in the root of the tree: vertex 0.
She would like to make a sequence of N jumps that visits each of the other N vertices exactly once.

Note that Elly is allowed to jump over previously visited vertices.
For example, if A is an ancestor of B and B is an ancestor of C, Elly can jump from A to C or from C to A even if B has been already visited.


You are given the description of the tree: a vector <int> parent with N elements.
For each i between 0 and N-1, inclusive, the vertex parent[i] is the parent of the vertex (i+1).

If it is possible for Elly to visit each of the vertices 1 through N exactly once, return a vector <int> with N elements: the numbers of the vertices in the order in which she should visit them.
If there is more than one possible answer, return the lexicographically smallest one.
If there is no way to achieve her goal, return an empty vector <int> instead.

DEFINITION
Class:EllysTree
Method:getMoves
Parameters:vector <int>
Returns:vector <int>
Method signature:vector <int> getMoves(vector <int> parent)


NOTES
-A tree is a connected graph with N+1 vertices and N edges. A rooted tree is a tree in which one vertex is labeled as the root.
-In a rooted tree, the parent of vertex X is the first vertex on the path from X to the root. The root has no parent.
-In a rooted tree, vertex X is a descendant of vertex Y if Y lies on the path from X to the root.
-Given two equally long but different sequences of integers A and B, A is said to be lexicographically smaller than B if A contains a smaller number on the first position where they differ.


CONSTRAINTS
-parent will contain between 1 and 100 elements, inclusive.
-Each element of parent will be between 0 and |parent|, inclusive, where "|parent|" denotes the number of elements in parent (i.e. N).
-It is guaranteed, that the given graph will be a valid rooted tree.


EXAMPLES

0)
{9, 13, 7, 9, 8, 14, 14, 0, 6, 9, 2, 2, 5, 5, 7}

Returns: {1, 5, 2, 11, 13, 12, 8, 3, 7, 15, 14, 4, 6, 9, 10 }

The nodes Elly can jump to from node 6 are: {0, 8, 5, 14, 9, 10, 1, 4}.


1)
{3, 4, 5, 0, 2}

Returns: {1, 2, 3, 4, 5 }

There are no branches in this tree, thus Elly can traverse it in any order.

2)
{0, 0}

Returns: { }

The root has two children. No matter which of them Elly chooses first, she will not be able to get to the other, since the girl has to go back to the root, which is already visited.

3)
{0, 6, 6, 2, 6, 1, 3, 5}

Returns: {2, 4, 1, 3, 7, 6, 5, 8 }



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
		cout << "Testing EllysTree (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1459008907;
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
		EllysTree _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int parent[] = {9, 13, 7, 9, 8, 14, 14, 0, 6, 9, 2, 2, 5, 5, 7};
				int __expected[] = {1, 5, 2, 11, 13, 12, 8, 3, 7, 15, 14, 4, 6, 9, 10 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getMoves(vector <int>(parent, parent+sizeof(parent)/sizeof(int))); break;
			}
			case 1:
			{
				int parent[] = {3, 4, 5, 0, 2};
				int __expected[] = {1, 2, 3, 4, 5 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getMoves(vector <int>(parent, parent+sizeof(parent)/sizeof(int))); break;
			}
			case 2:
			{
				int parent[] = {0, 0};
				int __expected[] = { };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getMoves(vector <int>(parent, parent+sizeof(parent)/sizeof(int))); break;
			}
			case 3:
			{
				int parent[] = {0, 6, 6, 2, 6, 1, 3, 5};
				int __expected[] = {2, 4, 1, 3, 7, 6, 5, 8 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getMoves(vector <int>(parent, parent+sizeof(parent)/sizeof(int))); break;
			}
			/*case 4:
			{
				int parent[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getMoves(vector <int>(parent, parent+sizeof(parent)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int parent[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getMoves(vector <int>(parent, parent+sizeof(parent)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int parent[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getMoves(vector <int>(parent, parent+sizeof(parent)/sizeof(int))); break;
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
