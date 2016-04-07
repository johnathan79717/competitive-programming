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
#define FOR(i, c) for(auto &i: c)
#define ALL(x) (x).begin(),(x).end()
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define PER(i,n) for(int i=(n)-1;i>=0;i--)
#define PER1(i,a,b) for(int i=(a);i>=(b);i--)
#define MP make_pair
#define PB push_back
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,-1,sizeof(x))
#define V(T) vector<T >
#define EB emplace_back
 
typedef long long LL;

struct FarStrings {
  vector <string> find(string t) {

  }
};

// BEGIN CUT HERE
/*
PROBLEM STATEMENT
All strings in this problem are strings of lowercase 
English letters ('a'-'z').


Given two strings S and T, their edit distance is defined 
as the smallest number of steps in which we can change S 
to T.
In each step, we are allowed to make one of the following 
changes:

Erasing one arbitrary character of S.
Inserting one arbitrary character anywhere into S 
(including its beginning or end).
Replacing one arbitrary character of S by a different 
character.


For example:

The edit distance between "color" and "coord" is 2.
The edit distance between "banana" and "bnn" is 3.
The edit distance between "aaaa" and "bbbb" is 4.


You are given a string t.
Let n be the length of t.
Return a vector <string> with n elements.
For each i, element i (0-based index) of the returned 
vector <string> must be the lexicographically smallest 
string with n characters such that the edit distance 
between t and the string is exactly i+1.


DEFINITION
Class:FarStrings
Method:find
Parameters:string
Returns:vector <string>
Method signature:vector <string> find(string t)


NOTES
-You may assume that for each valid test case there is at 
least one n-character string with each of the required 
edit distances.


CONSTRAINTS
-t will contain between 1 and 25 characters, inclusive.
-Each character in t will be a lowercase English letter 
('a'-'z').


EXAMPLES

0)
"atan"

Returns: {"aaan", "aaaa", "aaba", "babb" }

Let d(s,u) denote the edit distance between the strings s 
and u. The return value shown above is correct because:

d("atan", "aaan") = 1: we can change 't' to 'a'.
d("atan", "aaaa") = 2: we can change 't' to 'a' and then 
'n' to 'a'.
d("atan", "aaba") = 3: one shortest sequence of changes is 
"atan" -> "aan" -> "aab" -> "aaba".
d("atan", "babb") = 4: one shortest sequence of changes is 
"atan" -> "aan" -> "ban" -> "bab" -> "babb".
The strings "aaan", "aaaa", "aaba", and "babb" are the 
lexicographically smallest strings with the given edit 
distance from "atan".


1)
"ir"

Returns: {"ar", "aa" }



2)
"aaa"

Returns: {"aab", "abb", "bbb" }



3)
"bazinga"

Returns: {"aazinga", "aaainga", "aaaanga", "aaaaaga", 
"aaaaaaa", "aaaaaab", "abbaabb" }



4)
"bcdab"

Returns: {"acdab", "aadab", "aaaab", "aaaaa", "aaaca" }



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
		cout << "Testing FarStrings (800.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1398082722;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 800.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		FarStrings _obj;
		vector <string> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string t = "atan";
				string __expected[] = {"aaan", "aaaa", "aaba", "babb" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.find(t); break;
			}
			case 1:
			{
				string t = "ir";
				string __expected[] = {"ar", "aa" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.find(t); break;
			}
			case 2:
			{
				string t = "aaa";
				string __expected[] = {"aab", "abb", "bbb" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.find(t); break;
			}
			case 3:
			{
				string t = "bazinga";
				string __expected[] = {"aazinga", "aaainga", "aaaanga", "aaaaaga", "aaaaaaa", "aaaaaab", "abbaabb" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.find(t); break;
			}
			case 4:
			{
				string t = "bcdab";
				string __expected[] = {"acdab", "aadab", "aaaab", "aaaaa", "aaaca" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.find(t); break;
			}
			/*case 5:
			{
				string t = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.find(t); break;
			}*/
			/*case 6:
			{
				string t = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.find(t); break;
			}*/
			/*case 7:
			{
				string t = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.find(t); break;
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
				cout << " \"" << _expected[i] << "\"";
			}
			cout << " }" << endl;
			cout << "           Received: {";
			for (unsigned i = 0; i < _received.size(); i++)
			{
				if (i) cout << ",";
				cout << " \"" << _received[i] << "\"";
			}
			cout << " }" << endl;
		}
	}
}

// END CUT HERE
