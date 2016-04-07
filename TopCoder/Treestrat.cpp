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
#define PB push_back
#define V(T) vector<T >

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;
#line 28 "Treestrat.cpp"
#include <string>
#include <vector>

V(VI) adj;
int parent[51][51];

void dfs(int root, int v, int p) {
    parent[root][v] = p;
    if (p < 0) {
        parent[root][v] = v;
    }
    for (int u: adj[v]) {
        if (u != p)
            dfs(root, u, v);
    }
}

int N;
class Treestrat {
public:
    int roundcnt(vector <int> tree, vector <int> A, vector <int> B) {
        N = tree.size() + 1;
        adj = V(VI)(N);
        REP(i, N-1) {
            adj[i+1].PB(tree[i]);
            adj[tree[i]].PB(i+1);
        }
        REP(root, N) {
            dfs(root, root, -1);
        }
        int ans = INT_MAX;
        for (int a: A) {
            int cnt = 0;
            REP(dest, N) {
                cnt = max(cnt, chase(a, dest, B));
            }
            ans = min(ans, cnt);
        }
        return ans;
    }
    int chase(int a, int dest, VI B) {
        int cnt = 0;
        while (true) {
            cnt++;
            a = parent[dest][a];
            bool end = false;
            for (int &b: B) {
                b = parent[a][b];
                if (b == a) {
                    end = true;
                    break;
                }
            }
            if (end) break;
        }
        return cnt;
    }
};
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Two players are playing a game with some tokens on a tree.
Player A has one or more red tokens.
Player B has one or more blue tokens.
Initially, each vertex of the tree is either empty or contains exactly one token (either a red one or a blue one, not both).
During the game there can be arbitrarily many tokens of each color in each vertex.

You are given the description of the initial state of the game.
More precisely, you are given the vector <int>s tree, A, and B.
The length of tree is n-1, where n is the number of vertices in the tree.
The vertices in the tree are numbered 0 through n-1.
For each i between 1 and n-1, inclusive, there is an edge between the vertices i and tree[i-1].
The elements of A are the numbers of vertices that initially contain player A's tokens.
The elements of B are the vertices with player B's tokens.

The game is played in rounds.
Each round consists of two phases.
In the first phase player A may move some of his tokens, and in the second phase player B may move some of her tokens.
More precisely, the current player always examines all of their tokens, and for each of them the player either decides to keep it in its current vertex, or decides to move it to one of the adjacent vertices.

Player B wins if after some round there is a vertex that contains both a red and a blue token.
(There can even be multiple red or blue tokens in that vertex.)
Player B wants to win in as few rounds as possible.
Player A wants the game to go for as many rounds as possible.
Assume that both players play the game optimally.
Compute and return the number of rounds the game will take.

Note that it can be shown that the answer is always finite: player B always has a winning strategy.
Also note that you are supposed to return the number of rounds, not the total number of phases.

DEFINITION
Class:Treestrat
Method:roundcnt
Parameters:vector <int>, vector <int>, vector <int>
Returns:int
Method signature:int roundcnt(vector <int> tree, vector <int> A, vector <int> B)


CONSTRAINTS
-tree will contain n - 1 element.
-n will be between 2 and 50, inclusive.
-i-th elements in tree will be between 0 and i, inclusive.
-A will contain between 1 and 50 elements, inclusive.
-B will contain between 1 and 50 elements, inclusive.
-Each element in A and B will be between 0 and n - 1, inclusive.
-No element will occur more than once in the concatenation of A and B.


EXAMPLES

0)
{0}
{0}
{1}

Returns: 1

This is a tree with a single edge 0-1.
Initially there is a red token in vertex 0 and a blue token in vertex 1.
Regardless of where player A moves the red token, player B can move the blue token to the same vertex and win.

1)
{0,1}
{1}
{2}

Returns: 2

This tree is a line that consists of two edges: 0-1 and 1-2.
We start with a red token on vertex 1 and a blue token on vertex 2.
Player A's optimal strategy is to start by moving his token into vertex 0.
Player B will then move her token into vertex 1.
In the second round player B will then win the game in the same way as in Example 0.

2)
{0,0,0,3,4}
{2}
{1}

Returns: 2



3)
{0,0,0,3,4,2}
{1}
{6}

Returns: 5



4)
{0,0,0,3,4,2}
{1}
{6,5}

Returns: 3



5)
{0,0,0,3,4,2}
{4,1}
{3,6}

Returns: 2



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
		cout << "Testing Treestrat (450.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1444493734;
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
		Treestrat _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int tree[] = {0};
				int A[] = {0};
				int B[] = {1};
				_expected = 1;
				_received = _obj.roundcnt(vector <int>(tree, tree+sizeof(tree)/sizeof(int)), vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int))); break;
			}
			case 1:
			{
				int tree[] = {0,1};
				int A[] = {1};
				int B[] = {2};
				_expected = 2;
				_received = _obj.roundcnt(vector <int>(tree, tree+sizeof(tree)/sizeof(int)), vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int))); break;
			}
			case 2:
			{
				int tree[] = {0,0,0,3,4};
				int A[] = {2};
				int B[] = {1};
				_expected = 2;
				_received = _obj.roundcnt(vector <int>(tree, tree+sizeof(tree)/sizeof(int)), vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int))); break;
			}
			case 3:
			{
				int tree[] = {0,0,0,3,4,2};
				int A[] = {1};
				int B[] = {6};
				_expected = 5;
				_received = _obj.roundcnt(vector <int>(tree, tree+sizeof(tree)/sizeof(int)), vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int))); break;
			}
			case 4:
			{
				int tree[] = {0,0,0,3,4,2};
				int A[] = {1};
				int B[] = {6,5};
				_expected = 3;
				_received = _obj.roundcnt(vector <int>(tree, tree+sizeof(tree)/sizeof(int)), vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int))); break;
			}
			case 5:
			{
				int tree[] = {0,0,0,3,4,2};
				int A[] = {4,1};
				int B[] = {3,6};
				_expected = 2;
				_received = _obj.roundcnt(vector <int>(tree, tree+sizeof(tree)/sizeof(int)), vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int))); break;
			}
			/*case 6:
			{
				int tree[] = ;
				int A[] = ;
				int B[] = ;
				_expected = ;
				_received = _obj.roundcnt(vector <int>(tree, tree+sizeof(tree)/sizeof(int)), vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int tree[] = ;
				int A[] = ;
				int B[] = ;
				_expected = ;
				_received = _obj.roundcnt(vector <int>(tree, tree+sizeof(tree)/sizeof(int)), vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int tree[] = ;
				int A[] = ;
				int B[] = ;
				_expected = ;
				_received = _obj.roundcnt(vector <int>(tree, tree+sizeof(tree)/sizeof(int)), vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int))); break;
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
