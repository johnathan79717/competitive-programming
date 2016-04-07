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
#line 39 "FoxAirline2.cpp"
#include <string>
#include <vector>
struct DisjointSet {
    VI par, _size;
    int N;
    stack<int> record;

    DisjointSet(int _N): par(_N), _size(_N), N(_N) {
        init();
    }

    void init() {
        for(int i = 0; i < N; i++) {
            par[i] = i;
            _size[i] = 1;
        }
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
int d[10][10];

V(PII) e;
int N;

bool ok() {
    DisjointSet set(N);
    for (auto &pr: e) {
        d[pr.first][pr.second]--;
    }
    REP(ii, N) {
        REP1(jj, ii+1, N-1) {
            if (d[ii][jj]) {
                set.unite(ii, jj);
            }
        }
    }
    for (auto &pr: e) {
        d[pr.first][pr.second]++;
    }
    return set.size(0) == N;
}

bool dfs(int i, int j) {
    if (i == N) {
        return ok();
    }
    if (j == N) {
        return dfs(i+1, i+2);
    }
    if (d[i][j] == 0) {
        return dfs(i, j+1);
    }
    DisjointSet set(N);
    for (auto &pr: e) {
        set.unite(pr.first, pr.second);
    }
    if (set.size(0) == N) {
        return ok();
    }

    if (set.find(i) != set.find(j)) {
        e.EB(i, j);
        if (ok() && dfs(i, j+1)) {
            return true;
        }
        e.pop_back();
    }
    int ii = i, jj = j+1;
    while (ii < N) {
        while (jj < N) {
            if (d[ii][jj]) {
                set.unite(ii, jj);
            }
            jj++;
        }
        jj = ii+2;
        ii++;
    }
    if (set.size(0) == N) {
        return dfs(i, j+1);
    }
    return false;
}

class FoxAirline2 {
public:
    string isPossible(int n, vector <int> a, vector <int> b) {
        N = n;
        int M = a.size();
        REP(i, M) {
            if (a[i] > b[i]) {
                swap(a[i], b[i]);
            }
            d[a[i]][b[i]]++;
        }
        return dfs(0, 1) ? "Possible" : "Impossible";
    }
};
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Fox Ciel has an airline company: Fox Airline.
There are n airports in the region serviced by Fox Airline.
The airports are numbered 0 through n-1.
You are given the int n.

The company currently offers several bidirectional flights.
You are given the information about these flights in the vector <int>s a and b:
for each valid i there is a bidirectional flight that connects the airports a[i] and b[i].
Note that some pairs of airports may be connected by multiple direct flights.

Fox Airline is too big, so Ciel has to split it into two new companies.
After the split, each of the current flights will belong to one of the two new companies.

We say that a company services the entire region if it is possible to travel between all cities in the region by just using flights of that company.
Fox Ciel wants to know whether it is possible to split her company in such a way that each of the two new companies will service the entire region (i.e., all n cities).
Return "Possible" if it can be done, and "Impossible" otherwise.  

DEFINITION
Class:FoxAirline2
Method:isPossible
Parameters:int, vector <int>, vector <int>
Returns:string
Method signature:string isPossible(int n, vector <int> a, vector <int> b)


CONSTRAINTS
-n will be between 2 and 10, inclusive.
-a will contain between 1 and 50 elements, inclusive.
-a and b will contain the same number of elements.
-Each element in a will be between 0 and n-1, inclusive.
-Each element in b will be between 0 and n-1, inclusive.
-For each i, a[i] != b[i].


EXAMPLES

0)
4
{0,0,0,1,1,2}
{1,2,3,2,3,3}

Returns: "Possible"

One possible solution is to assign the flights {(0,1), (0,2), (2,3)} to one company and the flights {(0,3), (1,2), (1,3)} to the other company.

1)
6
{0,0,0,0,1,1,1,2,2,3,0}
{1,2,3,4,2,3,4,3,4,4,5}

