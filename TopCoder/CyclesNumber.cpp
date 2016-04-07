#include <string>
#include <cassert>
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
#define FOR(i, c) for(auto &i: c)
#define PER(i,n) for(int i=(n)-1;i>=0;i--)
#define PER1(i,a,b) for(int i=(a);i>=(b);i--)
#define MP make_pair
#define PB push_back
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,-1,sizeof(x))
#define V(T) vector<T >
#define EB emplace_back
#define MAX(x, a) x = max(x, a)
#define MIN(x, a) x = min(x, a)

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;
// #line 40 "CyclesNumber.cpp"
#include <string>
#include <vector>
class CyclesNumber {
public:
    vector <int> getExpectation(vector <int> n, vector <int> m) {
        
    }
};
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
The level-M weight of a permutation P, denoted W(P,M), is computed by finding the number of cycles of P and then taking that number to the M-th power.
For example, the level-3 weight of a permutation with 5 cycles is 5^3.


The total level-M weight of all permutations on N elements, denoted T(N,M), is computed as the sum of W(P,M) over all N! possible permutations P on N elements.


You are given multiple queries.
These are encoded as two vector <int>s n and m with the same number of elements.
Return a vector <int> with the same number of elements as n.
For each valid i, element i of the return value should be the value T( n[i], m[i] ) modulo 1,000,000,007.


DEFINITION
Class:CyclesNumber
Method:getExpectation
Parameters:vector <int>, vector <int>
Returns:vector <int>
Method signature:vector <int> getExpectation(vector <int> n, vector <int> m)


NOTES
-Formally, a permutation on N elements is a bijective function P defined on an N-element set S.
-A cycle of a permutation is a sequence c[0], c[1], ..., c[k-1] of distinct elements of S such that for each i, P(c[i]) = c[(i+1) mod k].


CONSTRAINTS
-n and m will contain the same number of elements.
-n will contain between 1 and 300 elements, inclusive.
-Each element of n will be between 1 and 100,000, inclusive.
-Each element of m will be between 0 and 300, inclusive.


EXAMPLES

0)
{2}
{2}

Returns: {5 }

Here are two permutations: (1, 2) and (2, 1). (1, 2) have 2 cycles. (2, 1) has one cycle. So answer is 1 * 1 + 2 * 2 = 5.

1)
{3}
{0}

Returns: {6 }

Here answer is just number of permutations, 3! = 6.

2)
{1, 2, 3}
{1, 3, 3}

Returns: {1, 9, 53 }

Could be more than one query.

3)
{10, 20, 30}
{10, 20, 30}

Returns: {586836447, 544389755, 327675273 }

Do not forget take answers modulo 1,000,000,007.

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
		cout << "Testing CyclesNumber (600.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1459214306;
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
		CyclesNumber _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n[] = {2};
				int m[] = {2};
				int __expected[] = {5 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getExpectation(vector <int>(n, n+sizeof(n)/sizeof(int)), vector <int>(m, m+sizeof(m)/sizeof(int))); break;
			}
			case 1:
			{
				int n[] = {3};
				int m[] = {0};
				int __expected[] = {6 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getExpectation(vector <int>(n, n+sizeof(n)/sizeof(int)), vector <int>(m, m+sizeof(m)/sizeof(int))); break;
			}
			case 2:
			{
				int n[] = {1, 2, 3};
				int m[] = {1, 3, 3};
				int __expected[] = {1, 9, 53 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getExpectation(vector <int>(n, n+sizeof(n)/sizeof(int)), vector <int>(m, m+sizeof(m)/sizeof(int))); break;
			}
			case 3:
			{
				int n[] = {10, 20, 30};
				int m[] = {10, 20, 30};
				int __expected[] = {586836447, 544389755, 327675273 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getExpectation(vector <int>(n, n+sizeof(n)/sizeof(int)), vector <int>(m, m+sizeof(m)/sizeof(int))); break;
			}
			/*case 4:
			{
				int n[] = ;
				int m[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getExpectation(vector <int>(n, n+sizeof(n)/sizeof(int)), vector <int>(m, m+sizeof(m)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int n[] = ;
				int m[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getExpectation(vector <int>(n, n+sizeof(n)/sizeof(int)), vector <int>(m, m+sizeof(m)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int n[] = ;
				int m[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getExpectation(vector <int>(n, n+sizeof(n)/sizeof(int)), vector <int>(m, m+sizeof(m)/sizeof(int))); break;
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
