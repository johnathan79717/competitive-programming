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
#include <cassert>
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

#line 41 "Eggheads.cpp"
#include <string>
#include <vector>
class Eggheads {
public:
    double winProbability(int S, vector <int> yourSkills, vector <int> theirSkills) {

    }
};

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
Eggheads is a quiz show in which a five-person team of challengers competes against a five-person team of professional quizzers called the Eggheads.
You are a team of challengers and you want to maximize the probability that your team will win.
In this problem you are given the data on how good each quizzer is, and you should compute and return the probability that you win the game if you take the optimal choices.
The rules of the game are explained below.


The game consists of four individual rounds followed by a team round. The team that wins the team round wins the game.
There are S+1 subjects, numbered from 0 to S.
Subject number S is general knowledge.
This subject is used in the team round.
Four of the remaining S subjects are used in the individual rounds.


Each individual round looks as follows:


One of the possible subjects that haven't been chosen yet is chosen uniformly at random and announced.
Knowing the subject, you (the challengers) get to choose the two people who will compete against each other: one member of your team and one member of the Eggheads. You may not choose a person who has already competed in a previous individual round.
Each person who competes in this round is given three questions on the chosen subject. If one of the contestants has more correct answers than the other, they win the round.
In case of a tie, the contestants are repeatedly given one question each until there is a decision (i.e., one contestant gets their question right and the other's answer is wrong).


The team round looks the same as the individual rounds, with one exception:


On each team, all the members who have not lost an individual round get to compete. In other words, the people who lost the individual rounds have to leave the room, and then all who remained get to play the final team round.


Suppose we number the members of your team from 0 to 4.
We will assume that your team member i can answer any question on subject j with probability p[i][j].
You are given these probabilities as percentages in the vector <int> yourSkills.
More precisely, yourSkills = { p[0][0], ..., p[0][S], p[1][0], .... p[1][S], ..., p[4][S] }.


You are also given the vector <int> theirSkills that describes your opponents in the same way.


We assume that all random choices in the problem statement are mutually independent.
In the team round we assume that a team knows the answer if and only if at least one of the present team members knows the answer.


DEFINITION
Class:Eggheads
Method:winProbability
Parameters:int, vector <int>, vector <int>
Returns:double
Method signature:double winProbability(int S, vector <int> yourSkills, vector <int> theirSkills)


NOTES
-The only choice you actually get to make is the choice which pair of players should compete in each round (knowing the subject for that round).
-The subject for each round is only chosen and announced when that round begins. Notably, you do not know the subjects for future rounds when making your choice for a particular round.
-Your answer will be accepted if it has an absolute error at most 1e-9.


CONSTRAINTS
-S will be between 4 and 7, inclusive.
-yourSkills will have 5*(S+1) elements.
-theirSkills will have 5*(S+1) elements.
-Each element of yourSkills will be between 1 and 99, inclusive.
-Each element of theirSkills will be between 1 and 99, inclusive.


EXAMPLES

0)
4
{50, 50, 50, 50, 50,
 50, 50, 50, 50, 50,
 50, 50, 50, 50, 50,
 50, 50, 50, 50, 50,
 50, 50, 50, 50, 50}
{50, 50, 50, 50, 50,
 50, 50, 50, 50, 50,
 50, 50, 50, 50, 50,
 50, 50, 50, 50, 50,
 50, 50, 50, 50, 50}

Returns: 0.5

Everything is fifty-fifty, so your choices don't matter and your team has a 50 percent probability of winning the game.

1)
7
{1, 1, 1, 1, 1, 1, 1, 1,
 1, 1, 1, 1, 1, 1, 1, 1,
 1, 1, 1, 1, 1, 1, 1, 1,
 1, 1, 1, 1, 1, 1, 1, 1,
 1, 1, 1, 1, 1, 1, 1, 1}
{99, 99, 99, 99, 99, 99, 99, 99,
 99, 99, 99, 99, 99, 99, 99, 99,
 99, 99, 99, 99, 99, 99, 99, 99,
 99, 99, 99, 99, 99, 99, 99, 99,
 99, 99, 99, 99, 99, 99, 99, 99}

Returns: 3.011523858729556E-16

