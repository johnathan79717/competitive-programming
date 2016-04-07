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
#line 39 "SuccessfulMerger.cpp"
#include <string>
#include <vector>
class SuccessfulMerger {
public:
    int minimumMergers(vector <int> road) {
        
    }
};
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// In the country of Byteland, there are N cities connected by N bidirectional roads (that is, the number of roads is the same as the number of cities).
The cities are numbered from 0 to N-1.
For each i from 0 to N-1, a bidirectional road connects city i and city road[i].
(Note that sometimes a pair of cities can be connected by two distinct roads.)
It is possible to travel between any pair of cities using the network of roads.


You are the prime minister of Byteland and you must choose one of the cities to be the capital city.
The capital city must have the following property:
whenever A and B are two distinct cities, it must be impossible to travel between A and B without visiting the capital.


If there is no valid location for the capital, you must create one.
In order to do that, you may modify the road network by doing a sequence of mergers.
A merger is an operation that merges two adjacent cities into a single new city.
Formally, a merger is performed as follows:

You select two cities X and Y that are directly connected by a road. (They may even be connected by more than one direct road.)
The two cities are merged together to create a new city Z.
All direct roads between X and Y disappear. Each other road that connected X or Y to some other city now connects Z to that other city.


For example, suppose this is the network:





There is no valid location for the capital. However, by merging city 1 and city 2, we can create a valid location:





Now the newly-created city is a valid location for the capital.


You are given the description of the road network in the vector <int> road.
Please find and return the minimum number of mergers necessary to create a valid location for the capital.

DEFINITION
Class:SuccessfulMerger
Method:minimumMergers
Parameters:vector <int>
Returns:int
Method signature:int minimumMergers(vector <int> road)


CONSTRAINTS
-N will be between 2 and 50, inclusive.
-road will contain N elements.
-Each element of road will be between 0 and N-1, inclusive.
-For each valid i, road[i] does not equal i.
-It will be possible to travel from any city to any other city using the roads.


EXAMPLES

0)
{2, 2, 1, 1, 1}

Returns: 1

This test case corresponds to the example from the problem statement.
In the given road network there is no valid location for the capital, so at least one merger is needed.
The one merger shown above is therefore the optimal solution for this test case.

1)
{3, 4, 5, 4, 5, 3}

Returns: 2



2)
{1, 0, 1, 0, 0, 0, 1, 0, 1, 1}

Returns: 1



3)
{1, 2, 3, 0}

Returns: 2



4)
{31, 19, 0, 15, 30, 32, 15, 24, 0, 20, 40, 1, 22, 21, 39, 28, 0, 23, 15, 5, 19, 22, 6, 32, 8, 38, 35, 30, 4, 28, 32, 18, 18, 9, 22, 41, 20, 18, 6, 25, 41, 34, 4}

Returns: 25



5)
{1, 0}

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
		cout << "Testing SuccessfulMerger (450.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1456194488;
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
		SuccessfulMerger _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int road[] = {2, 2, 1, 1, 1};
				_expected = 1;
				_received = _obj.minimumMergers(vector <int>(road, road+sizeof(road)/sizeof(int))); break;
			}
			case 1:
			{
				int road[] = {3, 4, 5, 4, 5, 3};
				_expected = 2;
				_received = _obj.minimumMergers(vector <int>(road, road+sizeof(road)/sizeof(int))); break;
			}
			case 2:
			{
				int road[] = {1, 0, 1, 0, 0, 0, 1, 0, 1, 1};
				_expected = 1;
				_received = _obj.minimumMergers(vector <int>(road, road+sizeof(road)/sizeof(int))); break;
			}
			case 3:
			{
				int road[] = {1, 2, 3, 0};
				_expected = 2;
				_received = _obj.minimumMergers(vector <int>(road, road+sizeof(road)/sizeof(int))); break;
			}
			case 4:
			{
				int road[] = {31, 19, 0, 15, 30, 32, 15, 24, 0, 20, 40, 1, 22, 21, 39, 28, 0, 23, 15, 5, 19, 22, 6, 32, 8, 38, 35, 30, 4, 28, 32, 18, 18, 9, 22, 41, 20, 18, 6, 25, 41, 34, 4};
				_expected = 25;
				_received = _obj.minimumMergers(vector <int>(road, road+sizeof(road)/sizeof(int))); break;
			}
			case 5:
			{
				int road[] = {1, 0};
				_expected = 0;
				_received = _obj.minimumMergers(vector <int>(road, road+sizeof(road)/sizeof(int))); break;
			}
			/*case 6:
			{
				int road[] = ;
				_expected = ;
				_received = _obj.minimumMergers(vector <int>(road, road+sizeof(road)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int road[] = ;
				_expected = ;
				_received = _obj.minimumMergers(vector <int>(road, road+sizeof(road)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int road[] = ;
				_expected = ;
				_received = _obj.minimumMergers(vector <int>(road, road+sizeof(road)/sizeof(int))); break;
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
