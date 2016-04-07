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
#define ALL(x) (x).begin(),(x).end()
#define REP(i,n) for(int i=0;i<(n);i++)

struct SixteenBricks {
  int maximumSurface(vector <int> height) {
  	sort(ALL(height));
  	int ans = 0;
  	REP(i, 16) ans += height[i];
  	ans = 4 * ans + 16 - 2*(4*(height[0] + height[1])
  		+ 3 * (height[2] + height[3] + height[4] + height[5])
  		+ 2 * (height[6] + height[7]));
  	return ans;
  }
};

// BEGIN CUT HERE
/*
PROBLEM STATEMENT
You have 16 bricks. Each brick has the shape of a 
rectangular box. You are given a vector <int> height. For 
each i, one of your bricks has dimensions 1 x 1 x height[i].

You also have an opaque table. You are going to place your 
16 bricks onto the table in a specific way. You are not 
allowed to rotate the bricks while placing them: the 
dimension given in height must always be vertical. On the 
table, there is a 4 x 4 grid of squares. You have to place 
exactly one of your bricks onto each of the squares.

After you place all the bricks, we will look at the solid 
formed by them. We are interested in the visible surface 
area of the solid. Note that the bottom sides of your 
bricks are not a part of the visible surface, as they 
stand on the table. Also, adjacent bricks always touch 
each other and the parts where they touch are not visible.

Different arrangements of bricks may lead to different 
visible surfaces. Return the largest possible visible 
surface area.


DEFINITION
Class:SixteenBricks
Method:maximumSurface
Parameters:vector <int>
Returns:int
Method signature:int maximumSurface(vector <int> height)


CONSTRAINTS
-height will contain exactly 16 elements.
-Each element of height will be between 1 and 100, 
inclusive.


EXAMPLES

0)
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}

Returns: 32

All your bricks look the same.
The only solid you can construct is a 1 x 4 x 4 box.
The bottom side of the box is not visible, the other five 
sides are.
The total visible surface area is 4*4 + 4*(1*4) = 32.

1)
{1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2}

Returns: 64

In order to maximize the visible surface area, you should 
produce a configuration in which no two bricks with height 
2 share a common face.

2)
{77, 78, 58, 34, 30, 20, 8, 71, 37, 74, 21, 45, 39, 16, 4, 
59}


Returns: 1798



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
		cout << "Testing SixteenBricks (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1400342409;
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
		SixteenBricks _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int height[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
				_expected = 32;
				_received = _obj.maximumSurface(vector <int>(height, height+sizeof(height)/sizeof(int))); break;
			}
			case 1:
			{
				int height[] = {1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2};
				_expected = 64;
				_received = _obj.maximumSurface(vector <int>(height, height+sizeof(height)/sizeof(int))); break;
			}
			case 2:
			{
				int height[] = {77, 78, 58, 34, 30, 20, 8, 71, 37, 74, 21, 45, 39, 16, 4, 59};
				_expected = 1798;
				_received = _obj.maximumSurface(vector <int>(height, height+sizeof(height)/sizeof(int))); break;
			}
			/*case 3:
			{
				int height[] = ;
				_expected = ;
				_received = _obj.maximumSurface(vector <int>(height, height+sizeof(height)/sizeof(int))); break;
			}*/
			/*case 4:
			{
				int height[] = ;
				_expected = ;
				_received = _obj.maximumSurface(vector <int>(height, height+sizeof(height)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int height[] = ;
				_expected = ;
				_received = _obj.maximumSurface(vector <int>(height, height+sizeof(height)/sizeof(int))); break;
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
