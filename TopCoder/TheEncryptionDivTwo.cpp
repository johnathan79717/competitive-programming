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
// #line 40 "TheEncryptionDivTwo.cpp"
#include <string>
#include <vector>
class TheEncryptionDivTwo {
public:
    string encrypt(string message) {
        map<char,char> dict;
        char u = 'a';
        for (char &c: message) {
            if (dict.count(c)) {
                c = dict[c];
            } else {
                dict[c] = u++;
                c = dict[c];
            }
        }
        return message;
    }
};
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
John is obsessed with security.
He is writing a letter to his friend Brus and he wants nobody else to be able to read it.
He uses a simple substitution cipher to encode his message.
Each letter in the message is replaced with its corresponding letter in a substitution alphabet.
A substitution alphabet is a permutation of all the letters in the original alphabet.
In this problem, the alphabet will consist of only lowercase letters ('a'-'z').



For example, if John's message is "hello" and his cipher maps 'h' to 'q', 'e' to 'w', 'l' to 'e' and 'o' to 'r', the encoded message will be "qweer".
If the cipher maps 'h' to 'a', 'e' to 'b', 'l' to 'c' and 'o' to 'd', then the encoded message will be "abccd".



Given the original message, determine the cipher that will produce the encoded string that comes earliest alphabetically.
Return this encoded string.
In the example above, the second cipher produces the alphabetically earliest encoded string ("abccd").



DEFINITION
Class:TheEncryptionDivTwo
Method:encrypt
Parameters:string
Returns:string
Method signature:string encrypt(string message)


NOTES
-If A and B are two strings of the same length, then A comes earlier alphabetically than B if it contains a smaller character at the first position where the strings differ.


CONSTRAINTS
-message will contain between 1 and 50 characters, inclusive.
-message will contain only lowercase letters ('a'-'z').


EXAMPLES

0)
"hello"

Returns: "abccd"

The example from the statement.

1)
"abcd"

Returns: "abcd"

Here the message is encoded to itself.

2)
"topcoder"

Returns: "abcdbefg"

3)
"encryption"

Returns: "abcdefghib"

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
		cout << "Testing TheEncryptionDivTwo (300.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1463326795;
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
		TheEncryptionDivTwo _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string message = "hello";
				_expected = "abccd";
				_received = _obj.encrypt(message); break;
			}
			case 1:
			{
				string message = "abcd";
				_expected = "abcd";
				_received = _obj.encrypt(message); break;
			}
			case 2:
			{
				string message = "topcoder";
				_expected = "abcdbefg";
				_received = _obj.encrypt(message); break;
			}
			case 3:
			{
				string message = "encryption";
				_expected = "abcdefghib";
				_received = _obj.encrypt(message); break;
			}
			/*case 4:
			{
				string message = ;
				_expected = ;
				_received = _obj.encrypt(message); break;
			}*/
			/*case 5:
			{
				string message = ;
				_expected = ;
				_received = _obj.encrypt(message); break;
			}*/
			/*case 6:
			{
				string message = ;
				_expected = ;
				_received = _obj.encrypt(message); break;
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
