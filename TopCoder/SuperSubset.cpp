#line 2 "SuperSubset.cpp"
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
#define MP make_pair
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
#define PZ(x) PI((x).i);

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

    static ZZ choose0(int n, int k) {
        assert(n < 1e7);
        if(n < k) return 0;
        return fact(n) * (inv_fact(k) * inv_fact(n-k));
    }

    static ZZ choose1(int n, int k) {
        assert(k < 1e7);
        if (n < k) return 0;
        if (k == 0) return 1;
        return choose1(n-1, k-1) * n / k;
    }

    static pair<ZZ,int> factModExp(int n) {
            if (n == 0) return MP(1, 0);
            int e = n / MOD;
            pair<ZZ,int> pr = factModExp(e);
            if (e % 2) {
                    return MP(ZZ(0) - pr.first * fact(n % MOD), pr.second + e);
            } else {
                    return MP(pr.first * fact(n % MOD), pr.second + e);
            }
    }

    static ZZ choose2(int n, int k) {
        assert(MOD < 1e7);
        pair<ZZ,int> p1 = factModExp(n), p2 = factModExp(k), p3 = factModExp(n-k);
        if (p1.second > p2.second + p3.second) return 0;
        assert(p1.second == p2.second + p3.second);
        return p1.first / (p2.first * p3.first);
    }
};

typedef ZZ<int, long long> Z;
template<> int Z::MOD = 1000000007;
template<> vector<Z> Z::factorial(1, 1);
template<> vector<Z> Z::inv_factorial(1, 1);

long long mul(long long a,long long b,long long mod=Z::MOD){
  long long x = 0,y=a%mod;
  while(b > 0){
    if(b%2 == 1){
      x = x+y;
      if(x >= mod) x -= mod;
    }
    y = y*2;
    if(y >= mod) y -= mod;
    b /= 2;
  }
  return x%mod;
}

long long pow(long long a, long long b, long long c=Z::MOD){
  long long x=1,y=a; // ll is taken to avoid overflow of intermediate results
  while(b > 0){
    if(b%2 == 1){
      x=mul(x, y, c);
    }
    y = mul(y, y, c); // squaring the base
    b /= 2;
  }
  return x%c;
}

void _W(Z x) { printf("%d", x.i);  }


class SuperSubset {
public:
    int solve(vector <int> A, int Y) {
	vector<Z> dp(Y+1);
	dp[0] = 1;
	for (int a : A) {
	    for (int i = Y; i >= 0; i--) {
		dp[i] *= 2;
		if (i >= a) {
		    dp[i] += dp[i-a];
		}
	    }
	}
	return dp[Y].i;
    }
};

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
You're given a sequence A of N positive integers and a positive integer Y.



Let S be any subset of the set {0, 1, 2, 3, ..., N-1}.
The weight of S, denoted w(S), is defined as the number of subsets {x1, x2, ..., xk} of S such that 
A[x1] + A[x2] + ... + A[xk] = Y.



For example, suppose A = {1, 10, 40, 70, 71, 100, 111, 200} and Y = 111.

For the set S1 = {0, 1, 2, 3, 4, 5} we have w(S1) = 3 because of the three subsets {0, 1, 5}, {0, 2, 3}, and {2, 4}:


A[0] + A[1] + A[5] = 1 + 10 + 100 = 111,
A[0] + A[2] + A[3] = 1 + 40 + 70 = 111, and
A[2] + A[4] = 40 + 71 = 111.


For the set S2 = {2, 5, 6, 7} we have w(S2) = 1 because the only subset of S2 with the required property is {6}, with A[6] = 111.



Find the sum of w(S) over all subsets of the sequence {0, 1, 2, 3, ..., N-1}.
Return this sum modulo 109+7.


DEFINITION
Class:SuperSubset
Method:solve
Parameters:vector <int>, int
Returns:int
Method signature:int solve(vector <int> A, int Y)


CONSTRAINTS
-A will have between 1 and 3000 elements, both inclusive.
-A[i] will have between 1 and 9999, both inclusive.
-Y will be between 1 and 9999, inclusive.


EXAMPLES

0)
{1, 2, 3}
3

Returns: 6

w( { } ) = 0 
w( { 1 } ) = 0 
w( { 2 } ) = 0 
w( { 3 } ) = 1 
w( { 1, 2 } ) = 1 
w( { 1, 3 } ) = 1 
w( { 2, 3 } ) = 1 
w( { 1, 2, 3 } ) = 2 

1)
{1, 1, 1, 1, 1}
4

Returns: 10

Each of the five 4-element sets of indices has weight 1 and the only 5-element set of indices has weight 5.

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
		cout << "Testing SuperSubset (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1611421503;
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
		SuperSubset _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int A[] = {1, 2, 3};
				int Y = 3;
				_expected = 6;
				_received = _obj.solve(vector <int>(A, A+sizeof(A)/sizeof(int)), Y); break;
			}
			case 1:
			{
				int A[] = {1, 1, 1, 1, 1};
				int Y = 4;
				_expected = 10;
				_received = _obj.solve(vector <int>(A, A+sizeof(A)/sizeof(int)), Y); break;
			}
			/*case 2:
			{
				int A[] = ;
				int Y = ;
				_expected = ;
				_received = _obj.solve(vector <int>(A, A+sizeof(A)/sizeof(int)), Y); break;
			}*/
			/*case 3:
			{
				int A[] = ;
				int Y = ;
				_expected = ;
				_received = _obj.solve(vector <int>(A, A+sizeof(A)/sizeof(int)), Y); break;
			}*/
			/*case 4:
			{
				int A[] = ;
				int Y = ;
				_expected = ;
				_received = _obj.solve(vector <int>(A, A+sizeof(A)/sizeof(int)), Y); break;
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
