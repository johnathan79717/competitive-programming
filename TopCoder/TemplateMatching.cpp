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
// #line 40 "TemplateMatching.cpp"
#include <string>
#include <vector>
class TemplateMatching {
public:
    int ps(string t, string prefix) {
        int l1 = t.size(), l2 = prefix.size(), l = min(l1, l2);
        while (true) {
            if (t.substr(0, l) == prefix.substr(l2-l, l)) {
                return l;
            }
            l--;
        }
    }
    string bestMatch(string text, string prefix, string suffix) {
        int N = text.size();
        pair<pair<int,int>,string> ans;
        ans.first.first = INT_MAX;
        for (int i = 0; i < N; i++) {
            for (int j = i; j < N; j++) {
                string t = text.substr(i, j-i+1);
                int p = ps(t, prefix);
                int s = ps(suffix, t);
                ans = min(ans, MP(MP(-p-s, -p), t));
            }
        }
        return ans.second;
    }
};
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// In this problem you will be given a  string text and you will need to find the substring of the text that matches a given template in the best way.
The template will be represented by two strings: prefix and suffix.
Consider a string S. The prefix match score of S with respect to a given template is the maximal n >= 0 such that the first n characters of S are equal to the last n characters of prefix and occur in the same exact order. Analogously, the suffix match score of S is the maximal m >= 0 such that the last m characters of S are equal to the first m characters of suffix and occur in the same exact order.

For example, if S = "something", prefix = "awesome", and suffix = "ingenious", than the prefix score of S is 4 (the matched characters are "some") and the suffix score is 3 (the matched characters are "ing").

The match score of a string S with respect to a given template is the sum of its prefix and suffix match scores. Find the non-empty substring of text with the maximal match score according to the template (prefix, suffix). In case of a tie, return the substring with the maximal prefix score. If there are still several candidates, return one that comes first lexicographically.

DEFINITION
Class:TemplateMatching
Method:bestMatch
Parameters:string, string, string
Returns:string
Method signature:string bestMatch(string text, string prefix, string suffix)


NOTES
-String A comes before string B lexicographically if A is a proper prefix of B, or if A has a smaller character at the first position where the strings differ. When comparing the characters, refer to the following list of characters in ascending order: ' ', 'a', 'b', ..., 'z'.


CONSTRAINTS
-text will contain between 1 and 50 characters, inclusive.
-prefix will contain between 1 and 50 characters, inclusive.
-suffix will contain between 1 and 50 characters, inclusive.
-text, prefix and suffix will contain only lowercase letters ('a'-'z') and spaces (' ').


EXAMPLES

0)
"something"
"awesome"
"ingenious"

Returns: "something"

The example from the problem statement.

1)
"havka"
"eto"
"papstvo"

Returns: "a"

The return value must be non-empty string, so the correct answer is "a".

2)
"abracadabra"
"habrahabr"
"bracket"

Returns: "abrac"



3)
"mississippi"
"promise"
"piccolo"

Returns: "ippi"



4)
"a a a a a a"
"a a"
"a"

Returns: "a a"



5)
"ab"
"b"
"a"

Returns: "b"



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
		cout << "Testing TemplateMatching (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1463327741;
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
		TemplateMatching _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string text = "something";
				string prefix = "awesome";
				string suffix = "ingenious";
				_expected = "something";
				_received = _obj.bestMatch(text, prefix, suffix); break;
			}
			case 1:
			{
				string text = "havka";
				string prefix = "eto";
				string suffix = "papstvo";
				_expected = "a";
				_received = _obj.bestMatch(text, prefix, suffix); break;
			}
			case 2:
			{
				string text = "abracadabra";
				string prefix = "habrahabr";
				string suffix = "bracket";
				_expected = "abrac";
				_received = _obj.bestMatch(text, prefix, suffix); break;
			}
			case 3:
			{
				string text = "mississippi";
				string prefix = "promise";
				string suffix = "piccolo";
				_expected = "ippi";
				_received = _obj.bestMatch(text, prefix, suffix); break;
			}
			case 4:
			{
				string text = "a a a a a a";
				string prefix = "a a";
				string suffix = "a";
				_expected = "a a";
				_received = _obj.bestMatch(text, prefix, suffix); break;
			}
			case 5:
			{
				string text = "ab";
				string prefix = "b";
				string suffix = "a";
				_expected = "b";
				_received = _obj.bestMatch(text, prefix, suffix); break;
			}
			/*case 6:
			{
				string text = ;
				string prefix = ;
				string suffix = ;
				_expected = ;
				_received = _obj.bestMatch(text, prefix, suffix); break;
			}*/
			/*case 7:
			{
				string text = ;
				string prefix = ;
				string suffix = ;
				_expected = ;
				_received = _obj.bestMatch(text, prefix, suffix); break;
			}*/
			/*case 8:
			{
				string text = ;
				string prefix = ;
				string suffix = ;
				_expected = ;
				_received = _obj.bestMatch(text, prefix, suffix); break;
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
