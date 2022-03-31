#line 2 "AnnoyingPasswords.cpp"
#include <array>
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


class AnnoyingPasswords {
public:
    int count(int U, int L, int D) {
	if (!U && !L && !D) return 1;
	vector<vector<vector<Z>>> u(U+1, vector<vector<Z>>(L+1, vector<Z>(D+1)));
	vector<vector<vector<Z>>> l(U+1, vector<vector<Z>>(L+1, vector<Z>(D+1)));
	vector<vector<vector<Z>>> d(U+1, vector<vector<Z>>(L+1, vector<Z>(D+1)));
	if (U) u[1][0][0] = 26;
	if (L) l[0][1][0] = 26;
	if (D) d[0][0][1] = 10;
	FOR(i, 0, U) {
	    FOR(j, 0, L) {
		FOR(k, 0, D) {
		    if (i + j + k == 1) continue;
		    if (i) {
			u[i][j][k] = (l[i-1][j][k] + d[i-1][j][k]) * (27 - i);
		    }
		    if (j) {
			l[i][j][k] = (u[i][j-1][k] + d[i][j-1][k]) * (27 - j);
		    }
		    if (k) {
			d[i][j][k] = (l[i][j][k-1] + u[i][j][k-1]) * (11 - k);
		    }
		}
	    }
	}
	return (u[U][L][D] + l[U][L][D] + d[U][L][D]).i;
    }
};

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
Many websites force their users to select passwords that satisfy various annoying constraints.
This is not only annoying but also dumb, as it often makes the passwords less secure: users who cannot remember their password are prone to storing it in an insecure way.


The authors of these annoying systems often claim that they do it to increase the space of possible passwords.
In this problem we will look at this claim and count some annoying passwords.



An annoying password has the following properties:


It contains exactly U uppercase letters ('A'-'Z').
It contains exactly L lowercase letters ('a'-'z').
It contains exactly D digits ('0'-'9').
It does not contain any other characters.
No two characters of the same type (uppercase, lowercase, digits) are adjacent.
All characters in the password are distinct.


Given U, L and D, count all annoying passwords and return their count modulo 10^9 + 7.



DEFINITION
Class:AnnoyingPasswords
Method:count
Parameters:int, int, int
Returns:int
Method signature:int count(int U, int L, int D)


NOTES
-There are 26 different letters (both in uppercase and in lowercase), and there are 10 different digits.


CONSTRAINTS
-U will be between 0 and 26, inclusive.
-L will be between 0 and 26, inclusive.
-D will be between 0 and 10, inclusive.


EXAMPLES

0)
4
1
1

Returns: 0


The password should contain 4 uppercase letters, 1 lowercase letter and 1 digit.


There are no such annoying passwords: regardless of what order of characters we'll choose, there will always be two consecutive uppercase letters somewhere in the password, and that's not allowed.



1)
5
0
4

Returns: 783743727

The uppercase letters and digits must alternate. For example, "A1B2C3D4Z" is a valid annoying password. There are exactly 39,783,744,000 annoying passwords, the return value is the remainder this number gives when divided by 10^9 + 7.

2)
1
1
1

Returns: 40560

Here, the answer is the exact number of annoying passwords (as it is smaller than 10^9 + 7).

3)
2
2
3

Returns: 559599923

Some annoying passwords of this type include "a1b2C3D" and "7gG4Pp2".

4)
0
0
0

Returns: 1

There is exactly one empty password. By definition, it is annoying.

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
		cout << "Testing AnnoyingPasswords (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1625742304;
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
		AnnoyingPasswords _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int U = 4;
				int L = 1;
				int D = 1;
				_expected = 0;
				_received = _obj.count(U, L, D); break;
			}
			case 1:
			{
				int U = 5;
				int L = 0;
				int D = 4;
				_expected = 783743727;
				_received = _obj.count(U, L, D); break;
			}
			case 2:
			{
				int U = 1;
				int L = 1;
				int D = 1;
				_expected = 40560;
				_received = _obj.count(U, L, D); break;
			}
			case 3:
			{
				int U = 2;
				int L = 2;
				int D = 3;
				_expected = 559599923;
				_received = _obj.count(U, L, D); break;
			}
			case 4:
			{
				int U = 0;
				int L = 0;
				int D = 0;
				_expected = 1;
				_received = _obj.count(U, L, D); break;
			}
			/*case 5:
			{
				int U = ;
				int L = ;
				int D = ;
				_expected = ;
				_received = _obj.count(U, L, D); break;
			}*/
			/*case 6:
			{
				int U = ;
				int L = ;
				int D = ;
				_expected = ;
				_received = _obj.count(U, L, D); break;
			}*/
			/*case 7:
			{
				int U = ;
				int L = ;
				int D = ;
				_expected = ;
				_received = _obj.count(U, L, D); break;
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
