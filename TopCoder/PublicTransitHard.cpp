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

class PublicTransitHard {
	public:
	int countValidTeleporters(int N, vector <int> edges, int X) {
		
	}
};
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Note that this problem has a time limit of 3 seconds.


The city of Treeonto is a tree of N vertices numbered from 0 to N-1. For each valid i, an edge connects vertex i+1 and vertex edges[i]. Travelling along an edge in the graph takes one minute.


The citizens of Treeonto are upset that it takes too long to get around, so they have decided to build a teleporter. The teleporter will consist of two identical booths, each located in some vertex. If a citizen enters either booth, he or she may choose to teleport to the other booth instantly. It is allowed to build both booths in the same vertex.


We define the distance between two vertices as the smallest number of minutes needed to get from one vertex to the other. Let D be the maximum distance between any two vertices. Return the number of ways to place the teleporter such that D does not exceed X.

DEFINITION
Class:PublicTransitHard
Method:countValidTeleporters
Parameters:int, vector <int>, int
Returns:int
Method signature:int countValidTeleporters(int N, vector <int> edges, int X)


CONSTRAINTS
-N will be between 1 and 2000, inclusive.
-edges will contain N-1 elements.
-For each valid i, edges[i] will be between 0 and i, inclusive.
-X will be between 0 and N, inclusive.


EXAMPLES

0)
4
{0, 1, 2}
1

Returns: 1



1)
3
{0, 0}
2

Returns: 6

Any teleporter placement is valid.

2)
6
{0, 0, 0, 1, 1}
2

Returns: 1



3)
7
{0, 1, 0, 1, 2, 4}
3

Returns: 0



4)
16
{0, 1, 0, 2, 0, 0, 4, 5, 8, 9, 10, 11, 8, 4, 6}
7

Returns: 31



5)
56
{0, 1, 1, 3, 1, 5, 1, 0, 8, 8, 10, 10, 12, 10, 10, 8, 16, 16, 18, 19, 19, 21, 19, 19, 24, 25, 25, 27, 18, 0, 30, 30, 30, 33, 34, 34, 34, 30, 38, 39, 39, 38, 42, 43, 0, 45, 45, 45, 48, 45, 45, 51, 45, 53, 54}
12

Returns: 610



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
		cout << "Testing PublicTransitHard (1100.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1431479124;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 1100.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		PublicTransitHard _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 4;
				int edges[] = {0, 1, 2};
				int X = 1;
				_expected = 1;
				_received = _obj.countValidTeleporters(N, vector <int>(edges, edges+sizeof(edges)/sizeof(int)), X); break;
			}
			case 1:
			{
				int N = 3;
				int edges[] = {0, 0};
				int X = 2;
				_expected = 6;
				_received = _obj.countValidTeleporters(N, vector <int>(edges, edges+sizeof(edges)/sizeof(int)), X); break;
			}
			case 2:
			{
				int N = 6;
				int edges[] = {0, 0, 0, 1, 1};
				int X = 2;
				_expected = 1;
				_received = _obj.countValidTeleporters(N, vector <int>(edges, edges+sizeof(edges)/sizeof(int)), X); break;
			}
			case 3:
			{
				int N = 7;
				int edges[] = {0, 1, 0, 1, 2, 4};
				int X = 3;
				_expected = 0;
				_received = _obj.countValidTeleporters(N, vector <int>(edges, edges+sizeof(edges)/sizeof(int)), X); break;
			}
			case 4:
			{
				int N = 16;
				int edges[] = {0, 1, 0, 2, 0, 0, 4, 5, 8, 9, 10, 11, 8, 4, 6};
				int X = 7;
				_expected = 31;
				_received = _obj.countValidTeleporters(N, vector <int>(edges, edges+sizeof(edges)/sizeof(int)), X); break;
			}
			case 5:
			{
				int N = 56;
				int edges[] = {0, 1, 1, 3, 1, 5, 1, 0, 8, 8, 10, 10, 12, 10, 10, 8, 16, 16, 18, 19, 19, 21, 19, 19, 24, 25, 25, 27, 18, 0, 30, 30, 30, 33, 34, 34, 34, 30, 38, 39, 39, 38, 42, 43, 0, 45, 45, 45, 48, 45, 45, 51, 45, 53, 54};
				int X = 12;
				_expected = 610;
				_received = _obj.countValidTeleporters(N, vector <int>(edges, edges+sizeof(edges)/sizeof(int)), X); break;
			}
			/*case 6:
			{
				int N = ;
				int edges[] = ;
				int X = ;
				_expected = ;
				_received = _obj.countValidTeleporters(N, vector <int>(edges, edges+sizeof(edges)/sizeof(int)), X); break;
			}*/
			/*case 7:
			{
				int N = ;
				int edges[] = ;
				int X = ;
				_expected = ;
				_received = _obj.countValidTeleporters(N, vector <int>(edges, edges+sizeof(edges)/sizeof(int)), X); break;
			}*/
			/*case 8:
			{
				int N = ;
				int edges[] = ;
				int X = ;
				_expected = ;
				_received = _obj.countValidTeleporters(N, vector <int>(edges, edges+sizeof(edges)/sizeof(int)), X); break;
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
