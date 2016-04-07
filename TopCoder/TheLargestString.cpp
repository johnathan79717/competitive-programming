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
#define ALL(x) (x).begin(),(x).end()
#define REP(i,n) for(int i=0;i<(n);i++)
#define PB push_back

struct TheLargestString {
  string find(string s, string t) {
  	string s1, t1;
  	int i = 0;
  	while(i < s.size()) {
	  	i = max_element(s.begin()+i, s.end()) - s.begin();
	  	s1.PB(s[i]); t1.PB(t[i]);
	  	i++;
	  }
	  while(true) {
		  i = 0;
		  while(i < t1.size() && t1[i] == s1.back()) i++;
		  int j = s1.size()-1;
		  while(j >= 0 && s1[j] == s1.back()) j--;
		  j++;
		  string s2 = s1.substr(0, j), t2 = t1.substr(0, j);
		  if(i < j) {
		  	if(t1[i] < s1[j]) return s1 + t1;
		  	else {
		  		s1 = s2;
		  		t1 = t2;
		  	}
		  } else {
		  	string t3 = t1.substr(j), s3 = s1.substr(j);
			  int k = max_element(ALL(t3)) - t3.begin();
		  	if(t3[k] > s3[k]) {
		  		return s2 + s3[k] + t2 + t3[k];
		  	} else if(t3[k] < s3.back()) {
		  		return s3 + t3;
		  	} else {
		  		int num = s3.size() + j;
		  		int gain = 0, best = 0;
		  		string pos = t3;
		  		REP(i, t3.size()) {
		  			if(t3[i] == s3[i])
		  				gain++;
		  			else
		  				gain--;
		  			if(gain > best) {
		  				best = gain;
		  				pos = t3.substr(i+1);
		  			} else if(gain == best) {
		  				pos = max(pos, t3.substr(i+1));
		  			}
		  		}
		  		return s2 + string(num + best, s3.back()) + pos;
		  	}
		  }
	  }
  }
};

// BEGIN CUT HERE
/*
PROBLEM STATEMENT
John has two strings s and t of equal length.
He can choose a set of positions (possibly empty) and 
erase characters at these positions in both s and t.
Then he writes down the concatenation of what remained of 
the strings: first the letters we kept from s, in their 
original order, then the letters we kept from t, again in 
their original order.


Return the lexicographically largest string John can get 
at the end.


DEFINITION
Class:TheLargestString
Method:find
Parameters:string, string
Returns:string
Method signature:string find(string s, string t)


NOTES
-String A is lexicographically smaller than string B if 
either A is a proper prefix of B, or if there is an 
integer i such that the first i characters of A match the 
first i characters of B, and character i+1 of A is smaller 
than character i+1 of B.


CONSTRAINTS
-s will contain between 1 and 47 characters, inclusive.
-s and t will contain the same number of characters.
-s will contain only lowercase English characters ('a'-'z').
-t will contain only lowercase English characters ('a'-'z').


EXAMPLES

0)
"ab"
"zy"

Returns: "by"

There are four options here:

Do not erase anything. The resulting string would be "abzy".
Erase both first characters. The resulting string would be 
"by".
Erase both last characters. The resulting string would be 
"az".
Erase all characters. The resulting string would be empty.

Among all possible results "by" is the lexicographically 
largest one.


1)
"abacaba"
"zzzaaaa"

Returns: "cbaaaa"



2)
"x"
"x"

Returns: "xx"



3)
"abbabbabbababaaaabbababab"
"bababbaabbbababbbbababaab"

Returns: "bbbbbbbbbbbbbbbbbbaaab"



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
		cout << "Testing TheLargestString (300.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1400387721;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 300.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		TheLargestString _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string s = "ab";
				string t = "zy";
				_expected = "by";
				_received = _obj.find(s, t); break;
			}
			case 1:
			{
				string s = "abacaba";
				string t = "zzzaaaa";
				_expected = "cbaaaa";
				_received = _obj.find(s, t); break;
			}
			case 2:
			{
				string s = "x";
				string t = "x";
				_expected = "xx";
				_received = _obj.find(s, t); break;
			}
			case 3:
			{
				string s = "abbabbabbababaaaabbababab";
				string t = "bababbaabbbababbbbababaab";
				_expected = "bbbbbbbbbbbbbbbbbbaaab";
				_received = _obj.find(s, t); break;
			}
			case 4:
			{
				string s = "uxwhmsncbxcokszkvatxdknlyjyhfi";
				string t = "xjswnkkufnuxxzzbmnmgqooketlyhn";
				_expected = "zz";
				_received = _obj.find(s, t); break;
			}
			case 5:
			{
				string s = "acabcbabccbaaabbaaacbbaccabaccababcaccbccbcbacc";
				string t = "cccbbccaacbcccabbbcccabbbbacbacbaacababccccacca";
				_expected = "ccccccccccccccccccbbbacbacccca";
				_received = _obj.find(s, t); break;
			}
			case 6:
			{
				string s = "yxyxyxxyxxyxxyyxyxyxyyyxyyxyyxyyyxyxxyyyyyyxxyx";
				string t = "xxxxxxxxyxyxxxyyxyyxxxxxxyxxyxyyxxxyyyyyxxxyxyx";
				_expected = "yyyyyyyyyyyyyyyyyyyyyyyyyyyxxxxyxyxyxxxxyxyyyxxyyyxxxy";
				_received = _obj.find(s, t); break;
			}
			case 7:
			{
				string s = "abaababbcacbccbbaabaacabbcbbbcacbbcbbbaabcbbaba";
				string t = "cacacccaacacccaacaccbbcbacbccbccabcbbbabbbcbbba";
				_expected = "cccccccccccb";
				_received = _obj.find(s, t); break;
			}
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
