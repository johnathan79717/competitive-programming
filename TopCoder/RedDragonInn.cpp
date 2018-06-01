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
 
typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;

#line 40 "RedDragonInn.cpp"
#include <string>
#include <vector>
class RedDragonInn {
public:
  int maxGold(int N, int X) {
    for (int i = 0; i < 100000000; i++) {

    }
    return 0;
  }
};

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
Red Dragon Inn is a board game in which the players' characters spend time in an inn brawling and drinking.




At any moment each character has some gold coins.
If a character has "too much fun" during the game, they pass out.
When that happens, the gold they have is divided between the inn and all other characters who are left standing.
This works as follows:


The inn takes half of the coins, rounded up to the nearest integer.
The remaining coins, if any, are split evenly among the remaining characters.
The remaining coins, if any, are taken by the inn again. (This occurs whenever in step 2 the number of coins isn't divisible by the number of players.)



A character just passed out.
Let C be the number of coins they had.
You do not know the value of C.
You are given the int N: the number of characters who are still standing.
You are also given the int X: the number of gold coins each of those characters received when the C coins were split between the inn and the players.
Determine and return the largest possible value of C.


DEFINITION
Class:RedDragonInn
Method:maxGold
Parameters:int, int
Returns:int
Method signature:int maxGold(int N, int X)


CONSTRAINTS
-N will be between 2 and 100, inclusive.
-X will be between 1 and 100,000, inclusive.


EXAMPLES

0)
3
2

Returns: 17

The process of dividing 17 coins between the inn and three characters looks as follows:

First, the inn gets 9 coins (half of all coins, rounded up).
Next, the remaining 8 coins are divided between the three characters. This means that each of them gets 2 coins (i.e., 8/3, rounded down).
Finally, the inn takes the 2 coins that were left over.


It can be shown that 17 is the largest initial amount of coins for which the players receive two coins each.
For example, when dividing 18 coins the inn takes 9 and then each player takes 3.

1)
8
13

Returns: 223



2)
42
1234

Returns: 103739



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
		cout << "Testing RedDragonInn (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1524326403;
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
		RedDragonInn _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 3;
				int X = 2;
				_expected = 17;
				_received = _obj.maxGold(N, X); break;
			}
			case 1:
			{
				int N = 8;
				int X = 13;
				_expected = 223;
				_received = _obj.maxGold(N, X); break;
			}
			case 2:
			{
				int N = 42;
				int X = 1234;
				_expected = 103739;
				_received = _obj.maxGold(N, X); break;
			}
			/*case 3:
			{
				int N = ;
				int X = ;
				_expected = ;
				_received = _obj.maxGold(N, X); break;
			}*/
			/*case 4:
			{
				int N = ;
				int X = ;
				_expected = ;
				_received = _obj.maxGold(N, X); break;
			}*/
			/*case 5:
			{
				int N = ;
				int X = ;
				_expected = ;
				_received = _obj.maxGold(N, X); break;
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
