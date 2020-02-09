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
#include <cassert>
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
#define PER(i,n) for(int i=(n)-1;i>=0;i--)
#define PER1(i,a,b) for(int i=(a);i>=(b);i--)
 
typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;

#line 41 "EllysSki.cpp"
#include <string>
#include <vector>
class EllysSki {
public:
    int getMax(vector <int> height) {
	int ans = 1;
	int N = height.size();
	REP(i, N) {
	    int n = 1;
	    REP1(j, i+1, N-1) {
		if (height[j] <= height[j-1]) {
		    n++;
		} else {
		    break;
		}
	    }
	    ans = max(ans, n);
	    n = 1;
	    PER1(j, i-1, 0) {
		if (height[j] <= height[j+1]) {
		    n++;
		} else {
		    break;
		}
	    }
	    ans = max(ans, n);
	    //cout << i << ' ' << ans << endl;
	}
	return ans;
    }
};

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
Elly hates the cold, but for some weird reason she likes skiing. Now she has started organizing a new ski adventure on a mountain ridge she hasn't visited before.


Elly has a map of the mountain ridge: the vector <int> height.
The mountain (when viewed from a side) has the shape of a polyline that goes through the points (0, height[0]), (1, height[1]), (2, height[2]), and so on.
For example, suppose height = {3, 4, 11, 6, 2, 2, 2, 5, 7, 7, 10, 8, 5, 8, 1, 4}.
If you walk along this mountain from the left to the right, you start at altitude 3, go up to altitude 4, then up some more to altitude 11. From there it goes down the hill to altitudes 6, 2, and so on.


Elly can hire a helicopter to bring her up to any point on the mountain. 
She can then pick a direction (either left or right) and start skiing.
There are only two restrictions:


She cannot ski uphill.
While skiing, she cannot change direction. (If she started skiing left, she cannot turn around and ski right, or vice versa.)


For example, suppose Elly starts at index 2 (altitude 11) and chooses to go right. In this case the longest possible ski run consists of five points: {11, 6, 2, 2, 2}. She cannot continue farther because the next segment of the mountain goes uphill.
Should she start at the same place and go left instead, she would only visit three points (altitudes 11, 4, and 3, in this order).


Find the longest section of the mountain Elly can ski in a single run, and return the number of points that form the section.


DEFINITION
Class:EllysSki
Method:getMax
Parameters:vector <int>
Returns:int
Method signature:int getMax(vector <int> height)


CONSTRAINTS
-height will contain between 1 and 50 elements, inclusive.
-Each element of height will be between 1 and 1000, inclusive.


EXAMPLES

0)
{3, 4, 11, 6, 2, 2, 2, 5, 7, 7, 10, 8, 5, 8, 1, 4}

Returns: 7

The example from the problem statement.
The optimal solution is to start at index 10 (altitude 10) and ski left. The points visited, in order in which Elly skis through them, have altitudes {10, 7, 7, 5, 2, 2, 2}.

1)
{42, 42, 42}

Returns: 3

This mountain is quite flat, but okay for skiing, according to Elly. She should start at either end and ski towards the other end.

2)
{543, 230, 421, 415, 271, 962, 677, 373, 951, 114, 379, 15, 211, 955, 66, 573, 982, 296, 730, 591}

Returns: 3



3)
{50, 77, 24, 86, 98, 84, 42, 70, 88, 78, 73, 17, 76, 68, 64, 65, 40, 77, 33, 87, 11, 23, 78, 20, 8, 74, 44, 95, 94, 78, 27, 88, 71, 40, 11, 98, 82, 85, 79, 89, 31, 67, 41, 61, 71, 62, 74, 77, 86, 36}

Returns: 4



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
		cout << "Testing EllysSki (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1556708405;
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
		EllysSki _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int height[] = {3, 4, 11, 6, 2, 2, 2, 5, 7, 7, 10, 8, 5, 8, 1, 4};
				_expected = 7;
				_received = _obj.getMax(vector <int>(height, height+sizeof(height)/sizeof(int))); break;
			}
			case 1:
			{
				int height[] = {42, 42, 42};
				_expected = 3;
				_received = _obj.getMax(vector <int>(height, height+sizeof(height)/sizeof(int))); break;
			}
			case 2:
			{
				int height[] = {543, 230, 421, 415, 271, 962, 677, 373, 951, 114, 379, 15, 211, 955, 66, 573, 982, 296, 730, 591};
				_expected = 3;
				_received = _obj.getMax(vector <int>(height, height+sizeof(height)/sizeof(int))); break;
			}
			case 3:
			{
				int height[] = {50, 77, 24, 86, 98, 84, 42, 70, 88, 78, 73, 17, 76, 68, 64, 65, 40, 77, 33, 87, 11, 23, 78, 20, 8, 74, 44, 95, 94, 78, 27, 88, 71, 40, 11, 98, 82, 85, 79, 89, 31, 67, 41, 61, 71, 62, 74, 77, 86, 36};
				_expected = 4;
				_received = _obj.getMax(vector <int>(height, height+sizeof(height)/sizeof(int))); break;
			}
			/*case 4:
			{
				int height[] = ;
				_expected = ;
				_received = _obj.getMax(vector <int>(height, height+sizeof(height)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int height[] = ;
				_expected = ;
				_received = _obj.getMax(vector <int>(height, height+sizeof(height)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int height[] = ;
				_expected = ;
				_received = _obj.getMax(vector <int>(height, height+sizeof(height)/sizeof(int))); break;
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
