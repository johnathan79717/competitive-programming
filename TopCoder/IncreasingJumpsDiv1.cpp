#line 2 "IncreasingJumpsDiv1.cpp"
#include <string>
#include <vector>
#include <climits>
#include <cstring>
#include <map>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <cassert>
#include <deque>
#include <stack>
#include <functional>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define FOR(I, A, B) for (int I = (A); I <= (B); ++I)
#define FORS(I, S) for (int I = 0; S[I]; ++I)
#define RS(X) scanf("%s", (X))
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define GET_POS(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
#define CASET int ___T; scanf("%d", &___T); for(int cs=1;cs<=___T;cs++)
#define MP make_pair
#define PB emplace_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define F first
#define S second
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII> VPII;
typedef pair<LL,LL> PLL;
typedef vector<PLL> VPLL;
int MOD = 1e9+7;
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}

class IncreasingJumpsDiv1 {
public:
    vector <int> jump(vector <int> frogs) {
		
    }
};

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
The x axis goes from the left to the right.
N frogs, numbered from 1 to N, are sitting on some specific positions on the x axis.
Currently, frog number i sits on the integer coordinate frogs[i-1].
At any moment (including the beginning), multiple frogs may be located at the same position without interfering with each other in any way.


You don't like your frogs scattered, so you would like to move them to some N consecutive integer positions.
Formally, in the final configuration the frogs must occupy the positions {x, x+1, ..., x+N-1} for some integer x.
The order of frogs on those positions does not matter.


You have to move the frogs in a sequence of steps.
The steps are numbered starting from 1.
In each step you must select exactly one frog and tell it to jump either to the left or to the right.
In step x, the length of the frog's jump will be exactly x.


Find and return any valid solution that involves at most 2500 jumps.
The returned solution should be a vector <int> that describes the jump.
For each jump, in order, the return value should contain either +f or -f, where f is the number of the frog that jumps and + means jumping to the right (coordinate of the frog increases).


DEFINITION
Class:IncreasingJumpsDiv1
Method:jump
Parameters:vector <int>
Returns:vector <int>
Method signature:vector <int> jump(vector <int> frogs)


NOTES
-You may assume that a solution always exists.
-You do not have to minimize the number of jumps. Any solution with at most 2500 jumps will be accepted.


CONSTRAINTS
-frogs will contain between 1 and 50 elements, inclusive.
-Each element of frogs will be between 0 and 2500, inclusive.


EXAMPLES

0)
{5, 6, 1, 9, 8}

Returns: {3, 3, 3 }

The example return value tells frog number 3 (the one that starts at coordinate 1) to make three jumps to the right. The coordinate of this frog will change by +1, then by +2, and then by +3. After the third jump the frogs occupy five consecutive positions and we are done.

1)
{0, 0, 1, 0}

Returns: {-2, 4 }

The example return value tells frog 2 to jump left (from coordinate 0 to coordinate -1) and then frog 4 to jump right (from coordinate 0 to coordinate 2). Now the frogs sit on the consecutive positions -1, 0, 1, 2.

2)
{0, 35}

Returns: {1, 1, 1, 1, 1, 1, -2, -2 }

Frog 1 will end on position 21, frog 2 will end on position 20.

3)
{4, 7, 3, 9, 5, 6, 10, 8}

Returns: {3, 3, -3 }

These frogs already sit on consecutive integers, so we don't have to do anything: {} would be a correct return value.
Just to illustrate that we do not have to minimize the number of jumps, our example output shows a solution in which one frog makes three jumps. These are pointless: the frog ends exactly where it started.

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
		cout << "Testing IncreasingJumpsDiv1 (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1603575798;
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
		IncreasingJumpsDiv1 _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int frogs[] = {5, 6, 1, 9, 8};
				int __expected[] = {3, 3, 3 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.jump(vector <int>(frogs, frogs+sizeof(frogs)/sizeof(int))); break;
			}
			case 1:
			{
				int frogs[] = {0, 0, 1, 0};
				int __expected[] = {-2, 4 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.jump(vector <int>(frogs, frogs+sizeof(frogs)/sizeof(int))); break;
			}
			case 2:
			{
				int frogs[] = {0, 35};
				int __expected[] = {1, 1, 1, 1, 1, 1, -2, -2 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.jump(vector <int>(frogs, frogs+sizeof(frogs)/sizeof(int))); break;
			}
			case 3:
			{
				int frogs[] = {4, 7, 3, 9, 5, 6, 10, 8};
				int __expected[] = {3, 3, -3 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.jump(vector <int>(frogs, frogs+sizeof(frogs)/sizeof(int))); break;
			}
			/*case 4:
			{
				int frogs[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.jump(vector <int>(frogs, frogs+sizeof(frogs)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int frogs[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.jump(vector <int>(frogs, frogs+sizeof(frogs)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int frogs[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.jump(vector <int>(frogs, frogs+sizeof(frogs)/sizeof(int))); break;
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
				cout << " " << _expected[i];
			}
			cout << " }" << endl;
			cout << "           Received: {";
			for (unsigned i = 0; i < _received.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _received[i];
			}
			cout << " }" << endl;
		}
	}
}

// END CUT HERE
