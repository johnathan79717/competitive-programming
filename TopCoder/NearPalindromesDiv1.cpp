#line 2 "NearPalindromesDiv1.cpp"
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

class NearPalindromesDiv1 {
public:
    int solve(string S) {
	bool f[26] = {};
	for (char c : S) {
	    f[c-'a'] ^= 1;
	}
	auto g = [&f]() {
	    int prev = -1;
	    int s = 0;
	    REP(i, 26) {
		if (f[i]) {
		    //cout << i << endl;
		    if (prev < 0) {
			prev = i;
		    } else {
			s += i - prev;
			prev = -1;
		    }
		}
	    }
	    int s2 = 0;
	    prev = 0;
	    REP(i, 26) {
		if (f[i]) {
		    //cout << i << endl;
		    if (prev < 0) {
			prev = i;
		    } else {
			s2 += i - prev;
			prev = -1;
		    }
		}
	    }
	    return min(s, s2 + 26 - prev);
	};
	if (S.size() % 2 == 0) {
	    return g();
	}
	int ans = MOD;
	REP(i, 26) {
	    if (f[i]) {
		f[i] = false;
		ans = min(ans, g());
		f[i] = true;
	    }
	}
	return ans;
    }
};

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
A string is called a palindrome if it reads the same forwards and backwards. E.g., "a", "noon" and "tacocat" are palindromes but "cocoa" isn't.


A string is called a near-palindrome if we can rearrange its characters to make it a palindrome. For example, "aaa", "cocoa" and "xxyyzz" are near-palindromes but "abc" isn't.



You are given a string S of lowercase English letters.
You are allowed to perform a sequence of operations.
In each operation you can choose an index into S and either increment or decrement the character at that index.
(Incrementing 'a' turns it into 'b', incrementing 'b' gives 'c', ..., and if we increment 'z' we get 'a' again. Decrementing is the inverse operation.)


Determine and return the smallest number of operations needed to turn S into a near-palindrome.


DEFINITION
Class:NearPalindromesDiv1
Method:solve
Parameters:string
Returns:int
Method signature:int solve(string S)


CONSTRAINTS
-S will contain between 1 and 2,500 characters, inclusive.
-Each character of S will be a lowercase English letter ('a'-'z').


EXAMPLES

0)
"cocoa"

Returns: 0

This is already a near-palindrome, no operations are needed.

1)
"daddy"

Returns: 2

One optimal solution is to increment S[4] twice, changing the input string into the near-palindrome "dadda".
(The string "dadda" is a near-palindrome because we can rearrange its letters to get a palindrome. One of the palindromes we can obtain this way is "dadad".)

2)
"abcdefgh"

Returns: 4



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
		cout << "Testing NearPalindromesDiv1 (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1603399575;
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
		NearPalindromesDiv1 _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string S = "cocoa";
				_expected = 0;
				_received = _obj.solve(S); break;
			}
			case 1:
			{
				string S = "daddy";
				_expected = 2;
				_received = _obj.solve(S); break;
			}
			case 2:
			{
				string S = "abcdefgh";
				_expected = 4;
				_received = _obj.solve(S); break;
			}
			/*case 3:
			{
				string S = ;
				_expected = ;
				_received = _obj.solve(S); break;
			}*/
			/*case 4:
			{
				string S = ;
				_expected = ;
				_received = _obj.solve(S); break;
			}*/
			/*case 5:
			{
				string S = ;
				_expected = ;
				_received = _obj.solve(S); break;
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
