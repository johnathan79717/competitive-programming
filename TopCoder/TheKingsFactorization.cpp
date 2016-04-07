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

class TheKingsFactorization {
	public:
	vector<long long> getVector(long long N, vector<long long> primes) {
		FOR(p, primes) N /= p;
		switch (primes.size()) {
			case 1:
				if (N > 1)
					primes.PB(N);
				return primes;
			// case 2:
			// 	if (N < primes.back()) {
			// 		primes.insert(primes.begin() + 1, N);
			// 	} else {
			// 		primes.PB(N);
			// 	}
			// 	return primes;
			default:
				// auto it = primes.begin() + 1;
				int it = 1;
				LL p;
				for (p = 2; p * p <= N; p++) {
					while (N % p == 0) {
						N /= p;
						primes.insert(primes.begin() + it, p);
						it += 2;
					}
					if (primes.begin() + it == primes.end())
						break;
				}
				if (N > 1) {
					primes.insert(primes.begin() + it, N);
				}
				return primes;
		}
	}
};
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
The King of Byteland likes integer factorization.
Your task is to help him factor the number N.
You will be given the long long N and you should return a vector<long long> containing all prime factors of N sorted in non-decreasing order.
Note that some primes may occur multiple times in the prime factorization of N.
For example, for N = 60 the only correct return value is {2, 2, 3, 5} because 2*2*3*5 = 60.




To make this task easier, the King has decided to give you a hint.
He already knows the correct factorization and he will tell you every second number in the correct return value.
More precisely, in addition to N you will be given a vector<long long> primes.
The number of elements in primes will be (M+1)/2, rounded down, where M is the number of elements in the correct return value.
For each valid i, primes[i] will be equal to the element 2i of the correct return value.
(All indices are 0-based.)




Given N and primes, return the vector<long long> containing the factorization of N.


DEFINITION
Class:TheKingsFactorization
Method:getVector
Parameters:long long, vector<long long>
Returns:vector<long long>
Method signature:vector<long long> getVector(long long N, vector<long long> primes)


CONSTRAINTS
-N will be between 2 and 1,000,000,000,000,000,000 (10^18), inclusive.
-primes will contain the correct prime factors (as defined in the problem statement).


EXAMPLES

0)
12
{2, 3}

Returns: {2, 2, 3 }



1)
7
{7}

Returns: {7 }



2)
1764
{2, 3, 7}

Returns: {2, 2, 3, 3, 7, 7 }



3)
49
{7}

Returns: {7, 7 }



4)
210
{2, 5}

Returns: {2, 3, 5, 7 }



5)
100000
{2, 2, 2, 5, 5}

Returns: {2, 2, 2, 2, 2, 5, 5, 5, 5, 5 }



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
		cout << "Testing TheKingsFactorization (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1420119231;
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
		TheKingsFactorization _obj;
		vector<long long> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				long long N = 12LL;
				long long primes[] = {2, 3};
				long long __expected[] = {2, 2, 3 };
				_expected = vector<long long>(__expected, __expected+sizeof(__expected)/sizeof(long long));
				_received = _obj.getVector(N, vector<long long>(primes, primes+sizeof(primes)/sizeof(long long))); break;
			}
			case 1:
			{
				long long N = 7LL;
				long long primes[] = {7};
				long long __expected[] = {7 };
				_expected = vector<long long>(__expected, __expected+sizeof(__expected)/sizeof(long long));
				_received = _obj.getVector(N, vector<long long>(primes, primes+sizeof(primes)/sizeof(long long))); break;
			}
			case 2:
			{
				long long N = 1764LL;
				long long primes[] = {2, 3, 7};
				long long __expected[] = {2, 2, 3, 3, 7, 7 };
				_expected = vector<long long>(__expected, __expected+sizeof(__expected)/sizeof(long long));
				_received = _obj.getVector(N, vector<long long>(primes, primes+sizeof(primes)/sizeof(long long))); break;
			}
			case 3:
			{
				long long N = 49LL;
				long long primes[] = {7};
				long long __expected[] = {7, 7 };
				_expected = vector<long long>(__expected, __expected+sizeof(__expected)/sizeof(long long));
				_received = _obj.getVector(N, vector<long long>(primes, primes+sizeof(primes)/sizeof(long long))); break;
			}
			case 4:
			{
				long long N = 210LL;
				long long primes[] = {2, 5};
				long long __expected[] = {2, 3, 5, 7 };
				_expected = vector<long long>(__expected, __expected+sizeof(__expected)/sizeof(long long));
				_received = _obj.getVector(N, vector<long long>(primes, primes+sizeof(primes)/sizeof(long long))); break;
			}
			case 5:
			{
				long long N = 100000LL;
				long long primes[] = {2, 2, 2, 5, 5};
				long long __expected[] = {2, 2, 2, 2, 2, 5, 5, 5, 5, 5 };
				_expected = vector<long long>(__expected, __expected+sizeof(__expected)/sizeof(long long));
				_received = _obj.getVector(N, vector<long long>(primes, primes+sizeof(primes)/sizeof(long long))); break;
			}
			/*case 6:
			{
				long long N = LL;
				long long primes[] = ;
				long long __expected[] = ;
				_expected = vector<long long>(__expected, __expected+sizeof(__expected)/sizeof(long long));
				_received = _obj.getVector(N, vector<long long>(primes, primes+sizeof(primes)/sizeof(long long))); break;
			}*/
			/*case 7:
			{
				long long N = LL;
				long long primes[] = ;
				long long __expected[] = ;
				_expected = vector<long long>(__expected, __expected+sizeof(__expected)/sizeof(long long));
				_received = _obj.getVector(N, vector<long long>(primes, primes+sizeof(primes)/sizeof(long long))); break;
			}*/
			/*case 8:
			{
				long long N = LL;
				long long primes[] = ;
				long long __expected[] = ;
				_expected = vector<long long>(__expected, __expected+sizeof(__expected)/sizeof(long long));
				_received = _obj.getVector(N, vector<long long>(primes, primes+sizeof(primes)/sizeof(long long))); break;
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
