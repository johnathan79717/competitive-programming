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
#define ALL(x) (x).begin(),(x).end()
#define PB push_back
 
typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;

class PathGame {
	public:
	string judge(vector <string> board) {
		int prev = -1;
		int N = board[0].size();
		int ans = 0;
		VI dp(1001, -1);
		dp[0] = 0;
		dp[1] = 1;
		dp[2] = 1;
		dp[3] = 2;
		REP1(i, 4, 1000) {
			VI cand;
			cand.PB(dp[i-2]);
			REP1(j, 1, i-4) {
				cand.PB(dp[j] ^ dp[i-3-j]);
			}
			sort(ALL(cand));
			cand.resize(unique(ALL(cand)) - cand.begin());
			cand.PB(cand.size() + 2);
			REP(j, cand.size()) {
				if (cand[j] != j) {
					dp[i] = j;
					break;
				}
			}
		}
		REP(i, N) {
			if(board[0][i] == '#' || board[1][i] == '#') {
				if(prev >= 0) {
					if (i - prev - 3 >= 0) {
						ans ^= dp[i - prev - 3];
						cout << i - prev - 3 << endl;
					}
				} else {
					if (i > 0) {
						ans ^= dp[i-1];
						cout << i-1 << endl;
					}
				}
				prev = i;
			}
		}
		int i = N+1;
				if(prev >= 0) {
					if (i - prev - 3 >= 0) {
						ans ^= dp[i - prev - 3];
						cout << i - prev - 3 << endl;
					}
				} else {
					if (i > 0) {
						ans ^= dp[i-1];
						cout << i-1 << endl;
					}
				}
		if (ans) return "Snuke";
		else return "Sothe";
	}
};
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Cat Snuke and wolf Sothe are playing the Path Game.

The Path Game is played on a rectangular grid of square cells.
The grid has 2 rows and some positive number of columns.
Each cell is either black or white.

A left-to-right path in the grid is a sequence of white cells such that the first cell in the sequence is in the leftmost column, the last cell in the sequence is in the rightmost column, and each pair of consecutive cells shares a common side.

The initial coloring of the grid is such that there is at least one left-to-right path.
You are given this initial coloring as a vector <string> board with two elements.
For each i and j, board[i][j] is either '#' (representing a black cell) or '.' (representing a white cell).

The players take alternating turns.
In each turn, the current player has to choose and color one white cell black.
Snuke goes first.
The game ends when there is no longer a left-to-right path on the board.
The last player who colored a cell loses the game.
In other words, the loser is the player who was forced to block the last left-to-right path.

Assume that both players play the game optimally.
Return "Snuke" (quotes for clarity) if Snuke wins the game, and "Sothe" otherwise.

DEFINITION
Class:PathGame
Method:judge
Parameters:vector <string>
Returns:string
Method signature:string judge(vector <string> board)


CONSTRAINTS
-board will contain 2 elements.
-Each element in board will contain between 1 and 1000 characters, inclusive.
-All elements in board will have the same length.
-Each character in board will be '#' or '.'.
-The grid described by board will contain a left-to-right path.


EXAMPLES

0)
{"#.."
,"..."}

Returns: "Snuke"

Snuke has exactly one winning move: he must color the lower right cell.
After this move the resulting grid will still contain a left-to-right path.
Sothe will then have four possible moves, but each of those loses the game immediately.

1)
{"#"
,"."}

Returns: "Sothe"

Snuke has to color the only white cell black, and he immediately loses the game.

2)
{"....."
,"..#.."}

Returns: "Sothe"



3)
{".#..."
,"....."}

Returns: "Snuke"



4)
{".....#..#........##......."
,"..........#..........#...."}

Returns: "Snuke"



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
		cout << "Testing PathGame (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1414080288;
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
		PathGame _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string board[] = {"#.."
				                 ,"..."};
				_expected = "Snuke";
				_received = _obj.judge(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 1:
			{
				string board[] = {"#"
				                 ,"."};
				_expected = "Sothe";
				_received = _obj.judge(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 2:
			{
				string board[] = {"....."
				                 ,"..#.."};
				_expected = "Sothe";
				_received = _obj.judge(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 3:
			{
				string board[] = {".#..."
				                 ,"....."};
				_expected = "Snuke";
				_received = _obj.judge(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 4:
			{
				string board[] = {".....#..#........##......."
				                 ,"..........#..........#...."};
				_expected = "Snuke";
				_received = _obj.judge(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			/*case 5:
			{
				string board[] = ;
				_expected = ;
				_received = _obj.judge(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string board[] = ;
				_expected = ;
				_received = _obj.judge(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string board[] = ;
				_expected = ;
				_received = _obj.judge(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
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
