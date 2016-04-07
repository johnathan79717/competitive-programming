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

struct TheFrog {
  double getMinimum(int D, vector <int> L, vector <int> R) {

  }
};

// BEGIN CUT HERE
/*
PROBLEM STATEMENT
Frog Jim is fond of jumping.
Moreover, all his jumps have the same length X.
Currently, he is standing at the point 0 on the real axis.
He needs to jump along the axis until he gets to point D or beyond it.

There are several pits between points 0 and D. 
For each valid i, there is a pit strictly between L[i] and R[i].
This means that Jim cannot step onto any point that is strictly between points L[i] and R[i].
(He is allowed to step onto the points L[i] and R[i]: as all pits are disjoint, the endpoints of each pit are always safe.)

Find the minimum length of jump X such that if Jim performs only jumps of length X, he can avoid every pit and get to point D or any point beyond it. Note that this length can be non-integer.

DEFINITION
Class:TheFrog
Method:getMinimum
Parameters:int, vector <int>, vector <int>
Returns:double
Method signature:double getMinimum(int D, vector <int> L, vector <int> R)


NOTES
-The returned value must have an absolute or relative error less than 1e-9.


CONSTRAINTS
-D will be between 1 and 30,000, inclusive.
-L will contain between 1 and 50 elements, inclusive.
-Each element of L will be between 0 and D-1, inclusive.
-R will contain the same number of elements as L.
-The i-th element of R will be between L[i]+1 and D, inclusive.
-The intervals given by (L[i], R[i]) will not intersect.


EXAMPLES

0)
16
{2}
{7}

Returns: 7.0

Moving by jumps of length 7, Jim goes from point 0 to point 7, then to point 14 and then to point 21, which is beyond 16. If Jim chose a shorter jump, he would end up in the pit.

1)
25
{11, 3}
{21, 7}

Returns: 10.5

There are two pits. One of them is between points 11 and 21 and the other between points 3 and 7. By fixing jump length at 10.5, Jim successfully avoids them.

2)
100
{0}
{100}

Returns: 100.0

Jim has no other choice but to jump right to point 100.

3)
100
{0, 50}
{50, 100}

Returns: 50.0

In this case, point 50 is a suitable place to land, so Jim can choose X = 50.

4)
30000
{17, 25281, 5775, 2825, 14040}
{55, 26000, 5791, 3150, 14092}

Returns: 787.8787878787879



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
		cout << "Testing TheFrog (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1396416235;
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
		TheFrog _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int D = 16;
				int L[] = {2};
				int R[] = {7};
				_expected = 7.0;
				_received = _obj.getMinimum(D, vector <int>(L, L+sizeof(L)/sizeof(int)), vector <int>(R, R+sizeof(R)/sizeof(int))); break;
			}
			case 1:
			{
				int D = 25;
				int L[] = {11, 3};
				int R[] = {21, 7};
				_expected = 10.5;
				_received = _obj.getMinimum(D, vector <int>(L, L+sizeof(L)/sizeof(int)), vector <int>(R, R+sizeof(R)/sizeof(int))); break;
			}
			case 2:
			{
				int D = 100;
				int L[] = {0};
				int R[] = {100};
				_expected = 100.0;
				_received = _obj.getMinimum(D, vector <int>(L, L+sizeof(L)/sizeof(int)), vector <int>(R, R+sizeof(R)/sizeof(int))); break;
			}
			case 3:
			{
				int D = 100;
				int L[] = {0, 50};
				int R[] = {50, 100};
				_expected = 50.0;
				_received = _obj.getMinimum(D, vector <int>(L, L+sizeof(L)/sizeof(int)), vector <int>(R, R+sizeof(R)/sizeof(int))); break;
			}
			case 4:
			{
				int D = 30000;
				int L[] = {17, 25281, 5775, 2825, 14040};
				int R[] = {55, 26000, 5791, 3150, 14092};
				_expected = 787.8787878787879;
				_received = _obj.getMinimum(D, vector <int>(L, L+sizeof(L)/sizeof(int)), vector <int>(R, R+sizeof(R)/sizeof(int))); break;
			}
			/*case 5:
			{
				int D = ;
				int L[] = ;
				int R[] = ;
				_expected = ;
				_received = _obj.getMinimum(D, vector <int>(L, L+sizeof(L)/sizeof(int)), vector <int>(R, R+sizeof(R)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int D = ;
				int L[] = ;
				int R[] = ;
				_expected = ;
				_received = _obj.getMinimum(D, vector <int>(L, L+sizeof(L)/sizeof(int)), vector <int>(R, R+sizeof(R)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int D = ;
				int L[] = ;
				int R[] = ;
				_expected = ;
				_received = _obj.getMinimum(D, vector <int>(L, L+sizeof(L)/sizeof(int)), vector <int>(R, R+sizeof(R)/sizeof(int))); break;
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
