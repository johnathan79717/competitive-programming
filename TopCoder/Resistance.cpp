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
#define V(T) vector<T >
 
typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;

#line 40 "Resistance.cpp"
#include <string>
#include <vector>
class Resistance {
    public:
	vector <double> spyProbability(int P, int S, vector <string> missions) {
	    int p = 0;
	    V(double) ans(P);
	    REP(mask, (1 << P)) {
		int cnt = 0;
		REP(i, P) {
		    if ((mask >> i) & 1) {
			cnt++;
		    }
		}
		if (cnt != S) continue;
		bool fail = false;
		for (auto &mission : missions) {
		    if (mission[0] == 'F') {
			bool found = false;
			REP1(i, 1, P) {
			    if (mission[i] == '1' && ((mask >> (i-1)) & 1)) {
				found = true;
			    }
			}
			if (!found) {
			    fail = true;
			    break;
			}
		    }
		}
		if (!fail) {
		    p++;
		    REP(i, P) {
			if ((mask >> i) & 1) {
			    ans[i]++;
			}
		    }
		}
	    }
	    if (p == 0) {
		return V(double)();
	    }
	    REP(i, P) ans[i] /= p;
	    return ans;
	}
};

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
The Resistance is a multiplayer board game.
During the game each player belongs into one of two groups: some are resistance members, others are spies.
In this problem there are P players, and exactly S of them are spies.
The players are numbered 0 through P-1.




The game is played in rounds.
In each round of the game a subset of all players goes on a mission.
Each player who goes on the mission casts a secret vote on whether they want it to succeed or to fail.
Resistance members always vote for the mission to succeed, and spies may cast either vote.
(Sometimes a spy will vote for a mission to succeed in order to gain trust of the other players.)
If at least one player on a mission voted for it to fail, the mission fails.
If everybody voted for the mission to succeed, it succeeds.




You are given the ints P and S.
You are also given the vector <string> missions: data on all the missions that already took place.
Each mission is described by a string.
The first character of that string is 'F' for a failed mission or 'S' for a successful one.
The next P characters describe which players went on the mission: for each valid i, character (i+1) is '1' if player i went on the misson and '0' otherwise.




Verify whether the mission history is valid.
If there is no assignment of roles (spies / resistance members) to players that would be consistent with the given mission history, return an empty vector <double>.




If the mission history is valid, assume that each of the matching assignments of roles to players is equally likely.
Return a vector <double> containing P elements.
For each i, the i-th element of the return value should be the probability that player i is a spy, given the above assumption.


DEFINITION
Class:Resistance
Method:spyProbability
Parameters:int, int, vector <string>
Returns:vector <double>
Method signature:vector <double> spyProbability(int P, int S, vector <string> missions)


NOTES
-Each element of your return value must have an absolute or a relative error smaller than 1e-9.


CONSTRAINTS
-P will be between 3 and 10, inclusive.
-S will be between 1 and P, inclusive.
-missions will contain between 1 and 50 elements, inclusive.
-Each element of missions will contain exactly P+1 characters.
-For each element of missions, its first character will be 'S' or 'F', and the rest of the characters will be '0' or '1'.
-Each element of missions will contain at least one '1' character.


EXAMPLES

0)
4
1
{"S0110",
 "F1100",
 "S0011"}

Returns: {0.5, 0.5, 0.0, 0.0 }

There is only one spy. Players 2 and 3 cannot be the spy because neither of them went on the failed mission. Players 0 and 1 can be spies. As both scenarios are valid, each of these two players is a spy with probability 50%.

1)
4
2
{"F0100",
 "S0101",
 "F1010",
 "S1011"}

Returns: {0.5, 1.0, 0.5, 0.0 }

Now we have two spies. Only one player went to the first failed mission, so we can be certain that player 1 is a spy. Based on the second failed mission, one of players 0 and 2 must be a spy. Both possibilities match the rest of the input, so we assign each of them probability 50% of being a spy.

Note that player 1 (a known spy) once voted for a success of a mission.

2)
3
1
{"F110",
 "F101",
 "F011"}

Returns: { }

There is supposed to be only one spy, but no player went on all three failed missions, so the mission history is invalid.

3)
5
2
{"F11000",
 "S00011",
 "F10100",
 "S01111"}

Returns: {0.8, 0.4, 0.4, 0.2, 0.2 }

