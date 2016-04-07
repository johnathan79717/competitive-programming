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

struct EllysScrabble {
  string getMin(string letters, int maxDistance) {
  	string ans;
  	int N = letters.size();
  	V(bool) used(N);
  	REP(i, N) {
  		int m = -1;
  		if(i - maxDistance >= 0 && !used[i - maxDistance]) {
  			m = i - maxDistance;
  		} else {
  			REP1(j, max(0, i - maxDistance), min(N-1, i + maxDistance))
  				if(!used[j] && (m < 0 || letters[j] < letters[m]))
  					m = j;
  		}
  		ans.push_back(letters[m]);
  		used[m] = true;
  	}
  	return ans;
  }
};

// BEGIN CUT HERE
/*
PROBLEM STATEMENT
Elly is playing Scrabble with her family. The exact rules 
of the game are not important for this problem. You only 
need to know that Elly has a holder that contains a row of 
N tiles, and that there is a single letter on each of 
those tiles. (Tiles are small square pieces of wood. A 
holder is a tiny wooden shelf with room for precisely N 
tiles placed in a row.)

While Elly waits for the other players, she entertains 
herself in the following way. She slightly taps the table, 
causing the tiles on her holder jump a little and some of 
them switch places.
Formally, suppose that Elly has N tiles. There are N 
positions on the holder, we will label them 0 through N-1 
from left to right.
When Elly taps the table, the tiles on her holder will 
form some permutation of their original order.
You are given an int maxDistance with the following 
meaning: in the permutation that Elly produces by tapping 
the table, no tile will be more than maxDistance positions 
away from its original position (in either direction).

For example, suppose that before a tap the letters in 
Elly's holder formed the string "TOPCODER" when read from 
left to right.
If maxDistance is 3, one possible string after Elly taps 
the table is "CODTEPOR".
This can happen in the following way:

The letter 'T' at position 0 moves three positions to the 
right (to position 3).
The letter 'O' at position 1 remains on its initial 
position (position 1).
The letter 'P' at position 2 moves three positions to the 
right (to position 5).
The letter 'C' at position 3 moves three positions to the 
left (to position 0).
The letter 'O' at position 4 moves two positions to the 
right (to position 6).
The letter 'D' at position 5 moves three positions to the 
left (to position 2).
The letter 'E' at position 6 moves two positions to the 
left (to position 4).
The letter 'R' at position 7 remains on its initial 
position (position 7).

Note that the letter 'D' (at position 5) cannot move to 
position 1, because this would require it to move more 
than the maximal distance 3.

It turns out that the string "CODTEPOR" is the 
lexicographically smallest one Elly can get from 
"TOPCODER" with a single tap and maxDistance = 3. Now you 
want to write a program that, given the string letters and 
the int maxDistance, returns the lexicographically 
smallest string the girl can get after a single tap.

DEFINITION
Class:EllysScrabble
Method:getMin
Parameters:string, int
Returns:string
Method signature:string getMin(string letters, int 
maxDistance)


NOTES
-Given two different strings A and B of equal length, the 
lexicographically smaller one is the one that contains a 
smaller character at the first position where they differ.


CONSTRAINTS
-letters will contain between 1 and 50 characters, 
inclusive.
-letters will contain only uppercase letters from the 
English alphabet ('A'-'Z').
-maxDistance will be between 1 and 9, inclusive.


EXAMPLES

0)
"TOPCODER"
3

Returns: "CODTEPOR"

The example from the problem statement.

1)
"ESPRIT"
3

Returns: "EIPRST"

In this example the letters 'E', 'P', 'R', and 'T' stay on 
their initial places, and the letters 'S' and 'I' swap. 
Since the distance between them is exactly 3 (which also 
happens to be the maximal distance they can move), this is 
a valid final configuration.

2)
"BAZINGA"
8

Returns: "AABGINZ"

Note that the maximal distance may be greater than the 
number of letters Elly has. In such cases, the 
lexicographically smallest result is, obviously, the 
sorted sequence of letters.

3)
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
9

Returns: "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

As the input letters are already sorted, we can assume 
they'll just fall back to their initial places.

4)
"GOODLUCKANDHAVEFUN"
7

Returns: "CADDGAHEOOFLUKNNUV"



5)
"AAAWDIUAOIWDESBEAIWODJAWDBPOAWDUISAWDOOPAWD"
6

Returns: "AAAADDEIBWAEUIODWADSBIAJWODIAWDOPOAWDUOSPWW"



6)
"ABRACADABRA"
2

Returns: "AABARACBDAR"


The letter 'A' at position 0 remains on its initial place 
(position 0).
The letter 'B' at position 1 moves one position to the 
right (to position 2).
The letter 'R' at position 2 moves two positions to the 
right (to position 4).
The letter 'A' at position 3 moves two positions to the 
left (to position 1).
The letter 'C' at position 4 moves two positions to the 
right (to position 6).
The letter 'A' at position 5 moves two positions to the 
left (to position 3).
The letter 'D' at position 6 moves two positions to the 
right (to position 8).
The letter 'A' at position 7 moves two positions to the 
left (to position 5).
The letter 'B' at position 8 moves one position to the 
left (to position 7).
The letter 'R' at position 9 moves one position to the 
right (to position 10).
The letter 'A' at position 10 moves one position to the 
left (to position 9).


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
		cout << "Testing EllysScrabble (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1397318866;
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
		EllysScrabble _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string letters = "TOPCODER";
				int maxDistance = 3;
				_expected = "CODTEPOR";
				_received = _obj.getMin(letters, maxDistance); break;
			}
			case 1:
			{
				string letters = "ESPRIT";
				int maxDistance = 3;
				_expected = "EIPRST";
				_received = _obj.getMin(letters, maxDistance); break;
			}
			case 2:
			{
				string letters = "BAZINGA";
				int maxDistance = 8;
				_expected = "AABGINZ";
				_received = _obj.getMin(letters, maxDistance); break;
			}
			case 3:
			{
				string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
				int maxDistance = 9;
				_expected = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
				_received = _obj.getMin(letters, maxDistance); break;
			}
			case 4:
			{
				string letters = "GOODLUCKANDHAVEFUN";
				int maxDistance = 7;
				_expected = "CADDGAHEOOFLUKNNUV";
				_received = _obj.getMin(letters, maxDistance); break;
			}
			case 5:
			{
				string letters = "AAAWDIUAOIWDESBEAIWODJAWDBPOAWDUISAWDOOPAWD";
				int maxDistance = 6;
				_expected = "AAAADDEIBWAEUIODWADSBIAJWODIAWDOPOAWDUOSPWW";
				_received = _obj.getMin(letters, maxDistance); break;
			}
			case 6:
			{
				string letters = "ABRACADABRA";
				int maxDistance = 2;
				_expected = "AABARACBDAR";
				_received = _obj.getMin(letters, maxDistance); break;
			}
			/*case 7:
			{
				string letters = ;
				int maxDistance = ;
				_expected = ;
				_received = _obj.getMin(letters, maxDistance); break;
			}*/
			/*case 8:
			{
				string letters = ;
				int maxDistance = ;
				_expected = ;
				_received = _obj.getMin(letters, maxDistance); break;
			}*/
			/*case 9:
			{
				string letters = ;
				int maxDistance = ;
				_expected = ;
				_received = _obj.getMin(letters, maxDistance); break;
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
