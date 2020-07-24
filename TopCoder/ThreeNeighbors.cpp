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
#include <cassert>
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
 
typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;

#line 41 "ThreeNeighbors.cpp"
#include <string>
#include <vector>
class ThreeNeighbors {
public:
    vector <string> construct(int N) {
	vector<string> ans(50, string(50, '.'));
	for (int i = 0; i < N / 96; i++) {
	    int r = 3 * (i + 1);
	    REP(c, 50) {
		ans[r][c] = 'X';
	    }
	}
	N %= 96;
	if (N <= 48) {
	    REP(c, N + 2) {
		ans[0][c] = 'X';
	    }
	} else {
	    REP(c, 50) {
		ans[0][c] = 'X';
	    }
	    N -= 48;
	    REP(c, N + 2) {
		ans[49][c] = 'X';
	    }
	}
	return ans;
    }
};

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
Game of Life is a cellular automaton invented by the recently deceased mathematician John H. Conway. We included this problem into today's set to honor his memory.


In our version of the Game of Life the world is a rectangular array of cells.
Each cell is either alive ('X') or dead ('.').
Each cell has up to eight neighbors: horizontal, vertical, and diagonal.
Cells at the boundary have fewer than eight neighbors.


The world evolves in steps. In each step some living cells may die and some dead cells may become alive.
In particular, a cell that is currently dead will become a living cell in the next step if and only if it currently has exactly three neighbors that are alive.


You are given the int N.
Find any rectangular configuration of cells with dimensions at most 50x50 and with the following property: in the next step, exactly N of the dead cells will become living cells.
Return your configuration as a vector <string>.




DEFINITION
Class:ThreeNeighbors
Method:construct
Parameters:int
Returns:vector <string>
Method signature:vector <string> construct(int N)


NOTES
-For the given constraints a solution always exists, and any valid solution will be accepted.
-We only care about the number of cells that change from dead to living. All other parameters of your world (dimensions, the number of cells that die, the total number of cells, etc.) may be arbitrary.


CONSTRAINTS
-N will be between 1 and 500, inclusive.


EXAMPLES

0)
2

Returns: {".....", ".XX..", ".X.X.", ".X...", "....." }


The return value corresponds to a configuration of cells known as a "glider":


.....
.XX..
.X.X.
.X...
.....


Below, the two cells that will become alive in the next step are marked with asterisks. Each of these dead cells has exactly three neighbors that are alive.


.....
.XX..
*X.X.
.X*..
.....



1)
6

Returns: {"........", ".XXX..X.", "..X..X..", "..X..X..", "..X...X.", "........" }


..*.....
.XXX..X.
..X.*X*.
.*X*.X*.
..X...X.
........


2)
1

Returns: {"XXXX", "XXXX", ".XXX" }


XXXX
XXXX
*XXX


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
		cout << "Testing ThreeNeighbors (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1587226349;
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
		ThreeNeighbors _obj;
		vector <string> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 2;
				string __expected[] = {".....", ".XX..", ".X.X.", ".X...", "....." };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.construct(N); break;
			}
			case 1:
			{
				int N = 6;
				string __expected[] = {"........", ".XXX..X.", "..X..X..", "..X..X..", "..X...X.", "........" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.construct(N); break;
			}
			case 2:
			{
				int N = 1;
				string __expected[] = {"XXXX", "XXXX", ".XXX" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.construct(N); break;
			}
			/*case 3:
			{
				int N = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.construct(N); break;
			}*/
			/*case 4:
			{
				int N = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.construct(N); break;
			}*/
			/*case 5:
			{
				int N = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.construct(N); break;
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
			cout << "           Expected: {";
			for (unsigned i = 0; i < _expected.size(); i++)
			{
				if (i) cout << ",";
				cout << " \"" << _expected[i] << "\"";
			}
			cout << " }" << endl;
			cout << "           Received: {";
			for (unsigned i = 0; i < _received.size(); i++)
			{
				if (i) cout << ",";
				cout << " \"" << _received[i] << "\"";
			}
			cout << " }" << endl;
		}
	}
}

// END CUT HERE