A team of losers vs. a team of geniuses.

2)
5
{50, 1, 1, 1, 1, 30,
 1, 1, 1, 1, 1, 1,
 1, 1, 1, 1, 1, 1,
 1, 1, 1, 1, 1, 1,
 1, 1, 1, 1, 1, 1}
{70, 99, 99, 99, 99, 99,
 20, 20, 20, 20, 20, 1,
 20, 20, 20, 20, 20, 1,
 20, 20, 20, 20, 20, 1,
 20, 20, 20, 20, 20, 1}

Returns: 0.19276528375258337


Your team member 0 is decent at subject 0 and also at subject 5 (general knowledge). The Eggheads have one elite player who is amazing at everything except for subject 0. If this player makes it to the final round, your chances of winning it are really slim. Your best bet is to hope that subject 0 comes up during the individual rounds (probability 4/5 = 0.8). If it does, you can send your team member 0 against Egghead 0. With probability 0.258 you will be able to eliminate the Egghead and suddenly you'll have the only good player in the final round. The probability that your two team members (including member 0) will win the final round against four Eggheads (other than Egghead 0) is very close to 93.1%. This option (0.8 * 0.258 * 0.931 = 0.1921584) is the only way in which you have a reasonable chance to win. The other scenarios in which you win are much less likely and contribute only a few hundredths of a percent towards the total probability of winning.


3)
4
{50, 1, 1, 1, 10,
 1, 50, 1, 1, 10,
 1, 1, 50, 1, 10,
 1, 1, 1, 50, 10,
 1, 1, 1, 1, 10}
{99, 99, 99, 20, 99,
 99, 20, 99, 99, 99,
 20, 99, 99, 99, 99,
 99, 99, 99, 99, 20,
 99, 99, 20, 99, 99}

Returns: 0.40036967200462004

Each Egghead has got one weakness. As there are only four subjects other than general knowledge, you can be sure that all of them will come up. You can assign each of your team members who knows a subject to the Egghead who is bad at that subject. With high probability this should give you a final round in which all five of you play against the last remaining Egghead -- the one who is only 20% at general knowledge. If that final round really takes place, your team should win it with probability approximately 77.338%.

4)
4
{99, 99, 99, 99, 10,
 1, 1, 1, 1, 10,
 1, 1, 1, 1, 10,
 1, 1, 1, 1, 10,
 1, 1, 1, 1, 10}
{20, 99, 99, 99, 99,
 99, 20, 99, 99, 99,
 99, 99, 20, 99, 99,
 99, 99, 99, 20, 99,
 99, 99, 99, 99, 20}

Returns: 3.812459259291132E-5

