#include <string>
#include <cassert>
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
// #line 40 "GridSortMax.cpp"
#include <string>
#include <vector>
class GridSortMax {
public:
    string findMax(int n, int m, vector <int> grid) {
        
    }
};
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
Charlie has a grid of n rows by m columns.
The rows are numbered 0 through n-1 from top to bottom.
The columns are numbered 0 through m-1 from left to right.



Each cell of the grid contains a positive integer.
The integers in Charlie's grid are a permutation of the numbers 1 through n*m.
(I.e., each of these numbers occurs in the grid exactly once.)



Given a grid, its value list is a sequence constructed by listing all values in the grid in row major order.
That is, we first list the values in row 0 from left to right, then the values in row 1 from left to right, and so on.



You are given the ints n and m: the dimensions of Charlie's grid.
You are also given a vector <int> grid: the value list for Charlie's grid.
(Formally, grid[i*m+j] is the value stored in row i, column j of the grid.)



In Charlie's eyes, the most beautiful of all grids is the sorted grid: the grid whose value list is the ordered ordered sequence {1,2,3,...,n*m}.



Given a grid, its similarity string is a string of zeroes and ones that describes the similarity between that particular grid and the sorted grid. More precisely:

The similarity string is a string of length n*m.
For each i, character i of the similarity string is '1' if both grids have the same i-th element in their value lists, and it is '0' if those values differ. (All indices in the previous sentence are 0-based.)




For example, suppose n=2 and m=3. The sorted grid has the value list {1,2,3,4,5,6}, and its similarity string is "111111". Another possible grid with these dimensions has the value list {1,5,2,4,3,6}. The similarity string for this grid is "100101".



Charlie can modify his grid in two ways: He may swap any two rows, and he may swap any two columns.
He wants to use these operations to obtain a grid with the lexicographically largest possible similarity string.
Find and return that string.


DEFINITION
Class:GridSortMax
Method:findMax
Parameters:int, int, vector <int>
Returns:string
Method signature:string findMax(int n, int m, vector <int> grid)


CONSTRAINTS
-n,m will be between 1 and 50, inclusive.
-grid will be a permutation of [1,...,n*m]


EXAMPLES

0)
2
2
{
 1,2,
 3,4
}

Returns: "1111"

Charlie's grid is the sorted grid.
Its similarity string is therefore "1111".
Charlie should make no changes to the grid, as this is already the lexicographically largest of all possible strings.

1)
2
2
{
 2,1,
 3,4
}

Returns: "1100"

The similarity string for Charlie's current grid is "0011", as the values 3 and 4 are in the same places as in the sorted grid.
Charlie should swap the two columns.
That swap will produce a grid with the similarity string "1100": now the values 1 and 2 are in their correct places but the values 3 and 4 aren't.

2)
2
2
{
 4,2,
 3,1
}

Returns: "1001"



3)
1
10
{10,6,2,3,5,7,1,9,4,8}

Returns: "1111111111"



4)
3
5
{
 5,2,10,7,9,
 3,4,14,11,1,
 15,12,6,8,13
}

Returns: "101100100100000"



5)
6
2
{
 3,9,
 5,1,
 10,6,
 2,7,
 8,11,
 12,4
}

Returns: "100000101010"



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
		cout << "Testing GridSortMax (300.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1481600908;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 300.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		GridSortMax _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 2;
				int m = 2;
				int grid[] = {
				              1,2,
				              3,4
				             };
				_expected = "1111";
				_received = _obj.findMax(n, m, vector <int>(grid, grid+sizeof(grid)/sizeof(int))); break;
			}
			case 1:
			{
				int n = 2;
				int m = 2;
				int grid[] = {
				              2,1,
				              3,4
				             };
				_expected = "1100";
				_received = _obj.findMax(n, m, vector <int>(grid, grid+sizeof(grid)/sizeof(int))); break;
			}
			case 2:
			{
				int n = 2;
				int m = 2;
				int grid[] = {
				              4,2,
				              3,1
				             };
				_expected = "1001";
				_received = _obj.findMax(n, m, vector <int>(grid, grid+sizeof(grid)/sizeof(int))); break;
			}
			case 3:
			{
				int n = 1;
				int m = 10;
				int grid[] = {10,6,2,3,5,7,1,9,4,8};
				_expected = "1111111111";
				_received = _obj.findMax(n, m, vector <int>(grid, grid+sizeof(grid)/sizeof(int))); break;
			}
			case 4:
			{
				int n = 3;
				int m = 5;
				int grid[] = {
				              5,2,10,7,9,
				              3,4,14,11,1,
				              15,12,6,8,13
				             };
				_expected = "101100100100000";
				_received = _obj.findMax(n, m, vector <int>(grid, grid+sizeof(grid)/sizeof(int))); break;
			}
			case 5:
			{
				int n = 6;
				int m = 2;
				int grid[] = {
				              3,9,
				              5,1,
				              10,6,
				              2,7,
				              8,11,
				              12,4
				             };
				_expected = "100000101010";
				_received = _obj.findMax(n, m, vector <int>(grid, grid+sizeof(grid)/sizeof(int))); break;
			}
			/*case 6:
			{
				int n = ;
				int m = ;
				int grid[] = ;
				_expected = ;
				_received = _obj.findMax(n, m, vector <int>(grid, grid+sizeof(grid)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int n = ;
				int m = ;
				int grid[] = ;
				_expected = ;
				_received = _obj.findMax(n, m, vector <int>(grid, grid+sizeof(grid)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int n = ;
				int m = ;
				int grid[] = ;
				_expected = ;
				_received = _obj.findMax(n, m, vector <int>(grid, grid+sizeof(grid)/sizeof(int))); break;
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
