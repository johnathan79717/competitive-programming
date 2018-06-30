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
 
typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;

#line 40 "ArithmeticSequenceDiv1.cpp"
#include <string>
#include <vector>
class ArithmeticSequenceDiv1 {
public:
  int findMinCost(vector <int> x) {
    int N = x.size();
    int ans = 1e9;
    REP(i, N) {
      REP1(d, -100, 100) {
	int cost = 0;
	REP(j, N) {
	  int y = x[i] + (j - i) * d;
	  cost += abs(x[j] - y);
	}
	ans = min(ans, cost);
      }
    }
    return ans;
  }
};

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
An arithmetic sequence of length n is a sequence y[0], y[1], ..., y[n-1] such that for each i we have y[i] = y[0] + i*d, where d is some constant.
For example, {4,5,6,7}, {1,1,1,1,1}, and {7,5,3} are arithmetic sequences.




You are given a sequence of n positive integers: x[0], x[1], ..., x[n-1].
You are allowed to change this sequence.
More precisely, you may perform arbitrarily many steps.
In each step you may choose any element of the sequence and change it to any integer value.
(Note that the new value is not required to be positive.)
The cost of each change is equal to the absolute difference between the old and the new value.




You are given the vector <int> x.
Compute and return the smallest total cost of changing x into an arithmetic sequence of integers.


DEFINITION
Class:ArithmeticSequenceDiv1
Method:findMinCost
Parameters:vector <int>
Returns:int
Method signature:int findMinCost(vector <int> x)


CONSTRAINTS
-x will contain betwee 1 and 100 elements, inclusive.
-Each element of x will be between 1 and 100, inclusive. 


EXAMPLES

0)
{1,3,2}

Returns: 2

One optimal solution is to change this sequence into {1,2,3}.
Changing x[1] from 3 to 2 costs abs(3-2) = 1.
Changing x[2] from 2 to 3 costs abs(2-3) = 1.
Thus, the total cost is 2.

1)
{1,1,1,2,3,4,5}

Returns: 3

Here an optimal solution is to change x[0] from 1 to -1 (cost 2) and then change x[1] from 1 to 0 (cost 1).

2)
{1,2,3,4}

Returns: 0

This is already an arithmetic sequence, so the cheapest solution is to do nothing.

3)
{1,5,2,5}

Returns: 5



4)
{11,33,22}

Returns: 17



5)
{1, 3, 5, 7, 2, 4, 6}

Returns: 12



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
		cout << "Testing ArithmeticSequenceDiv1 (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1527955205;
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
		ArithmeticSequenceDiv1 _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int x[] = {1,3,2};
				_expected = 2;
				_received = _obj.findMinCost(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}
			case 1:
			{
				int x[] = {1,1,1,2,3,4,5};
				_expected = 3;
				_received = _obj.findMinCost(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}
			case 2:
			{
				int x[] = {1,2,3,4};
				_expected = 0;
				_received = _obj.findMinCost(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}
			case 3:
			{
				int x[] = {1,5,2,5};
				_expected = 5;
				_received = _obj.findMinCost(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}
			case 4:
			{
				int x[] = {11,33,22};
				_expected = 17;
				_received = _obj.findMinCost(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}
			case 5:
			{
				int x[] = {1, 3, 5, 7, 2, 4, 6};
				_expected = 12;
				_received = _obj.findMinCost(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}
			/*case 6:
			{
				int x[] = ;
				_expected = ;
				_received = _obj.findMinCost(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int x[] = ;
				_expected = ;
				_received = _obj.findMinCost(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int x[] = ;
				_expected = ;
				_received = _obj.findMinCost(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
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
