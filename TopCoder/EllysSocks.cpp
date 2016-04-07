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
#define REP(i,n) for(int i=0;i<int(n);i++)
#define ALL(x) (x).begin(),(x).end()
#define MIN(x, a) x = min(x, a)

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;
// #line 40 "EllysSocks.cpp"
#include <string>
#include <vector>
int dp[1005][1005];
class EllysSocks {
public:
    int getDifference(vector <int> S, int P) {
        sort(ALL(S));
        REP(i, 1005) REP(j, 1005) dp[i][j] = 1e9;
        dp[0][0] = 0;
        REP(i, S.size()) {
            REP(j, P+1) {
                MIN(dp[i+1][j], dp[i][j]);
                if (i >= 1 && j+1 <= P) {
                    MIN(dp[i+1][j+1], max(dp[i-1][j], abs(S[i] - S[i-1])));
                }
            }
        }
        return dp[S.size()][P];
    }
};
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// By the time a programmer qualifies for TCO finals he or she should have at least heard of the mythical device called "washing machine". An interesting property of this device is that it is fed not by electricity, as many of you would think, but by socks.

Elly has been living on her own for a while now. Every time she washes her clothes some of her socks mysteriously disappear. Because of that the girl has gathered quite a few single socks of various sizes. She wants to match some of them in pairs, possibly using two socks of different sizes as a pair (come on, nobody will notice if you wear a size 36 sock on your left foot and 37 on your right one). She wants to make P pairs in total out of the socks she has. Any two socks can be paired, however Elly does not like to have pairs in which one of the socks is much bigger than the other. Thus, she wants the difference in sizes in the worst pair to be as little as possible.


You are given the sizes of Elly's socks in the vector <int> S. You are also given the int P. Compute and return the smallest nonnegative integer D with the following property: Elly can create P disjoint pairs of socks in such a way that in each pair the sock sizes differ by at most D.

DEFINITION
Class:EllysSocks
Method:getDifference
Parameters:vector <int>, int
Returns:int
Method signature:int getDifference(vector <int> S, int P)


CONSTRAINTS
-S will contain between 2 and 1000 elements, inclusive.
-Each element of S will be between 1 and 1,000,000,000, inclusive.
-P will be between 1 and |S|/2 (rounded down), inclusive, where |S| is the number of elements in S.


EXAMPLES

0)
{42, 37, 84, 36, 41, 42}
2

Returns: 1

Elly has 6 socks and wants to create 2 pairs out of them. One of the optimal possibilities here is to match 36 with 37 and 42 with 42. The maximal difference is 1 (|36 - 37|).

1)
{42, 37, 84, 36, 41, 42}
3

Returns: 42

This is the same as the previous test, but now all socks must be matched into pairs. We have to include the one with size 84, so the best we can do is to match it with one of the socks with size 42.

2)
{5, 2, 8, 8, 6, 7, 3, 7, 4, 2, 4, 5, 3, 6}
7

Returns: 0

In this case Elly can match all socks perfectly.

3)
{17, 3, 13, 3, 2, 17, 11, 5, 5, 7, 11, 7, 13, 19}
7

Returns: 4

The girl wants to minimize the difference in the worst pair.

4)
{795755685, 581869303, 404620563, 708632712, 545404205, 133711906, 372047868, 949333986, 579004999, 323567404,
 418932836, 944672732, 196140741, 809094427, 946129058, 30574577, 182506778, 15198493, 150802600, 138749191,
 676943010, 177512688, 126303054, 81133258, 183966551, 471852627, 84672537, 867128744, 857788837, 275731772,
 609397213, 20544910, 811450930, 483031419, 361913171, 547204602, 892462744, 522136404, 173978710, 131752569,
 478582453, 867889991, 153380496, 551745921, 647984700, 910208077, 283496852, 368550363, 379821990, 712568903,
 40498239, 113911604, 103237637, 39073007, 684602223, 812852787, 479711181, 746745228, 735241235, 296707007,
 262522458, 870676136, 136721027, 359573809, 189375153, 547914047, 198304613, 640439653, 417177802, 25475624,
 758242872, 764919655, 310701088, 537655880, 361931892, 14685971, 213794688, 107063881, 147944789, 444803289,
 884392679, 540721924, 638781100, 902841101, 7097711, 219972874, 879609715, 156513984, 802611721, 755486970,
 103522060, 967048445, 913778155, 94092596, 519074050, 884870761, 248268555, 339840186, 53612697, 826647953}
