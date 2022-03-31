#line 2 "MaximumPenalty.cpp"
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

class MaximumPenalty {
public:
    vector <int> schedule(vector <int> L, vector <int> P) {
	int N = L.size();
	auto eval = [&](int i, ULL s)->ULL {
	    return P[4*i] + s * (P[4*i+1] + s * (P[4*i+2] + s * P[4*i+3]));
	};
	int s = 0;
	for (int l : L) {
	    s += l;
	}
	vector<bool> used(N);
	VI ans(N, -1);
	for (int j = N-1; j >= 0; j--) {
	    REP(i, N) {
		if (!used[i] && (ans[j] < 0 || eval(i, s) < eval(ans[j], s))) {
		    ans[j] = i;
		}
	    }
	    used[ans[j]] = true;
	    s -= L[ans[j]];
	}
	return ans;
    }
};

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
We have N jobs to complete.
The jobs are numbered from 0 to N-1.
Job i requires L[i] seconds of work.
At any moment we can only work on one of the jobs.


As is usually the case, each job should be completed as soon as possible: the longer it takes, the worse the penalty will be.
If job i is completed after t seconds, the penalty is calculated as follows:


penalty(i, t) = P[4i+0] * t0 + P[4i+1] * t1 + P[4i+2] * t2 + P[4i+3] * t3


All coefficients in P are nonnegative, and therefore the penalty is nondecreasing in time.


The penalty of the whole schedule is the maximum (not the sum!) over all jobs. 
Your goal is to minimize this penalty.



Clearly it doesn't pay off to jump back and forth between jobs: there is always an optimal schedule in which whenever you start working on a problem, you work on it until you complete it.
Such a schedule can then be described by a list of job numbers in the order in which you should perform them.
Find any such optimal schedule and return a vector <int> with the corresponding job order.
Any optimal solution will be accepted.


DEFINITION
Class:MaximumPenalty
Method:schedule
Parameters:vector <int>, vector <int>
Returns:vector <int>
Method signature:vector <int> schedule(vector <int> L, vector <int> P)


NOTES
-For the constraints specified below the largest possible penalty fits into a signed 64-bit integer.


CONSTRAINTS
-N will be between 1 and 1000, inclusive.
-L will contain N elements.
-Each element of L will be between 1 and 100, inclusive.
-P will contain 4*N elements.
-Each element of P will be between 0 and 8000, inclusive.


EXAMPLES

0)
{7, 4, 1}
{0, 0, 0, 1,
 0, 0, 2, 0,
 0, 3, 0, 0}

Returns: {0, 2, 1 }

We have a long job with penalty function t^3, a medium job with penalty function 2t^2, and a short job with penalty 3t.
If we do them in the order {0, 2, 1}, we will finish job 0 at 7 seconds, job 2 at 8 seconds, and then job 1 at 12 seconds.
The individual penalties will be 7^3 = 343, 2*8^2 = 128, and 3*12 = 36.
Thus, the overall penalty will be 343.
This is optimal. There is one other optimal solution that would also be accepted.

1)
{7, 4, 2, 5}
{47, 0, 0, 0,
 47, 0, 0, 0,
 47, 0, 0, 0,
 47, 0, 0, 0}

Returns: {3, 2, 1, 0 }

All jobs have the same constant penalty. The order in which we do them does not matter.

2)
{7, 4, 2, 5}
{0, 47, 0, 0,
 0, 47, 0, 0,
 0, 47, 0, 0,
 0, 47, 0, 0}

Returns: {3, 2, 1, 0 }

All jobs have the same linear time penalty. Regardless of the order in which we perform them the penalty for the last job finished will always be 47*18, so again the order does not matter.

3)
{7, 4, 2, 5}
{0, 7, 8,  15,
 1, 6, 9,  14,
 2, 5, 10, 13,
 3, 4, 11, 12}

Returns: {0, 1, 2, 3 }

Any order in which job 3 is performed last is optimal.

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
		cout << "Testing MaximumPenalty (550.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1613237955;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 550.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		MaximumPenalty _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int L[] = {7, 4, 1};
				int P[] = {0, 0, 0, 1,
				           0, 0, 2, 0,
				           0, 3, 0, 0};
				int __expected[] = {0, 2, 1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.schedule(vector <int>(L, L+sizeof(L)/sizeof(int)), vector <int>(P, P+sizeof(P)/sizeof(int))); break;
			}
			case 1:
			{
				int L[] = {7, 4, 2, 5};
				int P[] = {47, 0, 0, 0,
				           47, 0, 0, 0,
				           47, 0, 0, 0,
				           47, 0, 0, 0};
				int __expected[] = {3, 2, 1, 0 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.schedule(vector <int>(L, L+sizeof(L)/sizeof(int)), vector <int>(P, P+sizeof(P)/sizeof(int))); break;
			}
			case 2:
			{
				int L[] = {7, 4, 2, 5};
				int P[] = {0, 47, 0, 0,
				           0, 47, 0, 0,
				           0, 47, 0, 0,
				           0, 47, 0, 0};
				int __expected[] = {3, 2, 1, 0 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.schedule(vector <int>(L, L+sizeof(L)/sizeof(int)), vector <int>(P, P+sizeof(P)/sizeof(int))); break;
			}
			case 3:
			{
				int L[] = {7, 4, 2, 5};
				int P[] = {0, 7, 8,  15,
				           1, 6, 9,  14,
				           2, 5, 10, 13,
				           3, 4, 11, 12};
				int __expected[] = {0, 1, 2, 3 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.schedule(vector <int>(L, L+sizeof(L)/sizeof(int)), vector <int>(P, P+sizeof(P)/sizeof(int))); break;
			}
			case 4:
			{
				int L[] = {79, 3, 48, 97, 1, 5, 5, 3, 70, 3, 10, 29};
				int P[] = {9, 246, 0, 0, 7, 1, 0, 0, 2299, 53, 0, 0, 2, 3, 0, 0, 6, 5475, 0, 0, 4190, 43, 0, 0, 1843, 1, 0, 0, 3, 118, 0, 0, 2, 3794, 0, 0, 1, 25, 0, 0, 421, 576, 0, 0, 81, 2900, 0, 0};
				int __expected[] = {4, 8, 11, 10, 0, 7, 2, 5, 9, 6, 3, 1};
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.schedule(vector <int>(L, L+sizeof(L)/sizeof(int)), vector <int>(P, P+sizeof(P)/sizeof(int))); break;
			}
			/*case 5:
			{
				int L[] = ;
				int P[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.schedule(vector <int>(L, L+sizeof(L)/sizeof(int)), vector <int>(P, P+sizeof(P)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int L[] = ;
				int P[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.schedule(vector <int>(L, L+sizeof(L)/sizeof(int)), vector <int>(P, P+sizeof(P)/sizeof(int))); break;
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
