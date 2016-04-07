#include <cassert>
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
#define MS0(x) memset(x,0,sizeof(x))

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;
#line 39 "BearCries.cpp"
#include <string>
#include <vector>

template<class Short, class Long>
struct ZZ {
    static Short MOD;
    Short i;
    ZZ():i(0) {}
    ZZ(Short i): i(i >= 0 ? i : i + MOD) {}
    ZZ(Long i): i(i % MOD) {}
    void operator +=(const ZZ& z) { i += z.i; if(i >= MOD) i -= MOD; }
    void operator -=(const ZZ& z) { i -= z.i; if(i < 0) i += MOD; }
    void operator *=(const ZZ& z) { i = (Long) i * z.i % MOD; }
    ZZ operator +(const ZZ& z) const { ZZ ret(i); ret += z; return ret; }
    ZZ operator -(const ZZ& z) const { ZZ ret(i); ret -= z; return ret; }
    ZZ operator *(const ZZ& z) const { ZZ ret(i); ret *= z; return ret; }
};

typedef ZZ<int, long long> Z;
template<> int Z::MOD = 1000000007;

Z dp[2][200][200];

class BearCries {
    public:
    int count(string message) {
        int p = 0, n = 1;
        dp[n][0][0] = 1;
        REP(k, message.size()) {
            char c = message[k];
            swap(n, p);
            MS0(dp[n]);
            REP(i, 200) REP(j, 200) {
                if (dp[p][i][j].i) {
                    if (c == '_') {
                        dp[n][i][j] += dp[p][i][j] * i;
                        if (j > 0 && i < 199)
                            dp[n][i+1][j-1] += dp[p][i][j] * j;
                    } else {
                        if (j+1 < 200)
                            dp[n][i][j+1] += dp[p][i][j];
                        if (i-1 >= 0)
                            dp[n][i-1][j] += dp[p][i][j] * i;
                    }
                }
            }
        }
        return dp[n][0][0].i;
    }
};
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Limak is a polar bear who often chats online with his friends.
Nowadays, bears often use emoticons to express their feelings.
In this problem we consider one particular emoticon: the crying emoticon.

A crying emoticon consists of an arbitrary positive number of underscores between two semicolons.
Hence, the shortest possible crying emoticon is ";_;" (quotes for clarity).
The strings ";__;" and ";_____________;" are also valid crying emoticons.

Today Limak is sad, so he sent his friend a sequence of crying emoticons.
However, due to a network malfunction all those emoticons got mixed together into a single string.

You are given a string message containing the message Limak's friend received.
You guess that the message can be divided into one or more crying emoticons.
Each emoticon must be a subsequence of the message, and each character of the message must belong to exactly one emoticon.
Note that the subsequences are not required to be contiguous.

Let X be the number of ways in which one can divide the given message into emoticons.
Compute and return the value (X modulo 1,000,000,007).

DEFINITION
Class:BearCries
Method:count
Parameters:string
Returns:int
Method signature:int count(string message)


CONSTRAINTS
-message will contain between 1 and 200 characters, inclusive.
-Each character in message will be either semicolon or underscore.


EXAMPLES

0)
";_;;_____;"

Returns: 2

There are two ways to divide this string into two crying emoticons.
One looks as follows:

 ;_;
    ;_____;

and the other looks like this:

 ;_ ;
   ; _____;


1)
";;;___;;;"

Returns: 36

This message consists of 3 semicolons, 3 underscores and 3 semicolons again.
Clearly, we have to divide this message into exactly three crying emoticons, each with a single underscore.
There are 36 different ways to do so.

2)
"_;__;"

Returns: 0

As this message begins with an underscore, it clearly cannot be divided into one or more crying emoticons: each crying emoticon starts with a semicolon.

3)
";_____________________________________;"

Returns: 1



4)
";__;____;"

Returns: 0



5)
";_;;__;_;;"

Returns: 52



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
		cout << "Testing BearCries (300.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1444834850;
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
		BearCries _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string message = ";_;;_____;";
				_expected = 2;
				_received = _obj.count(message); break;
			}
			case 1:
			{
				string message = ";;;___;;;";
				_expected = 36;
				_received = _obj.count(message); break;
			}
			case 2:
			{
				string message = "_;__;";
				_expected = 0;
				_received = _obj.count(message); break;
			}
			case 3:
			{
				string message = ";_____________________________________;";
				_expected = 1;
				_received = _obj.count(message); break;
			}
			case 4:
			{
				string message = ";__;____;";
				_expected = 0;
				_received = _obj.count(message); break;
			}
			case 5:
			{
				string message = ";_;;__;_;;";
				_expected = 52;
				_received = _obj.count(message); break;
			}
			/*case 6:
			{
				string message = ;
				_expected = ;
				_received = _obj.count(message); break;
			}*/
			/*case 7:
			{
				string message = ;
				_expected = ;
				_received = _obj.count(message); break;
			}*/
			/*case 8:
			{
				string message = ;
				_expected = ;
				_received = _obj.count(message); break;
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
