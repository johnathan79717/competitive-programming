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
#define ALL(x) (x).begin(),(x).end()
#define MP make_pair
#define PB push_back
#define V(T) vector<T >
#define SZ(x) x.size()
 
typedef vector<int> VI;
typedef pair<int, int> PII;

class FoxesOfTheRoundTable {
	public:
	vector <int> minimalDifference(vector <int> h) {
		V(PII) a(SZ(h));
		REP(i, SZ(h)) {
			a[i] = MP(h[i], i);
		}
		sort(ALL(a));
		VI ans;
		for (int i = 1; i < SZ(h); i += 2) {
			// ans.PB(h[i]);
			ans.PB(a[i].second);
		}
		int i = SZ(h)-1;
		if (i % 2) i--;
		while (i >= 0) {
			// ans.PB(h[i]);
			ans.PB(a[i].second);
			i-=2;
		}
		return ans;
	}
};
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// There are n foxes, numbered 0 through n-1.
You are given a vector <int> h with n elements.
The elements of h are the heights of those foxes.
Your task is to arrange all foxes around a round table.


Given an arrangement of foxes, let D be the largest height difference between adjacent foxes.
For example, suppose that four foxes with heights { 10, 30, 20, 40 } sit around the table in this order.
The height differences are |10-30|=20, |30-20|=10, |20-40|=20, and |40-10|=30.
(Note that the last fox is also adjacent to the first one, as this is a round table.)
Then, the value D is max(20,10,20,30) = 30.


Find an arrangement of the given foxes for which the value D is as small as possible.
Return a permutation of foxes that describes your arrangement.
I.e., return a vector <int> with n elements: the numbers of foxes in order around the table.
If there are multiple optimal solutions, you may return any of them.

DEFINITION
Class:FoxesOfTheRoundTable
Method:minimalDifference
Parameters:vector <int>
Returns:vector <int>
Method signature:vector <int> minimalDifference(vector <int> h)


CONSTRAINTS
-h will contain between 3 and 50 elements, inclusive.
-Each element in h will be between 1 and 1,000, inclusive.


EXAMPLES

0)
{1,99,50,50}

Returns: {0, 3, 1, 2 }

In the optimal solution the foxes with heights 1 and 99 mustn't be adjacent.
Hence, the heights of foxes have to be 1, 50, 99, 50, in this cyclic order, and the optimal value of D is 49.
One permutation that produces this order of foxes is 0, 3, 1, 2.

1)
{123,456,789}

Returns: {0, 1, 2 }

Whatever we do, the result will always be 789-123.

2)
{10,30,40,50,60}

Returns: {0, 1, 4, 3, 2 }

The permutation {0, 1, 4, 3, 2 } specifies that the heights of foxes are in the following order: 10, 30, 60, 50, 40.

3)
{1,2,3,4,8,12,13,14 }

Returns: {0, 1, 2, 3, 5, 6, 7, 4 }



4)
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 }

Returns: {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19 }



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
		cout << "Testing FoxesOfTheRoundTable (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1436490073;
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
		FoxesOfTheRoundTable _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int h[] = {1,99,50,50};
				int __expected[] = {0, 3, 1, 2 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.minimalDifference(vector <int>(h, h+sizeof(h)/sizeof(int))); break;
			}
			case 1:
			{
				int h[] = {123,456,789};
				int __expected[] = {0, 1, 2 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.minimalDifference(vector <int>(h, h+sizeof(h)/sizeof(int))); break;
			}
			case 2:
			{
				int h[] = {10,30,40,50,60};
				int __expected[] = {0, 1, 4, 3, 2 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.minimalDifference(vector <int>(h, h+sizeof(h)/sizeof(int))); break;
			}
			case 3:
			{
				int h[] = {1,2,3,4,8,12,13,14 };
				int __expected[] = {0, 1, 2, 3, 5, 6, 7, 4 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.minimalDifference(vector <int>(h, h+sizeof(h)/sizeof(int))); break;
			}
			case 4:
			{
				int h[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 };
				int __expected[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.minimalDifference(vector <int>(h, h+sizeof(h)/sizeof(int))); break;
			}
			/*case 5:
			{
				int h[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.minimalDifference(vector <int>(h, h+sizeof(h)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int h[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.minimalDifference(vector <int>(h, h+sizeof(h)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int h[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.minimalDifference(vector <int>(h, h+sizeof(h)/sizeof(int))); break;
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
			cout << "           Expected: {";
			for (unsigned i = 0; i < _expected.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _expected[i];
			}
			cout << " }" << endl;
			cout << "           Received: {";
			for (unsigned i = 0; i < _received.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _received[i];
			}
			cout << " }" << endl;
		}
	}
}

// END CUT HERE
