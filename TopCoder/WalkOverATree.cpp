#include <cassert>
#include <list>
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

int dp1[51][101], dp2[51][101];
VI parent;
int N, L;

void dfs(int p) {
    REP1(v, 1, N-1) {
        if (parent[v-1] == p) {
            dfs(v);
            PER(i, 101) {
                if (i-1 >= 0)
                    MAX(dp1[p][i], dp1[v][i-1]);
                if (i-2 >= 0)
                    MAX(dp2[p][i], dp2[v][i-2]);
                PER(j, 101) {
                    if (i-j-2 >= 0) {
                        MAX(dp1[p][i], dp1[p][j] + dp2[v][i-j-2]);
                        MAX(dp2[p][i], dp2[p][j] + dp2[v][i-j-2]);
                    }
                    if (i-j-1 >= 0) {
                        MAX(dp1[p][i], dp2[p][j] + dp1[v][i-j-1]);
                    }
                }
            }
            REP(i, 100) {
                MAX(dp1[p][i+1], dp1[p][i]);
                MAX(dp2[p][i+1], dp2[p][i]);
            }
        }
    }
    REP(i, 101) dp1[p][i]++, dp2[p][i]++;
}


class WalkOverATree {
public:
    int maxNodesVisited(vector <int> parent, int L) {
        N = parent.size() + 1;
        ::L = L;
        ::parent = parent;
        dfs(0);
        return max(dp1[0][L], dp2[0][L]);
    }
};
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
Given is a tree on n nodes.
The nodes are numbered 0 through n-1.
You are given the description of the tree as a vector <int> parent with n-1 elements.
For each valid i, there is an edge between vertices (i+1) and parent[i].





A person is currently standing in node 0.
In a single step, the person can move from its current node to any adjacent node.
You are given an int L.
The person is allowed to make at most L steps.





Return the maximum number of nodes the person can visit during the walk.
Node 0 (where the walk starts) and the node where the walk ends count as visited.
Each visited node is only counted once, even if it is visited multiple times.


DEFINITION
Class:WalkOverATree
Method:maxNodesVisited
Parameters:vector <int>, int
Returns:int
Method signature:int maxNodesVisited(vector <int> parent, int L)


CONSTRAINTS
-parent will contain between 0 and 49 elements, inclusive.
-For each i, parent[i] will be between 0 and i, inclusive.
-L will be between 1 and 100, inclusive.


EXAMPLES

0)
{0, 0}
2

Returns: 2

The tree consists of edges 1-0 and 2-0.
Our person will start in node 0 and can make at most L=2 steps.
In two steps, the best we can do is visit one of the nodes 1 and 2.

1)
{0, 0}
3

Returns: 3

This is the same tree, only now we have L=3.
In three steps the person can visit all three nodes: for example, by going from node 0 to node 1, back to node 0, and finally to node 2.
Note that even though the person visited node 0 twice, we only count it once.

2)
{0, 1, 2, 3}
2

Returns: 3



3)
{0,0,0,0,2,4,2,3,1}
1

Returns: 2



4)
{0,0,1,2,3,2,3,1,3,0,1,8,6,8,0,5,15,0,9}
4

Returns: 5



5)
{0,0,0,1,1,3,5,1,4,5,2,2,10,5,10,10,11,13,8,3,18,15,20,20,23,8,11,26,4}
26

Returns: 17



6)
{0, 0, 2, 0}

100

Returns: 5

As the tree is very small and L large, the person can easily visit all nodes.

7)
{0, 0, 2}
4

Returns: 4



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
		cout << "Testing WalkOverATree (222.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1440779808;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 222.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		WalkOverATree _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int parent[] = {0, 0};
				int L = 2;
				_expected = 2;
				_received = _obj.maxNodesVisited(vector <int>(parent, parent+sizeof(parent)/sizeof(int)), L); break;
			}
			case 1:
			{
				int parent[] = {0, 0};
				int L = 3;
				_expected = 3;
				_received = _obj.maxNodesVisited(vector <int>(parent, parent+sizeof(parent)/sizeof(int)), L); break;
			}
			case 2:
			{
				int parent[] = {0, 1, 2, 3};
				int L = 2;
				_expected = 3;
				_received = _obj.maxNodesVisited(vector <int>(parent, parent+sizeof(parent)/sizeof(int)), L); break;
			}
			case 3:
			{
				int parent[] = {0,0,0,0,2,4,2,3,1};
				int L = 1;
				_expected = 2;
				_received = _obj.maxNodesVisited(vector <int>(parent, parent+sizeof(parent)/sizeof(int)), L); break;
			}
			case 4:
			{
				int parent[] = {0,0,1,2,3,2,3,1,3,0,1,8,6,8,0,5,15,0,9};
				int L = 4;
				_expected = 5;
				_received = _obj.maxNodesVisited(vector <int>(parent, parent+sizeof(parent)/sizeof(int)), L); break;
			}
			case 5:
			{
				int parent[] = {0,0,0,1,1,3,5,1,4,5,2,2,10,5,10,10,11,13,8,3,18,15,20,20,23,8,11,26,4};
				int L = 26;
				_expected = 17;
				_received = _obj.maxNodesVisited(vector <int>(parent, parent+sizeof(parent)/sizeof(int)), L); break;
			}
			case 6:
			{
				int parent[] = {0, 0, 2, 0};
				int L = 100;
				_expected = 5;
				_received = _obj.maxNodesVisited(vector <int>(parent, parent+sizeof(parent)/sizeof(int)), L); break;
			}
			case 7:
			{
				int parent[] = {0, 0, 2};
				int L = 4;
				_expected = 4;
				_received = _obj.maxNodesVisited(vector <int>(parent, parent+sizeof(parent)/sizeof(int)), L); break;
			}
			/*case 8:
			{
				int parent[] = ;
				int L = ;
				_expected = ;
				_received = _obj.maxNodesVisited(vector <int>(parent, parent+sizeof(parent)/sizeof(int)), L); break;
			}*/
			/*case 9:
			{
				int parent[] = ;
				int L = ;
				_expected = ;
				_received = _obj.maxNodesVisited(vector <int>(parent, parent+sizeof(parent)/sizeof(int)), L); break;
			}*/
			/*case 10:
			{
				int parent[] = ;
				int L = ;
				_expected = ;
				_received = _obj.maxNodesVisited(vector <int>(parent, parent+sizeof(parent)/sizeof(int)), L); break;
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
