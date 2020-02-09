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
#include <cassert>
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
 
typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;

#line 41 "MedianFaking.cpp"
#include <string>
#include <vector>
class MedianFaking {
public:
    vector <int> minimize(int F, int M, vector <int> data, int goal) {
	vector<int> sorted = data;
	sort(ALL(sorted));
	int N = data.size();
	int mid = sorted[(N - 1) / 2];
	if (mid == goal) {
	    return {0, 0};
	}
	int sum = 0;
	vector<int> v;
	int a1 = 0, a2 = 0;
	REP(i, F) {
	    int cnt = 0;
	    REP(j, M) {
		if (mid < goal) {
		    if (data[i * M + j] < goal) {
			cnt++;
		    }
		} else {
		    if (data[i * M + j] > goal) {
			cnt++;
		    }
		}
	    }
	    v.push_back(cnt);
	    sum += cnt;
	}
	sum -= (mid < goal ? (N - 1) / 2 : N / 2);
	sort(ALL(v));
	while (a2 < sum) {
	    a2 += v.back();
	    v.pop_back();
	    a1++;
	}
	return { a1, sum };
    }
};

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
A group of F friends is working on an assignment for their Physics class.
Each of the friends made exactly M measurements of the same property. Their outcomes are given
in the vector <int> data. (More precisely, data is a concatenation 
of F arrays of length M each: the first M elements are the measurements 
made by one person, the next M elements are the measurements made by a second person, and so on.)


The median of a sequence is the element that would be in the middle if the sequence were sorted.
If the length of the sequence is even, we'll say that the smaller of the two middle elements is the median.
For example, in this problem the median of {10, 40, 30, 20} is 20.


According to the friends' textbook, the value they all measured should be goal.
The friends would like to tweak some of their measurements to make the median of data exactly equal to goal.
Your task is as follows:


Determine X = the smallest number of people who have to cheat and modify some of the values they measured.
Suppose we want to have exactly X cheaters. Determine Y = the smallest number of individual measurements that will have to be changed.
Return {X, Y}.


DEFINITION
Class:MedianFaking
Method:minimize
Parameters:int, int, vector <int>, int
Returns:vector <int>
Method signature:vector <int> minimize(int F, int M, vector <int> data, int goal)


NOTES
-When modifying an element of data the friends can set it to any real value they like. In particular, the new value doesn't have to satisfy the input constraints.


CONSTRAINTS
-F and M will be positive.
-F*M will not exceed 1,000.
-data will have exactly F*M elements.
-Each element of data will be between 0 and 99, inclusive.
-goal will be between 0 and 99, inclusive.


EXAMPLES

0)
5
5
{1,2,3,4,5, 10,9,8,7,6, 25,24,23,22,21, 18,16,17,19,20, 11,13,12,14,15}
8

Returns: {1, 5 }

There are five friends, each of them made five measurements. Spaces in data are included for better readability.
The current median of data is 13. In order to bring it down to 8 it is enough if just one person cheats. For example, person #4 could change their measurements from {18,16,17,19,20} to {3,1,3,5,7}.
It can be shown that for this input there is no solution in which the only cheater changes fewer than all five of their measurements.

1)
5
5
{1,2,25,24,23, 3,4,22,21,20, 5,6,19,18,17, 7,16,15,14,13, 8,12,11,10,9}
8

Returns: {2, 5 }

In this test case the friends have the same collection of measurements but in this case there is no single person who can change the median to 5 by tweaking their outcomes. We need at least two cheaters.
One optimal solution: person 2 changes two of their outcomes to get {3,4,7,21,8} and person 4 changes three more to get {7,1,15,-1,-47}.

2)
1
4
{10, 40, 30, 20}
20

Returns: {0, 0 }

The example from the problem statement. The median is already 20, no changes are needed.

3)
4
3
{3,8,12, 3,8,12, 3,8,12, 8,12,17}
12

Returns: {1, 2 }

The measurements given in data are not necessarily distinct.

4)
5
1
{10, 20, 30, 40, 50}
23

Returns: {1, 1 }

The desired median is not among the measurements these five friends made. Luckily, there is an easy fix: person #3 should change their outcome from 30 to 23 and they will be done.

*/
// END CUT HERE

// BEGIN CUT HERE
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
		cout << "Testing MedianFaking (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1559660409;
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
		MedianFaking _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int F = 5;
				int M = 5;
				int data[] = {1,2,3,4,5, 10,9,8,7,6, 25,24,23,22,21, 18,16,17,19,20, 11,13,12,14,15};
				int goal = 8;
				int __expected[] = {1, 5 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.minimize(F, M, vector <int>(data, data+sizeof(data)/sizeof(int)), goal); break;
			}
			case 1:
			{
				int F = 5;
				int M = 5;
				int data[] = {1,2,25,24,23, 3,4,22,21,20, 5,6,19,18,17, 7,16,15,14,13, 8,12,11,10,9};
				int goal = 8;
				int __expected[] = {2, 5 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.minimize(F, M, vector <int>(data, data+sizeof(data)/sizeof(int)), goal); break;
			}
			case 2:
			{
				int F = 1;
				int M = 4;
				int data[] = {10, 40, 30, 20};
				int goal = 20;
				int __expected[] = {0, 0 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.minimize(F, M, vector <int>(data, data+sizeof(data)/sizeof(int)), goal); break;
			}
			case 3:
			{
				int F = 4;
				int M = 3;
				int data[] = {3,8,12, 3,8,12, 3,8,12, 8,12,17};
				int goal = 1;
				int __expected[] = {1, 2 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.minimize(F, M, vector <int>(data, data+sizeof(data)/sizeof(int)), goal); break;
			}
			case 4:
			{
				int F = 5;
				int M = 1;
				int data[] = {10, 20, 30, 40, 50};
				int goal = 23;
				int __expected[] = {1, 1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.minimize(F, M, vector <int>(data, data+sizeof(data)/sizeof(int)), goal); break;
			}
			case 5:
			{
				int F = 2;
				int M = 2;
				int data[] = {2, 4, 2, 4};
				int goal = 1;
				int __expected[] = {1, 1};
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.minimize(F, M, vector <int>(data, data+sizeof(data)/sizeof(int)), goal); break;
			}
			/*case 6:
			{
				int F = ;
				int M = ;
				int data[] = ;
				int goal = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.minimize(F, M, vector <int>(data, data+sizeof(data)/sizeof(int)), goal); break;
			}*/
			/*case 7:
			{
				int F = ;
				int M = ;
				int data[] = ;
				int goal = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.minimize(F, M, vector <int>(data, data+sizeof(data)/sizeof(int)), goal); break;
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
			cout << "           Expected: {";
			for (unsigned i = 0; i < _expected.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _expected[i];
			}
			cout << " }" << endl;
			cout << "           Received: {";
			for (unsigned i = 0; i < _received.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _received[i];
			}
			cout << " }" << endl;
		}
	}
}

// END CUT HERE
