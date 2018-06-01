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
#define ALL(x) (x).begin(),(x).end()
 
typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;

#line 40 "SocialNetwork.cpp"
#include <string>
#include <vector>
class SocialNetwork {
public:
  double averageFriends(vector <string> interests) {
    int N = interests.size();
    REP(i, N) {
      sort(ALL(interests[i]));
    }
    char c[30];
    char *p = c;
    double ans = 0;
    REP(i, N) {
      int f = 0;
      REP(j, N) {
	if (i == j) continue;
	p = set_intersection(ALL(interests[i]), ALL(interests[j]), c);
	f += (p != c);
      }
      ans += f;
    }
    ans /= N;
    return ans;
  }
};

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// A new social network automatically matches people together based upon a shared interest. A list of interests for each member of the social network is given in the vector <string> interests. Each element represents the interests of a single member: each character ('A'-'Z') represents a different interest. Two individuals become friends if they have at least one interest in common. Return the average number of friends each member has.

DEFINITION
Class:SocialNetwork
Method:averageFriends
Parameters:vector <string>
Returns:double
Method signature:double averageFriends(vector <string> interests)


NOTES
-Your return value must have an absolute or a relative error at most 10^(-9).


CONSTRAINTS
-interests will contain between 2 and 50 elements, inclusive.
-Each character in each element of interests will be an uppercase English letter ('A'-'Z').
-The characters in each element of interests will be distinct.


EXAMPLES

0)
{"A", "A"}

Returns: 1.0

Two people who share a common interest. Thus, they each have one friend, and the average number of
friends is therefore also 1.

1)
{"ABC", "DE", "FGHIJ"}

Returns: 0.0

Three people with no common interests.


2)
{"ABC", "DE", "FGHIJA"}

Returns: 0.6666666666666666

This is almost the same situation as Example #1 but now two of the people share a common interests.
Now these three people have 1, 0, and 1 friends, respectively. The average number of friends is
(1+0+1)/3 = 2/3 = 0.6666666667.


3)
{"AB", "AC", "AD", "AE", "BCDE"}

Returns: 4.0

All of these people are friends with each other, even though there is no single topic they would all
be interested in.


4)
{"ABCDE", "BCDEF"}

Returns: 1.0

Even if people share multiple common interests, they are only friends once.


5)
{"", "", "", ""}

Returns: 0.0

Four grumpy people who are not interested in anything.


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
		cout << "Testing SocialNetwork (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1526130034;
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
		SocialNetwork _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string interests[] = {"A", "A"};
				_expected = 1.0;
				_received = _obj.averageFriends(vector <string>(interests, interests+sizeof(interests)/sizeof(string))); break;
			}
			case 1:
			{
				string interests[] = {"ABC", "DE", "FGHIJ"};
				_expected = 0.0;
				_received = _obj.averageFriends(vector <string>(interests, interests+sizeof(interests)/sizeof(string))); break;
			}
			case 2:
			{
				string interests[] = {"ABC", "DE", "FGHIJA"};
				_expected = 0.6666666666666666;
				_received = _obj.averageFriends(vector <string>(interests, interests+sizeof(interests)/sizeof(string))); break;
			}
			case 3:
			{
				string interests[] = {"AB", "AC", "AD", "AE", "BCDE"};
				_expected = 4.0;
				_received = _obj.averageFriends(vector <string>(interests, interests+sizeof(interests)/sizeof(string))); break;
			}
			case 4:
			{
				string interests[] = {"ABCDE", "BCDEF"};
				_expected = 1.0;
				_received = _obj.averageFriends(vector <string>(interests, interests+sizeof(interests)/sizeof(string))); break;
			}
			case 5:
			{
				string interests[] = {"", "", "", ""};
				_expected = 0.0;
				_received = _obj.averageFriends(vector <string>(interests, interests+sizeof(interests)/sizeof(string))); break;
			}
			/*case 6:
			{
				string interests[] = ;
				_expected = ;
				_received = _obj.averageFriends(vector <string>(interests, interests+sizeof(interests)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string interests[] = ;
				_expected = ;
				_received = _obj.averageFriends(vector <string>(interests, interests+sizeof(interests)/sizeof(string))); break;
			}*/
			/*case 8:
			{
				string interests[] = ;
				_expected = ;
				_received = _obj.averageFriends(vector <string>(interests, interests+sizeof(interests)/sizeof(string))); break;
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
