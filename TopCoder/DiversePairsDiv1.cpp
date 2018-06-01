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

#line 40 "DiversePairsDiv1.cpp"
#include <string>
#include <vector>

VI dp[2005];

class DiversePairsDiv1 {
public:
  vector <int> findMaxDiversePairs(int a, int b) {
    int N = b - a;
    REP1(i, 0, N) {
      dp[i].clear();
    }
    dp[2].PB(1);
    dp[2].PB(2);
    REP1(i, 3, N) {
      if (dp[i-1].size() > dp[i-3].size() + 2) {
	dp[i] = dp[i-1];
      } else {
	dp[i] = dp[i-3];
	for (int &x : dp[i]) {
	  x++;
	}
	dp[i].PB(1);
	dp[i].PB(i);
      }
    }
    for (int &x : dp[N]) {
      x += a-1;
    }
    return dp[N];
  }
};

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
You are given the ints a ≤ b.
Consider the set of integers between a and b, inclusive.
You want to use some of these integers to construct a set of pairs of integers.
A set that consists of k pairs is said to be diverse if all of the following conditions are met.

All 2k integers used in the pairs are distinct.
The sum of each pair is strictly smaller than a + b.
The sums of the k pairs are k distinct integers.





For instance, suppose that a=2 and b=4, which means that we are allowed to use the integers from the set {2, 3, 4}. Then:



{(2, 2)} is a set that contains one pair of numbers, but it is not a diverse set because it violates condition #1.
{(3, 3)} does also violate condition #1
{(2, 4)} violates condition #2, as 2 + 4 is not strictly smaller than a + b.
{(3, 4)} does also violate condition #2.
{(2, 4), (3, 3)} is a set that contains two pairs of numbers; this set violates conditions #1 and #3.
{(2, 3)} is a diverse set.
{(3, 2)} is another diverse set.



In the above example it is obvious that there is no diverse set with two or more pairs of integers, hence {(2, 3)} and {(3, 2)} are the largest diverse sets.




You are interested in finding the largest possible diverse set of pairs for the given a and b.
That is, among all diverse sets of pairs you can construct, you want to find one that contains the maximum number of pairs.




Return a vector <int> that describes a maximum diverse set of pairs as follows:
If {(x1, y1), (x2, y2), ..., (xk, yk)} is the set of pairs you found, 
return 
{
x1, y1, 
x2, y2, 
..., 
xk, yk
}.




If multiple answers exist, you may return any one of them.
If the maximum set of pairs is an empty set, then you must return an empty vector <int>.



DEFINITION
Class:DiversePairsDiv1
Method:findMaxDiversePairs
Parameters:int, int
Returns:vector <int>
Method signature:vector <int> findMaxDiversePairs(int a, int b)


CONSTRAINTS
-a will be between 1 and 10^9, inclusive.
-b will be between 1 and 10^9, inclusive.
-b-a will be between 0 and 2,000, inclusive.


EXAMPLES

0)
1
1

Returns: { }



1)
1
2

Returns: { }

The only pairs of distinct integers we can construct are (1, 2) and (2, 1), but both sets {(1, 2)} and {(2, 1)} violate condition #2.


2)
2
4

Returns: {2, 3 }

This example was discussed in the problem statement.
{3, 2} is another correct return value.


3)
5
9

Returns: {5, 6 }

There is no diverse set with two pairs of integers. In particular, the set {(5, 8), (6, 7)} does satisfy conditions #1 and #2 (all integers are distinct and all pairwise sums are small enough) but 5+8 = 6+7, so this set violates condition #3.

4)
15
21

Returns: {15, 20, 16, 18 }



5)
20
27

Returns: {21, 25, 22, 23, 20, 24 }



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
		cout << "Testing DiversePairsDiv1 (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1526130418;
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
		DiversePairsDiv1 _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int a = 1;
				int b = 1;
				int __expected[] = { };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findMaxDiversePairs(a, b); break;
			}
			case 1:
			{
				int a = 1;
				int b = 2;
				int __expected[] = { };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findMaxDiversePairs(a, b); break;
			}
			case 2:
			{
				int a = 2;
				int b = 4;
				int __expected[] = {2, 3 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findMaxDiversePairs(a, b); break;
			}
			case 3:
			{
				int a = 5;
				int b = 9;
				int __expected[] = {5, 6 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findMaxDiversePairs(a, b); break;
			}
			case 4:
			{
				int a = 15;
				int b = 21;
				int __expected[] = {15, 20, 16, 18 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findMaxDiversePairs(a, b); break;
			}
			case 5:
			{
				int a = 20;
				int b = 27;
				int __expected[] = {21, 25, 22, 23, 20, 24 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findMaxDiversePairs(a, b); break;
			}
			/*case 6:
			{
				int a = ;
				int b = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findMaxDiversePairs(a, b); break;
			}*/
			/*case 7:
			{
				int a = ;
				int b = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findMaxDiversePairs(a, b); break;
			}*/
			/*case 8:
			{
				int a = ;
				int b = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findMaxDiversePairs(a, b); break;
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
