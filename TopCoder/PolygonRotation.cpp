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

#line 40 "PolygonRotation.cpp"
#include <string>
#include <vector>
class PolygonRotation {
public:
  double f(int x1, int y1, int x2, int y2) {
    if (x1 <= 0 && x2 <= 0) {
      swap(x1, x2);
      swap(y1, y2);
    }
    if (x1 == x2) {
      return M_PI * x1 * x1 * (y1 - y2);
    }
    if (x1 > x2) {
      swap(x1, x2);
    }
    double y = y1 - y2;
    double h = x1 * y * 1.0 / (x2 - x1);
    return M_PI * (x2 * x2 * (h + y) - x1 * x1 * h) / 3;
  }
  double getVolume(vector <int> x, vector <int> y) {
    int N = x.size();
    double ans = f(x[N-1], y[N-1], x[0], y[0]);
    REP(i, N-1) {
      ans += f(x[i], y[i], x[i+1], y[i+1]);
    }
    return fabs(ans);
  }
};

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// We have a convex polygon in the XY plane.
The vertices of the polygon are the points (x[0], y[0]), (x[1], y[1]), ... in clockwise order.
You are given the vector <int>s x and y.

In order to make the implementation simpler the polygon and its representation satisfy some additional constraints.
Please read the Constraints section carefully.

A three-dimensional solid is obtained by rotating this polygon around the Y axis.
Compute and return the volume of the resulting solid.


DEFINITION
Class:PolygonRotation
Method:getVolume
Parameters:vector <int>, vector <int>
Returns:double
Method signature:double getVolume(vector <int> x, vector <int> y)


NOTES
-The returned value must have an absolute or relative error less than 1e-9.


CONSTRAINTS
-x will contain between 3 and 50 elements, inclusive.
-y will contain the same number of elements as x.
-Each element of x and y will be between -100 and 100, inclusive.
-The polygon will be convex.
-All vertices of the polygon will be distinct.
-The polygon will have exactly two vertices on the Y axis. Let's denote them (0, Ymin) and (0, Ymax) with Ymin < Ymax.
-The vertices will be listed in clockwise order, starting with (0, Ymax).
-The y-coordinates of all vertices will be between Ymin and Ymax, inclusive.
-No three points will lie on the same line.


EXAMPLES

0)
{0, 1, 1, 0}
{1, 1, 0, 0}

Returns: 3.141592653589793

The polygon is a square with sides parallel to the coordinate axes.
One of the sides of the square belongs to the Y axis.
The resulting solid of revolution is a right cylinder of height 1 and radius 1.

1)
{0, 1, 0, -1}
{2, 1, 0, 1}

Returns: 2.0943951023931953

This polygon is also a square.
Each of its sides is angled at 45 degrees to the coordinate axes.
The resulting solid of revolution is the union of two cones, each with base radius 1 and height 1.

2)
{0, 3, 0, -2, -2}
{2, 0, -3, -1, 1}

Returns: 49.91641660703782



3)
{0, 3, 3, 0, -1, -1}
{2, 2, -2, -2, -1, 1}

Returns: 113.09733552923255



*/
// END CUT HERE

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
		cout << "Testing PolygonRotation (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1491065624;
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
		PolygonRotation _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int x[] = {0, 1, 1, 0};
				int y[] = {1, 1, 0, 0};
				_expected = 3.141592653589793;
				_received = _obj.getVolume(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 1:
			{
				int x[] = {0, 1, 0, -1};
				int y[] = {2, 1, 0, 1};
				_expected = 2.0943951023931953;
				_received = _obj.getVolume(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 2:
			{
				int x[] = {0, 3, 0, -2, -2};
				int y[] = {2, 0, -3, -1, 1};
				_expected = 49.91641660703782;
				_received = _obj.getVolume(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 3:
			{
				int x[] = {0, 3, 3, 0, -1, -1};
				int y[] = {2, 2, -2, -2, -1, 1};
				_expected = 113.09733552923255;
				_received = _obj.getVolume(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			/*case 4:
			{
				int x[] = ;
				int y[] = ;
				_expected = ;
				_received = _obj.getVolume(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int x[] = ;
				int y[] = ;
				_expected = ;
				_received = _obj.getVolume(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int x[] = ;
				int y[] = ;
				_expected = ;
				_received = _obj.getVolume(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (abs(_expected-_received) < 1e-9 || (_received > min(_expected*(1.0-1e-9), _expected*(1.0+1e-9)) && _received < max(_expected*(1.0-1e-9), _expected*(1.0+1e-9))))
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout.precision(10);
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
