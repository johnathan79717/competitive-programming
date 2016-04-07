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
#define FOR(i, c) for(auto &i: c)
#define REP(i,n) for(int i=0;i<(n);i++)

int gcd(int a, int b) {
	if(a == 0) return b;
	return gcd(b % a, a);
}

int lcm(int a, int b) {
	return a / gcd(a, b) * b;
}

struct WakingUp {
  int maxSleepiness(vector <int> period, vector <int> start, vector <int> volume, int D) {
  	int total = 1;
  	FOR(p, period) total = lcm(total, p);
  	// cout << total << endl;
  	int S = 0; int N = period.size(), m = INT_MAX;
  	for(int i = 1; i <= total; i++) {
  		S += D;
  		REP(j, N) {
  			if((i - start[j]) % period[j] == 0)
  				S -= volume[j];
  		}
  		// cout << S << endl;
  		m = min(m, S);
  	}
  	if(S < 0)
  		return -1;
  	else
  		return max(-m, 0);
  }
};

// BEGIN CUT HERE
/*
PROBLEM STATEMENT
Alex is sleeping soundly. At any minute T, his sleepiness 
can be characterized by an integer. Initially, at minute 
0, Alex's sleepiness is some unknown integer S.

Unfortunately, there are several repeatedly ringing alarms 
disturbing him.

Starting from minute 1, the following happens. First, 
Alex's sleepiness increases by D. Then some of the alarms 
ring, decreasing Alex's sleepiness.

Formally, alarms' characteristics are given in three 
vector <int>s period, start and volume. The i-th alarm 
rings at minutes start[i], start[i] + period[i], start[i] 
+ 2 * period[i], etc., and each time it rings, Alex's 
sleepiness instantly decreases by volume[i]. If several 
alarms ring at the same minute, their effects are added 
up, so each of them decreases Alex's sleepiness by its 
volume.

While Alex's sleepiness is positive, he's still sleeping. 
Once it becomes less than or equal to zero, Alex 
immediately wakes up. Note that Alex's initial sleepiness 
can be non-positive. In that case he just wakes up at 
minute 0.

You are given the vector <int>s period, start, volume, and 
the int D. Return the largest possible value of S (Alex's 
initial sleepiness) such that he will wake up at some 
moment. If he is guaranteed to wake up for all possible 
values of S, return -1 instead.


DEFINITION
Class:WakingUp
Method:maxSleepiness
Parameters:vector <int>, vector <int>, vector <int>, int
Returns:int
Method signature:int maxSleepiness(vector <int> period, 
vector <int> start, vector <int> volume, int D)


NOTES
-It is possible to prove that the answer for any test case 
fits into a 32-bit signed integer type.


CONSTRAINTS
-period will contain between 1 and 50 elements, inclusive.
-period, start and volume will contain the same number of 
elements.
-Each element of period will be between 1 and 10, inclusive.
-start[i] will be between 1 and period[i], inclusive.
-Each element of volume will be between 1 and 1000, 
inclusive.
-D will be between 1 and 100, inclusive.


EXAMPLES

0)
{2, 3}
{1, 2}
{3, 4}
3

Returns: 2

There are two alarms. The first alarm rings every 2 
minutes, starting from minute 1, and has volume 3. The 
second alarm rings every 3 minutes, starting from minute 
2, and has volume 4.

Here is what would happen for S = 2:


At minute 0, Alex's sleepiness is 2.
At minute 1, Alex's sleepiness increases to 5. Then the 
first alarm rings, decreasing his sleepiness to 2.
At minute 2, Alex's sleepiness increases to 5. Then the 
second alarm rings, decreasing his sleepiness to 1.
At minute 3, Alex's sleepiness increases to 4. Then the 
first alarm rings, decreasing his sleepiness to 1.
At minute 4, Alex's sleepiness increases to 4. No alarm 
rings at this minute.
At minute 5, Alex's sleepiness increases to 7. Then both 
alarms ring, decreasing his sleepiness to 0, so he wakes up.


It can be proven that for any larger S, Alex will never 
wake up.


1)
{1}
{1}
{17}
17

Returns: 0

For any positive S, Alex will never wake up. It's better 
not to fall asleep.

2)
{1}
{1}
{23}
17

Returns: -1

Each minute Alex's sleepiness decreases by 6. That means 
he will wake up at some moment, regardless of the initial 
sleepiness.

3)
{9, 2, 5, 5, 7}
{6, 1, 4, 1, 6}
{71, 66, 7, 34, 6}
50

Returns: 78



4)
{5, 6, 5, 3, 8, 3, 4}
{1, 1, 3, 2, 6, 3, 3}
{42, 85, 10, 86, 21, 78, 38}
88

Returns: -1



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
		cout << "Testing WakingUp (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1397142020;
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
		WakingUp _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int period[] = {2, 3};
				int start[] = {1, 2};
				int volume[] = {3, 4};
				int D = 3;
				_expected = 2;
				_received = _obj.maxSleepiness(vector <int>(period, period+sizeof(period)/sizeof(int)), vector <int>(start, start+sizeof(start)/sizeof(int)), vector <int>(volume, volume+sizeof(volume)/sizeof(int)), D); break;
			}
			case 1:
			{
				int period[] = {1};
				int start[] = {1};
				int volume[] = {17};
				int D = 17;
				_expected = 0;
				_received = _obj.maxSleepiness(vector <int>(period, period+sizeof(period)/sizeof(int)), vector <int>(start, start+sizeof(start)/sizeof(int)), vector <int>(volume, volume+sizeof(volume)/sizeof(int)), D); break;
			}
			case 2:
			{
				int period[] = {1};
				int start[] = {1};
				int volume[] = {23};
				int D = 17;
				_expected = -1;
				_received = _obj.maxSleepiness(vector <int>(period, period+sizeof(period)/sizeof(int)), vector <int>(start, start+sizeof(start)/sizeof(int)), vector <int>(volume, volume+sizeof(volume)/sizeof(int)), D); break;
			}
			case 3:
			{
				int period[] = {9, 2, 5, 5, 7};
				int start[] = {6, 1, 4, 1, 6};
				int volume[] = {71, 66, 7, 34, 6};
				int D = 50;
				_expected = 78;
				_received = _obj.maxSleepiness(vector <int>(period, period+sizeof(period)/sizeof(int)), vector <int>(start, start+sizeof(start)/sizeof(int)), vector <int>(volume, volume+sizeof(volume)/sizeof(int)), D); break;
			}
			case 4:
			{
				int period[] = {5, 6, 5, 3, 8, 3, 4};
				int start[] = {1, 1, 3, 2, 6, 3, 3};
				int volume[] = {42, 85, 10, 86, 21, 78, 38};
				int D = 88;
				_expected = -1;
				_received = _obj.maxSleepiness(vector <int>(period, period+sizeof(period)/sizeof(int)), vector <int>(start, start+sizeof(start)/sizeof(int)), vector <int>(volume, volume+sizeof(volume)/sizeof(int)), D); break;
			}
			/*case 5:
			{
				int period[] = ;
				int start[] = ;
				int volume[] = ;
				int D = ;
				_expected = ;
				_received = _obj.maxSleepiness(vector <int>(period, period+sizeof(period)/sizeof(int)), vector <int>(start, start+sizeof(start)/sizeof(int)), vector <int>(volume, volume+sizeof(volume)/sizeof(int)), D); break;
			}*/
			/*case 6:
			{
				int period[] = ;
				int start[] = ;
				int volume[] = ;
				int D = ;
				_expected = ;
				_received = _obj.maxSleepiness(vector <int>(period, period+sizeof(period)/sizeof(int)), vector <int>(start, start+sizeof(start)/sizeof(int)), vector <int>(volume, volume+sizeof(volume)/sizeof(int)), D); break;
			}*/
			/*case 7:
			{
				int period[] = ;
				int start[] = ;
				int volume[] = ;
				int D = ;
				_expected = ;
				_received = _obj.maxSleepiness(vector <int>(period, period+sizeof(period)/sizeof(int)), vector <int>(start, start+sizeof(start)/sizeof(int)), vector <int>(volume, volume+sizeof(volume)/sizeof(int)), D); break;
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
