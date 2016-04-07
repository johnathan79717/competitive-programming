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
 
typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;

class TheFootballDivOne {
	public:
	int find(int yourScore, vector <int> scores, vector <int> numberOfTeams) {
		
	}
};
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// John and Brus are the managers of your football team.
The team is taking part in a tournament.
The tournament is almost over: each team still has exactly two matches to play (possibly both against the same opponent).
Note that two different teams play in each match.


If a match ends in a draw, each team scores 1 point.
Otherwise, the winner gets 3 points and the loser gets 0 points.


You are given an int yourScore: the number of points your team has scored so far.
You are also given two vector <int>s scores and numberOfTeams that describe the other teams.
For each valid i, there are numberOfTeams[i] other teams that each have scored scores[i] points so far.
Note that the total number of teams in the tournament is 1 + sum(numberOfTeams).


At the end of the tournament, teams will be ranked by the total number of points.
Teams with the same number of points will be ranked according to their total score.


Given the above information, you are interested in the best possible (1-based) final rank of your team.
Note that you do not know which matches are still to be played, so you assume the best possible combination of matches that is consistent with the given information.


In other words, you want to find the smallest X such that there exists a valid set of future match results that causes your team to end in X-th place.
Note that your team's score can be arbitrarily good, so you may always assume that your team is placed above all other teams that have the same score as you.


Compute and return the X defined above.

DEFINITION
Class:TheFootballDivOne
Method:find
Parameters:int, vector <int>, vector <int>
Returns:int
Method signature:int find(int yourScore, vector <int> scores, vector <int> numberOfTeams)


NOTES
-The current scores given in yourScore and scores do not necessarily correspond to a valid game history.


CONSTRAINTS
-yourScore will be between 0 and 100,000, inclusive.
-scores will contain between 1 and 47 elements, inclusive.
-scores and numberOfTeams will contain the same number of elements.
-Each element of scores will be between 0 and 100,000, inclusive.
-Each element of numberOfTeams will be between 1 and 100,000, inclusive.
-All elements of scores will be distinct.


EXAMPLES

0)
4
{7}
{1}

Returns: 1

There are two teams in the tournament.
They play two games against each other.
If your team wins both games it will be on the top of the scoreboard with 10 points.

1)
1
{7}
{2}

Returns: 2

There are three teams.
Your team has 1 point and each of the other two teams has 7 points.
With three teams, the remaining matches are determined uniquely: each pair of teams must play a single match against each other.
The best possible final result for your team is to place second with 7 points.

2)
1
{7, 1}
{2, 1}

Returns: 1

There are four teams - two with 1 point each and two with 7 points each.
If each 1-point team plays against each 7-point team and wins, each team will have 7 points in the end.

3)
11
{5, 12, 17, 19, 99, 13, 15, 14}
{2, 4, 8, 2, 1, 3, 25, 3}

Returns: 4



4)
1
{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}
{245, 365, 135, 367, 4345, 6729, 5806, 431, 256, 178}

Returns: 1650



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
		cout << "Testing TheFootballDivOne (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1421375348;
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
		TheFootballDivOne _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int yourScore = 4;
				int scores[] = {7};
				int numberOfTeams[] = {1};
				_expected = 1;
				_received = _obj.find(yourScore, vector <int>(scores, scores+sizeof(scores)/sizeof(int)), vector <int>(numberOfTeams, numberOfTeams+sizeof(numberOfTeams)/sizeof(int))); break;
			}
			case 1:
			{
				int yourScore = 1;
				int scores[] = {7};
				int numberOfTeams[] = {2};
				_expected = 2;
				_received = _obj.find(yourScore, vector <int>(scores, scores+sizeof(scores)/sizeof(int)), vector <int>(numberOfTeams, numberOfTeams+sizeof(numberOfTeams)/sizeof(int))); break;
			}
			case 2:
			{
				int yourScore = 1;
				int scores[] = {7, 1};
				int numberOfTeams[] = {2, 1};
				_expected = 1;
				_received = _obj.find(yourScore, vector <int>(scores, scores+sizeof(scores)/sizeof(int)), vector <int>(numberOfTeams, numberOfTeams+sizeof(numberOfTeams)/sizeof(int))); break;
			}
			case 3:
			{
				int yourScore = 11;
				int scores[] = {5, 12, 17, 19, 99, 13, 15, 14};
				int numberOfTeams[] = {2, 4, 8, 2, 1, 3, 25, 3};
				_expected = 4;
				_received = _obj.find(yourScore, vector <int>(scores, scores+sizeof(scores)/sizeof(int)), vector <int>(numberOfTeams, numberOfTeams+sizeof(numberOfTeams)/sizeof(int))); break;
			}
			case 4:
			{
				int yourScore = 1;
				int scores[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
				int numberOfTeams[] = {245, 365, 135, 367, 4345, 6729, 5806, 431, 256, 178};
				_expected = 1650;
				_received = _obj.find(yourScore, vector <int>(scores, scores+sizeof(scores)/sizeof(int)), vector <int>(numberOfTeams, numberOfTeams+sizeof(numberOfTeams)/sizeof(int))); break;
			}
			/*case 5:
			{
				int yourScore = ;
				int scores[] = ;
				int numberOfTeams[] = ;
				_expected = ;
				_received = _obj.find(yourScore, vector <int>(scores, scores+sizeof(scores)/sizeof(int)), vector <int>(numberOfTeams, numberOfTeams+sizeof(numberOfTeams)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int yourScore = ;
				int scores[] = ;
				int numberOfTeams[] = ;
				_expected = ;
				_received = _obj.find(yourScore, vector <int>(scores, scores+sizeof(scores)/sizeof(int)), vector <int>(numberOfTeams, numberOfTeams+sizeof(numberOfTeams)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int yourScore = ;
				int scores[] = ;
				int numberOfTeams[] = ;
				_expected = ;
				_received = _obj.find(yourScore, vector <int>(scores, scores+sizeof(scores)/sizeof(int)), vector <int>(numberOfTeams, numberOfTeams+sizeof(numberOfTeams)/sizeof(int))); break;
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
