#line 2 "MarioJumper.cpp"
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

class MarioJumper {
public:
    long long minTime(vector <string> pieces, vector <int> counts, int J, long long S, long long F) {
		
    }
};

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
You are playing a simple Mario-style computer game.
The game takes place in a vertically placed two-dimensional plane divided into a grid of unit square cells.
The rows and columns of this grid have integer coordinates (row, column), with column numbers growing left to right and row numbers growing bottom to top.


The game world itself consists of cells (r, c) such that 0 <= r and 0 <= c < N.
In column i, the bottommost H[i] cells are solid ground.
The bottom of the level is solid, as if all the cells (-1, c) also contained solid ground.
All other cells contain air.


For example, several bottom rows of the level corresponding to H = {1, 4, 0, 2, 0, 2} are shown below. ('#' is solid ground, '.' is air, '=' shows the additional solid ground below the level.)



column: 012345

        ......
        ......
        .#....
        .#....
        .#.#.#
        ##.#.#
        ======
     H: 140202



You are given a compressed description of the game world: a vector <string> pieces containing strings of digits and an vector <int> counts.
You can build a string that describes the game world by concatenating counts[0] copies of pieces[0], followed by counts[1] copies of pieces[1], and so on.
N (the width of the game world) is equal to the length of the resulting string, and for each i the digit at index i in the resulting string gives the height H[i].



You are controlling a character.
The character can move in steps and jumps.
Each movement (regardless of whether it's a step or a jump) takes 1 second.
Both steps and jumps can be made in either direction.
Jumps have maximum height J and a maximum span of two columns.
All possible movements look as follows:


A step from column c1 to an adjacent column c2 is possible if and only if H[c2] does not exceed H[c1].
A jump from column c1 to an adjacent column c2 is possible if and only if H[c2] does not exceed H[c1] + J.
A jump from column c1 over an adjacent column c2 to the following column c3 is possible if and only if neither of H[c2] and H[c3] exceeds H[c1] + J.


As the last part of each movement, after reaching the destination column the character falls straight down until it hits the ground in that column.


Your character starts on the ground in column S.
You want to reach column F as quickly as possible.
Return the minimum time in seconds in which it can be done, or -1 if it's impossible.


DEFINITION
Class:MarioJumper
Method:minTime
Parameters:vector <string>, vector <int>, int, long long, long long
Returns:long long
Method signature:long long minTime(vector <string> pieces, vector <int> counts, int J, long long S, long long F)


CONSTRAINTS
-pieces will contain between 1 and 50 elements, inclusive.
-Each element of pieces will have between 2 and 50 characters, inclusive.
-Each character in pieces will be a digit ('0'-'9').
-counts will contain the same number of elements as pieces
-Each element of counts will be between 1 and 10^9, inclusive.
-J will be between 1 and 9, inclusive.
-S and F will be valid column numbers.


EXAMPLES

0)
{"140202"}
{1}
3
0
4

Returns: 2

The world from the example in the problem statement. If our jump height is 3, we can get from column 0 to column 4 in two jumps.


1)
{"14", "02"}
{1, 2}
2
0
5

Returns: -1

The same world as in the previous example, only this time given as a concatenation of smaller pieces. In this example the jump length is too small, so we actually cannot move from column 0 at all.

2)
{"140202"}
{1}
2
5
0

Returns: 3

Direction of travel matters. This is the same situation as in Example 1, but with start and finish swapped. In this case we can jump from column 5 to column 3, from there we can jump to column 1, and from column 1 we can either step or jump to column 0.

3)
{"000"}
{1000000000}
9
0
2999999999

Returns: 1500000000

Even though the level is straight and we could walk from start to finish, jumping is twice as fast.

4)
{"0123456789"}
{10}
1
3
95

Returns: 83

Jumping up the stairs. As J = 1, most of the jumps we'll make will be just to the adjacent column. Only from the columns of height 9 we can make a jump of length 2.

5)
{"12", "34", "56", "789"}
{12, 34, 56, 789}
3
470
470

Returns: 0

The obligatory example that shows the situation in which we start and end in the same column.

6)
{"90009"}
{1}
8
4
0

Returns: -1

There is no way to preserve height in this scenario. As soon as we leave the starting column (regardless of whether by a step or a jump), we will fall down to height 0, and from there we won't be able to reach the desired column.

7)
{"12", "34", "56", "789"}
{12, 34, 56, 789}
9
123
2345

Returns: 1111

