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

class ArmyTeleportation {
	public:
	string ifPossible(vector <int> x1, vector <int> y1, vector <int> x2, vector <int> y2, vector <int> xt, vector <int> yt) {
		
	}
};
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// King Janusz is in great trouble.
His enemies have attacked his kingdom from a direction the king did not expect and now he must relocate his troops quickly.
The desperate king asked the great sorcerer Mirek for help.

Mirek has three magic towers that are able to teleport troops.
Each time a tower is activated, all soldiers get teleported to new locations.
The new location is computed by reflecting the old position through the position of the activated tower.
(In other words, the activated tower will be in the middle of each segment that connects the old and the new position of a soldier.)

The king can activate the towers in any order he likes.
Each tower can be activated arbitrarily many times.

You are given the current locations of the troops in vector <int>s x1 and y1.
For each valid i, there is a soldier on the point (x1[i], y1[i]).
You are also given the desired locations of the troops in vector <int>s x2 and y2.
For each valid i, the King wants to have a soldier on the point (x2[i], y2[i]).
Finally, you are given the coordinates of the three towers in vector <int>s xt and yt.

The soldiers are not allowed to move in any way other than by teleportation.
The order of soldiers does not have to be preserved.
(For example, the soldier that started at (x1[0], y1[0]) may end at (x2[2], y2[2]).)

Return "possible" (quotes for clarity) if it is possible to reach the state in which there are soldiers at all desired locations.
Otherwise, return "impossible".


DEFINITION
Class:ArmyTeleportation
Method:ifPossible
Parameters:vector <int>, vector <int>, vector <int>, vector <int>, vector <int>, vector <int>
Returns:string
Method signature:string ifPossible(vector <int> x1, vector <int> y1, vector <int> x2, vector <int> y2, vector <int> xt, vector <int> yt)


CONSTRAINTS
-x1, y1, x2 and y2 will have the same number of element which will be between 1 and 50, inclusive.
-xt and yt will have exactly 3 elements each.
-The points described by x1 and y1 are pairwise distinct.
-The points described by x2 and y2 are pairwise distinct.
-The points described by xt and yt are pairwise distinct.
-Each element of x1, y1, x2, y2, xt and yt will be between -1,000,000 and 1,000,000, inclusive.


EXAMPLES

0)
{0, 1}
{0, 1}
{2, 1}
{4, 3}
{2, 3, 2}
{0, 1, 3}

Returns: "possible"

We have soldiers at (0,0) and (1,1).
We want to have soldiers at (2,4) and (1,3).
There are three towers: at (2,0), (3,1), and (2,3).

Mirek can teleport the king's troops as follows:

He will activate the tower at (2,0). One soldier will teleport from (0,0) to (4,0), the other from (1,1) to (3,-1).
He will activate the tower at (3,1), teleporting the soldiers to (2,2) and (3,3).
He will activate the tower at (2,3), teleporting the soldiers to (2,4) and (1,3), as desired.


1)
{0, 1, 2}
{2, 4, 6}
{3, 5, 6}
{1, 1, 0}
{3, 1, -2}
{4, 2, 10}

Returns: "impossible"

The soldiers are standing in a line. It is impossible to change that during the teleportation.

2)
{0, 1}
{1, 2}
{1, 2}
{2, 3}
{0, 0, 0}
{5, 3, 8}

Returns: "impossible"

Regardless of the order of teleportation, the soldier that starts at (0,1) will always have his x coordinate equal to zero.
Therefore he will never reach any of the desired destinations.

3)
{6, -5, 1}
{3, -10, -7}
{0, 11, 5}
{-5, 8, 5}
{0, -5, 4}
{-8, -9, -4}

Returns: "possible"



4)
{3, 2, 1}
{1, 2, 3}
{4, 5, 6}
{6, 5, 4}
{-2, 5, 6}
{1, -3, 2}

Returns: "impossible"



5)
{903, -970, 404, 563}
{-348, -452, 37, 692}
{3359, 1486, 2860, 3019}
{-416, -520, -31, 624}
{346, -838, 916}
{-541, -717, -348}

Returns: "possible"



6)
{4600, 8914, 9330, -193, 5422}
{25, 7650, -7366, -8494, -6574}
{-117326, -121640, -122056, -112533, -118148}
{322619, 314994, 330010, 331138, 329218}
{9523, -7546, -9858}
{-3750, -5347, -3828}

Returns: "impossible"



