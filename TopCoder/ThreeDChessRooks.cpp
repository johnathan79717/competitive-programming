#line 2 "ThreeDChessRooks.cpp"
#include <array>
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
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define FOR(I, A, B) for (int I = (A); I <= (B); ++I)
#define FORS(I, S) for (int I = 0; S[I]; ++I)
#define RS(X) scanf("%s", (X))
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define GET_POS(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
#define CASET int ___T; scanf("%d", &___T); for(int cs=1;cs<=___T;cs++)
#define MP make_pair
#define PB emplace_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define F first
#define S second
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

class ThreeDChessRooks {
public:
    long long count(int C, int R, vector <int> XP, vector <int> YP, vector <int> ZP, int seed) {
	vector<int> X(R), Y(R), Z(R);

	int L = XP.size();
	for (int i=0; i<L; ++i) { X[i]=XP[i]; Y[i]=YP[i]; Z[i]=ZP[i]; }

	long long state = seed;
	for (int i=L; i<R; ++i) {
	    state = (state * 1103515245 + 12345) % (1LL << 31);
	    X[i] = state % C;
	    state = (state * 1103515245 + 12345) % (1LL << 31);
	    Y[i] = state % C;
	    state = (state * 1103515245 + 12345) % (1LL << 31);
	    Z[i] = state % C;
	}

	vector<array<int, 3>> p(R);
	REP(i, R) {
	    p[i][0] = X[i];
	    p[i][1] = Y[i];
	    p[i][2] = Z[i];
	}

	map<int, int> x[3] = {};
	map<pair<int, int>, int> xy[3][3] = {};
	map<array<int, 3>, int> xyz;
	LL ans = 0;
	REP(i, R) {
	    REP(j, 3) {
		x[j][p[i][j]]++;
	    }
	    REP(j, 3) {
		REPP(k, j+1, 3) {
		    xy[j][k][MP(p[i][j], p[i][k])]++;
		}
	    }
	    xyz[p[i]]++;
	}

	REP(i, R) {
	    REP(j, 3) {
		ans += x[j][p[i][j]];
		REPP(k, j+1, 3) {
		    ans -= xy[j][k][MP(p[i][j], p[i][k])];
		}

		if (p[i][j] == 0) {
		    auto tmp = p[i];
		    tmp[j] = 1;
		    auto it = xyz.find(tmp);
		    if (it != xyz.end()) {
			ans -= it->S;
		    }
		}

		if (p[i][j] == C-1) {
		    auto tmp = p[i];
		    tmp[j] = C-2;
		    auto it = xyz.find(tmp);
		    if (it != xyz.end()) {
			ans -= it->S;
		    }
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
A 3D chessboard is a C x C x C cube. Rows, columns and floors are each numbered from 0 to C-1, inclusive.


A rook in 3D chess moves like a rook in traditional chess, except now we have six possible cardinal directions instead of four.
When moving a rook we choose one of those six directions and move the rook a positive number of steps in the chosen direction.
During the move the rook can only traverse through empty cells.
The rook may end its move in a cell that contains a chess piece of the opposite color; that piece is then captured by the rook and removed from the board.



You are given a collection of R (not necessarily distinct) cells of the 3D chessboard.
The cells in the collection are numbered from 0 to R-1, inclusive.
Cell i has coordinates (X[i], Y[i], Z[i]).
In order to keep the input size small, only a prefix of the coordinates is actually given, the rest will be pseudorandom.



Consider the following interaction:


Wanda selected an index i (0 <= i <= R-1) and placed a white rook into cell i.
Boris selected an index j (0 <= j <= R-1, cells i and j are not the same cell) and placed a black rook into cell j.
Wanda made a valid move with her rook without capturing Boris's rook.
Boris made a valid move with his rook and captured Wanda's rook with that move.


Count all ordered pairs (i, j) for which the above interaction could take place. Return that count.



The arrays X, Y and Z are defined as follows:



---------------------------------------------------------

Pseudocode:

L = length(XP)
for i = 0 to L-1:
    X[i] = XP[i]
    Y[i] = YP[i]
    Z[i] = ZP[i]

state = seed
for i = L to R-1:
    state = (state * 1103515245 + 12345) modulo 2^31
    X[i] = state modulo C
    state = (state * 1103515245 + 12345) modulo 2^31
    Y[i] = state modulo C
    state = (state * 1103515245 + 12345) modulo 2^31
    Z[i] = state modulo C

---------------------------------------------------------

C++:

vector<int> X(R), Y(R), Z(R);

int L = XP.size();
for (int i=0; i<L; ++i) { X[i]=XP[i]; Y[i]=YP[i]; Z[i]=ZP[i]; }

long long state = seed;
for (int i=L; i<R; ++i) {
    state = (state * 1103515245 + 12345) % (1LL << 31);
    X[i] = state % C;
    state = (state * 1103515245 + 12345) % (1LL << 31);
    Y[i] = state % C;
    state = (state * 1103515245 + 12345) % (1LL << 31);
    Z[i] = state % C;
}

---------------------------------------------------------

Java:

int[] X = new int[R];
int[] Y = new int[R];
int[] Z = new int[R];

int L = XP.length;
for (int i=0; i<L; ++i) { X[i]=XP[i]; Y[i]=YP[i]; Z[i]=ZP[i]; }

long state = seed;
for (int i=L; i<R; ++i) {
    state = (state * 1103515245 + 12345) % (1L << 31);
    X[i] = (int)(state % C);
    state = (state * 1103515245 + 12345) % (1L << 31);
    Y[i] = (int)(state % C);
    state = (state * 1103515245 + 12345) % (1L << 31);
    Z[i] = (int)(state % C);
}


DEFINITION
Class:ThreeDChessRooks
Method:count
Parameters:int, int, vector <int>, vector <int>, vector <int>, int
Returns:long long
Method signature:long long count(int C, int R, vector <int> XP, vector <int> YP, vector <int> ZP, int seed)


NOTES
-The reference solution does not depend on the input being pseudorandom.
-Remember that during a valid move a rook must move by at least one cell. Leaving a rook in its current cell is not a valid move.


CONSTRAINTS
-C will be between 2 and 1,000,000, inclusive.
-R will be between 1 and 100,000, inclusive.
-XP will have between 0 and 100 elements, inclusive.
-XP will have at most R elements.
-YP and ZP will each have the same number of elements as XP.
-Each element of XP, YP and ZP will be between 0 and C-1, inclusive.
-seed will be between 0 and 2^31 - 1, inclusive.


EXAMPLES

0)
10
4
{0, 0, 0, 0}
{0, 0, 0, 0}
{2, 3, 5, 7}
0

Returns: 12


We have a 10x10x10 cube. The collection contains four cells, their coordinates are (0,0,2), (0,0,3), (0,0,5) and (0,0,7).


Clearly, Wanda can select any of these four cells and then Boris can select any of the remaining three, giving us 4*3 = 12 valid pairs (i,j).


For example: Wanda selects i=1 and thus places the white rook at (0,0,3). Boris selects j=3 and thus places the black rook at (0,0,7). Wanda moves her rook to (0,0,6). Boris moves his rook to (0,0,6) and captures Wanda's rook.


1)
10
4
{1, 1, 1, 1}
{4, 4, 4, 4}
{0, 0, 0, 0}
0

Returns: 0

All four cells in this collection are identical. Regardless of which i Wanda chooses, Boris cannot choose any valid j.

2)
10
4
{9, 2, 3, 4}
{5, 6, 7, 8}
{9, 0, 1, 9}
0

Returns: 2


The only two pairs of indices that work for this collection are (0,3) and (3,0). For example, (0,3) works because this is one possible interaction:


Wanda selects i=0 and places the white rook at (9,5,9). Boris selects j=3 and places the black rook at (4,8,9). Wanda moves her rook to (4,5,9). Boris moves his rook to (4,5,9) and captures Wanda's rook.


3)
10
10
{9, 2, 3, 4}
{5, 6, 7, 8}
{9, 0, 1, 9}
47474747

Returns: 16

The collection starts as in Example 2, but now we have additional rooks with pseudorandom coordinates. Complete collection:


X = {9, 2, 3, 4, 8, 5, 2, 3, 0, 3}
Y = {5, 6, 7, 8, 1, 8, 1, 2, 9, 0}
Z = {9, 0, 1, 9, 8, 7, 6, 5, 4, 7}


4)
10
7
{1, 1, 1, 1, 1, 1, 1}
{4, 7, 4, 7, 4, 7, 4}
{2, 2, 2, 2, 2, 2, 2}
42

Returns: 24

Note that we are counting pairs of indices, not pairs of cells. Here, each pair of indices (i, j) where i and j have a different parity works.

5)
99
8
{47, 48, 49, 50, 50, 51, 52, 53}
{12, 12, 12, 12, 12, 12, 12, 12}
{12, 12, 12, 12, 12, 12, 12, 12}
111

