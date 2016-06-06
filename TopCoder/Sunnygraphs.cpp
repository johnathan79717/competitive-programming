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

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;
// #line 40 "Sunnygraphs.cpp"
#include <string>
#include <vector>
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

int component[50];
int c = 0;
VI adj;

int go(int i) {
    if (component[i]) return component[i];
    return go(adj[i]);
}

int depth[50];
int cycle[50];

class Sunnygraphs {
public:
    long long count(vector <int> a) {
        int N = a.size();
        DisjointSet ds(N);
        REP(i, N) {
            ds.unite(i, a[i]);
        }
        REP(i, N) {
            int k = 0;
            int j = i;
            do {
                j = a[j];
                k++;
            } while (j != i && k < N+1);
            if (j == i) {
                cycle[ds.find(i)] = k;
            } else {
                depth[i] = -1;
            }
        }
        REP(i, N) {
            if (depth[i] < 0) {
                int j = i, k = 0;
                while (depth[j]) {
                    j = a[j];
                    k++;
                }
                depth[i] = k;
            }
        }
        int d0 = depth[0], d1 = depth[1];
        int c0 = cycle[ds.find(0)], c1 = cycle[ds.find(1)];
        if (ds.find(0) == ds.find(1)) {
            int i = 0, j = 1;
            while (depth[i] > depth[j]) i = a[i];
            while (depth[i] < depth[j]) j = a[j];
            while (i != j && depth[i]) {
                i = a[i];
                j = a[j];
            }
            if (i != j) {
                return (1ll << N) - ((1ll<<d0)-1 + (1ll<<d1)-1) * (1ll << (N - d0 - d1 - cycle[ds.find(0)]));
            } else {
                int di = depth[i];
                return (1ll << N) - ((1ll << (d0 - di)) - 1 + (1ll << (d1 - di)) - 1) * (1ll << (N - d0 - d1 + di - c0));
            }
        } else {
            return (1ll << N) - (1ll << (N - d0 - c0)) - (1ll << (N - d1 - c1)) + (1ll << (N - d0 - c0 - d1 - c1));
        }
    }
};
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Hero has just constructed a very specific graph.
He started with n isolated vertices, labeled 0 through n-1.
For each vertex i Hero then chose a vertex a[i] (other than i) and he added an edge that connected i and a[i].
This way he created a graph with n vertices and n edges.
Note that if a[x]=y and a[y]=x, the vertices x and y were connected by two different edges.

Hero now wants to perform the following procedure:

Add a new isolated vertex number n.
Choose a subset M of the original vertices.
For each x in M, erase an edge between vertices x and a[x].
For each x in M, add a new edge between vertices x and n.


Hero's goal is to create a final graph in which the vertices 0 and 1 are in the same connected component.
(I.e., there is a path from one of them to the other.)

In step 2 of the above procedure Hero has 2^n possible subsets to choose from.
A choice of M is good if it produces a graph with the desired property.
Count how many of the 2^n possibilities are good choices.
Return that count as a long long.

DEFINITION
Class:Sunnygraphs
Method:count
Parameters:vector <int>
Returns:long long
Method signature:long long count(vector <int> a)


CONSTRAINTS
-a will contain n elements.
-n will be between 2 and 50, inclusive.
-Each element in a will be between 0 and n - 1, inclusive.
-For each i between 0 and n - 1 holds a[i] != i.


EXAMPLES

0)
{1,0}

Returns: 4

The original graph contained the vertices 0 and 1.
This pair of vertices was connected by two edges.

Next, Hero added a new vertex 2.
Then he had to choose one of four possible subsets M:

If he chose M = {}, the resulting graph contained the edges 0-1 and 0-1. The vertices 0 and 1 were connected.
If he chose M = {0}, the resulting graph contained the edges 0-1 and 0-2. The vertices 0 and 1 were connected.
If he chose M = {1}, the resulting graph contained the edges 0-1 and 1-2. The vertices 0 and 1 were connected.
Finally, if he chose M = {0, 1}, the resulting graph contained the edges 0-2 and 1-2. And again, the vertices 0 and 1 were connected: there is a path 0-1-2.


As all four choices of M are good, the correct answer is 4.

1)
{2,2,0}

Returns: 7

Here, the original graph contained the edges 0-2, 0-2, and 1-2.
For this graph M = {1} is not a good choice.
This choice produces a graph with edges 0-2, 0-2, and 1-3.
In this graph the vertices 0 and 1 are not in the same connected component.
The other seven possible choices of M are all good.

2)
{2,3,0,1}

Returns: 9



3)
{2,2,3,4,3}

Returns: 30



4)
{18,18,20,28,7,27,8,13,40,3,7,21,30,17,13,34,29,16,15,11,0,9,39,36,38,23,24,8,4,9,29,22,35,5,13,23,3,27,34,23,8}

Returns: 2198754820096



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
		cout << "Testing Sunnygraphs (300.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1464620404;
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
		Sunnygraphs _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int a[] = {1,0};
				_expected = 4LL;
				_received = _obj.count(vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}
			case 1:
			{
				int a[] = {2,2,0};
				_expected = 7LL;
				_received = _obj.count(vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}
			case 2:
			{
				int a[] = {2,3,0,1};
				_expected = 9LL;
				_received = _obj.count(vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}
			case 3:
			{
				int a[] = {2,2,3,4,3};
				_expected = 30LL;
				_received = _obj.count(vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}
			case 4:
			{
				int a[] = {18,18,20,28,7,27,8,13,40,3,7,21,30,17,13,34,29,16,15,11,0,9,39,36,38,23,24,8,4,9,29,22,35,5,13,23,3,27,34,23,8};
				_expected = 2198754820096LL;
				_received = _obj.count(vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}
			/*case 5:
			{
				int a[] = ;
				_expected = LL;
				_received = _obj.count(vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int a[] = ;
				_expected = LL;
				_received = _obj.count(vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int a[] = ;
				_expected = LL;
				_received = _obj.count(vector <int>(a, a+sizeof(a)/sizeof(int))); break;
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
