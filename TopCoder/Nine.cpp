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
typedef vector<int> VI;
typedef pair<int, int> PII;

class Nine {
	public:
	int count(int N, vector <int> d) {
		
	}
};
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
Bob's little sister Alice is nine years old.
Bob is testing her mathematical prowess by asking her to compute the remainder a number gives when divided by 9.



Today, Bob gave Alice exactly N such questions.
We will number the questions 0 through N-1.
In each question, Bob gave Alice the same M-digit number.
(Note that Bob's number is allowed to have some leading zeros.)



In some of those cases Alice may have skipped some of the digits when reading the number.
However, she never made any other mistakes in her calculations.
For example, if Bob gave Alice the number 012345 three times, she may have read it as 0145 the first time, 012345 the second time, and 135 the third time.
Then, her answers would be 145 modulo 9 = 1, 12345 modulo 9 = 6, and 135 modulo 9 = 0.



You are given the int N and a vector <int> d with M elements.
For each i, the number d[i] corresponds to the digit of the order 10^i in Bob's number.
For each i and j, Alice read digit i when answering question j if and only if bit number j of the number d[i] is 1.



For example, suppose that d[3] = 6.
In binary, 6 is 110.
In other words, the binary digits number 0, 1, and 2 are 0, 1, and 1.
Hence, Alice skipped the corresponding digit in question 0 but she read it in questions 1 and 2.



A surprising thing happened in today's experiment:
For each of the N questions, Alice's answer was that the remainder is 0.
Bob found that interesting.
He now wonders: given N and d, how many different M-digit numbers have this property?



Let X be the answer to Bob's question.
Compute and return the value (X modulo 1,000,000,007).


DEFINITION
Class:Nine
Method:count
Parameters:int, vector <int>
Returns:int
Method signature:int count(int N, vector <int> d)


CONSTRAINTS
-N will be between 1 and 5, inclusive.
-The number of elements in d will be between 1 and 5,000, inclusive.
-All elements in d must be between 0 and 2N-1, inclusive
-d will be such that in each question Alice will read at least one digit.


EXAMPLES

0)
2
{1,2}

Returns: 4

In this case we have N=2 questions and Bob's number has two digits.
When processing question 0, Alice only reads digit 0 (the last digit of the number).
As her answer is that the remainder is 0, this digit must be either 0 or 9.
When processing question 1, Alice only reads digit 1 (the first digit of the number).
As her answer is that the remainder is 0 again, this digit must also be either 0 or 9.
Thus there are four possible numbers: 00, 09, 90, and 99.

1)
2
{1,2,3}

Returns: 16



2)
1
{0,0,1}

Returns: 200



3)
5
{1,3,5,8,24,22,25,21,30,2,4,0,6,7,9,11,14,13,12,15,18,17,16,19,26,29,31,28,27,10,20,23}

Returns: 450877328



4)
5
{31,31,31,31,31}

Returns: 11112



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
		cout << "Testing Nine (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1428592771;
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
		Nine _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 2;
				int d[] = {1,2};
				_expected = 4;
				_received = _obj.count(N, vector <int>(d, d+sizeof(d)/sizeof(int))); break;
			}
			case 1:
			{
				int N = 2;
				int d[] = {1,2,3};
				_expected = 16;
				_received = _obj.count(N, vector <int>(d, d+sizeof(d)/sizeof(int))); break;
			}
			case 2:
			{
				int N = 1;
				int d[] = {0,0,1};
				_expected = 200;
				_received = _obj.count(N, vector <int>(d, d+sizeof(d)/sizeof(int))); break;
			}
			case 3:
			{
				int N = 5;
				int d[] = {1,3,5,8,24,22,25,21,30,2,4,0,6,7,9,11,14,13,12,15,18,17,16,19,26,29,31,28,27,10,20,23};
				_expected = 450877328;
				_received = _obj.count(N, vector <int>(d, d+sizeof(d)/sizeof(int))); break;
			}
			case 4:
			{
				int N = 5;
				int d[] = {31,31,31,31,31};
				_expected = 11112;
				_received = _obj.count(N, vector <int>(d, d+sizeof(d)/sizeof(int))); break;
			}
			/*case 5:
			{
				int N = ;
				int d[] = ;
				_expected = ;
				_received = _obj.count(N, vector <int>(d, d+sizeof(d)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int N = ;
				int d[] = ;
				_expected = ;
				_received = _obj.count(N, vector <int>(d, d+sizeof(d)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int N = ;
				int d[] = ;
				_expected = ;
				_received = _obj.count(N, vector <int>(d, d+sizeof(d)/sizeof(int))); break;
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
