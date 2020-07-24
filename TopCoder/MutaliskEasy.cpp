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

#line 41 "MutaliskEasy.cpp"
#include <string>
#include <vector>
class MutaliskEasy {
public:
    int minimalAttacks(vector <int> x) {

    }
};

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Fox Ciel is writing an AI for the game Starcraft and she needs your help.


In Starcraft, one of the available units is a mutalisk.
Mutalisks are very useful for harassing Terran bases.
Fox Ciel has one mutalisk.
The enemy base contains one or more Space Construction Vehicles (SCVs).
Each SCV has some amount of hit points.


When the mutalisk attacks, it can target up to three different SCVs.

The first targeted SCV will lose 9 hit points.
The second targeted SCV (if any) will lose 3 hit points.
The third targeted SCV (if any) will lose 1 hit point.

If the hit points of a SCV drop to 0 or lower, the SCV is destroyed.
Note that you may not target the same SCV twice in the same attack.


You are given a vector <int> HP containing the current hit points of your enemy's SCVs.
Return the smallest number of attacks in which you can destroy all these SCVs.

DEFINITION
Class:MutaliskEasy
Method:minimalAttacks
Parameters:vector <int>
Returns:int
Method signature:int minimalAttacks(vector <int> x)


CONSTRAINTS
-x will contain between 1 and 3 elements, inclusive.
-Each element in x will be between 1 and 60, inclusive.


EXAMPLES

0)
{12,10,4}

Returns: 2

You can destroy all SCVs in two attacks as follows:

Target the SCVs in the order 0, 2, 1. Their hit points after the attack will be {12-9, 10-1, 4-3} = {3, 9, 1}.
Target the SCVs in the order 1, 0, 2. Their hit points will drop exactly to {0, 0, 0}.


1)
{54,18,6}

Returns: 6

You should attack 6 times, always in the order 0, 1, 2.

2)
{55,60,53}

Returns: 13



3)
{1,1,1}

Returns: 1



4)
{60, 40}

Returns: 9



5)
{60}

Returns: 7



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
		cout << "Testing MutaliskEasy (200.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1592746078;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 200.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		MutaliskEasy _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int x[] = {12,10,4};
				_expected = 2;
				_received = _obj.minimalAttacks(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}
			case 1:
			{
				int x[] = {54,18,6};
				_expected = 6;
				_received = _obj.minimalAttacks(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}
			case 2:
			{
				int x[] = {55,60,53};
				_expected = 13;
				_received = _obj.minimalAttacks(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}
			case 3:
			{
				int x[] = {1,1,1};
				_expected = 1;
				_received = _obj.minimalAttacks(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}
			case 4:
			{
				int x[] = {60, 40};
				_expected = 9;
				_received = _obj.minimalAttacks(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}
			case 5:
			{
				int x[] = {60};
				_expected = 7;
				_received = _obj.minimalAttacks(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}
			/*case 6:
			{
				int x[] = ;
				_expected = ;
				_received = _obj.minimalAttacks(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int x[] = ;
				_expected = ;
				_received = _obj.minimalAttacks(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int x[] = ;
				_expected = ;
				_received = _obj.minimalAttacks(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
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
