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
#define SZ(x) (int)((x).size())
 
typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;

int MOD = 1000000007;
LL mul(LL a,LL b,LL mod=MOD){
  LL x = 0,y=a%mod;
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

LL pow(LL a, LL b, LL c=MOD){
  LL x=1,y=a; // ll is taken to avoid overflow of intermediate results
  while(b > 0){
    if(b%2 == 1){
      x=mul(x, y, c);
    }
    y = mul(y, y, c); // squaring the base
    b /= 2;
  }
  return x%c;
}

#define PZ(x) PI((x).i);

const int MAX = 4005;
template<class Short, class Long>
struct ZZ {
    static Short MOD;
    Short i;
    ZZ():i(0) {}
    ZZ(Short i): i(i >= 0 ? i : i + MOD) {}
    ZZ(Long i): i(i % MOD) {}
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

    static ZZ choose(int n, int k) {
        if(n < k) return 0;
        return fact(n) * (inv_fact(k) * inv_fact(n-k));
    }

    static pair<ZZ,int> factModExp(int n) {
            if (n == 0) return MP(1, 0);
            int e = n / MOD;
            pair<ZZ,int> pr = factModExp(e);
            if (e % 2) {
                    return MP(ZZ(0) - pr.F * fact(n % MOD), pr.S + e);
            } else {
                    return MP(pr.F * fact(n % MOD), pr.S + e);
            }
    }

    static ZZ choose2(int n, int k) {
        pair<ZZ,int> p1 = factModExp(n), p2 = factModExp(k), p3 = factModExp(n-k);
        if (p1.S > p2.S + p3.S) return 0;
        assert(p1.S == p2.S + p3.S);
        return p1.F / (p2.F * p3.F);
    }

    static ZZ choose3(int n, int k) {
        static bool first = true;
        if (first) {
            REP(i, MAX) {
                C[i][0] = 1;
                REP1(j, 1, i) {
                    C[i][j] = C[i-1][j] + C[i-1][j-1];
                }
            }
            first = false;
        }
        return C[n][k];
    } 

    static ZZ C[MAX][MAX];
};

typedef ZZ<int, LL> Z;
template<> int Z::MOD = 1000000007;
template<> vector<Z> Z::factorial(1, 1);
template<> vector<Z> Z::inv_factorial(1, 1);
template<> Z Z::C[MAX][MAX] = {};

list<int> adj[1000001];

Z ed[1000001], e[1000001];
Z ans;

void dfs(int v, int p) {
	Z den = Z(v+1).inverse();
	if (p < 0) {
		ans = 1;
		e[v] = 1;
	} else {
		ans = (ans * v + ans + 1 + e[p] * 2) * den;
		e[v] = (e[p] + 1) * den;
	}
	ed[v] = den;
	for (int u: adj[v]) {
		if (u != p) {
			dfs(u, v);
			ed[v] += ed[u] * den;
			e[v] += ed[u] * den;
		}
	}
}

class BearAttacks {
	public:
	int expectedValue(int N, int R0, int A, int B, int M, int LOW, int HIGH) {
		LL R = R0;
		int BILLION = 1000000000;
		// adj = V(list<int>)(N);
		REP1(i, 1, N-1) {
			R = (A * R + B) % M;
			int MIN = (LL(i-1) * LOW) / BILLION;
			int MAX = (LL(i-1) * HIGH) / BILLION;
			int j = MIN + (R % (MAX - MIN + 1));
			adj[i].PB(j);
			adj[j].PB(i);
			// cout << i << ' ' << j << endl;
		}
		dfs(0, -1);
		ans *= Z::fact(N);
		return ans.i;
	}
};
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Limak is a grizzly bear.
He is currently making plans to attack Deerland.

Deerland has N cities, numbered from 0 to N-1.
The cities are all connected together by a network of roads.
There are exactly N-1 bidirectional roads, each connecting two cities.
(Hence, the topology of Deerland is a tree.)

Limak will attack each city in Deerland exactly once.
For each i, when he attacks city i, there are two possible outcomes:

With probability 1/(i+1) the city will defend itself successfully.
In all other cases the city is destroyed by Limak. The city disappears from Deerland, along with all roads that led into the city.


Let's define a region as a connected component of Deerland.
In other words, a region is a maximal group of cities such that the existing roads allow us to travel between any two cities in the group.
Initially, the entire Deerland is a single region.
After Limak's N attacks Deerland will be divided into one or more regions.

The strength of a region is the square of the number of cities it contains.

You are given a description of Deerland in a format that is specified below.
Let E be the expected value of the sum of strengths of all regions after Limak attacks Deerland.
It can be proved that E*N! is an integer.
Return this integer modulo 1,000,000,007.

The description of Deerland is provided in the form of a pseudorandom generator.
You are given the ints N, R0, A, B, M, LOW, and HIGH.
As defined above, N is the number of cities in Deerland.
The list of roads is generated by the pseudocode below.


R = R0;
BILLION = 1000000000;
for i between 1 and N-1, inclusive:
    R = (A * R + B) modulo M;
    MIN = ((i-1) * LOW)  / BILLION;
    MAX = ((i-1) * HIGH) / BILLION;
    there is a road between city i and city MIN + (R modulo (MAX-MIN+1));


Both divisions in the pseudocode are integer divisions.
(Integer division rounds down. For example, 29/10 is 2.)
You may assume that the pseudocode always generates a valid tree.
Watch out for integer overflow when implementing it.

DEFINITION
Class:BearAttacks
Method:expectedValue
Parameters:int, int, int, int, int, int, int
Returns:int
Method signature:int expectedValue(int N, int R0, int A, int B, int M, int LOW, int HIGH)


CONSTRAINTS
-N will be between 1 and 1,000,000, inclusive.
-M will be between 1 and 1,000,000,000, inclusive.
-R0, A and B will be between 0 and M-1, inclusive.
-LOW and HIGH will be between 0 and 1,000,000,000, inclusive.
-LOW will not be greater than HIGH.


EXAMPLES

0)
3
0
2
3
100
938593850
1000000000

