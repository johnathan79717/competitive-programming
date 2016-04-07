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

struct SwitchingGame {
  int timeToWin(vector <string> states) {
  	int N = states[0].size();
  	int M = states.size();
  	V(bool) on(N), off(N), curr(N);
  	int ans = 0;
  	REP(m, M) {
  		bool turnon = false, turnoff = false;
  		REP(i, N) {
  			if(states[m][i] == '+') {
  				if(!curr[i]) {
	  				curr[i] = true;
	  				if(!on[i])
	  					turnon = true;
	  			}
	  			on[i] = off[i] = false;
  			} else if(states[m][i] == '-') {
  				if(curr[i]) {
	  				curr[i] = false;
	  				if(off[i])
	  					on[i] = off[i] = false;
	  				else
	  					turnoff = true;
	  			}
	  			on[i] = off[i] = false;
  			}
  		}
  		REP(i, N)
  			if(states[m][i] == '?') {
  				if(turnon) on[i] = true;
  				if(turnoff) off[i] = true;
  			}
  		ans += 1 + turnon + turnoff;
  		// cout << ans << endl;
  	}
  	return ans;
  }
};

// BEGIN CUT HERE
/*
PROBLEM STATEMENT
You're playing a game with lamps.
There are M lamps in a row.
The lamps are numbered 0 through M-1.
Initially, all lamps are turned off.

The game consists of N levels.
The levels are numbered 0 through N-1.
Each level is described by a string of M characters.
For each i, character i of that string gives the required 
state of lamp i.
Each of these characters will be either '+', '-', or '?'.
Here, '+' means that the lamp must be on, '-' means that 
the lamp must be off, and '?' means that the lamp may be 
in either state.

The game is played in turns.
Each turn takes one second.
In each turn, you may do one of three things:

You may choose any subset of lamps that are all turned 
off, and turn all of them on.
You may choose any subset of lamps that are all turned on, 
and turn all of them off.
You may press the big red button that says "Check!".

Whenever you press the button, the current states of all 
lamps are checked against the requirements of the current 
level.
If all lamps satisfy the requirements, you solved the 
current level.
You win the game by solving all N levels.
You must solve the levels in the given order, starting 
with level 0.
Note that the lamps do not reset between levels: you 
continue playing the next level from the state you had 
when you solved the previous level.

Return the smallest number of seconds it takes to win the 
game if you play optimally.


DEFINITION
Class:SwitchingGame
Method:timeToWin
Parameters:vector <string>
Returns:int
Method signature:int timeToWin(vector <string> states)


CONSTRAINTS
-states will contain exactly N elements.
-N will be between 1 and 50, inclusive.
-Each element of states will contain exactly M characters.
-M will be between 1 and 50, inclusive.
-Each character of states will be '+', '-' or '?'.


EXAMPLES

0)
{"++--",
 "--++"}

Returns: 5

The following sequence of actions wins the game in five 
seconds:

Turn lamps 0 and 1 on.
Press the button to win level 0.
Turn lamps 0 and 1 off.
Turn lamps 2 and 3 on.
Press the button to win level 1 and thus win the game.


1)
{"+-++",
 "+-++"}

Returns: 3

Each time you press the button you can only win a single 
level.
Even though levels 0 and 1 are identical, you have to 
press the button twice in a row to win both of them.


2)
{"++",
 "+?",
 "?+",
 "++"}

Returns: 5

Here we can simply turn both lamps on, and then use that 
configuration to win all four levels.

3)
{"+", 
 "?",
 "?",
 "?",
 "-"}

Returns: 7

At some point between winning level 0 and winning level 4 
we have to turn the lamp off.

4)
{"+??+++",
 "++??+-",
 "?++??+",
 "?-+-??",
 "??+?++",
 "++-?+?",
 "?++?-+",
 "?--+++",
 "-??-?+"}


Returns: 20



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
		cout << "Testing SwitchingGame (350.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1402156806;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 350.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		SwitchingGame _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string states[] = {"++--",
				                   "--++"};
				_expected = 5;
				_received = _obj.timeToWin(vector <string>(states, states+sizeof(states)/sizeof(string))); break;
			}
			case 1:
			{
				string states[] = {"+-++",
				                   "+-++"};
				_expected = 3;
				_received = _obj.timeToWin(vector <string>(states, states+sizeof(states)/sizeof(string))); break;
			}
			case 2:
			{
				string states[] = {"++",
				                   "+?",
				                   "?+",
				                   "++"};
				_expected = 5;
				_received = _obj.timeToWin(vector <string>(states, states+sizeof(states)/sizeof(string))); break;
			}
			case 3:
			{
				string states[] = {"+", 
				                   "?",
				                   "?",
				                   "?",
				                   "-"};
				_expected = 7;
				_received = _obj.timeToWin(vector <string>(states, states+sizeof(states)/sizeof(string))); break;
			}
			case 4:
			{
				string states[] = {"+??+++",
				                   "++??+-",
				                   "?++??+",
				                   "?-+-??",
				                   "??+?++",
				                   "++-?+?",
				                   "?++?-+",
				                   "?--+++",
				                   "-??-?+"};
				_expected = 20;
				_received = _obj.timeToWin(vector <string>(states, states+sizeof(states)/sizeof(string))); break;
			}
			/*case 5:
			{
				string states[] = ;
				_expected = ;
				_received = _obj.timeToWin(vector <string>(states, states+sizeof(states)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string states[] = ;
				_expected = ;
				_received = _obj.timeToWin(vector <string>(states, states+sizeof(states)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string states[] = ;
				_expected = ;
				_received = _obj.timeToWin(vector <string>(states, states+sizeof(states)/sizeof(string))); break;
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
