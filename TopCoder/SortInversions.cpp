#line 2 "SortInversions.cpp"
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

class SortInversions {
public:
    long long count(int N) {
		
    }
};

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
Bob had an array that contained the integers from 1 to N, inclusive.
He converted each integer into a string.
Then, he sorted the array.
Finally, he converted each string back into an integer.


Count and return the number of inversions in Bob's final array.


DEFINITION
Class:SortInversions
Method:count
Parameters:int
Returns:long long
Method signature:long long count(int N)


NOTES
-A pair of indices (i, j) into an array B is an inversion if and only if (i < j and B[i] > B[j]). In other words, an inversion is a pair of elements such that the bigger element is to the left of the smaller one.


CONSTRAINTS
-N will be between 1 and 10^9, inclusive.


EXAMPLES

0)
12

Returns: 24


Bob had the array {1, 2, ..., 9, 10, 11, 12}.


He converted the elements to strings: {"1", "2", ..., "9", "10", "11", "12"}.


He sorted those strings: {"1", "10", "11", "12", "2", ..., "9"}.


He converted everything back to integers: {1, 10, 11, 12, 2, ..., 9}.


This array now contains 24 inversions.


1)
7

Returns: 0



2)
199

Returns: 9610



3)
999999

Returns: 45451601010



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
		cout << "Testing SortInversions (600.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1599323361;
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
		SortInversions _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 12;
				_expected = 24LL;
				_received = _obj.count(N); break;
			}
			case 1:
			{
				int N = 7;
				_expected = 0LL;
				_received = _obj.count(N); break;
			}
			case 2:
			{
				int N = 199;
				_expected = 9610LL;
				_received = _obj.count(N); break;
			}
			case 3:
			{
				int N = 999999;
				_expected = 45451601010LL;
				_received = _obj.count(N); break;
			}
			/*case 4:
			{
				int N = ;
				_expected = LL;
				_received = _obj.count(N); break;
			}*/
			/*case 5:
			{
				int N = ;
				_expected = LL;
				_received = _obj.count(N); break;
			}*/
			/*case 6:
			{
				int N = ;
				_expected = LL;
				_received = _obj.count(N); break;
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
