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

struct DucksAlignment {
  int minimumTime(vector <string> grid) {

  }
};

// BEGIN CUT HERE
/*
PROBLEM STATEMENT
Mr. Dengklek has a rectangular farm conveniently divided 
into a grid of unit squares. At this moment, each unit 
square contains at most one duck. Moreover, each row and 
column of the farm also contains at most one duck. You are 
given a vector <string> grid. The j-th character of the i-
th element of grid will be 'o' if there is exactly one 
duck in square (i, j), i.e., row i column j, or '.' if 
there is no duck in that square. 

Today, Mr. Dengklek wants to align the ducks so that the 
ducks form a contiguous line. More precisely, assume that 
there are N ducks on the farm. After the alignment, the 
ducks must either occupy N contiguous squares in some row 
or N contiguous squares in some column. To accomplish 
that, he will move the ducks one at a time. To move a duck 
in square (a, b) to another empty square (c, d), he needs 
|a-c| + |b-d| seconds, where |x| denotes the absolute 
value of x. Mr. Dengklek can always move any duck to any 
empty square he desires - the other ducks are not obstacles.

Return the minimum time in seconds Mr. Dengklek needs to 
align the ducks. Note that restrictions imposed on the 
initial placement of ducks guarantee that a proper 
alignment is always possible.

DEFINITION
Class:DucksAlignment
Method:minimumTime
Parameters:vector <string>
Returns:int
Method signature:int minimumTime(vector <string> grid)


CONSTRAINTS
-grid will contain between 1 and 50 elements, inclusive.
-Each element of grid will contain between 1 and 50 
characters, inclusive.
-All elements of grid will contain the same number of 
characters.
-Each character of grid will be either 'o' or '.'.
-Each row in grid will contain at most one character 'o'.
-Each column in grid will contain at most one character 'o'.
-grid will contain at least one character 'o'.


EXAMPLES

0)
{".o",
 "o."}

Returns: 1

Move either duck to an adjacent empty square.

1)
{".o...",
 "..o..",
 "....o"}

Returns: 3

One of the solutions is: move the the duck in the first 
row one square to the right, and then move the duck in the 
last row two squares to the left.

2)
{"o..........",
 "..o........",
 ".......o...",
 "...........",
 "...........",
 "...........",
 "........o..",
 "..........."}

Returns: 16

Align all ducks in the second row.

3)
{".........",
 "....o....",
 "........."}

Returns: 0



4)
{"...o..........................",
 "............................o.",
 ".o............................",
 "............o.................",
 ".................o............",
 "......................o.......",
 "......o.......................",
 "....o.........................",
 "...............o..............",
 ".......................o......",
 "...........................o..",
 ".......o......................"}

Returns: 99



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
		cout << "Testing DucksAlignment (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1404998593;
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
		DucksAlignment _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string grid[] = {".o",
				                 "o."};
				_expected = 1;
				_received = _obj.minimumTime(vector <string>(grid, grid+sizeof(grid)/sizeof(string))); break;
			}
			case 1:
			{
				string grid[] = {".o...",
				                 "..o..",
				                 "....o"};
				_expected = 3;
				_received = _obj.minimumTime(vector <string>(grid, grid+sizeof(grid)/sizeof(string))); break;
			}
			case 2:
			{
				string grid[] = {"o..........",
				                 "..o........",
				                 ".......o...",
				                 "...........",
				                 "...........",
				                 "...........",
				                 "........o..",
				                 "..........."};
				_expected = 16;
				_received = _obj.minimumTime(vector <string>(grid, grid+sizeof(grid)/sizeof(string))); break;
			}
			case 3:
			{
				string grid[] = {".........",
				                 "....o....",
				                 "........."};
				_expected = 0;
				_received = _obj.minimumTime(vector <string>(grid, grid+sizeof(grid)/sizeof(string))); break;
			}
			case 4:
			{
				string grid[] = {"...o..........................",
				                 "............................o.",
				                 ".o............................",
				                 "............o.................",
				                 ".................o............",
				                 "......................o.......",
				                 "......o.......................",
				                 "....o.........................",
				                 "...............o..............",
				                 ".......................o......",
				                 "...........................o..",
				                 ".......o......................"};
				_expected = 99;
				_received = _obj.minimumTime(vector <string>(grid, grid+sizeof(grid)/sizeof(string))); break;
			}
			/*case 5:
			{
				string grid[] = ;
				_expected = ;
				_received = _obj.minimumTime(vector <string>(grid, grid+sizeof(grid)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string grid[] = ;
				_expected = ;
				_received = _obj.minimumTime(vector <string>(grid, grid+sizeof(grid)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string grid[] = ;
				_expected = ;
				_received = _obj.minimumTime(vector <string>(grid, grid+sizeof(grid)/sizeof(string))); break;
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