If your jump height is 9, you don't really care about the terrain.

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
		cout << "Testing MarioJumper (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1601727048;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 1000.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		MarioJumper _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string pieces[] = {"140202"};
				int counts[] = {1};
				int J = 3;
				long long S = 0LL;
				long long F = 4LL;
				_expected = 2LL;
				_received = _obj.minTime(vector <string>(pieces, pieces+sizeof(pieces)/sizeof(string)), vector <int>(counts, counts+sizeof(counts)/sizeof(int)), J, S, F); break;
			}
			case 1:
			{
				string pieces[] = {"14", "02"};
				int counts[] = {1, 2};
				int J = 2;
				long long S = 0LL;
				long long F = 5LL;
				_expected = -1LL;
				_received = _obj.minTime(vector <string>(pieces, pieces+sizeof(pieces)/sizeof(string)), vector <int>(counts, counts+sizeof(counts)/sizeof(int)), J, S, F); break;
			}
			case 2:
			{
				string pieces[] = {"140202"};
				int counts[] = {1};
				int J = 2;
				long long S = 5LL;
				long long F = 0LL;
				_expected = 3LL;
				_received = _obj.minTime(vector <string>(pieces, pieces+sizeof(pieces)/sizeof(string)), vector <int>(counts, counts+sizeof(counts)/sizeof(int)), J, S, F); break;
			}
			case 3:
			{
				string pieces[] = {"000"};
				int counts[] = {1000000000};
				int J = 9;
				long long S = 0LL;
				long long F = 2999999999LL;
				_expected = 1500000000LL;
				_received = _obj.minTime(vector <string>(pieces, pieces+sizeof(pieces)/sizeof(string)), vector <int>(counts, counts+sizeof(counts)/sizeof(int)), J, S, F); break;
			}
			case 4:
			{
				string pieces[] = {"0123456789"};
				int counts[] = {10};
				int J = 1;
				long long S = 3LL;
				long long F = 95LL;
				_expected = 83LL;
				_received = _obj.minTime(vector <string>(pieces, pieces+sizeof(pieces)/sizeof(string)), vector <int>(counts, counts+sizeof(counts)/sizeof(int)), J, S, F); break;
			}
			case 5:
			{
				string pieces[] = {"12", "34", "56", "789"};
				int counts[] = {12, 34, 56, 789};
				int J = 3;
				long long S = 470LL;
				long long F = 470LL;
				_expected = 0LL;
				_received = _obj.minTime(vector <string>(pieces, pieces+sizeof(pieces)/sizeof(string)), vector <int>(counts, counts+sizeof(counts)/sizeof(int)), J, S, F); break;
			}
			case 6:
			{
				string pieces[] = {"90009"};
				int counts[] = {1};
				int J = 8;
				long long S = 4LL;
				long long F = 0LL;
				_expected = -1LL;
				_received = _obj.minTime(vector <string>(pieces, pieces+sizeof(pieces)/sizeof(string)), vector <int>(counts, counts+sizeof(counts)/sizeof(int)), J, S, F); break;
			}
			case 7:
			{
				string pieces[] = {"12", "34", "56", "789"};
				int counts[] = {12, 34, 56, 789};
				int J = 9;
				long long S = 123LL;
				long long F = 2345LL;
				_expected = 1111LL;
				_received = _obj.minTime(vector <string>(pieces, pieces+sizeof(pieces)/sizeof(string)), vector <int>(counts, counts+sizeof(counts)/sizeof(int)), J, S, F); break;
			}
			/*case 8:
			{
				string pieces[] = ;
				int counts[] = ;
				int J = ;
				long long S = LL;
				long long F = LL;
				_expected = LL;
				_received = _obj.minTime(vector <string>(pieces, pieces+sizeof(pieces)/sizeof(string)), vector <int>(counts, counts+sizeof(counts)/sizeof(int)), J, S, F); break;
			}*/
			/*case 9:
			{
				string pieces[] = ;
				int counts[] = ;
				int J = ;
				long long S = LL;
				long long F = LL;
				_expected = LL;
				_received = _obj.minTime(vector <string>(pieces, pieces+sizeof(pieces)/sizeof(string)), vector <int>(counts, counts+sizeof(counts)/sizeof(int)), J, S, F); break;
			}*/
			/*case 10:
			{
				string pieces[] = ;
				int counts[] = ;
				int J = ;
				long long S = LL;
				long long F = LL;
				_expected = LL;
				_received = _obj.minTime(vector <string>(pieces, pieces+sizeof(pieces)/sizeof(string)), vector <int>(counts, counts+sizeof(counts)/sizeof(int)), J, S, F); break;
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
