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
 
typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;

#line 41 "TieForMax.cpp"
#include <string>
#include <vector>

long double dp[51][51][51];
long double C[51][51];

class TieForMax {
public:
    double getProbability(int T, int P) {
	C[0][0] = 1;
	REP1(i, 1, 50) {
	    C[i][0] = 1;
	    REP1(j, 1, i) {
		C[i][j] = C[i-1][j] + C[i-1][j-1];
	    }
	}
	REP1(p, 0, 50)
	REP1(mt, 0, 50) {
	    dp[0][p][mt] = 1;
	}
	long double ans = 0;
	REP1(t, 1, T) {
	    REP1(p, 1, P) {
		REP1(mt, 1, T) {
		    dp[t][p][mt] = dp[t][p][mt-1];
		    if (mt > t) continue;
		    long double x = C[t][mt];
		    REP1(mp, 1, p) {
			if (mt * mp > t) {
			    break;
			}
			long double y = C[p][mp] * x * dp[t - mp*mt][p-mp][mt-1];
			if (t == T && p == P && mp > 1) {
			    //cout << mt << ' ' << mp << ' ' << y << endl;
			    //cout << C[p][mp] << ' ' << x << ' ' << dp[t-mp*mt][p-mp][mt-1] << endl;
			    ans += y;
			}
			dp[t][p][mt] += y;
			x *= C[t - mp*mt][mt];
		    }
		    //if (t == 14 && p == 2) {
			//cout << t << ' ' << p << ' ' << mt << ' ' << dp[t][p][mt] << endl;
		    //}
		}
	    }
	}
	//cerr << dp[14][2][14] << endl;
	//cerr << ans << endl;
	REP(t, T) {
	    ans /= P;
	}
	return ans;
    }
};

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
I have t tokens and p initially empty piles.
One after another, I place each token onto a pile chosen uniformly at random.
(All choices are mutually independent.)


What is the probability that once I'm done, multiple piles will be tied for being the largest?


DEFINITION
Class:TieForMax
Method:getProbability
Parameters:int, int
Returns:double
Method signature:double getProbability(int t, int p)


NOTES
-Your return value must have an absolute error at most 1e-9.


CONSTRAINTS
-t will be between 1 and 50, inclusive.
-p will be between 1 and 50, inclusive.


EXAMPLES

0)
7
1

Returns: 0.0

I will make a single pile with seven tokens. With just one pile there can be no ties.

1)
2
2

Returns: 0.5

With probability 50% I will get a unique largest pile with two tokens, and with probability 50% I will get a tie: two piles with one token each.

2)
3
3

Returns: 0.2222222222222222

The tie can only happen if I get three piles with one token on each of them. The probability of that event is 6/27 = 2/9.

3)
6
4

Returns: 0.380859375

Now there are multiple configurations in which the maximum isn't unique. For example, the pile sizes can be {1,2,1,2}, {0,3,3,0}, or even {0,2,2,2}.

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
		cout << "Testing TieForMax (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1547914220;
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
		TieForMax _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int t = 7;
				int p = 1;
				_expected = 0.0;
				_received = _obj.getProbability(t, p); break;
			}
			case 1:
			{
				int t = 2;
				int p = 2;
				_expected = 0.5;
				_received = _obj.getProbability(t, p); break;
			}
			case 2:
			{
				int t = 3;
				int p = 3;
				_expected = 0.2222222222222222;
				_received = _obj.getProbability(t, p); break;
			}
			case 3:
			{
				int t = 6;
				int p = 4;
				_expected = 0.380859375;
				_received = _obj.getProbability(t, p); break;
			}
			case 4:
			{
				int t = 50;
				int p = 3;
				_expected = 0.10878542928411916;
				_received = _obj.getProbability(t, p); break;
			}
			/*case 5:
			{
				int t = ;
				int p = ;
				_expected = ;
				_received = _obj.getProbability(t, p); break;
			}*/
			/*case 6:
			{
				int t = ;
				int p = ;
				_expected = ;
				_received = _obj.getProbability(t, p); break;
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
