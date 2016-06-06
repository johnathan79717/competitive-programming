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
// #line 40 "QuickSums.cpp"
#include <string>
#include <vector>
class QuickSums {
public:
    int minSums(string numbers, int sum) {
        int N = numbers.size();
        vector<vector<int>> dp(N+1, vector<int>(sum+1, 1e9));
        dp[0][0] = -1;
        for (int i = 0; i < N; i++) {
            int a = 0;
            for (int j = 0; j <= i; j++) {
                a += (numbers[i-j] - '0') * pow(10, j);
                if (a > sum) break;
                for (int k = 0; k <= sum - a; k++) {
                    dp[i+1][k+a] = min(dp[i+1][k+a], dp[i-j][k] + 1);
                }
            }
        }
        return dp[N][sum] < 1e9 ? dp[N][sum] : -1;
    }
};
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Given a string of digits, find the minimum number of additions required for the string to equal some target number.  Each addition is the equivalent of inserting a plus sign somewhere into the string of digits.  After all plus signs are inserted, evaluate the sum as usual.  For example, consider the string "12" (quotes for clarity).  With zero additions, we can achieve the number 12.  If we insert one plus sign into the string, we get "1+2", which evaluates to 3.  So, in that case, given "12", a minimum of 1 addition is required to get the number 3.  As another example, consider "303" and a target sum of 6.  The best strategy is not "3+0+3", but "3+03".  You can do this because leading zeros do not change the result.

Write a class QuickSums that contains the method minSums, which takes a string numbers and an int sum.  The method should calculate and return the minimum number of additions required to create an expression from numbers that evaluates to sum.  If this is impossible, return -1.

DEFINITION
Class:QuickSums
Method:minSums
Parameters:string, int
Returns:int
Method signature:int minSums(string numbers, int sum)


CONSTRAINTS
-numbers will contain between 1 and 10 characters, inclusive.
-Each character in numbers will be a digit.
-sum will be between 0 and 100, inclusive.


EXAMPLES

0)
"99999"
45

Returns: 4

In this case, the only way to achieve 45 is to add 9+9+9+9+9.  This requires 4 additions.

1)
"1110"
3

Returns: 3

Be careful with zeros.  1+1+1+0=3 and requires 3 additions.

2)
"0123456789"
45

Returns: 8

3)
"99999"
100

Returns: -1

4)
"382834"
100

Returns: 2

There are 3 ways to get 100.  They are 38+28+34, 3+8+2+83+4 and 3+82+8+3+4.  The minimum required is 2.

5)
"9230560001"
71

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
		cout << "Testing QuickSums (1100.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1463309822;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 1100.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		QuickSums _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string numbers = "99999";
				int sum = 45;
				_expected = 4;
				_received = _obj.minSums(numbers, sum); break;
			}
			case 1:
			{
				string numbers = "1110";
				int sum = 3;
				_expected = 3;
				_received = _obj.minSums(numbers, sum); break;
			}
			case 2:
			{
				string numbers = "0123456789";
				int sum = 45;
				_expected = 8;
				_received = _obj.minSums(numbers, sum); break;
			}
			case 3:
			{
				string numbers = "99999";
				int sum = 100;
				_expected = -1;
				_received = _obj.minSums(numbers, sum); break;
			}
			case 4:
			{
				string numbers = "382834";
				int sum = 100;
				_expected = 2;
				_received = _obj.minSums(numbers, sum); break;
			}
			case 5:
			{
				string numbers = "9230560001";
				int sum = 71;
				_expected = 4;
				_received = _obj.minSums(numbers, sum); break;
			}
			/*case 6:
			{
				string numbers = ;
				int sum = ;
				_expected = ;
				_received = _obj.minSums(numbers, sum); break;
			}*/
			/*case 7:
			{
				string numbers = ;
				int sum = ;
				_expected = ;
				_received = _obj.minSums(numbers, sum); break;
			}*/
			/*case 8:
			{
				string numbers = ;
				int sum = ;
				_expected = ;
				_received = _obj.minSums(numbers, sum); break;
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
