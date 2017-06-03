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

#line 40 "FoxAndCake2.cpp"
#include <string>
#include <vector>
class FoxAndCake2 {
public:
  string isPossible(int c, int s) {
    return solve(c, s) ? "Possible" : "Impossible";
  }

  bool solve(int c, int s) {
    if (__gcd(c, s) != 1) {
      return true;
    }
    if (c > s) {
      swap(c, s);
    }
    if (c <= 4) {
      return false;
    }
    if (c % 2 == 1 && s % 2 == 1) {
      return true;
    }
    if (c == 5) {
      if (s > 6) {
        return true;
      }
      return false;
    }
    return true;
  }
};

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Fox Ciel has c cherries and s strawberries.
She wants to bake some cakes.
While doing so, she wants to follow some rules:

She must use exactly all cherries and all strawberries she has.
The number of cakes can be arbitrary (i.e., any positive integer).
Different cakes may contain different amounts of cherries and strawberries.
Each cake must contain at least one cherry and at least one strawberry.
A cake will taste bad if the number of cherries and the number of strawberries it contains happen to be coprime. Therefore, the numbers of cherries and strawberries in a cake must never be coprime. (Two positive integers are coprime if their greatest common divisor is 1.)


You are given the ints c and s.
Return "Possible" if Ciel can bake cakes according to the above rules, or "Impossible" if she cannot do so.

DEFINITION
Class:FoxAndCake2
Method:isPossible
Parameters:int, int
Returns:string
Method signature:string isPossible(int c, int s)


CONSTRAINTS
-c will be between 1 and 1,000,000,000, inclusive.
-s will be between 1 and 1,000,000,000, inclusive.


EXAMPLES

0)
74
109

Returns: "Possible"

One possible solution is to bake 3 cakes as follows:

A cake with 21 cherries and 14 strawberries.
A cake with 20 cherries and 40 strawberries.
A cake with 33 cherries and 55 strawberries.


1)
1000000000
1000000000

Returns: "Possible"

Here Ciel can simply make one huge cake with 1000000000 cherries and 1000000000 strawberries.

2)
1
58

Returns: "Impossible"

Ciel only has 1 cherry, so the only option is to bake one cake with 1 cherry and 58 strawberries.
However, 1 and 58 are coprime, so this is not a good cake.

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
		cout << "Testing FoxAndCake2 (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1495296031;
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
		FoxAndCake2 _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int c = 74;
				int s = 109;
				_expected = "Possible";
				_received = _obj.isPossible(c, s); break;
			}
			case 1:
			{
				int c = 1000000000;
				int s = 1000000000;
				_expected = "Possible";
				_received = _obj.isPossible(c, s); break;
			}
			case 2:
			{
				int c = 1;
				int s = 58;
				_expected = "Impossible";
				_received = _obj.isPossible(c, s); break;
			}
			/*case 3:
			{
				int c = ;
				int s = ;
				_expected = ;
				_received = _obj.isPossible(c, s); break;
			}*/
			/*case 4:
			{
				int c = ;
				int s = ;
				_expected = ;
				_received = _obj.isPossible(c, s); break;
			}*/
			/*case 5:
			{
				int c = ;
				int s = ;
				_expected = ;
				_received = _obj.isPossible(c, s); break;
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
			cout << "           Expected: " << "\"" << _expected << "\"" << endl;
			cout << "           Received: " << "\"" << _received << "\"" << endl;
		}
	}
}

// END CUT HERE
