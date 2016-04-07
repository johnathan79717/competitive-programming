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
#define ALL(x) (x).begin(),(x).end()
#define FOR(i, c) for(auto &i: c)
#define V(T) vector<T >
typedef vector<int> VI;

class Graph {
  int V;
  struct edge { int to, cap, rev; };
  vector<vector<edge> > G;
  vector<bool> used;
  VI level, iter;
  void bfs() {
    fill(ALL(level), -1);
    queue<int> que;
    level[source] = 0;
    que.push(source);
    while(!que.empty()) {
      int v = que.front(); que.pop();
      FOR(e, G[v]) {
        if(e.cap > 0 && level[e.to] < 0) {
          level[e.to] = level[v] + 1;
          que.push(e.to);
        }
      }
    }
  }
  int dfs(int v, int f) {
    if(v == sink) return f;
    for(int &i = iter[v]; i < G[v].size(); i++) {
      edge &e = G[v][i];
      if(e.cap > 0 && level[v] < level[e.to]) {
        int d = dfs(e.to, min(f, e.cap));
        if(d > 0) {
          e.cap -= d;
          G[e.to][e.rev].cap += d;
          return d;
        }
      }
    }
    return 0;
  }
public:
  int source, sink;
  Graph() { V = 0; source = addVertex(); sink = addVertex(); }
  int addVertex() {
    G.resize(V+1);
    return V++;
  }
  void addEdge(int from, int to, int cap) {
    G[from].push_back((edge){to, cap, (int)G[to].size()});
    G[to].push_back((edge){from, 0, (int)G[from].size() - 1});
  }
  int maxFlow() {
    int flow = 0;
    level.resize(V);
    iter.resize(V);
    for (;;) {
      bfs();
      if(level[sink] < 0) return flow;
      fill(ALL(iter), 0);
      int f;
      while((f = dfs(source, INT_MAX)) > 0) {
        flow += f;
      }
    }
    return flow;
  }
};
const int INF = 2501;
struct BlockTheBlockPuzzle {
  int minimumHoles(vector <string> b) {
  	int n = b.size(), x, y;
  	REP(i, n) REP(j, n) {
  		if(b[i][j] == '$') {
  			x = i;
  			y = j;
  		}
  	}
  	Graph g;
  	V(VI) in(n, VI(n, -1)), out(n, VI(n, -1));
  	REP(i, n) {
  		if(i % 3 != x % 3) continue;
  		REP(j, n) {
  			if(j % 3 != y % 3) continue;
  			if(b[i][j] == 'H') continue;
  			in[i][j] = g.addVertex();
  			out[i][j] = g.addVertex();
  			if(b[i][j] == '$' || b[i][j] == 'b')
  				g.addEdge(in[i][j], out[i][j], INF);
  			else
  				g.addEdge(in[i][j], out[i][j], 1);
  			if(b[i][j] == '$')
  				g.addEdge(g.source, in[i][j], INF);
  			if(b[i][j] == 'b')
  				g.addEdge(out[i][j], g.sink, INF);
  			if(i >= 3 && in[i-3][j] >= 0 && (b[i-1][j] != 'H' || b[i-2][j] != 'H')) {
  				int tin = g.addVertex(), tout = g.addVertex();
  				int c = 2;
  				if(b[i-1][j] == 'b' || b[i-2][j] == 'b')
  					c = INF;
  				else {
  					if(b[i-1][j] == 'H' || b[i-2][j] == 'H')
  						c = 1;
  				}
  				g.addEdge(tin, tout, c);
  				g.addEdge(out[i][j], tin, INF);
  				g.addEdge(out[i-3][j], tin, INF);
  				g.addEdge(tout, in[i-3][j], INF);
  				g.addEdge(tout, in[i][j], INF);
  			}
  			if(j >= 3 && in[i][j-3] >= 0 && (b[i][j-1] != 'H' || b[i][j-2] != 'H')) {
  				int tin = g.addVertex(), tout = g.addVertex();
  				int c = 2;
  				if(b[i][j-1] == 'b' || b[i][j-2] == 'b')
  					c = INF;
  				else {
  					if(b[i][j-1] == 'H' || b[i][j-2] == 'H')
  						c = 1;
  				}
  				g.addEdge(tin, tout, c);
  				g.addEdge(out[i][j], tin, INF);
  				g.addEdge(out[i][j-3], tin, INF);
  				g.addEdge(tout, in[i][j-3], INF);
  				g.addEdge(tout, in[i][j], INF);
  			}
  		}
  	}
  	int ans = g.maxFlow();
  	if(ans >= INF) return -1;
  	else return ans;
  }
};

