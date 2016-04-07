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

class ModModMod {
	public:
	long long findSum(vector <int> m, int R) {
		
	}
};
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
Moose Mod has just learned about the mod operator.
Given two positive integers x and y, the mod operator returns the remainder when x is divided by y.
For example, 17 mod 5 = 2 because 17 = 3*5 + 2.



Moose Mod has just defined a function that applies a sequence of N mod operators to its input.
Formally, the function looks as follows:
f(x) = (((x mod m[0]) mod m[1]) ... mod m[N-1]).
For example, m = { 10, 3 } corresponds to the function f(x) = (x mod 10) mod 3.
For this function we have f(18) = (18 mod 10) mod 3 = 8 mod 3 = 2.



You are given the vector <int> m.
You are also given a int R.
Moose Mod is interested in finding the sum f(1) + f(2) + ... + f(R).
Compute and return its value.


DEFINITION
Class:ModModMod
Method:findSum
Parameters:vector <int>, int
Returns:long long
Method signature:long long findSum(vector <int> m, int R)


CONSTRAINTS
-m will have between 1 and 5,000 elements, inclusive.
-Each element of m will be between 1 and 10,000,000, inclusive.
-R will be between 1 and 10,000,000, inclusive.


EXAMPLES

0)
{5,3,2}
10

Returns: 4

The values of f from 1 to 10 are 1, 0, 0, 1, 0, 1, 0, 0, 1, 0. The sum of all these values is 4.

1)
{33, 15, 7, 10, 100, 9, 5}
64

Returns: 92



2)
{995,149,28,265,275,107,555,241,702,462,519,212,362,478,783,381,602,546,183,886,59,317,977,612,328,91,771,131}
992363

Returns: 12792005



3)
{100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100}
100

Returns: 4950



4)
{2934}
10000000

Returns: 14664070144



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
		cout << "Testing ModModMod (300.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1433081315;
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
		ModModMod _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int m[] = {5,3,2};
				int R = 10;
				_expected = 4LL;
				_received = _obj.findSum(vector <int>(m, m+sizeof(m)/sizeof(int)), R); break;
			}
			case 1:
			{
				int m[] = {33, 15, 7, 10, 100, 9, 5};
				int R = 64;
				_expected = 92LL;
				_received = _obj.findSum(vector <int>(m, m+sizeof(m)/sizeof(int)), R); break;
			}
			case 2:
			{
				int m[] = {995,149,28,265,275,107,555,241,702,462,519,212,362,478,783,381,602,546,183,886,59,317,977,612,328,91,771,131};
				int R = 992363;
				_expected = 12792005LL;
				_received = _obj.findSum(vector <int>(m, m+sizeof(m)/sizeof(int)), R); break;
			}
			case 3:
			{
				int m[] = {100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
				           100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
				           100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
				           100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
				           100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
				           100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
				           100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
				           100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100};
				int R = 100;
				_expected = 4950LL;
				_received = _obj.findSum(vector <int>(m, m+sizeof(m)/sizeof(int)), R); break;
			}
			case 4:
			{
				int m[] = {2934};
				int R = 10000000;
				_expected = 14664070144LL;
				_received = _obj.findSum(vector <int>(m, m+sizeof(m)/sizeof(int)), R); break;
			}
			/*case 5:
			{
				int m[] = ;
				int R = ;
				_expected = LL;
				_received = _obj.findSum(vector <int>(m, m+sizeof(m)/sizeof(int)), R); break;
			}*/
			/*case 6:
			{
				int m[] = ;
				int R = ;
				_expected = LL;
				_received = _obj.findSum(vector <int>(m, m+sizeof(m)/sizeof(int)), R); break;
			}*/
			/*case 7:
			{
				int m[] = ;
				int R = ;
				_expected = LL;
				_received = _obj.findSum(vector <int>(m, m+sizeof(m)/sizeof(int)), R); break;
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
