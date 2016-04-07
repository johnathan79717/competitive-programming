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

struct SplitStoneGame {
  string winOrLose(vector <int> number) {
  	if(number.size() < 3) return "LOSE";
  	bool allOne = true;
  	FOR(n, number) if(n > 1) allOne = false;
  	if(allOne) return "LOSE";
  	if(number.size() % 2) return "WIN";
  	return "LOSE";
  }
};

// BEGIN CUT HERE
/*
PROBLEM STATEMENT

Shiny likes to play games.
Her favorite games are games with pebbles (small stones).
Today, she is playing such a game with her friend Lucy.

Initially, there are N piles of stones.
You are given a vector <int> number with N elements.
Each element of number is the number of stones in one of 
the piles.

The players take alternating turns.
Shiny plays first.
In each turn, the current player must:

Choose a pile X that has at least two stones.
Split the chosen pile X into two non-empty parts A and B. 
(The parts can have arbitrary sizes, as long as both are 
non-empty.)
Choose two piles Y and Z. (Y and Z must be different non-
empty piles other than X.)
Add all stones from A to the pile X, and all stones from B 
to the pile Y.


For example, if the current piles are {1, 2, 50}, the 
current player could:

Choose the pile with 50 stones as X.
Split it into two parts with 25 stones each.
Choose the other two piles (the ones with 1 and 2 stones) 
to be Y and Z.
Add all stones from A to the pile X, and all stones from B 
to the pile Y. At the end of the turn, there are two piles 
of stones: one with 26 and one with 27 stones.


The player who cannot make a valid move loses the game.
Assume that both players play the game optimally.
Return the string "WIN" (quotes for clarity) if Shiny wins 
the game, and "LOSE" if she does not.


DEFINITION
Class:SplitStoneGame
Method:winOrLose
Parameters:vector <int>
Returns:string
Method signature:string winOrLose(vector <int> number)


CONSTRAINTS
-number will contain between 1 and 50 elements, inclusive.
-Each element of number will be between 1 and 50, inclusive.


EXAMPLES

0)
{1, 1, 1}

Returns: "LOSE"

Shiny can't choose a pile X that has at least two stones, 
so she loses.

1)
{2, 2}

Returns: "LOSE"

After Shiny chooses one of the piles as X and splits it 
into two piles with one stone each, she is
unable to choose Y and Z, because there is only one pile 
left to choose from at the moment. Thus,
she cannot make a valid move and therefore she loses the 
game.

2)
{1, 1, 2}

Returns: "WIN"

Shiny can choose the last pile as X, split it into 1+1 
stone, and add those stones to the other two
piles. This is a valid move that produces two piles with 
two stones each, and it is now Lucy's turn. 
As we saw in Example 1, Lucy now has no valid move left, 
thus she loses the game and Shiny is the
winner.

3)
{1, 2, 3, 4, 3, 2, 2, 4, 3, 1, 4, 4, 1, 2, 4, 4, 1, 4, 3, 
1, 4, 2, 1}

Returns: "WIN"



4)
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 3, 1, 9, 1, 3, 
1, 1, 1, 1, 1}

Returns: "LOSE"



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
		cout << "Testing SplitStoneGame (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1399287610;
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
		SplitStoneGame _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int number[] = {1, 1, 1};
				_expected = "LOSE";
				_received = _obj.winOrLose(vector <int>(number, number+sizeof(number)/sizeof(int))); break;
			}
			case 1:
			{
				int number[] = {2, 2};
				_expected = "LOSE";
				_received = _obj.winOrLose(vector <int>(number, number+sizeof(number)/sizeof(int))); break;
			}
			case 2:
			{
				int number[] = {1, 1, 2};
				_expected = "WIN";
				_received = _obj.winOrLose(vector <int>(number, number+sizeof(number)/sizeof(int))); break;
			}
			case 3:
			{
				int number[] = {1, 2, 3, 4, 3, 2, 2, 4, 3, 1, 4, 4, 1, 2, 4, 4, 1, 4, 3, 1, 4, 2, 1};
				_expected = "WIN";
				_received = _obj.winOrLose(vector <int>(number, number+sizeof(number)/sizeof(int))); break;
			}
			case 4:
			{
				int number[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 3, 1, 9, 1, 3, 1, 1, 1, 1, 1};
				_expected = "LOSE";
				_received = _obj.winOrLose(vector <int>(number, number+sizeof(number)/sizeof(int))); break;
			}
			/*case 5:
			{
				int number[] = ;
				_expected = ;
				_received = _obj.winOrLose(vector <int>(number, number+sizeof(number)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int number[] = ;
				_expected = ;
				_received = _obj.winOrLose(vector <int>(number, number+sizeof(number)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int number[] = ;
				_expected = ;
				_received = _obj.winOrLose(vector <int>(number, number+sizeof(number)/sizeof(int))); break;
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
			cout << "           Expected: " << "\"" << _expected << "\"" << endl;
			cout << "           Received: " << "\"" << _received << "\"" << endl;
		}
	}
}

// END CUT HERE
