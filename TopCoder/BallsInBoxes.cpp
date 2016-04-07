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

class BallsInBoxes {
	public:
	long long maxTurns(long long N, long long K) {
		long long ans = max(0ll, (N - K*3 + 1) / 3 - 1);
                N -= ans * K;
                while (K < N) {
                    LL x = min(K, (N + 1 - K) / 2);
                    N = max(N - x, x + K - 1);
                    ans++;
                }
                return ans;
	}
};
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// There are N boxes arranged in a row. The boxes are numbered 0 through N-1 from left to right.


Cat Snuke knows that exactly K consecutive boxes contain balls. Formally, there exists some i (0 <= i <= N-K)
such that the boxes i, i+1, ..., i+K-1 contain balls while all others are empty.


He wants to determine which boxes contain balls. In each turn, he can choose a box, open it and check whether the box contains a ball or not. Note that the result of each turn may affect his future decisions about which boxes to open in the next turns.


How many turns are required to determine the positions of the balls in the worst case, assuming that Snuke uses the optimal strategy?


DEFINITION
Class:BallsInBoxes
Method:maxTurns
Parameters:long long, long long
Returns:long long
Method signature:long long maxTurns(long long N, long long K)


CONSTRAINTS
-N will be between 1 and 10^18, inclusive.
-K will be between 1 and N, inculsive.


EXAMPLES

0)
10
10

Returns: 0

Snuke knows that all boxes contain balls, so he doesn't need to open any boxes.

1)
100
1

Returns: 99

In the worst case, if he opens 98 boxes and none of them contains the only ball, he can't determine which box contains the ball.

2)
1000
999

Returns: 1

There are two possibilities:

Boxes 0, 1, ..., 998 contain balls.
Boxes 1, 2, ..., 999 contain balls.

He can determine the positions of the balls if he opens box 0.


3)
10
5

Returns: 3



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
		cout << "Testing BallsInBoxes (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1440225697;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 500.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		BallsInBoxes _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				long long N = 10LL;
				long long K = 10LL;
				_expected = 0LL;
				_received = _obj.maxTurns(N, K); break;
			}
			case 1:
			{
				long long N = 100LL;
				long long K = 1LL;
				_expected = 99LL;
				_received = _obj.maxTurns(N, K); break;
			}
			case 2:
			{
				long long N = 1000LL;
				long long K = 999LL;
				_expected = 1LL;
				_received = _obj.maxTurns(N, K); break;
			}
			case 3:
			{
				long long N = 10LL;
				long long K = 5LL;
				_expected = 3LL;
				_received = _obj.maxTurns(N, K); break;
			}
			/*case 4:
			{
				long long N = LL;
				long long K = LL;
				_expected = LL;
				_received = _obj.maxTurns(N, K); break;
			}*/
			/*case 5:
			{
				long long N = LL;
				long long K = LL;
				_expected = LL;
				_received = _obj.maxTurns(N, K); break;
			}*/
			/*case 6:
			{
				long long N = LL;
				long long K = LL;
				_expected = LL;
				_received = _obj.maxTurns(N, K); break;
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
