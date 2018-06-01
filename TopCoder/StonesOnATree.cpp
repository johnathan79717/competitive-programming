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

#line 40 "StonesOnATree.cpp"
#include <string>
#include <vector>
class StonesOnATree {
public:
  int minStones(vector <int> p, vector <int> w) {

  }
};

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
You are given a rooted tree with n nodes.
The nodes are labeled from 0 to n-1.
Node 0 is the root.
Each node of the tree has at most two children.




You are given the description of the tree: the vector <int>s p and w.
The vector <int> p has n-1 elements.
For each valid i, node p[i] is the parent of node (i+1).
You may assume that for each i we have p[i] ≤ i.
The vector <int> w has n elements.
For each valid i, w[i] is the weight of node i.





The vector <int> w has a special property: it is non-decreasing.
That is, for each valid i we have w[i-1] ≤ w[i].





All nodes of the tree are currently empty.
You are now going to play a game with the tree and an unlimited supply of stones.
The game is played in turns.
In each turn you can either remove a single stone from anywhere into a tree, or you can place a single stone onto a node of the tree.
However, there is a restriction on placing the stones:
you may only place a stone onto a node if all of its children currently have stones placed on them.
(Note that this means that you can always place a stone onto any leaf of the tree.)





The weight of a given state of the game is equal to the sum of weights of nodes with stones.





You win the game by placing a stone onto the root of the tree.
You want to win the game.
If there are multiple ways to do so, you prefer a way for which the maximum weight of a state during the game is minimized.
Compute and return this weight.
In other words, compute and return the smallest W for which there is a way to win the game such that during the game the total weight of nodes with stones never exceeds W.


DEFINITION
Class:StonesOnATree
Method:minStones
Parameters:vector <int>, vector <int>
Returns:int
Method signature:int minStones(vector <int> p, vector <int> w)


CONSTRAINTS
-p will have between 1 and 999 elements, inclusive. (Thus, the number of nodes is between 2 and 1,000, inclusive.)
-The i-th element of p will be between 0 and i, inclusive.
-In the given tree each node will have at most two children. In other words, each value will appear in p at most twice.
-w will have exactly len(p)+1 elements.
-Each element of w will be 1 and 10^5, inclusive.
-Elements of w will be non-decreasing.


EXAMPLES

0)
{0,1,2,3}
{1,2,2,4,4}

Returns: 8

There are five nodes in a line. 
Here, one optimal solution is as follows:


 Place stone on node 4 (weight = 4). 
 Place stone on node 3 (weight = 8). 
 Remove stone from node 4 (weight = 4). 
 Place stone on node 2 (weight = 6). 
 Place stone on node 1 (weight = 8). 
 Remove stone from node 2 (weight = 6). 
 Place stone on node 0 (weight = 7). 


The maximum weight over all states is 8. It can be shown there is no other sequence of moves that has a smaller maximum weight.

1)
{0,0}
{1,2,3}

Returns: 6

In order to be able to place a stone onto node 0 we have to place stones onto both of its children. Thus, at the end of the game each of these three nodes will have a stone.


2)
{0}
{100000,100000}

Returns: 200000



3)
{0,0,1,1,2,2}
{1,1,1,1,1,1,1}

Returns: 4



4)
{0,0,1,2,3,4,4,2,1,3,6,7}
{1,2,3,4,5,6,6,7,8,8,8,9,10}

Returns: 22



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
		cout << "Testing StonesOnATree (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1521294969;
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
		StonesOnATree _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int p[] = {0,1,2,3};
				int w[] = {1,2,2,4,4};
				_expected = 8;
				_received = _obj.minStones(vector <int>(p, p+sizeof(p)/sizeof(int)), vector <int>(w, w+sizeof(w)/sizeof(int))); break;
			}
			case 1:
			{
				int p[] = {0,0};
				int w[] = {1,2,3};
				_expected = 6;
				_received = _obj.minStones(vector <int>(p, p+sizeof(p)/sizeof(int)), vector <int>(w, w+sizeof(w)/sizeof(int))); break;
			}
			case 2:
			{
				int p[] = {0};
				int w[] = {100000,100000};
				_expected = 200000;
				_received = _obj.minStones(vector <int>(p, p+sizeof(p)/sizeof(int)), vector <int>(w, w+sizeof(w)/sizeof(int))); break;
			}
			case 3:
			{
				int p[] = {0,0,1,1,2,2};
				int w[] = {1,1,1,1,1,1,1};
				_expected = 4;
				_received = _obj.minStones(vector <int>(p, p+sizeof(p)/sizeof(int)), vector <int>(w, w+sizeof(w)/sizeof(int))); break;
			}
			case 4:
			{
				int p[] = {0,0,1,2,3,4,4,2,1,3,6,7};
				int w[] = {1,2,3,4,5,6,6,7,8,8,8,9,10};
				_expected = 22;
				_received = _obj.minStones(vector <int>(p, p+sizeof(p)/sizeof(int)), vector <int>(w, w+sizeof(w)/sizeof(int))); break;
			}
			/*case 5:
			{
				int p[] = ;
				int w[] = ;
				_expected = ;
				_received = _obj.minStones(vector <int>(p, p+sizeof(p)/sizeof(int)), vector <int>(w, w+sizeof(w)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int p[] = ;
				int w[] = ;
				_expected = ;
				_received = _obj.minStones(vector <int>(p, p+sizeof(p)/sizeof(int)), vector <int>(w, w+sizeof(w)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int p[] = ;
				int w[] = ;
				_expected = ;
				_received = _obj.minStones(vector <int>(p, p+sizeof(p)/sizeof(int)), vector <int>(w, w+sizeof(w)/sizeof(int))); break;
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
