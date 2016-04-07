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
#define FOR(i, c) for(auto &i: c)

long double fact(int n) {
	if(n == 0) return 1;
	else return fact(n-1) * n;
}

struct PalindromePermutations {
  double palindromeProbability(string word) {
  	vector<int> f(26);
  	FOR(c, word) {
  		f[c-'a']++;
  	}
  	int odd = -1;
  	REP(i, 26) {
  		if(f[i] % 2) {
  			if(odd >= 0) return 0.0;
  			odd = i;
  		}
  	}
  	long double ans = 1;
  	int sum = 0;
  	REP(i, 26) {
  		sum += f[i];
  		ans *= fact(f[i]);
  		ans /= fact(f[i]/2);
  	}
  	ans *= fact(sum / 2) / fact(sum);
  	return ans;
  }
};

// BEGIN CUT HERE
/*
PROBLEM STATEMENT
A palindrome is a word that reads the same forwards and 
backwards. For example, "a", "abba", and "zzz" are 
palindromes, while "ab" and "xxxyx" are not.

The anagram of a string S is any string we can obtain from 
S by rearranging its letters. For example, the string 
"haha" has exactly six anagrams: "aahh", "ahah", "ahha", 
"haah", "haha", and "hhaa".

We are given a string word. We will choose one of its 
anagrams uniformly at random. Return the probability that 
the chosen anagram will be a palindrome.

DEFINITION
Class:PalindromePermutations
Method:palindromeProbability
Parameters:string
Returns:double
Method signature:double palindromeProbability(string word)


NOTES
-The returned value must have an absolute or a relative 
error of less than 1e-9.


CONSTRAINTS
-word will contain between 1 and 50 characters, inclusive.
-Each character of word will be a lowercase English letter 
('a'-'z').


EXAMPLES

0)
"haha"

Returns: 0.3333333333333333

Each of the six anagrams of "haha" will be selected with 
probability 1/6.
Two of them are palindromes: "ahha" and "haah".
Hence, the probability of selecting a palindrome is 2/6.

1)
"xxxxy"

Returns: 0.2



2)
"xxxx"

Returns: 1.0

This word only has one anagram: "xxxx". That is a 
palindrome.

3)
"abcde"

Returns: 0.0

Regardless of how we rearrange the letters of "abcde", we 
will never get a palindrome.

4)
"hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhff"

Returns: 0.025641025641025637



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
		cout << "Testing PalindromePermutations (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1403175609;
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
		PalindromePermutations _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string word = "haha";
				_expected = 0.3333333333333333;
				_received = _obj.palindromeProbability(word); break;
			}
			case 1:
			{
				string word = "xxxxy";
				_expected = 0.2;
				_received = _obj.palindromeProbability(word); break;
			}
			case 2:
			{
				string word = "xxxx";
				_expected = 1.0;
				_received = _obj.palindromeProbability(word); break;
			}
			case 3:
			{
				string word = "abcde";
				_expected = 0.0;
				_received = _obj.palindromeProbability(word); break;
			}
			case 4:
			{
				string word = "hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhff";
				_expected = 0.025641025641025637;
				_received = _obj.palindromeProbability(word); break;
			}
			case 5:
			{
				string word = "hhhhhhhhhhhhhhhhhhhhhhhhffffffffffffffffffffffff";
				_expected = 8.38560293215575e-8;
				_received = _obj.palindromeProbability(word); break;
			}
			/*case 6:
			{
				string word = ;
				_expected = ;
				_received = _obj.palindromeProbability(word); break;
			}*/
			/*case 7:
			{
				string word = ;
				_expected = ;
				_received = _obj.palindromeProbability(word); break;
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
