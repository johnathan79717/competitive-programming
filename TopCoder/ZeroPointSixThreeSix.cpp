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
// #line 40 "ZeroPointSixThreeSix.cpp"
#include <string>
#include <vector>
class ZeroPointSixThreeSix {
public:
    vector <int> replan(vector <int> x, vector <int> y, vector <int> match) {
        
    }
};
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Foxland is a perfectly flat country.
There are 2*n cities in Foxland.
The cities are numbered 0 through 2*n-1.
For the purpose of this problem, each city is a point.
You are given the coordinates of all cities in the vector <int>s x and y.
For each valid i, city i is located at (x[i], y[i]).



Each city has an airport.
There are some flights between those airports.
Flight regulations in Foxland specify that each flight must be a round-trip flight between two cities.
Additionally, the trajectory of a flight must be the straight line segment between those two cities.
(I.e., the planes must always fly along the shortest path.)



Fox Airline is the only airline in Foxland.
The airline operates exactly n flights.
Each city is served by one of the flights.
In other words, there are n disjoint pairs of cities, with each pair of cities being served by one of the n flights.



One day, Fox TV has shown a sci-fi movie in which two airplanes collided.
After seeing the movie, many citizens of Foxland became afraid of flying.
In order to make them feel safe again, Fox Airline now wants to make sure that their planes will never collide.
More precisely, they want to make sure that the trajectories of their n flights are disjoint.



The revenue from a flight is proportional to its length, i.e., to the Euclidean distance between the cities it connects.
Your task will be to reroute the flights without losing too much revenue.



You are given the information about the current n flights in the vector <int> match with 2*n elements.
For each valid i, there is a flight between cities i and match[i].
Note that the set of flights described by match can be arbitrary, it does not necessarily maximize the total revenue.
Your task is to find a new set of n flights with the following properties:


As before, each of the 2*n cities must be served by one of the n new flights.
The trajectories of the n new flights must be pairwise disjoint.
If the total length of the n old flights is L, the total length of the n new flights must be at least 0.636 * L.


Note that some of the old flights may appear among the new flights.
In fact, if the old flights have disjoint trajectories, the new flights may be the same as the old flights.



Return a vector <int> with 2*n elements, describing the n new flights using the same format as in match.
You may assume that there is always at least one valid solution.
If there are multiple valid solutions, you may return any of them.

DEFINITION
Class:ZeroPointSixThreeSix
Method:replan
Parameters:vector <int>, vector <int>, vector <int>
Returns:vector <int>
Method signature:vector <int> replan(vector <int> x, vector <int> y, vector <int> match)


CONSTRAINTS
-x will contain between 4 and 200 elements, inclusive.
-x will contain an even number of elements.
-x and y will contain the same number of elements, inclusive.
-Each element in x and y will be between -100,000 and 100,000, inclusive.
-No three points will be on the same line.
-match will contain exactly |x| elements.
-Each element in match will be between 0 and |x|-1, inclusive.
-For each valid i, match[i] != i.
-For each valid i, match[match[i]] = i.


EXAMPLES

0)
{0,0,1,1}
{0,1,0,1}
{3,2,1,0}

Returns: {1, 0, 3, 2 }

The four cities are located in the vertices of a square.
The two old flights correspond to the diagonals of the square.
Instead of those, we can choose any two opposite sides of the square as the two new flights.
If the total length of the old flights is L, the total lenght of the new flights is L / sqrt(2).
This is approximately 0.707 * L , which is clearly at least 0.636 * L.

1)
{0,0,4,4}
{0,3,0,3}
{3,2,1,0}

Returns: {2, 3, 0, 1 }

In this example the four cities are located in the vertices of a 4 by 3 rectangle.
Again, the old flights correspond to the diagonals of the rectangle.
Their total length is L = 10.
Note that this time the two new flights must correspond to the long sides of the rectangle.
If you choose the two short sides as the new flights, their total length will be only 0.6 * L, which is less than 0.636.
For the two long sides the total length is 0.8 * L.

2)
{0,0,4,4}
{0,3,0,3}
{1,0,3,2}

Returns: {2, 3, 0, 1 }

