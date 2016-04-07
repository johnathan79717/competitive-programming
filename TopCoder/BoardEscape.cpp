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
#define MAX(x, a) x = max(x, a)
#define MIN(x, a) x = min(x, a)

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;
#line 39 "BoardEscape.cpp"
#include <string>
#include <vector>

int d[51][51];

class BoardEscape {
    public:
    string findWinner(vector <string> s, int k) {
        k = (k - 1) % 4 + 1;
        int N = s.size(), M = s[0].size();
        int ei, ej;
        REP(i, N) {
            REP(j, M) {
                if (s[i][j] == 'E') {
                    ei = i;
                    ej = j;
                }
            }
        }            
        queue<PII> q;
        q.emplace(ei, ej);
        int dx[] = {-1, 0, 1, -1}, dy[] = {0, 1, 0, -1};
        MS1(d);
        d[ei][ej] = 0;
        while (q.size()) {
            int x = q.front().first, y = q.front().second;
            REP(i, 4) {
                int xx = x + dx[i], yy = y + dy[i];
                if (xx >= 0 && xx < N && yy >= 0 && yy < M && s[xx][yy] != '#' && d[x][y] >= 0) {
                    d[xx][yy] = d[x][y] + 1;
                    q.emplace(xx, yy);
                }
            }
        }
        int ans = 0;

        return ans ? "Alice" : "Bob";
    }
};
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
Alice and Bob have a rectangular board divided into a grid with r rows and c columns.
The grid is described by the vector <string> s.
Each character of s represents one cell.
There are four types of cells:

'E' denotes an exit. There may be arbitrarily many exits, possibly zero.
'T' means the square contains a single token. There may be arbitrarily many tokens, possibly zero.
'#' denotes an obstacle.
'.' denotes an empty cell.




Alice and Bob will play a game on this board.
The game is parameterized by the int k.
Each token initially has the number k on it.
The players will take alternating turns, starting with Alice.
A player's turn consists of the following steps:

The player chooses a single token on the board and moves it one square up, down, left, or right. The token cannot go over the edge of the board and it cannot enter a cell with an obstacle. The token may be moved into a cell that already contains other token(s). During the game, arbitrarily many tokens may share the same cell.
If this token is on an exit, it disappears from the board.
Otherwise, subtract one from the number on the token. If the number on the token is zero, remove it from the board. (The numbers on other tokens do not change.)




The first player unable to make a move loses the game.



You are given the vector <string> s and the int k
Compute the winner of the game, assuming both Alice and Bob play optimally.
Return the winner's name: either "Alice" or "Bob".


DEFINITION
Class:BoardEscape
Method:findWinner
Parameters:vector <string>, int
Returns:string
Method signature:string findWinner(vector <string> s, int k)


CONSTRAINTS
-r,c will be between 1 and 50, inclusive.
-s will contain exactly r elements, each consisting of c characters.
-Each character of each element of s will be one of 'T', 'E', '#', or '.'.
-k will be between 1 and 1,000,000,000, inclusive.


EXAMPLES

0)
{"TE"}
2

Returns: "Alice"

Alice can move the token directly to the exit on her first move, making Bob unable to move.

1)
{"E#E",
 "#T#",
 "E#E"}
1000000

Returns: "Bob"

Alice is unable to make the first move in this case.

2)
{"T.T.T.",
 ".E.E.E"}
1

Returns: "Alice"



3)
{"TTE"}
6

Returns: "Alice"



4)
{"..........................",
 "......TTT..TTT..T...T.....",
 ".....T.....T..T.TT.TT.....",
 "......TTT..TTT..T.T.T.....",
 ".........T.T.T..T...T.....",
 "......TTT..T..T.T...T.....",
 "..........................",
 "...E#E#E#E#E#E#E#E#E#E#...",
 "..........................",
 "......TTT..TTT...TTT......",
 ".....T........T.T.........",
 "......TTT.....T..TTT......",
 ".....T...T...T..T...T.....",
 "......TTT....T...TTT......",
 "..........................",
 "...#E#E#E#E#E#E#E#E#E#E...",
 "..........................",
 "....TT...T...T..T.TTT.T...",
 "...T.....T...T..T.T...T...",
 "...T.TT..T...TTTT.TT..T...",
 "...T..T..T...T..T.T.......",
 "....TT...TTT.T..T.T...T...",
 ".........................."}
987654321

Returns: "Bob"



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
		cout << "Testing BoardEscape (450.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1450455347;
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
		BoardEscape _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string s[] = {"TE"};
				int k = 2;
				_expected = "Alice";
				_received = _obj.findWinner(vector <string>(s, s+sizeof(s)/sizeof(string)), k); break;
			}
			case 1:
			{
				string s[] = {"E#E",
				              "#T#",
				              "E#E"};
				int k = 1000000;
				_expected = "Bob";
				_received = _obj.findWinner(vector <string>(s, s+sizeof(s)/sizeof(string)), k); break;
			}
			case 2:
			{
				string s[] = {"T.T.T.",
				              ".E.E.E"};
				int k = 1;
				_expected = "Alice";
				_received = _obj.findWinner(vector <string>(s, s+sizeof(s)/sizeof(string)), k); break;
			}
			case 3:
			{
				string s[] = {"TTE"};
				int k = 6;
				_expected = "Alice";
				_received = _obj.findWinner(vector <string>(s, s+sizeof(s)/sizeof(string)), k); break;
			}
			case 4:
			{
				string s[] = {"..........................",
				              "......TTT..TTT..T...T.....",
				              ".....T.....T..T.TT.TT.....",
				              "......TTT..TTT..T.T.T.....",
				              ".........T.T.T..T...T.....",
				              "......TTT..T..T.T...T.....",
				              "..........................",
				              "...E#E#E#E#E#E#E#E#E#E#...",
				              "..........................",
				              "......TTT..TTT...TTT......",
				              ".....T........T.T.........",
				              "......TTT.....T..TTT......",
				              ".....T...T...T..T...T.....",
				              "......TTT....T...TTT......",
				              "..........................",
				              "...#E#E#E#E#E#E#E#E#E#E...",
				              "..........................",
				              "....TT...T...T..T.TTT.T...",
				              "...T.....T...T..T.T...T...",
				              "...T.TT..T...TTTT.TT..T...",
				              "...T..T..T...T..T.T.......",
				              "....TT...TTT.T..T.T...T...",
				              ".........................."};
				int k = 987654321;
				_expected = "Bob";
				_received = _obj.findWinner(vector <string>(s, s+sizeof(s)/sizeof(string)), k); break;
			}
			/*case 5:
			{
				string s[] = ;
				int k = ;
				_expected = ;
				_received = _obj.findWinner(vector <string>(s, s+sizeof(s)/sizeof(string)), k); break;
			}*/
			/*case 6:
			{
				string s[] = ;
				int k = ;
				_expected = ;
				_received = _obj.findWinner(vector <string>(s, s+sizeof(s)/sizeof(string)), k); break;
			}*/
			/*case 7:
			{
				string s[] = ;
				int k = ;
				_expected = ;
				_received = _obj.findWinner(vector <string>(s, s+sizeof(s)/sizeof(string)), k); break;
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
