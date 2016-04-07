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

class ExactTree {
	public:
	int getTree(int n, int m, int r) {
		
	}
};
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// In this problem, if a tree has x nodes, the nodes are numbered 0 through x-1.
Given a tree T, the distance dist(i,j) between nodes i and j is the number of edges on the unique simple path that connects them.
The sum of all pairwise distances in T, denoted S(T), is the sum of dist(i,j) over all pairs i,j such that i<j.


You are given ints n, m, and r.
We are interested in trees with the following properties:

The tree T has exactly n nodes (labeled 0 through n-1).
S(T) modulo m equals r.


If there are such trees, return the smallest possible value S(T).
Otherwise, return -1.

DEFINITION
Class:ExactTree
Method:getTree
Parameters:int, int, int
Returns:int
Method signature:int getTree(int n, int m, int r)


CONSTRAINTS
-n will be between 2 and 50, inclusive.
-m will be between 2 and 100, inclusive.
-r will be between 0 and m-1, inclusive.


EXAMPLES

0)
4
100
9

Returns: 9

For a tree T on 4 vertices there are only two possible values of S(T): 9 and 10.
(One tree that has S(T)=9 is a tree with the edges 0-1, 0-2, and 0-3.
One tree that has S(T)=10 is a tree with the edges 0-1, 1-2, and 2-3.)

We are only interested in trees T such that S(T) modulo 100 = 9.
Given this constraint, the smallest actually possible value S(T) is 9.

1)
4
100
10

Returns: 10



2)
4
100
0

Returns: -1



3)
6
2
0

Returns: 28



4)
6
2
1

Returns: 25



5)
25
100
0

Returns: 700



6)
50
97
89

Returns: 2708



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
		cout << "Testing ExactTree (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1436491537;
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
		ExactTree _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 4;
				int m = 100;
				int r = 9;
				_expected = 9;
				_received = _obj.getTree(n, m, r); break;
			}
			case 1:
			{
				int n = 4;
				int m = 100;
				int r = 10;
				_expected = 10;
				_received = _obj.getTree(n, m, r); break;
			}
			case 2:
			{
				int n = 4;
				int m = 100;
				int r = 0;
				_expected = -1;
				_received = _obj.getTree(n, m, r); break;
			}
			case 3:
			{
				int n = 6;
				int m = 2;
				int r = 0;
				_expected = 28;
				_received = _obj.getTree(n, m, r); break;
			}
			case 4:
			{
				int n = 6;
				int m = 2;
				int r = 1;
				_expected = 25;
				_received = _obj.getTree(n, m, r); break;
			}
			case 5:
			{
				int n = 25;
				int m = 100;
				int r = 0;
				_expected = 700;
				_received = _obj.getTree(n, m, r); break;
			}
			case 6:
			{
				int n = 50;
				int m = 97;
				int r = 89;
				_expected = 2708;
				_received = _obj.getTree(n, m, r); break;
			}
			/*case 7:
			{
				int n = ;
				int m = ;
				int r = ;
				_expected = ;
				_received = _obj.getTree(n, m, r); break;
			}*/
			/*case 8:
			{
				int n = ;
				int m = ;
				int r = ;
				_expected = ;
				_received = _obj.getTree(n, m, r); break;
			}*/
			/*case 9:
			{
				int n = ;
				int m = ;
				int r = ;
				_expected = ;
				_received = _obj.getTree(n, m, r); break;
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
