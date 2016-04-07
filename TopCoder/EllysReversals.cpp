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
#define PER(i,n) for(int i=(n)-1;i>=0;i--)
#define MP make_pair

struct EllysReversals {
	bool eq(string &s1, string&s2) {
		if(s1.size() != s2.size()) return false;
		if(s1.size() % 2 && s1.back() != s2.back()) return false;
		multiset<pair<char, char> > set1, set2;
		REP(i, s1.size() / 2) {
			set1.insert(minmax(s1.at(2*i), s1.at(2*i+1)));
			set2.insert(minmax(s2.at(2*i), s2.at(2*i+1)));
		}
		return set1 == set2;
	}
  int getMin(vector <string> words) {
  	int N = words.size();
  	PER(i, N) {
  		REP(j, i) {
  			if(eq(words.at(j), words.at(i))) {
  				// cout << words[j] << ' ' << words[i] << endl;
  				words.pop_back();
  				words.erase(words.begin() + j);
  				i--;
  				break;
  			}
  		}
  	}
  	return words.size();
  }
};

// BEGIN CUT HERE
/*
PROBLEM STATEMENT
Elly has a list of several distinct strings given in the vector <string> words. She can apply the following operation as many times as she wants (including zero times):

Choose one of the words and call it S.
Choose an even number k between 2 and |S|, inclusive, where |S| is the length of S (thus, chose a prefix with even length).
Reverse the order of the first k characters of S (thus, reverse the chosen prefix without the rest of the word).

For example, if she has the word "topcoder", she can reverse its first 2, 4, 6, or all 8 characters. If she chooses to reverse its first 4 characters, the change will be: "topcoder" -> "cpotoder". If at a later time she decides to chose the same string and reverse all of its characters (which is also a valid prefix with even length), she would get "cpotoder"->"redotopc".

After performing some operations two strings might become equal. If that happens, Elly crosses them out and continues playing her game with the remaining strings only, i.e. they "disappear" from the list. The girl wonders what is the minimal number of strings she can end up with.

For example, suppose she has the strings {"esprit", "god", "redotopc", "odcpoter", "dog"}. The word "redotopc" can be converted to "topcoder" by first reversing all 8 characters and then reversing the first 4. The word "odcpoter" can also be converted to "topcoder" by performing "odcpoter" -> "docpoter" -> "topcoder". At that point the words become equal and disappear, leaving Elly only with {"esprit", "god", "dog"}. This is where she gets stuck: The words "god" and "dog" cannot become equal, because she can only reverse prefixes with even length. Thus, the minimal number of words she can get is 3.

Given her initial strings in vector <string> words, return an int indicating the minimal number of strings she can be left with.

DEFINITION
Class:EllysReversals
Method:getMin
Parameters:vector <string>
Returns:int
Method signature:int getMin(vector <string> words)


CONSTRAINTS
-words will contain between 1 and 50 elements, inclusive.
-Each element of words will contain between 1 and 50 characters, inclusive.
-Each element of words will consist only of lowercase letters of the English alphabet ('a'-'z').
-All elements of words will be distinct.


EXAMPLES

0)
{"esprit", "god", "redotopc", "odcpoter", "dog"}

Returns: 3

The example from the problem statement.

1)
{"no", "zaphod", "just", "very", "improbable"}

Returns: 5

It is possible that she cannot get rid of any of the words.

2)
{"rats", "live", "stressed", "to", "act", "as", "star", "desserts", "of", "evil", "cat", "sa", "fo", "ot"}

Returns: 0

It is possible that she ends up with zero words.

3)
{"topcoder", "redocpot", "doretopc", "cpotdoer", "harlemshake"}

Returns: 1

Sometimes it is possible to match different words when using a different sequence of operations.

4)
{"iprlzgukfggzg", "bmhxvjbrtkbxy", "khapjiabbny", "nqlwgmcyvdikt",
 "nxromtvtpug", "leealcapovm", "ushnxwjczczbmd", "bwhykzupcux",
 "xrlboyuwlnsp", "bbjoketeheezfs", "dxfztrldomjqkv", "dkbktqdtgfujcut",
 "zfybzyuxgpnt", "ffmsldrdftode", "vopuufksxd", "pqhbsiujwda",
 "yhwbkzupcux", "hkbabnapjiy", "zqsqefrrzehtxn", "yovinyguyudmv"}

Returns: 16



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
		cout << "Testing EllysReversals (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1396458278;
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
		EllysReversals _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string words[] = {"esprit", "god", "redotopc", "odcpoter", "dog"};
				_expected = 3;
				_received = _obj.getMin(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
			}
			case 1:
			{
				string words[] = {"no", "zaphod", "just", "very", "improbable"};
				_expected = 5;
				_received = _obj.getMin(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
			}
			case 2:
			{
				string words[] = {"rats", "live", "stressed", "to", "act", "as", "star", "desserts", "of", "evil", "cat", "sa", "fo", "ot"};
				_expected = 0;
				_received = _obj.getMin(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
			}
			case 3:
			{
				string words[] = {"topcoder", "redocpot", "doretopc", "cpotdoer", "harlemshake"};
				_expected = 1;
				_received = _obj.getMin(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
			}
			case 4:
			{
				string words[] = {"iprlzgukfggzg", "bmhxvjbrtkbxy", "khapjiabbny", "nqlwgmcyvdikt",
				                  "nxromtvtpug", "leealcapovm", "ushnxwjczczbmd", "bwhykzupcux",
				                  "xrlboyuwlnsp", "bbjoketeheezfs", "dxfztrldomjqkv", "dkbktqdtgfujcut",
				                  "zfybzyuxgpnt", "ffmsldrdftode", "vopuufksxd", "pqhbsiujwda",
				                  "yhwbkzupcux", "hkbabnapjiy", "zqsqefrrzehtxn", "yovinyguyudmv"};
				_expected = 16;
				_received = _obj.getMin(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
			}
			case 5:
			{
				string words[] = {"dxkhoxqw", "eawok", "ikpwzsixc", "eaowk", "jqovb", "wpszxiikc", "ajbzmph", "cybfeim", "wqxdhkox", "szixkipwc", "woaek", "imxeyymb", "japmbzh", "voqjb", "crdzf", "dmfyqq", "pxnmllys", "smzhomj", "lfeieb", "beflei", "fymdqq", "wqxohkdx", "zszxdo", "llyspxnm", "zeobgie", "mszhomj", "qjvob", "beiefl", "bmxeyyim", "yyimxemb", "dzrcf", "juxjvkxmb", "zxzsdo", "ycfbeim", "cyfbeim", "xzszod", "rqtgbrw", "dmyfqq", "mpajbzh", "omhzmsj", "brgtqrw", "jxkvmxjub", "bogizee", "ujjxxmvkb", "rczdf", "syllpxmn", "zeigobe"};
				_expected = 15;
				_received = _obj.getMin(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
			}
			/*case 6:
			{
				string words[] = ;
				_expected = ;
				_received = _obj.getMin(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string words[] = ;
				_expected = ;
				_received = _obj.getMin(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
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
