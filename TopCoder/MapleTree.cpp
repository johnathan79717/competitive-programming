#line 2 "MapleTree.cpp"
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
#include <bitset>
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
#define MAX_LOG_V 11
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

int parent[MAX_LOG_V][2000];
int depth[2000];

int lca(int u, int v) {
  if(depth[u] > depth[v]) swap(u, v);
  for(int k = 0; k < MAX_LOG_V; k++) {
    if((depth[v] - depth[u]) >> k & 1) {
      v = parent[k][v];
    }
  }
  if(u == v) return u;
  for(int k = MAX_LOG_V - 1; k >= 0; k--) {
    if(parent[k][u] != parent[k][v]) {
      u = parent[k][u];
      v = parent[k][v];
    }
  }
  return parent[0][u];
}

bitset<2000> bs[2000];

class MapleTree {
public:
    int sum(vector <int> p, vector <int> length) {
	int N = p.size() + 1;
	MS1(parent);
	depth[0] = 0;
	VI d(N);
	REPP(i, 1, N) {
	    depth[i] = depth[p[i-1]] + 1;
	    d[i] = d[p[i-1]] + length[i-1];
	    parent[0][i] = p[i-1];
	}
	for(int k = 0; k + 1 < MAX_LOG_V; k++) {
	    for(int v = 0; v < N; v++) {
	      if(parent[k][v] < 0)
		parent[k+1][v] = -1;
	      else
		parent[k + 1][v] = parent[k][parent[k][v]];
	    }
	}
	REP(i, N) {
	    bs[i].reset();
	    REP(j, N) {
		bs[i].set(j);
	    }
	}
	vector<pair<int, PII>> ds;
	REP(i, N) {
	    REPP(j, i, N) {
		int a = lca(i, j);
		ds.PB(d[i] - d[a] + d[j] - d[a], MP(i, j));
	    }
	}
	sort(ALL(ds), greater<pair<int, PII>>());
	Z ans = 0;
	for (const auto &pr : ds) {
	    int i = pr.S.F, j = pr.S.S, d = pr.F;
	    bs[i].reset(j);
	    bs[j].reset(i);
	    ans += Z(2).pow((bs[i] & bs[j]).count()) * d;
	}
	return ans.i;
    }
};

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Time limit is 3.5 seconds.
Kaede loves maple trees. One day, she found a big maple tree and she described it as an undirected connected graph with N nodes and N-1 edges.
You are given the description in the vector <int>s p and length. For each valid i, the i-th edge of the tree connects node p[i] and node i+1, and the length of this edge is length[i].

There are 2N-1 ways to choose a non-empty subset of nodes. Once we choose a subset of nodes, there is always a unique minimal subtree which contains all nodes in the subset.

Kaede got interested in diameters of these subtrees.
Suppose we iterate over all 2N-1 ways to choose a non-empty subset of nodes, for each of them we construct the unique minimal subtree and then we determine and write down its diameter. Let D be the sum of the 2N-1 values we would write down.
Please help Kaede: calculate and return the value (D modulo 1,000,000,007) for the given tree.

DEFINITION
Class:MapleTree
Method:sum
Parameters:vector <int>, vector <int>
Returns:int
Method signature:int sum(vector <int> p, vector <int> length)


NOTES
-Given two vertices u, v in a tree, let d(u, v) be the distance between u and v, i.e., the sum of lengths on the unique simple path that connects u and v. The diameter of a tree is the largest out of all values d(u, v).


CONSTRAINTS
-N will be between 2 and 2000, inclusive.
-p and length will contain exactly N-1 elements each.
-For valid i, p[i] will be between 0 and i, inclusive.
-Each element of length will be between 1 and 10000, inclusive.


EXAMPLES

0)
{0, 0, 1, 1, 2}
{1, 2, 1, 1, 2}

Returns: 249

The tree is shown below as ASCII art. Edge lengths are shown using the corresponding number of symbols.

       0
      / \
     1   \
    / \   2
   3   4   \
            \
             5

The diameter of this tree is 6.
There are 63 different ways in which we can select a non-empty subset of nodes, so the answer is a sum of 63 subtree diameters.


1)
{0, 1, 2, 3}
{10, 10, 10, 10}

Returns: 720

This tree is a line.
We can compute the answer as follows:

There are 5 non-empty subsets of nodes that produce a subtree of diameter 0. Example subset: {2}.
There are 4 non-empty subsets of nodes that produce a subtree of diameter 10. Example subset: {2, 3}.
There are 6 non-empty subsets of nodes that produce a subtree of diameter 20. Example subsets: {0, 2} and {1, 2, 3}.
There are 8 non-empty subsets of nodes that produce a subtree of diameter 30. Example subset: {0, 1, 3}.
There are 8 non-empty subsets of nodes that produce a subtree of diameter 40. Example subset: {0, 1, 2, 3, 4}.

Thus, the sum of all 31 diameters is 4*10 + 6*20 + 8*30 + 8*40 = 720.



2)
{0, 0, 0, 0}
{10, 10, 10, 10}

Returns: 480

This tree is a star. Among the 31 subtrees whose diameters we are interested in are five with diameter 0, four with diameter 10, and twenty-two with diameter 20. Thus, the sum of all diameters is 4*10 + 22*20 = 480.

3)
{0}
{1}

Returns: 1



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
		cout << "Testing MapleTree (600.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1612635786;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 600.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		MapleTree _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int p[] = {0, 0, 1, 1, 2};
				int length[] = {1, 2, 1, 1, 2};
				_expected = 249;
				_received = _obj.sum(vector <int>(p, p+sizeof(p)/sizeof(int)), vector <int>(length, length+sizeof(length)/sizeof(int))); break;
			}
			case 1:
			{
				int p[] = {0, 1, 2, 3};
				int length[] = {10, 10, 10, 10};
				_expected = 720;
				_received = _obj.sum(vector <int>(p, p+sizeof(p)/sizeof(int)), vector <int>(length, length+sizeof(length)/sizeof(int))); break;
			}
			case 2:
			{
				int p[] = {0, 0, 0, 0};
				int length[] = {10, 10, 10, 10};
				_expected = 480;
				_received = _obj.sum(vector <int>(p, p+sizeof(p)/sizeof(int)), vector <int>(length, length+sizeof(length)/sizeof(int))); break;
			}
			case 3:
			{
				int p[] = {0};
				int length[] = {1};
				_expected = 1;
				_received = _obj.sum(vector <int>(p, p+sizeof(p)/sizeof(int)), vector <int>(length, length+sizeof(length)/sizeof(int))); break;
			}
			/*case 4:
			{
				int p[] = ;
				int length[] = ;
				_expected = ;
				_received = _obj.sum(vector <int>(p, p+sizeof(p)/sizeof(int)), vector <int>(length, length+sizeof(length)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int p[] = ;
				int length[] = ;
				_expected = ;
				_received = _obj.sum(vector <int>(p, p+sizeof(p)/sizeof(int)), vector <int>(length, length+sizeof(length)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int p[] = ;
				int length[] = ;
				_expected = ;
				_received = _obj.sum(vector <int>(p, p+sizeof(p)/sizeof(int)), vector <int>(length, length+sizeof(length)/sizeof(int))); break;
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