Returns: 21

There are N=3 cities.
The generator outputs that the two roads are 1-0 and 2-1.
Hence, Deerland is the path 0-1-2.
Here is what may happen:

With probability (1/1) * (1/2) * (1/3) = 1/6 all three cities survive. In this case we have a single region with strength 9.
With probability (1/1) * (1/2) * (2/3) = 2/6 only cities 0 and 1 survive. We have one region with strength 4.
With probability (1/1) * (1/2) * (1/3) = 1/6 only cities 0 and 2 survive. Here we have two regions, each with strength 1, hence the total strength is 2.
With probability (1/1) * (1/2) * (2/3) = 2/6 only city 0 survives. There is only one region and its strength is 1.

Therefore, the expected sum of regions' strengths is (1/6)*9 + (2/6)*4 + (1/6)*2 + (2/6)*1 = 21/6.
The correct return value is ( (21/6) * N! ) modulo 1,000,000,007, which is 21.

1)
3
0
0
0
1
0
0

Returns: 23

Again there are three cities, but now the roads are 1-0 and 2-0.
A different set of roads leads to a different answer.

2)
6
303840291
848660283
395739574
950123456
0
1000000000

Returns: 3856

Six cities. Roads: 1-0, 2-1, 3-1, 4-3, 5-1.

3)
1
0
0
0
1
0
0

Returns: 1



4)
19
384038999
938592393
692854433
1000000000
300000000
600000000

Returns: 473263988



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
		cout << "Testing BearAttacks (550.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1438445839;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 550.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		BearAttacks _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 3;
				int R0 = 0;
				int A = 2;
				int B = 3;
				int M = 100;
				int LOW = 938593850;
				int HIGH = 1000000000;
				_expected = 21;
				_received = _obj.expectedValue(N, R0, A, B, M, LOW, HIGH); break;
			}
			case 1:
			{
				int N = 3;
				int R0 = 0;
				int A = 0;
				int B = 0;
				int M = 1;
				int LOW = 0;
				int HIGH = 0;
				_expected = 23;
				_received = _obj.expectedValue(N, R0, A, B, M, LOW, HIGH); break;
			}
			case 2:
			{
				int N = 6;
				int R0 = 303840291;
				int A = 848660283;
				int B = 395739574;
				int M = 950123456;
				int LOW = 0;
				int HIGH = 1000000000;
				_expected = 3856;
				_received = _obj.expectedValue(N, R0, A, B, M, LOW, HIGH); break;
			}
			case 3:
			{
				int N = 1;
				int R0 = 0;
				int A = 0;
				int B = 0;
				int M = 1;
				int LOW = 0;
				int HIGH = 0;
				_expected = 1;
				_received = _obj.expectedValue(N, R0, A, B, M, LOW, HIGH); break;
			}
			case 4:
			{
				int N = 19;
				int R0 = 384038999;
				int A = 938592393;
				int B = 692854433;
				int M = 1000000000;
				int LOW = 300000000;
				int HIGH = 600000000;
				_expected = 473263988;
				_received = _obj.expectedValue(N, R0, A, B, M, LOW, HIGH); break;
			}
			/*case 5:
			{
				int N = ;
				int R0 = ;
				int A = ;
				int B = ;
				int M = ;
				int LOW = ;
				int HIGH = ;
				_expected = ;
				_received = _obj.expectedValue(N, R0, A, B, M, LOW, HIGH); break;
			}*/
			/*case 6:
			{
				int N = ;
				int R0 = ;
				int A = ;
				int B = ;
				int M = ;
				int LOW = ;
				int HIGH = ;
				_expected = ;
				_received = _obj.expectedValue(N, R0, A, B, M, LOW, HIGH); break;
			}*/
			/*case 7:
			{
				int N = ;
				int R0 = ;
				int A = ;
				int B = ;
				int M = ;
				int LOW = ;
				int HIGH = ;
				_expected = ;
				_received = _obj.expectedValue(N, R0, A, B, M, LOW, HIGH); break;
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
