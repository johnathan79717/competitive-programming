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
#line 39 "Bracket107.cpp"
#include <string>
#include <vector>
class Bracket107 {
	public:
	int yetanother(string s) {
		
	}
};
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Correct bracket sequences are strings in which each character is a '(' or a ')', the total number of opening brackets is the same as the total number of closing brackets, and each prefix contains at least as many opening as closing brackets.
For example, the shortest few correct bracket sequences are "", "()", "(())", and "()()".

The subsequence of a string S is any string that can be obtained by erasing zero or more characters of S.
For example, each of the strings "", "ace", and "abcde" is a subsequence of "abcde".

We will use LCS(S,T) to denote the length of a longest common subsequence of strings S and T.
In other words, LCS(S,T) is the largest k such that there is a string U of length k that is both a subsequence of S and a subsequence of T.
For example, LCS("abcde","bad") = 2.

You are given a string s that contains a correct bracket sequence.
You are looking for a string t with the following properties:

t will have the same length as s,
t will be a correct bracket sequence,
t will not be equal to s,
LCS(s,t) will be as large as possible.

Compute and return the number of strings with these properties.

DEFINITION
Class:Bracket107
Method:yetanother
Parameters:string
Returns:int
Method signature:int yetanother(string s)


NOTES
-You may assume that the answer for each valid test case fits into a signed 32-bit integer variable.


CONSTRAINTS
-s will contain between 4 and 50 characters, inclusive.
-Each character in s will be either '(' or ')'.
-s will be a correct bracket sequence.


EXAMPLES

0)
"(())"

Returns: 1

There is only one other correct bracket sequence of the same length.

1)
"(())()"

Returns: 3

There are four other correct bracket sequences of the same length: "((()))", "()(())", "()()()", and "(()())".
However, only in three of those four cases the length of the longest common subsequence is 5.
LCS( "(())()", "()(())" ) is only 4, therefore "()(())" is not a valid choice of the string t.

2)
"()()()"

Returns: 3



3)
"(((())))"

Returns: 5



4)
"((())())"

Returns: 9



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
		cout << "Testing Bracket107 (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1444535722;
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
		Bracket107 _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string s = "(())";
				_expected = 1;
				_received = _obj.yetanother(s); break;
			}
			case 1:
			{
				string s = "(())()";
				_expected = 3;
				_received = _obj.yetanother(s); break;
			}
			case 2:
			{
				string s = "()()()";
				_expected = 3;
				_received = _obj.yetanother(s); break;
			}
			case 3:
			{
				string s = "(((())))";
				_expected = 5;
				_received = _obj.yetanother(s); break;
			}
			case 4:
			{
				string s = "((())())";
				_expected = 9;
				_received = _obj.yetanother(s); break;
			}
			/*case 5:
			{
				string s = ;
				_expected = ;
				_received = _obj.yetanother(s); break;
			}*/
			/*case 6:
			{
				string s = ;
				_expected = ;
				_received = _obj.yetanother(s); break;
			}*/
			/*case 7:
			{
				string s = ;
				_expected = ;
				_received = _obj.yetanother(s); break;
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
