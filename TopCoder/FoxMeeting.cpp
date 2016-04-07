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
#include <cassert>
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

struct DisjointSet {
  VI par, _size;
  int N;

  DisjointSet(int N): par(N), _size(N), N(N) {
    init();
  }

  void init() {
    for(int i = 0; i < N; i++) {
      par[i] = i;
      _size[i] = 1;
    }
  }

  int find(int x) {
    if(par[x] == x) return x;
    else return par[x] = find(par[x]);
  }

  void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y) return;
    if(_size[x] < _size[y]) {
      par[x] = y;
      _size[y] += _size[x];
    } else {
      par[y] = x;
      _size[x] += _size[y];
    }
  }

  int size(int x) {
    return _size[find(x)];
  }
};

int adj[51][51];
bool occupied[51];
int deg[51];
int N, F;
int d[51];
bool valid[51];

class FoxMeeting {
public:
    VI pos;
    void cut(int i) {
        if (!valid[i] || occupied[i] || deg[i] != 1) return;
        REP1(j, 1, N) {
            if (valid[j] && adj[i][j]) {
                adj[i][j] = adj[j][i] = 0;
                deg[j]--;
                deg[i] = 0;
                valid[i] = false;
                if (deg[j] == 1) {
                    cut(j);
                }
            }
        }
    }
    bool connected() {
        DisjointSet ds(F);
        REP(i, F) {
            REP(j, F) {
                if (adj[pos[i]][pos[j]]) {
                    ds.unite(i, j);
                }
            }
        }
        REP(i, F) {
            REP(j, F) {
                if (ds.find(i) != ds.find(j)) {
                    return false;
                }
            }
        }
        return true;
    }
	int maxDistance(vector <int> A, vector <int> B, vector <int> L, vector <int> foxes) {
        MS1(valid);
        pos = foxes;
	    N = A.size()+1;
        F = pos.size();
        REP(i, N-1) {
            adj[A[i]][B[i]] = adj[B[i]][A[i]] = L[i];
            deg[A[i]]++;
            deg[B[i]]++;
        }
        priority_queue<PII, vector<PII>, greater<PII> > pq;
        REP(i, F) {
            occupied[pos[i]] = true;
        }   
        REP1(i, 1, N) {
            cut(i);
        }
        REP(k, F) {
            assert(valid[pos[k]]);
            int p = pos[k];
            assert(deg[p]);
            if (deg[p] == 1) {
                int cnt = 0;
                REP1(j, 1, N) {
                    if (valid[j] && adj[p][j]) {
                        cnt++;
                        pq.emplace(adj[p][j], k);
                    }
                }
                assert(cnt == 1);
            }
        }
        while (!connected()) {
            assert(!pq.empty());
            int i = pq.top().second;
            int dd = pq.top().first;
            pq.pop();
            int p = pos[i];
            assert(valid[p]);
            int cnt = 0;
            REP1(j, 1, N) {
                if (valid[j] && adj[p][j]) {
                    cnt++;
                    assert(d[i] + adj[p][j] == dd);
                    d[i] = dd;
                    pos[i] = j;
                    bool exist = false;
                    REP(k, F) {
                        if (pos[k] == p) {
                            exist = true;
                        }
                    }
                    if (!exist) {
                        deg[p]--;
                        valid[p] = false;
                        deg[j]--;
                        adj[p][j] = adj[j][p] = 0;
                        assert(deg[j]);
                        if (deg[j] == 1) { // j becomes a leaf
                            REP(k, F) {
                                // assert(valid[pos[k]]);
                                if (pos[k] == j) {
                                    assert(deg[pos[k]] == 1);
                                    int cnt = 0;
                                    REP1(l, 1, N) {
                                        if (valid[l] && adj[j][l]) {
                                            cnt++;
                                            pq.emplace(d[k] + adj[j][l], k);
                                        }
                                    }
                                    assert(cnt == 1);
                                }
                            }
                        }
                    }
                }
            }
            assert(cnt == 1);
        }
        int ans = 0;
        REP(i, F) {
            MAX(ans, d[i]);
        }
        return ans;
	}
};
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
Foxland is a country with n cities.
The cities are numbered 1 through n.
The road network in Foxland is a tree.
You are given the description of the roads: three vector <int>s A, B and L with n-1 elements each.
For each valid i, there is a bidirectional road connecting the cities A[i] and B[i], and the length of the road is L[i].





There are some foxes in Foxland.
Each fox lives in a different city.
You are given a vector <int> foxes.
The elements of foxes are the numbers of cities inhabited by foxes.