One possibility is that the spies are players 1 and 2. Another possibility is that one of the spies is player 0 and the other spy can be any of the other four players.

4)
9
3
{"S100001100",
 "F011110000",
 "F001000010",
 "F100010101",
 "S010010001",
 "F100001010",
 "F000100100"}

Returns: {0.3, 0.1, 0.4, 0.5, 0.2, 0.1, 0.6, 0.7, 0.1 }



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
		cout << "Testing Resistance (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1524326675;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 500.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		Resistance _obj;
		vector <double> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int P = 4;
				int S = 1;
				string missions[] = {"S0110",
				                     "F1100",
				                     "S0011"};
				double __expected[] = {0.5, 0.5, 0.0, 0.0 };
				_expected = vector <double>(__expected, __expected+sizeof(__expected)/sizeof(double));
				_received = _obj.spyProbability(P, S, vector <string>(missions, missions+sizeof(missions)/sizeof(string))); break;
			}
			case 1:
			{
				int P = 4;
				int S = 2;
				string missions[] = {"F0100",
				                     "S0101",
				                     "F1010",
				                     "S1011"};
				double __expected[] = {0.5, 1.0, 0.5, 0.0 };
				_expected = vector <double>(__expected, __expected+sizeof(__expected)/sizeof(double));
				_received = _obj.spyProbability(P, S, vector <string>(missions, missions+sizeof(missions)/sizeof(string))); break;
			}
			case 2:
			{
				int P = 3;
				int S = 1;
				string missions[] = {"F110",
				                     "F101",
				                     "F011"};
				double __expected[] = { };
				_expected = vector <double>(__expected, __expected+sizeof(__expected)/sizeof(double));
				_received = _obj.spyProbability(P, S, vector <string>(missions, missions+sizeof(missions)/sizeof(string))); break;
			}
			case 3:
			{
				int P = 5;
				int S = 2;
				string missions[] = {"F11000",
				                     "S00011",
				                     "F10100",
				                     "S01111"};
				double __expected[] = {0.8, 0.4, 0.4, 0.2, 0.2 };
				_expected = vector <double>(__expected, __expected+sizeof(__expected)/sizeof(double));
				_received = _obj.spyProbability(P, S, vector <string>(missions, missions+sizeof(missions)/sizeof(string))); break;
			}
			case 4:
			{
				int P = 9;
				int S = 3;
				string missions[] = {"S100001100",
				                     "F011110000",
				                     "F001000010",
				                     "F100010101",
				                     "S010010001",
				                     "F100001010",
				                     "F000100100"};
				double __expected[] = {0.3, 0.1, 0.4, 0.5, 0.2, 0.1, 0.6, 0.7, 0.1 };
				_expected = vector <double>(__expected, __expected+sizeof(__expected)/sizeof(double));
				_received = _obj.spyProbability(P, S, vector <string>(missions, missions+sizeof(missions)/sizeof(string))); break;
			}
			/*case 5:
			{
				int P = ;
				int S = ;
				string missions[] = ;
				double __expected[] = ;
				_expected = vector <double>(__expected, __expected+sizeof(__expected)/sizeof(double));
				_received = _obj.spyProbability(P, S, vector <string>(missions, missions+sizeof(missions)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				int P = ;
				int S = ;
				string missions[] = ;
				double __expected[] = ;
				_expected = vector <double>(__expected, __expected+sizeof(__expected)/sizeof(double));
				_received = _obj.spyProbability(P, S, vector <string>(missions, missions+sizeof(missions)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				int P = ;
				int S = ;
				string missions[] = ;
				double __expected[] = ;
				_expected = vector <double>(__expected, __expected+sizeof(__expected)/sizeof(double));
				_received = _obj.spyProbability(P, S, vector <string>(missions, missions+sizeof(missions)/sizeof(string))); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		bool _passed = _expected.size() == _received.size();
		for (unsigned i = 0; i < _received.size(); i++)
			_passed = _passed && (abs(_expected[i]-_received[i]) < 1e-9 || (_received[i] > min(_expected[i]*(1.0-1e-9), _expected[i]*(1.0+1e-9)) && _received[i] < max(_expected[i]*(1.0-1e-9), _expected[i]*(1.0+1e-9))));
		if (_passed)
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout.precision(10);
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
