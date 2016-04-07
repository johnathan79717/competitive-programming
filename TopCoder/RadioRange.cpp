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
#define ALL(x) (x).begin(),(x).end()
#define FOR(i, c) for(auto &i: c)
#define V(T) vector<T >
#define EB emplace_back
 
struct Event {
	double r;
	bool t;
	Event(double r, bool t): r(r), t(t) {}
};

struct RadioRange {
  double RadiusProbability(vector <int> X, vector <int> Y, vector <int> R, int Z) {
  	V(Event) e;
  	int N = X.size();
  	REP(i, N) {
  		double r = sqrt((double)X[i]*X[i] + (double)Y[i] * Y[i]);
  		e.EB(max(0.0, min(double(Z), r - R[i])), true);
  		e.EB(min(double(Z), r + R[i]), false);
  	}
  	sort(ALL(e), [](Event const &e1, Event const &e2) {
  		return e1.r < e2.r;
  	});
  	double ans = 0;
  	int no = 0;
  	double prev = 0;
  	FOR(ev, e) {
  		if(no == 0) ans += (ev.r - prev);
  		if(ev.t) no++;
  		else no--;
  		prev = ev.r;
  	}
  	if(no == 0) ans += (Z - prev);
  	return ans / Z;
  }
};

// BEGIN CUT HERE
/*
PROBLEM STATEMENT
Note that the return value is a floating-point number and 
that in this problem the allowed absolute or relative 
error has been increased to 1e-6.

This problem takes place in a plane.
Nikola works at a radio station that is located in the 
point (0, 0).
You can hear the station if and only if you are within a 
circle with center at (0, 0) and some unknown radius.

There are some cities near the station.
Each city has the shape of a circle with some positive 
integer radius.
Cities may partially or even completely overlap each 
other, and some of them may contain the radio station.
You are given the description of all cities as vector 
<int>s X, Y, and R.
For each valid i, there is a city with center at (X[i], Y
[i]) and radius R[i].

The radius of our radio station is bad if there is a city 
that is only partially covered by the radio signal.
Otherwise, the radius is good.
In other words, if there is a point in a city where you 
can listen to our radio and another point in the same city 
where you cannot do so, the radius is bad.
A radius is good if and only if each city is either 
covered completely by radio signal, or not covered at all.

You are given a int Z.
The radius of our radio station is a real number chosen 
uniformly at random from the range [0, Z].
Return the probability that the radius is good.

DEFINITION
Class:RadioRange
Method:RadiusProbability
Parameters:vector <int>, vector <int>, vector <int>, int
Returns:double
Method signature:double RadiusProbability(vector <int> X, 
vector <int> Y, vector <int> R, int Z)


NOTES
-Your return value must have an absolute or relative error 
less than 1e-6.


CONSTRAINTS
-X will contain between 1 and 100 elements, inclusive.
-X, Y, and R will each contain the same number of elements.
-Each element of X will be between -10^9 and 10^9, 
inclusive.
-Each element of Y will be between -10^9 and 10^9, 
inclusive.
-Each element of R will be between 1 and 10^9, inclusive.
-Z will be between 1 and 10^9, inclusive.


EXAMPLES

0)
{0}
{0}
{5}
10

Returns: 0.5

Our radio station is in the center of a city with radius 
5, and we are choosing the radius for the station 
uniformly at random from [0,10].
Radii in [0,5) are all bad, because people in the center 
of the city can hear our radio but people on its boundary 
cannot.
Radii in [5,10] are all good, as the entire city is covered.
Hence, the probability of having a good radius is 5/10 = 
0.5.

1)
{0}
{0}
{10}
10

Returns: 0.0

Our radio station is in the center of a city with radius 
10, and we are choosing the radius for the station 
uniformly at random from [0,10].
In this case, the only good radius is 10, but the 
probability that it will be chosen is zero.

2)
{10}
{10}
{10}
10

Returns: 0.4142135623730951

The center of the city is at (10, 10) and its radius is 10.
The good radii for our station are those where the city is 
not covered at all.
These are the radii from 0 to approximately 4.14.

3)
{11, -11, 0, 0}
{0, 0, 11, -11}
{10, 10, 10, 10}
31

Returns: 0.3548387096774194

Here we have four cities.
They are located to the north, south, east, and west of 
the station.
A radius is good if it lies in [0,1) or in [21,31].

4)
{100}
{100}
{1}
10

Returns: 1.0

It is possible that some cities will not be covered even 
if the radius of our radio station is Z.

5)
{1000000000}
{1000000000}
{1000000000}
1000000000

Returns: 0.41421356237309503



6)
{20, -20, 0, 0}
{0, 0, 20, -20}
{50, 50, 50, 50}
100

Returns: 0.3



7)
{0, -60, -62, -60, 63, -97}
{-72, 67, 61, -8, -32, 89}
{6, 7, 8, 7, 5, 6}
918

Returns: 0.9407071068962471



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
		cout << "Testing RadioRange (275.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1400598012;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 275.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		RadioRange _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int X[] = {0};
				int Y[] = {0};
				int R[] = {5};
				int Z = 10;
				_expected = 0.5;
				_received = _obj.RadiusProbability(vector <int>(X, X+sizeof(X)/sizeof(int)), vector <int>(Y, Y+sizeof(Y)/sizeof(int)), vector <int>(R, R+sizeof(R)/sizeof(int)), Z); break;
			}
			case 1:
			{
				int X[] = {0};
				int Y[] = {0};
				int R[] = {10};
				int Z = 10;
				_expected = 0.0;
				_received = _obj.RadiusProbability(vector <int>(X, X+sizeof(X)/sizeof(int)), vector <int>(Y, Y+sizeof(Y)/sizeof(int)), vector <int>(R, R+sizeof(R)/sizeof(int)), Z); break;
			}
			case 2:
			{
				int X[] = {10};
				int Y[] = {10};
				int R[] = {10};
				int Z = 10;
				_expected = 0.4142135623730951;
				_received = _obj.RadiusProbability(vector <int>(X, X+sizeof(X)/sizeof(int)), vector <int>(Y, Y+sizeof(Y)/sizeof(int)), vector <int>(R, R+sizeof(R)/sizeof(int)), Z); break;
			}
			case 3:
			{
				int X[] = {11, -11, 0, 0};
				int Y[] = {0, 0, 11, -11};
				int R[] = {10, 10, 10, 10};
				int Z = 31;
				_expected = 0.3548387096774194;
				_received = _obj.RadiusProbability(vector <int>(X, X+sizeof(X)/sizeof(int)), vector <int>(Y, Y+sizeof(Y)/sizeof(int)), vector <int>(R, R+sizeof(R)/sizeof(int)), Z); break;
			}
			case 4:
			{
				int X[] = {100};
				int Y[] = {100};
				int R[] = {1};
				int Z = 10;
				_expected = 1.0;
				_received = _obj.RadiusProbability(vector <int>(X, X+sizeof(X)/sizeof(int)), vector <int>(Y, Y+sizeof(Y)/sizeof(int)), vector <int>(R, R+sizeof(R)/sizeof(int)), Z); break;
			}
			case 5:
			{
				int X[] = {1000000000};
				int Y[] = {1000000000};
				int R[] = {1000000000};
				int Z = 1000000000;
				_expected = 0.41421356237309503;
				_received = _obj.RadiusProbability(vector <int>(X, X+sizeof(X)/sizeof(int)), vector <int>(Y, Y+sizeof(Y)/sizeof(int)), vector <int>(R, R+sizeof(R)/sizeof(int)), Z); break;
			}
			case 6:
			{
				int X[] = {20, -20, 0, 0};
				int Y[] = {0, 0, 20, -20};
				int R[] = {50, 50, 50, 50};
				int Z = 100;
				_expected = 0.3;
				_received = _obj.RadiusProbability(vector <int>(X, X+sizeof(X)/sizeof(int)), vector <int>(Y, Y+sizeof(Y)/sizeof(int)), vector <int>(R, R+sizeof(R)/sizeof(int)), Z); break;
			}
			case 7:
			{
				int X[] = {0, -60, -62, -60, 63, -97};
				int Y[] = {-72, 67, 61, -8, -32, 89};
				int R[] = {6, 7, 8, 7, 5, 6};
				int Z = 918;
				_expected = 0.9407071068962471;
				_received = _obj.RadiusProbability(vector <int>(X, X+sizeof(X)/sizeof(int)), vector <int>(Y, Y+sizeof(Y)/sizeof(int)), vector <int>(R, R+sizeof(R)/sizeof(int)), Z); break;
			}
			/*case 8:
			{
				int X[] = ;
				int Y[] = ;
				int R[] = ;
				int Z = ;
				_expected = ;
				_received = _obj.RadiusProbability(vector <int>(X, X+sizeof(X)/sizeof(int)), vector <int>(Y, Y+sizeof(Y)/sizeof(int)), vector <int>(R, R+sizeof(R)/sizeof(int)), Z); break;
			}*/
			/*case 9:
			{
				int X[] = ;
				int Y[] = ;
				int R[] = ;
				int Z = ;
				_expected = ;
				_received = _obj.RadiusProbability(vector <int>(X, X+sizeof(X)/sizeof(int)), vector <int>(Y, Y+sizeof(Y)/sizeof(int)), vector <int>(R, R+sizeof(R)/sizeof(int)), Z); break;
			}*/
			/*case 10:
			{
				int X[] = ;
				int Y[] = ;
				int R[] = ;
				int Z = ;
				_expected = ;
				_received = _obj.RadiusProbability(vector <int>(X, X+sizeof(X)/sizeof(int)), vector <int>(Y, Y+sizeof(Y)/sizeof(int)), vector <int>(R, R+sizeof(R)/sizeof(int)), Z); break;
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
