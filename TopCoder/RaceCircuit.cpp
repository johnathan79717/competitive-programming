#line 2 "RaceCircuit.cpp"
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
void MIN(int &a, int b) { a = min(a, b); }

class RaceCircuit {
public:
    int construct(int R, int C, vector <int> costRight, vector <int> costDown, vector <int> costCorner) {
	int N = pow(3, C+1);
	vector<int> dp(N, MOD);
	dp[0] = 0;
	REP(k, R*C) {
	    vector<int> next(N, MOD);
	    REP(s, N) {
		if (dp[s] == MOD) {
		    continue;
		}
		auto decode = [C](int s) {
		    vector<int> ans(C+1);
		    int c = 1;
		    stack<int> st;
		    REP(i, C+1) {
			if (s % 3 == 1) {
			    st.push(c);
			    ans[i] = c++;
			} else if (s % 3 == 2) {
			    ans[i] = st.top();
			    st.pop();
			}
			s /= 3;
		    }
		    return ans;
		};
		vector<int> v = decode(s);
		int j = k % C;
		if (j == 0) {
		    if (v.back()) {
			continue;
		    }
		    v.pop_back();
		    v.insert(v.begin(), 0);
		}
		auto encode = [](const vector<int>& v) {
		    auto I = v.rbegin();
		    int ans = 0;
		    unordered_set<int> s;
		    while (I != v.rend()) {
			ans *= 3;
			if (*I == 0) {
			} else if (s.count(*I)) {
			    ans += 1;
			} else {
			    s.insert(*I);
			    ans += 2;
			}
			I++;
		    }
		    return ans;
		};
		if (!v[j] && !v[j+1]) {
		    if (costRight[k] >= 0 && costDown[k] >= 0) {
			v[j] = v[j+1] = N+2;
			MIN(next[encode(v)], dp[s] + costRight[k] + costDown[k] + costCorner[k]);
		    }
		} else if (!v[j]) {
		    if (costRight[k] >= 0) {
			MIN(next[encode(v)], dp[s] + costRight[k] + costCorner[k]);
		    }
		    if (costDown[k] >= 0) {
			swap(v[j], v[j+1]);
			MIN(next[encode(v)], dp[s] + costDown[k]);
		    }
		} else if (!v[j+1]) {
		    if (costDown[k] >= 0) {
			MIN(next[encode(v)], dp[s] + costDown[k] + costCorner[k]);
		    }
		    if (costRight[k] >= 0) {
			swap(v[j], v[j+1]);
			MIN(next[encode(v)], dp[s] + costRight[k]);
		    }
		} else if (k == R*C - 1 || v[j] != v[j+1]) {
		    int b = v[j+1];
		    for (int &a : v) {
			if (a == b) {
			    a = v[j];
			}
		    }
		    v[j] = v[j+1] = 0;
		    MIN(next[encode(v)], dp[s] + costCorner[k]);
		}
	    }
	    swap(dp, next);
	}
	return dp[0] == MOD ? -1 : dp[0];
    }
};

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Time limit is 3 seconds.


Chessland is located on a rectangular board divided into R times C unit squares, with R*C even.
Squares have coordinates (row, column) with rows numbered from 0 top to bottom and columns numbered from 0 left to right.



Chessland wants its own Formula 1 circuit.
The circuit will consist of road segments.
Each road segment must connect two squares that share a side.
The circuit must visit each square of the board exactly once.


For each pair of such squares you are given whether it's possible to build the road segment, and if yes, what it costs.



Additionally, corners are harder to build than straight road segments. For each square you are given the extra cost you have to pay if the circuit changes direction within that square.



You are given:


The dimensions R and C.
The vector <int> costRight where the value costRight[r*C+c] is the cost of building a road between the square (r, c) and the square (r, c+1), or -1 if this is impossible.
The vector <int> costDown where the value costDown[r*C+c] is the cost of building a road between the square (r, c) and the square (r+1, c), or -1 if this is impossible.
The vector <int> costCorner where the value costCorner[r*C+c] is the cost of building a corner of the circuit on the square (r, c).


Return -1 if no solution exists, or the cost of the cheapest solution if solutions exist.


DEFINITION
Class:RaceCircuit
Method:construct
Parameters:int, int, vector <int>, vector <int>, vector <int>
Returns:int
Method signature:int construct(int R, int C, vector <int> costRight, vector <int> costDown, vector <int> costCorner)


CONSTRAINTS
-R will be between 2 and 12, inclusive.
-C will be between 2 and 12, inclusive.
-R * C will be even.
-costRight, costDown and costCorner will have R * C elements each.
-Each element of costRight and costDown will be between -1 and 999, inclusive.
-Each element of costCorner will be between 0 and 999, inclusive.
-Elements of costRight and costDown that correspond to road segments leaving the kingdom will be -1.


EXAMPLES

0)
2
2
{10, -1,
 40, -1}
{20, 30,
 -1, -1}
{5, 4,
 9, 7}

Returns: 125

The smallest possible example. The costs to build roads and corners are shown below:


[5] --10-- [4]
 |          |
 |          |
20         30
 |          |
 |          |
[9] --40-- [7]


There is only one way how to build the circuit. The road segments cost 10+30+40+20 = 100 and the extra cost for its corners is 5+4+9+7 = 25.

