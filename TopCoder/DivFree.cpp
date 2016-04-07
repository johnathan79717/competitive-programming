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
#line 39 "DivFree.cpp"
#include <string>
#include <vector>
class DivFree {
public:
    int dfcount(int n, int k) {
        
    }
};
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Hero likes some arrays. The arrays he likes are the arrays that have all of the following properties:

The length of the array is n.
Each element is an integer between 1 and k, inclusive.
Whenever A and B are two consecutive elements of the array (in this order), we have (A <= B) or (A mod B != 0).


For example, suppose n=4 and k=7.
Hero will like the array {1,7,7,2} because it has the right length, all elements are in the correct range, 1 <= 7, 7 <= 7, and 7 mod 2 != 0.
Hero will not like the array {4,4,4,2}.

You are given the ints n and k.
Let X be the number of different arrays Hero likes.
Compute and return the value (X mod 1,000,000,007).

DEFINITION
Class:DivFree
Method:dfcount
Parameters:int, int
Returns:int
Method signature:int dfcount(int n, int k)


CONSTRAINTS
-n will be between 1 and 50,000, inclusive.
-k will be between 1 and 50,000, inclusive.


EXAMPLES

0)
2
2

Returns: 3

The three arrays Hero likes are {1,1}, {1,2}, and {2,2}.

1)
3
2

Returns: 4

The four arrays Hero likes in this case are {1,1,1}, {1,1,2}, {1,2,2}, and {2,2,2}.

2)
3
3

Returns: 15



3)
1
107

Returns: 107



4)
5
6

Returns: 2292



5)
42
23

Returns: 301026516



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
		cout << "Testing DivFree (600.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1457367577;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 600.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		DivFree _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 2;
				int k = 2;
				_expected = 3;
				_received = _obj.dfcount(n, k); break;
			}
			case 1:
			{
				int n = 3;
				int k = 2;
				_expected = 4;
				_received = _obj.dfcount(n, k); break;
			}
			case 2:
			{
				int n = 3;
				int k = 3;
				_expected = 15;
				_received = _obj.dfcount(n, k); break;
			}
			case 3:
			{
				int n = 1;
				int k = 107;
				_expected = 107;
				_received = _obj.dfcount(n, k); break;
			}
			case 4:
			{
				int n = 5;
				int k = 6;
				_expected = 2292;
				_received = _obj.dfcount(n, k); break;
			}
			case 5:
			{
				int n = 42;
				int k = 23;
				_expected = 301026516;
				_received = _obj.dfcount(n, k); break;
			}
			/*case 6:
			{
				int n = ;
				int k = ;
				_expected = ;
				_received = _obj.dfcount(n, k); break;
			}*/
			/*case 7:
			{
				int n = ;
				int k = ;
				_expected = ;
				_received = _obj.dfcount(n, k); break;
			}*/
			/*case 8:
			{
				int n = ;
				int k = ;
				_expected = ;
				_received = _obj.dfcount(n, k); break;
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