Returns: "Impossible"

Note that Ciel's current company has only one flight that visits airport 5.
Regardless of how we divide the flights between the two new companies, one of those companies won't have any flights that visit airport 5.

2)
5
{0,0,0,1,1,2,2,3}
{1,2,4,2,4,3,4,4}

Returns: "Possible"



3)
2
{0,1,1}
{1,0,0}

Returns: "Possible"

Note that there may be multiple flights between some pairs of airports.

4)
10
{0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 5, 5, 5, 5, 6, 6, 6, 7, 7, 8}
{1, 2, 3, 4, 5, 6, 7, 8, 9, 2, 3, 4, 5, 6, 7, 8, 9, 3, 4, 5, 6, 7, 8, 9, 4, 5, 6, 7, 8, 9, 5, 6, 7, 8, 9, 6, 7, 8, 9, 7, 8, 9, 8, 9, 9}

Returns: "Possible"



5)
2
{0}
{1}

Returns: "Impossible"



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
		cout << "Testing FoxAirline2 (450.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1458404329;
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
		FoxAirline2 _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 4;
				int a[] = {0,0,0,1,1,2};
				int b[] = {1,2,3,2,3,3};
				_expected = "Possible";
				_received = _obj.isPossible(n, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 1:
			{
				int n = 6;
				int a[] = {0,0,0,0,1,1,1,2,2,3,0};
				int b[] = {1,2,3,4,2,3,4,3,4,4,5};
				_expected = "Impossible";
				_received = _obj.isPossible(n, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 2:
			{
				int n = 5;
				int a[] = {0,0,0,1,1,2,2,3};
				int b[] = {1,2,4,2,4,3,4,4};
				_expected = "Possible";
				_received = _obj.isPossible(n, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 3:
			{
				int n = 2;
				int a[] = {0,1,1};
				int b[] = {1,0,0};
				_expected = "Possible";
				_received = _obj.isPossible(n, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 4:
			{
				int n = 10;
				int a[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 5, 5, 5, 5, 6, 6, 6, 7, 7, 8};
				int b[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 2, 3, 4, 5, 6, 7, 8, 9, 3, 4, 5, 6, 7, 8, 9, 4, 5, 6, 7, 8, 9, 5, 6, 7, 8, 9, 6, 7, 8, 9, 7, 8, 9, 8, 9, 9};
				_expected = "Possible";
				_received = _obj.isPossible(n, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 5:
			{
				int n = 2;
				int a[] = {0};
				int b[] = {1};
				_expected = "Impossible";
				_received = _obj.isPossible(n, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 6:
			{
				int n = 4;
				int a[] = {0, 0, 1, 1, 2};
				int b[] = {2, 3, 2, 3, 3};
				_expected = "Impossible";
				_received = _obj.isPossible(n, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 7:
			{
				int n = 10;
				int a[] = {2, 0, 7, 9, 5, 3, 2, 3, 7, 9, 5, 1, 9, 4, 7, 0, 3, 6};
				int b[] = {9, 8, 3, 7, 0, 0, 1, 6, 4, 4, 2, 4, 6, 8, 3, 7, 2, 3};
				_expected = "Possible";
				_received = _obj.isPossible(n, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 8:
			{
				int n = 10;
				int a[] = {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 5, 5, 6, 0, 0, 1, 2, 3, 4, 5, 6, 7};
				int b[] = {1, 2, 3, 4, 5, 6, 7, 2, 3, 4, 5, 6, 7, 3, 4, 5, 6, 7, 4, 5, 6, 7, 5, 6, 7, 6, 7, 7, 9, 8, 8, 8, 8, 8, 8, 8, 8};
				_expected = "Impossible";
				_received = _obj.isPossible(n, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
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
			cout << "           Expected: " << "\"" << _expected << "\"" << endl;
			cout << "           Received: " << "\"" << _received << "\"" << endl;
		}
	}
}

// END CUT HERE
