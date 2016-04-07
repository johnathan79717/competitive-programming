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
#define ALL(x) (x).begin(),(x).end()
#define VI vector<int>
#define PB push_back
 
struct Ethernet {
	int dfs(int u) {
		VI children;
		REP1(i, 1, N-1) {
			if(parent[i-1] == u) {
				children.PB(dist[i-1] + dfs(i));
			}
		}
		children.PB(0);
		sort(ALL(children));
		while(children.back() > maxDist) {
			children.pop_back();
			ans++;
		}
		while(children.size() > 1 && children[children.size()-2] + children.back() > maxDist) {
			children.pop_back();
			ans++;  			
		}
		return children.back();
	};
	VI parent, dist;
	int maxDist, ans, N;
  int connect(vector <int> parent, vector <int> dist, int maxDist) {
  	ans = 1; N = parent.size()+1;
  	this->maxDist = maxDist;
  	this->parent = parent;
  	this->dist = dist;
  	dfs(0);
  	return ans;
  }
};

// BEGIN CUT HERE
/*
PROBLEM STATEMENT
You have N computers numbered 0 through N-1.
They are connected into a single network.
The topology of the network is a tree.
You are given its description as vector <int>s parent and 
dist.
Each of the vector <int>s contains exactly N-1 elements.
For each i between 0 and N-2, inclusive, there is a cable 
connecting computers i+1 and parent[i], and the length of 
that cable is dist[i].

You are also given an int maxDist with the following 
meaning:
The distance between any two computers in the same network 
must not exceed maxDist.
(The distance between two computers is defined as the 
total length of cable between them.)
If this is currently not the case for your network, you 
have to divide it into several smaller networks.

Formally, it means that you need to choose the number K of 
smaller networks you will have.
Then you need to assign each of your computers into 
exactly one of the K networks.
The following properties must be satisfied:

Each of the K new networks must form a connected subtree 
of the original tree.
The diameter of each new network must be at most maxDist.

Return the smallest value of K for which it is possible to 
divide the original network into K new networks with the 
above properties.


DEFINITION
Class:Ethernet
Method:connect
Parameters:vector <int>, vector <int>, int
Returns:int
Method signature:int connect(vector <int> parent, vector 
<int> dist, int maxDist)


CONSTRAINTS
-parent will contain between 1 and 50 elements, inclusive.
-dist will contain the same number of elements as parent.
-For each valid i, the i-th element of parent will be 
between 0 and i, inclusive.
-Each element of dist will be between 1 and 500, inclusive.
-maxDist will be between 1 and 500, inclusive.


EXAMPLES

0)
{0,0,0}
{1,1,1}
2

Returns: 1

The diameter of this network is 2, which is small enough.

1)
{0,0,0,0,0,0,0}
{1,2,3,4,5,6,7}
8

Returns: 4

One optimal solution: the new networks will be formed by 
computers {4}, {6}, {7}, and {0,1,2,3,5}.

2)
{0,1,2,3,4,5}
{1,2,3,4,5,6}
6

Returns: 3

One optimal solution is to put computers {0,1,2,3} into 
the first new network, {4,5} into the second one, and {6} 
will be the third network.

3)
{0,0,0,1,1}
{1,1,1,1,1}
2

Returns: 2

The two new networks can be {0,2,3} and {1,4,5}.

4)
{0,1,0,3,0,5,0,6,0,6,0,6,4,6,9,4,5,5,2,5,2}
{93,42,104,105,59,73,161,130,30,81,62,93,131,133,139,5,13,34,25,111,4}

162

Returns: 11



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
		cout << "Testing Ethernet (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1401326632;
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
		Ethernet _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int parent[] = {0,0,0};
				int dist[] = {1,1,1};
				int maxDist = 2;
				_expected = 1;
				_received = _obj.connect(vector <int>(parent, parent+sizeof(parent)/sizeof(int)), vector <int>(dist, dist+sizeof(dist)/sizeof(int)), maxDist); break;
			}
			case 1:
			{
				int parent[] = {0,0,0,0,0,0,0};
				int dist[] = {1,2,3,4,5,6,7};
				int maxDist = 8;
				_expected = 4;
				_received = _obj.connect(vector <int>(parent, parent+sizeof(parent)/sizeof(int)), vector <int>(dist, dist+sizeof(dist)/sizeof(int)), maxDist); break;
			}
			case 2:
			{
				int parent[] = {0,1,2,3,4,5};
				int dist[] = {1,2,3,4,5,6};
				int maxDist = 6;
				_expected = 3;
				_received = _obj.connect(vector <int>(parent, parent+sizeof(parent)/sizeof(int)), vector <int>(dist, dist+sizeof(dist)/sizeof(int)), maxDist); break;
			}
			case 3:
			{
				int parent[] = {0,0,0,1,1};
				int dist[] = {1,1,1,1,1};
				int maxDist = 2;
				_expected = 2;
				_received = _obj.connect(vector <int>(parent, parent+sizeof(parent)/sizeof(int)), vector <int>(dist, dist+sizeof(dist)/sizeof(int)), maxDist); break;
			}
			case 4:
			{
				int parent[] = {0,1,0,3,0,5,0,6,0,6,0,6,4,6,9,4,5,5,2,5,2};
				int dist[] = {93,42,104,105,59,73,161,130,30,81,62,93,131,133,139,5,13,34,25,111,4};
				int maxDist = 162;
				_expected = 11;
				_received = _obj.connect(vector <int>(parent, parent+sizeof(parent)/sizeof(int)), vector <int>(dist, dist+sizeof(dist)/sizeof(int)), maxDist); break;
			}
			/*case 5:
			{
				int parent[] = ;
				int dist[] = ;
				int maxDist = ;
				_expected = ;
				_received = _obj.connect(vector <int>(parent, parent+sizeof(parent)/sizeof(int)), vector <int>(dist, dist+sizeof(dist)/sizeof(int)), maxDist); break;
			}*/
			/*case 6:
			{
				int parent[] = ;
				int dist[] = ;
				int maxDist = ;
				_expected = ;
				_received = _obj.connect(vector <int>(parent, parent+sizeof(parent)/sizeof(int)), vector <int>(dist, dist+sizeof(dist)/sizeof(int)), maxDist); break;
			}*/
			/*case 7:
			{
				int parent[] = ;
				int dist[] = ;
				int maxDist = ;
				_expected = ;
				_received = _obj.connect(vector <int>(parent, parent+sizeof(parent)/sizeof(int)), vector <int>(dist, dist+sizeof(dist)/sizeof(int)), maxDist); break;
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