Returns: 54

Each of the 8*7 = 56 pairs of indices works, except for the pairs (3, 4) and (4, 3) which both represent the same cell. Boris cannot place the black rook into the cell that is, at that moment, occupied by Wanda's white rook.

6)
2
2
{1, 1}
{0, 1}
{0, 0}
0

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
		cout << "Testing ThreeDChessRooks (300.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1620489904;
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
		ThreeDChessRooks _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int C = 10;
				int R = 4;
				int XP[] = {0, 0, 0, 0};
				int YP[] = {0, 0, 0, 0};
				int ZP[] = {2, 3, 5, 7};
				int seed = 0;
				_expected = 12LL;
				_received = _obj.count(C, R, vector <int>(XP, XP+sizeof(XP)/sizeof(int)), vector <int>(YP, YP+sizeof(YP)/sizeof(int)), vector <int>(ZP, ZP+sizeof(ZP)/sizeof(int)), seed); break;
			}
			case 1:
			{
				int C = 10;
				int R = 4;
				int XP[] = {1, 1, 1, 1};
				int YP[] = {4, 4, 4, 4};
				int ZP[] = {0, 0, 0, 0};
				int seed = 0;
				_expected = 0LL;
				_received = _obj.count(C, R, vector <int>(XP, XP+sizeof(XP)/sizeof(int)), vector <int>(YP, YP+sizeof(YP)/sizeof(int)), vector <int>(ZP, ZP+sizeof(ZP)/sizeof(int)), seed); break;
			}
			case 2:
			{
				int C = 10;
				int R = 4;
				int XP[] = {9, 2, 3, 4};
				int YP[] = {5, 6, 7, 8};
				int ZP[] = {9, 0, 1, 9};
				int seed = 0;
				_expected = 2LL;
				_received = _obj.count(C, R, vector <int>(XP, XP+sizeof(XP)/sizeof(int)), vector <int>(YP, YP+sizeof(YP)/sizeof(int)), vector <int>(ZP, ZP+sizeof(ZP)/sizeof(int)), seed); break;
			}
			case 3:
			{
				int C = 10;
				int R = 10;
				int XP[] = {9, 2, 3, 4};
				int YP[] = {5, 6, 7, 8};
				int ZP[] = {9, 0, 1, 9};
				int seed = 47474747;
				_expected = 16LL;
				_received = _obj.count(C, R, vector <int>(XP, XP+sizeof(XP)/sizeof(int)), vector <int>(YP, YP+sizeof(YP)/sizeof(int)), vector <int>(ZP, ZP+sizeof(ZP)/sizeof(int)), seed); break;
			}
			case 4:
			{
				int C = 10;
				int R = 7;
				int XP[] = {1, 1, 1, 1, 1, 1, 1};
				int YP[] = {4, 7, 4, 7, 4, 7, 4};
				int ZP[] = {2, 2, 2, 2, 2, 2, 2};
				int seed = 42;
				_expected = 24LL;
				_received = _obj.count(C, R, vector <int>(XP, XP+sizeof(XP)/sizeof(int)), vector <int>(YP, YP+sizeof(YP)/sizeof(int)), vector <int>(ZP, ZP+sizeof(ZP)/sizeof(int)), seed); break;
			}
			case 5:
			{
				int C = 99;
				int R = 8;
				int XP[] = {47, 48, 49, 50, 50, 51, 52, 53};
				int YP[] = {12, 12, 12, 12, 12, 12, 12, 12};
				int ZP[] = {12, 12, 12, 12, 12, 12, 12, 12};
				int seed = 111;
				_expected = 54LL;
				_received = _obj.count(C, R, vector <int>(XP, XP+sizeof(XP)/sizeof(int)), vector <int>(YP, YP+sizeof(YP)/sizeof(int)), vector <int>(ZP, ZP+sizeof(ZP)/sizeof(int)), seed); break;
			}
			case 6:
			{
				int C = 2;
				int R = 2;
				int XP[] = {1, 1};
				int YP[] = {0, 1};
				int ZP[] = {0, 0};
				int seed = 0;
				_expected = 0LL;
				_received = _obj.count(C, R, vector <int>(XP, XP+sizeof(XP)/sizeof(int)), vector <int>(YP, YP+sizeof(YP)/sizeof(int)), vector <int>(ZP, ZP+sizeof(ZP)/sizeof(int)), seed); break;
			}
			/*case 7:
			{
				int C = ;
				int R = ;
				int XP[] = ;
				int YP[] = ;
				int ZP[] = ;
				int seed = ;
				_expected = LL;
				_received = _obj.count(C, R, vector <int>(XP, XP+sizeof(XP)/sizeof(int)), vector <int>(YP, YP+sizeof(YP)/sizeof(int)), vector <int>(ZP, ZP+sizeof(ZP)/sizeof(int)), seed); break;
			}*/
			/*case 8:
			{
				int C = ;
				int R = ;
				int XP[] = ;
				int YP[] = ;
				int ZP[] = ;
				int seed = ;
				_expected = LL;
				_received = _obj.count(C, R, vector <int>(XP, XP+sizeof(XP)/sizeof(int)), vector <int>(YP, YP+sizeof(YP)/sizeof(int)), vector <int>(ZP, ZP+sizeof(ZP)/sizeof(int)), seed); break;
			}*/
			/*case 9:
			{
				int C = ;
				int R = ;
				int XP[] = ;
				int YP[] = ;
				int ZP[] = ;
				int seed = ;
				_expected = LL;
				_received = _obj.count(C, R, vector <int>(XP, XP+sizeof(XP)/sizeof(int)), vector <int>(YP, YP+sizeof(YP)/sizeof(int)), vector <int>(ZP, ZP+sizeof(ZP)/sizeof(int)), seed); break;
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
