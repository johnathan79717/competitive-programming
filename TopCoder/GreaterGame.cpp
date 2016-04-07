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

class GreaterGame {
	public:
	double calc(vector <int> hand, vector <int> sothe) {
		sort(hand.begin(), hand.end());
		sort(sothe.begin(), sothe.end());
		auto hand2 = hand;
		int N = hand.size();
		int ans = 0;
		for (int i = 0; i < sothe.size(); i++) {
			if (sothe[i] < 0) continue;
			auto j = upper_bound(hand.begin(), hand.end(), sothe[i]);
			if (j != hand.end()) {
				hand.erase(j);
				ans++;
			} else {
				hand.erase(hand.begin());
			}
		}
		int cnt = 0, ans2 = 0;
		for(int i = 1; i <= N * 2; i++) {
			if (find(hand2.begin(), hand2.end(), i) == hand2.end()
				&& find(sothe.begin(), sothe.end(), i) == sothe.end()) {
				cnt++;
				ans2 += hand.end() - upper_bound(hand.begin(), hand.end(), i);
			}
		}
		if (cnt)
			return ans + ans2 / (double) cnt;
		else
			return ans;
	}
};
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Cat Snuke and wolf Sothe are playing the Greater Game.
The game is played with cards.
Each card has a number written on it.
There are 2N cards.
The numbers on the cards are the integers between 1 and 2N, inclusive.

At the beginning of the game, each player gets N of the cards and chooses the order in which he wants to play them.
The game then consists of N turns.
In each turn, both players play one of their cards simultaneously.
The player who revealed the card with the larger number gets a point.

You are given a vector <int> hand.
The elements of hand are the numbers on Snuke's cards.
He can play those cards in any order he chooses.

Obviously, Snuke can determine the numbers on Sothe's cards, but he does not necessarily know the order in which Sothe is going to play his cards.
You are given the information Snuke has about Sothe in a vector <int> sothe.
For each i, element i of sothe is either the number on the card Sothe will play in turn i (0-based index), or -1 if Snuke does not know the card Sothe will play in that turn.

Snuke wants to play according to a strategy that maximizes the expected number of points he'll get.
Find that strategy and return the corresponding expected number of Snuke's points at the end of the game.

As shown in Example 0, the optimal strategy for Snuke may involve some random decisions.
However, note that before the game starts Snuke must choose the order in which he is going to play all his cards.
He is not allowed to change their order after he sees some of the cards played by Sothe.

DEFINITION
Class:GreaterGame
Method:calc
Parameters:vector <int>, vector <int>
Returns:double
Method signature:double calc(vector <int> hand, vector <int> sothe)


CONSTRAINTS
-N will be between 1 and 50, inclusive.
-hand and sothe will contain exactly N elements each.
-Each element of hand will be an integer between 1 and 2N, inclusive.
-Each element of sothe will be either -1, or an integer between 1 and 2N, inclusive.
-The positive integers in hand and sothe will be distinct.


EXAMPLES

0)
{4,2}
{-1,-1}

Returns: 1.5

Sothe will play the cards 1 and 3 in some unknown order.
The best strategy for Snuke is to flip a coin and to play his cards either in the order {2,4} or in the order {4,2} with equal probability.
This leads to two equally likely results of the game:

Snuke plays his 2 against Sothe's 1, and his 4 against Sothe's 3. In this case, Snuke wins both turns and thus scores 2 points.
Snuke plays his 2 against Sothe's 3, and his 4 against Sothe's 1. In this case, Snuke scores 1 point.

Therefore, the expected number of Snuke's points is 1.5.

1)
{4,2}
{1,3}

Returns: 2.0

If Snuke plays card 2 first and card 4 next, he is guaranteed to score 2 points.

2)
{2}
{-1}

Returns: 1.0

Sothe's only card has to be 1, and thus Snuke is guaranteed to win the only turn of this game.

3)
{1,3,5,7}
{8,-1,4,-1}

Returns: 2.5



4)
{6,12,17,14,20,8,16,7,2,15}
{-1,-1,4,-1,11,3,13,-1,-1,18}

Returns: 8.0



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
		cout << "Testing GreaterGame (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1414078607;
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
		GreaterGame _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int hand[] = {4,2};
				int sothe[] = {-1,-1};
				_expected = 1.5;
				_received = _obj.calc(vector <int>(hand, hand+sizeof(hand)/sizeof(int)), vector <int>(sothe, sothe+sizeof(sothe)/sizeof(int))); break;
			}
			case 1:
			{
				int hand[] = {4,2};
				int sothe[] = {1,3};
				_expected = 2.0;
				_received = _obj.calc(vector <int>(hand, hand+sizeof(hand)/sizeof(int)), vector <int>(sothe, sothe+sizeof(sothe)/sizeof(int))); break;
			}
			case 2:
			{
				int hand[] = {2};
				int sothe[] = {-1};
				_expected = 1.0;
				_received = _obj.calc(vector <int>(hand, hand+sizeof(hand)/sizeof(int)), vector <int>(sothe, sothe+sizeof(sothe)/sizeof(int))); break;
			}
			case 3:
			{
				int hand[] = {1,3,5,7};
				int sothe[] = {8,-1,4,-1};
				_expected = 2.5;
				_received = _obj.calc(vector <int>(hand, hand+sizeof(hand)/sizeof(int)), vector <int>(sothe, sothe+sizeof(sothe)/sizeof(int))); break;
			}
			case 4:
			{
				int hand[] = {6,12,17,14,20,8,16,7,2,15};
				int sothe[] = {-1,-1,4,-1,11,3,13,-1,-1,18};
				_expected = 8.0;
				_received = _obj.calc(vector <int>(hand, hand+sizeof(hand)/sizeof(int)), vector <int>(sothe, sothe+sizeof(sothe)/sizeof(int))); break;
			}
			case 5:
			{
				int hand[] = {2, 3};
				int sothe[] = {-1, 4};
				_expected = 1;
				_received = _obj.calc(vector <int>(hand, hand+sizeof(hand)/sizeof(int)), vector <int>(sothe, sothe+sizeof(sothe)/sizeof(int))); break;
			}
			/*case 6:
			{
				int hand[] = ;
				int sothe[] = ;
				_expected = ;
				_received = _obj.calc(vector <int>(hand, hand+sizeof(hand)/sizeof(int)), vector <int>(sothe, sothe+sizeof(sothe)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int hand[] = ;
				int sothe[] = ;
				_expected = ;
				_received = _obj.calc(vector <int>(hand, hand+sizeof(hand)/sizeof(int)), vector <int>(sothe, sothe+sizeof(sothe)/sizeof(int))); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (abs(_expected-_received) < 1e-9 || (_received > min(_expected*(1.0-1e-9), _expected*(1.0+1e-9)) && _received < max(_expected*(1.0-1e-9), _expected*(1.0+1e-9))))
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout.precision(10);
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
