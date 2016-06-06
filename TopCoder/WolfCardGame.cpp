#include <string>
#include <cassert>
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
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define PB push_back

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;
// #line 40 "WolfCardGame.cpp"
#include <string>
#include <vector>
class WolfCardGame {
public:
    vector <int> createAnswer(int N, int K) {
        for (int p: {2, 3, 5, 7}) {
            if (N % p) {
                VI ans;
                REP1(i, 1, K) {
                    ans.PB(p * i);
                }
                if (p < 7 || K < 15) {
                    return ans;
                }
                ans.pop_back();
                if (N % 7 != 1 && N % 7 != 6) {
                    ans.PB(1);
                    return ans;
                } else if (N % 7 != 2 && N % 7 != 2) {
                    ans.PB(2);
                    return ans;
                }
            }
        }
        return VI();
    }
};
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Wolf Sothe and Cat Snuke are playing a card game.
The game is played with exactly 100 cards.
The cards are numbered from 1 to 100.
The game is played as follows:

First, Cat Snuke chooses the goal: an integer N between 1 and 100, inclusive.
Then, Wolf Sothe chooses exactly K of the 100 cards and gives the chosen cards to Snuke.
Next, Cat Snuke may throw some of those K cards away. He may choose any subset of cards he was given, possibly none or all of them.
Finally, Cat Snuke may write minus signs onto any subset of the cards he still holds. For example, if he currently has the cards {1,3,4,7}, he may alter them to {-1,3,4,-7}.


At the end of the game, Snuke computes the sum of the numbers on his cards (with the added minus signs).
Snuke wins the game if the sum is exactly equal to the goal number N.
Otherwise, Sothe wins.

Your task is to help Wolf Sothe win the game.
We are now in step 2 of the game.
You are given the int N chosen by Snuke and the int K that specifies the number of cards you have to give to Snuke.
Choose those K cards in such a way that Snuke will be unable to win the game.
If you can do that, return a vector <int> with K elements: the numbers on the chosen cards.
If there are multiple solutions, you may return any of them.
If there is no solution, return an empty vector <int> instead.

DEFINITION
Class:WolfCardGame
Method:createAnswer
Parameters:int, int
Returns:vector <int>
Method signature:vector <int> createAnswer(int N, int K)


CONSTRAINTS
-N will be between 1 and 100, inclusive.
-K will be between 1 and 15, inclusive.


EXAMPLES

0)
20
4

Returns: {1, 2, 3, 4 }

If we give Snuke cards with numbers 1, 2, 3, and 4 on them, the largest sum he can form is 1+2+3+4 = 10.
Thus, he cannot reach N=20 and we win.

1)
40
1

Returns: {39 }



2)
97
6

Returns: {7, 68, 9, 10, 62, 58 }



3)
2
12

Returns: {33, 69, 42, 45, 96, 15, 57, 12, 93, 9, 54, 99 }



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
		cout << "Testing WolfCardGame (300.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1462325206;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 300.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		WolfCardGame _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 20;
				int K = 4;
				int __expected[] = {1, 2, 3, 4 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.createAnswer(N, K); break;
			}
			case 1:
			{
				int N = 40;
				int K = 1;
				int __expected[] = {39 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.createAnswer(N, K); break;
			}
			case 2:
			{
				int N = 97;
				int K = 6;
				int __expected[] = {7, 68, 9, 10, 62, 58 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.createAnswer(N, K); break;
			}
			case 3:
			{
				int N = 2;
				int K = 12;
				int __expected[] = {33, 69, 42, 45, 96, 15, 57, 12, 93, 9, 54, 99 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.createAnswer(N, K); break;
			}
			/*case 4:
			{
				int N = ;
				int K = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.createAnswer(N, K); break;
			}*/
			/*case 5:
			{
				int N = ;
				int K = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.createAnswer(N, K); break;
			}*/
			/*case 6:
			{
				int N = ;
				int K = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.createAnswer(N, K); break;
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
