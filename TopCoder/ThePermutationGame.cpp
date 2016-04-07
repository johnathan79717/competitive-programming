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

bool isprime[100005];

class ThePermutationGame {
	public:
	int findMin(int N) {
		MS1(isprime);
		LL ans = 1;
		for (int p = 2; p <= N; p++) {
			if (isprime[p]) {
				for (int k = p+p; k <= N; k+=p) {
					isprime[k] = false;
				}
				LL a = p;
				while (a * p <= N) {
					a = a * p;
				}
				ans = (ans * a) % 1000000007;
			}
		}
		return ans;
	}
};
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
Alice and Bob are playing a game called "The Permutation Game".
The game is parameterized with the int N.
At the start of the game, Alice chooses a positive integer x, and Bob chooses a permutation of the first N positive integers.
Let p be Bob's permutation.
Alice will start at 1, and apply the permutation to this value x times.
More formally, let f(1) = p[1], and f(m) = p[f(m-1)] for all m >= 2.
Alice's final value will be f(x).

Alice wants to choose the smallest x such that f(x) = 1 for any permutation Bob can provide.

Compute and return the value of such x modulo 1,000,000,007.


DEFINITION
Class:ThePermutationGame
Method:findMin
Parameters:int
Returns:int
Method signature:int findMin(int N)


NOTES
-A permutation of the first N positive integers is a sequence of length N that contains each of the integers 1 through N exactly once. The i-th (1-indexed) element of a permutation p is denoted by p[i].


CONSTRAINTS
-N will be between 1 and 100,000 inclusive.


EXAMPLES

0)
2

Returns: 2

 
Bob can choose the permutations (1,2) or (2,1).
If Alice chooses 1, then, Bob can choose the permutation (2,1), which would would make f(1) = 2.
However, if Alice chooses 2, no matter which permutation Bob chooses, Alice will get f(2) = 1.
Thus the answer in this case is 2.


1)
3

Returns: 6



2)
11

Returns: 27720



3)
102

Returns: 53580071



4)
9999

Returns: 927702802



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
		cout << "Testing ThePermutationGame (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1425947512;
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
		ThePermutationGame _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 2;
				_expected = 2;
				_received = _obj.findMin(N); break;
			}
			case 1:
			{
				int N = 3;
				_expected = 6;
				_received = _obj.findMin(N); break;
			}
			case 2:
			{
				int N = 11;
				_expected = 27720;
				_received = _obj.findMin(N); break;
			}
			case 3:
			{
				int N = 102;
				_expected = 53580071;
				_received = _obj.findMin(N); break;
			}
			case 4:
			{
				int N = 9999;
				_expected = 927702802;
				_received = _obj.findMin(N); break;
			}
			/*case 5:
			{
				int N = ;
				_expected = ;
				_received = _obj.findMin(N); break;
			}*/
			/*case 6:
			{
				int N = ;
				_expected = ;
				_received = _obj.findMin(N); break;
			}*/
			/*case 7:
			{
				int N = ;
				_expected = ;
				_received = _obj.findMin(N); break;
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
