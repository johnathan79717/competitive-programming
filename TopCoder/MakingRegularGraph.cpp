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
#define PB push_back
#define V(T) vector<T >
 
typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;

#line 40 "MakingRegularGraph.cpp"
#include <string>
#include <vector>
class MakingRegularGraph {
public:
  vector <int> addEdges(int n, vector <int> x, vector <int> y) {
    V(VI) adj(n);
    int L = x.size();
    REP(i, L) {
      adj[x[i]].PB(y[i]);
      adj[y[i]].PB(x[i]);
    }
    priority_queue<int, VI, greater<int>> pq[2];
    REP(i, n) {
      if (adj[i].size() <= 1) {
	pq[adj[i].size()].push(i);
      }
    }
    auto ok = [&pq, &adj]() {
      if (pq[1].empty() && pq[0].size() && pq[0].size() < 3) {
	return false;
      }
      if (pq[0].empty() && pq[1].size() == 2) {
	int a = pq[1].top();
	pq[1].pop();
	int b = pq[1].top();
	pq[1].push(a);
	if (adj[a][0] == b) {
	  return false;
	}
      }
      return true;
    };
    if (!ok()) {
      return VI(1, -1);
    }
    auto getNext = [&pq]() {
      int ans;
      if (pq[1].empty() || ( !pq[0].empty() && pq[0].top() < pq[1].top() )) {
	ans = pq[0].top();
	pq[0].pop();
      } else {
	ans = pq[1].top();
	pq[1].pop();
      }
      return ans;
    };
    VI ans;
    while (pq[0].size() || pq[1].size()) {
    //REP(i, 10) {
      //cout << pq[0].size() << ' ' << pq[1].size() << endl;
      int u = getNext(), v = getNext();
      adj[u].PB(v);
      adj[v].PB(u);
      if(adj[u].size() == 1) pq[1].push(u);
      if(adj[v].size() == 1) pq[1].push(v);
      if (!ok() || (adj[u].size() == 2 && adj[u][0] == v)) {
	int w = getNext();
	adj[u].pop_back();
	adj[v].pop_back();
	if (adj[v].size() == 0) {
	  VI tmp;
	  while (pq[1].top() != v) {
	    tmp.PB(pq[1].top());
	    pq[1].pop();
	  }
	  pq[1].top();
	  for (int t : tmp) {
	    pq[1].push(t);
	  }
	}
	pq[adj[v].size()].push(v);
	adj[u].PB(w);
	adj[w].PB(u);
	if(adj[w].size() == 1) pq[1].push(w);
	v = w;
      }
      //cout << u << ' ' << v << endl;
      ans.PB(u);
      ans.PB(v);
    }
    return ans;
  }
};

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 

A simple graph is an undirected graph in which each edge connects two different vertices and each pair of vertices is connected by at most one edge.
In other words, there are no self-loops and no multiple edges.




A 2-regular graph is a simple graph such that the degree of each vertex is 2.




You are given the int n and two vector <int>s x and y.
These variables describe a simple graph G on n vertices, labeled 0 through n-1.
For each valid i, the graph G contains an edge that connects the vertices x[i] and y[i].
It is guaranteed that each vertex in G has degree 2 or less.




You want to change G into a 2-regular graph by adding some edges.
Determine whether this can be done, and if yes, find the lexicographically smallest way of doing so.
A more precise definition of the task follows.




An encoding of a set of k edges is any vector <int> E of length 2k such that the set of edges is equal to the set { (E[0], E[1]), (E[2], E[3]), ... }.
For example, suppose you have the edges (1,7) and (2,5).
Then {1,7,5,2} and {2,5,1,7} are two of the valid encodings.
On the other hand, {1,2,5,7} is not a valid encoding.




If changing G into a 2-regular graph is impossible, return the vector <int> {-1}, i.e., an array that contains only one integer, -1.
Otherwise, find and return the lexicographically smallest encoding of a set of edges that should be added to G in order to make it 2-regular.


