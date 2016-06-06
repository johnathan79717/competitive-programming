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
// #line 40 "ShortPalindromes.cpp"
#include <string>
#include <vector>
class ShortPalindromes {
public:
    string s;
    string shortest(string base) {
        int N = base.size();
        s = base;
        return solve(0, N-1);
    }
    map<pair<int,int>,string> dp;
    string solve(int l, int r) {
        if (l > r) return "";
        if (l == r) return string(1, s[l]);
        if (dp.count(MP(l,r))) return dp[MP(l,r)];
        if (s[l] == s[r]) {
            return dp[MP(l,r)] = s[l] + solve(l+1, r-1) + s[r];
        }
        string a = s[l] + solve(l+1, r) + s[l];
        string b = s[r] + solve(l, r-1) + s[r]; 
        if (a.size() < b.size()) return dp[MP(l,r)] = a;
        if (a.size() > b.size()) return dp[MP(l,r)] = b;
        return dp[MP(l,r)] = min(a, b);
    }
};
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
A palindrome is a string that is spelled the same forward and backwards.  Given a string 
base that may or may not be a palindrome, we can always force base to be a palindrome by adding
letters to it.  For example, given the word "RACE", we could add the letters "CAR" to its back to get "RACECAR" (quotes for clarity only).  However, we are not restricted to adding letters at the back.  For example, we
could also add the letters "ECA" to the front to get "ECARACE".  In fact, we can add letters anywhere in the word, so we 
could also get "ERCACRE" by adding an 'E' at the beginning, a 'C' after the 'R', and another 'R' before the final 'E'. 
Your task is to make base into a palindrome by adding as few letters 
as possible and return the resulting string.  When there is more than one palindrome of minimal length that can be made, return the lexicographically earliest (that is, the one that occurs first in alphabetical order).




DEFINITION
Class:ShortPalindromes
Method:shortest
Parameters:string
Returns:string
Method signature:string shortest(string base)


CONSTRAINTS
-base contains between 1 and 25 characters, inclusive.
-Every character in base is an uppercase letter ('A'-'Z').


EXAMPLES

0)
"RACE"

Returns: "ECARACE"

To make "RACE" into a palindrome, we must add at least three letters.  However, there are
eight ways to do this by adding exactly three letters:

    "ECARACE"  "ECRARCE"  "ERACARE"  "ERCACRE"
    "RACECAR"  "RAECEAR"  "REACAER"  "RECACER"

Of these alternatives, "ECARACE" is the lexicographically earliest.


1)
"TOPCODER"

Returns: "REDTOCPCOTDER"

2)
"Q"

Returns: "Q"

3)
"MADAMIMADAM"

Returns: "MADAMIMADAM"

4)
"ALRCAGOEUAOEURGCOEUOOIGFA"

Returns: "AFLRCAGIOEOUAEOCEGRURGECOEAUOEOIGACRLFA"

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
		cout << "Testing ShortPalindromes (1150.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1463318802;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 1150.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		ShortPalindromes _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string base = "RACE";
				_expected = "ECARACE";
				_received = _obj.shortest(base); break;
			}
			case 1:
			{
				string base = "TOPCODER";
				_expected = "REDTOCPCOTDER";
				_received = _obj.shortest(base); break;
			}
			case 2:
			{
				string base = "Q";
				_expected = "Q";
				_received = _obj.shortest(base); break;
			}
			case 3:
			{
				string base = "MADAMIMADAM";
				_expected = "MADAMIMADAM";
				_received = _obj.shortest(base); break;
			}
			case 4:
			{
				string base = "ALRCAGOEUAOEURGCOEUOOIGFA";
				_expected = "AFLRCAGIOEOUAEOCEGRURGECOEAUOEOIGACRLFA";
				_received = _obj.shortest(base); break;
			}
			/*case 5:
			{
				string base = ;
				_expected = ;
				_received = _obj.shortest(base); break;
			}*/
			/*case 6:
			{
				string base = ;
				_expected = ;
				_received = _obj.shortest(base); break;
			}*/
			/*case 7:
			{
				string base = ;
				_expected = ;
				_received = _obj.shortest(base); break;
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
