#line 2 "BigJump.cpp"
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

class BigJump {
public:
    vector <int> construct(int N) {
		
    }
};

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
N points labeled 0 to N-1 are arranged around a circle in clockwise order. The number N is even.


The first point counter-clockwise from point x is called the predecessor of x. Note that the predecessor of 0 is N-1.


Whenever you stand on some point x, you have two options how to move:


The big jump will take you to the point (2*x) modulo N.
The almost big jump will take you to the predecessor of the point you would reach by the big jump: the point (2*x-1) modulo N.


Determine whether it is possible to start on some point, step on each other point exactly once and return to the point where you started.
If yes, find any one such solution and return it as a vector <int> with N elements: the order in which you first step on the points.
If there is no solution, return an empty vector <int>.


DEFINITION
Class:BigJump
Method:construct
Parameters:int
Returns:vector <int>
Method signature:vector <int> construct(int N)


NOTES
-Remember that in a valid solution it must also be possible to move from the last element of your return value back to its first element.


CONSTRAINTS
-N will be between 2 and 3000, inclusive.
-N will be even.


EXAMPLES

0)
6

Returns: {0, 5, 4, 1, 2, 3 }

Using A to denote an almost big jump and B to denote a big jump, the return value corresponds to starting at point 0 and performing the sequence of jumps A, B, A, B, A, B.

1)
12

Returns: {0, 11, 10, 8, 4, 7, 1, 2, 3, 5, 9, 6 }

There are other valid solutions. For example, {10, 7, 1, 2, 4, 8, 3, 6, 0, 11, 9, 5} is also a valid solution.

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
		cout << "Testing BigJump (900.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1599326687;
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
		BigJump _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 6;
				int __expected[] = {0, 5, 4, 1, 2, 3 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(N); break;
			}
			case 1:
			{
				int N = 12;
				int __expected[] = {0, 11, 10, 8, 4, 7, 1, 2, 3, 5, 9, 6 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(N); break;
			}
			/*case 2:
			{
				int N = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(N); break;
			}*/
			/*case 3:
			{
				int N = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(N); break;
			}*/
			/*case 4:
			{
				int N = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
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
