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

class Graph {
	typedef pair<int, int> P;
	int V;
	struct edge { int to, cap, cost, rev; };
	vector<vector<edge> > G;
public:
	int source, sink;
	Network() { V = 0; }
	int addVertex() {
		G.resize(V+1);
		return V++;
	}
	void addEdge(int from, int to, int cap = 1, int cost = 0) {
		G[from].push_back((edge){to, cap, cost, G[to].size()});
		G[to].push_back((edge){from, 0, -cost, G[from].size() - 1});

	}
	pair<int,int> minCostFlow(int f=2e9) {
		int res = 0;
		vector<int> h(V), prevv(V), preve(V);
		while(f > 0) {
			priority_queue<P, vector<P>, greater<P> > que;
			vector<int> dist(V, 1e9);
			dist[source] = 0;
      que.push(P(0, source));
			while(!que.empty()) {
				P p = que.top(); que.pop();
				int v = p.second;
				if(dist[v] < p.first) continue;
				for(int i = 0; i < G[v].size(); i++) {
					edge &e = G[v][i];
					if(e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to]) {
						dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
						prevv[e.to] = v;
						preve[e.to] = i;
						que.push(P(dist[e.to], e.to));
					}
				}
			}
			if(dist[sink] == 1e9) {
				if(f > 1e9) return P(res, 2e9 - f);
				else return P(1e9, 0);
			}
			for(int v = 0; v < V; v++) {
				if(h[v] >= 1e9 || dist[v] >= 1e9)
					h[v] = 1e9;
				else
					h[v] += dist[v];
			}
			int d = f;
			for(int v = sink; v != source; v = prevv[v])
				d = min(d, G[prevv[v]][preve[v]].cap);
			f -= d;
			res += d * h[sink];
			for(int v = sink; v != source; v = prevv[v]) {
				edge &e = G[prevv[v]][preve[v]];
				e.cap -= d;
				G[v][e.rev].cap += d;
			}
		}
		return P(res, f);
	}
};

struct DirectionBoard {
	int getMinimum(vector <string> board) {
    int w = board.size(), h = board[0].size();
    // min-cost max flow solver not included :)
    // Let us assume network() defines a graph class
    // that solves min cost max flow for us.
    //
    // network::addVertex() adds a vertex to the graph and
    // returns a  unique integer id  for it.
    //
    // network::addEdge(x,y, capacity, cost):
    // Adds an edge from x to y, with a capacity and cost.
    //
    // network::minCostMaxFlow(flow, cost)  finds the max flow
    //                                     and its cost.
    Graph G;
    // prepare the network.
    int in[w][h];
    int out[w][h];
    G.source = G.addVertex();
    G.sink = G.addVertex();
    for (int i=0; i<w; i++) {
        for (int j=0; j<h; j++) {
            // origin (in[i][j]) and destination (out[i][j]) vertices
            // for this cell:
            in[i][j] = G.addVertex();
            out[i][j] = G.addVertex();
            //From source to in[i][j], an edge with capacity 1 and no cost
            G.addEdge(G.source, in[i][j], 1, 0);
            
            //From out[i][j] to sink, an edge with capacity 1 and no cost
            G.addEdge(out[i][j], G.sink, 1, 0);
        }
    }
    // These arrays describe each of the directions and the change in
    // coordinates they represent
    const string NAME = "ULDR";
    const int dx[4] = {0, -1, 0, 1};
    const int dy[4] = {-1, 0, 1, 0};
    
    for (int x=0; x<h; x++) {
        for (int y=0; y<w; y++) {
            for (int d=0; d<4; d++) {
                // Using direction d, we move from (x,y) to (nx,ny)
                int nx = (x + dx[d] + h) % h; // %h or %w because it is cyclic
                int ny = (y + dy[d] + w) % w;
                if (NAME[d] == board[y][x]) {
                    // If the direction is the one that is initially written
                    // the cost is 0.
                    G.addEdge( in[y][x], out[ny][nx], 1, 0);
                } else {
                    // Else the cost is 1 (Change the direction)
                    G.addEdge( in[y][x], out[ny][nx], 1, 1);
                }
            }
        }
    }
    return G.minCostFlow(w*h).first;
	}
};

