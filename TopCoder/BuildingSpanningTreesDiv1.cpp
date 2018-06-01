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

#line 40 "BuildingSpanningTreesDiv1.cpp"
#include <string>
#include <vector>

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
template<> int Z::MOD = 987654323;
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
class DisjointSet {
    VI par, _size;
    int N;

    void init() {
        for(int i = 0; i < N; i++) {
            par[i] = i;
            _size[i] = 1;
        }
    }

public:
    DisjointSet(int _N): par(_N), _size(_N), N(_N) {
        init();
    }

    int find(int x) {
        if(par[x] == x) return x;
        else return par[x] = find(par[x]);
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if(x == y) return;
        if(_size[x] < _size[y]) {
            par[x] = y;
            _size[y] += _size[x];
        } else {
            par[y] = x;
            _size[x] += _size[y];
        }
    }

    int size(int x) {
        return _size[find(x)];
    }
};

Z dp[1005][1005];

class BuildingSpanningTreesDiv1 {
public:
  int getNumberOfSpanningTrees(int n, vector <int> x, vector <int> y) {
    DisjointSet ds(n+1);
    REP(i, (int)x.size()) {
      ds.unite(x[i], y[i]);
    }
    VI a;
    REP1(i, 1, n) {
      if (ds.find(i) == i) {
	a.PB(i);
      }
    }
    int N = a.size();
    REP(i, N) {
      REP1(j, 0, i-1) {
	dp[i+1][j] = 
      }
    }
  }
};

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
Consider an undirected, complete, simple graph G on n vertices.
The vertices of G are labeled from 1 to n.
Specifically, each pair of distinct vertices is connected by a single undirected edge, so there are precisely n*(n-1)/2 edges in this graph.




You are given a set E that contains some edges of the graph G.
More precisely, you are given the vector <int>s x and y.
For each valid i, (x[i], y[i]) is one of the edges in E.




A spanning tree of G is a subset of exactly n-1 edges of G such that the edges connect all n vertices.
You may note that the edges of a spanning tree do indeed form a tree that is a subgraph of G and spans all its vertices.




We are interested in spanning trees that contain all of the edges in the provided set E.
Compute and return the number of such spanning trees modulo 987,654,323.
Two spanning trees are different if there is an edge of G that is in one of them but not in the other.



DEFINITION
Class:BuildingSpanningTreesDiv1
Method:getNumberOfSpanningTrees
Parameters:int, vector <int>, vector <int>
Returns:int
Method signature:int getNumberOfSpanningTrees(int n, vector <int> x, vector <int> y)


NOTES
-987,654,323 is a prime number.


CONSTRAINTS
-n will be between 1 and 1,000, inclusive.
-x will contain between 1 and 1,000 elements, inclusive.
-y will contain between 1 and 1,000 elements, inclusive.
-x and y will contain the same number of elements.
-Each element of x will be between 1 and n-1, inclusive.
-Each element of y will be between 2 and n, inclusive.
-For each valid i, x[i] will be less than y[i].
-All edges in E will be distinct.


EXAMPLES

0)
3
{1,2}
{2,3}

Returns: 1

The edges in the provided set E alredy form a spanning tree, so there is exactly one spanning tree that contains them.

1)
5
{1,3,4}
{2,4,5}

Returns: 6

There are six ways to add the one missing edge: one endpoint of the new edge must lie in the set {1,2} and the other in the set {3,4,5}.

2)
4
{1}
{2}

Returns: 8

There are eight spanning trees that contain the edge (1, 2):

{(1, 2), (1, 3), (1, 4)}
{(1, 2), (1, 3), (2, 4)}
{(1, 2), (1, 3), (3, 4)}
{(1, 2), (2, 3), (2, 4)}
{(1, 2), (1, 4), (2, 3)}
{(1, 2), (1, 4), (3, 4)}
{(1, 2), (2, 3), (3, 4)}
{(1, 2), (2, 4), (3, 4)}



3)
4
{1,2,1}
{2,3,3}

Returns: 0

The set E contains a cycle, and thus there is no spanning tree that contains all these edges.

4)
8
{1,4,2,3,5}
{4,7,6,5,8}

Returns: 144



5)
1000
{1}
{2}

Returns: 529013784

Don't forget to take the modulo.


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
		cout << "Testing BuildingSpanningTreesDiv1 (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1523721604;
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
		BuildingSpanningTreesDiv1 _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 3;
				int x[] = {1,2};
				int y[] = {2,3};
				_expected = 1;
				_received = _obj.getNumberOfSpanningTrees(n, vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 1:
			{
				int n = 5;
				int x[] = {1,3,4};
				int y[] = {2,4,5};
				_expected = 6;
				_received = _obj.getNumberOfSpanningTrees(n, vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 2:
			{
				int n = 4;
				int x[] = {1};
				int y[] = {2};
				_expected = 8;
				_received = _obj.getNumberOfSpanningTrees(n, vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 3:
			{
				int n = 4;
				int x[] = {1,2,1};
				int y[] = {2,3,3};
				_expected = 0;
				_received = _obj.getNumberOfSpanningTrees(n, vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 4:
			{
				int n = 8;
				int x[] = {1,4,2,3,5};
				int y[] = {4,7,6,5,8};
				_expected = 144;
				_received = _obj.getNumberOfSpanningTrees(n, vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 5:
			{
				int n = 1000;
				int x[] = {1};
				int y[] = {2};
				_expected = 529013784;
				_received = _obj.getNumberOfSpanningTrees(n, vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			/*case 6:
			{
				int n = ;
				int x[] = ;
				int y[] = ;
				_expected = ;
				_received = _obj.getNumberOfSpanningTrees(n, vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int n = ;
				int x[] = ;
				int y[] = ;
				_expected = ;
				_received = _obj.getNumberOfSpanningTrees(n, vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int n = ;
				int x[] = ;
				int y[] = ;
				_expected = ;
				_received = _obj.getNumberOfSpanningTrees(n, vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
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
