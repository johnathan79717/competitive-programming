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

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

class FoxConnection3 {
	public:
	long long minimalSteps(vector <int> x, vector <int> y) {
		this->x = x;
		this->y = y;
		fx[0] = 9;
		fy[0] = 9;
		N = x.size();
		MS0(used);
		used[0] = true;
		MS0(grid);
		search(1);
		return best;
	}
	VI x, y, xx, yy;
	int fx[6], fy[6];
	int N;
	bool used[6];
	bool grid[20][20];
	LL best = LLONG_MAX;
	void search(int n) {
		if (n == N) {
			xx = x;
			yy = y;
			REP(i, N) {
				xx[i] -= fx[i] - fx[0];
				yy[i] -= fy[i] - fy[0];
			}
			sort(ALL(xx));
			sort(ALL(yy));
			LL ans = 0;
			REP(i, N) {
				ans += abs(xx[i] - xx[N/2]);
				ans += abs(yy[i] - yy[N/2]);
			}
			best = min(best, ans);
			return;
		}
		REP(j, N) {
			if (used[j]) {
				REP(k, 4) {
					int xx = fx[j]+dx[k], yy = fy[j]+dy[k];
					if (!grid[xx][yy]) {
						grid[xx][yy] = true;
						REP(i, N) {
							if (!used[i]) {
								used[i] = true;
								fx[i] = xx;
								fy[i] = yy;
								search(n+1);
								used[i] = false;
							}
						}
						grid[xx][yy] = false;
					}
				}
			}
		}
	}
};
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// The infinite plane is divided into a grid of unit square cells.
Two cells are considered adjacent if they share a side.
There are some foxes on the plane.
Each fox is currently standing on a different cell.
This must also be preserved in the future - there cannot be two foxes in the same cell at the same time.


Whenever a fox takes a step, it moves to a cell that is adjacent to its current cell.
A set of cells is considered connected if a fox could walk from any cell in the set to any other cell in the set without leaving the set.


All foxes want to get together.
More precisely, they want to move in such a way that at the end the set of cells occupied by the foxes is connected.
Return the smallest total number of steps the foxes need to make in order to reach such a configuration.


DEFINITION
Class:FoxConnection3
Method:minimalSteps
Parameters:vector <int>, vector <int>
Returns:long long
Method signature:long long minimalSteps(vector <int> x, vector <int> y)


CONSTRAINTS
-x will contain between 1 and 6 elements, inclusive.
-x and y will contain the same number of elements.
-Each element in x will be between -1,000,000,000 and 1,000,000,000, inclusive.
-Each element in y will be between -1,000,000,000 and 1,000,000,000, inclusive.
-No two foxes will be at the same position.


EXAMPLES

0)
{0,0,1,-2}
{1,-1,0,0}

Returns: 2

The optimal solution is to move the last fox 2 steps to the right.

1)
{0,0,0,0,0,0}
{1,2,3,4,5,6}

Returns: 0

Foxes are already connected, so we don't need any operations.

2)
{-123456789,-58585858,-47474747,123,456,789012345}
{0,0,0,0,0,0}

Returns: 1018530309



3)
{1,7,3,5,2}
{2,7,5,3,7}

Returns: 12



4)
{-3,0,1,-2,3,2}
{2,-3,0,1,-1,-1}

Returns: 10



5)
{-96277832,507856257,-86306299,-806700273,-775932643,-273209838}
{-955536464,-599634138,399850429,-165706338,-537800480,738983556}

Returns: 5247213600



6)
{0}
{0}

Returns: 0



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
		cout << "Testing FoxConnection3 (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1425143631;
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
		FoxConnection3 _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int x[] = {0,0,1,-2};
				int y[] = {1,-1,0,0};
				_expected = 2LL;
				_received = _obj.minimalSteps(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 1:
			{
				int x[] = {0,0,0,0,0,0};
				int y[] = {1,2,3,4,5,6};
				_expected = 0LL;
				_received = _obj.minimalSteps(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 2:
			{
				int x[] = {-123456789,-58585858,-47474747,123,456,789012345};
				int y[] = {0,0,0,0,0,0};
				_expected = 1018530309LL;
				_received = _obj.minimalSteps(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 3:
			{
				int x[] = {1,7,3,5,2};
				int y[] = {2,7,5,3,7};
				_expected = 12LL;
				_received = _obj.minimalSteps(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 4:
			{
				int x[] = {-3,0,1,-2,3,2};
				int y[] = {2,-3,0,1,-1,-1};
				_expected = 10LL;
				_received = _obj.minimalSteps(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 5:
			{
				int x[] = {-96277832,507856257,-86306299,-806700273,-775932643,-273209838};
				int y[] = {-955536464,-599634138,399850429,-165706338,-537800480,738983556};
				_expected = 5247213600LL;
				_received = _obj.minimalSteps(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 6:
			{
				int x[] = {0};
				int y[] = {0};
				_expected = 0LL;
				_received = _obj.minimalSteps(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			/*case 7:
			{
				int x[] = ;
				int y[] = ;
				_expected = LL;
				_received = _obj.minimalSteps(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int x[] = ;
				int y[] = ;
				_expected = LL;
				_received = _obj.minimalSteps(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}*/
			/*case 9:
			{
				int x[] = ;
				int y[] = ;
				_expected = LL;
				_received = _obj.minimalSteps(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
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
