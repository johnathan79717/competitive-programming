#line 2 "SlowSequence.cpp"
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
#define PB emplace_back
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

class SlowSequence {
public:
    vector <int> construct(int N, int S) {
	VI A = {0};
	while (A.size() < N) {
	    if (S >= 0) {
		S -= (N - A.size());
		A.PB(A.back() + 1);
	    } else {
		S += (N - A.size());
		A.PB(A.back() - 1);
	    }
	}
	if (S == 0) {
	    return A;
	}
	return VI();
    }
};

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
A slow sequence is a sequence A of N elements with the following properties:


A[0] = 0
for each valid i, the values A[i] and A[i+1] differ by exactly 1


Given N and S, construct and return any slow sequence with sum S.
Return an empty vector <int> if such a sequence does not exist.


DEFINITION
Class:SlowSequence
Method:construct
Parameters:int, int
Returns:vector <int>
Method signature:vector <int> construct(int N, int S)


CONSTRAINTS
-N will be between 1 and 2500, inclusive.
-S will be between -10^9 and 10^9, inclusive.


EXAMPLES

0)
4
4

Returns: {0, 1, 2, 1 }

The sequence {0, 1, 2, 1} has all the desired properties: element 0 is 0, we have |0-1| = |1-2| = |2-1| = 1, and its sum is 0+1+2+1 = 4.

1)
8
0

Returns: {0, 1, 0, -1, 0, -1, 0, 1 }



2)
1
4700

Returns: { }



3)
5
-10

Returns: {0, -1, -2, -3, -4 }



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
		cout << "Testing SlowSequence (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1601723513;
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
		SlowSequence _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 4;
				int S = 4;
				int __expected[] = {0, 1, 2, 1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(N, S); break;
			}
			case 1:
			{
				int N = 8;
				int S = 0;
				int __expected[] = {0, 1, 0, -1, 0, -1, 0, 1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(N, S); break;
			}
			case 2:
			{
				int N = 1;
				int S = 4700;
				int __expected[] = { };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(N, S); break;
			}
			case 3:
			{
				int N = 5;
				int S = -10;
				int __expected[] = {0, -1, -2, -3, -4 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(N, S); break;
			}
			/*case 4:
			{
				int N = ;
				int S = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(N, S); break;
			}*/
			/*case 5:
			{
				int N = ;
				int S = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(N, S); break;
			}*/
			/*case 6:
			{
				int N = ;
				int S = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(N, S); break;
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
