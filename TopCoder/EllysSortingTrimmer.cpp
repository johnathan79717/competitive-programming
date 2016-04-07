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

struct EllysSortingTrimmer {
  string getMin(string S, int L) {
  	int N = S.size();
  	for(int i = N - L; i >= 0; i--)
  		sort(S.begin() + i, S.begin() + i + L);
  	return S.substr(0, L);
  }
};

// BEGIN CUT HERE
/*
PROBLEM STATEMENT
Elly has a string S of uppercase letters and a magic 
device that can modify the string. The strength of the 
device is an int L.

The device is used in the following way. The user enters a 
0-based index i such that 0 <= i <= length(S)-L. The 
device then performs the following changes:

It leaves the first i characters (i.e., characters with 
indices 0 through i-1) untouched.
It rearranges the next L characters (i.e., characters with 
indices i through i+L-1) into alphabetical order.
It erases all the remaining characters (i.e., characters 
with indices i+L and more). Note that for i=length(S)-L no 
characters are erased.

The girl can use this "sorting trimmer" as many times as 
she likes. After each use she is left with the new version 
of the string.

In the examples below we use brackets to highlight the 
region that shall be sorted. For example, "ABRA[CADAB]RA" 
means that L=5 and Elly chose i=4. The device keeps the 
letters in front of the brackets, sorts the letters in the 
brackets, and throws away the rest.

Here is one way how Elly could have used a device with L = 
5, starting with the string S = "ABRACADABRA":

"ABRAC[ADABR]A" -> "ABRACAABDR"
"ABR[ACAAB]DR" -> "ABRAAABC"
"A[BRAAA]BC" -> "AAAABR"


You are given the string S and the int L. Return the 
lexicographically smallest string Elly can obtain.

DEFINITION
Class:EllysSortingTrimmer
Method:getMin
Parameters:string, int
Returns:string
Method signature:string getMin(string S, int L)


NOTES
-A string A is lexicographically smaller than string B if 
A contains a smaller character in the first position where 
they differ. In case one of the strings ends before they 
have a different character, the shorter one is considered 
smaller.


CONSTRAINTS
-S will contain between 2 and 50 characters, inclusive.
-L will be between 2 and |S|, inclusive, where |S| denotes 
the number of characters in S.
-S will consist of uppercase characters of the English 
alphabet, only ('A'-'Z').


EXAMPLES

0)
"ABRACADABRA"
5

Returns: "AAAAA"

Please note that the example in the problem statement does 
not obtain the lexicographically smallest string. In fact, 
it is optimal to start by using the device on the last 
five characters of the string, transforming it from ABRACA
[DABRA] to ABRACAAABDR.

1)
"ESPRIT"
3

Returns: "EIP"

We can obtain the answer in the following steps:

ES[PRI]T -> ESIPR
E[SIP]R -> EIPS
[EIP]S -> EIP
 

2)
"BAZINGA"
7

Returns: "AABGINZ"

We can use the sorting trimmer on the entire word.

3)
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
13

Returns: "ABCDEFGHIJKLM"

Even though the string is already sorted, shorter strings 
are considered lexicographically smaller, so we can use 
the device once to make the string as short as possible.

4)
"GOODLUCKANDHAVEFUN"
10

Returns: "AACDDEFGHK"



5)
"AAAWDIUAOIWDESBEAIWODJAWDBPOAWDUISAWDOOPAWD"
21

Returns: "AAAAAAAAABBDDDDDDDEEI"



6)
"TOPCODER"
3

Returns: "CDT"



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
		cout << "Testing EllysSortingTrimmer (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1397318407;
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
		EllysSortingTrimmer _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string S = "ABRACADABRA";
				int L = 5;
				_expected = "AAAAA";
				_received = _obj.getMin(S, L); break;
			}
			case 1:
			{
				string S = "ESPRIT";
				int L = 3;
				_expected = "EIP";
				_received = _obj.getMin(S, L); break;
			}
			case 2:
			{
				string S = "BAZINGA";
				int L = 7;
				_expected = "AABGINZ";
				_received = _obj.getMin(S, L); break;
			}
			case 3:
			{
				string S = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
				int L = 13;
				_expected = "ABCDEFGHIJKLM";
				_received = _obj.getMin(S, L); break;
			}
			case 4:
			{
				string S = "GOODLUCKANDHAVEFUN";
				int L = 10;
				_expected = "AACDDEFGHK";
				_received = _obj.getMin(S, L); break;
			}
			case 5:
			{
				string S = "AAAWDIUAOIWDESBEAIWODJAWDBPOAWDUISAWDOOPAWD";
				int L = 21;
				_expected = "AAAAAAAAABBDDDDDDDEEI";
				_received = _obj.getMin(S, L); break;
			}
			case 6:
			{
				string S = "TOPCODER";
				int L = 3;
				_expected = "CDT";
				_received = _obj.getMin(S, L); break;
			}
			/*case 7:
			{
				string S = ;
				int L = ;
				_expected = ;
				_received = _obj.getMin(S, L); break;
			}*/
			/*case 8:
			{
				string S = ;
				int L = ;
				_expected = ;
				_received = _obj.getMin(S, L); break;
			}*/
			/*case 9:
			{
				string S = ;
				int L = ;
				_expected = ;
				_received = _obj.getMin(S, L); break;
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
