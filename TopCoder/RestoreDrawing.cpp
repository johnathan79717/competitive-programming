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

#line 41 "RestoreDrawing.cpp"
#include <string>
#include <vector>
class RestoreDrawing {
public:
    vector <string> restore(vector <int> sizes4, vector <int> sizes8) {

    }
};

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
Basha and Misof want to decorate a rectangular wall of their flat by painting some black-and-white bitmap onto it. 
They now have to choose some bitmap that matches their desires.


Basha wants to have a bitmap such that the sizes of the 4-connected components of black cells are the numbers given in sizes4.
Misof wants to have a bitmap such that the sizes of the 8-connected components of black cells are the numbers given in sizes8.


Determine whether such a bitmap exists.
If no, return an empty vector <string>.
If yes, return any one such bitmap.
Your bitmap must be rectangular and it must contain at most 100 rows and at most 100 columns.
Use '.' to represent white cells and '#' to represent black cells.


DEFINITION
Class:RestoreDrawing
Method:restore
Parameters:vector <int>, vector <int>
Returns:vector <string>
Method signature:vector <string> restore(vector <int> sizes4, vector <int> sizes8)


NOTES
-Two black cells are 4-neighbors if we can move from one to the other by making a single step in one of the 4 cardinal directions. The 4-connected components of black cells are equivalence classes of the transitive closure of the 4-neighbor relation.
-The 8-connected components are defined the same way, but now diagonal movements are allowed as well.


CONSTRAINTS
-sizes4 will contain between 1 and 20 elements, inclusive.
-sizes8 will contain between 1 and 20 elements, inclusive.
-Each element of sizes4 will be a positive integer.
-Each element of sizes8 will be a positive integer.
-The sum of sizes4 will be at most 1500.
-The sum of sizes8 will be at most 1500.


EXAMPLES

0)
{1, 1, 1, 1, 1}
{5}

Returns: {"#.#", ".#.", "#.#" }

Nicely formatted output:

#.#
.#.
#.#



1)
{1, 1, 1, 1, 1}
{1, 1, 1, 1, 1}

Returns: {"#....", "..#.#", ".....", "#..#." }

Nicely formatted output:

#....
..#.#
.....
#..#.



2)
{2, 2, 2}
{3, 3}

Returns: { }



3)
{42}
{47}

Returns: { }



4)
{1, 2, 3, 5}
{7, 4}

Returns: {"##.##", "..##.", "#..#.", "##...", "..#.." }

Nicely formatted output:

##.##
..##.
#..#.
##...
..#..



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
		cout << "Testing RestoreDrawing (900.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1553945502;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 900.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		RestoreDrawing _obj;
		vector <string> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int sizes4[] = {1, 1, 1, 1, 1};
				int sizes8[] = {5};
				string __expected[] = {"#.#", ".#.", "#.#" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.restore(vector <int>(sizes4, sizes4+sizeof(sizes4)/sizeof(int)), vector <int>(sizes8, sizes8+sizeof(sizes8)/sizeof(int))); break;
			}
			case 1:
			{
				int sizes4[] = {1, 1, 1, 1, 1};
				int sizes8[] = {1, 1, 1, 1, 1};
				string __expected[] = {"#....", "..#.#", ".....", "#..#." };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.restore(vector <int>(sizes4, sizes4+sizeof(sizes4)/sizeof(int)), vector <int>(sizes8, sizes8+sizeof(sizes8)/sizeof(int))); break;
			}
			case 2:
			{
				int sizes4[] = {2, 2, 2};
				int sizes8[] = {3, 3};
				string __expected[] = { };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.restore(vector <int>(sizes4, sizes4+sizeof(sizes4)/sizeof(int)), vector <int>(sizes8, sizes8+sizeof(sizes8)/sizeof(int))); break;
			}
			case 3:
			{
				int sizes4[] = {42};
				int sizes8[] = {47};
				string __expected[] = { };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.restore(vector <int>(sizes4, sizes4+sizeof(sizes4)/sizeof(int)), vector <int>(sizes8, sizes8+sizeof(sizes8)/sizeof(int))); break;
			}
			case 4:
			{
				int sizes4[] = {1, 2, 3, 5};
				int sizes8[] = {7, 4};
				string __expected[] = {"##.##", "..##.", "#..#.", "##...", "..#.." };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.restore(vector <int>(sizes4, sizes4+sizeof(sizes4)/sizeof(int)), vector <int>(sizes8, sizes8+sizeof(sizes8)/sizeof(int))); break;
			}
			/*case 5:
			{
				int sizes4[] = ;
				int sizes8[] = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.restore(vector <int>(sizes4, sizes4+sizeof(sizes4)/sizeof(int)), vector <int>(sizes8, sizes8+sizeof(sizes8)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int sizes4[] = ;
				int sizes8[] = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.restore(vector <int>(sizes4, sizes4+sizeof(sizes4)/sizeof(int)), vector <int>(sizes8, sizes8+sizeof(sizes8)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int sizes4[] = ;
				int sizes8[] = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.restore(vector <int>(sizes4, sizes4+sizeof(sizes4)/sizeof(int)), vector <int>(sizes8, sizes8+sizeof(sizes8)/sizeof(int))); break;
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
