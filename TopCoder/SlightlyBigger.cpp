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

#line 41 "SlightlyBigger.cpp"
#include <string>
#include <vector>
class SlightlyBigger {
public:
    double getProbability(int maxDiff, int ifNear, int ifFar, int query) {

    }
};

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
Yvonne and Zara are playing a game again.
In this game their simultaneously choose a positive integer.
(The chosen numbers can be arbitrarily large.)
The goal of the game is to choose a number that is slightly larger than your opponent's number.
More precisely:


If the numbers are equal, the game is a draw and there is no payment.
If the bigger number minus the smaller number is at most maxDiff, the person with the bigger number wins and gets ifNear dollars from the loser.
If the difference is larger, the person with the bigger number loses and pays ifFar dollars to the winner. The ifFar payoff is at least as big as the ifNear payoff.


You are given the values mentioned above and an int query.
Consider the optimal strategy for the above game.
If there are multiple strategies, pick the lexicographically largest one. (I.e., one that maximizes the probability of choosing 1, then the probability of choosing 2, and so on.)
Return the probability with which Yvonne should choose the integer query.


DEFINITION
Class:SlightlyBigger
Method:getProbability
Parameters:int, int, int, int
Returns:double
Method signature:double getProbability(int maxDiff, int ifNear, int ifFar, int query)


NOTES
-Your return value will be accepted if it has an absolute or a relative error at most 1e-9.
-The constraint "ifFar <= 2*ifNear" has no significance in terms of the solution idea, it was just added to (hopefully) avoid precision issues with numbers getting too close to zero.


CONSTRAINTS
-maxDiff will be between 1 and 25, inclusive.
-ifNear will be between 1 and 50, inclusive.
-ifFar will be between ifNear and 2*ifNear, inclusive.
-query will be between 1 and 1000, inclusive.


EXAMPLES

0)
1
1
1
1

Returns: 0.3333333333333334

If your number is exactly one bigger than your opponent's, you win $1. If your number is bigger than that, you lose $1.

In this setting, Yvonne should choose the integer 1 with probability 1/3.

1)
1
1
1
470

Returns: 0.0

In the same setting as before, the probability with which Yvonne should choose the integer 470 is either zero or negligibly small.

2)
1
1
2
1

Returns: 0.25

In the new setting you pay $2 if you exceed your opponent's number by more than 1 (and, symmetrically, you get paid $2 when your opponent's number exceeds yours by two or more).
Perhaps surprisingly, in the new setting the optimal probability for the choice of the smallest possible integer is lower than before.

3)
3
4
7
3

Returns: 0.08005718370264478



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
		cout << "Testing SlightlyBigger (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1559662120;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 1000.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		SlightlyBigger _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int maxDiff = 1;
				int ifNear = 1;
				int ifFar = 1;
				int query = 1;
				_expected = 0.3333333333333334;
				_received = _obj.getProbability(maxDiff, ifNear, ifFar, query); break;
			}
			case 1:
			{
				int maxDiff = 1;
				int ifNear = 1;
				int ifFar = 1;
				int query = 470;
				_expected = 0.0;
				_received = _obj.getProbability(maxDiff, ifNear, ifFar, query); break;
			}
			case 2:
			{
				int maxDiff = 1;
				int ifNear = 1;
				int ifFar = 2;
				int query = 1;
				_expected = 0.25;
				_received = _obj.getProbability(maxDiff, ifNear, ifFar, query); break;
			}
			case 3:
			{
				int maxDiff = 3;
				int ifNear = 4;
				int ifFar = 7;
				int query = 3;
				_expected = 0.08005718370264478;
				_received = _obj.getProbability(maxDiff, ifNear, ifFar, query); break;
			}
			/*case 4:
			{
				int maxDiff = ;
				int ifNear = ;
				int ifFar = ;
				int query = ;
				_expected = ;
				_received = _obj.getProbability(maxDiff, ifNear, ifFar, query); break;
			}*/
			/*case 5:
			{
				int maxDiff = ;
				int ifNear = ;
				int ifFar = ;
				int query = ;
				_expected = ;
				_received = _obj.getProbability(maxDiff, ifNear, ifFar, query); break;
			}*/
			/*case 6:
			{
				int maxDiff = ;
				int ifNear = ;
				int ifFar = ;
				int query = ;
				_expected = ;
				_received = _obj.getProbability(maxDiff, ifNear, ifFar, query); break;
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
