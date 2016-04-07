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
 
typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;

class AliceGame {
	public:
	long long findMinimumValue(long long x, long long y) {
		if (x + y == 0) return 0;
		long long n = sqrt(x + y);
		while ((n-1) * (n-1) >= x + y) n--;
		while ((n+1) * (n+1) <= x + y) n++;
		if (n * n != x + y) return -1;
		int ans = 0;
		while (x > 0 && n > 0) {
			if (x >= n * 2 - 1) {
				x -= n * 2 - 1;
				ans++;
				if (x == 2) {
					if (n * 2 - 1 >= 7) {
						return ans + 2;
					} else {
						return -1;
					}
				}
			} else {

			}
			n -= 2;
		}
		if (x == 0) return ans;
		else if (x == 1) return 
		else return -1;
	}
};
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
Alice and Kirito just played a game.
The game consisted of a finite (possibly empty) sequence of turns.
You do not know the exact number of turns.
The turns were numbered starting from 1.
In each turn, exactly one of our two players won.
The winner of turn i scored 2*i-1 points.



You are given two long longs x and y.
Find out whether it is possible that at the end of the game Alice had exactly x points and Kirito had exactly y points.
If it is possible, return the smallest number of turns Alice could have won.
If the given final result is not possible, return -1 instead.


DEFINITION
Class:AliceGame
Method:findMinimumValue
Parameters:long long, long long
Returns:long long
Method signature:long long findMinimumValue(long long x, long long y)


CONSTRAINTS
-x and y are between 0 and 1,000,000,000,000, inclusive.


EXAMPLES

0)
8
17

Returns: 2

This final result is possible.
Alice must have won at least two turns.
One possibility is that Alice won turns 2 and 3 (for 3+5 = 8 points) and Kirito won turns 1, 4, and 5 (for 1+7+9 = 17 points).

1)
17
8

Returns: 3



2)
0
0

Returns: 0



3)
9
9

Returns: -1



4)
500000
500000

Returns: 294



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
		cout << "Testing AliceGame (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1417176005;
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
		AliceGame _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				long long x = 8LL;
				long long y = 17LL;
				_expected = 2LL;
				_received = _obj.findMinimumValue(x, y); break;
			}
			case 1:
			{
				long long x = 17LL;
				long long y = 8LL;
				_expected = 3LL;
				_received = _obj.findMinimumValue(x, y); break;
			}
			case 2:
			{
				long long x = 0LL;
				long long y = 0LL;
				_expected = 0LL;
				_received = _obj.findMinimumValue(x, y); break;
			}
			case 3:
			{
				long long x = 9LL;
				long long y = 9LL;
				_expected = -1LL;
				_received = _obj.findMinimumValue(x, y); break;
			}
			case 4:
			{
				long long x = 500000LL;
				long long y = 500000LL;
				_expected = 294LL;
				_received = _obj.findMinimumValue(x, y); break;
			}
			/*case 5:
			{
				long long x = LL;
				long long y = LL;
				_expected = LL;
				_received = _obj.findMinimumValue(x, y); break;
			}*/
			/*case 6:
			{
				long long x = LL;
				long long y = LL;
				_expected = LL;
				_received = _obj.findMinimumValue(x, y); break;
			}*/
			/*case 7:
			{
				long long x = LL;
				long long y = LL;
				_expected = LL;
				_received = _obj.findMinimumValue(x, y); break;
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
