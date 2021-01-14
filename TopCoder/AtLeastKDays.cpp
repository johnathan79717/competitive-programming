#line 2 "AtLeastKDays.cpp"
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
#define REP(I, N) for (int I = 0; I < (N); ++I)
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

class AtLeastKDays {
public:
    int N;
    long long sumOfMinCosts(vector <string> costs, int minDays) {
	N = costs.size();
	vector<VL> c(N, VL(N));
	REP(i, N) {
	    REP(j, N) {
		if (i == j) {
		    c[i][j] = 1e12;
		} else {
		    c[i][j] = costs[i][j] - '0';
		}
	    }
	}
	vector<VL> b = c;
	REP(k, 10) {
	    vector<VL> d = mul(b, c);
	    REP(i, N) {
		REP(j, N) {
		    b[i][j] = min(b[i][j], d[i][j]);
		}
	    }
	}
	vector<VL> ans;
	for (int i = 31; i >= 0; i--) {
	    if (ans.size()) {
		ans = mul(ans, ans);
	    }
	    if ((minDays >> i) & 1) {
		if (ans.empty()) {
		    ans = b;
		} else {
		    ans = mul(ans, b);
		}
	    }
	}
	LL a = 0;
	REP(i, N) {
	    REP(j, N) {
		a += ans[i][j];
	    }
	}
	return a;
    }
    vector<VL> mul(vector<VL> const &c1, const vector<VL>& c2) {
	vector<VL> ans(N, VL(N, 1e12));
	REP(i, N) {
	    REP(j, N) {
		REP(k, N) {
		    ans[i][j] = min(ans[i][j], c1[i][k] + c2[k][j]);
		}
	    }
	}
	return ans;
    }
};

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
There are N cities, numbered from 0 to N-1.
For each ordered pair of cities (u, v) you know the cost costs[u][v] of flying directly from u to v.
Each such flight takes one day.
Flight costs are not necessarily symmetric.


Suppose you are in city u and you want to get to city v.
You would like to use this opportunity to obtain a frequent flyer status.
In order to get the status, you have to travel on at least minDays consecutive days.
What is the minimum total cost c(u, v) of a flight schedule that gets you from u to v in minDays or more days?


Return the sum of all N*N values c(u, v).
Note that this includes trips that start and end in the same city.


DEFINITION
Class:AtLeastKDays
Method:sumOfMinCosts
Parameters:vector <string>, int
Returns:long long
Method signature:long long sumOfMinCosts(vector <string> costs, int minDays)


NOTES
-The diagonal of the array costs contains the character '-' denoting that staying in a city is not a valid form of traveling.
-Digits in costs represent the corresponding numerical values. For example, if costs[4][7] = '3', the flight from 4 to 7 has cost 3.


CONSTRAINTS
-N will be between 2 and 50, inclusive.
-costs will contain exactly N elements.
-Each element of costs will contain exactly N characters.
-For each u, costs[u][u] will be '-'.
-Each other character in costs will be between '1' and '9', inclusive.
-minDays will be between 1 and 10^9, inclusive.


EXAMPLES

0)
{"-12",
 "3-6",
 "45-"}
1

Returns: 34


We are traveling for at least one day.


For some pairs of cities the optimal solution is to take the direct flight and stop.
These are c(0,1) = 1, c(0,2) = 2, c(1,0) = 3, c(2,0) = 4, and c(2,1) = 5.


If we have to start and end in the same city, we need to fly for at least two days.
The optimal travel costs for these cases are c(0,0) = c(1,1) = 4 and c(2,2) = 6.


This leaves us with travel from 1 to 2. There is a direct flight that costs 6, but also a cheaper option: to fly from 1 to 0 and then from 0 to 2, paying only 3+2 = 5.
Thus, c(1,2) = 5.


The returned value is the sum of all c(u,v): 4+1+2+3+4+5+4+5+6 = 34.


1)
{"-111111111",
 "1-11111111",
 "11-1111111",
 "111-111111",
 "1111-11111",
 "11111-1111",
 "111111-111",
 "1111111-11",
 "11111111-1",
 "111111111-"}
1000000000

Returns: 100000000000

For each of the 10*10 pairs of vertices we can get from u to v in exactly 10^9 days while paying 1 for each ticket. Thus, each c(u, v) is 10^9 and therefore the final answer is 10^11.

2)
{"-12",
 "3-6",
 "45-"}
6

Returns: 122


The same costs as in example 0, but now we are traveling for at least 6 days.


One of the things worth noting is that c(0,1) = 13.
The optimal way of traveling from 0 to 1 in at least 6 days is to travel in 7 days, alternating between cities 0 and 1 the whole time.


Another thing worth noting is that c(0,2) = 14.
Again, optimal travel involves seven days, in which we travel as follows: 0-1-0-1-0-1-0-2.



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
		cout << "Testing AtLeastKDays (300.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1607792724;
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
		AtLeastKDays _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string costs[] = {"-12",
				                  "3-6",
				                  "45-"};
				int minDays = 1;
				_expected = 34LL;
				_received = _obj.sumOfMinCosts(vector <string>(costs, costs+sizeof(costs)/sizeof(string)), minDays); break;
			}
			case 1:
			{
				string costs[] = {"-111111111",
				                  "1-11111111",
				                  "11-1111111",
				                  "111-111111",
				                  "1111-11111",
				                  "11111-1111",
				                  "111111-111",
				                  "1111111-11",
				                  "11111111-1",
				                  "111111111-"};
				int minDays = 1000000000;
				_expected = 100000000000LL;
				_received = _obj.sumOfMinCosts(vector <string>(costs, costs+sizeof(costs)/sizeof(string)), minDays); break;
			}
			case 2:
			{
				string costs[] = {"-12",
				                  "3-6",
				                  "45-"};
				int minDays = 6;
				_expected = 122LL;
				_received = _obj.sumOfMinCosts(vector <string>(costs, costs+sizeof(costs)/sizeof(string)), minDays); break;
			}
			case 3:
			{
				string costs[] = {"-999999999",
				                  "9-99999999",
				                  "99-9999999",
				                  "999-999999",
				                  "9999-99999",
				                  "99999-9999",
				                  "999999-999",
				                  "9999999-99",
				                  "99999999-9",
				                  "999999999-"};
				int minDays = 1000000000;
				_expected = 900000000000LL;
				_received = _obj.sumOfMinCosts(vector <string>(costs, costs+sizeof(costs)/sizeof(string)), minDays); break;
			}
			/*case 4:
			{
				string costs[] = ;
				int minDays = ;
				_expected = LL;
				_received = _obj.sumOfMinCosts(vector <string>(costs, costs+sizeof(costs)/sizeof(string)), minDays); break;
			}*/
			/*case 5:
			{
				string costs[] = ;
				int minDays = ;
				_expected = LL;
				_received = _obj.sumOfMinCosts(vector <string>(costs, costs+sizeof(costs)/sizeof(string)), minDays); break;
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
