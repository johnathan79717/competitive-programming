#line 2 "TellBagsApart.cpp"
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

class TellBagsApart {
public:
    string whichBagIsSmaller(vector <int> A) {
	int N = SZ(A) / 8;
	string ans;
	REP(i, N) {
	    int s1 = A[8*i+0] + A[8*i+3], d1 = A[8*i+1] + A[8*i+2], s2 = A[8*i+4] + A[8*i+7], d2 = A[8*i+5] + A[8*i+6];
	    double p1 = s1 * log(3.0 / 7) + d1 * log(4.0 / 7) + s2 * log(19.0 / 39) + d2 * log(20.0 / 39);
	    double p2 = s2 * log(3.0 / 7) + d2 * log(4.0 / 7) + s1 * log(19.0 / 39) + d1 * log(20.0 / 39);
	    ans += (p1 > p2 ? '1' : '2');
	}
	return ans;
    }
};

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
Lucy has two bags.
The bags have numbers 1 and 2 on them.
One of them (but we do not know which one) contains four white and four black marbles, the other contains twenty white and twenty black marbles.
The bags are opaque, so we cannot see what's inside.


We would like to determine which bag is which.



Consider the following experiment:


We choose a bag.
Lucy draws a random marble from the chosen bag.
She shows us the marble.
She returns the marble back into the bag.


It should be clear that in terms of our goal the above experiment is useless: even if we are allowed to repeat it multiple times, we cannot use it to learn anything useful about the two bags.



Perhaps surprisingly, the situation changes completely once we modify the experiment slightly:


We choose a bag.
Lucy draws two random marbles from the chosen bag, one after another.
She shows us the two marbles in the order in which she drew them.
She returns both marbles back into the bag.



We have performed the two-marble version of the experiment exactly 2500 times.
For each round we recorded the number of the bag we chose (1 or 2) and the colors of the two marbles Lucy drew (WW, BW, WB, or BB).


Note that while the marbles were always drawn at random (with all random choices being uniform and mutually independent), the bag from which Lucy drew in each round was chosen by us, and not necessarily uniformly at random.
You do not know anything about how we selected the bag from which Lucy should draw in each round.
In particular, you should not expect that each bag was chosen approximately 50 percent of the time.



There are eight possible records for a single experiment: 1WW, 1BW, 1WB, 1BB, 2WW, 2BW, 2WB, 2BB.
As different draws are mutually independent and their order does not matter, we just kept a count for each record.


You are given these counts: eight integers that correspond to the eight records in the order given above.
Given this information, determine the number of the bag that contains the smaller number of marbles.


-----------------------------------


Each test case contains N independent queries.
In the examples we have N = 4 and N = 20, in each other test case N = 100.
In each query you are given the eight counts as described above, and your task is to determine which bag has the smaller number of marbles.


The input is given as the vector <int> records with 8*N elements: the first 8 elements of records form the first query, the next 8 elements the second query, and so on.


Return a string with N characters, each being '1' or '2': for each query, the number of the bag with the smaller number of marbles.



Your answer for a test case will be accepted if and only if its accuracy is at least 94 percent.


(I.e., you need to get Example 0 completely correct, you can make up to 1 mistake in Example 1, and in each other test case you can make up to 6 mistakes.)


DEFINITION
Class:TellBagsApart
Method:whichBagIsSmaller
Parameters:vector <int>
Returns:string
Method signature:string whichBagIsSmaller(vector <int> records)


NOTES
-All tests for this problem were prepared before the round by actually simulating the process from the problem statement. More precisely, we prepared the generator, ran it exactly once and used the tests it generated.
-Custom challenges for this problem will not be allowed, as we cannot guarantee that you generated them in a fair way.
-During the challenge phase you can only use the example tests as possible challenge inputs.
-There are exactly 20 test cases. (This includes the two examples.)
-Under these conditions, the reference solution would pass system tests with probability significantly over 99.99 percent.


CONSTRAINTS
-In the test case in Example 0, records contains 4*8 elements.
-In the test case in Example 1, records contains 20*8 elements.
-In each other test case, records contains 100*8 elements.
-All elements of records are non-negative.
-If we break records into groups of 8, the sum of each such group is exactly 2500.
-Each query in records was generated as described in the problem statement.


EXAMPLES

0)
{262, 371, 340, 277, 303, 304, 333, 310,
 296, 326, 370, 275, 312, 329, 284, 308,
 265, 402, 372, 279, 279, 317, 307, 279,
 112, 160, 121, 102, 497, 497, 505, 506}

Returns: "1111"


When generating this test case, we used the following strategies to select the bag for Lucy:


