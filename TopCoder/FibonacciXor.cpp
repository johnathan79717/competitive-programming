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
 
typedef long long LL;

struct FibonacciXor {
  int find(long long A, long long B) {

  }
};

// BEGIN CUT HERE
/*
PROBLEM STATEMENT
The Fibonacci sequence is defined as follows:

F[0] = 0
F[1] = 1
for each i >= 2: F[i] = F[i-1] + F[i-2]

Thus, the Fibonacci sequence starts as follows: 0, 1, 1, 
2, 3, 5, 8, 13, ...
The elements of the Fibonacci sequence are called 
Fibonacci numbers.

Fibonacci base is a positional numeral system.
The only two allowed digits are 0 and 1.
The weights assigned to positions in the number are all 
distinct positive Fibonacci numbers, in order.
For example, in Fibonacci base the sequence of digits 1101 
represents the number 1*5 + 1*3 + 0*2 + 1*1 = 9.
Some numbers have more than one representation in 
Fibonacci base.
For example, we can also represent 9 as 10001, because 1*8 
+ 0*5 + 0*3 + 0*2 + 1*1 = 9.

Consider the following greedy algorithm:

decompose(n):
    L = an empty list
    while n > 0:
        find the largest Fibonacci number f <= n
        append f to L
        n = n-f
    return L

It can easily be shown that the above algorithm will write 
any positive integer n as a sum of distinct Fibonacci 
numbers.
In other words, the above algorithm chooses one particular 
representation of n in Fibonacci base.
For example, for n=9 we get the representation 10001 (i.
e., 8+1), and for n=30 we get 1010001 (i.e., 21+8+1).

We can now define a new function g. The value g(n) is 
computed as follows:

Use the above algorithm to find a representation of n in 
Fibonacci base.
Take the sequence of digits obtained in step 1, and 
interpret it as a binary number (i.e., a number in base 2).
Return the value of that binary number.


For example, suppose that n=30.
First, we compute that 30 in Fibonacci base is 1010001.
Next, we compute that 1010001 in base 2 is 64+16+1=81.
Hence, g(30)=81.

You are given long longs A and B.
Compute and return the following value:
(g(A) xor g(A+1) xor g(A+2) xor ... xor g(B-2) xor g(B-1) 
xor g(B)) modulo 1,000,000,007.

DEFINITION
Class:FibonacciXor
Method:find
Parameters:long long, long long
Returns:int
Method signature:int find(long long A, long long B)


CONSTRAINTS
-B will be between 1 and 10^15, inclusive.
-A will be between 1 and B, inclusive.


EXAMPLES

0)
1
2

Returns: 3

We have g(1)=1, g(2)=2, and (1 xor 2)=3.

1)
3
10

Returns: 25

Our greedy algorithm chooses the following Fibonacci base 
representations for the numbers 3 through 10:

00100

00101

01000

01001

01010

10000

10001

10010


(Note that for clarity we included some leading zeros in 
some of the representations.)


If we consider these as base-2 numbers, their values are 
4, 5, 8, 9, 10, 16, 17, and 18.
Thus, the answer is (4 xor 5 xor 8 xor ... xor 18) = 25.

2)
1
1000000000000000

Returns: 780431495

Don't forget the modulo 1,000,000,007.

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
		cout << "Testing FibonacciXor (900.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1401332653;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 900.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		FibonacciXor _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				long long A = 1LL;
				long long B = 2LL;
				_expected = 3;
				_received = _obj.find(A, B); break;
			}
			case 1:
			{
				long long A = 3LL;
				long long B = 10LL;
				_expected = 25;
				_received = _obj.find(A, B); break;
			}
			case 2:
			{
				long long A = 1LL;
				long long B = 1000000000000000LL;
				_expected = 780431495;
				_received = _obj.find(A, B); break;
			}
			/*case 3:
			{
				long long A = LL;
				long long B = LL;
				_expected = ;
				_received = _obj.find(A, B); break;
			}*/
			/*case 4:
			{
				long long A = LL;
				long long B = LL;
				_expected = ;
				_received = _obj.find(A, B); break;
			}*/
			/*case 5:
			{
				long long A = LL;
				long long B = LL;
				_expected = ;
				_received = _obj.find(A, B); break;
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
