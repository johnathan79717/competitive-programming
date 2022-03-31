#line 2 "EllysBalancedStrings.cpp"
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

class EllysBalancedStrings {
public:
    int getMin(string S) {
	VI cs;
	for (char ch : S) {
	    switch (ch) {
		case 'A':
		case 'E':
		case 'I':
		case 'O':
		case 'U':
		    break;
		default:
		    int m = MOD;
		    for (char x : "AEIOU") {
			m = min(m, abs(x - ch));
		    }
		    cs.PB(m);
		    break;
	    }
	}
	int c = cs.size(), v = S.size() - c;
	if (v >= c)
	    return (v - c) / 2;
	sort(ALL(cs));
	int ans = 0;
	REP(i, (c-v)/2) {
	    ans += cs[i];
	}
	return ans;
    }
};

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
In the English alphabet the letters {'A', 'E', 'I', 'O', 'U'} are called vowels while all others are called consonants.
Note that in this problem 'Y' is always a consonant.


A string is balanced if the number of vowels in the string is the same as the number of consonants in the string.


For example, the string "BANANA" is balanced: it has three consonants ('B' and two 'N') and three vowels (three 'A').
The string "TOPCODER" is not balanced: it has five consonants but only three vowels.



Elly has a string S. The length of S is even.


The girl can alter her string as many times as she likes. In each operation she chooses one valid index i and either increments or decrements the letter S[i].


Incrementing a letter changes it to the next letter in the alphabet (e.g., 'A' to 'B', 'L' to 'M', and 'Y' to 'Z').
Decrementing a letter changes it to the previous letter in the alphabet (e.g., 'B' to 'A', 'M' to 'L', and 'Z' to 'Y').
The letter 'A' cannot be decremented and the letter 'Z' cannot be incremented.


Multiple operations may be applied to the same index.
Thus, S can be transformed into any other string of the same length.



Elly wonders what is the minimal number of operations she has to do on S in order to make it balanced.
Find and return that number.



DEFINITION
Class:EllysBalancedStrings
Method:getMin
Parameters:string
Returns:int
Method signature:int getMin(string S)


CONSTRAINTS
-S will contain between 2 and 100 characters, inclusive.
-S will contain an even number of characters.
-Each character in S will be an uppercase letter of the English alphabet ({'A'-'Z'}).


EXAMPLES

0)
"TOPCODER"

Returns: 1

We can convert "TOPCODER" to "TOOCODER" in a single operation. After that transformation, it has 4 vowels (three 'O's and one 'E') and 4 consonants ('T', 'C', 'D', and 'R').

1)
"BANANA"

Returns: 0

"BANANA" already has equal number of vowels and consonants.

2)
"WITHOUTITIAMJUSTESPR"

Returns: 2



3)
"NOZAPHODJUSTVERYVERYIMPROBABLE"

Returns: 5



4)
"SYZYGY"

Returns: 8

In astronomy, a syzygy is a roughly straight-line configuration of three or more celestial bodies in a gravitational system. Please note that although the letter 'Y' is sometimes considered a vowel, in this task it is always a consonant.
In this example, one optimal solution is to produce the balanced string "UUZYEY" in 2 + 4 + 0 + 0 + 2 + 0 = 8 operations.

5)
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"

Returns: 8



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
		cout << "Testing EllysBalancedStrings (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1618675504;
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
		EllysBalancedStrings _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string S = "TOPCODER";
				_expected = 1;
				_received = _obj.getMin(S); break;
			}
			case 1:
			{
				string S = "BANANA";
				_expected = 0;
				_received = _obj.getMin(S); break;
			}
			case 2:
			{
				string S = "WITHOUTITIAMJUSTESPR";
				_expected = 2;
				_received = _obj.getMin(S); break;
			}
			case 3:
			{
				string S = "NOZAPHODJUSTVERYVERYIMPROBABLE";
				_expected = 5;
				_received = _obj.getMin(S); break;
			}
			case 4:
			{
				string S = "SYZYGY";
				_expected = 8;
				_received = _obj.getMin(S); break;
			}
			case 5:
			{
				string S = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
				_expected = 8;
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