DEFINITION
Class:MakingRegularGraph
Method:addEdges
Parameters:int, vector <int>, vector <int>
Returns:vector <int>
Method signature:vector <int> addEdges(int n, vector <int> x, vector <int> y)


NOTES
-Given two different vector <int>s S and T with the same number of elements, the lexicographically smaller one is the one that has a smaller element at the first index at which they differ.


CONSTRAINTS
-n will be between 1 and 1,000, inclusive.
-x will contain between 0 and n-1 elements, inclusive.
-y will contain the same number of elements as x.
-Each element of x will be between 0 and n-2, inclusive.
-Each element of y will be between 1 and n-1, inclusive.
-x[i] < y[i] will hold for all i (i.e., no self-loops).
-In a graph described by n, x, and y, every vertex will have degree 2 or less (For every integer v between 0 and n-1, v appears at most twice in x and y combined).
-In a graph described by n, x, and y, there will be at most one edge between a pair of vertices (two equalities (x[i] = x[j] and y[i] = y[j]) will hold only when i = j).


EXAMPLES

0)
6
{0,2}
{2,3}

Returns: {0, 1, 1, 4, 3, 5, 4, 5 }

There are many ways to turn this G into a 2-regular graph. For example, you may:

add the edges (3, 4), (4, 5), (5, 1), (1, 0) to obtain one large cycle of length 6
add the edges (3, 5), (5, 4), (4, 1), (1, 0) to obtain another cycle of length 6
add the edges (0, 3), (1, 4), (4, 5), (1, 5) to obtain two cycles of length 3 each
...


Each of these options has multiple encodings.
The return value shown above is the lexicographically smallest out of all encodings of all options.
It corresponds to the second set of edges listed above.

1)
4
{1,2,1}
{2,3,3}

Returns: {-1 }

The given graph contains a cycle of length 3 and an isolated vertex.
Unfortunately, we cannot turn this into a 2-reguglar graph.


2)
3
{}
{}

Returns: {0, 1, 0, 2, 1, 2 }

x and y can be empty, meaning there are no edges present.
In this example, there is a unique set of edges we can add in order to create a 2-regular graph: (0, 1), (0, 2), and (1, 2).
However, there exist many different ways to describe these three edges. 
For instance, both {0, 1, 2, 0, 2, 1} and {0, 1, 0, 2, 1, 2} describe the same set of edges.
Recall that you must return the one that comes lexicographically first. 


3)
5
{0}
{4}

Returns: {0, 1, 1, 2, 2, 3, 3, 4 }



4)
5
{2}
{3}

Returns: {0, 1, 0, 2, 1, 4, 3, 4 }



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
		cout << "Testing MakingRegularGraph (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1527955687;
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
		MakingRegularGraph _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 6;
				int x[] = {0,2};
				int y[] = {2,3};
				int __expected[] = {0, 1, 1, 4, 3, 5, 4, 5 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.addEdges(n, vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 1:
			{
				int n = 4;
				int x[] = {1,2,1};
				int y[] = {2,3,3};
				int __expected[] = {-1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.addEdges(n, vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 2:
			{
				int n = 3;
				int x[] = {};
				int y[] = {};
				int __expected[] = {0, 1, 0, 2, 1, 2 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.addEdges(n, vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 3:
			{
				int n = 5;
				int x[] = {0};
				int y[] = {4};
				int __expected[] = {0, 1, 1, 2, 2, 3, 3, 4 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.addEdges(n, vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 4:
			{
				int n = 5;
				int x[] = {2};
				int y[] = {3};
				int __expected[] = {0, 1, 0, 2, 1, 4, 3, 4 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.addEdges(n, vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			/*case 5:
			{
				int n = ;
				int x[] = ;
				int y[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.addEdges(n, vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int n = ;
				int x[] = ;
				int y[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.addEdges(n, vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int n = ;
				int x[] = ;
				int y[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.addEdges(n, vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
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
