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
#define ALL(x) (x).begin(),(x).end()
#define REP(i,n) for(int i=0;i<(n);i++)
#define V(T) vector<T >
#define EB emplace_back
 
typedef pair<int, int> PII;

struct PairGame {
  int maxSum(int a, int b, int c, int d) {
  	V(PII) ans;
  	while(a && b) {
  		ans.EB(a, b);
  		if(a > b) a -= b;
  		else b -= a;
  	}
  	while(c && d) {
  		ans.EB(c, d);
  		if(c > d) c -= d;
  		else d -= c;
  	}
  	sort(ALL(ans), [](const PII &p1, const PII &p2) {
  		return p1.first + p1.second > p2.first + p2.second;
  	});
  	REP(i, ans.size()-1)
  		if(ans[i] == ans[i+1])
  			return ans[i].first + ans[i].second;
  	return -1;
  }
};

// BEGIN CUT HERE
/*
PROBLEM STATEMENT
You have an ordered pair of integers.
You can now make zero or more steps.
In each step, you can change your pair into a new pair of 
integers by adding one of them to the other.
That is, if your current pair is (x, y), then your next 
pair will be either (x+y, y), or (x, x+y).



For example, you can start with (1, 2), change it to (3, 
2), change that to (3, 5), and then change that again to 
(3, 8).



You are given four ints: a, b, c, and d.
We are looking for a pair (x, y) such that:

It is possible to start with (x, y) and end with (a, b).
It is also possible to start with the same (x, y) and end 
with (c, d).

The number of steps needed to reach (a, b) may be 
different from the number of steps needed to reach (c, d).



If there is at least one such pair (x, y), return the 
largest possible value of x+y.
Otherwise, return -1.

DEFINITION
Class:PairGame
Method:maxSum
Parameters:int, int, int, int
Returns:int
Method signature:int maxSum(int a, int b, int c, int d)


CONSTRAINTS
-a will be between 1 and 1,000,000, inclusive.
-b will be between 1 and 1,000,000, inclusive.
-c will be between 1 and 1,000,000, inclusive.
-d will be between 1 and 1,000,000, inclusive.


EXAMPLES

0)
1
2
2
1

Returns: 2

We have (1,1) -> (1,2) and (1,1) -> (2,1).


1)
15
4
10
7

Returns: 7

Now we have (3,4) -> (7,4) -> (11,4) -> (15,4) and (3,4) -
> (3,7) -> (10,7).

2)
1
1
10
10

Returns: -1



3)
1000
1001
2000
2001

Returns: 1001



4)
10944
17928
7704
21888

Returns: 144



5)
1
1
1
1

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
		cout << "Testing PairGame (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1399737604;
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
		PairGame _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int a = 1;
				int b = 2;
				int c = 2;
				int d = 1;
				_expected = 2;
				_received = _obj.maxSum(a, b, c, d); break;
			}
			case 1:
			{
				int a = 15;
				int b = 4;
				int c = 10;
				int d = 7;
				_expected = 7;
				_received = _obj.maxSum(a, b, c, d); break;
			}
			case 2:
			{
				int a = 1;
				int b = 1;
				int c = 10;
				int d = 10;
				_expected = -1;
				_received = _obj.maxSum(a, b, c, d); break;
			}
			case 3:
			{
				int a = 1000;
				int b = 1001;
				int c = 2000;
				int d = 2001;
				_expected = 1001;
				_received = _obj.maxSum(a, b, c, d); break;
			}
			case 4:
			{
				int a = 10944;
				int b = 17928;
				int c = 7704;
				int d = 21888;
				_expected = 144;
				_received = _obj.maxSum(a, b, c, d); break;
			}
			case 5:
			{
				int a = 1;
				int b = 1;
				int c = 1;
				int d = 1;
				_expected = 2;
				_received = _obj.maxSum(a, b, c, d); break;
			}
			/*case 6:
			{
				int a = ;
				int b = ;
				int c = ;
				int d = ;
				_expected = ;
				_received = _obj.maxSum(a, b, c, d); break;
			}*/
			/*case 7:
			{
				int a = ;
				int b = ;
				int c = ;
				int d = ;
				_expected = ;
				_received = _obj.maxSum(a, b, c, d); break;
			}*/
			/*case 8:
			{
				int a = ;
				int b = ;
				int c = ;
				int d = ;
				_expected = ;
				_received = _obj.maxSum(a, b, c, d); break;
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
