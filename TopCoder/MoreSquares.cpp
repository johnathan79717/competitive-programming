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
#include <complex>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define ALL(x) (x).begin(),(x).end()
#define MP make_pair
#define V(T) vector<T >
 
typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;
#define x real
#define y imag
typedef complex<double> point;

#line 41 "MoreSquares.cpp"
#include <string>
#include <vector>
class MoreSquares {
public:
    struct Comp {
	bool operator()(const point& a, const point &b) const {
	    return MP(a.x(), a.y()) < MP(b.x(), b.y());
	}
    };
    int countLocations(int N, int SX, int SY, vector <int> Xprefix, vector <int> Yprefix) {
	V(point) p(N);
	int L = Xprefix.size();
	REP(i, L) {
	    p[i] = point(Xprefix[i], Yprefix[i]);
	}
	REP1(i, L, N-1) {
	    double x = fmod(p[i-1].x() * 47 + 42, SX);
	    double y = fmod(p[i-1].y() * 47 + 42, SY);
	    p[i] = point(x, y);
	}
	set<point, Comp> s(ALL(p)), ans;
	for (auto &p1 : s) {
	    for (auto &p2: s) {
		auto p3 = p1 + (p2 - p1) * point(0, 1);
		auto p4 = p2 + p3 - p1;
		if (s.count(p3) && !s.count(p4)) {
		    ans.insert(p4);
		}
		if (s.count(p4) && !s.count(p3)) {
		    ans.insert(p3);
		}
	    }
	}
	return ans.size();
    }
};

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
Given a set of points in the plane, its square count is the number of ways in which we can select four of those points in such a way that they form the corners of a square.
The square may be rotated arbitrarily. Order of the four points does not matter. For example, the square count for the set { (1,2), (1,0), (0,1), (2,1) } is 1.



You are given a set S of points in the plane with integer coordinates.
Return the number of points P with the following property: P is not in S, and if we add P to S, the square count will increase.



In order to keep the input size small, S is given as follows:
You are given the ints N, SX, SY, and the vector <int>s Xprefix and Yprefix.
Use the pseudocode given below to generate S.



X, Y = two empty arrays of length N each
L    = length(Xprefix)

for i = 0 .. L-1:
    X[i] = Xprefix[i]
    Y[i] = Yprefix[i]

for i = L .. N-1:
    X[i] = ( X[i-1] * 47 + 42 ) modulo SX
    Y[i] = ( Y[i-1] * 47 + 42 ) modulo SY

for i = 0 .. N-1:
    if (X[i], Y[i]) is not in S:
        add (X[i], Y[i]) to S


DEFINITION
Class:MoreSquares
Method:countLocations
Parameters:int, int, int, vector <int>, vector <int>
Returns:int
Method signature:int countLocations(int N, int SX, int SY, vector <int> Xprefix, vector <int> Yprefix)


NOTES
-The reference solution would work fast enough for any input of the given size, it does not depend on any properties of the pseudorandom generator.
-The new point P can lie anywhere in the plane.


CONSTRAINTS
-N will be between 1 and 3,000, inclusive.
-SX and SY will each be between 1 and 10^6, inclusive.
-Xprefix will have between 1 and min(100,N) elements, inclusive.
-Yprefix will have the same number of elements as Xprefix.
-Each element of Xprefix will be between 0 and SX-1, inclusive.
-Each element of Yprefix will be between 0 and SY-1, inclusive.


EXAMPLES

0)
3
100
100
{3, 0, 2}
{0, 1, 2}

Returns: 1

The set S contains the points (3,0), (0,1), and (2,2). By adding a fourth point at (1,-1) we can increase the square count from 0 to 1.

1)
5
100
100
{47, 47, 47, 47, 47}
{47, 47, 47, 47, 47}

Returns: 0

The set S contains only one point: (47, 47). Adding a second point will always produce a two-element set with square count zero.

2)
23
11
13
{7}
{0}

Returns: 5


The set S contains 20 points. In the order of insertion, these are: (7, 0), (8, 3), (0, 1), (9, 11), (3, 0), (7, 3), (8, 1), (0, 11), (9, 0), (3, 3), (7, 1), (8, 11), (0, 0), (9, 3), (3, 1), (7, 11), (8, 0), (0, 3), (9, 1), (3, 11). The last three points generated using the formula in the statement are (7, 0), (8, 3), and (0, 1) again.


The five possible locations for the new point that increases the square count are (6, 2), (8, -1), (8, 2), (10, 2), and (11, 8).


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
		cout << "Testing MoreSquares (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1553943644;
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
		MoreSquares _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 3;
				int SX = 100;
				int SY = 100;
				int Xprefix[] = {3, 0, 2};
				int Yprefix[] = {0, 1, 2};
				_expected = 1;
				_received = _obj.countLocations(N, SX, SY, vector <int>(Xprefix, Xprefix+sizeof(Xprefix)/sizeof(int)), vector <int>(Yprefix, Yprefix+sizeof(Yprefix)/sizeof(int))); break;
			}
			case 1:
			{
				int N = 5;
				int SX = 100;
				int SY = 100;
				int Xprefix[] = {47, 47, 47, 47, 47};
				int Yprefix[] = {47, 47, 47, 47, 47};
				_expected = 0;
				_received = _obj.countLocations(N, SX, SY, vector <int>(Xprefix, Xprefix+sizeof(Xprefix)/sizeof(int)), vector <int>(Yprefix, Yprefix+sizeof(Yprefix)/sizeof(int))); break;
			}
			case 2:
			{
				int N = 23;
				int SX = 11;
				int SY = 13;
				int Xprefix[] = {7};
				int Yprefix[] = {0};
				_expected = 5;
				_received = _obj.countLocations(N, SX, SY, vector <int>(Xprefix, Xprefix+sizeof(Xprefix)/sizeof(int)), vector <int>(Yprefix, Yprefix+sizeof(Yprefix)/sizeof(int))); break;
			}
			/*case 3:
			{
				int N = ;
				int SX = ;
				int SY = ;
				int Xprefix[] = ;
				int Yprefix[] = ;
				_expected = ;
				_received = _obj.countLocations(N, SX, SY, vector <int>(Xprefix, Xprefix+sizeof(Xprefix)/sizeof(int)), vector <int>(Yprefix, Yprefix+sizeof(Yprefix)/sizeof(int))); break;
			}*/
			/*case 4:
			{
				int N = ;
				int SX = ;
				int SY = ;
				int Xprefix[] = ;
				int Yprefix[] = ;
				_expected = ;
				_received = _obj.countLocations(N, SX, SY, vector <int>(Xprefix, Xprefix+sizeof(Xprefix)/sizeof(int)), vector <int>(Yprefix, Yprefix+sizeof(Yprefix)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int N = ;
				int SX = ;
				int SY = ;
				int Xprefix[] = ;
				int Yprefix[] = ;
				_expected = ;
				_received = _obj.countLocations(N, SX, SY, vector <int>(Xprefix, Xprefix+sizeof(Xprefix)/sizeof(int)), vector <int>(Yprefix, Yprefix+sizeof(Yprefix)/sizeof(int))); break;
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