Remember that you cannot use the same person twice. Even though your player 0 really excels in four subjects, they can only compete in one individual round. Thus, the remaining three individual rounds will still quite likely be won by an Egghead, and the final round will almost surely be two challengers versus four Eggheads.

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
		cout << "Testing Eggheads (950.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1595089952;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 950.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		Eggheads _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int S = 4;
				int yourSkills[] = {50, 50, 50, 50, 50,
				                    50, 50, 50, 50, 50,
				                    50, 50, 50, 50, 50,
				                    50, 50, 50, 50, 50,
				                    50, 50, 50, 50, 50};
				int theirSkills[] = {50, 50, 50, 50, 50,
				                     50, 50, 50, 50, 50,
				                     50, 50, 50, 50, 50,
				                     50, 50, 50, 50, 50,
				                     50, 50, 50, 50, 50};
				_expected = 0.5;
				_received = _obj.winProbability(S, vector <int>(yourSkills, yourSkills+sizeof(yourSkills)/sizeof(int)), vector <int>(theirSkills, theirSkills+sizeof(theirSkills)/sizeof(int))); break;
			}
			case 1:
			{
				int S = 7;
				int yourSkills[] = {1, 1, 1, 1, 1, 1, 1, 1,
				                    1, 1, 1, 1, 1, 1, 1, 1,
				                    1, 1, 1, 1, 1, 1, 1, 1,
				                    1, 1, 1, 1, 1, 1, 1, 1,
				                    1, 1, 1, 1, 1, 1, 1, 1};
				int theirSkills[] = {99, 99, 99, 99, 99, 99, 99, 99,
				                     99, 99, 99, 99, 99, 99, 99, 99,
				                     99, 99, 99, 99, 99, 99, 99, 99,
				                     99, 99, 99, 99, 99, 99, 99, 99,
				                     99, 99, 99, 99, 99, 99, 99, 99};
				_expected = 3.011523858729556E-16;
				_received = _obj.winProbability(S, vector <int>(yourSkills, yourSkills+sizeof(yourSkills)/sizeof(int)), vector <int>(theirSkills, theirSkills+sizeof(theirSkills)/sizeof(int))); break;
			}
			case 2:
			{
				int S = 5;
				int yourSkills[] = {50, 1, 1, 1, 1, 30,
				                    1, 1, 1, 1, 1, 1,
				                    1, 1, 1, 1, 1, 1,
				                    1, 1, 1, 1, 1, 1,
				                    1, 1, 1, 1, 1, 1};
				int theirSkills[] = {70, 99, 99, 99, 99, 99,
				                     20, 20, 20, 20, 20, 1,
				                     20, 20, 20, 20, 20, 1,
				                     20, 20, 20, 20, 20, 1,
				                     20, 20, 20, 20, 20, 1};
				_expected = 0.19276528375258337;
				_received = _obj.winProbability(S, vector <int>(yourSkills, yourSkills+sizeof(yourSkills)/sizeof(int)), vector <int>(theirSkills, theirSkills+sizeof(theirSkills)/sizeof(int))); break;
			}
			case 3:
			{
				int S = 4;
				int yourSkills[] = {50, 1, 1, 1, 10,
				                    1, 50, 1, 1, 10,
				                    1, 1, 50, 1, 10,
				                    1, 1, 1, 50, 10,
				                    1, 1, 1, 1, 10};
				int theirSkills[] = {99, 99, 99, 20, 99,
				                     99, 20, 99, 99, 99,
				                     20, 99, 99, 99, 99,
				                     99, 99, 99, 99, 20,
				                     99, 99, 20, 99, 99};
				_expected = 0.40036967200462004;
				_received = _obj.winProbability(S, vector <int>(yourSkills, yourSkills+sizeof(yourSkills)/sizeof(int)), vector <int>(theirSkills, theirSkills+sizeof(theirSkills)/sizeof(int))); break;
			}
			case 4:
			{
				int S = 4;
				int yourSkills[] = {99, 99, 99, 99, 10,
				                    1, 1, 1, 1, 10,
				                    1, 1, 1, 1, 10,
				                    1, 1, 1, 1, 10,
				                    1, 1, 1, 1, 10};
				int theirSkills[] = {20, 99, 99, 99, 99,
				                     99, 20, 99, 99, 99,
				                     99, 99, 20, 99, 99,
				                     99, 99, 99, 20, 99,
				                     99, 99, 99, 99, 20};
				_expected = 3.812459259291132E-5;
				_received = _obj.winProbability(S, vector <int>(yourSkills, yourSkills+sizeof(yourSkills)/sizeof(int)), vector <int>(theirSkills, theirSkills+sizeof(theirSkills)/sizeof(int))); break;
			}
			/*case 5:
			{
				int S = ;
				int yourSkills[] = ;
				int theirSkills[] = ;
				_expected = ;
				_received = _obj.winProbability(S, vector <int>(yourSkills, yourSkills+sizeof(yourSkills)/sizeof(int)), vector <int>(theirSkills, theirSkills+sizeof(theirSkills)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int S = ;
				int yourSkills[] = ;
				int theirSkills[] = ;
				_expected = ;
				_received = _obj.winProbability(S, vector <int>(yourSkills, yourSkills+sizeof(yourSkills)/sizeof(int)), vector <int>(theirSkills, theirSkills+sizeof(theirSkills)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int S = ;
				int yourSkills[] = ;
				int theirSkills[] = ;
				_expected = ;
				_received = _obj.winProbability(S, vector <int>(yourSkills, yourSkills+sizeof(yourSkills)/sizeof(int)), vector <int>(theirSkills, theirSkills+sizeof(theirSkills)/sizeof(int))); break;
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
