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
#define MS1(x) memset(x,-1,sizeof(x))
 
typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;

#line 40 "Deadfish.cpp"
#include <string>
#include <vector>

int dp[400004];

int f(int x) {
    char s[10];
    sprintf(s, "%d", x);
    sort(s, s + strlen(s), greater<char>());
    sscanf(s, "%d", &x);
    return x;
}

class Deadfish {
public:
    int shortestCode(int N) {
	queue<int> q;
	q.push(0);
	MS1(dp);
	dp[0] = 0;
	while (true) {
	    int x = q.front();
	    //cout << x << endl;
	    q.pop();
	    LL a[] = { x+1, x-1, 1ll*x*x, f(x) };
	    for (LL y : a) {
		if (y >= 0 && y <= N * 2 && dp[y] < 0) {
		    dp[y] = dp[x] + 1;
		    q.push(y);
		}
		if (y == N) {
		    return dp[y];
		}
	    }
	}
    }
};

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Deadfish+ is a programming language with only 4 commands. All commands modify a single register. The register is initially set to zero, and during the execution of a program it can store an arbitrarily large integer value. The commands are:

"i" - increment the value,

"d" - decrement the value,

"s" - square the value, and

"p" - sort the digits of the number into non-increasing order (i.e., biggest to smallest).



For example, "p" changes 4070 to 7400, and it changes -4070 to -7400 (the minus sign is preserved).



You are given an int N. Return the minimal number of commands necessary to make the register hold the number N.


DEFINITION
Class:Deadfish
Method:shortestCode
Parameters:int
Returns:int
Method signature:int shortestCode(int N)


CONSTRAINTS
-N will be between 1 and 200,000, inclusive.


EXAMPLES

0)
3

Returns: 3

The fastest way to get to 3 is "iii" - three increments.

1)
5

Returns: 4

One fastest way to get a 5 is "iisi": two increments to get a 2, square to get a 4 and one more increment.
Another optimal way is "ddsi": two decrements change the register to -2, squaring that gives 4, and the final increment changes it to 5.

2)
15

Returns: 5

The fastest way to get 15 is "iissd". The value in the register will change as follows: 0, 1, 2, 4, 16, 15.

3)
61

Returns: 5

The fastest way to get 61 is "iissp". The value in the register will change as follows: 0, 1, 2, 4, 16, 61.

4)
200000

Returns: 207



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
		cout << "Testing Deadfish (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1524327496;
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
		Deadfish _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 3;
				_expected = 3;
				_received = _obj.shortestCode(N); break;
			}
			case 1:
			{
				int N = 5;
				_expected = 4;
				_received = _obj.shortestCode(N); break;
			}
			case 2:
			{
				int N = 15;
				_expected = 5;
				_received = _obj.shortestCode(N); break;
			}
			case 3:
			{
				int N = 61;
				_expected = 5;
				_received = _obj.shortestCode(N); break;
			}
			case 4:
			{
				int N = 200000;
				_expected = 207;
				_received = _obj.shortestCode(N); break;
			}
			/*case 5:
			{
				int N = ;
				_expected = ;
				_received = _obj.shortestCode(N); break;
			}*/
			/*case 6:
			{
				int N = ;
				_expected = ;
				_received = _obj.shortestCode(N); break;
			}*/
			/*case 7:
			{
				int N = ;
				_expected = ;
				_received = _obj.shortestCode(N); break;
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
