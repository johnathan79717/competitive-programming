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
#define FOR(i, c) for(auto &i: c)
#define PER(i,n) for(int i=(n)-1;i>=0;i--)
#define PER1(i,a,b) for(int i=(a);i>=(b);i--)
#define MP make_pair
#define PB push_back
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,-1,sizeof(x))
#define V(T) vector<T >
#define EB emplace_back
 
typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;

class RobotOnMoon {
	public:
	int longestSafeCommand(vector <string> board) {
		int N = board.size(), M = board[0].size();
		int si, sj;
		REP(i, N) {
			REP(j, M) {
				if (board[i][j] == 'S') {
					si = i;
					sj = j;
				}
			}
		}
		PER1(i, si-1, 0) {
			if (board[i][sj] == '#') {
				return -1;
			}
		}
		PER1(j, sj-1, 0) {
			if (board[si][j] == '#') {
				return -1;
			}
		}
		REP1(i, si+1, N-1) {
			if (board[i][sj] == '#') {
				return -1;
			}
		}
		REP1(j, sj+1, M-1) {
			if (board[si][j] == '#') {
				return -1;
			}
		}
		return N-1 + M-1;
	}
};
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// There is a robot on the moon.
You are given a vector <string> board containing the map of a rectangular area.
The robot is currently located somewhere in that area.
In the map, the character '.' (period) represents an empty square, 'S' represents an empty square that currently contains the robot, and '#' represents an obstacle.


We are going to send a sequence of commands to the robot.
Each command must be one of 'U', 'D', 'L', and 'R', representing a step up, down, left, and right, respectively.


Whenever the robot receives a command, one of three things will happen:

If the requested move leads to an empty square, the robot performs the move.
If the requested move leads to a square with an obstacle, the robot ignores the command and remains in place.
If the requested move leads out of the mapped area, the robot leaves the mapped area and dies immediately.



A sequence of commands is called safe if the robot is still alive after executing the entire sequence.


When sending commands to the moon, some of them may get lost along the way.
This may sometimes change a safe sequence of commands into an unsafe one.
We want to avoid that.


A sequence of commands is called perfectly safe if it is safe, and each of its subsequences is safe as well.
(Note that this includes subsequences that are not contiguous.)


Find and return the largest X such that there is a perfectly safe sequence of X commands.
If there are arbitrarily long perfectly safe sequences, return -1 instead.

DEFINITION
Class:RobotOnMoon
Method:longestSafeCommand
Parameters:vector <string>
Returns:int
Method signature:int longestSafeCommand(vector <string> board)


NOTES
-The direction 'U' corresponds to moving from board[i][j] to board[i-1][j]. The direction 'L' corresponds to moving from board[i][j] to board[i][j-1].


CONSTRAINTS
-board will contain between 1 and 50 elements, inclusive.
-Each element of board will contain between 1 and 50 characters.
-Each element of board will contain same number of characters.
-The characters in board will be '.', '#' or 'S'.
-There will be exactly one 'S' in board.


EXAMPLES

0)
{"#####",
 "#...#",
 "#.S.#",
 "#...#",
 "#####"}

Returns: -1

There are obstacles all around the map. This means that all possible sequences of commands are perfectly safe.

1)
{"S......"}

Returns: 6

The longest perfectly safe string is "RRRRRR"

2)
{"#.######",
 "#.#..S.#",
 "#.#.##.#",
 "#......#",
 "########"}

Returns: -1

Even though it is possible to leave this map, there are still arbitrarily long perfectly safe sequences of commands. For example, any sequence that does not contain any 'U' is perfectly safe.

3)
{"S"}

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
		cout << "Testing RobotOnMoon (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1425142861;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 250.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		RobotOnMoon _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string board[] = {"#####",
				                  "#...#",
				                  "#.S.#",
				                  "#...#",
				                  "#####"};
				_expected = -1;
				_received = _obj.longestSafeCommand(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 1:
			{
				string board[] = {"S......"};
				_expected = 6;
				_received = _obj.longestSafeCommand(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 2:
			{
				string board[] = {"#.######",
				                  "#.#..S.#",
				                  "#.#.##.#",
				                  "#......#",
				                  "########"};
				_expected = -1;
				_received = _obj.longestSafeCommand(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 3:
			{
				string board[] = {"S"};
				_expected = 0;
				_received = _obj.longestSafeCommand(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			/*case 4:
			{
				string board[] = ;
				_expected = ;
				_received = _obj.longestSafeCommand(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}*/
			/*case 5:
			{
				string board[] = ;
				_expected = ;
				_received = _obj.longestSafeCommand(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string board[] = ;
				_expected = ;
				_received = _obj.longestSafeCommand(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
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
