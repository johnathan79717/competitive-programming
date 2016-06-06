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
#define MP make_pair
#define PB push_back

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;
// #line 40 "ParenthesesDiv1Easy.cpp"
#include <string>
#include <vector>
class ParenthesesDiv1Easy {
public:
    vector <int> correct(string s) {
        int N = s.size();
        if (N % 2) {
            return VI(1, -1);
        }        
        int c = 0;
        PII m(0, 0);
        REP(i, N) {
            if (s[i] == '(') {
                c++;
            } else {
                c--;
            }
            m = min(m, MP(c, i+1));
        }
        VI ans;
        if (m.second > 0) {
            ans.PB(0);
            ans.PB(m.second - 1);
        }
        reverse(s.begin(), s.begin() + m.second);
        REP(i, m.second) {
            s[i] ^= ('(' ^ ')');
        }
        c = 0;
        REP(i, N) {
            if (s[i] == '(') {
                c++;
            } else {
                c--;
            }
        }
        if (c == 0) {
            return ans;
        }
        assert(c % 2 == 0);
        int half = c / 2;
        PER(i, N) {
            if (s[i] == '(') {
                c--;
            } else {
                c++;
            }
            if (c == half) {
                ans.PB(i);
                ans.PB(N-1);
                break;
            }
        }
        
        return ans;
    }
};
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Correct parentheses sequences can be defined recursively as follows:

The empty string "" is a correct sequence.
If "X" and "Y" are correct sequences, then "XY" (the concatenation of X and Y) is a correct sequence.
If "X" is a correct sequence, then "(X)" is a correct sequence.
Each correct parentheses sequence can be derived using the above rules.

Examples of correct parentheses sequences include "", "()", "()()()", "(()())", and "(((())))".


You have a string s.
You want to change it into a correct parentheses sequence.



You can only change the string using magic flips.
In order to do a magic flip, you specify two 0-based indices L and R such that L <= R.
The operation modifies the characters on indices from L to R, inclusive.
First, the order of these characters is reversed.
Then, each character is toggled to the opposite one.
That is, each '(' in the specified range changes to a ')' and vice versa.



For example, suppose you have the string "((()".
If you do a magic flip on the entire string (i.e., choosing L=0 and R=3), it first gets reversed to ")(((" and then all parentheses are toggled. Thus, flipping the string "((()" produces the string "()))".



Given s, find and report any sequence of at most 10 magic flips that changes s into a correct parentheses sequence.
If there is no such sequence of magic flips, return the vector <int> {-1}.
If there are multiple such sequences, you may return any of them.
In particular, you are not required to find the shortest possible sequence of flips.
The returned vector <int> should contain 2*F elements, where F is the number of flips you want to perform: 
for each flip, in order, first its L and then its R.

DEFINITION
Class:ParenthesesDiv1Easy
Method:correct
Parameters:string
Returns:vector <int>
Method signature:vector <int> correct(string s)


CONSTRAINTS
-s will contain between 1 and 1,000 characters, inclusive.
-Each character in s will be '(' or ')'.


EXAMPLES

0)
")("

Returns: {0, 0, 1, 1 }

The first flip has L=R=0.
It changes the string to "((".
The second flip has L=R=1.
It changes that string to "()", which is a correct parentheses sequence.

1)
"))))))(((((("

Returns: {0, 5, 6, 11 }

Here, the first flip changes the string to "((((((((((((" and then the second flip changes it to "(((((())))))".

Note that {0,0,1,1,2,2,...,11,11} is not a valid solution.
This sequence of flips produces a correct parentheses sequence (by flipping each character separately).
However, this sequence consists of 12 flips and we are only allowed to perform at most 10 flips.

2)
"))()())()"

Returns: {-1 }

This s has length 9.
There is no correct parentheses sequence of length 9, so there can be no good sequence of flips.

3)
")()((("

Returns: {0, 0, 3, 3, 5, 5 }



4)
"()"

Returns: { }

This time we don't need to do anything.

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
		cout << "Testing ParenthesesDiv1Easy (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1460734491;
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
		ParenthesesDiv1Easy _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string s = ")(";
				int __expected[] = {0, 0, 1, 1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.correct(s); break;
			}
			case 1:
			{
				string s = "))))))((((((";
				int __expected[] = {0, 5, 6, 11 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.correct(s); break;
			}
			case 2:
			{
				string s = "))()())()";
				int __expected[] = {-1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.correct(s); break;
			}
			case 3:
			{
				string s = ")()(((";
				int __expected[] = {0, 0, 3, 3, 5, 5 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.correct(s); break;
			}
			case 4:
			{
				string s = "()";
				int __expected[] = { };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.correct(s); break;
			}
			/*case 5:
			{
				string s = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.correct(s); break;
			}*/
			/*case 6:
			{
				string s = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.correct(s); break;
			}*/
			/*case 7:
			{
				string s = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.correct(s); break;
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
				cout << " " << _expected[i];
			}
			cout << " }" << endl;
			cout << "           Received: {";
			for (unsigned i = 0; i < _received.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _received[i];
			}
			cout << " }" << endl;
		}
	}
}

// END CUT HERE