1)
2
2
{0, -1,
 0, -1}
{-1,  0,
 -1, -1}
{5, 4,
 9, 7}

Returns: -1

A trivial example with no solution.


2)
3
4
{1, 2, 1, -1,
 2, 1, 2, -1,
 1, 1, 1, -1}
{ 1,  1,  1,  1,
  1,  2,  2,  1,
 -1, -1, -1, -1}
{100, 100, 100, 100,
 100, 100, 100, 100,
 100, 100, 100, 100}

Returns: 812

Building the corners costs the same everywhere. There are only two possible circuits and both have the same number of corners, so we just need the cheapest road segments. Luckily for us, the road segments with cost 1 form exactly one of the two possible circuits.

*---*   *---*
|   |   |   |
*   *---*   *
|           |
*---*---*---*

We pay 800 for the corners and 12 for the road segments.


3)
3
4
{1, 2, 1, -1,
 2, 1, 2, -1,
 1, 1, 1, -1}
{ 1,  1,  1,  1,
  1,  2,  2,  1,
 -1, -1, -1, -1}
{100, 100, 100, 100,
 100, 100, 100, 100,
 100,  50,  50, 100}

Returns: 715

Here the road costs are negligible in comparison to the corner costs. The optimal solution is to build the other possible circuit with corners at (2,1) and (2,2).


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
		cout << "Testing RaceCircuit (900.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1611424208;
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
		RaceCircuit _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int R = 2;
				int C = 2;
				int costRight[] = {10, -1,
				                   40, -1};
				int costDown[] = {20, 30,
				                  -1, -1};
				int costCorner[] = {5, 4,
				                    9, 7};
				_expected = 125;
				_received = _obj.construct(R, C, vector <int>(costRight, costRight+sizeof(costRight)/sizeof(int)), vector <int>(costDown, costDown+sizeof(costDown)/sizeof(int)), vector <int>(costCorner, costCorner+sizeof(costCorner)/sizeof(int))); break;
			}
			case 1:
			{
				int R = 2;
				int C = 2;
				int costRight[] = {0, -1,
				                   0, -1};
				int costDown[] = {-1,  0,
				                  -1, -1};
				int costCorner[] = {5, 4,
				                    9, 7};
				_expected = -1;
				_received = _obj.construct(R, C, vector <int>(costRight, costRight+sizeof(costRight)/sizeof(int)), vector <int>(costDown, costDown+sizeof(costDown)/sizeof(int)), vector <int>(costCorner, costCorner+sizeof(costCorner)/sizeof(int))); break;
			}
			case 2:
			{
				int R = 3;
				int C = 4;
				int costRight[] = {1, 2, 1, -1,
				                   2, 1, 2, -1,
				                   1, 1, 1, -1};
				int costDown[] = { 1,  1,  1,  1,
				                   1,  2,  2,  1,
				                  -1, -1, -1, -1};
				int costCorner[] = {100, 100, 100, 100,
				                    100, 100, 100, 100,
				                    100, 100, 100, 100};
				_expected = 812;
				_received = _obj.construct(R, C, vector <int>(costRight, costRight+sizeof(costRight)/sizeof(int)), vector <int>(costDown, costDown+sizeof(costDown)/sizeof(int)), vector <int>(costCorner, costCorner+sizeof(costCorner)/sizeof(int))); break;
			}
			case 3:
			{
				int R = 3;
				int C = 4;
				int costRight[] = {1, 2, 1, -1,
				                   2, 1, 2, -1,
				                   1, 1, 1, -1};
				int costDown[] = { 1,  1,  1,  1,
				                   1,  2,  2,  1,
				                  -1, -1, -1, -1};
				int costCorner[] = {100, 100, 100, 100,
				                    100, 100, 100, 100,
				                    100,  50,  50, 100};
				_expected = 715;
				_received = _obj.construct(R, C, vector <int>(costRight, costRight+sizeof(costRight)/sizeof(int)), vector <int>(costDown, costDown+sizeof(costDown)/sizeof(int)), vector <int>(costCorner, costCorner+sizeof(costCorner)/sizeof(int))); break;
			}
			/*case 4:
			{
				int R = ;
				int C = ;
				int costRight[] = ;
				int costDown[] = ;
				int costCorner[] = ;
				_expected = ;
				_received = _obj.construct(R, C, vector <int>(costRight, costRight+sizeof(costRight)/sizeof(int)), vector <int>(costDown, costDown+sizeof(costDown)/sizeof(int)), vector <int>(costCorner, costCorner+sizeof(costCorner)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int R = ;
				int C = ;
				int costRight[] = ;
				int costDown[] = ;
				int costCorner[] = ;
				_expected = ;
				_received = _obj.construct(R, C, vector <int>(costRight, costRight+sizeof(costRight)/sizeof(int)), vector <int>(costDown, costDown+sizeof(costDown)/sizeof(int)), vector <int>(costCorner, costCorner+sizeof(costCorner)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int R = ;
				int C = ;
				int costRight[] = ;
				int costDown[] = ;
				int costCorner[] = ;
				_expected = ;
				_received = _obj.construct(R, C, vector <int>(costRight, costRight+sizeof(costRight)/sizeof(int)), vector <int>(costDown, costDown+sizeof(costDown)/sizeof(int)), vector <int>(costCorner, costCorner+sizeof(costCorner)/sizeof(int))); break;
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
