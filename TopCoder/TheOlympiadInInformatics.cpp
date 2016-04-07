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
#define FOR(i, c) for(auto &i: c)

struct TheOlympiadInInformatics {
	bool ok(vector<int> sums, int k, int m) {
		long cnt = 0;
		FOR(s, sums)
			cnt += s / (m+1);
		return cnt <= k;
	}

  int find(vector <int> sums, int k) {
  	int ub = 1e9+1, lb = -1;
  	while(ub - lb > 1) {
  		int m = lb + (ub - lb) / 2;
  		if(ok(sums, k, m))
  			ub = m;
  		else
  			lb = m;		
  	}
  	return ub;
  }
};

// BEGIN CUT HERE
/*
PROBLEM STATEMENT
John takes part in a regional olympiad in informatics 
together with other participants.
At the contest each participant gains some nonnegative 
integer score.
Each participant (except for John) is assigned to one of 
the N contest rooms (numbered from 0 to N-1) and John is 
the only contestant in the room number N.
John has no idea how many participants are in the other 
rooms.
For each of the other rooms he only knows the sum of 
scores of all participants in it.


You are given a vector <int> sums containing N elements 
and an int k.
The i-th element of sums is the sum of participants' 
scores in the i-th contest room.
Return the minimal score John has to gain to be sure that 
there are at most k participants with strictly higher 
scores.


DEFINITION
Class:TheOlympiadInInformatics
Method:find
Parameters:vector <int>, int
Returns:int
Method signature:int find(vector <int> sums, int k)


CONSTRAINTS
-sums will contain between 1 and 47 elements, inclusive.
-Each element of sums will be between 0 and 1,000,000,000, 
inclusive.
-k will be between 0 and 1,000,000,000, inclusive.


EXAMPLES

0)
{4, 7, 0, 5}
0

Returns: 7

John has to gain at least 7 points, because there might be 
a competitor with 7 points in room number 1 (0-based index).

1)
{4, 7}
2

Returns: 3

It is possible that there are three contestants who scored 
more than 2 points: there can be one in room 0 and two 
more in room 1.
There can only be at most two contestants who scored more 
than 3 points: there can be at most one such contestant in 
each of the two rooms.
(Note that the score of each contestant has to be an 
integer.)
Therefore, John has to score at least 3 points.


2)
{999999999}
1000000000

Returns: 0

Here it is enough to gain 0 points.

3)
{95, 23, 87, 23, 82, 78, 59, 44, 12}
70

Returns: 6



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
		cout << "Testing TheOlympiadInInformatics (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1396672652;
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
		TheOlympiadInInformatics _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int sums[] = {4, 7, 0, 5};
				int k = 0;
				_expected = 7;
				_received = _obj.find(vector <int>(sums, sums+sizeof(sums)/sizeof(int)), k); break;
			}
			case 1:
			{
				int sums[] = {4, 7};
				int k = 2;
				_expected = 3;
				_received = _obj.find(vector <int>(sums, sums+sizeof(sums)/sizeof(int)), k); break;
			}
			case 2:
			{
				int sums[] = {999999999};
				int k = 1000000000;
				_expected = 0;
				_received = _obj.find(vector <int>(sums, sums+sizeof(sums)/sizeof(int)), k); break;
			}
			case 3:
			{
				int sums[] = {95, 23, 87, 23, 82, 78, 59, 44, 12};
				int k = 70;
				_expected = 6;
				_received = _obj.find(vector <int>(sums, sums+sizeof(sums)/sizeof(int)), k); break;
			}
			/*case 4:
			{
				int sums[] = ;
				int k = ;
				_expected = ;
				_received = _obj.find(vector <int>(sums, sums+sizeof(sums)/sizeof(int)), k); break;
			}*/
			/*case 5:
			{
				int sums[] = ;
				int k = ;
				_expected = ;
				_received = _obj.find(vector <int>(sums, sums+sizeof(sums)/sizeof(int)), k); break;
			}*/
			/*case 6:
			{
				int sums[] = ;
				int k = ;
				_expected = ;
				_received = _obj.find(vector <int>(sums, sums+sizeof(sums)/sizeof(int)), k); break;
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
