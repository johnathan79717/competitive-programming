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
#define MAX(x, a) x = max(x, a)
 
typedef vector<int> VI;

int dp1[101][201], dp2[101][201];

class YetAnotherCardGame {
	public:
	int maxCards(vector <int> petr, vector <int> snuke) {
		sort(ALL(petr));
		sort(ALL(snuke));
		int N = petr.size();
		REP(j, N) REP1(k, 0, 100) {
			dp2[j][k] = dp1[j][k] = -1e9;
		}
		dp1[0][0] = dp2[0][0] = 0;
		REP1(i, 1, N) {
			// dp[i+1][0][k]
			REP(k, 101) {
				MAX(dp1[i][k], dp2[i-1][k]);
				FOR(p, petr) {
					if (p > k) {
						MAX(dp1[i][p], dp2[i-1][k]+1);
						break;
					}
				}
			}

			REP(k, 101) {
				MAX(dp2[i][k], dp1[i][k]);
				FOR(p, snuke) {
					if (p > k) {
						MAX(dp2[i][p], dp1[i][k]+1);
						break;
					}
				}
			}


				// if ((i + j) % 2 == 0) {
				// 	// petr
				// 	int c = petr[i];
				// 	REP(k, c) {
				// 		MAX(dp[i+1][j][c], dp[i][j][k] + 1);
				// 	}
				// 	REP1(k, 0, 100) {
				// 		MAX(dp[i+1][j][k], dp[i][j][k]);
				// 	}
				// } else {
				// 	// snuke
				// 	int c = snuke[j];
				// 	REP(k, c) {
				// 		MAX(dp[i][j+1][c], dp[i][j][k] + 1);
				// 	}
				// 	REP1(k, 0, 100) {
				// 		MAX(dp[i][j+1][k], dp[i][j][k]);
				// 	}
				// }
			// }
		}
		int ans = 0;
		REP1(k, 0, 100) {
			MAX(ans, dp2[N][k]);
		}
		return ans;
	}
};
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Petr and Snuke are playing a cooperative card game.
The game is played with special cards: each card is labeled with some positive integer.
The integers on cards are not necessarily distinct.


At the beginning of the game Petr is holding some cards in his hand and Snuke is holding all the other cards in his hand.
You are given vector <int>s petr and snuke that describe the state at the beginning of the game:
the elements of petr are the numbers on Petr's cards and the elements of snuke are the numbers on Snuke's cards.


During the game the players will place some of their cards onto a pile.
Initially, the pile is empty.
The players take alternating turns, Petr goes first.
In each turn, if the current player has no cards in his hand, the game ends.
Otherwise, the player must make exactly one valid move.
There are three types of valid moves:

If the pile is empty, the player may choose any card and place it onto the pile.
If the pile is not empty, the player may choose any card and place it on top of the pile. However, this move is only valid if the number on the new card is strictly greater than the number on the card that was previously on the top of the pile.
The player may always choose one of his cards and eat it.


Petr and Snuke have a common goal: they want to create a pile with as many cards as possible.
Return the size of the pile at the end of the game, assuming that they cooperate and play the game optimally.


DEFINITION
Class:YetAnotherCardGame
Method:maxCards
Parameters:vector <int>, vector <int>
Returns:int
Method signature:int maxCards(vector <int> petr, vector <int> snuke)


CONSTRAINTS
-petr and snuke will contain between 1 and 50 elements, inclusive.
-petr and snuke will contain the same number of elements.
-Each element in petr and snuke will be between 1 and 100, inclusive.


EXAMPLES

0)
{2, 5}
{3, 1}

Returns: 3

One optimal way is as follows.

Petr puts 2 onto the pile.
Snuke puts 3 onto the pile.
Petr puts 5 onto the pile.
Snuke eats 1.
The game ends because Petr has no cards in his hand.



1)
{1, 1, 1, 1, 1}
{1, 1, 1, 1, 1}

Returns: 1

The integers on cards are not necessarily distinct.

2)
{1, 4, 6, 7, 3}
{1, 7, 1, 5, 7}

Returns: 6



3)
{19, 99, 86, 30, 98, 68, 73, 92, 37, 69, 93, 28, 58, 36, 86, 32, 46, 34, 71, 29}
{28, 29, 22, 75, 78, 75, 39, 41, 5, 14, 100, 28, 51, 42, 9, 25, 12, 59, 98, 83}

Returns: 28



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
		cout << "Testing YetAnotherCardGame (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1437199204;
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
		YetAnotherCardGame _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int petr[] = {2, 5};
				int snuke[] = {3, 1};
				_expected = 3;
				_received = _obj.maxCards(vector <int>(petr, petr+sizeof(petr)/sizeof(int)), vector <int>(snuke, snuke+sizeof(snuke)/sizeof(int))); break;
			}
			case 1:
			{
				int petr[] = {1, 1, 1, 1, 1};
				int snuke[] = {1, 1, 1, 1, 1};
				_expected = 1;
				_received = _obj.maxCards(vector <int>(petr, petr+sizeof(petr)/sizeof(int)), vector <int>(snuke, snuke+sizeof(snuke)/sizeof(int))); break;
			}
			case 2:
			{
				int petr[] = {1, 4, 6, 7, 3};
				int snuke[] = {1, 7, 1, 5, 7};
				_expected = 6;
				_received = _obj.maxCards(vector <int>(petr, petr+sizeof(petr)/sizeof(int)), vector <int>(snuke, snuke+sizeof(snuke)/sizeof(int))); break;
			}
			case 3:
			{
				int petr[] = {19, 99, 86, 30, 98, 68, 73, 92, 37, 69, 93, 28, 58, 36, 86, 32, 46, 34, 71, 29};
				int snuke[] = {28, 29, 22, 75, 78, 75, 39, 41, 5, 14, 100, 28, 51, 42, 9, 25, 12, 59, 98, 83};
				_expected = 28;
				_received = _obj.maxCards(vector <int>(petr, petr+sizeof(petr)/sizeof(int)), vector <int>(snuke, snuke+sizeof(snuke)/sizeof(int))); break;
			}
			/*case 4:
			{
				int petr[] = ;
				int snuke[] = ;
				_expected = ;
				_received = _obj.maxCards(vector <int>(petr, petr+sizeof(petr)/sizeof(int)), vector <int>(snuke, snuke+sizeof(snuke)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int petr[] = ;
				int snuke[] = ;
				_expected = ;
				_received = _obj.maxCards(vector <int>(petr, petr+sizeof(petr)/sizeof(int)), vector <int>(snuke, snuke+sizeof(snuke)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int petr[] = ;
				int snuke[] = ;
				_expected = ;
				_received = _obj.maxCards(vector <int>(petr, petr+sizeof(petr)/sizeof(int)), vector <int>(snuke, snuke+sizeof(snuke)/sizeof(int))); break;
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
