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

#line 41 "CentipedeSocks.cpp"
#include <string>
#include <vector>
class CentipedeSocks {
public:
    int fewestSocks(int C, int F, vector <int> sockCounts) {

    }
};

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
You have C pet centipedes.
You want to take them out for a walk, but it's quite cold.
You want to give them socks to make them feel more comfortable.


Each of your centipedes has F feet.
You have a large bin with centipede socks.
The socks come in different colors, but your centipedes are quite picky and each of them requires to wear F socks of the same color.


You are given the ints C and F.
You are also given the vector <int> sockCounts.
Each element of sockCounts is the number of socks of one particular color you have in the bin.


Find and return the smallest X such that if you take any X socks out of the bin, it is guaranteed that you will be able to use some of them to keep all feet of all your centipedes warm.
If there is no such X, return -1 instead.


DEFINITION
Class:CentipedeSocks
Method:fewestSocks
Parameters:int, int, vector <int>
Returns:int
Method signature:int fewestSocks(int C, int F, vector <int> sockCounts)


CONSTRAINTS
-C will be between 1 and 50, inclusive.
-F will be between 1 and 100, inclusive.
-sockCounts will have between 1 and 100 elements, inclusive.
-Each element of sockCounts will be between 1 and 10^7, inclusive.


EXAMPLES

0)
1
100
{1, 1, 1, 1, 100}

Returns: 104

One centipede with 100 feet. If you are really unlucky, you need to remove all 104 socks from the bin until you get all 100 pink ones.

1)
1
100
{40, 50, 60, 70}

Returns: -1

You do not have 100 socks of any single color, so the poor centipede will be cold.

2)
3
10
{12345}

Returns: 30

There are 12345 red socks in the bin. You just grab the first 30 and put 10 of them onto each of your centipedes.

3)
2
3
{4, 4, 5}

Returns: 10

Two red, two blue, and five pink socks are still not enough to satisfy two three-legged centipedes.

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
		cout << "Testing CentipedeSocks (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1556662966;
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
		CentipedeSocks _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int C = 1;
				int F = 100;
				int sockCounts[] = {1, 1, 1, 1, 100};
				_expected = 104;
				_received = _obj.fewestSocks(C, F, vector <int>(sockCounts, sockCounts+sizeof(sockCounts)/sizeof(int))); break;
			}
			case 1:
			{
				int C = 1;
				int F = 100;
				int sockCounts[] = {40, 50, 60, 70};
				_expected = -1;
				_received = _obj.fewestSocks(C, F, vector <int>(sockCounts, sockCounts+sizeof(sockCounts)/sizeof(int))); break;
			}
			case 2:
			{
				int C = 3;
				int F = 10;
				int sockCounts[] = {12345};
				_expected = 30;
				_received = _obj.fewestSocks(C, F, vector <int>(sockCounts, sockCounts+sizeof(sockCounts)/sizeof(int))); break;
			}
			case 3:
			{
				int C = 2;
				int F = 3;
				int sockCounts[] = {4, 4, 5};
				_expected = 10;
				_received = _obj.fewestSocks(C, F, vector <int>(sockCounts, sockCounts+sizeof(sockCounts)/sizeof(int))); break;
			}
			/*case 4:
			{
				int C = ;
				int F = ;
				int sockCounts[] = ;
				_expected = ;
				_received = _obj.fewestSocks(C, F, vector <int>(sockCounts, sockCounts+sizeof(sockCounts)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int C = ;
				int F = ;
				int sockCounts[] = ;
				_expected = ;
				_received = _obj.fewestSocks(C, F, vector <int>(sockCounts, sockCounts+sizeof(sockCounts)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int C = ;
				int F = ;
				int sockCounts[] = ;
				_expected = ;
				_received = _obj.fewestSocks(C, F, vector <int>(sockCounts, sockCounts+sizeof(sockCounts)/sizeof(int))); break;
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
