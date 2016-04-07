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
#define ALL(x) (x).begin(),(x).end()
 
typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;

struct PeriodicJumping {
  int minimalTime(int x, vector <int> jumpLengths) {
  	if(!x) return 0;
  	x = abs(x);
  	int N = jumpLengths.size();
  	LL s = x;
  	int m = x;
  	for(int i = 0; i < N+N; i++) {
  		s += jumpLengths[i%N];
  		m = max(m, jumpLengths[i%N]);
  		// cout << i << ' ' << s << ' ' << m << endl;
  		if(s - m >= m) {
  			return i + 1;
  		}
  	}
  	LL sum = 0;
  	for(int l: jumpLengths) {
  		sum += l;
  	}
  	int ans = (x / sum) * jumpLengths.size();
  	sum *= (x / sum);
  	// int i = 0;
  	// while(sum < x) {
  	// 	sum += jumpLengths[i];
  	// 	i++;
  	// }
  	// return ans + i;
  	if(sum == x) return ans;
  	for(int i = 1; i < jumpLengths.size(); i++) {
  		jumpLengths[i] += jumpLengths[i-1];
  	}
  	return ans + 1 + lower_bound(ALL(jumpLengths), x - sum) - jumpLengths.begin();
  }
};

// BEGIN CUT HERE
/*
PROBLEM STATEMENT
Frog Suwako lives on a two-dimensional plane.
Currently, she is located in the point (0, 0).
She would like to reach the point (x, 0).



Suwako jumps in a peculiar way: her jump lengths repeat in 
a periodic fashion.
The vector <int> jumpLengths contains one period of her 
jump lengths, starting with the length of the first jump 
she will make.
For example, if jumpLengths = { 2, 5 }, Suwako's jump 
lengths will be 2, 5, 2, 5, 2, 5, ...
Note that Suwako can jump onto arbitrary points in the 
plane, they are not required to have integer coordinates.



You are given the int x and the vector <int> jumpLengths.
Return the smallest non-negative integer j such that 
Suwako can reach the desired destination after j jumps.
If there is no such j, return -1 instead.

DEFINITION
Class:PeriodicJumping
Method:minimalTime
Parameters:int, vector <int>
Returns:int
Method signature:int minimalTime(int x, vector <int> 
jumpLengths)


CONSTRAINTS
-x will be between -1,000,000,000 and 1,000,000,000, 
inclusive.
-len will contain between 1 and 50 elements, inclusive.
-Each element in len will be between 1 and 1,000,000,000, 
inclusive.


EXAMPLES

0)
15
{1,2,3,4,5,6,7,8,9,10}

Returns: 5

In 4 jumps Suwako cannot get far enough. In 5 jumps she 
can reach the destination as follows: (0,0) -> (1,0) -> 
(3,0) -> (6,0) -> (10,0) -> (15,0).


1)
5
{5}

Returns: 1

One jump is enough, since the distance between (0,0) and 
(5,0) is exactly 5.

2)
1
{10}

Returns: 2

Here Suwako needs two jumps. One possible solution is to 
land at (0.5, sqrt(10*10-0.5*0.5)) after the first jump.


3)
-10
{2,3,4,500,6,7,8}

Returns: 11



4)
-1000000000
{1}

Returns: 1000000000



5)
0
{19911120}

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
		cout << "Testing PeriodicJumping (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1410966954;
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
		PeriodicJumping _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int x = 15;
				int jumpLengths[] = {1,2,3,4,5,6,7,8,9,10};
				_expected = 5;
				_received = _obj.minimalTime(x, vector <int>(jumpLengths, jumpLengths+sizeof(jumpLengths)/sizeof(int))); break;
			}
			case 1:
			{
				int x = 5;
				int jumpLengths[] = {5};
				_expected = 1;
				_received = _obj.minimalTime(x, vector <int>(jumpLengths, jumpLengths+sizeof(jumpLengths)/sizeof(int))); break;
			}
			case 2:
			{
				int x = 1;
				int jumpLengths[] = {10};
				_expected = 2;
				_received = _obj.minimalTime(x, vector <int>(jumpLengths, jumpLengths+sizeof(jumpLengths)/sizeof(int))); break;
			}
			case 3:
			{
				int x = -10;
				int jumpLengths[] = {2,3,4,500,6,7,8};
				_expected = 11;
				_received = _obj.minimalTime(x, vector <int>(jumpLengths, jumpLengths+sizeof(jumpLengths)/sizeof(int))); break;
			}
			case 4:
			{
				int x = -1000000000;
				int jumpLengths[] = {1};
				_expected = 1000000000;
				_received = _obj.minimalTime(x, vector <int>(jumpLengths, jumpLengths+sizeof(jumpLengths)/sizeof(int))); break;
			}
			case 5:
			{
				int x = 0;
				int jumpLengths[] = {19911120};
				_expected = 0;
				_received = _obj.minimalTime(x, vector <int>(jumpLengths, jumpLengths+sizeof(jumpLengths)/sizeof(int))); break;
			}
			/*case 6:
			{
				int x = ;
				int jumpLengths[] = ;
				_expected = ;
				_received = _obj.minimalTime(x, vector <int>(jumpLengths, jumpLengths+sizeof(jumpLengths)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int x = ;
				int jumpLengths[] = ;
				_expected = ;
				_received = _obj.minimalTime(x, vector <int>(jumpLengths, jumpLengths+sizeof(jumpLengths)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int x = ;
				int jumpLengths[] = ;
				_expected = ;
				_received = _obj.minimalTime(x, vector <int>(jumpLengths, jumpLengths+sizeof(jumpLengths)/sizeof(int))); break;
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
