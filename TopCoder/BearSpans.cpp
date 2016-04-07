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
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define PER(i,n) for(int i=(n)-1;i>=0;i--)
#define PB push_back
#define MS0(x) memset(x,0,sizeof(x))
#define SZ(x) ((x).size())

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;
#line 39 "BearSpans.cpp"
#include <string>
#include <vector>
bool used[1005][1005];
class BearSpans {
public:
    vector <int> findAnyGraph(int n, int m, int k) {
        MS0(used);
        if (k >= 10 || (1 << k) > n) {
            return vector<int> {-1};
        }        
        auto b = solve(n, k);
        if (SZ(b) / 2 > m) return vector<int> {-1};
        vector<int> ans;
        PER(i, SZ(b)/2) {
            int x = b[2*i], y = b[2*i+1];
            ans.PB(x); ans.PB(y);
            if (x > y) swap(x, y);
            used[x][y] = true;
        }
        REP1(i, 1, n) {
            REP1(j, i+1, n) {
                if (SZ(ans) < 2 * m && !used[i][j]) {
                    ans.PB(i); ans.PB(j);
                }
            }
        }
        return ans;
    }
    vector<int> solve(int n, int k) {
        if (k == 1) {
            vector<int> ans;
            REP1(i, 2, n) {
                ans.PB(1);
                ans.PB(i);
            }
            return ans;
        } else {
            auto ans = solve(n/2, k-1);
            REP1(i, 1, n/2) {
                ans.PB(i); ans.PB(i+n/2);
            }
            if (n % 2) {
                ans.PB(n-1); ans.PB(n);
            }
            return ans;
        }
    }
};
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Bear Limak loves algorithms and tolerates data structures.
Today he learned about Boruvka's algorithm.
Boruvka's algorithm was the first polynomial-time algorithm to find the minimum spanning tree (MST).
Moreover, it was pretty efficient because it worked in O(E log V).
You can find a detailed description of this algorithm and its history at https://en.wikipedia.org/wiki/Bor%C5%AFvka%27s_algorithm.
Below we give a short description of Boruvka's algorithm.
This description should be used when solving this problem.

The input for Boruvka's algorithm is a simple connected undirected weighted graph G.
(Here, "simple" means there are no loops and each pair of vertices is directly connected by at most one edge.)
The edge weights are distinct positive integers from 1 to m, where m is the number of edges in the graph.

The minimum spanning tree of G is a subgraph H of G with the following properties:

H contains the same vertices as G.
H is connected.
The sum of weights of edges in H is as small as possible.


Here is Boruvka's algorithm in pseudocode:


Initialize H to contain all vertices of G but no edges at all.

While H is not connected yet:
    For each component C in H:
        Find the lightest edge in G that has exactly one endpoint in C.
        Mark this edge for addition.

    Add all marked edges to H.

Return H.


Note that the algorithm is deterministic: the weights are all distinct, hence each edge we mark for addition is uniquely determined.

You are given ints n, m, and k.
Your task is to construct one arbitrary graph G with the following properties:

G is a valid input for Boruvka's algorithm, as defined above.
G has exactly n vertices and m edges. The vertices are numbered 1 through n. The edge weights are 1 through m.
Boruvka's algorithm will find the MST of G in exactly k rounds. (A round is a single iteration of the while-cycle in the pseudocode above.)


If no such G exists, return the vector <int> {-1}.
(That is, a vector <int> with a single element that is minus one.)

Otherwise, return a vector <int> with the description of your chosen G.
This vector <int> should have 2*m elements: two for each edge.
Let answer[] denote the returned vector <int>.
For each w between 1 and m, inclusive, take the edge with weight w and store its endpoints into answer[2*w-2] and answer[2*w-1].

DEFINITION
Class:BearSpans
Method:findAnyGraph
Parameters:int, int, int
Returns:vector <int>
Method signature:vector <int> findAnyGraph(int n, int m, int k)


NOTES
-n will be between 2 and 1000, inclusive.
-m will be between n-1 and 1000, inclusive.
-m will be not greater than n*(n-1)/2.
-k will be between 1 and 1000, inclusive.


