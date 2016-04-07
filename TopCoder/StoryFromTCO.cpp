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

class Graph {
  typedef pair<int, int> P;
  int V;
  struct edge { int to, cap, cost, rev; };
  vector<vector<edge> > G;
  vector<bool> used;
  int dfs(int v, int f) {
    if(v == sink) return f;
    used[v] = true;
    for(int i = 0; i < G[v].size(); i++) {
      edge &e = G[v][i];
      if(!used[e.to] && e.cap > 0) {
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
  void addEdge(int from, int to, int cap, int cost = 0) {
    G[from].push_back((edge){to, cap, cost, (int)G[to].size()});
    G[to].push_back((edge){from, 0, -cost, (int)G[from].size() - 1});
  }
  int maxFlow() {
    int flow = 0;
    while(true) {
      used.resize(V);
      fill(used.begin(), used.end(), false);
      int f = dfs(source, 1e9);
      if(f == 0) return flow;
      flow += f;
    }
  }
  pair<int,int> minCostFlow(int f=2e9, bool BellmanFord=false) {
    int res = 0;
    vector<int> h(V), prevv(V), preve(V);
    while(f > 0) {
      vector<int> dist(V, 1e9);
      dist[source] = 0;
      if(BellmanFord) {
        BellmanFord = false;
        bool update = true;
        while(update) {
          update = false;
          for(int v = 0; v < V; v++) {
            if(dist[v] == 1e9) continue;
            for(int i = 0; i < G[v].size(); i++) {
              edge &e = G[v][i];
              if(e.cap > 0 && dist[e.to] > dist[v] + e.cost) {
                dist[e.to] = dist[v] + e.cost;
                prevv[e.to] = v;
                preve[e.to] = i;
                update = true;
              }
            }
          }
        }    
      } else {
        priority_queue<P, vector<P>, greater<P> > que;
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

struct StoryFromTCO {
  int minimumChanges(vector <int> places, vector <int> cutoff) {
  	Graph g;
  	int N = places.size();
  	VI left(N), right(N);
  	REP(i, N) {
  		left[i] = g.addVertex();
  		right[i] = g.addVertex();
  		g.addEdge(g.source, left[i], 1, 0);
  		if (places[i] <= cutoff[i])
  			g.addEdge(left[i], right[i], 1, 0);
  		g.addEdge(right[i], g.sink, 1, 0);
  	}
  	REP(i, N) {
  		REP(j, N) {
  			if (i != j && places[i] <= cutoff[j]) {
  				g.addEdge(left[i], right[j], 1, 1);
  			}
  		}
  	}
  	auto ans = g.minCostFlow();
  	// cout << ans.second << ' ' << ans.first << endl;
  	if (ans.second < N) {
  		return -1;
  	} else {
  		return ans.first;
  	}
  }
};

// BEGIN CUT HERE
/*
PROBLEM STATEMENT

After the Challenge Phase of TCO 2014 round 2C ended, I 
realized that I probably wouldn't get into top 50. With 
the best place I'd ever gotten in an SRM, however, it 
would've been possible. Aargh, why can't I just swap 
them... but what about making another problem out of this 
situation?





Bonifác is going to compete in a tournament with N online 
rounds, numbered 0 through N-1 in no particular order. 
Unlike the TCO, each contestant may compete officially in 
all online rounds. However, only contestants who finished 
among the top cutoff[i] participants of round i for all 0 
<= i < N are invited to the onsite finals.





Bonifác wants to compete in the onsite finals. For that, 
he assessed his skills and determined that if he competed 
in round i, he'd take the places[i]-th place. This might 
not be sufficient, but Bonifác is able to select any 
subset of elements of places and reorder them in any way 
(don't think too deeply into how he'd do it). However, 
such a feat is very difficult, so he wants to perform it 
on as few elements as possible.





You're given vector <int>s cutoff and places. Return the 
smallest non-negative integer K, such that Bonifác could 
advance to the onsite finals after reordering (permuting) 
his results in K online rounds. Formally, for Bonifác to 
advance, there have to be K elements of places, such that 
after rearranging them into a different order, places[i] 
<= cutoff[i] would hold for all 0 <= i < N. If no such K 
exists, return -1 instead.


DEFINITION
Class:StoryFromTCO
Method:minimumChanges
Parameters:vector <int>, vector <int>
Returns:int
Method signature:int minimumChanges(vector <int> places, 
vector <int> cutoff)


CONSTRAINTS
-places and cutoff will contain the same number of elements.
-places will contain between 1 and 1,000 elements, 
inclusive.
-All elements of places and cutoff will be between 1 and 
1,000,000, inclusive.


EXAMPLES

0)
{20,100,500,50}
{7500,2250,150,24}

Returns: 3

Without any changes to places, Bonifác's current 
performance in rounds 2 and 3 isn't sufficient (because 
500 > 150, 50 > 24).

For Bonifác to advance to the finals, he should permute 
places to {500,100,50,20}, which requires moving 3 elements.

1)
{5,4,3,2,1}
{5,4,3,2,1}

Returns: 0

Bonifác's current performance is exactly sufficient.

2)
{1,5,5,5}
{8,6,4,2}

Returns: -1



3)
{3,1,5}
{6,4,2}

Returns: 3

There's exactly 1 correct order; to achieve it, all 
elements must be permuted.

4)
{14,11,42,9,19}
{11,16,37,41,47}


Returns: 4



5)
{4,1,3,3,2,4,5,5,4,4}
{3,3,5,2,4,4,5,4,3,5}

Returns: 6



6)
{213,177,237,444,497,315,294,104,522,635,13,26,22,276,88,249,374,17,42,245,80,553,121,625,62,105,

53,132,178,250,18,210,492,181,2,99,29,21,62,218,188,584,702,63,41,79,28,452,2}

{33,40,41,48,74,84,117,125,126,164,197,197,201,218,222,231,244,277,290,309,321,321,360,376,440,

442,465,477,491,513,639,645,647,675,706,710,726,736,736,765,801,838,845,854,863,865,887,902,908}


Returns: 23



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
		cout << "Testing StoryFromTCO (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1412440178;
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
		StoryFromTCO _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int places[] = {20,100,500,50};
				int cutoff[] = {7500,2250,150,24};
				_expected = 3;
				_received = _obj.minimumChanges(vector <int>(places, places+sizeof(places)/sizeof(int)), vector <int>(cutoff, cutoff+sizeof(cutoff)/sizeof(int))); break;
			}
			case 1:
			{
				int places[] = {5,4,3,2,1};
				int cutoff[] = {5,4,3,2,1};
				_expected = 0;
				_received = _obj.minimumChanges(vector <int>(places, places+sizeof(places)/sizeof(int)), vector <int>(cutoff, cutoff+sizeof(cutoff)/sizeof(int))); break;
			}
			case 2:
			{
				int places[] = {1,5,5,5};
				int cutoff[] = {8,6,4,2};
				_expected = -1;
				_received = _obj.minimumChanges(vector <int>(places, places+sizeof(places)/sizeof(int)), vector <int>(cutoff, cutoff+sizeof(cutoff)/sizeof(int))); break;
			}
			case 3:
			{
				int places[] = {3,1,5};
				int cutoff[] = {6,4,2};
				_expected = 3;
				_received = _obj.minimumChanges(vector <int>(places, places+sizeof(places)/sizeof(int)), vector <int>(cutoff, cutoff+sizeof(cutoff)/sizeof(int))); break;
			}
			case 4:
			{
				int places[] = {14,11,42,9,19};
				int cutoff[] = {11,16,37,41,47};
				_expected = 4;
				_received = _obj.minimumChanges(vector <int>(places, places+sizeof(places)/sizeof(int)), vector <int>(cutoff, cutoff+sizeof(cutoff)/sizeof(int))); break;
			}
			case 5:
			{
				int places[] = {4,1,3,3,2,4,5,5,4,4};
				int cutoff[] = {3,3,5,2,4,4,5,4,3,5};
				_expected = 6;
				_received = _obj.minimumChanges(vector <int>(places, places+sizeof(places)/sizeof(int)), vector <int>(cutoff, cutoff+sizeof(cutoff)/sizeof(int))); break;
			}
			case 6:
			{
				int places[] = {213,177,237,444,497,315,294,104,522,635,13,26,22,276,88,249,374,17,42,245,80,553,121,625,62,105,
				               53,132,178,250,18,210,492,181,2,99,29,21,62,218,188,584,702,63,41,79,28,452,2};
				int cutoff[] = {33,40,41,48,74,84,117,125,126,164,197,197,201,218,222,231,244,277,290,309,321,321,360,376,440,
				               442,465,477,491,513,639,645,647,675,706,710,726,736,736,765,801,838,845,854,863,865,887,902,908};
				_expected = 23;
				_received = _obj.minimumChanges(vector <int>(places, places+sizeof(places)/sizeof(int)), vector <int>(cutoff, cutoff+sizeof(cutoff)/sizeof(int))); break;
			}
			/*case 7:
			{
				int places[] = ;
				int cutoff[] = ;
				_expected = ;
				_received = _obj.minimumChanges(vector <int>(places, places+sizeof(places)/sizeof(int)), vector <int>(cutoff, cutoff+sizeof(cutoff)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int places[] = ;
				int cutoff[] = ;
				_expected = ;
				_received = _obj.minimumChanges(vector <int>(places, places+sizeof(places)/sizeof(int)), vector <int>(cutoff, cutoff+sizeof(cutoff)/sizeof(int))); break;
			}*/
			/*case 9:
			{
				int places[] = ;
				int cutoff[] = ;
				_expected = ;
				_received = _obj.minimumChanges(vector <int>(places, places+sizeof(places)/sizeof(int)), vector <int>(cutoff, cutoff+sizeof(cutoff)/sizeof(int))); break;
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
