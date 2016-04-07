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
#define PB push_back
#define MS0(x) memset(x,0,sizeof(x))
#define SZ(x) ((int)(x).size())

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;
//#line 39 "MultiplicationTable2.cpp"
#include <string>
#include <vector>
bool used[100];
class MultiplicationTable2 {
public:
    int minimalGoodSet(vector <int> table) {
        int N = 1;
        while (N * N != SZ(table)) N++;
        int ans = N;
        REP(i, N) {
            MS0(used);
            VI a;
            a.PB(i);
            used[i] = true;
            REP(i1, SZ(a)) {
                int j = a[i1];
                REP(i2, i1+1) {
                    int k = a[i2];
                    if (!used[table[j*N+k]]) {
                        used[table[j*N+k]] = true;
                        a.PB(table[j*N+k]);
                    }
                    if (!used[table[k*N+j]]) {
                        used[table[k*N+j]] = true;
                        a.PB(table[k*N+j]);
                    }
                }
            }
            cout << i << ' ' << SZ(a) << endl;
            ans = min(ans, SZ(a));
        }
        return ans;
    }
};
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Fox Ciel is creating a new binary operation.

The operation will be denoted $ and it will be defined on the finite set S = {0, 1, 2, ..., n-1}.
I.e., for each ordered pair (i, j) of elements of S the operation (i $ j) will return some element of S.

For example, we can have S = {0, 1}, and we can define that (0 $ 0) = 0, (0 $ 1) = 1, (1 $ 0) = 0, and (1 $ 1) = 0.

Note that Ciel's operation is not necessarily symmetric.
In other words, it is possible that for some i and j the operations (i $ j) and (j $ i) return two different values.

A nice concise description of the operation $ is its "multiplication table": a square table where in row i and column j we have the value (i $ j).
You are given this "multiplication table" encoded as a vector <int> table with n^2 elements.
For each valid i and j the operation (i $ j) returns the value table[i*n+j].

A subset T of S is called good if it has the following property:
for any two elements i and j in T, (i $ j) is also in T.

Find and return the minimal size of a good subset of S.
Note that the answer is always defined, as there always are some good subsets.
For example, the entire set S is always good.

DEFINITION
Class:MultiplicationTable2
Method:minimalGoodSet
Parameters:vector <int>
Returns:int
Method signature:int minimalGoodSet(vector <int> table)


CONSTRAINTS
-n will be between 1 and 50, inclusive.
-table will contain exactly n*n elements.
-Each element in table will be between 0 and n-1, inclusive.


EXAMPLES

0)
{1,1,2,3,
 1,0,3,2,
 2,0,1,3,
 1,2,3,0}

Returns: 2

The smallest Good set is {0,1}, we can verify:

0 $ 0 = 1
0 $ 1 = 1
1 $ 0 = 1
1 $ 1 = 0



1)
{0,1,2,3,
 1,2,3,0,
 2,3,0,1,
 3,0,1,2}

Returns: 1

This time the answer is 1 since {0} is a Good set.

2)
{1,1,1,1,
 2,2,2,2,
 3,3,3,3,
 0,0,0,0}

Returns: 4

Now the only Good set is {0,1,2,3}.

3)
{0}

Returns: 1



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
		cout << "Testing MultiplicationTable2 (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1458403204;
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
		MultiplicationTable2 _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int table[] = {1,1,2,3,
				               1,0,3,2,
				               2,0,1,3,
				               1,2,3,0};
				_expected = 2;
				_received = _obj.minimalGoodSet(vector <int>(table, table+sizeof(table)/sizeof(int))); break;
			}
			case 1:
			{
				int table[] = {0,1,2,3,
				               1,2,3,0,
				               2,3,0,1,
				               3,0,1,2};
				_expected = 1;
				_received = _obj.minimalGoodSet(vector <int>(table, table+sizeof(table)/sizeof(int))); break;
			}
			case 2:
			{
				int table[] = {1,1,1,1,
				               2,2,2,2,
				               3,3,3,3,
				               0,0,0,0};
				_expected = 4;
				_received = _obj.minimalGoodSet(vector <int>(table, table+sizeof(table)/sizeof(int))); break;
			}
			case 3:
			{
				int table[] = {0};
				_expected = 1;
				_received = _obj.minimalGoodSet(vector <int>(table, table+sizeof(table)/sizeof(int))); break;
			}
		        case 4:
			{
				int table[] = {1, 0, 2, 3, 4, 0, 4, 4, 3, 4, 0, 2, 0, 2, 0, 3, 2, 4, 0, 0, 2, 0, 2, 2, 2};
				_expected = 4;
				_received = _obj.minimalGoodSet(vector <int>(table, table+sizeof(table)/sizeof(int))); break;
			}
			/*case 5:
			{
				int table[] = ;
				_expected = ;
				_received = _obj.minimalGoodSet(vector <int>(table, table+sizeof(table)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int table[] = ;
				_expected = ;
				_received = _obj.minimalGoodSet(vector <int>(table, table+sizeof(table)/sizeof(int))); break;
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
