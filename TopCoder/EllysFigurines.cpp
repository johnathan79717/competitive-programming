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
#define FOR(i, c) for(auto &i: c)
#define ALL(x) (x).begin(),(x).end()
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define MS1(x) memset(x,-1,sizeof(x))
#define V(T) vector<T >
 
struct EllysFigurines {
	V(string) board;
	int R, C;
	int dp[15][15];

	int row(int n, int m) {
		REP1(i, n, board.size()-1)
			REP1(j, m, board[0].size() - 1)
				if(board[i][j] == 'X')
					return 1 + f(i+R, m);
		return 0;
	}

	int col(int n, int m) {
		REP1(j, m, board[0].size() - 1)
			REP1(i, n, board.size() - 1)
				if(board[i][j] == 'X')
					return 1 + f(n, j+C);
		return 0;
	}
	
	int f(int n, int m) {
		if(n >= board.size() || m >= board[0].size()) return 0;
		if(dp[n][m] >= 0) return dp[n][m];
		return dp[n][m] = min(row(n, m), col(n, m));
	};

  int getMoves(vector <string> board, int R, int C) {
  	MS1(dp);
  	this->board = board;
  	this->R = R;
  	this->C = C;
  	return f(0, 0);
  }
};

// BEGIN CUT HERE
/*
PROBLEM STATEMENT
Elly has placed several (possibly none) figurines on a rectangular board with several rows and columns. Now Kristina wants to remove all figurines from the board. In a single move she selects either up to R consecutive rows, or up to C consecutive columns and removes all remaining figurines that are located there. The girl wonders what is the minimal number of moves in which she can clear the entire board.

The position of the figurines will be given to you in the vector <string> board. The j-th character of the i-th element of board will be '.' if the cell is empty, or 'X' if it contains a figurine. The maximal number of cleared rows in a single move will be given in the int R. The maximal number of cleared columns in a single move will be given in the int C. Return the minimal number of moves that is sufficient to clear the entire board.

DEFINITION
Class:EllysFigurines
Method:getMoves
Parameters:vector <string>, int, int
Returns:int
Method signature:int getMoves(vector <string> board, int R, int C)


NOTES
-In a single move the girl can only select a consecutive group of rows or columns to be cleared. In other words, in each move Kristina first decides whether she wants rows or columns, then she picks the index i of the first chosen row/column, then the number k of chosen rows/columns, and finally she removes all figurines from the rows/columns with indices i, i+1, i+2, ..., i+k-1.


CONSTRAINTS
-board will contain between 1 and 15 elements, inclusive.
-Each element of board will contain between 1 and 15 characters, inclusive.
-All elements of board will contain the same number of characters.
-Each character of board will be either '.' or 'X'.
-R will be between 1 and 15, inclusive.
-C will be between 1 and 15, inclusive.


EXAMPLES

0)
{".X.X.",
 "XX..X",
 ".XXX.",
 "...X.",
 ".X.XX"}
1
2

Returns: 3

In this case in a single move Elly can remove all figurines from a single row, all figurines from a single column or all figurines from two consecutive columns.
One way to achieve the optimal answer here would be to remove the figurines from the first and second column in the first move, then the ones from the fourth and fifth column in the second move, and finally the remaining ones on the third row in the third move.
Another solution would be to erase only columns, again using three moves.

1)
{".X.X.",
 "XX..X",
 ".X.X.",
 "...X.",
 ".X.XX"}
2
2

Returns: 2

Almost the same as the first example, but without the figurine in the middle and the number of maximal rows removed is increased by one.
This time, the only optimal solution is to clear the first two columns in one move and the last two in another move.

2)
{"XXXXXXX"}
2
3

Returns: 1

The maximal allowed number of cleared rows or columns might be greater than the corresponding dimension of the board. The optimal solution for this board is to clear the only row in one move.

3)
{"XXXXX",
 "X....",
 "XXX..",
 "X....",
 "XXXXX"}
1
1

Returns: 4

Here clearing rows 1, 3 and 5, together with column 1 yields the best result 4.

4)
{"XXX..XXX..XXX.",
 ".X..X....X...X",
 ".X..X....X...X",
 ".X..X....X...X",
 ".X...XXX..XXX.",
 "..............",
 "...XX...XXX...",
 "....X......X..",
 "....X....XXX..",
 "....X......X..",
 "...XXX..XXX..."}
1
2

Returns: 7

Good luck in TCO 13!

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
		cout << "Testing EllysFigurines (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1396458243;
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
		EllysFigurines _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string board[] = {".X.X.",
				                  "XX..X",
				                  ".XXX.",
				                  "...X.",
				                  ".X.XX"};
				int R = 1;
				int C = 2;
				_expected = 3;
				_received = _obj.getMoves(vector <string>(board, board+sizeof(board)/sizeof(string)), R, C); break;
			}
			case 1:
			{
				string board[] = {".X.X.",
				                  "XX..X",
				                  ".X.X.",
				                  "...X.",
				                  ".X.XX"};
				int R = 2;
				int C = 2;
				_expected = 2;
				_received = _obj.getMoves(vector <string>(board, board+sizeof(board)/sizeof(string)), R, C); break;
			}
			case 2:
			{
				string board[] = {"XXXXXXX"};
				int R = 2;
				int C = 3;
				_expected = 1;
				_received = _obj.getMoves(vector <string>(board, board+sizeof(board)/sizeof(string)), R, C); break;
			}
			case 3:
			{
				string board[] = {"XXXXX",
				                  "X....",
				                  "XXX..",
				                  "X....",
				                  "XXXXX"};
				int R = 1;
				int C = 1;
				_expected = 4;
				_received = _obj.getMoves(vector <string>(board, board+sizeof(board)/sizeof(string)), R, C); break;
			}
			case 4:
			{
				string board[] = {"XXX..XXX..XXX.",
				                  ".X..X....X...X",
				                  ".X..X....X...X",
				                  ".X..X....X...X",
				                  ".X...XXX..XXX.",
				                  "..............",
				                  "...XX...XXX...",
				                  "....X......X..",
				                  "....X....XXX..",
				                  "....X......X..",
				                  "...XXX..XXX..."};
				int R = 1;
				int C = 2;
				_expected = 7;
				_received = _obj.getMoves(vector <string>(board, board+sizeof(board)/sizeof(string)), R, C); break;
			}
			case 5:
			{
				string board[] = {"X"};
				int R = 1;
				int C = 1;
				_expected = 1;
				_received = _obj.getMoves(vector <string>(board, board+sizeof(board)/sizeof(string)), R, C); break;
			}
			/*case 6:
			{
				string board[] = ;
				int R = ;
				int C = ;
				_expected = ;
				_received = _obj.getMoves(vector <string>(board, board+sizeof(board)/sizeof(string)), R, C); break;
			}*/
			/*case 7:
			{
				string board[] = ;
				int R = ;
				int C = ;
				_expected = ;
				_received = _obj.getMoves(vector <string>(board, board+sizeof(board)/sizeof(string)), R, C); break;
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
