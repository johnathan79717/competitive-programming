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
#define PER(i,n) for(int i=(n)-1;i>=0;i--)
#define PB push_back
 
typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;

#line 41 "EllysTeleport.cpp"
#include <string>
#include <vector>
class EllysTeleport {
public:
    int getMax(int N, int H1, int A, int B, int P, int Q, int M) {
	VI h(N);
	h[0] = H1;
	REP1(i, 1, N-1) {
	    h[i] = (1ll * h[i-1] * A + B) % M;
	}
	sort(ALL(h));
	VI score(N);
	auto advance = [&h, Q, P, M](int i) {
	    int l = (1ll * h[i] * P + Q) % M;
	    return upper_bound(ALL(h), l) - h.begin() - 1;
	};
	REP(i, N) {
	    if (score[i]) continue;
	    VI visited;
	    unordered_map<int,int> index;
	    int c = 0;
	    int j = i;
	    while (j >= 0 && !score[j] && !index.count(j)) {
		visited.PB(j);
		index[j] = c++;
		j = advance(j);
	    }
	    int V = visited.size();
	    if (j < 0 || score[j]) {
		int s = j < 0 ? 0 : score[j];
		PER(k, V) {
		    score[visited[k]] = V - k + s;
		}
	    } else {
		int d = index[j];
		REP1(k, d, V-1) {
		    score[visited[k]] = V - d;
		}
		REP(k, d) {
		    score[visited[k]] = V - k;
		}
	    }
	}
	int ans = 0;
	REP(i, N) {
	    ans = max(ans, score[i]);
	}
	return ans;
    }
};

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
Elly plays a platform game on her computer.
There are N platforms with distinct heights, placed on top of each other.
You can generate the heights of the platforms as follows:


Platform number 1 is has height[1] = H1.
For each i between 2 and N, inclusive, height[i] = (height[i-1] * A + B) % M.


The girl has a "hero" whom she can move from platform to platform.
At the beginning of the game there is a coin on each platform.
The hero collects the coin the first time she visits the platform.
(Once a coin is collected, it is gone. Visiting the same platform again does not give Elly a second coin.)


In the beginning of the game Elly can place her hero on any of the N platforms.
Once she does that, the hero will pick up the coin from that platform and then the game starts.


During the game Elly only has one way to move her hero: by using a device that teleports the hero vertically.
The device is deterministic and it behaves as follows:
if the hero's current platform is at height X, the hero gets teleported to the height Y = (X * P + Q) % M.
After the teleport, one of three different things will happen:


If there is a platform at height Y, the hero will stand on that platform and collect the coin from that platform (if it is still there).
If there is no platform at height Y but there are some lower platforms, the hero falls down until she hits the closest platform. She will always lands safely, regardless of the height of the fall. Then, she will collect the coin from that platform (if it is still there).
If there are no platforms at or below the hero's new height, the game ends.


Elly can use the device arbitrarily many times, one after another.
Note that the device can only be used while the hero is standing on a platform (i.e., not while she is falling).


You are given all the ints mentioned in the problem statement.
Compute and return the largest number of coins Elly's hero can collect during a single game.


DEFINITION
Class:EllysTeleport
Method:getMax
Parameters:int, int, int, int, int, int, int
Returns:int
Method signature:int getMax(int N, int H1, int A, int B, int P, int Q, int M)


CONSTRAINTS
-N will be between 1 and 10,000, inclusive.
-M will be between 1 and 1,000,000,007, inclusive.
-H1, A, B, P and Q will be between 0 and M-1, inclusive.
-All platform heights will be distinct.


EXAMPLES

0)
11
9
17
9
7
13
23

Returns: 6

The generated heights are {9, 1, 3, 14, 17, 22, 15, 11, 12, 6, 19}. The optimal choice would be to start from the platform with height 15. The heights Elly's hero will visit are: 15 -> 3 -> 11 -> [21] -> 19 -> [8] -> 6 -> 9 -> [7] -> 6... With [Y] we have denoted a height where the hero is teleported to, but there is no platform so she starts falling down.

1)
8
17
23
19
15
28
43

Returns: 4

The generated numbers are {17, 23, 32, 24, 12, 37, 10, 34}. There are two possible choices for a starting platform, which yields the maximal number of coins: 32 or 12 (the paths being, respectively, 32 -> [35] -> 34 -> [22] -> 17 -> [25] -> 24 -> [1] -> game ends, and 12 -> [36] -> 34 -> [22] -> 17 -> [25] -> 24 -> [1] -> game ends).

2)
15
42
114
52
76
1
131

Returns: 5

The generated numbers are {42, 124, 40, 27, 117, 28, 100, 55, 34, 129, 86, 31, 49, 5, 98}.

3)
10
71
54
85
96
52
100

Returns: 10

Here the heights are {71, 19, 11, 79, 51, 39, 91, 99, 31, 59}. Starting from the platform with height 99 Elly's hero can collect all of the coins: 99 -> [56] -> 51 -> [49] -> 39 -> [96] -> 91 -> [88] -> 79 -> [36] -> 31 -> [28] -> 19 -> [76] -> 71 -> [68] -> 59 -> [16] -> 11 -> [8] -> game ends

4)
1000
1337
706135
1085680
1153206
345473
1234567

Returns: 42

Watch out for overflows when generating the heights!

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
		cout << "Testing EllysTeleport (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1556708906;
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
		EllysTeleport _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 11;
				int H1 = 9;
				int A = 17;
				int B = 9;
				int P = 7;
				int Q = 13;
				int M = 23;
				_expected = 6;
				_received = _obj.getMax(N, H1, A, B, P, Q, M); break;
			}
			case 1:
			{
				int N = 8;
				int H1 = 17;
				int A = 23;
				int B = 19;
				int P = 15;
				int Q = 28;
				int M = 43;
				_expected = 4;
				_received = _obj.getMax(N, H1, A, B, P, Q, M); break;
			}
			case 2:
			{
				int N = 15;
				int H1 = 42;
				int A = 114;
				int B = 52;
				int P = 76;
				int Q = 1;
				int M = 131;
				_expected = 5;
				_received = _obj.getMax(N, H1, A, B, P, Q, M); break;
			}
			case 3:
			{
				int N = 10;
				int H1 = 71;
				int A = 54;
				int B = 85;
				int P = 96;
				int Q = 52;
				int M = 100;
				_expected = 10;
				_received = _obj.getMax(N, H1, A, B, P, Q, M); break;
			}
			case 4:
			{
				int N = 1000;
				int H1 = 1337;
				int A = 706135;
				int B = 1085680;
				int P = 1153206;
				int Q = 345473;
				int M = 1234567;
				_expected = 42;
				_received = _obj.getMax(N, H1, A, B, P, Q, M); break;
			}
			/*case 5:
			{
				int N = ;
				int H1 = ;
				int A = ;
				int B = ;
				int P = ;
				int Q = ;
				int M = ;
				_expected = ;
				_received = _obj.getMax(N, H1, A, B, P, Q, M); break;
			}*/
			/*case 6:
			{
				int N = ;
				int H1 = ;
				int A = ;
				int B = ;
				int P = ;
				int Q = ;
				int M = ;
				_expected = ;
				_received = _obj.getMax(N, H1, A, B, P, Q, M); break;
			}*/
			/*case 7:
			{
				int N = ;
				int H1 = ;
				int A = ;
				int B = ;
				int P = ;
				int Q = ;
				int M = ;
				_expected = ;
				_received = _obj.getMax(N, H1, A, B, P, Q, M); break;
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
