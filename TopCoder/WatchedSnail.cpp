#line 2 "WatchedSnail.cpp"
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

class WatchedSnail {
public:
    double maxDistance(int raceTime, int observerCount, int observationTime, int observationDistance) {
	if (raceTime == observationTime) {
	    return observationDistance;
	}
	int n = raceTime / observationTime;
	if (raceTime % observationTime == 0) n--;
	return 1.0 * observationDistance * min(observerCount, n * 2);
    }
};

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
A snail was racing along a straight trail for raceTime seconds.
The snail maintained the same direction during the entire race.
On the other hand, its speed during the race was not necessarily constant.



The race had observerCount observers.
Each of them watched the snail during a single contiguous closed interval that measured exactly observationTime seconds.


(No observation started before the start of the race. No observation ended after the end of the race. Some observers could have started and therefore also ended their observation at a non-integer timestamp.)


It is guaranteed that during the entire race the snail was always observed by at least one person.
Each observer came to the same conclusion: the distance traveled by the snail during their observation was exactly observationDistance inches.



Return the maximum distance in inches the snail could have traveled during the entire race.


DEFINITION
Class:WatchedSnail
Method:maxDistance
Parameters:int, int, int, int
Returns:double
Method signature:double maxDistance(int raceTime, int observerCount, int observationTime, int observationDistance)


NOTES
-Your return value will be accepted if it has an absolute or a relative error at most 10^(-9).
-The snail cannot teleport (move at infinite speed). Its position in time is a continuous non-decreasing function. 
-As implied by the "non-decreasing" in the previous sentence, the snail may stand still during some intervals of time.


CONSTRAINTS
-raceTime will be between 1 and 1000, inclusive.
-observerCount will be between 1 and 1000, inclusive.
-observationTime will be between 1 and raceTime, inclusive.
-observationDistance will be between 1 and 1000, inclusive.
-observerCount * observationTime will be greater than or equal to raceTime.


EXAMPLES

0)
100
3
100
47

Returns: 47.0

Each person observed the snail during the entire race and saw the snail traverse 47 inches.

1)
100
10
10
47

Returns: 470.0

Ten people took turns watching the snail. Each person saw the snail traverse 47 inches, so the snail traversed 470 inches total. Boring.

2)
100
8
20
47

Returns: 376.0


This should be obvious, right?


Each observation took 20 seconds. The distance traveled during each observation is 47 inches, so for each observation the snail had an average speed of 2.35 inches per second.


The whole race was 100 seconds and at that average speed the snail must have travelled 2.35 * 100 = 235 inches.


The snail was always watched, so it could not have... wait, what?



3)
100
2
74
47

Returns: 94.0


One observer started at the beginning of the race and one ended at the end of the race. 
If [0,100] is the time interval of the race, the first observer was active during [0,74] and the second one during [26,100].


It is possible that the snail traversed only 47 inches total, but it is also possible that it traversed more.
The largest possible total distance it could have travelled is obviously 94 inches.


The answer would clearly remain 94 inches even if we had more than two observers (while keeping the other three parameters the same).


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
		cout << "Testing WatchedSnail (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1627142745;
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
		WatchedSnail _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int raceTime = 100;
				int observerCount = 3;
				int observationTime = 100;
				int observationDistance = 47;
				_expected = 47.0;
				_received = _obj.maxDistance(raceTime, observerCount, observationTime, observationDistance); break;
			}
			case 1:
			{
				int raceTime = 100;
				int observerCount = 10;
				int observationTime = 10;
				int observationDistance = 47;
				_expected = 470.0;
				_received = _obj.maxDistance(raceTime, observerCount, observationTime, observationDistance); break;
			}
			case 2:
			{
				int raceTime = 100;
				int observerCount = 8;
				int observationTime = 20;
				int observationDistance = 47;
				_expected = 376.0;
				_received = _obj.maxDistance(raceTime, observerCount, observationTime, observationDistance); break;
			}
			case 3:
			{
				int raceTime = 100;
				int observerCount = 2;
				int observationTime = 74;
				int observationDistance = 47;
				_expected = 94.0;
				_received = _obj.maxDistance(raceTime, observerCount, observationTime, observationDistance); break;
			}
			/*case 4:
			{
				int raceTime = ;
				int observerCount = ;
				int observationTime = ;
				int observationDistance = ;
				_expected = ;
				_received = _obj.maxDistance(raceTime, observerCount, observationTime, observationDistance); break;
			}*/
			/*case 5:
			{
				int raceTime = ;
				int observerCount = ;
				int observationTime = ;
				int observationDistance = ;
				_expected = ;
				_received = _obj.maxDistance(raceTime, observerCount, observationTime, observationDistance); break;
			}*/
			/*case 6:
			{
				int raceTime = ;
				int observerCount = ;
				int observationTime = ;
				int observationDistance = ;
				_expected = ;
				_received = _obj.maxDistance(raceTime, observerCount, observationTime, observationDistance); break;
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