Query 0: we first chose bag 1 exactly 1250 times and then bag 2 exactly 1250 times. (Note that 262+371+340+277 = 303+304+333+310 = 1250.)
Query 1: in each round of the experiment we chose the bag at random.
Query 2: we started by choosing bag 1, and each time Lucy drew two black marbles, we flipped to the other bag.
Query 3: we were choosing the bags in the cyclic order 1,2,2,2,2.


The return value is correct: in each query bag 1 was the one with fewer marbles.



1)
{401, 405, 345, 358, 203, 295, 284, 209,
 348, 380, 396, 361, 221, 274, 307, 213,
 361, 347, 410, 347, 246, 287, 298, 204,
 301, 389, 412, 304, 253, 289, 280, 272,
 303, 450, 388, 290, 270, 286, 246, 267,
 328, 354, 326, 362, 254, 305, 309, 262,
 290, 362, 391, 296, 285, 282, 313, 281,
 338, 335, 345, 335, 220, 338, 335, 254,
 309, 356, 348, 323, 239, 344, 343, 238,
 264, 368, 365, 258, 301, 312, 328, 304,
 256, 368, 343, 295, 296, 323, 319, 300,
 275, 318, 383, 258, 320, 340, 306, 300,
 275, 301, 323, 309, 273, 372, 366, 281,
 263, 331, 290, 309, 277, 358, 395, 277,
 261, 310, 291, 259, 301, 407, 379, 292,
 256, 318, 297, 257, 325, 358, 366, 323,
 284, 287, 274, 286, 294, 406, 358, 311,
 266, 271, 282, 256, 282, 395, 429, 319,
 270, 274, 278, 268, 308, 396, 404, 302,
 203, 283, 299, 229, 368, 401, 377, 340}

Returns: "22211212211122212221"


For each i from 0 to 19, inclusive, when generating query i we used the strategy that in each round bag 1 was chosen with probability (60-i) percent.


The return value is correct for each of the 20 queries.


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
		cout << "Testing TellBagsApart (400.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1625743239;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 400.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		TellBagsApart _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int records[] = {262, 371, 340, 277, 303, 304, 333, 310,
				                 296, 326, 370, 275, 312, 329, 284, 308,
				                 265, 402, 372, 279, 279, 317, 307, 279,
				                 112, 160, 121, 102, 497, 497, 505, 506};
				_expected = "1111";
				_received = _obj.whichBagIsSmaller(vector <int>(records, records+sizeof(records)/sizeof(int))); break;
			}
			case 1:
			{
				int records[] = {401, 405, 345, 358, 203, 295, 284, 209,
				                 348, 380, 396, 361, 221, 274, 307, 213,
				                 361, 347, 410, 347, 246, 287, 298, 204,
				                 301, 389, 412, 304, 253, 289, 280, 272,
				                 303, 450, 388, 290, 270, 286, 246, 267,
				                 328, 354, 326, 362, 254, 305, 309, 262,
				                 290, 362, 391, 296, 285, 282, 313, 281,
				                 338, 335, 345, 335, 220, 338, 335, 254,
				                 309, 356, 348, 323, 239, 344, 343, 238,
				                 264, 368, 365, 258, 301, 312, 328, 304,
				                 256, 368, 343, 295, 296, 323, 319, 300,
				                 275, 318, 383, 258, 320, 340, 306, 300,
				                 275, 301, 323, 309, 273, 372, 366, 281,
				                 263, 331, 290, 309, 277, 358, 395, 277,
				                 261, 310, 291, 259, 301, 407, 379, 292,
				                 256, 318, 297, 257, 325, 358, 366, 323,
				                 284, 287, 274, 286, 294, 406, 358, 311,
				                 266, 271, 282, 256, 282, 395, 429, 319,
				                 270, 274, 278, 268, 308, 396, 404, 302,
				                 203, 283, 299, 229, 368, 401, 377, 340};
				_expected = "22211212211122212221";
				_received = _obj.whichBagIsSmaller(vector <int>(records, records+sizeof(records)/sizeof(int))); break;
			}
			case 2:
			{
				int records[] = {3, 4, 4, 3, 0, 0, 0, 0, };
				_expected = "1";
				_received = _obj.whichBagIsSmaller(vector <int>(records, records+sizeof(records)/sizeof(int))); break;
			}
			/*case 3:
			{
				int records[] = ;
				_expected = ;
				_received = _obj.whichBagIsSmaller(vector <int>(records, records+sizeof(records)/sizeof(int))); break;
			}*/
			/*case 4:
			{
				int records[] = ;
				_expected = ;
				_received = _obj.whichBagIsSmaller(vector <int>(records, records+sizeof(records)/sizeof(int))); break;
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
