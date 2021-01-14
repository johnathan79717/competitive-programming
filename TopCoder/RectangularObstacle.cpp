#line 2 "RectangularObstacle.cpp"
#include <string>
#include <vector>
#include <climits>
#include <cstring>
#include <map>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <cassert>
#include <deque>
#include <stack>
#include <functional>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII> VPII;
typedef pair<LL,LL> PLL;
typedef vector<PLL> VPLL;
int MOD = 1e9+7;
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}

class RectangularObstacle {
public:
    long long countReachable(int x1, int x2, int y1, int y2, int s) {
	LL ans = 0;
	ans += (1ll + s) * (1ll + s);

	LL n = min(y1 - 1, s);
	ans += n * (2 * (2 * s - 1) + (n-1) * (-2)) / 2;

	if (1 - x1 + y1 <= s) {
	    LL s1 = s - (y1 + 1 - x1);
	    
	    LL n = min(y2 - y1 + 1ll, s1 + 1);
	    ans += n * (2 * (s1 + 1) + (n-1) * (-1)) / 2;
	}
	if (1 + x2 + y1 <= s) {
	    LL s2 = s - (y1 + 1 + x2);
	    LL n = min(y2 - y1 + 1ll, s2 + 1);
	    ans += n * (2 * (s2 + 1) + (n-1) * (-1)) / 2;
	}
	LL s1 = s - (1 - x1 + y2 + 1);
	LL s2 = s - (1 + x2 + y2 + 1);
	if (s1 >= 0) {
	    ans += (s1 + 1) * (s1 + 1);
	}
	if (s2 >= 0) {
	    ans += (s2 + 1) * (s2 + 1);
	}
	if (s1 >= 0 && s2 >= 0) {
	    LL l = max(x2 + 1 - s2, x1 - 1 - s1);
	    LL r = min(x2 + 1 + s2, x1 - 1 + s1);
	    if (r >= l) {
		LL t = r - l + 1;
		LL n = (t + 1) / 2;
		ans -= n * (2 * t + (n-1) * (-2)) / 2;
	    }
	}

	return ans;
    }
};

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
You are standing on the cell (0, 0) of an infinite square grid.


Elsewhere in the grid is a rectangular obstacle.
The obstacle covers all cells (x, y) such that x1 <= x <= x2 and y1 <= y <= y2.


The value y1 is positive, the value x1 is non-positive, and the value x2 is non-negative.
This means that if you went in the positive y direction, you would eventually hit the obstacle.


From your starting cell (0, 0) you are allowed to take between 0 and s steps, inclusive.
In each step you can move between two cells that share a side.
Obviously, you cannot enter cells covered by the obstacle.
Return the number of cells you can reach.


DEFINITION
Class:RectangularObstacle
Method:countReachable
Parameters:int, int, int, int, int
Returns:long long
Method signature:long long countReachable(int x1, int x2, int y1, int y2, int s)


CONSTRAINTS
-The x-coordinates will satisfy -10^6 <= x1 <= 0 <= x2 <= 10^6.
-The y-coordinates will satisfy 1 <= y1 <= y2 <= 10^6.
-s will be between 0 and 10^9, inclusive.


EXAMPLES

0)
-5
5
3
3
2

Returns: 13


The situation is shown below: X denotes the obstacle, S your starting position, * other cells you can visit, and . cells you cannot visit because they are too far.


XXXXXXXXXXX
.....*.....
....***....
...**S**...
....***....
.....*.....
...........


1)
-5
5
3
3
3

Returns: 24


The same situation as in Example 0 but we can do one more step. Note that walking into the obstacle is forbidden.


XXXXXXXXXXX
....***....
...*****...
..***S***..
...*****...
....***....
.....*.....
...........


2)
-4
1
1
2
6

Returns: 61


........*.....
.......***....
..XXXXXX***...
.*XXXXXX****..
******S******.
.***********..
..*********...
...*******....
....*****.....
.....***......
......*.......
..............

A fairly general case in which we can go partially around the obstacle.


3)
0
0
1
1
4

Returns: 38


...........
....*.*....
...*****...
..***X***..
.****S****.
..*******..
...*****...
....***....
.....*.....
...........

A nice, vaguely heart-shaped area.


4)
-100
100
42
47
0

Returns: 1

If you cannot move, the only cell you can visit is the starting cell.

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
		cout << "Testing RectangularObstacle (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1596297903;
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
		RectangularObstacle _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int x1 = -5;
				int x2 = 5;
				int y1 = 3;
				int y2 = 3;
				int s = 2;
				_expected = 13LL;
				_received = _obj.countReachable(x1, x2, y1, y2, s); break;
			}
			case 1:
			{
				int x1 = -5;
				int x2 = 5;
				int y1 = 3;
				int y2 = 3;
				int s = 3;
				_expected = 24LL;
				_received = _obj.countReachable(x1, x2, y1, y2, s); break;
			}
			case 2:
			{
				int x1 = -4;
				int x2 = 1;
				int y1 = 1;
				int y2 = 2;
				int s = 6;
				_expected = 61LL;
				_received = _obj.countReachable(x1, x2, y1, y2, s); break;
			}
			case 3:
			{
				int x1 = 0;
				int x2 = 0;
				int y1 = 1;
				int y2 = 1;
				int s = 4;
				_expected = 38LL;
				_received = _obj.countReachable(x1, x2, y1, y2, s); break;
			}
			case 4:
			{
				int x1 = -100;
				int x2 = 100;
				int y1 = 42;
				int y2 = 47;
				int s = 0;
				_expected = 1LL;
				_received = _obj.countReachable(x1, x2, y1, y2, s); break;
			}
			case 5:
			{
				int x1 = -1;
				int x2 = 10;
				int y1 = 3;
				int y2 = 3;
				int s = 20;
				_expected = 785LL;
				_received = _obj.countReachable(x1, x2, y1, y2, s); break;
			}
			/*case 6:
			{
				int x1 = ;
				int x2 = ;
				int y1 = ;
				int y2 = ;
				int s = ;
				_expected = LL;
				_received = _obj.countReachable(x1, x2, y1, y2, s); break;
			}*/
			/*case 7:
			{
				int x1 = ;
				int x2 = ;
				int y1 = ;
				int y2 = ;
				int s = ;
				_expected = LL;
				_received = _obj.countReachable(x1, x2, y1, y2, s); break;
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
