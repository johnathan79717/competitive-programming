#line 2 "CapriciousSorting.cpp"
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

class CapriciousSorting {
public:
    int count(vector <int> num) {
	int N = num.size();
	REP(i, N-1) {
	    if (num[i] == num[i+1]) {
		return 0;
	    }
	}
	int ans = 1;
	for (int i = 29; i >= 0; i--) {
	    bool c0 = false, c1 = false;
	    for (int j = 0; j + 1 < num.size(); j++) {
		int a = num[j], b = num[j+1];
		if ((a >> (i+1)) == ((b >> (i+1))) && (a >> i) != (b >> i)) {
		    if ((a >> i) < (b >> i)) {
			c0 = true;
		    } else {
			c1 = true;
		    }
		}
	    }
	    if (c0 && c1) {
		return 0;
	    }
	    if (!c0 && !c1) {
		ans *= 2;
	    }
	}
	return ans;
    }
};

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// One day, Frederica found the vector <int> num that consisted of N non-negative integers.
She thinks that only sorted arrays are beautiful, so she would like to transform num into a sequence that is sorted in strictly ascending order.
However, she thinks that simply sorting the elements is not fun. Instead, she is going to do the following operation: 

First, she picks some integer A that is between 0 and 2^30 - 1, inclusive.
Second, she will xor all elements of num with the chosen A. That is, the new value of num[i] will be (num[i] xor A), for all valid i.

Of course, not every selection of A makes the final sequence sorted.
In order to help Frederica, please calculate and return the number of different choices for A that do change num into a sequence in strictly ascending order.

DEFINITION
Class:CapriciousSorting
Method:count
Parameters:vector <int>
Returns:int
Method signature:int count(vector <int> num)


CONSTRAINTS
-N will be between 2 and 50, inclusive.
-num will contain exactly N elements.
-Each element in num will be between 0 and 2^30 - 1, inclusive.


EXAMPLES

0)
{0, 1, 2, 3, 4, 5, 6, 7}

Returns: 134217728

We can choose the highest 27 bits of A arbitrarily. The lowest three bits of A must be 0.

1)
{7, 6, 5, 4, 3, 2, 1, 0}

Returns: 134217728

Again, we can choose the highest 27 bits of A arbitrarily. This time the lowest three bits of A must be 1.

2)
{47, 47, 42}

Returns: 0

Regardless of which A you choose, the first two elements will always be the same and thus the sequence will never be strictly increasing.

3)
{84, 94, 68, 72, 96, 31, 2, 57}

Returns: 67108864



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
		cout << "Testing CapriciousSorting (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1612634740;
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
		CapriciousSorting _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int num[] = {0, 1, 2, 3, 4, 5, 6, 7};
				_expected = 134217728;
				_received = _obj.count(vector <int>(num, num+sizeof(num)/sizeof(int))); break;
			}
			case 1:
			{
				int num[] = {7, 6, 5, 4, 3, 2, 1, 0};
				_expected = 134217728;
				_received = _obj.count(vector <int>(num, num+sizeof(num)/sizeof(int))); break;
			}
			case 2:
			{
				int num[] = {47, 47, 42};
				_expected = 0;
				_received = _obj.count(vector <int>(num, num+sizeof(num)/sizeof(int))); break;
			}
			case 3:
			{
				int num[] = {84, 94, 68, 72, 96, 31, 2, 57};
				_expected = 67108864;
				_received = _obj.count(vector <int>(num, num+sizeof(num)/sizeof(int))); break;
			}
			case 4:
			{
				int num[] = {2, 1, 2};
				_expected = 0;
				_received = _obj.count(vector <int>(num, num+sizeof(num)/sizeof(int))); break;
			}
			/*case 5:
			{
				int num[] = ;
				_expected = ;
				_received = _obj.count(vector <int>(num, num+sizeof(num)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int num[] = ;
				_expected = ;
				_received = _obj.count(vector <int>(num, num+sizeof(num)/sizeof(int))); break;
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
