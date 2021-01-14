#line 2 "RollMe.cpp"
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

class RollMe {
public:
    int solve(vector <int> die, string goal) {
		
    }
};

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
You have a biased die with N faces, labeled 0 to N-1.
You are given the vector <int> die with the relative probabilities of rolling each value.
I.e., on this die you will roll the value x with probability die[x] / sum(die).



You are given the string goal.
You are going to repeatedly roll your die and write down the result until the last length(goal) characters match goal exactly.



The expected number of rolls in the above process can be written as a reduced fraction P/Q.
Return P*Q^(-1) modulo (10^9 + 7).


DEFINITION
Class:RollMe
Method:solve
Parameters:vector <int>, string
Returns:int
Method signature:int solve(vector <int> die, string goal)


NOTES
-The exact answer is always a rational number. If we write it as a simplified fraction P/Q, the value Q will always be relatively prime to 10^9 + 7. Hence, Q has a multiplicative inverse: a value Q^(-1) such that (Q*Q^(-1)) mod (10^9 + 7) = 1.


CONSTRAINTS
-N will be between 2 and 10, inclusive.
-die will have N elements.
-Each element of die will be between 1 and 10, inclusive.
-goal will have between 1 and 5000 characters, inclusive.
-Each character of goal will be one of the N smallest digits ('0', '1', ...).


EXAMPLES

0)
{7, 7}
"01"

Returns: 4

A fair coin. We are waiting until we see a head ('0') followed by a tail ('1'). This takes four flips on average.

1)
{1, 1}
"00"

Returns: 6

Another fair coin, but now we are waiting for two heads in a row. Perhaps surprisingly, that requires 6 coin flips on average: more than another pattern of the same length.

2)
{2, 1}
"1011"

Returns: 500000047


On average we'll need to make 43.5 = 87/2 coin flips with this biased coin until "1011" appears.


We have P=87 and Q=2. The multiplicative inverse to this Q is Q^(-1) = 500,000,004, and thus the correct return value is (87 * 500000004) mod 1000000007 = 500,000,047.


3)
{1, 1, 1, 1, 1}
"0123401"

Returns: 78150



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
		cout << "Testing RollMe (600.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1610214251;
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
		RollMe _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int die[] = {7, 7};
				string goal = "01";
				_expected = 4;
				_received = _obj.solve(vector <int>(die, die+sizeof(die)/sizeof(int)), goal); break;
			}
			case 1:
			{
				int die[] = {1, 1};
				string goal = "00";
				_expected = 6;
				_received = _obj.solve(vector <int>(die, die+sizeof(die)/sizeof(int)), goal); break;
			}
			case 2:
			{
				int die[] = {2, 1};
				string goal = "1011";
				_expected = 500000047;
				_received = _obj.solve(vector <int>(die, die+sizeof(die)/sizeof(int)), goal); break;
			}
			case 3:
			{
				int die[] = {1, 1, 1, 1, 1};
				string goal = "0123401";
				_expected = 78150;
				_received = _obj.solve(vector <int>(die, die+sizeof(die)/sizeof(int)), goal); break;
			}
			/*case 4:
			{
				int die[] = ;
				string goal = ;
				_expected = ;
				_received = _obj.solve(vector <int>(die, die+sizeof(die)/sizeof(int)), goal); break;
			}*/
			/*case 5:
			{
				int die[] = ;
				string goal = ;
				_expected = ;
				_received = _obj.solve(vector <int>(die, die+sizeof(die)/sizeof(int)), goal); break;
			}*/
			/*case 6:
			{
				int die[] = ;
				string goal = ;
				_expected = ;
				_received = _obj.solve(vector <int>(die, die+sizeof(die)/sizeof(int)), goal); break;
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
