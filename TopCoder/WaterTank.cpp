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

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;
#line 39 "WaterTank.cpp"
#include <string>
#include <vector>
class WaterTank {
public:
    double minOutputRate(vector <int> t, vector <int> x, int C) {
        double lb = 0, ub = 1e18;
        int N = t.size();
        auto ok = [&](double r) {
            double w = 0;
            REP(i, N) {
                w += t[i] * (x[i] - r);
                if (w < 0) w = 0;
                if (w > C) return false;
            }
            return true;
        };
    	REP(i, 10000) {
            double m = (ub + lb) / 2;
            if (ok(m)) {
                ub = m;
            } else {
                lb = m;
            }
        }
        return ub;
    }
};
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
You are given the int C and the vector <int>s x and t.
You have a water tank with capacity C liters.
The tank is initially empty.



At time 0 water will start flowing into the tank through an input pipe.
This process will consist of n consecutive intervals, numbered 0 to n-1 in order.
Interval i lasts for t[i] seconds.
During each second of interval i exactly x[i] liters of water will enter the tank.



The tank also has an output pipe.
The water will always leave the tank through the output pipe as quickly as it can.
The output pipe has a valve.
You can use the valve to set the output pipe to any maximum output rate R (in liters per second).
This maximum output rate must remain constant during the entire process.
The rate must be nonnegative but it doesn't have to be an integer.



Determine and return the smallest output rate limit R such that the amount of water in the tank will never exceed C liters.


DEFINITION
Class:WaterTank
Method:minOutputRate
Parameters:vector <int>, vector <int>, int
Returns:double
Method signature:double minOutputRate(vector <int> t, vector <int> x, int C)


NOTES
-Your return value must have an absolute or relative error smaller than 1e-6.


CONSTRAINTS
-n will be between 1 and 50, inclusive.
-t,x will have exactly n elements.
-Each element of t will be between 1 and 1,000,000, inclusive.
-Each element of x will be between 1 and 1,000,000, inclusive.
-C will be between 1 and 10^9, inclusive.


EXAMPLES

0)
{3,3}
{1,2}
3

Returns: 0.9999999999999999

In this case, we have two time intervals, the first one lasts 3 seconds and water flows at 1 liter per second. The second one lasts 3 seconds and water flows in at 2 liters per second.

The answer in this case is 1. During the first interval, water flows in and out at the same rate, while in the second interval, water flows in at a net rate of 1 liter per second. Any lower output rate would cause the tank to overflow 3 liters.

1)
{1,2,3,4,5}
{5,4,3,2,1}
10

Returns: 1.9999999999999996



2)
{5949,3198,376,3592,4019,3481,5609,3840,6092,4059}
{29,38,96,84,10,2,39,27,76,94}
1000000000

Returns: 0.0



3)
{9,3,4,8,1,2,5,7,6}
{123,456,789,1011,1213,1415,1617,1819,2021}
11

Returns: 2019.1666666666665



4)
{100}
{1000}
12345

Returns: 876.55



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
		cout << "Testing WaterTank (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1450454439;
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
		WaterTank _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int t[] = {3,3};
				int x[] = {1,2};
				int C = 3;
				_expected = 0.9999999999999999;
				_received = _obj.minOutputRate(vector <int>(t, t+sizeof(t)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int)), C); break;
			}
			case 1:
			{
				int t[] = {1,2,3,4,5};
				int x[] = {5,4,3,2,1};
				int C = 10;
				_expected = 1.9999999999999996;
				_received = _obj.minOutputRate(vector <int>(t, t+sizeof(t)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int)), C); break;
			}
			case 2:
			{
				int t[] = {5949,3198,376,3592,4019,3481,5609,3840,6092,4059};
				int x[] = {29,38,96,84,10,2,39,27,76,94};
				int C = 1000000000;
				_expected = 0.0;
				_received = _obj.minOutputRate(vector <int>(t, t+sizeof(t)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int)), C); break;
			}
			case 3:
			{
				int t[] = {9,3,4,8,1,2,5,7,6};
				int x[] = {123,456,789,1011,1213,1415,1617,1819,2021};
				int C = 11;
				_expected = 2019.1666666666665;
				_received = _obj.minOutputRate(vector <int>(t, t+sizeof(t)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int)), C); break;
			}
			case 4:
			{
				int t[] = {100};
				int x[] = {1000};
				int C = 12345;
				_expected = 876.55;
				_received = _obj.minOutputRate(vector <int>(t, t+sizeof(t)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int)), C); break;
			}
			/*case 5:
			{
				int t[] = ;
				int x[] = ;
				int C = ;
				_expected = ;
				_received = _obj.minOutputRate(vector <int>(t, t+sizeof(t)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int)), C); break;
			}*/
			/*case 6:
			{
				int t[] = ;
				int x[] = ;
				int C = ;
				_expected = ;
				_received = _obj.minOutputRate(vector <int>(t, t+sizeof(t)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int)), C); break;
			}*/
			/*case 7:
			{
				int t[] = ;
				int x[] = ;
				int C = ;
				_expected = ;
				_received = _obj.minOutputRate(vector <int>(t, t+sizeof(t)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int)), C); break;
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
