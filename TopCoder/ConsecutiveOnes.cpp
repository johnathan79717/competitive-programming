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

#line 40 "ConsecutiveOnes.cpp"
#include <string>
#include <vector>
class ConsecutiveOnes {
	public:
	long long get(long long n, int k) {
		
	}
};
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// You are given a long long n.
You are also given an int k that is a positive integer between 1 and 50, inclusive.

Find and return the smallest m such that:

m is greater than or equal to n
the binary representation of m contains (at least) k consecutive ones


DEFINITION
Class:ConsecutiveOnes
Method:get
Parameters:long long, int
Returns:long long
Method signature:long long get(long long n, int k)


CONSTRAINTS
-n will be beween 0 and 2^50 - 1, inclusive.  
-k will be between 1 and 50, inclusive.  


EXAMPLES

0)
1
2

Returns: 3

We want the smallest integer that is at least 1 and contains 2 consecutive ones in binary. Clearly the smallest such integer is 3.

1)
5
2

Returns: 6

The binary representation of the number 5 is 101, which does not contain two consecutive ones.
The next integer is 6, which is 110 in binary. As this does contain two consecutive ones, the correct return value is 6.

2)
7
2

Returns: 7



3)
364269800189924
33

Returns: 364273356242943



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
		cout << "Testing ConsecutiveOnes (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1490950930;
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
		ConsecutiveOnes _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				long long n = 1LL;
				int k = 2;
				_expected = 3LL;
				_received = _obj.get(n, k); break;
			}
			case 1:
			{
				long long n = 5LL;
				int k = 2;
				_expected = 6LL;
				_received = _obj.get(n, k); break;
			}
			case 2:
			{
				long long n = 7LL;
				int k = 2;
				_expected = 7LL;
				_received = _obj.get(n, k); break;
			}
			case 3:
			{
				long long n = 364269800189924LL;
				int k = 33;
				_expected = 364273356242943LL;
				_received = _obj.get(n, k); break;
			}
			/*case 4:
			{
				long long n = LL;
				int k = ;
				_expected = LL;
				_received = _obj.get(n, k); break;
			}*/
			/*case 5:
			{
				long long n = LL;
				int k = ;
				_expected = LL;
				_received = _obj.get(n, k); break;
			}*/
			/*case 6:
			{
				long long n = LL;
				int k = ;
				_expected = LL;
				_received = _obj.get(n, k); break;
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
