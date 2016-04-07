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
#define MAX(x, a) x = max(x, a)
#define MIN(x, a) x = min(x, a)
 
typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;

class AToughGame {
	public:
	double expectedGain(vector <int> prob, vector <int> value) {
		
	}
};
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
Allen is playing a very difficult game.
The game has N levels, numbered 0 through N-1 in the order in which they have to be completed.
Each level can be described by two parameters: prob[i] and value[i].
The meaning of these parameters is as follows:

Whenever Allen plays level i, he either completes it or dies. The probability that he completes the level is always prob[i]/1000. (He always tries his best to complete each level.)
At the end of level i there is a treasure chest that contains value[i] units of gold. When Allen completes the level, he picks up the gold from the chest.




At the beginning of a new game Allen starts in level 0 with no gold.
For each valid i, whenever Allen completes level i, he moves on to play level i+1.
The game ends as soon as he completes level N-1.



Whenever Allen dies, several things happen in order:

All the gold that is currently neither in a treasure chest nor carried by Allen is removed from the game.
All the gold Allen is currently carrying is dropped at the beginning of the level where he died.
    As soon as Allen reaches this level again, he will be able to pick it all up again, even before attempting to complete the level.
    (Note that if he dies again before collecting it, this gold will be lost forever.)
New gold is added to all chests to refill them to the amounts they originally contained.
Allen is returned to the beginning of level 0. He is carrying no gold.




Hence, after Allen's death there is always at most one pile of gold that is not in a treasure chest.
That pile is at the beginning of the level where Allen most recently died.



You are given the vector <int>s prob and value with N elements each.
In order to avoid precision errors, prob will always be such that the probability that Allen wins the entire game without ever dying will be at least 10^(-6).
Compute and return the expected amount of gold Allen will carry when he wins the game.


DEFINITION
Class:AToughGame
Method:expectedGain
Parameters:vector <int>, vector <int>
Returns:double
Method signature:double expectedGain(vector <int> prob, vector <int> value)


NOTES
-Your return value must have an absolute or relative error smaller than 1e-6


CONSTRAINTS
-prob,value will contain between 2 and 1,000 elements, inclusive.
-prob,value will have the same length.
-Each element of prob,value will be between 1 and 1,000, inclusive.
-The probability of beating all levels without dying is at least 10^-6.


EXAMPLES

0)
{1000,500}
{3,4}

Returns: 10.0


This game has 2 levels.
Allen will beat level 0 with probability 1, and he will beat level 1 with probability 1/2.
Allen will gain 3 units of gold for beating level 0, and 4 units of gold for beating level 1.



Here is an example how Allen could have played the game:

He completes level 0 and collects 3 gold.
He dies in level 1. He drops the 3 gold at the beginning of level 1. Treasure chest in level 0 is refilled to 3 gold.
He completes level 0 again and collects the new 3 gold.
As he reaches level 1, he collects the 3 gold he dropped when he first died.
Again, he dies in level 1. This time he drops 6 gold at the beginning of level 1. Treasure chest in level 0 is refilled again.
He completes level 0 for the third time and collects the new 3 gold.
As he reaches level 1, he collects the 6 gold he dropped when he last died. He now has 9 gold.
This time he completes level 1 and collects the 4 gold from its chest.
As Allen completes level 1, the game ends. He is currently carrying 13 gold.




Allen will win level 1 exactly once.
It can be shown that on average Allen will play (and win) level 0 twice.
Thus, the expected amount of gold he will have at the end is 2*3 + 4 = 10.


1)
{1000,1}
{3,4}

Returns: 3003.9999999999977



2)
{500,500,500,500,500}
{1,2,3,4,5}

Returns: 16.626830517153095


In this game there are 5 levels, and Allen can complete each of them with probability 1/2.
Here is an example how Allen could have played this game:




He completes levels 0, 1, and 2, collecting 1+2+3 = 6 gold.
He then dies in level 3 and drops the 6 gold at the beginning of level 3.
Starting again, he completes levels 0, 1, 2, and 3. He will collect 1+2+3 gold for completing the first three levels, then 6 gold for reaching level 3, and finally 4 gold for completing level 3. Allen now has a total of 16 gold.
He then dies in level 4 and drops the 16 gold at the beginning of level 4.
Allen starts the game for the third time, completes level 0 and gains 1 gold.
This time, he dies in level 1. The 16 gold that was waiting in level 4 is now lost forever. Instead, Allen just drops the 1 gold he is currently carrying at the beginning of level 1.
In his fourth attempt Allen completes all five levels in a row. He ends the game with 1+2+3+4+5 gold collected when completing the levels, and the 1 extra gold that he collected at the beginning of level 1.




