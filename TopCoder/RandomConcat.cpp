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
#include <cassert>
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

#line 41 "RandomConcat.cpp"
#include <string>
#include <vector>
class RandomConcat {
public:
    double expectation(vector <string> pieces, string needle) {

    }
};

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
You have several (at most 15) strings in the vector <string> pieces.
You are going to construct a single string called the haystack by shuffling the pieces into a random order and concatenating them.
(Each permutation of pieces is equally likely.)


You also have a string needle.
Compute and return the expected number of occurrences of the needle in the haystack.


DEFINITION
Class:RandomConcat
Method:expectation
Parameters:vector <string>, string
Returns:double
Method signature:double expectation(vector <string> pieces, string needle)


NOTES
-Your return value must have an absolute or a relative error at most 1e-9.


CONSTRAINTS
-pieces will have between 1 and 15 elements, inclusive.
-Each element of pieces will have between 1 and 50 characters, inclusive.
-needle will have between 1 and 50 characters, inclusive.
-Each character in each of the strings will be a lowercase English letter ('a'-'z').


EXAMPLES

0)
{"hahaha"}
"aha"

Returns: 2.0

Haystack will always be "hahaha". This string contains two occurrences of the string "aha". Note that the two occurrences overlap partially.

1)
{"hah","ah"}
"aha"

Returns: 0.5

With probability 1/2 haystack will be "hahah" and there is one occurrence of the substring "aha". With probability 1/2 haystack will be "ahhah" and there are no occurrences of "aha". Hence, the expected number of occurrences is 0.5.

2)
{"t","o","p","c","o","d","e","r"}
"topcoder"

Returns: 4.9603174603174596E-5

Two of the 8! permutations produce the haystack "topcoder" that exactly matches the given needle.

3)
{"hellotopc","oderhellotop","coderbye"}
"topcoder"

Returns: 0.6666666666666666

If we concatenate the pieces in the given order, there will be two occurrences of "topcoder". Two other concatenation orders will produce a haystack with one occurrence of the needle, and the remaining three produce a haystack that contains no needles at all.

4)
{"aabaa","aabaaaaa","aba","goodluck","havefun"}
"aaaa"

Returns: 2.8000000000000016



5)
{"a","a","aa","b"}
"aba"

Returns: 0.5



*/
// END CUT HERE

// BEGIN CUT HERE
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
		cout << "Testing RandomConcat (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1543531163;
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
		RandomConcat _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string pieces[] = {"hahaha"};
				string needle = "aha";
				_expected = 2.0;
				_received = _obj.expectation(vector <string>(pieces, pieces+sizeof(pieces)/sizeof(string)), needle); break;
			}
			case 1:
			{
				string pieces[] = {"hah","ah"};
				string needle = "aha";
				_expected = 0.5;
				_received = _obj.expectation(vector <string>(pieces, pieces+sizeof(pieces)/sizeof(string)), needle); break;
			}
			case 2:
			{
				string pieces[] = {"t","o","p","c","o","d","e","r"};
				string needle = "topcoder";
				_expected = 4.9603174603174596E-5;
				_received = _obj.expectation(vector <string>(pieces, pieces+sizeof(pieces)/sizeof(string)), needle); break;
			}
			case 3:
			{
				string pieces[] = {"hellotopc","oderhellotop","coderbye"};
				string needle = "topcoder";
				_expected = 0.6666666666666666;
				_received = _obj.expectation(vector <string>(pieces, pieces+sizeof(pieces)/sizeof(string)), needle); break;
			}
			case 4:
			{
				string pieces[] = {"aabaa","aabaaaaa","aba","goodluck","havefun"};
				string needle = "aaaa";
				_expected = 2.8000000000000016;
				_received = _obj.expectation(vector <string>(pieces, pieces+sizeof(pieces)/sizeof(string)), needle); break;
			}
			case 5:
			{
				string pieces[] = {"a","a","aa","b"};
				string needle = "aba";
				_expected = 0.5;
				_received = _obj.expectation(vector <string>(pieces, pieces+sizeof(pieces)/sizeof(string)), needle); break;
			}
			/*case 6:
			{
				string pieces[] = ;
				string needle = ;
				_expected = ;
				_received = _obj.expectation(vector <string>(pieces, pieces+sizeof(pieces)/sizeof(string)), needle); break;
			}*/
			/*case 7:
			{
				string pieces[] = ;
				string needle = ;
				_expected = ;
				_received = _obj.expectation(vector <string>(pieces, pieces+sizeof(pieces)/sizeof(string)), needle); break;
			}*/
			/*case 8:
			{
				string pieces[] = ;
				string needle = ;
				_expected = ;
				_received = _obj.expectation(vector <string>(pieces, pieces+sizeof(pieces)/sizeof(string)), needle); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (abs(_expected-_received) < 1e-9 || (_received > min(_expected*(1.0-1e-9), _expected*(1.0+1e-9)) && _received < max(_expected*(1.0-1e-9), _expected*(1.0+1e-9))))
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout.precision(10);
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
