#include <string>
#include <cassert>
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
#define PER(i,n) for(int i=(n)-1;i>=0;i--)
#define MS0(x) memset(x,0,sizeof(x))

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;
// #line 40 "BracketSequenceDiv1.cpp"
#include <string>
#include <vector>

LL dp[21][1<<20];

class BracketSequenceDiv1 {
public:
    long long count(string s) {
        int N = s.size();
        dp[0][0] = 1;
        REP(i, N) {
            if (s[i] == '(' || s[i] == '[') {
                PER(l, i+1) {
                    if (l > N-i) continue;
                    if (l == 20) continue;
                    REP(j, 1<<l) {
                        if (dp[l][j]) {
                            if (s[i] == '(') {
                                dp[l+1][j*2] += dp[l][j];
                            } else if (s[i] == '[') {
                                dp[l+1][j*2+1] += dp[l][j];
                            }
                        }
                    }
                }
            } else {
                REP(l, i+1) {
                    if (l > N-i) continue;
                    if (l == 0) continue;
                    REP(j, 1<<l) {
                       if (dp[l][j]) { 
                            if ((s[i] == ')' && j % 2 == 0) || (s[i] == ']' && j % 2 == 1)) {
                                dp[l-1][j/2] += dp[l][j];
                            }
                        }
                    }
                }
            }
        }
        return dp[0][0] - 1;
    }
};
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
Correct bracket sequences can be defined recursively as follows:

The empty string "" is a correct sequence.
If "X" and "Y" are correct sequences, then "XY" (the concatenation of X and Y) is a correct sequence.
If "X" is a correct sequence, then "(X)" and "[X]" are also correct sequences.
Each correct bracket sequence can be derived using the above rules.



Examples of correct bracket sequences include "", "()", "()[][]", "([]())", and "([[()]])".


You are given a string s that only contains the characters '(', ')', '[', and ']'.
We want to erase some subset of characters of s (possibly none of them, but not all of them).
Moreover, we want to do it in such a way that the resulting string will be a correct non-empty bracket sequence.
Compute and return the number of ways in which this can be done.


DEFINITION
Class:BracketSequenceDiv1
Method:count
Parameters:string
Returns:long long
Method signature:long long count(string s)


CONSTRAINTS
-s will contain between 1 and 40 characters, inclusive.
-Each character in s will be one of '(', ')', '[', ']'.


EXAMPLES

0)
"()[]"

Returns: 3

There are 3 valid ways to erase some characters and obtain a correct non-empty bracket sequence:

Erase nothing and obtain "()[]".
Erase the first two characters and obtain "[]".
Erase the last two characters and obtain "()".


1)
"())"

Returns: 2

Here we have 2 solutions: we can either erase the middle character or the last character.
Note that we count each of those ways separately, even though in both cases we get the same string "()".

2)
"()()"

Returns: 4



3)
"([)]"

Returns: 2



4)
"())[]][]([]()]]()]]]"

Returns: 3854



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
		cout << "Testing BracketSequenceDiv1 (300.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1459215473;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 300.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		BracketSequenceDiv1 _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string s = "()[]";
				_expected = 3LL;
				_received = _obj.count(s); break;
			}
			case 1:
			{
				string s = "())";
				_expected = 2LL;
				_received = _obj.count(s); break;
			}
			case 2:
			{
				string s = "()()";
				_expected = 4LL;
				_received = _obj.count(s); break;
			}
			case 3:
			{
				string s = "([)]";
				_expected = 2LL;
				_received = _obj.count(s); break;
			}
			case 4:
			{
				string s = "())[]][]([]()]]()]]]";
				_expected = 3854LL;
				_received = _obj.count(s); break;
			}
			/*case 5:
			{
				string s = ;
				_expected = LL;
				_received = _obj.count(s); break;
			}*/
			/*case 6:
			{
				string s = ;
				_expected = LL;
				_received = _obj.count(s); break;
			}*/
			/*case 7:
			{
				string s = ;
				_expected = LL;
				_received = _obj.count(s); break;
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
