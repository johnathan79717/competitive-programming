#line 2 "NRooksPosition.cpp"
#include <string>
#include <vector>
#include <climits>
#include <cstring>
#include <map>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <cassert>
#include <deque>
#include <stack>
#include <functional>
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII> VPII;
typedef pair<LL,LL> PLL;
typedef vector<PLL> VPLL;
int MOD = 1e9+7;
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}

class NRooksPosition {
public:
    long long minSteps(int N, vector <int> Xprefix, vector <int> Yprefix, int A, int B, int C) {
	VI X(N), Y(N);
	int L = Xprefix.size();
	REP(i, L) {
	    X[i] = Xprefix[i];
	    Y[i] = Yprefix[i];
	}
	REPP(i, L, N) {
	    X[i] = (1ll * A * X[i-1] + 1ll * B * X[i-2]) % C;
	    Y[i] = (1ll * A * Y[i-1] + 1ll * B * Y[i-2]) % C;
	}
	sort(ALL(X));
	sort(ALL(Y));
	REP(i, N) {
	    X[i] -= i;
	    Y[i] -= i;
	}
	sort(ALL(X));
	sort(ALL(Y));
	int l = 0, r = N-1;
	LL ans = 0;
	while (l < r) {
	    ans += X[r] - X[l];
	    ans += Y[r] - Y[l];
	    r--;
	    l++;
	}
	return ans;
    }
};

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
This problem takes place on an infinite grid of unit squares.
There are N tokens on the grid.
Currently, token number i is in the square at coordinates (X[i], Y[i]).
Multiple tokens may share the same square at any time.



You can move the tokens. The only allowed operation is called a step and involves moving one token into one of the four squares adjacent to its current square.



We say that the N tokens are in an N rooks position if the tokens occupy N consecutive rows of the grid and at the same time they occupy N consecutive columns of the grid.
(Each of those rows and columns must actually be occupied by one of the tokens. In other words, if the tokens are in this position and we would cut out the smallest rectangle that contains all tokens, we would have an N times N board on which the tokens represent one possible position of N rooks that don't attack each other.)



Given the initial positions of all tokens, find the minimum number of steps needed to move all tokens into some valid N rooks position.



As we need to have large inputs, please be so kind and use the following simple pseudocode to generate the arrays X and Y with the coordinates of all points:


L = length(Xprefix)
for i = 0 to L-1:
    X[i] = Xprefix[i]
    Y[i] = Yprefix[i]
for i = L to N-1:
    X[i] = (A * X[i-1] + B * X[i-2]) mod C
    Y[i] = (A * Y[i-1] + B * Y[i-2]) mod C


DEFINITION
Class:NRooksPosition
Method:minSteps
Parameters:int, vector <int>, vector <int>, int, int, int
Returns:long long
Method signature:long long minSteps(int N, vector <int> Xprefix, vector <int> Yprefix, int A, int B, int C)


NOTES
-The reference solution is fast enough for any input within the allowed range of N. It does not depend on the pseudorandom generator in any way.


CONSTRAINTS
-N will be between 2 and 10^6, inclusive.
-Xprefix will have between 2 and min(500,N) elements, inclusive.
-Yprefix will have the same number of elements as Xprefix.
-All elements of Xprefix and Yprefix will be between 0 and 10^9 - 1, inclusive.
-A and B will be between 0 and 10^9 - 1, inclusive.
-C will be between 1 and 10^9, inclusive.


EXAMPLES

0)
3
{5, 8, 7}
{1, 3, 5}
0
0
1

Returns: 3


The initial configuration of tokens looks as follows (X grows to the right, Y grows upwards):


......2.
........
.......1
........
....0...

One optimal solution is to move token 0 one step right, then one step up, and then move token 2 one step down, producing:

........
......2.
.......1
.....0..
........

The tokens are now in three consecutive rows and three consecutive columns.

1)
999999
{0, 0}
{0, 0}
0
0
1

Returns: 499999000000

999,999 tokens, all of them start at (0,0).
One optimal solution is to distribute them to the points (-499999,499999) to (499999,-499999).