The foxes are running a secret candy-smuggling network.
Recently they have been harrassed by a new strict police officer: cat Taro.
In order to avoid him, the foxes have now learned to communicate by waving their tails at each other.
However, two foxes can only communicate in this way if they see each other.
More precisely, they must either both be in the same city, or they have to be in two adjacent cities.
(Adjacent cities are cities directly connected by a road, regardless of the road's length.)





Foxes can forward messages to other foxes, which makes communication transitive:
If fox x can talk to fox y and fox y can talk to fox z, fox x will be able to communicate with fox z as well.





In order to avoid Taro, each fox must be able to talk to all other foxes (either directly or indirectly).
If it isn't possible in their current configuration, some foxes may be forced to move into different cities.
The foxes think that it is also suspicious if a fox moves too far from its current home.
Therefore, they want to minimize the maximum distance traveled by any fox.





Formally, find and return the smallest integer D with the following property:
It is possible to relocate some (possibly zero, possibly all) of the foxes into new cities in such a way that:

For each fox, the total total distance traveled by that fox is at most D.
After the relocation, all foxes can communicate (either directly or indirectly).



DEFINITION
Class:FoxMeeting
Method:maxDistance
Parameters:vector <int>, vector <int>, vector <int>, vector <int>
Returns:int
Method signature:int maxDistance(vector <int> A, vector <int> B, vector <int> L, vector <int> foxes)


CONSTRAINTS
-n will be between 1 and 50, inclusive.
-A, B, and L will contain exactly n-1 elements each.
-Each element in A and B will be between 1 and n, inclusive.
-Each element in L will be between 1 and 100,000, inclusive.
-A, B, and L will define a tree.
-Number of elements in foxes will be between 1 and n, inclusive.
-Each element in foxes will be between 1 and n, inclusive.
-All the elements of foxes are distinct.


EXAMPLES

0)
{1}
{2}
{5}
{1, 2}

Returns: 0

There are two cities connected by a single road of length 5.
There are two foxes: one in each city.
As they are in adjacent cities, they can already communicate so no relocation is necessary.

1)
{1, 2}
{2, 3}
{1, 1}
{1, 3}

Returns: 1

This country has three cities and two roads: 1-2 (length 1) and 2-3 (length 1).
Initially, there is one fox in city 1 and another fox in city 3.
In one optimal solution, the first fox will move from city 1 to city 2.
In another optimal solution, both foxes will move from their respective cities to city 2.
In each of the solutions described above we have D = 1.

2)
{1, 2}
{2, 3}
{1, 1}
{1, 2, 3}

Returns: 0

 No relocation is necessary, all foxes can already talk to each other.

3)
{10,8,3,7,2,6,9,1,4}
{5,5,8,10,5,5,6,10,3}
{71846,10951,42265,37832,29439,95676,83661,28186,21216}
{1,2,3,4,5,6,7,8,9,10}

Returns: 0



4)
{8,15,22,24,2,25,13,26,18,4,9,29,1,12,3,16,14,21,19,27,17,7,20,10,30,11,6,5,23}
{28,28,8,8,28,28,25,2,13,24,24,22,22,29,4,22,8,4,1,24,21,14,18,16,13,21,14,1,25}
{79374,40629,43195,73589,24200,63937,35339,7598,65109,51764,11142,84017,51078,58051,81387,22035,34883,92710,52283,57337,79309,3383,41904,35839,38242,43208,82062,24676,71838}
{3,5,7,9,10,14,17,19,20,21,24,25,28}

Returns: 107013



5)
{34,14,22,9,24,19,11,37,33,21,5,30,1,43,7,31,45,27,6,12,13,35,23,47,49,50,26,40,16,10,48,25,29,15,28,46,4,20,44,17,39,32,38,2,42,8,36,3,41}
{18,18,18,14,9,34,9,24,34,11,18,14,21,21,43,1,22,7,1,30,14,33,13,18,9,5,1,1,26,19,50,33,50,40,29,48,50,37,16,40,48,14,30,22,47,37,7,50,6}
{22051,11109,85275,6691,43705,47374,27748,5411,62549,84079,89542,38006,82198,24083,16847,66335,3542,72495,37378,73973,85703,51682,68688,94295,31337,
90071,99317,63484,43244,99079,55857,34503,79709,82140,91137,27033,91599,61168,52345,49569,58919,38133,43361,
40718,2115,79278,88841,40966,42023}
{5,12,13,18,23,27,28,29,32,33,34,35,36,37,40,42,43,47,48,49,50}

