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
#include <cassert>
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
#define ALL(x) (x).begin(),(x).end()
#define MP make_pair
 
typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;

LL A[500005];
pair<double, int> B[500005], C[500005];

PII solve(int N, double &lb, double &ub, double c, bool &early) {
    early = false;
    int pi = -1, pj = -1;
    REP(i, N) {
	if (B[i].second != C[i].second) {
	    if (pi >= 0) {
		ub = c;
		early = false;
		return MP(pi, pj);
		//return;
	    }
	    pi = B[i].second;
	    pj = C[i].second;
	}
    }
    if (pi >= 0) {
	ub = c;
	early = true;
    } else {
	lb = c;
	early = false;
    }
    return MP(pi, pj);
}

#line 41 "AqaAsadiMinimizes.cpp"
#include <string>
#include <vector>
class AqaAsadiMinimizes {
public:
    double getMin(vector <int> P, int B0, int X, int Y, int N) {
	REP(i, N) {
	    if (i < int(P.size())) {
		A[i] = P[i];
	    } else if (i == (int)P.size()) {
		A[i] = B0;
	    } else {
		A[i] = (A[i-1] * X + Y) % 1000000007;
	    }
	    C[i].first = B[i].first = A[i];
	    C[i].second = B[i].second = i;
	}

	double lb = 0, ub = 1000000007. / (N-1);
	double prev_c = 0;
	while (ub - lb > 1e-9 && (ub - lb) > lb * 1e-9) {
	    double c = (lb + ub) / 2;
	    REP(i, N) {
		B[i].first += (c - prev_c) * B[i].second;
		C[i].first += (c - prev_c) * C[i].second;
	    }
	    prev_c = c;
	    sort(B, B+N);
	    sort(C, C+N);
	    bool early = false;
	    auto pr = 
		solve(N, lb, ub, c, early);
	    if (early) {
		int i = pr.first, j = pr.second;
		return fabs((A[i] - A[j]) / (i - j));
	    }
	}
	return ub;
    }
};

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
Aqa Asadi is a kind teacher who puts a lot of effort into helping students grow and make friends.


N students stand in a line.
They are numbered 0 through N-1, in order.
Student i is A[i] seconds old.


Aqa Asadi came up with a formula that measures how difficult it is for two students to become friends: for students i and j, the difficulty is |A[j] - A[i]| / |j - i|.
In the formula, |x| denotes the absolute value of x.


Find the pair of students with the smallest difficulty to form a friendship, and return that difficulty.


Use the following pseudocode for generating the array A[0..N-1]:


for i = 0 to N-1:
    if i < length(P):
        A[i] = P[i]
    if i == length(P):
        A[i] = B0
    if i > length(P):
        A[i] = (A[i-1] * X + Y) modulo 1000000007


DEFINITION
Class:AqaAsadiMinimizes
Method:getMin
Parameters:vector <int>, int, int, int, int
Returns:double
Method signature:double getMin(vector <int> P, int B0, int X, int Y, int N)


NOTES
-The returned value will be accepted if its relative or absolute error does not exceed 1e-9.


CONSTRAINTS
-N will be between 2 and 500,000, inclusive.
-P will have between 0 and N elements, inclusive.
-P will have at most 100 elements.
-B0, X, Y, and all elements of P will be between 0 and 1,000,000,006, inclusive.


EXAMPLES

0)
{11, 0, 30, 20, 1000}
0
0
0
5

Returns: 3.0

The best pair are the students i=0 and j=3, their difficulty of forming a friendship is |20 - 11| / |3 - 0| = 9/3 = 3.

1)
{47, 1, 10, 3, 2}
0
0
0
5

Returns: 0.3333333333333333

Students i=1 and j=4 are the best choice here.

2)
{123456}
234567890
345678
456789
10

Returns: 8333191.571428572


A = {123456, 234567890, 958968621, 353106369, 103025544, 664206330, 514591322, 898217931, 176235549, 752137571}


*/
// END CUT HERE

// BEGIN CUT HERE
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
		cout << "Testing AqaAsadiMinimizes (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1592755503;
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
		AqaAsadiMinimizes _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int P[] = {11, 0, 30, 20, 1000};
				int B0 = 0;
				int X = 0;
				int Y = 0;
				int N = 5;
				_expected = 3.0;
				_received = _obj.getMin(vector <int>(P, P+sizeof(P)/sizeof(int)), B0, X, Y, N); break;
			}
			case 1:
			{
				int P[] = {47, 1, 10, 3, 2};
				int B0 = 0;
				int X = 0;
				int Y = 0;
				int N = 5;
				_expected = 0.3333333333333333;
				_received = _obj.getMin(vector <int>(P, P+sizeof(P)/sizeof(int)), B0, X, Y, N); break;
			}
			case 2:
			{
				int P[] = {123456};
				int B0 = 234567890;
				int X = 345678;
				int Y = 456789;
				int N = 10;
				_expected = 8333191.571428572;
				_received = _obj.getMin(vector <int>(P, P+sizeof(P)/sizeof(int)), B0, X, Y, N); break;
			}
			/*case 3:
			{
				int P[] = ;
				int B0 = ;
				int X = ;
				int Y = ;
				int N = ;
				_expected = ;
				_received = _obj.getMin(vector <int>(P, P+sizeof(P)/sizeof(int)), B0, X, Y, N); break;
			}*/
			/*case 4:
			{
				int P[] = ;
				int B0 = ;
				int X = ;
				int Y = ;
				int N = ;
				_expected = ;
				_received = _obj.getMin(vector <int>(P, P+sizeof(P)/sizeof(int)), B0, X, Y, N); break;
			}*/
			/*case 5:
			{
				int P[] = ;
				int B0 = ;
				int X = ;
				int Y = ;
				int N = ;
				_expected = ;
				_received = _obj.getMin(vector <int>(P, P+sizeof(P)/sizeof(int)), B0, X, Y, N); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (abs(_expected-_received) < 1e-9 || (_received > min(_expected*(1.0-1e-9), _expected*(1.0+1e-9)) && _received < max(_expected*(1.0-1e-9), _expected*(1.0+1e-9))))
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout.precision(10);
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