EXAMPLES

0)
17
22
1

Returns: {1, 2, 1, 3, 1, 4, 1, 5, 1, 6, 1, 7, 1, 8, 1, 9, 1, 10, 1, 11, 1, 12, 1, 13, 1, 14, 1, 15, 1, 16, 1, 17, 2, 3, 2, 8, 3, 9, 8, 9, 10, 12, 12, 14 }

We were asked to find a graph with 17 vertices and 22 edges that will be fully solved in one round of Boruvka's algorithm.
We can easily verify that the graph given in the example output does have the property.
The minimum spanning tree of this graph consists of the edges 1-x for all x between 2 and 17, inclusive.
For each x, the edge 1-x is marked for addition in the first round: as the cheapest edge that leaves vertex x.

1)
9
12
3

Returns: {6, 5, 7, 6, 1, 2, 3, 4, 8, 9, 3, 5, 7, 4, 1, 9, 6, 2, 6, 1, 1, 8, 4, 5 }

Let's take a loot at the graph given in the example output.
After the first round we have four components: {1,2}, {3,4}, {5,6,7}, {8,9}.
After the second round we have two components: {1,2,8,9} and {3,4,5,6,7}.
The third round connects the two remaining componenets so we get 3 rounds in total.

2)
9
12
7

Returns: {-1 }



3)
1000
999
970

Returns: {-1 }



4)
2
1
1

Returns: {1, 2 }



5)
3
2
1

Returns: {1, 2, 1, 3 }



6)
3
3
2

Returns: {-1 }



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
		cout << "Testing BearSpans (450.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1453998599;
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
		BearSpans _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 17;
				int m = 22;
				int k = 1;
				int __expected[] = {1, 2, 1, 3, 1, 4, 1, 5, 1, 6, 1, 7, 1, 8, 1, 9, 1, 10, 1, 11, 1, 12, 1, 13, 1, 14, 1, 15, 1, 16, 1, 17, 2, 3, 2, 8, 3, 9, 8, 9, 10, 12, 12, 14 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findAnyGraph(n, m, k); break;
			}
			case 1:
			{
				int n = 9;
				int m = 12;
				int k = 3;
				int __expected[] = {6, 5, 7, 6, 1, 2, 3, 4, 8, 9, 3, 5, 7, 4, 1, 9, 6, 2, 6, 1, 1, 8, 4, 5 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findAnyGraph(n, m, k); break;
			}
			case 2:
			{
				int n = 9;
				int m = 12;
				int k = 7;
				int __expected[] = {-1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findAnyGraph(n, m, k); break;
			}
			case 3:
			{
				int n = 1000;
				int m = 999;
				int k = 970;
				int __expected[] = {-1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findAnyGraph(n, m, k); break;
			}
			case 4:
			{
				int n = 2;
				int m = 1;
				int k = 1;
				int __expected[] = {1, 2 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findAnyGraph(n, m, k); break;
			}
			case 5:
			{
				int n = 3;
				int m = 2;
				int k = 1;
				int __expected[] = {1, 2, 1, 3 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findAnyGraph(n, m, k); break;
			}
			case 6:
			{
				int n = 3;
				int m = 3;
				int k = 2;
				int __expected[] = {-1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findAnyGraph(n, m, k); break;
			}
			case 7:
			{
				int n = 9;
				int m = 12;
				int k = 3;
				int __expected[] = {-1};
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findAnyGraph(n, m, k); break;
			}
			/*case 8:
			{
				int n = ;
				int m = ;
				int k = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findAnyGraph(n, m, k); break;
			}*/
			/*case 9:
			{
				int n = ;
				int m = ;
				int k = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findAnyGraph(n, m, k); break;
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
			cout << "           Expected: {";
			for (unsigned i = 0; i < _expected.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _expected[i];
			}
			cout << " }" << endl;
			cout << "           Received: {";
			for (unsigned i = 0; i < _received.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _received[i];
			}
			cout << " }" << endl;
		}
	}
}

// END CUT HERE