// BEGIN CUT HERE
/*
PROBLEM STATEMENT
Block Puzzle is played on a square grid of unit cells. 
Some of those cells are marked as start cells, and one is 
marked as a goal cell.

The player begins by placing a 1x1x2 block on top of one 
of the start cells in such a way that the 1x1 face of the 
block coincides with the cell.
The goal of the game is to reach the state where the block 
stands with its 1x1 face covering the goal cell.
The game is played by rolling the block across the board.
Only some types of moves are allowed:
When the block stands on its 1x1 face, the player may roll 
the block in either of the four basic directions.
However, when the block's bottom face is 2x1, the player 
may only roll it onto one of its 1x1 faces.
In other words, the block must always be rolled over an 
edge of length 1.

All allowed moves are shown in the figure below. (The old 
state of the block is always semi-transparent, the new 
state is opaque.)



So far, the game seems trivial.
Its difficulty comes from the fact that there are holes 
instead of some cells.
Whenever the entire bottom face of the block stands on a 
hole, the block falls through the hole and the player 
loses the game. The block also falls off if the player 
rolls it across the edge of the game board.
(Note that if the block stands on a 2x1 face and only one 
of the two cells under the face is missing, the block is 
still safe.
Technically, the block would also be safe with one half of 
its bottom face sticking out of the game board, but 
obviously a move into such a configuration will never help 
you reach the goal.)

Bohn has been playing Block Puzzle too much. Jrus is 
bored, so he decided to make Bohn's game unsolvable by 
making more holes into his board.
Jrus can only remove cells that are neither starting nor 
goal. As he doesn't want to get caught, he wants to remove 
as few cells as possible.

You are given the current board as a vector <string> board.
The character '.' represents an ordinary cell, 'H' is a 
hole, 'b' is a starting cell, and '$' is the only goal cell.
Return the smallest number of cells that have to be 
removed in order to make the puzzle unsolvable.
If it is not possible to make the puzzle unsolvable, 
return -1 instead.





DEFINITION
Class:BlockTheBlockPuzzle
Method:minimumHoles
Parameters:vector <string>
Returns:int
Method signature:int minimumHoles(vector <string> board)


CONSTRAINTS
-n will be between 3 and 50, inclusive.
-board will contain exactly n elements.
-Each element of board will contain exactly n characters.
-Each character in board will be '.', 'H', 'b' or '$'.
-board will contain exactly one '$' character.
-board will contain at least one 'b' character.


EXAMPLES

0)
{"b..$",
 "....",
 "HHHH",
 "HHHH"}

Returns: 2

Remove the two cells between the start and the goal. Note 
that removing just one of them is not enough.

1)
{"............H..",
 "...............",
 "...............",
 "HHH$HHH.....H..",
 "HHHHHHH........",
 "HHHHHHHH.......",
 "......b..H.....",
 "...............",
 "...............",
 "...H..H..H.....",
 "...............",
 "...............",
 "...............",
 "...............",
 "..............."}

Returns: 0

This puzzle is already unsolvable.

2)
{"............H..",
 "...............",
 "...............",
 "HHH$HHH........",
 "HHHHHHH........",
 "HHHHHHHH.......",
 "......b..H.....",
 "...............",
 "...............",
 "...H..H..H.....",
 "...............",
 "...............",
 "...............",
 "...............",
 "..............."}

Returns: 1

This puzzle is solvable. The only difference between this 
puzzle and Example 1 is that one cell in this example was 
a hole in Example 1. Hence, we can easily make this puzzle 
unsolvable by removing that one cell.

3)
{"b..$...",
 "...H...",
 ".......",
 "b..b..b",
 "...H...",
 ".......",
 "b..b..b"}



Returns: 4

A puzzle may contain multiple starting cells. Bohn may 
start the game from any of them.

4)
{"b..b..b",
 "..b..b.",
 ".......",
 "b..$bbb",
 ".b.....",
 "....b..",
 "b..b..b"}


Returns: -1

You cannot replace start cells with holes.

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
		cout << "Testing BlockTheBlockPuzzle (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1403176457;
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
		BlockTheBlockPuzzle _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string board[] = {"b..$",
				                  "....",
				                  "HHHH",
				                  "HHHH"};
				_expected = 2;
				_received = _obj.minimumHoles(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 1:
			{
				string board[] = {"............H..",
				                  "...............",
				                  "...............",
				                  "HHH$HHH.....H..",
				                  "HHHHHHH........",
				                  "HHHHHHHH.......",
				                  "......b..H.....",
				                  "...............",
				                  "...............",
				                  "...H..H..H.....",
				                  "...............",
				                  "...............",
				                  "...............",
				                  "...............",
				                  "..............."};
				_expected = 0;
				_received = _obj.minimumHoles(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 2:
			{
				string board[] = {"............H..",
				                  "...............",
				                  "...............",
				                  "HHH$HHH........",
				                  "HHHHHHH........",
				                  "HHHHHHHH.......",
				                  "......b..H.....",
				                  "...............",
				                  "...............",
				                  "...H..H..H.....",
				                  "...............",
				                  "...............",
				                  "...............",
				                  "...............",
				                  "..............."};
				_expected = 1;
				_received = _obj.minimumHoles(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 3:
			{
				string board[] = {"b..$...",
				                  "...H...",
				                  ".......",
				                  "b..b..b",
				                  "...H...",
				                  ".......",
				                  "b..b..b"};
				_expected = 4;
				_received = _obj.minimumHoles(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 4:
			{
				string board[] = {"b..b..b",
				                  "..b..b.",
				                  ".......",
				                  "b..$bbb",
				                  ".b.....",
				                  "....b..",
				                  "b..b..b"};
				_expected = -1;
				_received = _obj.minimumHoles(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			/*case 5:
			{
				string board[] = ;
				_expected = ;
				_received = _obj.minimumHoles(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string board[] = ;
				_expected = ;
				_received = _obj.minimumHoles(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string board[] = ;
				_expected = ;
				_received = _obj.minimumHoles(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
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
