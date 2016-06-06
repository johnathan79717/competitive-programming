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
// #line 40 "AlmostFibonacciKnapsack.cpp"
#include <string>
#include <vector>
class AlmostFibonacciKnapsack {
public:
    vector <int> getIndices(long long x) {
        
    }
};
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
You are given a sequence of integers.
This sequence is defined as follows:

A[1] = 2
A[2] = 3
for each n >= 3, A[n] = A[n-1] + A[n-2] - 1




You are given a long long x that is at least 2.
Your task is to write x as a sum of distinct elements of the above sequence.
More precisely, you have to find and return any valid vector <int> B with the following properties:

The elements of B are distinct positive integers.
x = A[B[0]] + A[B[1]] + ... + A[B[k-1]], where k is the number of elements in B.




If there are multiple solutions, return any of them.
If there are no solutions, return the vector <int> {-1} instead.


DEFINITION
Class:AlmostFibonacciKnapsack
Method:getIndices
Parameters:long long
Returns:vector <int>
Method signature:vector <int> getIndices(long long x)


CONSTRAINTS
-x will be between 2 and 10^18, inclusive.


EXAMPLES

0)
148

Returns: {6, 10, 8, 5 }

The first few terms of the sequence are 2,3,4,6,9,14,22,35,56,90.
We can see that 14+90+35+9=148, and their respective indices are 6,10,8,5.

1)
2

Returns: {1 }



2)
13

Returns: {2, 3, 4 }



3)
3

Returns: {2 }



4)
86267769395

Returns: {3, 14, 15, 9, 26, 53, 5, 8 }



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
		cout << "Testing AlmostFibonacciKnapsack (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1460725388;
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
		AlmostFibonacciKnapsack _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				long long x = 148LL;
				int __expected[] = {6, 10, 8, 5 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getIndices(x); break;
			}
			case 1:
			{
				long long x = 2LL;
				int __expected[] = {1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getIndices(x); break;
			}
			case 2:
			{
				long long x = 13LL;
				int __expected[] = {2, 3, 4 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getIndices(x); break;
			}
			case 3:
			{
				long long x = 3LL;
				int __expected[] = {2 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getIndices(x); break;
			}
			case 4:
			{
				long long x = 86267769395LL;
				int __expected[] = {3, 14, 15, 9, 26, 53, 5, 8 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getIndices(x); break;
			}
			/*case 5:
			{
				long long x = LL;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getIndices(x); break;
			}*/
			/*case 6:
			{
				long long x = LL;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getIndices(x); break;
			}*/
			/*case 7:
			{
				long long x = LL;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getIndices(x); break;
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
