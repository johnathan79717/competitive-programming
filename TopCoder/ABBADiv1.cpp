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

class ABBADiv1 {
public:
	string i, t;
	map<PII, bool> mp;
	string get(int l, int r) {
		if (l <= r) {
			return t.substr(l, r - l + 1);
		} else {
			return t.substr(r, l - r + 1);
		}
	}
	bool f(int l, int r) {
		bool ans;
		if (abs(r - l) + 1 < i.size()) {
			ans = false;
		} else if (abs(r - l) + 1 == i.size()) {
			ans = (i == get(l, r));
		} else if (mp.count(MP(l, r))) {
			ans = mp[MP(l, r)];
		} else {
			int d = (r - l) / abs(r - l);
			ans = ((t[r] == 'A' && f(l, r-d)) || (t[l] == 'B' && f(r, l+d)));
		}
		return mp[MP(l, r)] = ans;
	}
	string canObtain(string initial, string target) {
		i = initial, t = target;
		return f(0, target.size()-1) ? "Possible" : "Impossible";
	}
};
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// One day, Jamie noticed that many English words only use the letters A and B.
Examples of such words include "AB" (short for abdominal), "BAA" (the noise a sheep makes), "AA" (a type of lava), and "ABBA" (a Swedish pop sensation).

Inspired by this observation, Jamie created a simple game.
You are given two strings: initial and target.
The goal of the game is to find a sequence of valid moves that will change initial into target.
There are two types of valid moves:

Add the letter A to the end of the string.
Add the letter B to the end of the string and then reverse the entire string. (After the reversal the newly-added B becomes the first character of the string).


Return "Possible" (quotes for clarity) if there is a sequence of valid moves that will change initial into target.
Otherwise, return "Impossible".

DEFINITION
Class:ABBADiv1
Method:canObtain
Parameters:string, string
Returns:string
Method signature:string canObtain(string initial, string target)


CONSTRAINTS
-The length of initial will be between 1 and 49, inclusive.
-The length of target will be between 2 and 50, inclusive.
-target will be longer than initial.
-Each character in initial and each character in target will be either 'A' or 'B'.


EXAMPLES

0)
"A"
"BABA"

Returns: "Possible"

Jamie can perform the following moves:

Initially, the string is "A".
Jamie adds a 'B' to the end of the string and then reverses the string. Now the string is "BA".
Jamie adds a 'B' to the end of the string and then reverses the string. Now the string is "BAB".
Jamie adds an 'A' to the end of the string. Now the string is "BABA".

Since there is a sequence of moves which starts with "A" and creates the string "BABA", the answer is "Possible".

1)
"BAAAAABAA"
"BAABAAAAAB"

Returns: "Possible"

Jamie can add a 'B' to the end of the string and then reverse the string.

2)
"A"
"ABBA"

Returns: "Impossible"



3)
"AAABBAABB"
"BAABAAABAABAABBBAAAAAABBAABBBBBBBABB"

Returns: "Possible"



4)
"AAABAAABB"
"BAABAAABAABAABBBAAAAAABBAABBBBBBBABB"

Returns: "Impossible"



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
		cout << "Testing ABBADiv1 (300.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1437742979;
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
		ABBADiv1 _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string initial = "A";
				string target = "BABA";
				_expected = "Possible";
				_received = _obj.canObtain(initial, target); break;
			}
			case 1:
			{
				string initial = "BAAAAABAA";
				string target = "BAABAAAAAB";
				_expected = "Possible";
				_received = _obj.canObtain(initial, target); break;
			}
			case 2:
			{
				string initial = "A";
				string target = "ABBA";
				_expected = "Impossible";
				_received = _obj.canObtain(initial, target); break;
			}
			case 3:
			{
				string initial = "AAABBAABB";
				string target = "BAABAAABAABAABBBAAAAAABBAABBBBBBBABB";
				_expected = "Possible";
				_received = _obj.canObtain(initial, target); break;
			}
			case 4:
			{
				string initial = "AAABAAABB";
				string target = "BAABAAABAABAABBBAAAAAABBAABBBBBBBABB";
				_expected = "Impossible";
				_received = _obj.canObtain(initial, target); break;
			}
			/*case 5:
			{
				string initial = ;
				string target = ;
				_expected = ;
				_received = _obj.canObtain(initial, target); break;
			}*/
			/*case 6:
			{
				string initial = ;
				string target = ;
				_expected = ;
				_received = _obj.canObtain(initial, target); break;
			}*/
			/*case 7:
			{
				string initial = ;
				string target = ;
				_expected = ;
				_received = _obj.canObtain(initial, target); break;
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