7)
{4514, -67225, -78413, -96468, -58938}
{-22815, -86062, -54529, -87391, 42044}
{259998, 331737, 342925, 360980, 323450}
{912263, 975510, 943977, 976839, 847404}
{23726, -98808, -26788}
{80876, -68160, -13684}

Returns: "possible"



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
		cout << "Testing ArmyTeleportation (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1421079934;
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
		ArmyTeleportation _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int x1[] = {0, 1};
				int y1[] = {0, 1};
				int x2[] = {2, 1};
				int y2[] = {4, 3};
				int xt[] = {2, 3, 2};
				int yt[] = {0, 1, 3};
				_expected = "possible";
				_received = _obj.ifPossible(vector <int>(x1, x1+sizeof(x1)/sizeof(int)), vector <int>(y1, y1+sizeof(y1)/sizeof(int)), vector <int>(x2, x2+sizeof(x2)/sizeof(int)), vector <int>(y2, y2+sizeof(y2)/sizeof(int)), vector <int>(xt, xt+sizeof(xt)/sizeof(int)), vector <int>(yt, yt+sizeof(yt)/sizeof(int))); break;
			}
			case 1:
			{
				int x1[] = {0, 1, 2};
				int y1[] = {2, 4, 6};
				int x2[] = {3, 5, 6};
				int y2[] = {1, 1, 0};
				int xt[] = {3, 1, -2};
				int yt[] = {4, 2, 10};
				_expected = "impossible";
				_received = _obj.ifPossible(vector <int>(x1, x1+sizeof(x1)/sizeof(int)), vector <int>(y1, y1+sizeof(y1)/sizeof(int)), vector <int>(x2, x2+sizeof(x2)/sizeof(int)), vector <int>(y2, y2+sizeof(y2)/sizeof(int)), vector <int>(xt, xt+sizeof(xt)/sizeof(int)), vector <int>(yt, yt+sizeof(yt)/sizeof(int))); break;
			}
			case 2:
			{
				int x1[] = {0, 1};
				int y1[] = {1, 2};
				int x2[] = {1, 2};
				int y2[] = {2, 3};
				int xt[] = {0, 0, 0};
				int yt[] = {5, 3, 8};
				_expected = "impossible";
				_received = _obj.ifPossible(vector <int>(x1, x1+sizeof(x1)/sizeof(int)), vector <int>(y1, y1+sizeof(y1)/sizeof(int)), vector <int>(x2, x2+sizeof(x2)/sizeof(int)), vector <int>(y2, y2+sizeof(y2)/sizeof(int)), vector <int>(xt, xt+sizeof(xt)/sizeof(int)), vector <int>(yt, yt+sizeof(yt)/sizeof(int))); break;
			}
			case 3:
			{
				int x1[] = {6, -5, 1};
				int y1[] = {3, -10, -7};
				int x2[] = {0, 11, 5};
				int y2[] = {-5, 8, 5};
				int xt[] = {0, -5, 4};
				int yt[] = {-8, -9, -4};
				_expected = "possible";
				_received = _obj.ifPossible(vector <int>(x1, x1+sizeof(x1)/sizeof(int)), vector <int>(y1, y1+sizeof(y1)/sizeof(int)), vector <int>(x2, x2+sizeof(x2)/sizeof(int)), vector <int>(y2, y2+sizeof(y2)/sizeof(int)), vector <int>(xt, xt+sizeof(xt)/sizeof(int)), vector <int>(yt, yt+sizeof(yt)/sizeof(int))); break;
			}
			case 4:
			{
				int x1[] = {3, 2, 1};
				int y1[] = {1, 2, 3};
				int x2[] = {4, 5, 6};
				int y2[] = {6, 5, 4};
				int xt[] = {-2, 5, 6};
				int yt[] = {1, -3, 2};
				_expected = "impossible";
				_received = _obj.ifPossible(vector <int>(x1, x1+sizeof(x1)/sizeof(int)), vector <int>(y1, y1+sizeof(y1)/sizeof(int)), vector <int>(x2, x2+sizeof(x2)/sizeof(int)), vector <int>(y2, y2+sizeof(y2)/sizeof(int)), vector <int>(xt, xt+sizeof(xt)/sizeof(int)), vector <int>(yt, yt+sizeof(yt)/sizeof(int))); break;
			}
			case 5:
			{
				int x1[] = {903, -970, 404, 563};
				int y1[] = {-348, -452, 37, 692};
				int x2[] = {3359, 1486, 2860, 3019};
				int y2[] = {-416, -520, -31, 624};
				int xt[] = {346, -838, 916};
				int yt[] = {-541, -717, -348};
				_expected = "possible";
				_received = _obj.ifPossible(vector <int>(x1, x1+sizeof(x1)/sizeof(int)), vector <int>(y1, y1+sizeof(y1)/sizeof(int)), vector <int>(x2, x2+sizeof(x2)/sizeof(int)), vector <int>(y2, y2+sizeof(y2)/sizeof(int)), vector <int>(xt, xt+sizeof(xt)/sizeof(int)), vector <int>(yt, yt+sizeof(yt)/sizeof(int))); break;
			}
			case 6:
			{
				int x1[] = {4600, 8914, 9330, -193, 5422};
				int y1[] = {25, 7650, -7366, -8494, -6574};
				int x2[] = {-117326, -121640, -122056, -112533, -118148};
				int y2[] = {322619, 314994, 330010, 331138, 329218};
				int xt[] = {9523, -7546, -9858};
				int yt[] = {-3750, -5347, -3828};
				_expected = "impossible";
				_received = _obj.ifPossible(vector <int>(x1, x1+sizeof(x1)/sizeof(int)), vector <int>(y1, y1+sizeof(y1)/sizeof(int)), vector <int>(x2, x2+sizeof(x2)/sizeof(int)), vector <int>(y2, y2+sizeof(y2)/sizeof(int)), vector <int>(xt, xt+sizeof(xt)/sizeof(int)), vector <int>(yt, yt+sizeof(yt)/sizeof(int))); break;
			}
			case 7:
			{
				int x1[] = {4514, -67225, -78413, -96468, -58938};
				int y1[] = {-22815, -86062, -54529, -87391, 42044};
				int x2[] = {259998, 331737, 342925, 360980, 323450};
				int y2[] = {912263, 975510, 943977, 976839, 847404};
				int xt[] = {23726, -98808, -26788};
				int yt[] = {80876, -68160, -13684};
				_expected = "possible";
				_received = _obj.ifPossible(vector <int>(x1, x1+sizeof(x1)/sizeof(int)), vector <int>(y1, y1+sizeof(y1)/sizeof(int)), vector <int>(x2, x2+sizeof(x2)/sizeof(int)), vector <int>(y2, y2+sizeof(y2)/sizeof(int)), vector <int>(xt, xt+sizeof(xt)/sizeof(int)), vector <int>(yt, yt+sizeof(yt)/sizeof(int))); break;
			}
			/*case 8:
			{
				int x1[] = ;
				int y1[] = ;
				int x2[] = ;
				int y2[] = ;
				int xt[] = ;
				int yt[] = ;
				_expected = ;
				_received = _obj.ifPossible(vector <int>(x1, x1+sizeof(x1)/sizeof(int)), vector <int>(y1, y1+sizeof(y1)/sizeof(int)), vector <int>(x2, x2+sizeof(x2)/sizeof(int)), vector <int>(y2, y2+sizeof(y2)/sizeof(int)), vector <int>(xt, xt+sizeof(xt)/sizeof(int)), vector <int>(yt, yt+sizeof(yt)/sizeof(int))); break;
			}*/
			/*case 9:
			{
				int x1[] = ;
				int y1[] = ;
				int x2[] = ;
				int y2[] = ;
				int xt[] = ;
				int yt[] = ;
				_expected = ;
				_received = _obj.ifPossible(vector <int>(x1, x1+sizeof(x1)/sizeof(int)), vector <int>(y1, y1+sizeof(y1)/sizeof(int)), vector <int>(x2, x2+sizeof(x2)/sizeof(int)), vector <int>(y2, y2+sizeof(y2)/sizeof(int)), vector <int>(xt, xt+sizeof(xt)/sizeof(int)), vector <int>(yt, yt+sizeof(yt)/sizeof(int))); break;
			}*/
			/*case 10:
			{
				int x1[] = ;
				int y1[] = ;
				int x2[] = ;
				int y2[] = ;
				int xt[] = ;
				int yt[] = ;
				_expected = ;
				_received = _obj.ifPossible(vector <int>(x1, x1+sizeof(x1)/sizeof(int)), vector <int>(y1, y1+sizeof(y1)/sizeof(int)), vector <int>(x2, x2+sizeof(x2)/sizeof(int)), vector <int>(y2, y2+sizeof(y2)/sizeof(int)), vector <int>(xt, xt+sizeof(xt)/sizeof(int)), vector <int>(yt, yt+sizeof(yt)/sizeof(int))); break;
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
			cout << "           Expected: " << "\"" << _expected << "\"" << endl;
			cout << "           Received: " << "\"" << _received << "\"" << endl;
		}
	}
}

// END CUT HERE
