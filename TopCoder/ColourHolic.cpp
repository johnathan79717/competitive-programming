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
 
typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;

struct ColourHolic {
  int countSequences(vector <int> n) {

  }
};

// BEGIN CUT HERE
/*
PROBLEM STATEMENT

Vendelín has a part-time job in an "all for 1 euro" 
bargain store. He was given the task of putting several 
items into a row on one long shelf in the display window.



Vendelín is shape-blind: he only cares about the items' 
colours. This time, he sees that each of his items comes 
in one of just 4 colours: turquoise, magenta, beige and 
lavender (but don't worry, we've numbered them 0 through 3 
for your convenience). Also, in order to attract 
customers, he wants each two adjacent items on the shelf 
to have different colours. 



You're given an vector <int> n with 4 elements. For each 
i, Vendelín has n[i] items of colour i.



Compute and return the number of sequences of items such 
that no two adjacent items share the same colour. Since 
this number can get very large, return it modulo 
1,000,000,009.


DEFINITION
Class:ColourHolic
Method:countSequences
Parameters:vector <int>
Returns:int
Method signature:int countSequences(vector <int> n)


CONSTRAINTS
-n will contain exactly 4 elements.
-Each element of n will be between 0 and 50,000, inclusive.
-There will be at least 1 item, so the elements of n won't 
all be equal to 0.
-At least 2 elements of n won't exceed 200.


EXAMPLES

0)
{1,0,2,3}

Returns: 10

There are 10 possible sequences of 1 turquoise (colour 0), 
2 beige (colour 2) and 3 lavender (colour 3) items with no 
two adjacent items sharing the same colour. For example, 
(0,3,2,3,2,3) or (3,2,0,3,2,3) are valid sequences of 
colours. However, (3,2,2,3,2,3) isn't valid.

1)
{1,1,1,1}

Returns: 24

All 4! permutations of these items are valid.

2)
{42,42,42,9001}

Returns: 0

There are way too many items of colour 3. In any sequence, 
there would be two adjacent items of this colour.

3)
{8,0,0,8}

Returns: 2



4)
{0,5,1,3}

Returns: 4



5)
{4,2,1,3}

Returns: 1074



6)
{15,900,357,22}

Returns: 0



7)
{110,30000,200,29999}

Returns: 118115350

Make sure you're using 109+9 as the modulus!

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
		cout << "Testing ColourHolic (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1412441133;
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
		ColourHolic _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n[] = {1,0,2,3};
				_expected = 10;
				_received = _obj.countSequences(vector <int>(n, n+sizeof(n)/sizeof(int))); break;
			}
			case 1:
			{
				int n[] = {1,1,1,1};
				_expected = 24;
				_received = _obj.countSequences(vector <int>(n, n+sizeof(n)/sizeof(int))); break;
			}
			case 2:
			{
				int n[] = {42,42,42,9001};
				_expected = 0;
				_received = _obj.countSequences(vector <int>(n, n+sizeof(n)/sizeof(int))); break;
			}
			case 3:
			{
				int n[] = {8,0,0,8};
				_expected = 2;
				_received = _obj.countSequences(vector <int>(n, n+sizeof(n)/sizeof(int))); break;
			}
			case 4:
			{
				int n[] = {0,5,1,3};
				_expected = 4;
				_received = _obj.countSequences(vector <int>(n, n+sizeof(n)/sizeof(int))); break;
			}
			case 5:
			{
				int n[] = {4,2,1,3};
				_expected = 1074;
				_received = _obj.countSequences(vector <int>(n, n+sizeof(n)/sizeof(int))); break;
			}
			case 6:
			{
				int n[] = {15,900,357,22};
				_expected = 0;
				_received = _obj.countSequences(vector <int>(n, n+sizeof(n)/sizeof(int))); break;
			}
			case 7:
			{
				int n[] = {110,30000,200,29999};
				_expected = 118115350;
				_received = _obj.countSequences(vector <int>(n, n+sizeof(n)/sizeof(int))); break;
			}
			/*case 8:
			{
				int n[] = ;
				_expected = ;
				_received = _obj.countSequences(vector <int>(n, n+sizeof(n)/sizeof(int))); break;
			}*/
			/*case 9:
			{
				int n[] = ;
				_expected = ;
				_received = _obj.countSequences(vector <int>(n, n+sizeof(n)/sizeof(int))); break;
			}*/
			/*case 10:
			{
				int n[] = ;
				_expected = ;
				_received = _obj.countSequences(vector <int>(n, n+sizeof(n)/sizeof(int))); break;
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
