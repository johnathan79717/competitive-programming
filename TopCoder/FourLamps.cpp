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

#line 40 "FourLamps.cpp"
#include <string>
#include <vector>
class FourLamps {
public:
  long long count(string init, int k) {

  }
};

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Fox Ciel has n lamps.
The lamps are arranged in a row from the left to the right, and they are numbered 0 through n-1 in that order.
You are given a string init with n characters that describes the initial state of the lamps:
init[i] is '1' if lamp i is initially turned on, or '0' if it is initially turned off.


You are also given an int k.
Below we describe an operation.
Ciel can use that operation at most k times.
Compute and return the number of different final states she can obtain.
(Two states of lamps are different if there is a lamp that is on in one state but off in the other. The initial state is always one of the possible final states.)


The operation looks as follows:

Ciel chooses four consecutive lamps such that either exactly one of them is on, or exactly one of them is off. (If there is no such group of lamps, Ciel cannot perform any more operations.)
Ciel divides all lamps into a left part and a right part so that the division point is in the middle of the four lamps chosen in the previous step. In other words, if the four chosen lamps are x, x+1, x+2, x+3, the left part is {0, 1, ..., x+1} and the right part is {x+2, ..., n-2, n-1}.
Ciel chooses either the left part or the right part.
Ciel toggles all lamps in the chosen part. (Toggling a lamp means switching it to the opposite state.)


DEFINITION
Class:FourLamps
Method:count
Parameters:string, int
Returns:long long
Method signature:long long count(string init, int k)


CONSTRAINTS
-init will contain between 4 and 50 characters, inclusive.
-Each character in init will be '0' or '1'.
-k will be between 1 and 1,000,000,000, inclusive.


EXAMPLES

0)
"0001"
2

Returns: 4

As there are only four lamps, there is only one group of four consecutive lamps.
If these four lamps satisfy the constraint, the left part will be lamps {0,1} and the right part will be lamps {2,3}.


If Ciel performs zero operations, the only possible final state is the initial state "0001".


If Ciel performs one operation, she can either toggle the left part or the right part. Toggling the left part produces the state "1101", toggling the right part produces the state "0010".


Note that both states produced by the first operation still have the property that enables us to do the next operation: exactly one of the four lamps is off in "1101", and exactly one of them is on in "0010".


What states can we reach by performing two operations?


Toggling the left part and then the left part again will bring us back to "0001". Toggling the right part twice has the same effect.


Toggling the left part and then the right part produces the final state "1110". Toggling the right half and then the left half leads to that state as well.


In total there are four possible final states: "0001", "1101", "0010", "1110".

1)
"0001"
1000000000

Returns: 4

In the previous scenario increasing k to 10^9 does not change the answer.
The following operations won't produce any new states of the lamps.

2)
"1010"
100

Returns: 1

This time Ciel cannot make any operation because there are no four consecutive lamps with the required property.
Thus, the only possible final state is the initial state.

3)
"000111"
3

Returns: 12

These are the states we can get:

"000111"
"110111"
"001000"
"111011"
"000100"
"111000"
"001111"
"110000"
"001011"
"110100"
"000011"
"111100"


4)
"00000010000"
5

Returns: 58



5)
"10101100101010001011000100101000100001101"
58

Returns: 100256132848

Watch for overflow.

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
		cout << "Testing FourLamps (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1527949911;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 1000.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		FourLamps _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string init = "0001";
				int k = 2;
				_expected = 4LL;
				_received = _obj.count(init, k); break;
			}
			case 1:
			{
				string init = "0001";
				int k = 1000000000;
				_expected = 4LL;
				_received = _obj.count(init, k); break;
			}
			case 2:
			{
				string init = "1010";
				int k = 100;
				_expected = 1LL;
				_received = _obj.count(init, k); break;
			}
			case 3:
			{
				string init = "000111";
				int k = 3;
				_expected = 12LL;
				_received = _obj.count(init, k); break;
			}
			case 4:
			{
				string init = "00000010000";
				int k = 5;
				_expected = 58LL;
				_received = _obj.count(init, k); break;
			}
			case 5:
			{
				string init = "10101100101010001011000100101000100001101";
				int k = 58;
				_expected = 100256132848LL;
				_received = _obj.count(init, k); break;
			}
			/*case 6:
			{
				string init = ;
				int k = ;
				_expected = LL;
				_received = _obj.count(init, k); break;
			}*/
			/*case 7:
			{
				string init = ;
				int k = ;
				_expected = LL;
				_received = _obj.count(init, k); break;
			}*/
			/*case 8:
			{
				string init = ;
				int k = ;
				_expected = LL;
				_received = _obj.count(init, k); break;
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
