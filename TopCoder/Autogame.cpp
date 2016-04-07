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
#define MS0(x) memset(x,0,sizeof(x))

int MOD = 1000000007;

struct Z {
    int i;
    Z():i(0) {}
    Z(int i): i(i >= 0 ? i : i + MOD) {}
    void operator *=(const Z& z) { i = (long long) i * z.i % MOD; }
    Z operator *(const Z& z) const { Z ret(i); ret *= z; return ret; }
};


class Autogame {
	public:
	int wayscnt(vector <int> a, int K) {
		int temp[2][100];
		MS0(temp);
		int N = a.size();
		int *prev = temp[0], *next = temp[1];
		REP(i, N) {
			prev[i] = 1;
		}
		REP(k, min(K, 1000000)) {
			REP(i, N) {
				next[i] = 0;
			}
			REP(i, N) {
				next[a[i]-1] += prev[i];
			}
			swap(next, prev);
		}
		Z ans = 1;
		REP(i, N) {
			ans *= prev[i] + 1;
		}
		return ans.i;
	}
};
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Hero is playing a game with tokens.
There are N places for tokens.
The places are numbered 1 through N.
There are also N arrows, each pointing from some place to some place.
No two arrows start at the same place.
It is possible that multiple arrows point to the same place.
Also, an arrow may start and end at the same place.

You are given the description of the game board: a vector <int> a with N elements.
For each i between 1 and N, inclusive, the arrow that starts at the place i points to the place a[i-1].

At the beginning of the game, Hero will take an arbitrary number of tokens between 0 and N, inclusive, and he will place them onto distinct places.
He will then play K rounds of the game.
In each round each token moves from its current place along the arrow to the new place.
After each round, Hero checks whether all tokens are still in distinct places.
If two or more tokens are in the same place, Hero loses the game.
Hero wins the game if he does not lose it during the K rounds he plays.

There may be multiple ways how Hero can win the game.
Two ways are different if there is some i such that at the beginning of the game place i did contain a token in one case but not in the other.
Count those ways and return their count modulo 1,000,000,007.


DEFINITION
Class:Autogame
Method:wayscnt
Parameters:vector <int>, int
Returns:int
Method signature:int wayscnt(vector <int> a, int K)


CONSTRAINTS
-a will contain exactly N elements.
-N will be between 1 and 50, inclusive.
-Each element in a will be between 1 and N, inclusive.
-K will be between 1 and 1,000,000,000, inclusive.


EXAMPLES

0)
{1,2,3}
5

Returns: 8

There are 2^3 = 8 valid ways to place the tokens. In each round each token will stay in the same place. Hence, Hero will win the game for each initial placement of tokens.

1)
{1,1,1}
1

Returns: 4

If Hero starts the game with two or three tokens, after the first round there will be multiple tokens in the same place (place 1) and Hero will lose the game. He will only win the game if he starts with 0 tokens (1 possibility) or with 1 token (3 possibilities).

2)
{2,1}	
42

Returns: 4



3)
{2,3,4,3}
3

Returns: 9



4)
{4,4,3,2,1}
3

Returns: 18



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
		cout << "Testing Autogame (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1428768767;
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
		Autogame _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int a[] = {1,2,3};
				int K = 5;
				_expected = 8;
				_received = _obj.wayscnt(vector <int>(a, a+sizeof(a)/sizeof(int)), K); break;
			}
			case 1:
			{
				int a[] = {1,1,1};
				int K = 1;
				_expected = 4;
				_received = _obj.wayscnt(vector <int>(a, a+sizeof(a)/sizeof(int)), K); break;
			}
			case 2:
			{
				int a[] = {2,1}	;
				int K = 42;
				_expected = 4;
				_received = _obj.wayscnt(vector <int>(a, a+sizeof(a)/sizeof(int)), K); break;
			}
			case 3:
			{
				int a[] = {2,3,4,3};
				int K = 3;
				_expected = 9;
				_received = _obj.wayscnt(vector <int>(a, a+sizeof(a)/sizeof(int)), K); break;
			}
			case 4:
			{
				int a[] = {4,4,3,2,1};
				int K = 3;
				_expected = 18;
				_received = _obj.wayscnt(vector <int>(a, a+sizeof(a)/sizeof(int)), K); break;
			}
			/*case 5:
			{
				int a[] = ;
				int K = ;
				_expected = ;
				_received = _obj.wayscnt(vector <int>(a, a+sizeof(a)/sizeof(int)), K); break;
			}*/
			/*case 6:
			{
				int a[] = ;
				int K = ;
				_expected = ;
				_received = _obj.wayscnt(vector <int>(a, a+sizeof(a)/sizeof(int)), K); break;
			}*/
			/*case 7:
			{
				int a[] = ;
				int K = ;
				_expected = ;
				_received = _obj.wayscnt(vector <int>(a, a+sizeof(a)/sizeof(int)), K); break;
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
