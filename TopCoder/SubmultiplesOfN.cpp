#line 2 "SubmultiplesOfN.cpp"
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
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define FOR(I, A, B) for (int I = (A); I <= (B); ++I)
#define FORS(I, S) for (int I = 0; S[I]; ++I)
#define RS(X) scanf("%s", (X))
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define GET_POS(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
#define CASET int ___T; scanf("%d", &___T); for(int cs=1;cs<=___T;cs++)
#define MP make_pair
#define PB emplace_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define F first
#define S second
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

#include <vector>
using namespace std;
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
            factorial.push_back(factorial.back() * (int)factorial.size());
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
            if (n == 0) return {1, 0};
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

using mint = Z;

class SubmultiplesOfN {
public:
    int count(string B, int N) {
	int M = SZ(B);
	vector<vector<mint>> prev(10, vector<mint>(N));
	vector<mint> dp(N);
	dp[0] = 1;
	prev[0] = dp;
	REP(j, SZ(B)) {
	    vector<mint> next(N);
	    int b = B[j] - '0';
	    REP(i, N) {
		next[i] += dp[i];
		next[(i * 10 + b) % N] += dp[i] - prev[b][i];
	    }
	    prev[b] = dp;
	    swap(next, dp);
	}
	return (dp[0] - 1).val();
    }
};

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
The number X appears in the number Y if, when written in base-10, the digits of X form a (not necessarily contiguous) subsequence of the digits of Y.
For example, X = 246 appears in Y = 1234567 and X = 222 appears in Y = 222.
On the other hand, the numbers 1223 and 31 do not appear in the number 123.



Given a string B containing the base-10 representation of a possibly very large positive integer, count all positive integer multiples of N that appear in B.
Return the count modulo 10^9 + 7.



DEFINITION
Class:SubmultiplesOfN
Method:count
Parameters:string, int
Returns:int
Method signature:int count(string B, int N)


CONSTRAINTS
-B will have between 1 and 5,000 characters, inclusive.
-Each character of B will be a digit.
-B will not start with a zero.
-N will be between 1 and 1,000, inclusive.


EXAMPLES

0)
"1111111111"
7

Returns: 1

The only positive integer multiple of 7 that appears in the given number is 111,111. Note that we are counting distinct numbers, not their appearances: even though 111,111 can be seen in B in many different ways, we only want to count it once.

1)
"12345678"
2

Returns: 170

Exactly 170 distinct even numbers appear in 12345678. Some of those numbers are 4, 1346 and 12345678.

2)
"1357913579135791357913579"
2

Returns: 0



3)
"1122334455"
6

Returns: 20

Four of these 20 numbers are 12, 114, 2244 and 1123344.

4)
"1020402"
24

Returns: 6

The six multiples of 24 that appear in 1020402 are 24, 120, 240, 1200, 2040, and 10200.

5)
"123456789012345678901234567890"
1

Returns: 62224120

Don't forget to calculate the answer modulo 10^9 + 7.

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
		cout << "Testing SubmultiplesOfN (450.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1620491672;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 450.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		SubmultiplesOfN _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string B = "1111111111";
				int N = 7;
				_expected = 1;
				_received = _obj.count(B, N); break;
			}
			case 1:
			{
				string B = "12345678";
				int N = 2;
				_expected = 170;
				_received = _obj.count(B, N); break;
			}
			case 2:
			{
				string B = "1357913579135791357913579";
				int N = 2;
				_expected = 0;
				_received = _obj.count(B, N); break;
			}
			case 3:
			{
				string B = "1122334455";
				int N = 6;
				_expected = 20;
				_received = _obj.count(B, N); break;
			}
			case 4:
			{
				string B = "1020402";
				int N = 24;
				_expected = 6;
				_received = _obj.count(B, N); break;
			}
			case 5:
			{
				string B = "123456789012345678901234567890";
				int N = 1;
				_expected = 62224120;
				_received = _obj.count(B, N); break;
			}
			/*case 6:
			{
				string B = ;
				int N = ;
				_expected = ;
				_received = _obj.count(B, N); break;
			}*/
			/*case 7:
			{
				string B = ;
				int N = ;
				_expected = ;
				_received = _obj.count(B, N); break;
			}*/
			/*case 8:
			{
				string B = ;
				int N = ;
				_expected = ;
				_received = _obj.count(B, N); break;
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
