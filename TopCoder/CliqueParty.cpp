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
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define ALL(x) (x).begin(),(x).end()
#define MS0(x) memset(x,0,sizeof(x))

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;
#line 39 "CliqueParty.cpp"
#include <string>
#include <vector>

int dp[100];

class CliqueParty {
public:
    int maxsize(vector <int> a, int k) {
        sort(ALL(a));
        int ans = 2;
        int N = a.size();
        REP(i, N) REP(j, i) {
            MS0(dp);
            dp[j] = 1;
            int d = (a[i] - a[j] + k-1) / k;
            REP1(m, j+1, i) {
                REP(l, m) {
                    if (!dp[l]) continue;
                    if (a[m] - a[l] >= d) {
                        dp[m] = max(dp[m], dp[l] + 1);
                    }
                }
            }
            ans = max(ans, dp[i]);
        }        
        return ans;
    }
};
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// A set of positive integers is called k-smooth if each pair (A,B) of elements of the set satisfies A <= k * B.
For example, the set {3,4,7,9} is 3-smooth but the set {30,60,100} is not: 100 is strictly more than 3 * 30.

Hero likes some sets of integers.
In order to determine whether he likes a set S, Hero uses the following procedure:

Form a new set D of pairwise differences of elements in S. In other words: for each pair of elements A, B in S, put the number |A-B| into D.
Hero likes the original set S if and only if the new set D is k-smooth.


You are given a vector <int> a containing a set of distinct integers.
You are also given the int k Hero uses while determining whether he likes a set of integers.

Select the largest subset of a Hero likes.
Return the number of elements in that subset.

DEFINITION
Class:CliqueParty
Method:maxsize
Parameters:vector <int>, int
Returns:int
Method signature:int maxsize(vector <int> a, int k)


CONSTRAINTS
-Number of elements in a will be between 2 and 50, inclusive.
-Each elements in a will be between 1 and 1,000,000,000, inclusive.
-All elements in a will be distinct.
-k will be between 1 and 1,000,000,000, inclusive.


EXAMPLES

0)
{1,2,3}
2

Returns: 3

Hero likes the entire set a.

1)
{1,2,3}
1

Returns: 2

Here, Hero does not like the entire set a, but he does like, for example, the subset {1,3}.

2)
{4,10,5,6}
2

Returns: 3



3)
{1,2,3,4,5,6}
3

Returns: 4



4)
{10,9,25,24,23,30}
7

Returns: 4



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
		cout << "Testing CliqueParty (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1457366405;
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
		CliqueParty _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int a[] = {1,2,3};
				int k = 2;
				_expected = 3;
				_received = _obj.maxsize(vector <int>(a, a+sizeof(a)/sizeof(int)), k); break;
			}
			case 1:
			{
				int a[] = {1,2,3};
				int k = 1;
				_expected = 2;
				_received = _obj.maxsize(vector <int>(a, a+sizeof(a)/sizeof(int)), k); break;
			}
			case 2:
			{
				int a[] = {4,10,5,6};
				int k = 2;
				_expected = 3;
				_received = _obj.maxsize(vector <int>(a, a+sizeof(a)/sizeof(int)), k); break;
			}
			case 3:
			{
				int a[] = {1,2,3,4,5,6};
				int k = 3;
				_expected = 4;
				_received = _obj.maxsize(vector <int>(a, a+sizeof(a)/sizeof(int)), k); break;
			}
			case 4:
			{
				int a[] = {10,9,25,24,23,30};
				int k = 7;
				_expected = 4;
				_received = _obj.maxsize(vector <int>(a, a+sizeof(a)/sizeof(int)), k); break;
			}
			/*case 5:
			{
				int a[] = ;
				int k = ;
				_expected = ;
				_received = _obj.maxsize(vector <int>(a, a+sizeof(a)/sizeof(int)), k); break;
			}*/
			/*case 6:
			{
				int a[] = ;
				int k = ;
				_expected = ;
				_received = _obj.maxsize(vector <int>(a, a+sizeof(a)/sizeof(int)), k); break;
			}*/
			/*case 7:
			{
				int a[] = ;
				int k = ;
				_expected = ;
				_received = _obj.maxsize(vector <int>(a, a+sizeof(a)/sizeof(int)), k); break;
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
