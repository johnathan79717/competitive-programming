#line 2 "RPSMagicTrick.cpp"
#include <array>
#include <string>
#include <vector>
#include <climits>
#include <cstring>
#include <map>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <cassert>
#include <deque>
#include <stack>
#include <functional>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define FOR(I, A, B) for (int I = (A); I <= (B); ++I)
#define FORS(I, S) for (int I = 0; S[I]; ++I)
#define RS(X) scanf("%s", (X))
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define GET_POS(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
#define CASET int ___T; scanf("%d", &___T); for(int cs=1;cs<=___T;cs++)
#define MP make_pair
#define PB emplace_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define F first
#define S second
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII> VPII;
typedef pair<LL,LL> PLL;
typedef vector<PLL> VPLL;
int MOD = 1e9+7;
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}

class RPSMagicTrick {
public:
    string guess(string exampleGuess, string exampleResponse, string volunteersActions) {
	string ans;
	if (exampleResponse[0] == 'W') {
	    reverse(ALL(exampleGuess));
	}
	for (char c : volunteersActions) {
	    if (c == '?') {
		ans += exampleGuess;
	    } else {
		reverse(ALL(exampleGuess));
	    }
	}
	return ans;
    }
};

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
This problem is about a magic trick.
The trick uses some props: three pedestals, three statues of goddesses and three weapons.
Each pedestal consists of a stand for one statue and a holder for one weapon.


The pedestals are numbered 1, 2, and 3.
We will call the goddesses Aurora, Bellona and Ceres (or A, B, C for short).
The weapons are a magic orb, a magic scroll and a magic twin blade (also known as rock, paper and scissors).


Usual interactions apply: paper defeats rock, rock defeats scissors, and scissors beat paper.



At the beginning of the magic trick the magician selects a volunteer from the audience, brings them to the stage and shows them the pedestals, statues and weapons.
Then the magician puts on a blindfold. The blindfold will remain on until the end of the trick, so the magician won't be able to see anything.
Once they verify that the magician is properly blinded, he will start instructing the volunteer:


Please put a goddess on each of the three pedestals. You can choose which goddess goes where. (The volunteer does so.)
Please give each goddess one of the weapons. You can assign the weapons any way you like. Put each weapon into the holder at the goddess's pedestal. (The volunteer does so.)
During the actual trick I will make statements about fights between the goddesses and you will then help the audience by confirming whether I was right or wrong. Let's just try it out before we start: I say '[goddess1] defeats [goddess2]' and you say?
(The volunteer looks at the weapons the two goddesses currently have and truthfully answers "Right." if the magician's statement was correct and "Wrong." if it wasn't.)
Great work. But during the trick itself don't say anything out loud, that would only help me. Just show the audience thumbs up or down so that they know whether I got it right.
OK, now we are ready to start the trick. Your task is to try to catch me out by making some random swaps. Each time you make a swap, you may either swap two weapons, or you may swap two statues. (The weapons remain in place when swapping the statues.)


During the trick, the volunteer keeps on making some swaps and occasionally asks the magician to make a statement. Surprisingly, the magician is always right.



Example interaction:


Beginning of the trick: the volunteer has placed goddess C and rock on pedestal 1, goddess A and scissors on pedestal 2, and goddess B and paper on pedestal 3.
Magician: "Let's just try it out before we start: I say 'C defeats B' and you say?"
Volunteer: (Sees that C has rock and B has paper. Rock loses to paper, therefore the magician is incorrect.) "Wrong."
Magician: "Great work. But during the trick itself don't say anything out loud, that would only help me. Just show the audience thumbs up or down so that they know whether I got it right."
Magician: "OK, now we are ready to start the trick. Your task is to try to catch me out by making some random swaps. Each time you make a swap, you may either swap two weapons, or you may swap two statues."
Volunteer: swaps goddesses C and B.
Volunteer: swaps scissors and paper. (After these two swaps we have goddess B and rock on pedestal 1, goddess A and paper on pedestal 2, and goddess C and scissors on pedestal 3.)
Volunteer: "Make a guess."
Magician: "C defeats A."
Volunteer: Silently shows the audience thumbs up to confirm that the magician's guess was correct.



You are given:


The string exampleGuess with the example guess the magician made during the setup. This string is of the form "XY" for the statement "X defeats Y".
The string exampleResponse with the volunteer's response: either "Right." or "Wrong." (quotes for clarity)
The string volunteersActions that describes the volunteer's action during the actual magic trick. This string is described in detail below.


The magician can always hear when a volunteer makes a swap and he can almost always hear what type of swap it is.
If the magician hears that the volunteer swapped two statues, we'll denote it 'S'.
If the magician hears that the volunteer swapped two weapons, we'll denote it 'W'.
If the magician is sure that a swap took place but is unsure what type of objects was swapped, we'll denote it '-'.


The magician can never hear which specific objects are being swapped, nor which pedestals are involved. The magician has no other source of information except for the one described in the previous paragraph.


