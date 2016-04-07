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

class BichromePainting {
	public:
	string isThatPossible(vector <string> board, int k) {
		
	}
};
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// We have a square board divided into a grid of unit square cells.
Initially each cell is white.
You are given a vector <string> board that describes the desired final state.
In the final state each cell is either white ('W') or black ('B').


You are also given an int k.
The only change you can make to the board looks as follows:
You may select any square of k by k cells and repaint all of them using the same color: either black or white.
Later changes to the board may overlap previous ones.


Return "Possible" if we can obtain the desired final state.
Otherwise, return "Impossible".

DEFINITION
Class:BichromePainting
Method:isThatPossible
Parameters:vector <string>, int
Returns:string
Method signature:string isThatPossible(vector <string> board, int k)


CONSTRAINTS
-n will be between 1 and 20, inclusive.
-k will be between 1 and n, inclusive.
-board will contain exactly n elements.
-Each element in board will contain exactly n characters.
-Each character in board will be 'W' or 'B'.


EXAMPLES

0)
{"BBBW",
 "BWWW",
 "BWWW",
 "WWWW"}
3

Returns: "Possible"

We can reach the desired state by doing two changes.
First we paint the 3x3 square in the top left corner black:

BBBW
BBBW
BBBW
WWWW

Then we paint the 3x3 square in the bottom right corner white.

1)
{"BW",
 "WB"}

2

Returns: "Impossible"

We can get only an all-white board and an all-black board.

2)
{"BWBWBB",
 "WBWBBB",
 "BWBWBB",
 "WBWBBB",
 "BBBBBB",
 "BBBBBB"}

2

Returns: "Possible"



3)
{"BWBWBB",
 "WBWBWB",
 "BWBWBB",
 "WBWBWB",
 "BWBWBB",
 "BBBBBB"}

2

Returns: "Impossible"



4)
{"BWBWBB",
 "WBWBWB",
 "BWBWBB",
 "WBWBWB",
 "BWBWBB",
 "BBBBBB"}

1

Returns: "Possible"



5)
{"BB",
 "BB"}
2

Returns: "Possible"



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
		cout << "Testing BichromePainting (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1428591736;
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
		BichromePainting _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string board[] = {"BBBW",
				                  "BWWW",
				                  "BWWW",
				                  "WWWW"};
				int k = 3;
				_expected = "Possible";
				_received = _obj.isThatPossible(vector <string>(board, board+sizeof(board)/sizeof(string)), k); break;
			}
			case 1:
			{
				string board[] = {"BW",
				                  "WB"};
				int k = 2;
				_expected = "Impossible";
				_received = _obj.isThatPossible(vector <string>(board, board+sizeof(board)/sizeof(string)), k); break;
			}
			case 2:
			{
				string board[] = {"BWBWBB",
				                  "WBWBBB",
				                  "BWBWBB",
				                  "WBWBBB",
				                  "BBBBBB",
				                  "BBBBBB"};
				int k = 2;
				_expected = "Possible";
				_received = _obj.isThatPossible(vector <string>(board, board+sizeof(board)/sizeof(string)), k); break;
			}
			case 3:
			{
				string board[] = {"BWBWBB",
				                  "WBWBWB",
				                  "BWBWBB",
				                  "WBWBWB",
				                  "BWBWBB",
				                  "BBBBBB"};
				int k = 2;
				_expected = "Impossible";
				_received = _obj.isThatPossible(vector <string>(board, board+sizeof(board)/sizeof(string)), k); break;
			}
			case 4:
			{
				string board[] = {"BWBWBB",
				                  "WBWBWB",
				                  "BWBWBB",
				                  "WBWBWB",
				                  "BWBWBB",
				                  "BBBBBB"};
				int k = 1;
				_expected = "Possible";
				_received = _obj.isThatPossible(vector <string>(board, board+sizeof(board)/sizeof(string)), k); break;
			}
			case 5:
			{
				string board[] = {"BB",
				                  "BB"};
				int k = 2;
				_expected = "Possible";
				_received = _obj.isThatPossible(vector <string>(board, board+sizeof(board)/sizeof(string)), k); break;
			}
			/*case 6:
			{
				string board[] = ;
				int k = ;
				_expected = ;
				_received = _obj.isThatPossible(vector <string>(board, board+sizeof(board)/sizeof(string)), k); break;
			}*/
			/*case 7:
			{
				string board[] = ;
				int k = ;
				_expected = ;
				_received = _obj.isThatPossible(vector <string>(board, board+sizeof(board)/sizeof(string)), k); break;
			}*/
			/*case 8:
			{
				string board[] = ;
				int k = ;
				_expected = ;
				_received = _obj.isThatPossible(vector <string>(board, board+sizeof(board)/sizeof(string)), k); break;
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