The probability of this particular playthrough is 1/(2^(16)).


3)
{250,750}
{1000,1}

Returns: 1067.6666666666667



4)
{916,932,927,988,958,996,944,968,917,939,960,965,960,998,920,990,915,972,995,916,902,
968,970,962,922,959,994,915,996,996,994,986,945,947,912,946,972,951,973,965,921,910,
938,975,942,950,900,983,960,998,982,980,902,974,952,938,900,962,920,931,964,974,953,
995,946,946,903,921,923,985,919,996,930,915,991,967,996,911,999,936,1000,962,970,929,
966,960,930,920,958,926,983}
{583,428,396,17,163,815,31,536,175,165,532,781,29,963,331,987,599,497,380,180,780,25,
931,607,784,613,468,140,488,604,401,912,204,785,697,173,451,849,714,914,650,652,338,
336,177,147,22,652,901,548,370,9,118,487,779,567,818,440,10,868,316,666,690,714,623,
269,501,649,324,773,173,54,391,745,504,578,81,627,319,301,16,899,658,586,604,83,520,
81,181,943,157}

Returns: 54204.93356505282



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
		cout << "Testing AToughGame (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1440226969;
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
		AToughGame _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int prob[] = {1000,500};
				int value[] = {3,4};
				_expected = 10.0;
				_received = _obj.expectedGain(vector <int>(prob, prob+sizeof(prob)/sizeof(int)), vector <int>(value, value+sizeof(value)/sizeof(int))); break;
			}
			case 1:
			{
				int prob[] = {1000,1};
				int value[] = {3,4};
				_expected = 3003.9999999999977;
				_received = _obj.expectedGain(vector <int>(prob, prob+sizeof(prob)/sizeof(int)), vector <int>(value, value+sizeof(value)/sizeof(int))); break;
			}
			case 2:
			{
				int prob[] = {500,500,500,500,500};
				int value[] = {1,2,3,4,5};
				_expected = 16.626830517153095;
				_received = _obj.expectedGain(vector <int>(prob, prob+sizeof(prob)/sizeof(int)), vector <int>(value, value+sizeof(value)/sizeof(int))); break;
			}
			case 3:
			{
				int prob[] = {250,750};
				int value[] = {1000,1};
				_expected = 1067.6666666666667;
				_received = _obj.expectedGain(vector <int>(prob, prob+sizeof(prob)/sizeof(int)), vector <int>(value, value+sizeof(value)/sizeof(int))); break;
			}
			case 4:
			{
				int prob[] = {916,932,927,988,958,996,944,968,917,939,960,965,960,998,920,990,915,972,995,916,902,
				             968,970,962,922,959,994,915,996,996,994,986,945,947,912,946,972,951,973,965,921,910,
				             938,975,942,950,900,983,960,998,982,980,902,974,952,938,900,962,920,931,964,974,953,
				             995,946,946,903,921,923,985,919,996,930,915,991,967,996,911,999,936,1000,962,970,929,
				             966,960,930,920,958,926,983};
				int value[] = {583,428,396,17,163,815,31,536,175,165,532,781,29,963,331,987,599,497,380,180,780,25,
				              931,607,784,613,468,140,488,604,401,912,204,785,697,173,451,849,714,914,650,652,338,
				              336,177,147,22,652,901,548,370,9,118,487,779,567,818,440,10,868,316,666,690,714,623,
				              269,501,649,324,773,173,54,391,745,504,578,81,627,319,301,16,899,658,586,604,83,520,
				              81,181,943,157};
				_expected = 54204.93356505282;
				_received = _obj.expectedGain(vector <int>(prob, prob+sizeof(prob)/sizeof(int)), vector <int>(value, value+sizeof(value)/sizeof(int))); break;
			}
			/*case 5:
			{
				int prob[] = ;
				int value[] = ;
				_expected = ;
				_received = _obj.expectedGain(vector <int>(prob, prob+sizeof(prob)/sizeof(int)), vector <int>(value, value+sizeof(value)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int prob[] = ;
				int value[] = ;
				_expected = ;
				_received = _obj.expectedGain(vector <int>(prob, prob+sizeof(prob)/sizeof(int)), vector <int>(value, value+sizeof(value)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int prob[] = ;
				int value[] = ;
				_expected = ;
				_received = _obj.expectedGain(vector <int>(prob, prob+sizeof(prob)/sizeof(int)), vector <int>(value, value+sizeof(value)/sizeof(int))); break;
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
