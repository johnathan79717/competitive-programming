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

#line 40 "MovingCandies.cpp"
#include <string>
#include <vector>
class MovingCandies {
public:
  int minMoved(vector <string> t) {

  }
};

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Limak is a little bear.
He is currently planning a walk on a rectangular grid.
Each cell of the grid is either empty or it contains a single candy.
Empty cells are denoted '.', cells with a candy are denoted '#'.

Limak wants to go from the top-left corner to the bottom-right corner of the grid.
Since he loves sweets, there should be a candy in each cell he visits, including the starting and the final cell.
He can only move in the four cardinal directions.
In other words, he can move from cell A directly to cell B if and only if A and B share a side.

You are given the vector <string> t: the current state of the grid.
Limak's journey may be impossible on the current grid.
Your task is to make it possible by moving as few candies as you can.
Moving a candy means picking it up and placing it into any empty cell.

Return the smallest number of candies that have to be moved in order to make Limak's journey possible.
If there is no solution, return -1 instead.

DEFINITION
Class:MovingCandies
Method:minMoved
Parameters:vector <string>
Returns:int
Method signature:int minMoved(vector <string> t)


CONSTRAINTS
-t will have between 2 and 20 elements, inclusive.
-Each element of t will have between 2 and 20 characters, inclusive.
-Each element of t will have the same number of characters.
-Each character in each element of t will be either '.' or '#'.


EXAMPLES

0)
{
"#...###",
"#...#.#",
"##..#.#",
".#....#"
}

Returns: 3

You must move at least 3 candies.
One way of doing so is shown in the grid below.
Candies were moved from cells denoted 'o' to cells denoted 'X'.

#...###
#XXX#.#
oo..o.#
.#....#


1)
{
"#...###",
"#...#.#",
"##..###",
".#....#"
}

Returns: 2

2 moves are enough in this example:

#...###
#...#.#
##XX#o#
.o....#


2)
{
".#..",
"##..",
"..#.",
"..#.",
"..##",
"..##"
}

Returns: 2

Note that the starting and the final cell should both contain candies.

3)
{
".....",
".###.",
"####.",
"....."
}

Returns: -1

No matter how you move candies, Limak won't be able to get from the top-left to the bottom-right corner.

4)
{
".#...#.###.#",
"#.#.##......",
".#.#......#.",
"..#.......#.",
"##.........."
}

Returns: 9



5)
{
"###.#########..#####",
".#######.###########"
}

Returns: 0

You don't have to move any candies.
Limak can already go from the top-left to the bottom-right corner.

6)
{
"..",
".."
}

Returns: -1



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
		cout << "Testing MovingCandies (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1485014403;
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
		MovingCandies _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string t[] = {
				             "#...###",
				             "#...#.#",
				             "##..#.#",
				             ".#....#"
				             };
				_expected = 3;
				_received = _obj.minMoved(vector <string>(t, t+sizeof(t)/sizeof(string))); break;
			}
			case 1:
			{
				string t[] = {
				             "#...###",
				             "#...#.#",
				             "##..###",
				             ".#....#"
				             };
				_expected = 2;
				_received = _obj.minMoved(vector <string>(t, t+sizeof(t)/sizeof(string))); break;
			}
			case 2:
			{
				string t[] = {
				             ".#..",
				             "##..",
				             "..#.",
				             "..#.",
				             "..##",
				             "..##"
				             };
				_expected = 2;
				_received = _obj.minMoved(vector <string>(t, t+sizeof(t)/sizeof(string))); break;
			}
			case 3:
			{
				string t[] = {
				             ".....",
				             ".###.",
				             "####.",
				             "....."
				             };
				_expected = -1;
				_received = _obj.minMoved(vector <string>(t, t+sizeof(t)/sizeof(string))); break;
			}
			case 4:
			{
				string t[] = {
				             ".#...#.###.#",
				             "#.#.##......",
				             ".#.#......#.",
				             "..#.......#.",
				             "##.........."
				             };
				_expected = 9;
				_received = _obj.minMoved(vector <string>(t, t+sizeof(t)/sizeof(string))); break;
			}
			case 5:
			{
				string t[] = {
				             "###.#########..#####",
				             ".#######.###########"
				             };
				_expected = 0;
				_received = _obj.minMoved(vector <string>(t, t+sizeof(t)/sizeof(string))); break;
			}
			case 6:
			{
				string t[] = {
				             "..",
				             ".."
				             };
				_expected = -1;
				_received = _obj.minMoved(vector <string>(t, t+sizeof(t)/sizeof(string))); break;
			}
			/*case 7:
			{
				string t[] = ;
				_expected = ;
				_received = _obj.minMoved(vector <string>(t, t+sizeof(t)/sizeof(string))); break;
			}*/
			/*case 8:
			{
				string t[] = ;
				_expected = ;
				_received = _obj.minMoved(vector <string>(t, t+sizeof(t)/sizeof(string))); break;
			}*/
			/*case 9:
			{
				string t[] = ;
				_expected = ;
				_received = _obj.minMoved(vector <string>(t, t+sizeof(t)/sizeof(string))); break;
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
