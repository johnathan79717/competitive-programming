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

struct DoubleTree {
  int maximalScore(vector <int> a, vector <int> b, vector <int> c, vector <int> d, vector <int> score) {

  }
};

// BEGIN CUT HERE
/*
PROBLEM STATEMENT
You have two trees with the same number of nodes.
The nodes in each tree are labeled 0 through n-1.



You are given four vector <int>s with n-1 elements each: 
a, b, c, and d.
The vector <int>s a and b describe the first tree:
for each valid i, the first tree contains an edge between 
nodes labeled a[i] and b[i].
The vector <int>s c and d describe the second tree in the 
same way.



Each of the values 0 through n-1 has an assigned integer 
score.
These scores are given in an vector <int> score.
Note that some of the scores may be negative.



Your goal is to select a subset S of the set {0, 1, ..., n-
1} with the following properties:

In the first tree, the nodes with the labels in S induce a 
connected subgraph (a subtree of the original tree).
In the second tree, the nodes with the labels in S also 
induce a connected subgraph.




Return the largest possible sum of scores assigned to the 
elements of such a subset S.

DEFINITION
Class:DoubleTree
Method:maximalScore
Parameters:vector <int>, vector <int>, vector <int>, 
vector <int>, vector <int>
Returns:int
Method signature:int maximalScore(vector <int> a, vector 
<int> b, vector <int> c, vector <int> d, vector <int> score)


NOTES
-As there are only finitely many possible subsets S and 
the empty subset always has the desired properties, the 
return value is always correctly defined.


CONSTRAINTS
-n will be between 2 and 50, inclusive.
-a and b will describe a tree with exactly n ndoes.
-c and d will describe a tree with exactly n ndoes.
-score will contain exactly n elements.
-Each element in score will be between -1,000 and 1,000, 
inclusive.


EXAMPLES

0)
{0,0,1}
{1,3,2}
{0,0,3}
{1,3,2}
{1000,24,100,-200}

Returns: 1024

The best subset we can choose is {0,1}.
The nodes labeled 0 and 1 are connected by an edge in each 
of the trees.
Note that we cannot choose {0,1,2} as in the second tree 
we cannot get from 0 to 2 without going through 3.

1)
{0,0,1}
{1,3,2}
{0,0,3}
{1,3,2}
{1000,24,100,200}

Returns: 1324

As in this case all scores are positive, the best solution 
is to select all labels.

2)
{0,0,1}
{1,3,2}
{0,0,3}
{1,3,2}
{-1000,-24,-100,-200}

Returns: 0

As in this case all scores are negative, the best solution 
is to select no labels at all.

3)
{0,0,1}
{1,3,2}
{0,0,3}
{1,3,2}
{-1000,24,100,200}

Returns: 200

The optimal solution is to choose the subset {3} - a 
single node is connected.

4)
{0,0,1,1,2,2}
{1,2,3,4,5,6}
{0,0,1,1,2,2}
{1,2,3,4,5,6}
{-3,2,2,-1,2,2,-1}

Returns: 5

In this test case the two trees are identical. The answer 
is the maximum score of a subtree of this tree.

5)
{0,0,1,1,2,2}
{1,2,3,4,5,6}
{0,0,0,0,0,0}
{1,2,3,4,5,6}
{-3,2,2,-1,2,2,-1}

Returns: 5



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
		cout << "Testing DoubleTree (600.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1410968409;
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
		DoubleTree _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int a[] = {0,0,1};
				int b[] = {1,3,2};
				int c[] = {0,0,3};
				int d[] = {1,3,2};
				int score[] = {1000,24,100,-200};
				_expected = 1024;
				_received = _obj.maximalScore(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(c, c+sizeof(c)/sizeof(int)), vector <int>(d, d+sizeof(d)/sizeof(int)), vector <int>(score, score+sizeof(score)/sizeof(int))); break;
			}
			case 1:
			{
				int a[] = {0,0,1};
				int b[] = {1,3,2};
				int c[] = {0,0,3};
				int d[] = {1,3,2};
				int score[] = {1000,24,100,200};
				_expected = 1324;
				_received = _obj.maximalScore(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(c, c+sizeof(c)/sizeof(int)), vector <int>(d, d+sizeof(d)/sizeof(int)), vector <int>(score, score+sizeof(score)/sizeof(int))); break;
			}
			case 2:
			{
				int a[] = {0,0,1};
				int b[] = {1,3,2};
				int c[] = {0,0,3};
				int d[] = {1,3,2};
				int score[] = {-1000,-24,-100,-200};
				_expected = 0;
				_received = _obj.maximalScore(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(c, c+sizeof(c)/sizeof(int)), vector <int>(d, d+sizeof(d)/sizeof(int)), vector <int>(score, score+sizeof(score)/sizeof(int))); break;
			}
			case 3:
			{
				int a[] = {0,0,1};
				int b[] = {1,3,2};
				int c[] = {0,0,3};
				int d[] = {1,3,2};
				int score[] = {-1000,24,100,200};
				_expected = 200;
				_received = _obj.maximalScore(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(c, c+sizeof(c)/sizeof(int)), vector <int>(d, d+sizeof(d)/sizeof(int)), vector <int>(score, score+sizeof(score)/sizeof(int))); break;
			}
			case 4:
			{
				int a[] = {0,0,1,1,2,2};
				int b[] = {1,2,3,4,5,6};
				int c[] = {0,0,1,1,2,2};
				int d[] = {1,2,3,4,5,6};
				int score[] = {-3,2,2,-1,2,2,-1};
				_expected = 5;
				_received = _obj.maximalScore(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(c, c+sizeof(c)/sizeof(int)), vector <int>(d, d+sizeof(d)/sizeof(int)), vector <int>(score, score+sizeof(score)/sizeof(int))); break;
			}
			case 5:
			{
				int a[] = {0,0,1,1,2,2};
				int b[] = {1,2,3,4,5,6};
				int c[] = {0,0,0,0,0,0};
				int d[] = {1,2,3,4,5,6};
				int score[] = {-3,2,2,-1,2,2,-1};
				_expected = 5;
				_received = _obj.maximalScore(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(c, c+sizeof(c)/sizeof(int)), vector <int>(d, d+sizeof(d)/sizeof(int)), vector <int>(score, score+sizeof(score)/sizeof(int))); break;
			}
			/*case 6:
			{
				int a[] = ;
				int b[] = ;
				int c[] = ;
				int d[] = ;
				int score[] = ;
				_expected = ;
				_received = _obj.maximalScore(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(c, c+sizeof(c)/sizeof(int)), vector <int>(d, d+sizeof(d)/sizeof(int)), vector <int>(score, score+sizeof(score)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int a[] = ;
				int b[] = ;
				int c[] = ;
				int d[] = ;
				int score[] = ;
				_expected = ;
				_received = _obj.maximalScore(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(c, c+sizeof(c)/sizeof(int)), vector <int>(d, d+sizeof(d)/sizeof(int)), vector <int>(score, score+sizeof(score)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int a[] = ;
				int b[] = ;
				int c[] = ;
				int d[] = ;
				int score[] = ;
				_expected = ;
				_received = _obj.maximalScore(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(c, c+sizeof(c)/sizeof(int)), vector <int>(d, d+sizeof(d)/sizeof(int)), vector <int>(score, score+sizeof(score)/sizeof(int))); break;
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
