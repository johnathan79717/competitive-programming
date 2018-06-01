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

#line 40 "SquadConstructor2.cpp"
#include <string>
#include <vector>
class SquadConstructor2 {
public:
  int teamget(int n, int k, vector <int> friends) {

  }
};

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Hero is the coach of a team of his friends who play a strategic team game.


In the game there are n strategies a team can play.
Each of Hero's players can only play some subset of those strategies well.
For each player the subset of strategies they can play well is different from the others.

A set of strategies can be encoded into an n-bit number: 
If we number the strategies 0 through n-1, the code of a set of strategies will be the number that has, in base 2, ones on positions that correspond to the strategies in the set.


For example, the set {0,3,4} is encoded as the number 11001 in base 2.
(Bits 0, 3, and 4 are ones and the remaining bits of this number are zeros.)
The value of this number in base 10 is 2^4 + 2^3 + 2^0 = 25.


You are given the int n and the vector <int> friends.
Each element of friends encodes the set of strategies one of the players on Hero's team can play well.


Finally, you are given an int k.
Hero needs to choose exactly k of his players to form a squad that will take part in the next match.


The strength of a squad is calculated as follows:
For each strategy, compute the square of the number of players on the squad that play that strategy well.
The strength of the squad is the sum of all those squares.


Compute and return the largest possible strength of a k-player squad.

DEFINITION
Class:SquadConstructor2
Method:teamget
Parameters:int, int, vector <int>
Returns:int
Method signature:int teamget(int n, int k, vector <int> friends)


CONSTRAINTS
-n will be between 3 and 8, inclusive.
-k will be between 2 and 8, inclusive.
-friends will contain between k and 2^n elements, inclusive.
-Each element in friends will be between 0 and 2^n-1, inclusive.
-All elements in friends will be distinct.


EXAMPLES

0)
3
4
{0,1,2,3}

Returns: 8

As there are only four players and Hero needs a four-player squad, he has to select all four players.
Two of them can play strategy 0 well, two of them can play strategy 1 well, and nobody can play strategy 2 well.
Thus, the total strength of this squad is 2^2 + 2^2 + 0^2 = 8.


1)
3
4
{0,1,2,3,5}

Returns: 14

Select everyone except for the player who cannot play any strategy well.
This produces a squad with the strength 3^2 + 2^2 + 1^2 = 14.


2)
8
4
{0,1,2,3,7}

Returns: 19



3)
8
4
{3,4,7,8,9,10,11,15,16,17,18,19,20,21,23,26,27,28,29,33,35,37,41,42,43,45,47,48,49,53,54,55,56,57,58,60,61,62,64,66,67,68,72,74,75,78,80,81,82,83,87,89,90,91,93,94,95,98,99,100,101,103,105,108,111,112,113,115,118,119,121,122,123,125,127,128,129,130,131,137,143,144,147,148,151,152,155,156,160,163,167,169,171,172,173,178,179,180,182,186,188,190,192,193,194,195,196,198,199,204,207,208,212,213,215,217,219,220,221,225,228,231,233,237,240,243,244,245,246,247,249,251,252,254}

Returns: 100



4)
3
5
{0,1,2,3,5}

Returns: 14



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
		cout << "Testing SquadConstructor2 (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1521306702;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 1000.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		SquadConstructor2 _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 3;
				int k = 4;
				int friends[] = {0,1,2,3};
				_expected = 8;
				_received = _obj.teamget(n, k, vector <int>(friends, friends+sizeof(friends)/sizeof(int))); break;
			}
			case 1:
			{
				int n = 3;
				int k = 4;
				int friends[] = {0,1,2,3,5};
				_expected = 14;
				_received = _obj.teamget(n, k, vector <int>(friends, friends+sizeof(friends)/sizeof(int))); break;
			}
			case 2:
			{
				int n = 8;
				int k = 4;
				int friends[] = {0,1,2,3,7};
				_expected = 19;
				_received = _obj.teamget(n, k, vector <int>(friends, friends+sizeof(friends)/sizeof(int))); break;
			}
			case 3:
			{
				int n = 8;
				int k = 4;
				int friends[] = {3,4,7,8,9,10,11,15,16,17,18,19,20,21,23,26,27,28,29,33,35,37,41,42,43,45,47,48,49,53,54,55,56,57,58,60,61,62,64,66,67,68,72,74,75,78,80,81,82,83,87,89,90,91,93,94,95,98,99,100,101,103,105,108,111,112,113,115,118,119,121,122,123,125,127,128,129,130,131,137,143,144,147,148,151,152,155,156,160,163,167,169,171,172,173,178,179,180,182,186,188,190,192,193,194,195,196,198,199,204,207,208,212,213,215,217,219,220,221,225,228,231,233,237,240,243,244,245,246,247,249,251,252,254};
				_expected = 100;
				_received = _obj.teamget(n, k, vector <int>(friends, friends+sizeof(friends)/sizeof(int))); break;
			}
			case 4:
			{
				int n = 3;
				int k = 5;
				int friends[] = {0,1,2,3,5};
				_expected = 14;
				_received = _obj.teamget(n, k, vector <int>(friends, friends+sizeof(friends)/sizeof(int))); break;
			}
			/*case 5:
			{
				int n = ;
				int k = ;
				int friends[] = ;
				_expected = ;
				_received = _obj.teamget(n, k, vector <int>(friends, friends+sizeof(friends)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int n = ;
				int k = ;
				int friends[] = ;
				_expected = ;
				_received = _obj.teamget(n, k, vector <int>(friends, friends+sizeof(friends)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int n = ;
				int k = ;
				int friends[] = ;
				_expected = ;
				_received = _obj.teamget(n, k, vector <int>(friends, friends+sizeof(friends)/sizeof(int))); break;
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
