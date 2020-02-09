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
 
typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;

#line 41 "DivisorSequences.cpp"
#include <string>
#include <vector>

unordered_map<int,int> dp;

class DivisorSequences {
public:
    int longest(int N) {
	if (N <= 2) {
	    return 1;
	}
	int ans = 1;
	for (int p = 1; p * p <= N; p++) {
	    if (N % p == 0) {
		ans = max(ans,longest1(p));
		ans = max(ans,longest1(N / p));
	    }
	}
	return ans;
    }
    int longest1(int N) {
	if (N <= 2) {
	    return 1;
	}
	auto it = dp.find(N);
	if (it != dp.end()) return it->second;
	int ans = 2;
	for (int p = 2; p * p <= N-1; p++) {
	    if ((N-1) % p == 0) {
		ans = max(ans, 1 + longest1(p));
		ans = max(ans, 1 + longest1((N-1) / p));
	    }
	}
	return dp[N] = ans;
    }
};

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Given a positive integer N, find and return the length of the longest sequence a_1, ..., a_K of positive integers such that:

The sum of all a_i is N.
For each valid i, a_i < a_{i+1}.
For each valid i, a_i divides a_{i+1}.


DEFINITION
Class:DivisorSequences
Method:longest
Parameters:int
Returns:int
Method signature:int longest(int N)


CONSTRAINTS
-N will be between 1 and 2*10^9, inclusive.


EXAMPLES

0)
15

Returns: 4

The only optimal sequence is {1,2,4,8}. Clearly, 1 divides 2, 2 divides 4, 4 divides 8, and 1+2+4+8 = 15.

1)
12

Returns: 2

The are four distinct optimal sequences: {1,11}, {2,10}, {3,9}, and {4,8}. There is no valid sequence with more than two elements.

2)
34

Returns: 4

The only optimal sequence is {1, 3, 6, 24}.

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
		cout << "Testing DivisorSequences (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1559662125;
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
		DivisorSequences _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 15;
				_expected = 4;
				_received = _obj.longest(N); break;
			}
			case 1:
			{
				int N = 12;
				_expected = 2;
				_received = _obj.longest(N); break;
			}
			case 2:
			{
				int N = 34;
				_expected = 4;
				_received = _obj.longest(N); break;
			}
			case 3:
			{
				int N = 2000000001;
				_expected = 0;
				_received = _obj.longest(N); break;
			}
			/*case 4:
			{
				int N = ;
				_expected = ;
				_received = _obj.longest(N); break;
			}*/
			/*case 5:
			{
				int N = ;
				_expected = ;
				_received = _obj.longest(N); break;
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
