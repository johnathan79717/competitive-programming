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

#line 40 "RndSubTree.cpp"
#include <string>
#include <vector>
class RndSubTree {
public:
  int count(int k) {

  }
};

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Hero has an infinite complete binary tree rooted at the vertex r.
That is, the tree contains r, its two children, four grandchildren, and so on.
Initially, all vertices in this tree are white.

Hero is going to color k vertices of its tree red.
He will choose each of those vertices at random.
More precisely, he will repeat the following procedure k times:


Place a token onto the root vertex r.
While the token is on a red vertex, choose one of its two children at random with equal probability and move the token onto the chosen child.
When the token is on a white vertex for the first time, color that vertex red and remove the token.


If there are k red vertices in the tree, there are exactly k*(k-1)/2 simple paths such that both endpoints of the path are red.
Hero is interested in the total length of all these paths.
Calculate the expected value of that total length.

Let M = 10^9 + 7.
It can be shown that the exact value of the answer can be written as a reduced fraction P/Q such that Q and M are relatively prime.
Let Q^(-1) be the multiplicative inverse of Q, modulo M.
Compute and return the value (P*Q^(-1)) modulo M.

DEFINITION
Class:RndSubTree
Method:count
Parameters:int
Returns:int
Method signature:int count(int k)


CONSTRAINTS
-k will be between 1 and 2000, inclusive.


EXAMPLES

0)
1

Returns: 0

With only one red vertex there are no paths, so their total length is always zero.

1)
2

Returns: 1

The two red vertices will always be the root vertex r and one of its children. The only path with both endpoints red will always have length 1.

2)
3

Returns: 4

Regardless of the random choices, the three red vertices will always form a path. (The root vertex r may be an endpoint of this path, or it can be in its middle.) The three random paths will have lengths 1, 1, and 2, for a total of 4.

3)
4

Returns: 875000016

With probability 7/8 the sum of path lengths is 10 and with probability 1/8 the sum of path lengths is 9. Thus, the expected value of the sum of path lengths is (7/8)*10 + (1/8)*9 = 79/8.

The multiplicative inverse of 8 modulo M = 10^9 + 7 is 125,000,001, because (125000001*8) mod M = 1.

Thus, the value you should return is (79 * 125000001) mod M = 875000016.

4)
5

Returns: 531250023



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
		cout << "Testing RndSubTree (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1521304042;
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
		RndSubTree _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int k = 1;
				_expected = 0;
				_received = _obj.count(k); break;
			}
			case 1:
			{
				int k = 2;
				_expected = 1;
				_received = _obj.count(k); break;
			}
			case 2:
			{
				int k = 3;
				_expected = 4;
				_received = _obj.count(k); break;
			}
			case 3:
			{
				int k = 4;
				_expected = 875000016;
				_received = _obj.count(k); break;
			}
			case 4:
			{
				int k = 5;
				_expected = 531250023;
				_received = _obj.count(k); break;
			}
			/*case 5:
			{
				int k = ;
				_expected = ;
				_received = _obj.count(k); break;
			}*/
			/*case 6:
			{
				int k = ;
				_expected = ;
				_received = _obj.count(k); break;
			}*/
			/*case 7:
			{
				int k = ;
				_expected = ;
				_received = _obj.count(k); break;
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
