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
#define MS0(x) memset(x,0,sizeof(x))
#define MAX(x, a) x = max(x, a)
#define MIN(x, a) x = min(x, a)
 
class Similars {
	public:

	int maxsim(int L, int R) {
		int ans = 0;
		REP1(a, L, R) {
			bool fa[10]; MS0(fa);
			int aa = a;
			while (aa) {
				fa[aa % 10] = true;
				aa /= 10;
			}
			REP1(b, max(L, a - 100), min(R, a + 100)) {
				if (b == a) continue;
				bool fb[10]; MS0(fb);
				int bb = b;
				while (bb) {
					fb[bb % 10] = true;
					bb /= 10;
				}
				int cnt = 0;
				REP(i, 10) {
					if (fa[i] && fb[i]) {
						cnt++;
					}
				}
				MAX(ans, cnt);
				// cout << a << ' ' << b << ' ' << ans << endl;
			}
		}	
		return ans;
	}
};
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Given two positive integers x and y, their similarity S(x, y) is defined as follows:
To compute S(x, y) we count all d between 0 and 9, inclusive, such that both x and y contain the digit d when written in base 10 (without any leading zeros).
For example, S(1123, 220181) = 2 since both numbers contain the digit 1 and both contain the digit 2.

You are given two ints L and R that define a range.
Find two distinct integers in this range that have the largest similarity.
Formally, return the maximum of S(a, b) over all a, b such that L <= a < b <= R.

DEFINITION
Class:Similars
Method:maxsim
Parameters:int, int
Returns:int
Method signature:int maxsim(int L, int R)


CONSTRAINTS
-R will be between 2 and 100,000, inclusive.
-L will be between 1 and R - 1, inclusive.


EXAMPLES

0)
1
10

Returns: 1

We have S(1, 10) = 1 since both numbers contain the digit 1. All other pairs of numbers within this range have similarity 0.

1)
1
99

Returns: 2

There are many pairs with similarity 2, for example pairs (23,32) and (38,83).

2)
99
100

Returns: 0

Here we have only one pair (99, 100) and its similarity is 0.

3)
1000
1010

Returns: 2



4)
444
454

Returns: 2



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
		cout << "Testing Similars (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1428768002;
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
		Similars _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int L = 1;
				int R = 10;
				_expected = 1;
				_received = _obj.maxsim(L, R); break;
			}
			case 1:
			{
				int L = 1;
				int R = 99;
				_expected = 2;
				_received = _obj.maxsim(L, R); break;
			}
			case 2:
			{
				int L = 99;
				int R = 100;
				_expected = 0;
				_received = _obj.maxsim(L, R); break;
			}
			case 3:
			{
				int L = 1000;
				int R = 1010;
				_expected = 2;
				_received = _obj.maxsim(L, R); break;
			}
			case 4:
			{
				int L = 444;
				int R = 454;
				_expected = 2;
				_received = _obj.maxsim(L, R); break;
			}
			/*case 5:
			{
				int L = ;
				int R = ;
				_expected = ;
				_received = _obj.maxsim(L, R); break;
			}*/
			/*case 6:
			{
				int L = ;
				int R = ;
				_expected = ;
				_received = _obj.maxsim(L, R); break;
			}*/
			/*case 7:
			{
				int L = ;
				int R = ;
				_expected = ;
				_received = _obj.maxsim(L, R); break;
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
