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

#line 40 "BearBall.cpp"
#include <string>
#include <vector>
class BearBall {
public:
  int countThrows(vector <int> x, vector <int> y) {

  }
};

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// N bears are playing a game.
For the purpose of this problem, each bear is just a single point in the plane.
You are given the coordinates of the bears: the vector <int>s x and y, each with N elements.
For each valid i there is a bear at (x[i], y[i]).

The game they play is played in rounds.
There is a single ball.
At the beginning of each round one of the bears holds the ball.
This bear chooses a direction and throws the ball in that direction.
The ball will travel along a straight line.
As soon as the ball hits another bear for the first time, that bear will catch the ball and the round will end.
It is not allowed to throw the ball in a direction where it won't hit any other bear.

At the beginning of the game, the bears choose two special roles: 
one bear will be the Startbear and another bear will be the Goalbear.
The Startbear has the ball at the beginning of the game.
The game ends when the Goalbear gets the ball.
Bears always play optimally — they always finish the game in the smallest possible number of rounds.

There are exactly N*(N-1) ways to choose the Startbear and the Goalbear.
For each of those ways, determine the smallest possible number of rounds the game may take.
Return the sum of those N*(N-1) numbers.

DEFINITION
Class:BearBall
Method:countThrows
Parameters:vector <int>, vector <int>
Returns:int
Method signature:int countThrows(vector <int> x, vector <int> y)


CONSTRAINTS
-N will be between 2 and 1500, inclusive.
-x will contain exactly N elements.
-y will contain exactly N elements.
-Each element in x and in y will be between -20,000 and 20,000, inclusive.
-No two points will coincide.


EXAMPLES

0)
{1,4,2}
{1,10,7}

Returns: 6

There are three bears. They stand at (1,1), (4,10), and (2,7).

There are six ways to choose the Startbear and the Goalbear.
In each of those six cases the game will have a single round, because the Startbear can throw the ball directly at the Goalbear.
So, the answer is 6.

1)
{0,0,0,1,1}
{0,1,2,0,1}

Returns: 22

There are five bears. They stand at (0,0), (0,1), (0,2), (1,0), and (1,1).

There are 20 ways to choose the two special bears. In 18 of those 20 ways a single throw is enough. In each of the remaining two ways the bears need two rounds of the game.

Consider the situation when the Startbear is at (0,0) and the Goalbear is at (0,2). 
This game cannot be won in a single round:
if the Startbear throws a ball in the direction of the Goalbear, the ball will hit the bear at (0,1) and that bear will catch it.

There are multiple ways to win that game in two rounds.
For example, after the Startbear hits the bear at (0,1), that bear will throw the ball to the Goalbear.
Another optimal strategy is to start by throwing the ball from (0,0) to (1,1).
This is shown in the figure below; the bear with the ball is painted red.



2)
{5,7,9,11}
{4,3,2,1}

Returns: 20



3)
{10,10,50,50,90,90}
{5,17,5,17,5,17}

Returns: 34



4)
{-100, -90, -80, -70, -85, -90, 0, 20}
{-5, -8, -13, -21, -13, -13, -13, -69}

Returns: 68



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
		cout << "Testing BearBall (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1495288975;
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
		BearBall _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int x[] = {1,4,2};
				int y[] = {1,10,7};
				_expected = 6;
				_received = _obj.countThrows(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 1:
			{
				int x[] = {0,0,0,1,1};
				int y[] = {0,1,2,0,1};
				_expected = 22;
				_received = _obj.countThrows(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 2:
			{
				int x[] = {5,7,9,11};
				int y[] = {4,3,2,1};
				_expected = 20;
				_received = _obj.countThrows(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 3:
			{
				int x[] = {10,10,50,50,90,90};
				int y[] = {5,17,5,17,5,17};
				_expected = 34;
				_received = _obj.countThrows(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 4:
			{
				int x[] = {-100, -90, -80, -70, -85, -90, 0, 20};
				int y[] = {-5, -8, -13, -21, -13, -13, -13, -69};
				_expected = 68;
				_received = _obj.countThrows(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			/*case 5:
			{
				int x[] = ;
				int y[] = ;
				_expected = ;
				_received = _obj.countThrows(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int x[] = ;
				int y[] = ;
				_expected = ;
				_received = _obj.countThrows(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int x[] = ;
				int y[] = ;
				_expected = ;
				_received = _obj.countThrows(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
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