// BEGIN CUT HERE
/*
PROBLEM STATEMENT
A direction board is a matrix filled with arrows. Each arrow occupies one cell and points in one of the four directions: left, right, down, up. Each cell has two coordinates (row, column), starting with (0, 0) in the top left corner. Given a starting cell (r, c), you can move through the board in the following way. First, check the arrow in cell (r, c). If it points left, move left of the current cell, i.e. into cell(r, c - 1). For the right arrow, move to (r, c + 1). Up goes to (r - 1, c) and down to (r + 1, c). Each row and column of the board is cyclic, so whenever the new cell is outside the board, you appear on the other side. For example, moving left from (3, 0) on a board of size 5 by 5 results in appearing in cell (3, 4).

You need a board such that for every starting cell you always return to it during the movement process. If the given board does not satisfy this condition, you can change the direction of the arrow in any cell. For example, look at the following boards. In the left one, one only returns to the initial cell when he begins in cells (1, 1), (1, 2), (2, 0), (2, 3). After redirecting two arrows, you obtain a board with the given property.



Find the minimum number of arrow redirections which transforms the given board into a valid one.

DEFINITION
Class:DirectionBoard
Method:getMinimum
Parameters:vector <string>
Returns:int
Method signature:int getMinimum(vector <string> board)


CONSTRAINTS
-board will contain between 1 and 15 elements, inclusive.
-Each element of board will contain between 1 and 15 characters, inclusive.
-All elements of board will be of the same length.
-Each element of board will consist of characters from the set {'L', 'R', 'U', 'D'} only.


EXAMPLES

0)
{"RRRD",
 "URDD",
 "UULD",
 "ULLL"}

Returns: 0

This board is already good. No matter which cell you start in, you always you return to it.

1)
{"RRRD",
 "URLL",
 "LRRR"}

Returns: 2

The example from the problem statement.

2)
{"RRD",
 "URD",
 "ULL"}

Returns: 2

This board is not valid, because if one starts from (1, 1), he never returns to this cell. A possible solution with only two changes:



3)
{"ULRLRD",
 "UDDLRR"}

Returns: 4



4)
{"UDLRLDLD",
 "DLDLLDLR",
 "LLLLLDLD",
 "UUURRRDD"}

Returns: 9



5)
{"UDUDUUDUDUDUDUR",
 "LLLLDUUDRDLUDRU",
 "DLLDLDURDURUDDL",
 "UDUDUUDUDUDUDUR",
 "LLLLDUUDRDLUDRU",
 "DLLDLDURDURUDDL",
 "UDUDUUDUDUDUDUR",
 "LLLLDUUUDDLUDRU",
 "DLLDLDURDURUDDL",
 "UDUDUUDUDUDUDUR",
 "LLLLDUUDRDLUDRU",
 "DLLDLDURDURUDDL",
 "UDUDUUDUDUDUDUR",
 "LLLLDUUDRDLUDRU",
 "RRRDLDURDURUDDR"}


Returns: 73



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
		cout << "Testing DirectionBoard (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1396417264;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 1000.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		DirectionBoard _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string board[] = {"RRRD",
				                  "URDD",
				                  "UULD",
				                  "ULLL"};
				_expected = 0;
				_received = _obj.getMinimum(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 1:
			{
				string board[] = {"RRRD",
				                  "URLL",
				                  "LRRR"};
				_expected = 2;
				_received = _obj.getMinimum(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 2:
			{
				string board[] = {"RRD",
				                  "URD",
				                  "ULL"};
				_expected = 2;
				_received = _obj.getMinimum(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 3:
			{
				string board[] = {"ULRLRD",
				                  "UDDLRR"};
				_expected = 4;
				_received = _obj.getMinimum(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 4:
			{
				string board[] = {"UDLRLDLD",
				                  "DLDLLDLR",
				                  "LLLLLDLD",
				                  "UUURRRDD"};
				_expected = 9;
				_received = _obj.getMinimum(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 5:
			{
				string board[] = {"UDUDUUDUDUDUDUR",
				                  "LLLLDUUDRDLUDRU",
				                  "DLLDLDURDURUDDL",
				                  "UDUDUUDUDUDUDUR",
				                  "LLLLDUUDRDLUDRU",
				                  "DLLDLDURDURUDDL",
				                  "UDUDUUDUDUDUDUR",
				                  "LLLLDUUUDDLUDRU",
				                  "DLLDLDURDURUDDL",
				                  "UDUDUUDUDUDUDUR",
				                  "LLLLDUUDRDLUDRU",
				                  "DLLDLDURDURUDDL",
				                  "UDUDUUDUDUDUDUR",
				                  "LLLLDUUDRDLUDRU",
				                  "RRRDLDURDURUDDR"};
				_expected = 73;
				_received = _obj.getMinimum(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			/*case 6:
			{
				string board[] = ;
				_expected = ;
				_received = _obj.getMinimum(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string board[] = ;
				_expected = ;
				_received = _obj.getMinimum(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}*/
			/*case 8:
			{
				string board[] = ;
				_expected = ;
				_received = _obj.getMinimum(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
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
