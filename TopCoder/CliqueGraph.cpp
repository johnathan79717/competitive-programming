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
 
typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;

struct CliqueGraph {
  long long calcSum(int N, vector <int> V, vector <int> sizes) {

  }
};

// BEGIN CUT HERE
/*
PROBLEM STATEMENT
Fox Ciel has an unweighted undirected connected graph G 
with N vertices.
The vertices are numbered 0 through N-1.
The graph has a special structure.
You are given its description in two vector <int>s V and 
sizes.
V contains a sequence of vertex numbers.
Note that some vertex numbers may occur in V multiple times.

For each valid i, let S[i] be the sum of the first i 
elements of sizes.
For example, if sizes={10,20,30} then S[0]=0, S[1]=10, S[2]
=10+20=30, and S[3]=10+20+30=60.

The graph G that is described by V and sizes looks as 
follows:
For each valid i, consider all pairs (j,k) such that S[i] 
<= j < k < S[i+1].
For each such pair (j,k), our graph G contains an edge 
between the vertices V[j] and V[k].
There are no other edges in G, only those defined above.
You may assume that V and sizes are always such that the 
resulting graph G is connected.

For each pair of vertices, compute their distance.
Return the sum of all those distances.

DEFINITION
Class:CliqueGraph
Method:calcSum
Parameters:int, vector <int>, vector <int>
Returns:long long
Method signature:long long calcSum(int N, vector <int> V, 
vector <int> sizes)


NOTES
-For some test cases, the correct return value may 
overflow a signed 32-bit integer variable.


CONSTRAINTS
-N will be between 2 and 2,500, inclusive.
-V will contain between 1 and 5,000 elements, inclusive.
-Each element of V will be between 0 and N-1, inclusive.
-sizes will contain between 1 and 2,500 elements, inclusive.
-Each element of sizes will be between 2 and N, inclusive.
-The sum of all elements of sizes will be equal to the 
number of elements in V.
-For each valid i, the elements V[S[i]], V[S[i]+1], ..., V
[S[i+1]-1] will be distinct. (See the problem statement 
for the definition of S[i].)
-The graph G described by V and sizes will be connected.


EXAMPLES

0)
4
{0,1,2,0,3}
{3,2}

Returns: 8

The graph looks as follows:

The distance between vertex 0 and vertex 1 : 1
The distance between vertex 0 and vertex 2 : 1
The distance between vertex 0 and vertex 3 : 1
The distance between vertex 1 and vertex 2 : 1
The distance between vertex 1 and vertex 3 : 2
The distance between vertex 2 and vertex 3 : 2
The sum is 8.

1)
5
{0,1,2,3,1,2,4}
{4,3}

Returns: 12

The graph looks as follows:



2)
15
{1,3,5,7,9,11,13,0
,2,3,6,7,10,11,14,0
,4,5,6,7,12,13,14,0
,8,9,10,11,12,13,14,0}
{8,8,8,8}

Returns: 130



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
		cout << "Testing CliqueGraph (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1404577568;
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
		CliqueGraph _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 4;
				int V[] = {0,1,2,0,3};
				int sizes[] = {3,2};
				_expected = 8LL;
				_received = _obj.calcSum(N, vector <int>(V, V+sizeof(V)/sizeof(int)), vector <int>(sizes, sizes+sizeof(sizes)/sizeof(int))); break;
			}
			case 1:
			{
				int N = 5;
				int V[] = {0,1,2,3,1,2,4};
				int sizes[] = {4,3};
				_expected = 12LL;
				_received = _obj.calcSum(N, vector <int>(V, V+sizeof(V)/sizeof(int)), vector <int>(sizes, sizes+sizeof(sizes)/sizeof(int))); break;
			}
			case 2:
			{
				int N = 15;
				int V[] = {1,3,5,7,9,11,13,0
				          ,2,3,6,7,10,11,14,0
				          ,4,5,6,7,12,13,14,0
				          ,8,9,10,11,12,13,14,0};
				int sizes[] = {8,8,8,8};
				_expected = 130LL;
				_received = _obj.calcSum(N, vector <int>(V, V+sizeof(V)/sizeof(int)), vector <int>(sizes, sizes+sizeof(sizes)/sizeof(int))); break;
			}
			/*case 3:
			{
				int N = ;
				int V[] = ;
				int sizes[] = ;
				_expected = LL;
				_received = _obj.calcSum(N, vector <int>(V, V+sizeof(V)/sizeof(int)), vector <int>(sizes, sizes+sizeof(sizes)/sizeof(int))); break;
			}*/
			/*case 4:
			{
				int N = ;
				int V[] = ;
				int sizes[] = ;
				_expected = LL;
				_received = _obj.calcSum(N, vector <int>(V, V+sizeof(V)/sizeof(int)), vector <int>(sizes, sizes+sizeof(sizes)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int N = ;
				int V[] = ;
				int sizes[] = ;
				_expected = LL;
				_received = _obj.calcSum(N, vector <int>(V, V+sizeof(V)/sizeof(int)), vector <int>(sizes, sizes+sizeof(sizes)/sizeof(int))); break;
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
