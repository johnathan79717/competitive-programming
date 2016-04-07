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
#define FOR(i, c) for(auto &i: c)
#define ALL(x) (x).begin(),(x).end()
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define PER(i,n) for(int i=(n)-1;i>=0;i--)
#define PER1(i,a,b) for(int i=(a);i>=(b);i--)
#define MP make_pair
#define PB push_back
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,-1,sizeof(x))
#define V(T) vector<T >
#define EB emplace_back
 
typedef long long LL;

struct TheKnights {
  double find(int n, int a, int b) {

  }
};

// BEGIN CUT HERE
/*
PROBLEM STATEMENT
John and Brus have two (a, b) chess knights.
When an (a, b) knight moves, it can move a squares 
horizontally and b squares vertically, or b squares 
horizontally and a squares vertically.


John and Brus place their knights on two different cells 
of an n by n chessboard.
The pair of cells is chosen uniformly at random.
A chessboard cell is attacked if it is either occupied by 
one of the knights, or if it can be reached by one of the 
knights in a single move.
Return the expected number of attacked cells.


DEFINITION
Class:TheKnights
Method:find
Parameters:int, int, int
Returns:double
Method signature:double find(int n, int a, int b)


NOTES
-The returned value must be accurate to within a relative 
or absolute value of 1E-9.
-Informally, the expected number of attacked cells can be 
seen as the average number over very many rounds of the 
process. See http://en.wikipedia.org/wiki/Expected_value 
for a formal definition.


CONSTRAINTS
-n will be between 2 and 1,000,000,000, inclusive.
-a will be between 1 and 1,000,000,000, inclusive.
-b will be between 1 and 1,000,000,000, inclusive.


EXAMPLES

0)
2
1
1

Returns: 3.3333333333333335

If we fix one of the knights, there are three ways to 
place the other one.
In two of those three cases all 4 cells on the board will 
be attacked.
In the last case only the 2 cells occupied by the knights 
will be attacked.
Thus the expected value is 4*(2/3) + 2*(1/3) =  10/3.


1)
47
7
74

Returns: 2.0

For any placement of the knights only two cells will be 
attacked.

2)
3
2
1

Returns: 4.888888888888889



3)
9999
999
99

Returns: 16.25885103191273



4)
10
1
6

Returns: 7.636363636363637



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
		cout << "Testing TheKnights (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1396673722;
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
		TheKnights _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 2;
				int a = 1;
				int b = 1;
				_expected = 3.3333333333333335;
				_received = _obj.find(n, a, b); break;
			}
			case 1:
			{
				int n = 47;
				int a = 7;
				int b = 74;
				_expected = 2.0;
				_received = _obj.find(n, a, b); break;
			}
			case 2:
			{
				int n = 3;
				int a = 2;
				int b = 1;
				_expected = 4.888888888888889;
				_received = _obj.find(n, a, b); break;
			}
			case 3:
			{
				int n = 9999;
				int a = 999;
				int b = 99;
				_expected = 16.25885103191273;
				_received = _obj.find(n, a, b); break;
			}
			case 4:
			{
				int n = 10;
				int a = 1;
				int b = 6;
				_expected = 7.636363636363637;
				_received = _obj.find(n, a, b); break;
			}
			/*case 5:
			{
				int n = ;
				int a = ;
				int b = ;
				_expected = ;
				_received = _obj.find(n, a, b); break;
			}*/
			/*case 6:
			{
				int n = ;
				int a = ;
				int b = ;
				_expected = ;
				_received = _obj.find(n, a, b); break;
			}*/
			/*case 7:
			{
				int n = ;
				int a = ;
				int b = ;
				_expected = ;
				_received = _obj.find(n, a, b); break;
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
