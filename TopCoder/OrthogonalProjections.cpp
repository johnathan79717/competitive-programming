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

#line 41 "OrthogonalProjections.cpp"
#include <string>
#include <vector>
class OrthogonalProjections {
public:
    vector <int> generate(int n) {

    }
};

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
If point X lies on the line L, the orthogonal projection of X onto L is X itself. Otherwise, the orthogonal projection of X onto L is the unique point Y on L such that XY is orthogonal to L.


Suppose you are given a finite sequence S of points in the plane. Two lines L1 and L2 are equivalent if the orthogonal projections of points of S onto L1 are in the same order as the projections of points of S onto L2.


For example, suppose the points in S are S[0]=(0,0), S[1]=(0,1), and S[2]=(1,2). 
The figure below shows two blue lines that are equivalent: the points of S projected onto each of them lie in the order 0, 1, 2.



The second figure below shows the same sequence of points and two other lines. On the red line the projections of 0 and 1 coincide, so the order is 0+1, 2. The green line has the projections in order 1, 0, 2.
Thus, these lines represent two new equivalence classes.



(Note that lines don't have direction. A line on which the projections lie in the order 1, 0, 2 is the same as a line on which they are in the order 2, 0, 1.)


For a fixed sequence S of points in the plane let g(S) denote the number of equivalence classes among lines in that plane.


You are given a int n. If there is no S such that g(S) = n, return an empty vector <int>. Otherwise, find any such S with the following additional properties:


S must contain between 1 and 500 points, inclusive.
The points in S must be distinct.
The coordinates of each point in S must be integers between 0 and 10^9, inclusive.


Then, return the following vector <int>: { S[0].x, S[0].y, S[1].x, S[1].y, ... }.


DEFINITION
Class:OrthogonalProjections
Method:generate
Parameters:int
Returns:vector <int>
Method signature:vector <int> generate(int n)


NOTES
-For the given constraints, whenever there is a sequence S such that g(S) = n, there is always such a sequence that also satisfies the additional requirements on the length of S and range of values for coordinates.


CONSTRAINTS
-n will be between 1 and 100,000, inclusive.


EXAMPLES

0)
6

Returns: {0, 0, 0, 1, 1, 2 }

This is the example from the problem statement. We have already shown lines from three equivalence classes. The other three possibilities are listed below.

Projections are in order 0, 1+2.
Projections are in order 1, 0+2.
Projections are in order 0, 2, 1.


1)
47

Returns: { }



2)
8

Returns: {0, 0, 0, 2, 7, 1, 14, 0, 14, 2 }


For the line y = 0 the projections lie in the order 0+1, 2, 3+4.


(Note that for example 0+1, 3+4, 2 would have been a different order, but for these five points that order does not correspond to any line in the plane.)


For another class of lines the projections lie in the order 1, 0+2+4, 3.


3)
100

Returns: {70, 30, 16, 85, 51, 41, 29, 72, 47, 6, 15, 45, 71, 30, 45, 18, 22, 58, 79, 45, 58, 17 }



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
		cout << "Testing OrthogonalProjections (600.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1553944650;
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
		OrthogonalProjections _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 6;
				int __expected[] = {0, 0, 0, 1, 1, 2 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.generate(n); break;
			}
			case 1:
			{
				int n = 47;
				int __expected[] = { };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.generate(n); break;
			}
			case 2:
			{
				int n = 8;
				int __expected[] = {0, 0, 0, 2, 7, 1, 14, 0, 14, 2 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.generate(n); break;
			}
			case 3:
			{
				int n = 100;
				int __expected[] = {70, 30, 16, 85, 51, 41, 29, 72, 47, 6, 15, 45, 71, 30, 45, 18, 22, 58, 79, 45, 58, 17 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.generate(n); break;
			}
			/*case 4:
			{
				int n = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.generate(n); break;
			}*/
			/*case 5:
			{
				int n = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.generate(n); break;
			}*/
			/*case 6:
			{
				int n = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.generate(n); break;
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
