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
#define MS0(x) memset(x,0,sizeof(x))
#define MAX(x, a) x = max(x, a)
 
typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;

#line 40 "CheeseSlicing.cpp"
#include <string>
#include <vector>
int dp[105][105][105];
class CheeseSlicing {
public:
  int totalArea(int A, int B, int C, int S) {
    MS0(dp);
    REP(i, 101) REP(j, 101) REP(k, 101) {
      if (i < S || j < S || k < S) {
        continue;
      }
      dp[i][j][k] = max(i * j, max(j * k, k * i));
      REP1(c, S, i-S) {
        MAX(dp[i][j][k], dp[c][j][k] + dp[i-c][j][k]);
      }
      REP1(c, S, j-S) {
        MAX(dp[i][j][k], dp[i][c][k] + dp[i][j-c][k]);
      }
      REP1(c, S, k-S) {
        MAX(dp[i][j][k], dp[i][j][c] + dp[i][j][k-c]);
      }
    }
    return dp[A][B][C];
  }
};

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// You want to make a lot of sandwiches.
However, you only have a limited amount of cheese.
The only piece of cheese you currently have is a rectangular block with dimensions A, B, and C.

You can cut the block of cheese into smaller pieces.
You are only allowed to cut as follows:

Each cut must divide one block of cheese into two smaller blocks of cheese.
Each cut must be parallel to one of the faces of the piece you are cutting.
Each of the two smaller blocks must have integer dimensions.


When placing a block of cheese onto a piece of bread, the cheese is always rotated so that its shortest side is vertical.
In other words, suppose you have a block of cheese with dimensions (X,Y,Z) such that X ≥ Y ≥ Z.
If you place this block onto a piece of bread, its surface area will be X*Y and its thickness will be Z.

A block of cheese is called a good slice if and only if its thickness is greater than or equal to S.
(Recall that the thickness of a block is the length of its shortest side.)

You can cut your block of cheese into arbitrarily many pieces, as long as you follow the rules given above.
Your goal is to cut the block in such a way that maximizes the total surface area of all good slices among the pieces.
Note that your way of cutting may also produce some pieces that are not good slices, but those pieces won't contribute to the surface area.
The number of good slices does not matter, we only care about their surface.
Different good slices may have different dimensions.

You are given the ints A, B, C, and S.
Return the maximum total surface area of good slices you can get.

DEFINITION
Class:CheeseSlicing
Method:totalArea
Parameters:int, int, int, int
Returns:int
Method signature:int totalArea(int A, int B, int C, int S)


CONSTRAINTS
-A, B and C will be between 1 and 100, inclusive.
-S will be between 1 and 10, inclusive.


EXAMPLES

0)
1
3
3
2

Returns: 0

One of the dimensions of this block is 1.
Regardless of how we cut it, each piece will have one dimension equal to 1.
As S=2, this means that producing a good slice is impossible.
Hence, the maximum total surface area of good slices is 0.

1)
5
3
5
3

Returns: 25

The entire block is a good slice with thickness 3 and surface area 5*5 = 25.
An optimal solution is to make no cuts and to simply take this one block.

2)
5
5
5
2

Returns: 58

One possible sequence of cuts:

 5x5x5 -> 2x5x5 + 3x5x5 
 3x5x5 -> 3x2x5 + 3x3x5 
 3x3x5 -> 3x3x2 + 3x3x3 

After these three cuts we have four pieces: 2x5x5, 3x2x5, 3x3x2, and 3x3x3.
Each of these is a good slice.
Their total surface area is 5*5 + 3*5 + 3*3 + 3*3.

3)
49
92
20
3

Returns: 30045



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
		cout << "Testing CheeseSlicing (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1491063678;
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
		CheeseSlicing _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int A = 1;
				int B = 3;
				int C = 3;
				int S = 2;
				_expected = 0;
				_received = _obj.totalArea(A, B, C, S); break;
			}
			case 1:
			{
				int A = 5;
				int B = 3;
				int C = 5;
				int S = 3;
				_expected = 25;
				_received = _obj.totalArea(A, B, C, S); break;
			}
			case 2:
			{
				int A = 5;
				int B = 5;
				int C = 5;
				int S = 2;
				_expected = 58;
				_received = _obj.totalArea(A, B, C, S); break;
			}
			case 3:
			{
				int A = 49;
				int B = 92;
				int C = 20;
				int S = 3;
				_expected = 30045;
				_received = _obj.totalArea(A, B, C, S); break;
			}
			/*case 4:
			{
				int A = ;
				int B = ;
				int C = ;
				int S = ;
				_expected = ;
				_received = _obj.totalArea(A, B, C, S); break;
			}*/
			/*case 5:
			{
				int A = ;
				int B = ;
				int C = ;
				int S = ;
				_expected = ;
				_received = _obj.totalArea(A, B, C, S); break;
			}*/
			/*case 6:
			{
				int A = ;
				int B = ;
				int C = ;
				int S = ;
				_expected = ;
				_received = _obj.totalArea(A, B, C, S); break;
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