Here we have the same four cities, but this time the old flights correspond to the short sides of the rectangle.
You may return those two flights, but you may also return the two flights that correspond to the long sides of the rectangle.
In that case, the revenue from the new flights will actually be greater than the revenue from the old flights.
This is allowed.

3)
{-1,1,100,100,1,-1,-100,-100}
{100,100,1,-1,-100,-100,-1,1}
{1,0,3,2,5,4,7,6}

Returns: {1, 0, 3, 2, 5, 4, 7, 6 }

There is no intersection in the old plan, so you can output it.

4)
{-1,1,100,100,1,-1,-100,-100}
{100,100,1,-1,-100,-100,-1,1}
{2,3,0,1,6,7,4,5}

Returns: {7, 2, 1, 4, 3, 6, 5, 0 }



5)
{-9331, -7945, 697, 7897, 3789, -4517, -7995, 6145, -3842, -3234, -4150, -4414, -8065, 7381, -6647, -4401}
{2058, -5482, 5501, -3207, -3836, -2061, 9589, 8487, -3062, -3736, 1491, 1424, 7285, -6753, 3937, -1084}
{3, 2, 1, 0, 11, 10, 8, 15, 6, 12, 5, 4, 9, 14, 13, 7}

Returns: {1, 0, 3, 2, 5, 4, 7, 6, 9, 8, 11, 10, 13, 12, 15, 14 }



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
		cout << "Testing ZeroPointSixThreeSix (900.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1461429889;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 900.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		ZeroPointSixThreeSix _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int x[] = {0,0,1,1};
				int y[] = {0,1,0,1};
				int match[] = {3,2,1,0};
				int __expected[] = {1, 0, 3, 2 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.replan(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(match, match+sizeof(match)/sizeof(int))); break;
			}
			case 1:
			{
				int x[] = {0,0,4,4};
				int y[] = {0,3,0,3};
				int match[] = {3,2,1,0};
				int __expected[] = {2, 3, 0, 1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.replan(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(match, match+sizeof(match)/sizeof(int))); break;
			}
			case 2:
			{
				int x[] = {0,0,4,4};
				int y[] = {0,3,0,3};
				int match[] = {1,0,3,2};
				int __expected[] = {2, 3, 0, 1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.replan(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(match, match+sizeof(match)/sizeof(int))); break;
			}
			case 3:
			{
				int x[] = {-1,1,100,100,1,-1,-100,-100};
				int y[] = {100,100,1,-1,-100,-100,-1,1};
				int match[] = {1,0,3,2,5,4,7,6};
				int __expected[] = {1, 0, 3, 2, 5, 4, 7, 6 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.replan(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(match, match+sizeof(match)/sizeof(int))); break;
			}
			case 4:
			{
				int x[] = {-1,1,100,100,1,-1,-100,-100};
				int y[] = {100,100,1,-1,-100,-100,-1,1};
				int match[] = {2,3,0,1,6,7,4,5};
				int __expected[] = {7, 2, 1, 4, 3, 6, 5, 0 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.replan(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(match, match+sizeof(match)/sizeof(int))); break;
			}
			case 5:
			{
				int x[] = {-9331, -7945, 697, 7897, 3789, -4517, -7995, 6145, -3842, -3234, -4150, -4414, -8065, 7381, -6647, -4401};
				int y[] = {2058, -5482, 5501, -3207, -3836, -2061, 9589, 8487, -3062, -3736, 1491, 1424, 7285, -6753, 3937, -1084};
				int match[] = {3, 2, 1, 0, 11, 10, 8, 15, 6, 12, 5, 4, 9, 14, 13, 7};
				int __expected[] = {1, 0, 3, 2, 5, 4, 7, 6, 9, 8, 11, 10, 13, 12, 15, 14 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.replan(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(match, match+sizeof(match)/sizeof(int))); break;
			}
			/*case 6:
			{
				int x[] = ;
				int y[] = ;
				int match[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.replan(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(match, match+sizeof(match)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int x[] = ;
				int y[] = ;
				int match[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.replan(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(match, match+sizeof(match)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int x[] = ;
				int y[] = ;
				int match[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.replan(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(match, match+sizeof(match)/sizeof(int))); break;
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
