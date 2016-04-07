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
#define PB push_back
#define V(T) vector<T >
 
typedef long long LL;

struct ColorfulCoins {
	bool ok(int ans, const vector<long long> &ratio) {
		V(LL) slot(2);
		int i = 2;
		while(true) {
			slot.PB(pow(i, ans) - pow(i-1, ans));
			if(i > 60 || slot.back() > 60) break;
			i++;
		}
		for(LL r: ratio) {
			if(slot.size() <= r) continue;
			while(r >= 2 && slot[r] == 0) r--;
			if(r == 1) return false;
			slot[r]--;
		}
		return true;
	}

	// bool repeat(vector<long long> &ratio) {
	// 	int N = ratio.size();
	// 	sort(ratio.begin(), ratio.end())
 //  	REP(i, N) REP(j, i) if(ratio[i] == ratio[j]) return true;
 //  	return false;
 //  }

  int minQueries(vector<long long> values) {
  	int N = values.size();
  	if(N == 1) return 1;
  	vector<long long> ratio;
  	REP(i, N-1) ratio.PB(values[i+1] / values[i]);
  	// if(!repeat(ratio)) return 1;
  	int ans = 1;
  	while(!ok(ans, ratio)) ans++;
  	return ans;
  }
};

// BEGIN CUT HERE
/*
PROBLEM STATEMENT
The currency system in Colorland consists of various types 
of coins. The coin denominations follow these simple rules:


The denominations are distinct positive integers.
There is a coin type with denomination 1.
For each pair of different coin types, the denomination of 
one coin type divides the denomination of the other one.


You are given a long[] values containing all the available 
denominations in ascending order.

Coins of different denominations look exactly the same 
except that they have different colors. Each coin in 
Colorland has exactly one color. The coin colors follow 
these even simpler rules:


All coins of the same type are of the same color.
No two coins of different types are of the same color.


You know all coin denominations used in Colorland, but you 
don't know their colors. You don't even know the set of 
colors used on the coins.

For each denomination, you'd like to know the color of 
coins of this denomination. To accomplish this, you've got 
a credit card with an infinite amount of money. You can 
perform queries to an ATM which can also provide you with 
an infinite amount of money. Each query is described by a 
positive integer X, which means that you want to receive 
exactly X units of money from the ATM. The ATM will 
provide you with the requested amount. You also know that 
the requested amount will be paid using the smallest 
possible number of coins. (Note that this rule always 
uniquely determines the set of coins chosen to make the 
payment.)

Return the smallest number of queries you need to 
determine the corresponding color for each of the 
denominations. (Note that this can always be done in a 
finite number of queries.)


DEFINITION
Class:ColorfulCoins
Method:minQueries
Parameters:vector<long long>
Returns:int
Method signature:int minQueries(vector<long long> values)


CONSTRAINTS
-values will contain between 1 and 60 elements, inclusive.
-Each element of values will be between 1 and 10^18, 
inclusive.
-values will be sorted in strictly ascending order. Note 
that this also implies that all the elements of values 
will be distinct.
-For each pair of different elements in values, the 
smaller one will be a divisor of the larger one.
-values[0] will be 1.


EXAMPLES

0)
{1}

Returns: 1

There is just one coin type. We have to make a query to 
learn the color of coins.

1)
{1, 3}

Returns: 1

Just one query with X = 5 is one possible solution. As the 
ATM gives the smallest number of coins, it will give one 
coin of denomination 3 and two coins of denomination 1. 
That means, for example, that if you get one red coin and 
two blue coins, you'll understand that coins of 
denomination 3 are red, and coins of denomination 1 are 
blue.

2)
{1, 2, 4}

Returns: 2

One optimal solution is to make two queries, first X = 5 
and then X = 6. After the first query you'll receive one 
coin from each of denominations 1 and 4, and after the 
second query you'll receive one coin from each of 
denominations 2 and 4. Now you can uniquely determine the 
color of each denomination. For example, coins of 
denomination 4 have the color which appears twice among 
the received coins.

3)
{1, 2, 4, 8, 16}

Returns: 3



4)
{1, 2, 6, 30, 90, 270, 810, 2430, 7290, 29160, 87480, 
262440, 787320, 3149280,
  9447840, 28343520, 56687040, 170061120, 510183360, 
1530550080, 3061100160,
  9183300480, 27549901440, 82649704320, 247949112960, 
1239745564800, 3719236694400,
  14876946777600, 44630840332800, 223154201664000, 
669462604992000, 2008387814976000,
  6025163444928000, 12050326889856000, 24100653779712000, 
72301961339136000,
  289207845356544000, 867623536069632000}

Returns: 4



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
		cout << "Testing ColorfulCoins (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1397143372;
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
		ColorfulCoins _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				long long values[] = {1};
				_expected = 1;
				_received = _obj.minQueries(vector<long long>(values, values+sizeof(values)/sizeof(long long))); break;
			}
			case 1:
			{
				long long values[] = {1, 3};
				_expected = 1;
				_received = _obj.minQueries(vector<long long>(values, values+sizeof(values)/sizeof(long long))); break;
			}
			case 2:
			{
				long long values[] = {1, 2, 4};
				_expected = 2;
				_received = _obj.minQueries(vector<long long>(values, values+sizeof(values)/sizeof(long long))); break;
			}
			case 3:
			{
				long long values[] = {1, 2, 4, 8, 16};
				_expected = 3;
				_received = _obj.minQueries(vector<long long>(values, values+sizeof(values)/sizeof(long long))); break;
			}
			case 4:
			{
				long long values[] = {1LL, 2LL, 6LL, 30LL, 90LL, 270LL, 810LL, 2430LL, 7290LL, 29160LL, 87480LL, 262440LL, 787320LL, 3149280LL,
				                       9447840LL, 28343520LL, 56687040LL, 170061120LL, 510183360LL, 1530550080LL, 3061100160LL,
				                       9183300480LL, 27549901440LL, 82649704320LL, 247949112960LL, 1239745564800LL, 3719236694400LL,
				                       14876946777600LL, 44630840332800LL, 223154201664000LL, 669462604992000LL, 2008387814976000LL,
				                       6025163444928000LL, 12050326889856000LL, 24100653779712000LL, 72301961339136000LL,
				                       289207845356544000LL, 867623536069632000LL};
				_expected = 4;
				_received = _obj.minQueries(vector<long long>(values, values+sizeof(values)/sizeof(long long))); break;
			}
			case 5:
			{
				long long values[] = {1, 16, 256, 4096, 65536, 1048576, 16777216, 268435456, 4294967296LL, 68719476736LL, 1099511627776LL, 17592186044416LL, 281474976710656LL, 4503599627370496LL, 72057594037927936LL};
				_expected = 1;
				_received = _obj.minQueries(vector<long long>(values, values+sizeof(values)/sizeof(long long))); break;
			}
			/*case 6:
			{
				long long values[] = ;
				_expected = ;
				_received = _obj.minQueries(vector<long long>(values, values+sizeof(values)/sizeof(long long))); break;
			}*/
			/*case 7:
			{
				long long values[] = ;
				_expected = ;
				_received = _obj.minQueries(vector<long long>(values, values+sizeof(values)/sizeof(long long))); break;
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
