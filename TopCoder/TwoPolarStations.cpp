#line 2 "TwoPolarStations.cpp"
#include <array>
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
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define FOR(I, A, B) for (int I = (A); I <= (B); ++I)
#define FORS(I, S) for (int I = 0; S[I]; ++I)
#define RS(X) scanf("%s", (X))
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define GET_POS(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
#define CASET int ___T; scanf("%d", &___T); for(int cs=1;cs<=___T;cs++)
#define MP make_pair
#define PB emplace_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define F first
#define S second
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

class TwoPolarStations {
public:
    int count(int N, int lo, int hi) {
		
    }
};

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
A polar station consists of N sensors and two habitats for the researchers.
The sensors measure various things: temperature, air pressure, the number of polar bears in vicinity, and so on.
All N sensors are placed on the same circle around the habitats.
The sensors are numbered from 0 to N-1 in the order in which they lie on the circle.
For convenience, the habitats will get the numbers N and N+1.



Yesterday there were 2*N + 1 paths:


N paths around the circle, each connecting one pair of cyclically adjacent sensors (i.e., one path connects sensors 0 and N-1 and each of the others connects sensors i and i+1 for some i)
for each sensor a path from the sensor to exactly one of the habitats
and finally, one path between the two habitats


Habitat N was connected to sensors with numbers between lo and hi, inclusive.
Habitat N+1 was connected to all other sensors.



Last night, a blizzard covered all paths with fresh snow.
The scientists at the station would like to be able to reach each other and all the sensors again.
Thus, they need to pick up shovels and clean some of the paths.
But, as you might expect, the scientists are not fond of manual labor and thus they are only willing to clean as few paths as possible (which is clearly always exactly N+1 paths).


Count the number of ways in which the scientists can shovel away the snow.
Two ways are different if the sets of cleaned paths differ.
Return the count modulo 10^9 + 7.


DEFINITION
Class:TwoPolarStations
Method:count
Parameters:int, int, int
Returns:int
Method signature:int count(int N, int lo, int hi)


NOTES
-You may only restore a subset of the original paths, you are not able to make new paths where there was no path before the snowfall.


CONSTRAINTS
-N will be between 3 and 10^9, inclusive.
-0 <= lo <= hi <= N-1.


EXAMPLES

0)
3
0
2

Returns: 16

Sensors have numbers 0, 1, 2, habitats have numbers 3 and 4.
As there is no other path from habitat 4, the scientists must clear the path between the two habitats. Then they have 16 options which three of the remaining paths they should clear.
For example, they may clear the three paths from habitat 3 to the sensors.
Another valid solution is to clear the paths 3-0, 0-1, and 0-2.
Yet another valid solution is to clear the paths 3-0, 0-1, and 1-2.
Cleaning the three paths between sensors does not work, as then you cannot get from the habitats to the sensors.
Cleaning the paths 3-0, 3-1, and 0-1 does not work, as there is no way to reach sensor 2 from anywhere.


1)
3
1
1

Returns: 24

Here habitat 3 was connected to sensor 1, while habitat 4 was connected to sensors 0 and 2.

2)
10
1
4

Returns: 28325



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
		cout << "Testing TwoPolarStations (800.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1621703040;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 800.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		TwoPolarStations _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 3;
				int lo = 0;
				int hi = 2;
				_expected = 16;
				_received = _obj.count(N, lo, hi); break;
			}
			case 1:
			{
				int N = 3;
				int lo = 1;
				int hi = 1;
				_expected = 24;
				_received = _obj.count(N, lo, hi); break;
			}
			case 2:
			{
				int N = 10;
				int lo = 1;
				int hi = 4;
				_expected = 28325;
				_received = _obj.count(N, lo, hi); break;
			}
			/*case 3:
			{
				int N = ;
				int lo = ;
				int hi = ;
				_expected = ;
				_received = _obj.count(N, lo, hi); break;
			}*/
			/*case 4:
			{
				int N = ;
				int lo = ;
				int hi = ;
				_expected = ;
				_received = _obj.count(N, lo, hi); break;
			}*/
			/*case 5:
			{
				int N = ;
				int lo = ;
				int hi = ;
				_expected = ;
				_received = _obj.count(N, lo, hi); break;
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
