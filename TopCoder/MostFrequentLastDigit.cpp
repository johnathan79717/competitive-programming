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
#define PB push_back
 
typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;

#line 41 "MostFrequentLastDigit.cpp"
#include <string>
#include <vector>
class MostFrequentLastDigit {
public:
    vector <int> generate(int n, int d) {
	int a = n / 2, b = (n + 1) / 2;
	VI ans;
	int x = d == 1 ? 2 : 1;
	REP(i, a) {
	    ans.PB(x);
	    x += 10;
	}
	if ((x + x) % 10 != d) {
	    x = (d - x) % 10;
	    if (x < 0) x += 10;
	}
	REP(i, b) {
	    ans.PB(x);
	    x += 10;
	}
	return ans;
    }
};

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
You are given the ints n and d.
Return any vector <int> with the following properties:


The number of elements is n.
Each element is between 0 and 10^9, inclusive.
All elements are distinct.
No element is divisible by 10.
If we take all n*(n-1)/2 possible sums of two elements and look at the last digit of each of them, the digit d will be the unique most frequent one.


DEFINITION
Class:MostFrequentLastDigit
Method:generate
Parameters:int, int
Returns:vector <int>
Method signature:vector <int> generate(int n, int d)


CONSTRAINTS
-n will be between 2 and 200, inclusive.
-d will be between 0 and 9, inclusive.


EXAMPLES

0)
4
7

Returns: {1, 6, 13, 4 }

The pairwise sums are 7, 14, 5, 19, 10, and 17. The last digit 7 appears in two of them, and each other digit appears at most once as a last digit of one of these sums.

1)
2
8

Returns: {44, 444 }

Note that {4, 4} is not a valid return value because all numbers must be distinct.}

2)
7
2

Returns: {109, 22, 74, 23, 29, 9, 1003 }



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
		cout << "Testing MostFrequentLastDigit (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1547913604;
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
		MostFrequentLastDigit _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 4;
				int d = 7;
				int __expected[] = {1, 6, 13, 4 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.generate(n, d); break;
			}
			case 1:
			{
				int n = 2;
				int d = 8;
				int __expected[] = {44, 444 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.generate(n, d); break;
			}
			case 2:
			{
				int n = 7;
				int d = 2;
				int __expected[] = {109, 22, 74, 23, 29, 9, 1003 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.generate(n, d); break;
			}
			/*case 3:
			{
				int n = ;
				int d = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.generate(n, d); break;
			}*/
			/*case 4:
			{
				int n = ;
				int d = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.generate(n, d); break;
			}*/
			/*case 5:
			{
				int n = ;
				int d = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.generate(n, d); break;
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
