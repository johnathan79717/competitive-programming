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
#define V(T) vector<T >
 
typedef V(int) VI;

struct BuildingRoutes {
  int build(vector <string> dist, int T) {
  	int N = dist.size();
  	V(VI) dp(N, VI(N));
  	REP(i, N) REP(j, N) {
  		dp[i][j] = dist[i][j] - '0';
  	}
  	REP(i, N) REP(j, N) REP(k, N) {
  		dp[j][k] = min(dp[j][k], dp[j][i] + dp[i][k]);
  	}
  	int ans = 0;
  	REP(i, N) REP(j, N) {
  		if(i == j) continue;
  		int cnt = 0;
  		REP(k, N) REP(l, N) {
  			if(dp[k][i] + dist[i][j]-'0' + dp[j][l] == dp[k][l])
  				cnt++;
  		}
  		if(cnt >= T)
  			ans+=dist[i][j]-'0';
  	}
  	return ans;
  }
};

// BEGIN CUT HERE
/*
PROBLEM STATEMENT
In the Republic of Nlogonia there are N cities.
For convenience, the cities are numbered 0 through N-1.
For each two different cities i and j, there is a direct 
one-way road from i to j.
You are given the lengths of those roads as a vector 
<string> dist with N elements, each with N characters.
For each i and j, the character dist[i][j] represents the 
length of the road from i to j.

The lengths of roads are integers between 1 and 9, 
inclusive, and they are represented by digits '1' through 
'9'.
That is, for distinct i and j, dist[i][j] will be between 
'1' and '9'.
For each i, dist[i][i] will be '0'.
Note that the roads from i to j and from j to i may have 
different lengths.

Every year on Algorithms Day (the most important holiday 
in Nlogonia) people travel between the cities.
More precisely, for each pair of distinct cities i and j, 
one full bus of people travels from i to j.
Each of those buses drives along a shortest path from its 
origin to its destination.
If there are multiple shortest paths, the bus driver picks 
one of them arbitrarily.

The roads in Nlogonia are currently limited.
You are given an int T with the following meaning: 
each of the current roads is only safe if it is guaranteed 
that there will be strictly fewer than T buses driving 
along the road.
In other words, a road is unsafe if it is possible that T 
or more buses will use it.
The government wants to rebuild all unsafe roads before 
the next Algorithms Day.
Return the sum of lengths of all unsafe roads.

DEFINITION
Class:BuildingRoutes
Method:build
Parameters:vector <string>, int
Returns:int
Method signature:int build(vector <string> dist, int T)


CONSTRAINTS
-N will be between 2 and 50, inclusive.
-dist will contain exactly N elements.
-Each element of dist will contain exactly N characters.
-For each i, dist[i][i] will be '0'.
-For each pair of distinct i and j, dist[i][j] will be 
between '1' and '9', inclusive.
-T will be between 1 and 2500, inclusive.


EXAMPLES

0)
{"011",
 "101",
 "110"}
1

Returns: 6

As T=1, a road is unsafe as soon as it is possible that a 
bus will use it. 
Each of the six roads in this test case belongs to some 
shortest path, hence each of them is unsafe

1)
{"033",
 "309",
 "390"}
1

Returns: 12

The roads 1->2 and 2->1 (the two roads of length 9) will 
not be used by any bus.
Only the four remaining roads are unsafe in this case.

2)
{"0123",
 "1023",
 "1203",
 "1230"}
2

Returns: 5



3)
{"05789654",
 "10347583",
 "65085479",
 "55602398",
 "76590934",
 "57939045",
 "12345608",
 "68647640"}
3

Returns: 40



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
		cout << "Testing BuildingRoutes (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1401325228;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 250.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		BuildingRoutes _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string dist[] = {"011",
				                 "101",
				                 "110"};
				int T = 1;
				_expected = 6;
				_received = _obj.build(vector <string>(dist, dist+sizeof(dist)/sizeof(string)), T); break;
			}
			case 1:
			{
				string dist[] = {"033",
				                 "309",
				                 "390"};
				int T = 1;
				_expected = 12;
				_received = _obj.build(vector <string>(dist, dist+sizeof(dist)/sizeof(string)), T); break;
			}
			case 2:
			{
				string dist[] = {"0123",
				                 "1023",
				                 "1203",
				                 "1230"};
				int T = 2;
				_expected = 5;
				_received = _obj.build(vector <string>(dist, dist+sizeof(dist)/sizeof(string)), T); break;
			}
			case 3:
			{
				string dist[] = {"05789654",
				                 "10347583",
				                 "65085479",
				                 "55602398",
				                 "76590934",
				                 "57939045",
				                 "12345608",
				                 "68647640"};
				int T = 3;
				_expected = 40;
				_received = _obj.build(vector <string>(dist, dist+sizeof(dist)/sizeof(string)), T); break;
			}
			/*case 4:
			{
				string dist[] = ;
				int T = ;
				_expected = ;
				_received = _obj.build(vector <string>(dist, dist+sizeof(dist)/sizeof(string)), T); break;
			}*/
			/*case 5:
			{
				string dist[] = ;
				int T = ;
				_expected = ;
				_received = _obj.build(vector <string>(dist, dist+sizeof(dist)/sizeof(string)), T); break;
			}*/
			/*case 6:
			{
				string dist[] = ;
				int T = ;
				_expected = ;
				_received = _obj.build(vector <string>(dist, dist+sizeof(dist)/sizeof(string)), T); break;
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
