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
#line 39 "TreeAndPathLength3.cpp"
#include <string>
#include <vector>
class TreeAndPathLength3 {
	public:
	vector <int> construct(int s) {
		
	}
};
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// You are given an int s.
Your task is to construct an undirected tree such that:

The number of nodes is between 1 and 500, inclusive.
The number of simple paths of length 3 in the tree is exactly s.


Note that the direction of the simple path does not matter: A-B-C-D is the same simple path as D-C-B-A.

It is guaranteed that for the constraints used in this task a tree with the required properties always exists.
Find one such tree.

If your tree has n nodes, they must be labeled 0 through n-1.
Return a vector <int> with (n-1)*2 elements.
For each valid i, elements 2i and 2i+1 of the return value should be the endpoints of one of the edges in your tree.
If there are multiple correct solutions, you may return any of them.

DEFINITION
Class:TreeAndPathLength3
Method:construct
Parameters:int
Returns:vector <int>
Method signature:vector <int> construct(int s)


CONSTRAINTS
-s will be between 1 and 10,000, inclusive.


EXAMPLES

0)
1

Returns: {0, 1, 1, 2, 2, 3 }

The return value has 6 elements, so it has to describe a tree on 4 vertices.
This tree contains the edges 0-1, 1-2, and 2-3.
We can easily verify that this tree does indeed contain exactly one simple path of length 3: the path 0-1-2-3.

1)
2

Returns: {0, 1, 1, 2, 2, 3, 3, 4 }

The returned tree has 5 vertices.
The two simple paths of length 3 in this tree are the paths 0-1-2-3 and 1-2-3-4.

2)
6

Returns: {0, 1, 1, 2, 0, 3, 3, 4, 0, 5, 5, 6 }

The six simple paths of length 3 in this tree are the following paths:
2-1-0-3, 2-1-0-5, 4-3-0-1, 4-3-0-5, 6-5-0-1, and 6-5-0-3.

3)
8

Returns: {0, 1, 1, 2, 1, 3, 3, 4, 3, 5, 5, 6, 5, 7 }



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
		cout << "Testing TreeAndPathLength3 (300.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1450443336;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 300.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		TreeAndPathLength3 _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int s = 1;
				int __expected[] = {0, 1, 1, 2, 2, 3 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(s); break;
			}
			case 1:
			{
				int s = 2;
				int __expected[] = {0, 1, 1, 2, 2, 3, 3, 4 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(s); break;
			}
			case 2:
			{
				int s = 6;
				int __expected[] = {0, 1, 1, 2, 0, 3, 3, 4, 0, 5, 5, 6 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(s); break;
			}
			case 3:
			{
				int s = 8;
				int __expected[] = {0, 1, 1, 2, 1, 3, 3, 4, 3, 5, 5, 6, 5, 7 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(s); break;
			}
			/*case 4:
			{
				int s = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(s); break;
			}*/
			/*case 5:
			{
				int s = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(s); break;
			}*/
			/*case 6:
			{
				int s = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(s); break;
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
