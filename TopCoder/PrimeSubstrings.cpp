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
 
typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;
const int MAX = 10000000;
bool is_prime[MAX];

#line 41 "PrimeSubstrings.cpp"
#include <string>
#include <vector>
class PrimeSubstrings {
public:
    string construct(int N, int L) {
	//memset(is_prime, -1, sizeof is_prime);
	//for (int p = 2; p < MAX; p++) {
	    //if (is_prime[p]) {
		//for (int k = p+p; k < MAX; k += p) {
		    //is_prime[k] = false;
		//}
	    //}
	//}
	string ans(N, '1');
	switch (L) {
	    case 1:
		REP(i, N) {
		    ans[i] = '2';
		}
		break;
	    case 2:
		REP(i, N) {
		    ans[i] = '1';
		}
		break;
	    case 3:
		REP(i, N) {
		    ans[i] = i % 3 ? '1' : '3';
		}
		break;
	    case 4:
		REP(i, N) {
		    switch (i % L) {
			case 0:
			case 1:
			    ans[i] = '1';
			    break;
			case 2:
			    ans[i] = '9';
			    break;
			case 3:
			    ans[i] = '3';
			    break;
		    }
		}
		break;
	    case 5:
		REP(i, N) {
		    switch (i % L) {
			case 0:
			case 1:
			    ans[i] = '1';
			    break;
			case 2:
			    ans[i] = '9';
			    break;
			case 3:
			    ans[i] = '3';
			    break;
			case 4:
			    ans[i] = '9';
			    break;
		    }
		}
		break;
	    case 6:
		REP(i, N) {
		    switch (i % L) {
			case 0:
			    ans[i] = '1';
			    break;
			case 1:
			case 2:
			case 3:
			    ans[i] = '9';
			    break;
			case 4:
			case 5:
			    ans[i] = '3';
			    break;
		    }
		}
		break;
	    case 7:
		REP(i, N) {
		    switch (i % 8) {
			case 0:
			    ans[i] = '1';
			    break;
			case 1:
			    ans[i] = '3';
			    break;
			case 2:
			    ans[i] = '1';
			    break;
			case 3:
			case 4:
			case 5:
			    ans[i] = '3';
			    break;
			case 6:
			case 7:
			    ans[i] = '9';
			    break;
		    }
		}
		break;

	}
	//REP(i, N-L+1) {
	    //int p = atoi(ans.substr(i, L).c_str());
	    //cout << p << endl;
	    //assert(is_prime[p]);
	//}
	return ans;
    }
};

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
As you certainly know, a positive integer is called a prime if it has exactly two divisors: 1 and itself. The smallest few primes are 2, 3, 5, 7, 11, 13, 17, and so on.


A string of L digits is called a prime string if it does not contain any leading zeros and represents a prime number.
E.g., "7", "47", and "10007" are prime strings but "047" and "42" aren't.


The L-quality of a number is computed by taking its base-10 representation as a string, looking at each (contiguous) substring of length L and counting those that are prime strings.
E.g., the 2-quality of the number 470537 is 3 because its substrings "47", "53", and "37" are prime strings. (The substrings "70" and "05" are not prime strings.)


You are given the ints N and L.
Construct an N-digit positive integer with the largest possible L-quality.
Return a string with its base-10 representation.
Any valid answer will be accepted.


DEFINITION
Class:PrimeSubstrings
Method:construct
Parameters:int, int
Returns:string
Method signature:string construct(int N, int L)


CONSTRAINTS
-N will be between 1 and 1000, inclusive.
-L will be between 1 and 7, inclusive.
-L will be less than or equal to N.


EXAMPLES

0)
4
2

Returns: "5317"



1)
7
7

Returns: "1301779"

The returned number is a prime. Any 7-digit prime is a correct answer for this test case.

2)
5
4

Returns: "13079"



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
		cout << "Testing PrimeSubstrings (400.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1594293790;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 400.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		PrimeSubstrings _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 4;
				int L = 2;
				_expected = "5317";
				_received = _obj.construct(N, L); break;
			}
			case 1:
			{
				int N = 7;
				int L = 7;
				_expected = "1301779";
				_received = _obj.construct(N, L); break;
			}
			case 2:
			{
				int N = 5;
				int L = 4;
				_expected = "13079";
				_received = _obj.construct(N, L); break;
			}
			case 3:
			{
				int N = 20;
				int L = 7;
				_expected = "1301779";
				_received = _obj.construct(N, L); break;
			}
			case 4:
			{
				int N = 20;
				int L = 6;
				_expected = "1301779";
				_received = _obj.construct(N, L); break;
			}
			case 5:
			{
				int N = 20;
				int L = 5;
				_expected = "1301779";
				_received = _obj.construct(N, L); break;
			}
			case 6:
			{
				int N = 20;
				int L = 4;
				_expected = "1301779";
				_received = _obj.construct(N, L); break;
			}
			case 7:
			{
				int N = 20;
				int L = 3;
				_expected = "1301779";
				_received = _obj.construct(N, L); break;
			}
			case 8:
			{
				int N = 20;
				int L = 2;
				_expected = "1301779";
				_received = _obj.construct(N, L); break;
			}
			case 9:
			{
				int N = 20;
				int L = 1;
				_expected = "1301779";
				_received = _obj.construct(N, L); break;
			}
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
			cout << "           Expected: " << "\"" << _expected << "\"" << endl;
			cout << "           Received: " << "\"" << _received << "\"" << endl;
		}
	}
}

// END CUT HERE