42

Returns: 12866316



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
		cout << "Testing EllysSocks (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1459008334;
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
		EllysSocks _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int S[] = {42, 37, 84, 36, 41, 42};
				int P = 2;
				_expected = 1;
				_received = _obj.getDifference(vector <int>(S, S+sizeof(S)/sizeof(int)), P); break;
			}
			case 1:
			{
				int S[] = {42, 37, 84, 36, 41, 42};
				int P = 3;
				_expected = 42;
				_received = _obj.getDifference(vector <int>(S, S+sizeof(S)/sizeof(int)), P); break;
			}
			case 2:
			{
				int S[] = {5, 2, 8, 8, 6, 7, 3, 7, 4, 2, 4, 5, 3, 6};
				int P = 7;
				_expected = 0;
				_received = _obj.getDifference(vector <int>(S, S+sizeof(S)/sizeof(int)), P); break;
			}
			case 3:
			{
				int S[] = {17, 3, 13, 3, 2, 17, 11, 5, 5, 7, 11, 7, 13, 19};
				int P = 7;
				_expected = 4;
				_received = _obj.getDifference(vector <int>(S, S+sizeof(S)/sizeof(int)), P); break;
			}
			case 4:
			{
				int S[] = {795755685, 581869303, 404620563, 708632712, 545404205, 133711906, 372047868, 949333986, 579004999, 323567404,
				           418932836, 944672732, 196140741, 809094427, 946129058, 30574577, 182506778, 15198493, 150802600, 138749191,
				           676943010, 177512688, 126303054, 81133258, 183966551, 471852627, 84672537, 867128744, 857788837, 275731772,
				           609397213, 20544910, 811450930, 483031419, 361913171, 547204602, 892462744, 522136404, 173978710, 131752569,
				           478582453, 867889991, 153380496, 551745921, 647984700, 910208077, 283496852, 368550363, 379821990, 712568903,
				           40498239, 113911604, 103237637, 39073007, 684602223, 812852787, 479711181, 746745228, 735241235, 296707007,
				           262522458, 870676136, 136721027, 359573809, 189375153, 547914047, 198304613, 640439653, 417177802, 25475624,
				           758242872, 764919655, 310701088, 537655880, 361931892, 14685971, 213794688, 107063881, 147944789, 444803289,
				           884392679, 540721924, 638781100, 902841101, 7097711, 219972874, 879609715, 156513984, 802611721, 755486970,
				           103522060, 967048445, 913778155, 94092596, 519074050, 884870761, 248268555, 339840186, 53612697, 826647953};
				int P = 42;
				_expected = 12866316;
				_received = _obj.getDifference(vector <int>(S, S+sizeof(S)/sizeof(int)), P); break;
			}
			/*case 5:
			{
				int S[] = ;
				int P = ;
				_expected = ;
				_received = _obj.getDifference(vector <int>(S, S+sizeof(S)/sizeof(int)), P); break;
			}*/
			/*case 6:
			{
				int S[] = ;
				int P = ;
				_expected = ;
				_received = _obj.getDifference(vector <int>(S, S+sizeof(S)/sizeof(int)), P); break;
			}*/
			/*case 7:
			{
				int S[] = ;
				int P = ;
				_expected = ;
				_received = _obj.getDifference(vector <int>(S, S+sizeof(S)/sizeof(int)), P); break;
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
