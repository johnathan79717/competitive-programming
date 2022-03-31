#line 2 "IcelandRingRoad.cpp"
#include <array>
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

class IcelandRingRoad {
public:
    int solve(int N, int P, int M, long long state) {
		
    }
};

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
Time limit is 3 seconds.


The main road on Iceland is the Ring Road: a highway loop that goes around the whole island.



There are N towns on the Ring Road. They are numbered from 0 to N-1 in the order in which the road visits them. As the road is cyclic, after town N-1 it returns to town 0.


In winter the Ring Road needs to be maintained, otherwise it won't be usable due to too much snow.
For each i, we know the cost C[i] of maintaining the segment between towns i and ((i+1) modulo N).
Once a segment is maintained, it can be used in both directions.



We have polled all P people who live in Iceland. For each of them we know the town L[j] where they live and the town W[j] where they work.


We want to make sure that everybody can get to work.
Calculate and return the minimum total cost of doing so.



In order to keep the input data small, the values C, L and W will be pseudorandomly generated. Please use the pseudocode below.



for i in 0 .. N-1:
    state = (state * 1103515245 + 12345) modulo 2^31
    C[i] = 1 + ((state / 10) modulo M)

for j in 0 .. P-1:
    state = (state * 1103515245 + 12345) modulo 2^31
    L[j] = ((state / 10) modulo N)
    state = (state * 1103515245 + 12345) modulo 2^31
    W[j] = ((state / 10) modulo N)


DEFINITION
Class:IcelandRingRoad
Method:solve
Parameters:int, int, int, long long
Returns:int
Method signature:int solve(int N, int P, int M, long long state)


NOTES
-The reference solution does not depend on the input being pseudorandom.


CONSTRAINTS
-N will be between 3 and 500,000, inclusive.
-P will be between 1 and 100,000, inclusive.
-M will be between 1 and 1000, inclusive.
-state will be between 0 and 2^31 - 1, inclusive.


EXAMPLES

0)
10
2
1000
474747

Returns: 1161


The road maintenance costs are C = { 253, 325, 395, 132, 427, 50, 582, 52, 573, 747 }.


There are two people. One lives in town 2 and works in town 4, the other lives in town 6 and works in town 8.


The optimal solution is to maintain road segments 2-3, 3-4, 6-7, and 7-8. The total cost of doing so is 395+132+582+52 = 1161.


1)
3
47
1000
420042

Returns: 991

Here the road maintenance costs are C = { 373, 801, 618 }.
Clearly, we want to maintain roads 0-1 and 2-0, and we want to leave the most expensive road 1-2 covered by snow.

2)
100
12
1
12345

Returns: 83


L = { 30, 17, 11, 18, 81, 1, 44, 35, 61, 41, 98, 0 }


W = { 24, 28, 38, 70, 67, 88, 79, 44, 67, 61, 35, 63 }


Each road's maintenance cost is 1. The optimal solution is to maintain 83 roads: the roads 61-62-...-99-0-1-...-43-44.


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
		cout << "Testing IcelandRingRoad (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1627144732;
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
		IcelandRingRoad _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 10;
				int P = 2;
				int M = 1000;
				long long state = 474747LL;
				_expected = 1161;
				_received = _obj.solve(N, P, M, state); break;
			}
			case 1:
			{
				int N = 3;
				int P = 47;
				int M = 1000;
				long long state = 420042LL;
				_expected = 991;
				_received = _obj.solve(N, P, M, state); break;
			}
			case 2:
			{
				int N = 100;
				int P = 12;
				int M = 1;
				long long state = 12345LL;
				_expected = 83;
				_received = _obj.solve(N, P, M, state); break;
			}
			/*case 3:
			{
				int N = ;
				int P = ;
				int M = ;
				long long state = LL;
				_expected = ;
				_received = _obj.solve(N, P, M, state); break;
			}*/
			/*case 4:
			{
				int N = ;
				int P = ;
				int M = ;
				long long state = LL;
				_expected = ;
				_received = _obj.solve(N, P, M, state); break;
			}*/
			/*case 5:
			{
				int N = ;
				int P = ;
				int M = ;
				long long state = LL;
				_expected = ;
				_received = _obj.solve(N, P, M, state); break;
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