The string volunteersActions is a concatenation of characters from the set "SW-?". The character '?' denotes a situation in which the volunteer asked the magician to make a guess.



Your program has to play the role of the magician during the magic trick. Start with an empty string Ans. Each time the volunteer asks you a question, make a guess of the form "X defeats Y" and append "XY" to Ans. At the end, return Ans.


Your program does not have to be perfect, but it still needs to be way more precise than random guessing would be.
The sequence of guesses you return will be accepted if it has at least 80 percent accuracy.
That is, for the one specific sequence of swaps performed by the volunteer which was used to generate the test input, at least 80 percent of the guesses made by your program must be correct.


DEFINITION
Class:RPSMagicTrick
Method:guess
Parameters:string, string, string
Returns:string
Method signature:string guess(string exampleGuess, string exampleResponse, string volunteersActions)


NOTES
-In this problem only the test cases already in the system are accepted as valid test cases during the challenge phase. For these tests we know the exact sequence of swaps performed by the volunteer and we will use that sequence to evaluate the submitted solutions.
-When testing your solution, you can generate your own test cases locally so that you know what the answer should be for those test cases.
-You can still challenge during the challenge phase, but essentially the only way to submit a valid challenge is to use one of the examples as your challenge.


CONSTRAINTS
-exampleGuess will be "AB", "AC", "BA", "BC", "CA", or "CB".
-exampleResponse will be "Right." or "Wrong." (note the period)
-volunteersActions will contain between 10 and 500 characters, inclusive.
-Each character in volunteersActions will be one of "SW-?".
-volunteersActions will contain at most two '-'.
-volunteersActions will contain at least ten '?'.


EXAMPLES

0)
"BA"
"Right."
"W?S??W??SS??WS?W??"

Returns: "ABBAACBCCAABABABBACB"

The exact sequence of actions used to generate this test case was as follows:

The volunteer placed Aurora on pedestal 3, Bellona on pedestal 1, and Ceres on pedestal 2.
The volunteer gave Aurora the rock (i.e., the rock is now in the holder at pedestal 3), Bellona the paper and Ceres the scissors.
The magician made the sample guess that Bellona currently defeats Aurora.
The volunteer verified that paper does beat rock and confirmed "Right."
The magic trick begins.
'W': The volunteer swapped weapons between pedestals 1 and 2. Bellona now has the scissors and Ceres has the paper.
'?': The volunteer prompted the magician to make a guess. In our sample output the magician guessed that Aurora now defeats Bellona. As rock beats scissors, the magician was right.
'S': The volunteer swapped statues between pedestals 1 and 3. On pedestal 1 we now have Aurora (with the scissors that were left there), on pedestal 3 we have Bellona (with the rock that was left there), and Ceres with paper on pedestal 2 remained untouched.
'?': The volunteer prompted the magician to make a guess. The magician correctly guessed that currently Ceres (with paper) beats Bellona (with rock).
'?': The volunteer prompted the magician to make another guess. The magician could have just made the same guess, but to show off he made a different correct guess: Aurora defeats Ceres.
And so on. In this example, all answers by the magician were correct.


1)
"BA"
"Wrong."
"?S?WS?SW?WSWWS-???S??WWW?"

Returns: "ABCBCBBACBBACBCBABCA"

Maybe the '-' confused our magician a little. When we compare the example output to the scenario used to generate this test case, we see that two of the guesses the magician made after the '-' were incorrect. This is the smallest possible accuracy to get accepted.

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
		cout << "Testing RPSMagicTrick (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1621699557;
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
		RPSMagicTrick _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string exampleGuess = "BA";
				string exampleResponse = "Right.";
				string volunteersActions = "W?S??W??SS??WS?W??";
				_expected = "ABBAACBCCAABABABBACB";
				_received = _obj.guess(exampleGuess, exampleResponse, volunteersActions); break;
			}
			case 1:
			{
				string exampleGuess = "BA";
				string exampleResponse = "Wrong.";
				string volunteersActions = "?S?WS?SW?WSWWS-???S??WWW?";
				_expected = "ABCBCBBACBBACBCBABCA";
				_received = _obj.guess(exampleGuess, exampleResponse, volunteersActions); break;
			}
			/*case 2:
			{
				string exampleGuess = ;
				string exampleResponse = ;
				string volunteersActions = ;
				_expected = ;
				_received = _obj.guess(exampleGuess, exampleResponse, volunteersActions); break;
			}*/
			/*case 3:
			{
				string exampleGuess = ;
				string exampleResponse = ;
				string volunteersActions = ;
				_expected = ;
				_received = _obj.guess(exampleGuess, exampleResponse, volunteersActions); break;
			}*/
			/*case 4:
			{
				string exampleGuess = ;
				string exampleResponse = ;
				string volunteersActions = ;
				_expected = ;
				_received = _obj.guess(exampleGuess, exampleResponse, volunteersActions); break;
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
