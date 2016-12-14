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

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;
// #line 40 "BiconnectedDiv1.cpp"
#include <string>
#include <vector>

int dp[104];

class BiconnectedDiv1 {
public:
    int minimize(vector <int> w1, vector <int> w2) {
        int N = w1.size() + 1;
        REP1(i, 1, N) dp[i] = 1e9;
        REP1(i, 3, N) {
            REP1(j, 3, i) {
                int sum = w1[i-j+1-1] + w1[i-1-1];
                REP1(k, i-j+1, i-2) {
                    sum += w2[k-1];
                }
                dp[i] = min(dp[i], dp[i-j] + sum);
            }
        }
        return dp[N];
    }
};
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// A 2-edge-connected graph is a connected undirected graph with the following property:
for any two distinct vertices u,v and for any edge e there exists a path from u to v that does not contain e.

You are given a graph G with n vertices numbered 0 through n-1, where n is not less than 3.
The graph has a very specific structure.
For each i between 0 and n-2, inclusive, vertices i and i+1 are connected by an edge with weight w1[i].
Additionally, for each i between 0 and n-3, inclusive, vertices i and i+2 are connected by an edge with weight w2[i].
It is easy to verify that this graph is 2-edge-connected.

Note that some of the edge weights may be zeros.
An edge with weight zero is still present in the graph, just like any other edge.

You may erase some edges of the graph G.
If you do, you must do it in such a way that the graph remains 2-edge-connected.
Your goal is to minimize the sum of weights of edges that remain in G.

You are given the vector <int>s w1 and w2 that describe the graph G.
Compute and return the smallest possible sum of weights of a graph that can be produced in the way described above.

DEFINITION
Class:BiconnectedDiv1
Method:minimize
Parameters:vector <int>, vector <int>
Returns:int
Method signature:int minimize(vector <int> w1, vector <int> w2)


CONSTRAINTS
-n will be between 3 and 100, inclusive.
-w1 will contain exactly n-1 elements.
-w2 will contain exactly n-2 elements.
-Each element of w1 and w2 will be between 0 and 10,000, inclusive.


EXAMPLES

0)
{1,2}
{3}

Returns: 6

There are three vertices and three edges (0,1), (1,2), (2,0). If you erase edge (0,1), then any path from 0 to 1 has to go through edge (0,2). And if you erase two or more edges, the graph will become disconnected. So you cannot erase anything.

1)
{3,0,4}
{1,2}

Returns: 10

An optimal solution is to keep all the edges.

2)
{3,3,3,3}
{3,6,3}

Returns: 18

An optimal solution is to erase edge (1,3).

3)
{7243,7525,8467,6351,9453,8456,8175,5874,6869,7400,6438,8926,6876}
{2642,1743,3546,4100,2788,3019,2678,1935,1790,2674,3775,1920}

Returns: 46729



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
		cout << "Testing BiconnectedDiv1 (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1466870446;
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
		BiconnectedDiv1 _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int w1[] = {1,2};
				int w2[] = {3};
				_expected = 6;
				_received = _obj.minimize(vector <int>(w1, w1+sizeof(w1)/sizeof(int)), vector <int>(w2, w2+sizeof(w2)/sizeof(int))); break;
			}
			case 1:
			{
				int w1[] = {3,0,4};
				int w2[] = {1,2};
				_expected = 10;
				_received = _obj.minimize(vector <int>(w1, w1+sizeof(w1)/sizeof(int)), vector <int>(w2, w2+sizeof(w2)/sizeof(int))); break;
			}
			case 2:
			{
				int w1[] = {3,3,3,3};
				int w2[] = {3,6,3};
				_expected = 18;
				_received = _obj.minimize(vector <int>(w1, w1+sizeof(w1)/sizeof(int)), vector <int>(w2, w2+sizeof(w2)/sizeof(int))); break;
			}
			case 3:
			{
				int w1[] = {7243,7525,8467,6351,9453,8456,8175,5874,6869,7400,6438,8926,6876};
				int w2[] = {2642,1743,3546,4100,2788,3019,2678,1935,1790,2674,3775,1920};
				_expected = 46729;
				_received = _obj.minimize(vector <int>(w1, w1+sizeof(w1)/sizeof(int)), vector <int>(w2, w2+sizeof(w2)/sizeof(int))); break;
			}
			/*case 4:
			{
				int w1[] = ;
				int w2[] = ;
				_expected = ;
				_received = _obj.minimize(vector <int>(w1, w1+sizeof(w1)/sizeof(int)), vector <int>(w2, w2+sizeof(w2)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int w1[] = ;
				int w2[] = ;
				_expected = ;
				_received = _obj.minimize(vector <int>(w1, w1+sizeof(w1)/sizeof(int)), vector <int>(w2, w2+sizeof(w2)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int w1[] = ;
				int w2[] = ;
				_expected = ;
				_received = _obj.minimize(vector <int>(w1, w1+sizeof(w1)/sizeof(int)), vector <int>(w2, w2+sizeof(w2)/sizeof(int))); break;
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
