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
#include <cassert>
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

#line 41 "RochesterSequence.cpp"
#include <string>
#include <vector>
class RochesterSequence {
public:
    vector <int> solve(vector <int> Sprefix, int n, int a, int b, int m) {

    }
};

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
This problem has a nonstandard time limit: 4 seconds.


In a Rochester draft there are x people (numbered from 0 to x-1) and 2*x objects of different value.
The purpose of the draft is that each person should acquire two of the objects.
The draft works as follows:


Going from 0 to x-1, each person picks one of the objects that haven't been picked so far.
Going back from x-1 to 0, each person picks another object. (The very last pick is forced, as there is only one object left.)


A Rochester sequence is a sequence of length 2*x that represents the values of objects in the order in which they have been picked.
A Rochester sequence is called nondecreasing ("NRS" for short) if the total values acquired by the people form a nondecreasing sequence.
For example, {10, 5, 9, 9, 12, 7} is a NRS because 10+7 <= 5+12 <= 9+9.


You are given a sequence S.
You want to erase some (possibly none) elements of S in such a way that what remains will be a NRS.
Let L be the largest possible length of that NRS.
Let W be the number of ways in which you can erase some elements and obtain a NRS of length L.
Return a vector <int> with two elements: { L, W modulo (10^9 + 7) }.


The sequence S is given in the following format: You are given the vector <int> Sprefix and the ints n, a, b, and m.
Use the following pseudocode to generate S:


for i = 0 to length(Sprefix)-1:
    S[i] = Sprefix[i]
for i = length(Sprefix) to n-1:
    S[i] = ( S[i-1] * a + b ) modulo m



DEFINITION
Class:RochesterSequence
Method:solve
Parameters:vector <int>, int, int, int, int
Returns:vector <int>
Method signature:vector <int> solve(vector <int> Sprefix, int n, int a, int b, int m)


NOTES
-The reference solution does not depend on any properties of the pseudorandom generator.


CONSTRAINTS
-n will be between 2 and 1000, inclusive.
-Sprefix will contain between 1 and n elements, inclusive.
-Sprefix will contain at most 200 elements.
-Each element of Sprefix will be between 0 and 10^9 + 6, inclusive.
-m will be between 1 and 10^9 + 7, inclusive.
-Each of a and b will be between 0 and m-1, inclusive.


EXAMPLES

0)
{10, 5, 9, 9, 12, 7}
6
0
0
1

Returns: {6, 1 }

The example from the problem statement. As this is a NRS, the only optimal solution is to erase nothing and obtain a NRS of length 6.

1)
{10, 20, 30, 40, 50, 60, 70}
7
0
0
474747

Returns: {6, 5 }

There are five valid ways to erase a single element and obtain a NRS of length 6.
Note that the following are not NRSs:

{10, 20, 30, 40, 50, 70}
{10, 20, 30, 40, 60, 70}


2)
{64, 32, 16, 8, 4, 2, 1}
7
0
0
1

Returns: {2, 21 }

Here the optimal solution is to erase any five of these seven elements. There are 21 ways to do so.

3)
{1}
10
1000
1
1000000007

Returns: {8, 10 }

Watch out for integer overflow when generating the sequence S. This sequence S looks as follows: 1 1001 1001001 1000994 993994 993994001 993994050 994043050 43043043 43042700.

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
		cout << "Testing RochesterSequence (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1547917657;
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
		RochesterSequence _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int Sprefix[] = {10, 5, 9, 9, 12, 7};
				int n = 6;
				int a = 0;
				int b = 0;
				int m = 1;
				int __expected[] = {6, 1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.solve(vector <int>(Sprefix, Sprefix+sizeof(Sprefix)/sizeof(int)), n, a, b, m); break;
			}
			case 1:
			{
				int Sprefix[] = {10, 20, 30, 40, 50, 60, 70};
				int n = 7;
				int a = 0;
				int b = 0;
				int m = 474747;
				int __expected[] = {6, 5 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.solve(vector <int>(Sprefix, Sprefix+sizeof(Sprefix)/sizeof(int)), n, a, b, m); break;
			}
			case 2:
			{
				int Sprefix[] = {64, 32, 16, 8, 4, 2, 1};
				int n = 7;
				int a = 0;
				int b = 0;
				int m = 1;
				int __expected[] = {2, 21 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.solve(vector <int>(Sprefix, Sprefix+sizeof(Sprefix)/sizeof(int)), n, a, b, m); break;
			}
			case 3:
			{
				int Sprefix[] = {1};
				int n = 10;
				int a = 1000;
				int b = 1;
				int m = 1000000007;
				int __expected[] = {8, 10 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.solve(vector <int>(Sprefix, Sprefix+sizeof(Sprefix)/sizeof(int)), n, a, b, m); break;
			}
			/*case 4:
			{
				int Sprefix[] = ;
				int n = ;
				int a = ;
				int b = ;
				int m = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.solve(vector <int>(Sprefix, Sprefix+sizeof(Sprefix)/sizeof(int)), n, a, b, m); break;
			}*/
			/*case 5:
			{
				int Sprefix[] = ;
				int n = ;
				int a = ;
				int b = ;
				int m = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.solve(vector <int>(Sprefix, Sprefix+sizeof(Sprefix)/sizeof(int)), n, a, b, m); break;
			}*/
			/*case 6:
			{
				int Sprefix[] = ;
				int n = ;
				int a = ;
				int b = ;
				int m = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.solve(vector <int>(Sprefix, Sprefix+sizeof(Sprefix)/sizeof(int)), n, a, b, m); break;
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
