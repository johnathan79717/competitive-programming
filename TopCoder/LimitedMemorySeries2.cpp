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
#line 39 "LimitedMemorySeries2.cpp"
#include <string>
#include <vector>
class LimitedMemorySeries2 {
public:
    int getSum(int n, long long x0, long long a, long long b) {
        
    }
};
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Due to some infrastructure limits the memory limit is set to 13 MB. Note that this should correspond to an actual memory limit of only 1 MB. If your solution allocates more than 1 MB of memory, it may exceed the memory limit.


You are given an array X[0..n-1] of integers.
For each i between 0 and n-1, inclusive, the radius of element i is the largest k with the following properties:

Both i-k and i+k are valid indices into the array. That is, i-k >= 0 and i+k < n.
The value X[i] is the strict maximum among the values X[i-k], X[i-k+1], ..., X[i+k]. (Here, "strict" means that the values at all other indices must be strictly smaller.)




For example, in the array X = {4,4,4,4,4} the radius of each element is 0, and in the array X = {10,20,30,20} the radius of element 2 (0-based index) is 1.



Your task is to find the radius of each element of X and to compute the sum of all those radii.
Right now, this seems like a fairly standard problem.
Here's the catch: the memory limit in this problem is really small.
So small that you cannot even store the array X into memory.



You are given the int n and the long longs x0, a, and b.
Use the following pseudocode to generate the array X:



X[0] = x0
for i = 1 to n-1:
        X[i] = ((X[i-1] XOR a) + b) AND ((2^50) - 1)



In the above pseudocode, XOR and AND are the standard operators "bitwise xor" and "bitwise and".



Return the sum of radii of all elements of X, modulo 1,000,000,007.


DEFINITION
Class:LimitedMemorySeries2
Method:getSum
Parameters:int, long long, long long, long long
Returns:int
Method signature:int getSum(int n, long long x0, long long a, long long b)


CONSTRAINTS
-n will be between 1 and 10,000,000, inclusive.
-x0, a and b will be between 0 and 2^50-1, inclusive.


EXAMPLES

0)
6
2
23
1

Returns: 2

In this case, the generated array is X = {2,22,2,22,2,22}.
The radii of its elements are {0,1,0,1,0,0}.
The correct return value is 0+1+0+1+0+0 = 2.

1)
100
0
0
1

Returns: 0

Here, the generated array is {0,1,...,99}. The radius of each element is zero, so the answer is zero in this case.

2)
234234
1125899906842623
123456789123456
987654321549687

Returns: 1144970

Don't forget, the answer is modulo 1,000,000,007.

3)
10000000
12345678912345
98765094309812
34893049812392

Returns: 65420804

It is highly recommended to test this example in the arena before submitting.

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
		cout << "Testing LimitedMemorySeries2 (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1454779177;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 500.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		LimitedMemorySeries2 _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 6;
				long long x0 = 2LL;
				long long a = 23LL;
				long long b = 1LL;
				_expected = 2;
				_received = _obj.getSum(n, x0, a, b); break;
			}
			case 1:
			{
				int n = 100;
				long long x0 = 0LL;
				long long a = 0LL;
				long long b = 1LL;
				_expected = 0;
				_received = _obj.getSum(n, x0, a, b); break;
			}
			case 2:
			{
				int n = 234234;
				long long x0 = 1125899906842623LL;
				long long a = 123456789123456LL;
				long long b = 987654321549687LL;
				_expected = 1144970;
				_received = _obj.getSum(n, x0, a, b); break;
			}
			case 3:
			{
				int n = 10000000;
				long long x0 = 12345678912345LL;
				long long a = 98765094309812LL;
				long long b = 34893049812392LL;
				_expected = 65420804;
				_received = _obj.getSum(n, x0, a, b); break;
			}
			/*case 4:
			{
				int n = ;
				long long x0 = LL;
				long long a = LL;
				long long b = LL;
				_expected = ;
				_received = _obj.getSum(n, x0, a, b); break;
			}*/
			/*case 5:
			{
				int n = ;
				long long x0 = LL;
				long long a = LL;
				long long b = LL;
				_expected = ;
				_received = _obj.getSum(n, x0, a, b); break;
			}*/
			/*case 6:
			{
				int n = ;
				long long x0 = LL;
				long long a = LL;
				long long b = LL;
				_expected = ;
				_received = _obj.getSum(n, x0, a, b); break;
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
