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

struct TheMagicMatrix {
  int find(int n, vector <int> rows, vector <int> columns, vector <int> values) {

  }
};

// BEGIN CUT HERE
/*
PROBLEM STATEMENT
A magic matrix is a square matrix filled with digits (0 to 
9) such that its row sums and column sums all have the 
same last digit.
John has n by n matrix.
Its rows and columns are numbered from 0 to n-1.
Some cells of the matrix already contain digits and some 
are empty.
John wants to assign a value to each empty cell to get a 
magic matrix.


You are given an int n and vector <int>s rows, columns, 
values.
The number values[i] is the digit in John's matrix at row 
rows[i] and at column columns[i].
Return the number of different matrices John can get 
modulo 1,234,567,891.


DEFINITION
Class:TheMagicMatrix
Method:find
Parameters:int, vector <int>, vector <int>, vector <int>
Returns:int
Method signature:int find(int n, vector <int> rows, vector 
<int> columns, vector <int> values)


CONSTRAINTS
-n will be between 1 and 1000, inclusive.
-rows will contain between 1 and 10 elements, inclusive.
-rows, columns and values will all contains the same 
number of elements.
-Each element of rows will be between 0 and n-1, inclusive.
-Each element of columns will be between 0 and n-1, 
inclusive.
-Each element of values will be between 0 and 9, inclusive.
-All pairs (rows[i], columns[i]) will be distinct.


EXAMPLES

0)
2
{0, 1}
{1, 0}
{4, 4}

Returns: 10

John will get a magic matrix only if he assigns equal 
values to both empty cells. 


1)
2
{0, 1}
{1, 0}
{4, 7}

Returns: 0



2)
4
{0, 0, 0, 1, 2, 2, 2, 3, 3, 3}
{0, 1, 2, 3, 0, 1, 2, 0, 1, 2}
{3, 5, 1, 9, 5, 1, 8, 6, 7, 1}

Returns: 2



3)
474
{44, 77}
{47, 74}
{4, 7}

Returns: 83494518



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
		cout << "Testing TheMagicMatrix (600.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1400397791;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 600.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		TheMagicMatrix _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 2;
				int rows[] = {0, 1};
				int columns[] = {1, 0};
				int values[] = {4, 4};
				_expected = 10;
				_received = _obj.find(n, vector <int>(rows, rows+sizeof(rows)/sizeof(int)), vector <int>(columns, columns+sizeof(columns)/sizeof(int)), vector <int>(values, values+sizeof(values)/sizeof(int))); break;
			}
			case 1:
			{
				int n = 2;
				int rows[] = {0, 1};
				int columns[] = {1, 0};
				int values[] = {4, 7};
				_expected = 0;
				_received = _obj.find(n, vector <int>(rows, rows+sizeof(rows)/sizeof(int)), vector <int>(columns, columns+sizeof(columns)/sizeof(int)), vector <int>(values, values+sizeof(values)/sizeof(int))); break;
			}
			case 2:
			{
				int n = 4;
				int rows[] = {0, 0, 0, 1, 2, 2, 2, 3, 3, 3};
				int columns[] = {0, 1, 2, 3, 0, 1, 2, 0, 1, 2};
				int values[] = {3, 5, 1, 9, 5, 1, 8, 6, 7, 1};
				_expected = 2;
				_received = _obj.find(n, vector <int>(rows, rows+sizeof(rows)/sizeof(int)), vector <int>(columns, columns+sizeof(columns)/sizeof(int)), vector <int>(values, values+sizeof(values)/sizeof(int))); break;
			}
			case 3:
			{
				int n = 474;
				int rows[] = {44, 77};
				int columns[] = {47, 74};
				int values[] = {4, 7};
				_expected = 83494518;
				_received = _obj.find(n, vector <int>(rows, rows+sizeof(rows)/sizeof(int)), vector <int>(columns, columns+sizeof(columns)/sizeof(int)), vector <int>(values, values+sizeof(values)/sizeof(int))); break;
			}
			/*case 4:
			{
				int n = ;
				int rows[] = ;
				int columns[] = ;
				int values[] = ;
				_expected = ;
				_received = _obj.find(n, vector <int>(rows, rows+sizeof(rows)/sizeof(int)), vector <int>(columns, columns+sizeof(columns)/sizeof(int)), vector <int>(values, values+sizeof(values)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int n = ;
				int rows[] = ;
				int columns[] = ;
				int values[] = ;
				_expected = ;
				_received = _obj.find(n, vector <int>(rows, rows+sizeof(rows)/sizeof(int)), vector <int>(columns, columns+sizeof(columns)/sizeof(int)), vector <int>(values, values+sizeof(values)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int n = ;
				int rows[] = ;
				int columns[] = ;
				int values[] = ;
				_expected = ;
				_received = _obj.find(n, vector <int>(rows, rows+sizeof(rows)/sizeof(int)), vector <int>(columns, columns+sizeof(columns)/sizeof(int)), vector <int>(values, values+sizeof(values)/sizeof(int))); break;
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
