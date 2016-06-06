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
template<class Short, class Long>
struct ZZ {
    static Short MOD;
    Short i;
    ZZ():i(0) {}
    ZZ(Short _i): i(_i >= 0 ? _i : _i + MOD) {}
    ZZ(Long _i): i(_i % MOD) {}
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
};
typedef ZZ<int, long long> Z;
template<> int Z::MOD = 1000000007;

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;
// #line 40 "TriangleTriples.cpp"
#include <string>
#include <vector>
class TriangleTriples {
public:
    Z solve(int a, int b, int c) {
        a = min(a, c);
        b = min(b, c);
        Z A = a, B = b, C = c;
        if (a + b < c) {
            return A * B * (C+1) - A*(A+1)/2*B - B*(B+1)/2*A;
        } else {
            Z x = A + B - C;
            return (C-B)*((C+1)*B-B*(B+1)/2) - B*(C-B)*(C-B+1)/2 + (B*(B+1)*x-(B*2+1)*x*(x+1)/2+x*(x+1)*(x*2+1)/6)/2;
        }
    }

    int count(int A, int B, int C) {
        cout << solve(A, B, C).i << ' ' << solve(B, C, A).i << ' ' << solve(C, A, B).i << endl;
        return (Z(A) * B * C - solve(A, B, C) - solve(B, C, A) - solve(C, A, B)).i;
    }
};
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// An ordered triple (a, b, c) is called a triangle triple if a, b, c are positive integers such that there is a triangle with side lengths a, b, c and a positive area.

For example, (4, 5, 6) and (5, 4, 6) are two different triangle triples.
On the other hand, (1, 2, 3) and (47, 5, 5) are not triangle triples.

You are given the ints A, B, and C.
Let X be the number of triangle triples (a, b, c) such that 1 <= a <= A, 1 <= b <= B, and 1 <= c <= C.
Compute and return the value (X modulo 1,000,000,007).

DEFINITION
Class:TriangleTriples
Method:count
Parameters:int, int, int
Returns:int
Method signature:int count(int A, int B, int C)


CONSTRAINTS
-A will be between 1 and 1,000,000,000, inclusive.
-B will be between 1 and 1,000,000,000, inclusive.
-C will be between 1 and 1,000,000,000, inclusive.


EXAMPLES

0)
1
10
20

Returns: 10

We have 10 such triples: (1,1,1), (1,2,2), (1,3,3), ..., (1,10,10).

1)
2
2
1000000000

Returns: 6

This time we have: (1,1,1), (1,2,2), (2,1,2), (2,2,1), (2,2,2) and (2,2,3).

2)
10
10
10

Returns: 505



3)
1
1
1

Returns: 1



4)
123456789
987654321
555555555

Returns: 64296241



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
		cout << "Testing TriangleTriples (300.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1464262443;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 300.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		TriangleTriples _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int A = 1;
				int B = 10;
				int C = 20;
				_expected = 10;
				_received = _obj.count(A, B, C); break;
			}
			case 1:
			{
				int A = 2;
				int B = 2;
				int C = 1000000000;
				_expected = 6;
				_received = _obj.count(A, B, C); break;
			}
			case 2:
			{
				int A = 10;
				int B = 10;
				int C = 10;
				_expected = 505;
				_received = _obj.count(A, B, C); break;
			}
			case 3:
			{
				int A = 1;
				int B = 1;
				int C = 1;
				_expected = 1;
				_received = _obj.count(A, B, C); break;
			}
			case 4:
			{
				int A = 123456789;
				int B = 987654321;
				int C = 555555555;
				_expected = 64296241;
				_received = _obj.count(A, B, C); break;
			}
			/*case 5:
			{
				int A = ;
				int B = ;
				int C = ;
				_expected = ;
				_received = _obj.count(A, B, C); break;
			}*/
			/*case 6:
			{
				int A = ;
				int B = ;
				int C = ;
				_expected = ;
				_received = _obj.count(A, B, C); break;
			}*/
			/*case 7:
			{
				int A = ;
				int B = ;
				int C = ;
				_expected = ;
				_received = _obj.count(A, B, C); break;
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
