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

struct PerfectSquare {
  int ways(vector <int> x) {

  }
};

// BEGIN CUT HERE
/*
PROBLEM STATEMENT

There is an n by n matrix of positive integers.
You are given its elements in a vector <int> x with n*n 
elements.
For each i and j (0-based indices), the number in row i, 
column j of the matrix is x[i*n+j].



You want to select some elements of the matrix.
Your selection must satisfy the following constraints:

Each row must contain an odd number of selected elements.
Each column must contain an odd number of selected elements.
The product of all selected elements must be a perfect 
square.




Return the number of valid ways to select such subset of 
elements, modulo 1,000,000,007.



DEFINITION
Class:PerfectSquare
Method:ways
Parameters:vector <int>
Returns:int
Method signature:int ways(vector <int> x)


CONSTRAINTS
-n will be between 1 and 20, inclusive.
-x will contain exactly n*n elements.
-Each element in x will be between 1 and 1,000,000,000, 
inclusive.


EXAMPLES

0)
{1, 1,
 1, 2}


Returns: 1

The only valid solution is to select the elements in the 
cells (0,1) and (1,0). Their product is 1 = 1^2.

1)
{620, 620,
 620, 620}


Returns: 2

Two solutions: {(0,0), (1,1)}, {(0,1), (1,0)}.

2)
{1, 2, 3,
 4, 5, 6,
 7, 8, 9}

Returns: 1

The only valid solution is to select the elements with 
values 1, 2, 3, 6, and 9. Their product is 1*2*3*6*9 = 324 
= 18^2.

3)
{2, 2, 2, 2, 2,
 2, 2, 2, 2, 2,
 2, 2, 2, 2, 2,
 2, 2, 2, 2, 2,
 2, 2, 2, 2, 2}

Returns: 0

In this test case the total number of selected elements 
will always be odd. Thus, the product of all selected 
elements will always be equal to 2^(2k+1) for some k. A 
number of the form 2^(2k+1) can never be a perfect square.

4)
{2, 3, 4, 5,
 6, 7, 8, 9,
 10,11,12,13,
 14,15,16,17}

Returns: 4



5)
{9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,

 
9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,

 
9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,

 
9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,

 
9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,

 
9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,

 
9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,

 
9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,

 
9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,

 
9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690}


Returns: 993282280



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
		cout << "Testing PerfectSquare (800.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1399739653;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 800.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		PerfectSquare _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int x[] = {1, 1,
				           1, 2};
				_expected = 1;
				_received = _obj.ways(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}
			case 1:
			{
				int x[] = {620, 620,
				           620, 620};
				_expected = 2;
				_received = _obj.ways(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}
			case 2:
			{
				int x[] = {1, 2, 3,
				           4, 5, 6,
				           7, 8, 9};
				_expected = 1;
				_received = _obj.ways(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}
			case 3:
			{
				int x[] = {2, 2, 2, 2, 2,
				           2, 2, 2, 2, 2,
				           2, 2, 2, 2, 2,
				           2, 2, 2, 2, 2,
				           2, 2, 2, 2, 2};
				_expected = 0;
				_received = _obj.ways(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}
			case 4:
			{
				int x[] = {2, 3, 4, 5,
				           6, 7, 8, 9,
				           10,11,12,13,
				           14,15,16,17};
				_expected = 4;
				_received = _obj.ways(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}
			case 5:
			{
				int x[] = {9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,
				           9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,
				           9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,
				           9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,
				           9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,
				           9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,
				           9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,
				           9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,
				           9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,
				           9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690};
				_expected = 993282280;
				_received = _obj.ways(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}
			/*case 6:
			{
				int x[] = ;
				_expected = ;
				_received = _obj.ways(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int x[] = ;
				_expected = ;
				_received = _obj.ways(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int x[] = ;
				_expected = ;
				_received = _obj.ways(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
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