Returns: 89342



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
		cout << "Testing FoxMeeting (600.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1433073720;
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
		FoxMeeting _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int A[] = {1};
				int B[] = {2};
				int L[] = {5};
				int foxes[] = {1, 2};
				_expected = 0;
				_received = _obj.maxDistance(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(L, L+sizeof(L)/sizeof(int)), vector <int>(foxes, foxes+sizeof(foxes)/sizeof(int))); break;
			}
			case 1:
			{
				int A[] = {1, 2};
				int B[] = {2, 3};
				int L[] = {1, 1};
				int foxes[] = {1, 3};
				_expected = 1;
				_received = _obj.maxDistance(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(L, L+sizeof(L)/sizeof(int)), vector <int>(foxes, foxes+sizeof(foxes)/sizeof(int))); break;
			}
			case 2:
			{
				int A[] = {1, 2};
				int B[] = {2, 3};
				int L[] = {1, 1};
				int foxes[] = {1, 2, 3};
				_expected = 0;
				_received = _obj.maxDistance(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(L, L+sizeof(L)/sizeof(int)), vector <int>(foxes, foxes+sizeof(foxes)/sizeof(int))); break;
			}
			case 3:
			{
				int A[] = {10,8,3,7,2,6,9,1,4};
				int B[] = {5,5,8,10,5,5,6,10,3};
				int L[] = {71846,10951,42265,37832,29439,95676,83661,28186,21216};
				int foxes[] = {1,2,3,4,5,6,7,8,9,10};
				_expected = 0;
				_received = _obj.maxDistance(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(L, L+sizeof(L)/sizeof(int)), vector <int>(foxes, foxes+sizeof(foxes)/sizeof(int))); break;
			}
			case 4:
			{
				int A[] = {8,15,22,24,2,25,13,26,18,4,9,29,1,12,3,16,14,21,19,27,17,7,20,10,30,11,6,5,23};
				int B[] = {28,28,8,8,28,28,25,2,13,24,24,22,22,29,4,22,8,4,1,24,21,14,18,16,13,21,14,1,25};
				int L[] = {79374,40629,43195,73589,24200,63937,35339,7598,65109,51764,11142,84017,51078,58051,81387,22035,34883,92710,52283,57337,79309,3383,41904,35839,38242,43208,82062,24676,71838};
				int foxes[] = {3,5,7,9,10,14,17,19,20,21,24,25,28};
				_expected = 107013;
				_received = _obj.maxDistance(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(L, L+sizeof(L)/sizeof(int)), vector <int>(foxes, foxes+sizeof(foxes)/sizeof(int))); break;
			}
			case 5:
			{
				int A[] = {34,14,22,9,24,19,11,37,33,21,5,30,1,43,7,31,45,27,6,12,13,35,23,47,49,50,26,40,16,10,48,25,29,15,28,46,4,20,44,17,39,32,38,2,42,8,36,3,41};
				int B[] = {18,18,18,14,9,34,9,24,34,11,18,14,21,21,43,1,22,7,1,30,14,33,13,18,9,5,1,1,26,19,50,33,50,40,29,48,50,37,16,40,48,14,30,22,47,37,7,50,6};
				int L[] = {22051,11109,85275,6691,43705,47374,27748,5411,62549,84079,89542,38006,82198,24083,16847,66335,3542,72495,37378,73973,85703,51682,68688,94295,31337,
				          90071,99317,63484,43244,99079,55857,34503,79709,82140,91137,27033,91599,61168,52345,49569,58919,38133,43361,
				          40718,2115,79278,88841,40966,42023};
				int foxes[] = {5,12,13,18,23,27,28,29,32,33,34,35,36,37,40,42,43,47,48,49,50};
				_expected = 89342;
				_received = _obj.maxDistance(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(L, L+sizeof(L)/sizeof(int)), vector <int>(foxes, foxes+sizeof(foxes)/sizeof(int))); break;
			}
			/*case 6:
			{
				int A[] = ;
				int B[] = ;
				int L[] = ;
				int foxes[] = ;
				_expected = ;
				_received = _obj.maxDistance(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(L, L+sizeof(L)/sizeof(int)), vector <int>(foxes, foxes+sizeof(foxes)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int A[] = ;
				int B[] = ;
				int L[] = ;
				int foxes[] = ;
				_expected = ;
				_received = _obj.maxDistance(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(L, L+sizeof(L)/sizeof(int)), vector <int>(foxes, foxes+sizeof(foxes)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int A[] = ;
				int B[] = ;
				int L[] = ;
				int foxes[] = ;
				_expected = ;
				_received = _obj.maxDistance(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(L, L+sizeof(L)/sizeof(int)), vector <int>(foxes, foxes+sizeof(foxes)/sizeof(int))); break;
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
