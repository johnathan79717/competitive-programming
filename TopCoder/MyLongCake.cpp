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

struct MyLongCake {
  int cut(int n) {
  	V(bool) cuts(n);
  	for(int p = 1; p * p <= n; p++) {
  		if(n % p) continue;
  		if(p != 1) {
  			for(int k = 0; k < n; k += p)
  				cuts[k] = true;
  		}
  		for(int k = 0; k < n; k += (n/p))
  			cuts[k] = true;
  	}
  	int ans = 0;
  	REP(i, cuts.size()) if(cuts[i]) {
  		ans++;
  		// cout << i << endl;
  	}
  	return ans;
  }
};

// BEGIN CUT HERE
/*
PROBLEM STATEMENT
You have a long thin cake. For simplicity, we can consider 
the cake to be one-dimensional. The length of the cake is 
n. 

You are expecting some friends. You are going to cut the 
cake into multiple pieces before the friends arrive.

When the friends arrive, you will divide the cake among 
them, using the following procedure: starting at the 
beginning of the cake, you will first give some 
consecutive pieces to your first friend, then some 
consecutive pieces to your second friend, and so on.

Of course, you want to be fair. That is, each of your 
friends should receive the same total amount of cake. (The 
number of pieces may be different for different friends, 
but the sum of their lengths must be the same.)

As we stated above, you want to cut the cake before your 
friends arrive. However, you don't know how many friends 
will actually come. You only know that their count will be 
a divisor of n smaller than n.

You are given the int n. You want to cut the cake in such 
a way that for each valid number of friends it will be 
possible to give each of them the same amount of cake when 
using the above procedure. Return the smallest possible 
number of pieces after you cut the cake.

DEFINITION
Class:MyLongCake
Method:cut
Parameters:int
Returns:int
Method signature:int cut(int n)


CONSTRAINTS
-n will be between 2 and 100,000, inclusive.


EXAMPLES

0)
6

Returns: 4

The best possible solution is to cut the cake into 4 
pieces. Let's call the pieces A, B, C, and D, in order. 
Their lengths will be 2, 1, 1, and 2.

As n=6, there will be 1, 2, or 3 friends. If there is just 
one friend, she gets all four pieces. If there are two 
friends, the first gets A+B and the second gets C+D. If 
there are three friends, the first gets A, the second gets 
B+C, and the third gets D.

Note that the order of parts matters. For example, 
dividing the cake into parts of length 2, 1, 2, and 1 is 
not a valid solution.

1)
3

Returns: 1



2)
15

Returns: 7

You are expecting 1, 3, or 5 friends.

3)
100000

Returns: 60000



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
		cout << "Testing MyLongCake (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1398081604;
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
		MyLongCake _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 6;
				_expected = 4;
				_received = _obj.cut(n); break;
			}
			case 1:
			{
				int n = 3;
				_expected = 1;
				_received = _obj.cut(n); break;
			}
			case 2:
			{
				int n = 15;
				_expected = 7;
				_received = _obj.cut(n); break;
			}
			case 3:
			{
				int n = 100000;
				_expected = 60000;
				_received = _obj.cut(n); break;
			}
			/*case 4:
			{
				int n = ;
				_expected = ;
				_received = _obj.cut(n); break;
			}*/
			/*case 5:
			{
				int n = ;
				_expected = ;
				_received = _obj.cut(n); break;
			}*/
			/*case 6:
			{
				int n = ;
				_expected = ;
				_received = _obj.cut(n); break;
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