2)
2
{953523433, 43}
{2324, 244525243}
4
7
47

Returns: 1198046307

Two tokens far from each other. They must almost-meet somewhere. It doesn't really matter whether we push just one of them the whole way or whether we push each of them a part of the way towards the other.

3)
10
{47, 530}
{9421, 125521}
1234567
7654321
987654321

Returns: 5509135972


X = {47, 530, 26419276, 176189634, 267705568, 376691149, 738601310, 368332752, 756100319, 534681602, }
Y = {9421, 125521, 902603039, 753444129, 36706724, 375900842, 810804826, 812632368, 128411635, 285087958, }


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
		cout << "Testing NRooksPosition (450.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1607794539;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 450.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		NRooksPosition _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 3;
				int Xprefix[] = {5, 8, 7};
				int Yprefix[] = {1, 3, 5};
				int A = 0;
				int B = 0;
				int C = 1;
				_expected = 3LL;
				_received = _obj.minSteps(N, vector <int>(Xprefix, Xprefix+sizeof(Xprefix)/sizeof(int)), vector <int>(Yprefix, Yprefix+sizeof(Yprefix)/sizeof(int)), A, B, C); break;
			}
			case 1:
			{
				int N = 999999;
				int Xprefix[] = {0, 0};
				int Yprefix[] = {0, 0};
				int A = 0;
				int B = 0;
				int C = 1;
				_expected = 499999000000LL;
				_received = _obj.minSteps(N, vector <int>(Xprefix, Xprefix+sizeof(Xprefix)/sizeof(int)), vector <int>(Yprefix, Yprefix+sizeof(Yprefix)/sizeof(int)), A, B, C); break;
			}
			case 2:
			{
				int N = 2;
				int Xprefix[] = {953523433, 43};
				int Yprefix[] = {2324, 244525243};
				int A = 4;
				int B = 7;
				int C = 47;
				_expected = 1198046307LL;
				_received = _obj.minSteps(N, vector <int>(Xprefix, Xprefix+sizeof(Xprefix)/sizeof(int)), vector <int>(Yprefix, Yprefix+sizeof(Yprefix)/sizeof(int)), A, B, C); break;
			}
			case 3:
			{
				int N = 10;
				int Xprefix[] = {47, 530};
				int Yprefix[] = {9421, 125521};
				int A = 1234567;
				int B = 7654321;
				int C = 987654321;
				_expected = 5509135972LL;
				_received = _obj.minSteps(N, vector <int>(Xprefix, Xprefix+sizeof(Xprefix)/sizeof(int)), vector <int>(Yprefix, Yprefix+sizeof(Yprefix)/sizeof(int)), A, B, C); break;
			}
			/*case 4:
			{
				int N = ;
				int Xprefix[] = ;
				int Yprefix[] = ;
				int A = ;
				int B = ;
				int C = ;
				_expected = LL;
				_received = _obj.minSteps(N, vector <int>(Xprefix, Xprefix+sizeof(Xprefix)/sizeof(int)), vector <int>(Yprefix, Yprefix+sizeof(Yprefix)/sizeof(int)), A, B, C); break;
			}*/
			/*case 5:
			{
				int N = ;
				int Xprefix[] = ;
				int Yprefix[] = ;
				int A = ;
				int B = ;
				int C = ;
				_expected = LL;
				_received = _obj.minSteps(N, vector <int>(Xprefix, Xprefix+sizeof(Xprefix)/sizeof(int)), vector <int>(Yprefix, Yprefix+sizeof(Yprefix)/sizeof(int)), A, B, C); break;
			}*/
			/*case 6:
			{
				int N = ;
				int Xprefix[] = ;
				int Yprefix[] = ;
				int A = ;
				int B = ;
				int C = ;
				_expected = LL;
				_received = _obj.minSteps(N, vector <int>(Xprefix, Xprefix+sizeof(Xprefix)/sizeof(int)), vector <int>(Yprefix, Yprefix+sizeof(Yprefix)/sizeof(int)), A, B, C); break;
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
