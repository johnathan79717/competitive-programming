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
#line 39 "BearDarts.cpp"
#include <string>
#include <vector>
class BearDarts {
public:
    PII f(int a, int b) {
        int g = __gcd(a, b);
        return pair<int, int>(a / g, b / g);
    }
    long long count(vector <int> w) {
        int N = w.size();
        map<PII, int> s;
        LL ans = 0;
        REP(i, N) {
            REP1(j, i+1, N-1) {
                ans += s[f(w[j], w[i])];
            }
            REP(k, i) {
                s[f(w[k], w[i])]++;
            }
        }
        return ans;
    }
};
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Limak is an old brown bear who likes to play darts.

Limak just picked up an empty scorecard.
He then threw a sequence of darts into a dartboard and for each dart he recorded the point value of the area it hit.
You are given a vector <int> w containing the contents of Limak's scorecard: a sequence of point values.

Today there is a special jackpot.
In order to win the jackpot, the player must present a scorecard with exactly four scores: (a, b, c, d).
Additionally, these scores must be such that a*c = b*d.
Note that order matters: the scores a, b, c, d must have been obtained in this particular order.

Limak wants to erase all but four scores from his scorecard in such a way that he will win the jackpot.
Compute and return the number of different ways in which he can do that.

DEFINITION
Class:BearDarts
Method:count
Parameters:vector <int>
Returns:long long
Method signature:long long count(vector <int> w)


CONSTRAINTS
-w will contain between 4 and 1000 elements, inclusive.
-Each element in w will be between 1 and 10^9, inclusive.


EXAMPLES

0)
{6,8,4,3,6}

Returns: 2

Limak must present a scorecard with four scores, so here he has to erase exactly one of these five scores.
There are two ways to do that and win the jackpot: he can erase either the first throw or the last throw.
If he erases the first throw, he will be left with (a,b,c,d) = (8,4,3,6), and indeed 8*3 = 4*6.
If he erases the last throw, he will be left with (a,b,c,d) = (6,8,4,3), and we have 6*4 = 8*3.

1)
{3,4,12,1}

Returns: 0

Limak cannot erase anything, so the only thing he can try is to present this scorecard without any changes.
However, 3*12 does not equal 4*1, so he won't win the jackpot.

2)
{42,1000000,1000000,42,1000000,1000000}

Returns: 3

In this case there are three valid solutions:

Erase the elements with 0-based indices 4 and 5.
Erase the elements with 0-based indices 1 and 2.
Erase the elements with 0-based indices 0 and 3.


3)
{1,1,1,1,1}

Returns: 5

Here, Limak can erase any single score.
Note that the five ways are considered different, even though they all produce a scorecard with four 1s.

4)
{1,2,3,4,5,6,5,4,3,2,1}

Returns: 22



5)
{33554432, 33554432, 67108864, 134217728}

Returns: 0



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
		cout << "Testing BearDarts (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1444836384;
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
		BearDarts _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int w[] = {6,8,4,3,6};
				_expected = 2LL;
				_received = _obj.count(vector <int>(w, w+sizeof(w)/sizeof(int))); break;
			}
			case 1:
			{
				int w[] = {3,4,12,1};
				_expected = 0LL;
				_received = _obj.count(vector <int>(w, w+sizeof(w)/sizeof(int))); break;
			}
			case 2:
			{
				int w[] = {42,1000000,1000000,42,1000000,1000000};
				_expected = 3LL;
				_received = _obj.count(vector <int>(w, w+sizeof(w)/sizeof(int))); break;
			}
			case 3:
			{
				int w[] = {1,1,1,1,1};
				_expected = 5LL;
				_received = _obj.count(vector <int>(w, w+sizeof(w)/sizeof(int))); break;
			}
			case 4:
			{
				int w[] = {1,2,3,4,5,6,5,4,3,2,1};
				_expected = 22LL;
				_received = _obj.count(vector <int>(w, w+sizeof(w)/sizeof(int))); break;
			}
			case 5:
			{
				int w[] = {33554432, 33554432, 67108864, 134217728};
				_expected = 0LL;
				_received = _obj.count(vector <int>(w, w+sizeof(w)/sizeof(int))); break;
			}
			/*case 6:
			{
				int w[] = ;
				_expected = LL;
				_received = _obj.count(vector <int>(w, w+sizeof(w)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int w[] = ;
				_expected = LL;
				_received = _obj.count(vector <int>(w, w+sizeof(w)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int w[] = ;
				_expected = LL;
				_received = _obj.count(vector <int>(w, w+sizeof(w)/sizeof(int))); break;
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
