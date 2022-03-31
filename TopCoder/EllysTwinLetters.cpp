#line 2 "EllysTwinLetters.cpp"
#include <string>
#include <vector>
#include <climits>
#include <cstring>
#include <map>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <cassert>
#include <deque>
#include <stack>
#include <functional>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define FOR(I, A, B) for (int I = (A); I <= (B); ++I)
#define FORS(I, S) for (int I = 0; S[I]; ++I)
#define RS(X) scanf("%s", (X))
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define GET_POS(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
#define CASET int ___T; scanf("%d", &___T); for(int cs=1;cs<=___T;cs++)
#define MP make_pair
#define PB emplace_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define F first
#define S second
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII> VPII;
typedef pair<LL,LL> PLL;
typedef vector<PLL> VPLL;
int MOD = 1e9+7;
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}

class EllysTwinLetters {
public:
    int getMin(string S) {
	int N = S.size();
	VI dp(N+1, MOD);
	dp[0] = 0;
	REPP(i, 1, N) {
	    REP(j, i) {
		string p = S.substr(j, i-j+1);
		sort(ALL(p));
		int cost = 0;
		char m = p[SZ(p) / 2];
		for (char c : p) {
		    cost += abs(c - m);
		}
		dp[i+1] = min(dp[i+1], dp[j] + cost);
	    }
	}
	return dp[N];
    }
};

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
We say that a letter in a string has a twin if it has the same letter immediately to its left or immediately to its right (or both).


For example, in the string "AARDVARK" each of the first two 'A' has a twin (but the third 'A' does not) and in the string "FLUSSSAND" each of the three 'S' has a twin.



Elly has a string S containing at least two characters.


The girl can alter her string as many times as she likes. 
In each operation she chooses one valid index i and either increments or decrements the letter S[i].


Incrementing a letter changes it to the next letter in the alphabet (e.g., 'A' to 'B', 'L' to 'M', and 'Y' to 'Z').
Decrementing a letter changes it to the previous letter in the alphabet (e.g., 'B' to 'A', 'M' to 'L', and 'Z' to 'Y').
The letter 'A' cannot be decremented and the letter 'Z' cannot be incremented.


Multiple operations may be applied to the same index.
Thus, S can be transformed into any other string of the same length.



Elly wants to alter her S into a string in which each letter has a twin.
Please find and return the minimal number of operations needed.


DEFINITION
Class:EllysTwinLetters
Method:getMin
Parameters:string
Returns:int
Method signature:int getMin(string S)


CONSTRAINTS
-S will contain between 2 and 100 characters, inclusive.
-Each character of S will be an uppercase letter of the English alphabet ({'A'-'Z'}).


EXAMPLES

0)
"TOPCODER"

Returns: 30


Some of the strings we can produce from the string "TOPCODER" are:

"TTPPOOEE" in 0 + 5 + 0 + 13 + 0 + 11 + 0 + 13 = 42 operations;
"PPPEEEEE" in 4 + 1 + 0 + 2 + 10 + 1 + 0 + 13 = 31 operations;
"OOOOOOOO" in 5 + 0 + 1 + 12 + 0 + 11 + 10 + 3 = 42 operations;
"SSEEEKKK" in 1 + 4 + 11 + 2 + 10 + 7 + 6 + 7 = 48  operations;
"PPPDDDLL" in 4 + 1 + 0 + 1 + 11 + 0 + 7 + 6 = 30 operations;
"GGLLHHFF" in 13 + 8 + 4 + 9 + 7 + 4 + 1 + 12 = 58 operations.

Out of the options above, the transformation into "PPPDDDLL" is the one with the fewest operations: 30.
As it turns out, this answer is optimal: there is no solution with fewer operations for the string "TOPCODER".
(There are other optimal solutions that also require exactly 30 operations but produce a different string.)


1)
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"

Returns: 13

Each letter on an even position (counting from zero) can be incremented, achieving "BBDDFFHHJJLLNNPPRRTTVVXXZZ". We have incremented once 13 letters, thus the number of operations we have used is 13. This is the minimal number of operations for this test.

2)
"ESPRIT"

Returns: 25



3)
"WITHOUTITIMJUSTESPR"

Returns: 54



4)
"NOZAPHODJUSTVERYVERYIMPROBABLE"

Returns: 93



5)
"FROMALLTHETHINGSIVELOSTMYMINDIMISSTHEMOST"

Returns: 111



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
		cout << "Testing EllysTwinLetters (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1618675964;
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
		EllysTwinLetters _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string S = "TOPCODER";
				_expected = 30;
				_received = _obj.getMin(S); break;
			}
			case 1:
			{
				string S = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
				_expected = 13;
				_received = _obj.getMin(S); break;
			}
			case 2:
			{
				string S = "ESPRIT";
				_expected = 25;
				_received = _obj.getMin(S); break;
			}
			case 3:
			{
				string S = "WITHOUTITIMJUSTESPR";
				_expected = 54;
				_received = _obj.getMin(S); break;
			}
			case 4:
			{
				string S = "NOZAPHODJUSTVERYVERYIMPROBABLE";
				_expected = 93;
				_received = _obj.getMin(S); break;
			}
			case 5:
			{
				string S = "FROMALLTHETHINGSIVELOSTMYMINDIMISSTHEMOST";
				_expected = 111;
				_received = _obj.getMin(S); break;
			}
			/*case 6:
			{
				string S = ;
				_expected = ;
				_received = _obj.getMin(S); break;
			}*/
			/*case 7:
			{
				string S = ;
				_expected = ;
				_received = _obj.getMin(S); break;
			}*/
			/*case 8:
			{
				string S = ;
				_expected = ;
				_received = _obj.getMin(S); break;
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
