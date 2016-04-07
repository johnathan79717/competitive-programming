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
typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;

class BalancedSubstrings {
    public:
    int countSubstrings(string s) {
        int N = s.size();
        int ans = 0;
        REP(i, N) {
            int cnt = 0;
            int tor = 0;
            REP1(j, i, N-1) {
                if (s[j] == '1') {
                    cnt++;
                    tor += j - i;
                }
                if (cnt == 0 || tor % cnt == 0) {
                   // cout << i << ' ' << j << ' ' << cnt << ' ' << tor << endl;
                    ans++;
                }
            }
        }
        return ans;
    }
};
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
This problem deals with binary strings: strings in which each character is either '0' or '1'.
The characters are interpreted as zeros and ones.



Assume that we have a binary string of length N.
Imagine the string as a horizontal lever of length N-1.
The weight of the lever is negligible.
On the lever, the points with integer coordinates are numbered from 0 (one end of the lever) to N-1 (the other end).
Our string represents the distribution of weights on this lever.
For each i, if character i of our string is '0', the corresponding point is empty, and if the character is '1', there is a unit weight at that point.
Suppose that we place a fulcrum under the point number i.
We say that element i of the string is a balance point if the lever is balanced on the fulcrum: the moments of force on either side cancel each other out.
A string is called a balanced string if it has at least one balance point.
Note that the balance point must be one of the marked points (see examples below).



A formal definition follows.
For each valid index i we can compute the torque at i as follows:

For each element to the left of i, take its value, multiply it by its distance from i, and add all those results together to obtain the value A.
For each element to the right of i, take its value, multiply it by its distance from i, and add all those results together to obtain the value B.
The torque at i is computed as (A - B).

We say that index i is a balance point if the torque at i is exactly zero.
(Note that the value of the element at index i isn't used in the definition and therefore it can be arbitrary.)



For example, the string "10100001" is a balanced string.
Its balance point is the (0-based) index i=3.
If we put the fulcrum under the lever at this position, we see "101" to the left and "0001" to the right.
On the left side we get A = 1*3 + 0*2 + 1*1 = 4, and on the right side we get B = 0*1 + 0*2 + 0*3 + 1*4 = 4, hence A-B is exactly zero.



The string "0001" is also a balanced string, as its last character is a balance point.
The string "11" is not a balanced string, as neither of its two characters is a balance point.



You are given a string s that is a binary string.
Return the number of nonempty substrings of s that are balanced.



Substrings that consist of the same characters but occur elsewhere in s are considered different substrings.
If they are balanced, each of them should be counted separately.
For example, the string "00000" contains four distinct occurrences of the substring "00".


DEFINITION
Class:BalancedSubstrings
Method:countSubstrings
Parameters:string
Returns:int
Method signature:int countSubstrings(string s)


CONSTRAINTS
-s will have between 1 and 2,500 characters, inclusive.
-Each character in s will be '0' or '1'.


EXAMPLES

0)
"011"

Returns: 4

The balanced substrings in this case are {"0", "1", "1", "01"}

1)
"10111"

Returns: 10

The balanced substrings are {"1", "0", "1", "1", "1", "10", "01", "101", "111", "0111"}

2)
"00000"

Returns: 15

All substrings in this case are balanced.

3)
"0000001000000"

Returns: 91



4)
"100110001001"

Returns: 49



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
		cout << "Testing BalancedSubstrings (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1440225009;
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
		BalancedSubstrings _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string s = "011";
				_expected = 4;
				_received = _obj.countSubstrings(s); break;
			}
			case 1:
			{
				string s = "10111";
				_expected = 10;
				_received = _obj.countSubstrings(s); break;
			}
			case 2:
			{
				string s = "00000";
				_expected = 15;
				_received = _obj.countSubstrings(s); break;
			}
			case 3:
			{
				string s = "0000001000000";
				_expected = 91;
				_received = _obj.countSubstrings(s); break;
			}
			case 4:
			{
				string s = "100110001001";
				_expected = 49;
				_received = _obj.countSubstrings(s); break;
			}
			/*case 5:
			{
				string s = ;
				_expected = ;
				_received = _obj.countSubstrings(s); break;
			}*/
			/*case 6:
			{
				string s = ;
				_expected = ;
				_received = _obj.countSubstrings(s); break;
			}*/
			/*case 7:
			{
				string s = ;
				_expected = ;
				_received = _obj.countSubstrings(s); break;
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
