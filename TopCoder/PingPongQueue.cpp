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

#line 40 "PingPongQueue.cpp"
#include <string>
#include <vector>
class PingPongQueue {
public:
  vector <int> whoPlaysNext(vector <int> skills, int N, int K) {
    queue<int> q;
    for (int s : skills) {
      q.push(s);
    }
    int winner = q.front(); q.pop();
    int streak = 0;
    int loser;
    while (K) {
      if (streak == N) {
        q.push(winner);
        winner = q.front(); q.pop();
        streak = 0;
        continue;
      }
      loser = q.front(); q.pop();
      if (winner < loser) {
        swap(winner, loser);
        streak = 0;
      }
      streak++;
      K--;
      q.push(loser);
    }
    return { loser, winner };
  }
};

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// This task is about a group of people who like to play ping pong.
All games of ping pong mentioned in this task are one-on-one games.

You are given a vector <int> skills.
Each element of skills is the skill level of one person in the group.
The skill levels are all distinct.
Whenever two people play a game of ping pong, the one with the higher skill level always wins.

All people in the group would like to play but they only have a single table.
Therefore, only two people can play at any given time.

There will be a sequence of games, numbered starting from 1.
Game 1 will be played by the players who correspond to skills[0] and skills[1].
All the remaining people will form a queue, in the order in which they are given in skills.
After each game the following things will happen, in order:

The person who lost the game leaves the table and goes to the end of the queue.
If the person who won the game has already won N games in a row, they also leave the table and they go to the end of the queue (behind the person who lost the last game).
While there are fewer than two people at the table, the first person in the queue leaves the queue and goes to the table.
The two people at the table play the next game.


You are given the vector <int> skills, the int N, and an int K.
Return the two-element vector <int> { L, W }, where L and W are the skills of the loser and the winner of game K, in this order.

DEFINITION
Class:PingPongQueue
Method:whoPlaysNext
Parameters:vector <int>, int, int
Returns:vector <int>
Method signature:vector <int> whoPlaysNext(vector <int> skills, int N, int K)


CONSTRAINTS
-skills will contain between 2 and 50 elements, inclusive.
-Each element of skills will be between 1 and 50, inclusive.
-All elements of skills will be distinct.
-N will be between 1 and 100, inclusive.
-K will be between 1 and 1000, inclusive.


EXAMPLES

0)
{1, 2, 3}
2
2

Returns: {2, 3 }

In all annotations, we call people by their skill. For example, "player 7" means "the player whose skill level is 7".

In this example players 1 and 2 play the first game, and player 2 wins.
For the second game, player 3 joins player 2, so we return { 2, 3 }.

1)
{1, 2, 3}
2
4

Returns: {1, 2 }

The sequence of games is as follows:

Player 1 loses to player 2.
Player 2 loses to player 3.
Player 1 loses to player 3. After this player 1 joins the queue, player 3 also steps down because he just won 2 games in a row and joins the queue.
Player 1 loses to player 2.


2)
{49, 24, 26, 12, 5, 33, 25, 30, 35, 41, 46, 23, 21, 3, 38, 43, 11, 19, 34, 29, 20, 32, 39, 7, 50}
10
399

Returns: {12, 50 }



3)
{30, 12}
34
80

Returns: {12, 30 }



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
		cout << "Testing PingPongQueue (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1491062934;
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
		PingPongQueue _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int skills[] = {1, 2, 3};
				int N = 2;
				int K = 2;
				int __expected[] = {2, 3 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.whoPlaysNext(vector <int>(skills, skills+sizeof(skills)/sizeof(int)), N, K); break;
			}
			case 1:
			{
				int skills[] = {1, 2, 3};
				int N = 2;
				int K = 4;
				int __expected[] = {1, 2 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.whoPlaysNext(vector <int>(skills, skills+sizeof(skills)/sizeof(int)), N, K); break;
			}
			case 2:
			{
				int skills[] = {49, 24, 26, 12, 5, 33, 25, 30, 35, 41, 46, 23, 21, 3, 38, 43, 11, 19, 34, 29, 20, 32, 39, 7, 50};
				int N = 10;
				int K = 399;
				int __expected[] = {12, 50 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.whoPlaysNext(vector <int>(skills, skills+sizeof(skills)/sizeof(int)), N, K); break;
			}
			case 3:
			{
				int skills[] = {30, 12};
				int N = 34;
				int K = 80;
				int __expected[] = {12, 30 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.whoPlaysNext(vector <int>(skills, skills+sizeof(skills)/sizeof(int)), N, K); break;
			}
			/*case 4:
			{
				int skills[] = ;
				int N = ;
				int K = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.whoPlaysNext(vector <int>(skills, skills+sizeof(skills)/sizeof(int)), N, K); break;
			}*/
			/*case 5:
			{
				int skills[] = ;
				int N = ;
				int K = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.whoPlaysNext(vector <int>(skills, skills+sizeof(skills)/sizeof(int)), N, K); break;
			}*/
			/*case 6:
			{
				int skills[] = ;
				int N = ;
				int K = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.whoPlaysNext(vector <int>(skills, skills+sizeof(skills)/sizeof(int)), N, K); break;
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
