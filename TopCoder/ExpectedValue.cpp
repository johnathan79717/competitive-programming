#line 2 "ExpectedValue.cpp"
#include <string>
#include <vector>
#include <climits>
#include <cstring>
#include <map>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <cassert>
#include <deque>
#include <stack>
#include <functional>
#define SZ(X) ((int)(X).size())
#define FOR(I, A, B) for (int I = (A); I <= (B); ++I)
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII> VPII;
typedef pair<LL,LL> PLL;
typedef vector<PLL> VPLL;
int MOD = 1e9+7;
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}
template<class Short, class Long>
struct ZZ {
    static Short MOD;
    Short i;
    ZZ():i(0) {}
    ZZ(Short _i): i(_i >= 0 ? _i : _i + MOD) {}
    ZZ(Long _i): i(_i % MOD >= 0 ? _i % MOD : _i % MOD + MOD) {}
    Short val() { return i; }
    static ZZ raw(Short _i) { return ZZ(_i); }
    void operator +=(const ZZ& z) { i += z.i; if(i >= MOD) i -= MOD; }
    void operator -=(const ZZ& z) { i -= z.i; if(i < 0) i += MOD; }
    void operator *=(const ZZ& z) { i = (Long) i * z.i % MOD; }
    void operator /=(const ZZ& z) { (*this) *= z.inverse(); }
    ZZ operator +(const ZZ& z) const { ZZ ret(i); ret += z; return ret; }
    ZZ operator -(const ZZ& z) const { ZZ ret(i); ret -= z; return ret; }
    ZZ operator *(const ZZ& z) const { ZZ ret(i); ret *= z; return ret; }
    ZZ operator /(const ZZ& z) const { return (*this) * z.inverse(); }
    // ZZ operator -() const { return ZZ(-i); }
    ZZ inverse() const {
        return pow(MOD - 2);
    }
    ZZ pow(long long b) const {
        ZZ x=Short(1),y=*this;
        while(b > 0){
            if(b%2 == 1)
                x *= y;
            y *= y; // squaring the base
            b /= 2;
        }
        return x;
    }
    
    static vector<ZZ> factorial, inv_factorial;

    static ZZ fact(int n) {
        while(factorial.size() <= n)
            factorial.push_back(factorial.back() * SZ(factorial));
        return factorial.at(n);
    }

    static ZZ inv_fact(int n) {
        if (n < inv_factorial.size())
            return inv_factorial.at(n);
        int old_size = inv_factorial.size();
        inv_factorial.resize(n+1);
        inv_factorial.at(n) = fact(n).inverse();
        for (int i = n-1; i >= old_size; i--) {
            inv_factorial[i] = inv_factorial.at(i+1) * (i+1);
        }
        return inv_factorial.at(n);
    }
};
typedef ZZ<int, long long> Z;
template<> int Z::MOD = 1000000007;
template<> vector<Z> Z::factorial(1, 1);
template<> vector<Z> Z::inv_factorial(1, 1);

class ExpectedValue {
public:
    int solve(int N) {
	vector<Z> dp(N+1), dr(N+1);
	dp[0] = 0;
	dr[0] = 1;
	//FOR(i, 1, N) {
	    //FOR(j, 2, i) {
		//dp[i] += (Z::fact(i-1) * Z::inv_fact(i-j)) * (dp[i-j] + dr[i-j] * (j-1));
		//dr[i] += (Z::fact(i-1) * Z::inv_fact(i-j)) * dr[i-j];
	    //}
	//}
	//return (dp[N] / dr[N]).i;
	FOR(n, 1, N) {
	    dr[n] = dr[n-1] * n + (n % 2 ? -1 : 1);
	}
	Z ans = 0;
	FOR(L, 2, N) {
	    ans += Z::fact(N-1) * Z::inv_fact(N - L) * dr[N - L] * N / L;
	}
	return (Z(N) - ans / dr[N]).i;
    }
};

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
A derangement of the set {1, 2, 3, ..., N} is its permutation with no fixed points, i.e., a permutation P such that for all i, P[i] != i.


For example, the set {1, 2, 3} has two derangements: {2, 3, 1} and {3, 1, 2}.



Given is the int N.
A bag contains all derangements of the set {1, 2, 3, ..., N}.
One derangement is selected from the bag uniformly at random.



Let the selected derangement be P.
We can now view P as a sequence of integers and ask the question: what is the minimum number f(P) of swaps we need to make in order to sort P into ascending order?


For example, the optimum solution for P = {4, 3, 2, 1} involves two swaps: e.g., swap 2 and 3, and then swap 1 and 4.


The optimum solution for P = {2, 3, 4, 1} requires three swaps: e.g., swap 1 with 2 (producing {1, 3, 4, 2}), then 2 with 4, and finally 3 with 2.



Let M = 109 + 7.
The expected value of f(P) is a rational number.
When written as a reduced fraction f(P) = X/Y, Y and M are relatively prime.
Return (X * Y-1) modulo M.


DEFINITION
Class:ExpectedValue
Method:solve
Parameters:int
Returns:int
Method signature:int solve(int N)


CONSTRAINTS
-N will be between 2 and 1500, inclusive.


EXAMPLES

0)
2

Returns: 1

The only derangement in the bag is P = {2, 1}. We need one swap to sort it, so f(P) = 1. Thus, the expected value of f(P) is 1.

1)
3

Returns: 2

As mentioned in the statement, the two derangements in the bag are {2, 3, 1} and {3, 1, 2}. Each of them requires 2 swaps.

2)
4

Returns: 666666674


There are 9 derangements for N = 4. Three of them have f(P) = 2, the other six have f(P) = 3. Thus, the expected value of f(P) is (3*2 + 6*3) / 9 = 24/9 = 8/3.


Computing modulo M = 1,000,000,007 we have 3-1 = 333,333,336, and (8 * 333,333,336) modulo M = 666,666,674.



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
		cout << "Testing ExpectedValue (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1611422366;
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
		ExpectedValue _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 2;
				_expected = 1;
				_received = _obj.solve(N); break;
			}
			case 1:
			{
				int N = 3;
				_expected = 2;
				_received = _obj.solve(N); break;
			}
			case 2:
			{
				int N = 4;
				_expected = 666666674;
				_received = _obj.solve(N); break;
			}
			/*case 3:
			{
				int N = ;
				_expected = ;
				_received = _obj.solve(N); break;
			}*/
			/*case 4:
			{
				int N = ;
				_expected = ;
				_received = _obj.solve(N); break;
			}*/
			/*case 5:
			{
				int N = ;
				_expected = ;
				_received = _obj.solve(N); break;
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