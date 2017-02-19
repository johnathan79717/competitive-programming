#include <cassert>
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
#define MAX(x, a) x = max(x, a)
#define MIN(x, a) x = min(x, a)
 
typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;
#define PZ(x) PI((x).i);

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


#include <string>
#include <vector>

struct S {
  int s[3001];
  int c;

  S() : c(0) {
    MS0(s);
  }

  void clear() {
    MS0(s);
    c = 0;
  }

  void inc(int i) {
    if (s[i]++ == 0) {
      c++;
    }
  }

  void dec(int i) {
    if (--s[i] == 0) {
      c--;
    }
  }

  bool operator[](int i) const {
    return !!s[i];
  }
};

S s1, s2, s3, s12, s23, s13, s123;

class MappingABC {
public:
  int countStrings(vector <int> t) {
    int N = t.size();
    s1.clear();
    Z ans = 0;
    for (int i = 0; i < N; i++) {
      s3.clear();
      s13.clear();
      s2.clear();
      s12.clear();
      s23.clear();
      s123.clear();
      for (int k = i+1; k < N; k++) {
        s3.inc(t[k]);
        if (s1[t[k]] && s3[t[k]]) {
          s13.inc(t[k]);
        }
      }
      for (int j = i+1; j < N; j++) {
        s3.dec(t[j]);
        if (s1[t[j]]) {
          s13.dec(t[j]);
        }
        if (s2[t[j]]) {
          s23.dec(t[j]);
        }
        if (s12[t[j]]) {
          s123.dec(t[j]);
        }

        //fprintf(stderr, "%d %d\n", i, j);
        //fprintf(stderr, "%d %d %d %d %d %d %d\n", s1.c, s2.c, s3.c, s12.c, s13.c, s23.c, s123.c);
        if (t[i] != t[j] && !s1[t[i]] && !s3[t[j]]) {
          int c123 = s123.c - s123[t[i]] - s123[t[j]];
          int c1 = s1.c - s1[t[i]] - s1[t[j]];
          int c2 = s2.c - s2[t[i]] - s2[t[j]];
          int c3 = s3.c - s3[t[i]] - s3[t[j]];
          int c12 = s12.c - s12[t[i]] - s12[t[j]];
          int c13 = s13.c - s13[t[i]] - s13[t[j]];
          int c23 = s23.c - s23[t[i]] - s23[t[j]];
          c12 -= c123;
          c13 -= c123;
          c23 -= c123;
          c1 -= c12 + c13;
          c2 -= c23 + c12;
          c3 -= c13 + c23;
          ans += Z(2).pow(c1 + c3 + c12 + c23) * Z(3).pow(c2) - Z(2).pow(c1 + c3 + c2);
          //fprintf(stderr, "%d %d %d %d %d %d %d %d\n", c1, c2, c3, c12, c13, c23, c123, ans.i);
        }

        s2.inc(t[j]);
        if (s3[t[j]]) {
          s23.inc(t[j]);
        }
        if (s1[t[j]]) {
          s12.inc(t[j]);
        }
        if (s13[t[j]]) {
          s123.inc(t[j]);
        }
      }
      s1.inc(t[i]);
    }
    return ans.i;
  }
};

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// The lotteries you know are probably quite boring.
You just buy a lottery ticket with some numbers and then you hope that the organizers announce the same set of numbers.
As you will discover below, the lottery in Bearland is way more fun!

In the Bearland lottery, you win if you have a ticket that matches the goal string.
The goal string is a string of length N chosen by the organizers.
Each character of the string will be 'A', 'B', or 'C'.
Additionally, it is guaranteed that the goal string will contain "ABC" as a subsequence.
For example, "AABAC" and "BBABC" are two possible goal strings of length 5, but "CBAAA" is not a goal string.

However, the lottery tickets do not contain any strings at all.
Instead, each Bearland lottery ticket contains some sequence of N (not necessarily distinct) integers.

You win the lottery if you can transform your sequence into the goal string.
Transformation rules:

Each element of the sequence should be replaced by a single character: 'A', 'B', or 'C'.
All occurrences of the same number must be replaced by the same letter.


For example, the sequence {5, 8, 5, 2} can be transformed into "ABAC" or "BABB" but not into "ABBB".

Limak got a lottery ticket for his birthday.
You are given the vector <int> t: the sequence of the N numbers on the the ticket.
Count the number of different goal strings for which Limak can win the lottery.
Return that count modulo 10^9+7.

DEFINITION
Class:MappingABC
Method:countStrings
Parameters:vector <int>
Returns:int
Method signature:int countStrings(vector <int> t)


CONSTRAINTS
-t will have exactly N elements.
-N will be between 3 and 3000, inclusive.
-Each element in t will be between 1 and 3000, inclusive.


EXAMPLES

0)
{9,9,2,9,4}

Returns: 2

Limak can transform this lottery ticket into 27 different strings.
Some of them are: AAAAA, AAAAB, AAAAC, AABAA, AACAA, AABAB, AABAC, AACAB, AACAC, BBABA, BBABB, ... 
Among them, only two strings are valid goal strings: AABAC and BBABC.
Thus, the answer is 2.

1)
{1,2,3}

Returns: 1



2)
{1,2,2,1,2,1,2}

Returns: 0



3)
{7,3000,1,3000,1,3000,1,10,7}

Returns: 20



4)
{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,
26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48}

Returns: 166952139



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
		cout << "Testing MappingABC (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1485015057;
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
		MappingABC _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int t[] = {9,9,2,9,4};
				_expected = 2;
				_received = _obj.countStrings(vector <int>(t, t+sizeof(t)/sizeof(int))); break;
			}
			case 1:
			{
				int t[] = {1,2,3};
				_expected = 1;
				_received = _obj.countStrings(vector <int>(t, t+sizeof(t)/sizeof(int))); break;
			}
			case 2:
			{
				int t[] = {1,2,2,1,2,1,2};
				_expected = 0;
				_received = _obj.countStrings(vector <int>(t, t+sizeof(t)/sizeof(int))); break;
			}
			case 3:
			{
				int t[] = {7,3000,1,3000,1,3000,1,10,7};
				_expected = 20;
				_received = _obj.countStrings(vector <int>(t, t+sizeof(t)/sizeof(int))); break;
			}
			case 4:
			{
				int t[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,
				          26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48};
				_expected = 166952139;
				_received = _obj.countStrings(vector <int>(t, t+sizeof(t)/sizeof(int))); break;
			}
			/*case 5:
			{
				int t[] = ;
				_expected = ;
				_received = _obj.countStrings(vector <int>(t, t+sizeof(t)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int t[] = ;
				_expected = ;
				_received = _obj.countStrings(vector <int>(t, t+sizeof(t)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int t[] = ;
				_expected = ;
				_received = _obj.countStrings(vector <int>(t, t+sizeof(t)/sizeof(int))); break;
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
