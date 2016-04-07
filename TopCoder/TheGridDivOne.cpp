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
 
typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;

class TheGridDivOne {
	public:
	int find(vector <int> x, vector <int> y, int k) {
		
	}
};
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// John is standing at the origin of an infinite two-dimensional grid.
He is going to move along this grid.
During each second he can either stay where he is or he can move by one unit in one of the four cardinal directions (north, south, east, or west).
Some of the grid points are blocked.
John is not allowed to move to a blocked grid point.


You are given the coordinates of the blocked grid points as vector <int>s x and y.
For each valid i, the grid point that is x[i] units east and y[i] units north of the origin is blocked.
You are also given an int k.
Compute and return the maximal possible x-coordinate of a point John can reach in k seconds.


DEFINITION
Class:TheGridDivOne
Method:find
Parameters:vector <int>, vector <int>, int
Returns:int
Method signature:int find(vector <int> x, vector <int> y, int k)


CONSTRAINTS
-x will contain between 0 and 47 elements, inclusive.
-x and y will contain the same number of elements.
-Each element of x will be between -1,000,000,000 and 1,000,000,000, inclusive.
-Each element of y will be between -1,000,000,000 and 1,000,000,000, inclusive.
-All pairs (x[i], y[i]) will be distinct.
-Each pair (x[i], y[i]) will be different from (0, 0).
-k will be between 1 and 1,000,000,000, inclusive.


EXAMPLES

0)
{1,1,1,1}
{-2,-1,0,1}
4

Returns: 2

The optimal strategy is to move two times north to (0, 2) and then two times east to (2,2).

1)
{-1, 0, 0, 1}
{0, -1, 1, 0}
9

Returns: 0

John can not make any moves.

2)
{}
{}
1000

Returns: 1000



3)
{1,0,0,-1,-1,-2,-2,-3,-3,-4,-4}
{0,-1,1,-2,2,-3,3,-4,4,-5,5}
47

Returns: 31



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
		cout << "Testing TheGridDivOne (600.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1421375253;
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
		TheGridDivOne _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int x[] = {1,1,1,1};
				int y[] = {-2,-1,0,1};
				int k = 4;
				_expected = 2;
				_received = _obj.find(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), k); break;
			}
			case 1:
			{
				int x[] = {-1, 0, 0, 1};
				int y[] = {0, -1, 1, 0};
				int k = 9;
				_expected = 0;
				_received = _obj.find(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), k); break;
			}
			case 2:
			{
				int x[] = {};
				int y[] = {};
				int k = 1000;
				_expected = 1000;
				_received = _obj.find(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), k); break;
			}
			case 3:
			{
				int x[] = {1,0,0,-1,-1,-2,-2,-3,-3,-4,-4};
				int y[] = {0,-1,1,-2,2,-3,3,-4,4,-5,5};
				int k = 47;
				_expected = 31;
				_received = _obj.find(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), k); break;
			}
			/*case 4:
			{
				int x[] = ;
				int y[] = ;
				int k = ;
				_expected = ;
				_received = _obj.find(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), k); break;
			}*/
			/*case 5:
			{
				int x[] = ;
				int y[] = ;
				int k = ;
				_expected = ;
				_received = _obj.find(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), k); break;
			}*/
			/*case 6:
			{
				int x[] = ;
				int y[] = ;
				int k = ;
				_expected = ;
				_received = _obj.find(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), k); break;
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
