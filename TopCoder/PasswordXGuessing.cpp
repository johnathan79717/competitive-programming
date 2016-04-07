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
#define FOR(i, c) for(auto &i: c)
#define ALL(x) (x).begin(),(x).end()
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define PER(i,n) for(int i=(n)-1;i>=0;i--)
#define PER1(i,a,b) for(int i=(a);i>=(b);i--)
#define MP make_pair
#define PB push_back
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,-1,sizeof(x))
#define V(T) vector<T >
#define EB emplace_back
 
typedef long long LL;

struct PasswordXGuessing {
  long long howMany(vector <string> guesses) {
  	return 0;
  }
};

// BEGIN CUT HERE
/*
PROBLEM STATEMENT
Ms. Ciel loves rabbits. She has a large special cage for 
her rabbits. The special cage is protected by a secret 
password consisting of exactly X digits. Each digit of her 
password is one of '0'-'9'. (It is possible that the 
password starts with a '0'.)

There are N friends who want to guess the password. Each 
friend make a guess consisting of exactly X digits. This 
is given in vector <string> guesses that contains N 
elements, where guesses[i] is the guess of the i-th 
friend. The friends are so lucky that after they make 
their guesses, Ms. Ciel tells them that each person 
guessed the password correctly, except for exactly one 
digit.

You are given the vector <string> guesses. Return the 
number of different passwords that have the above property 
(i.e., differ from each element of guesses in exactly one 
digit). Note that it is possible that no such password 
exists. In such case, return 0.

DEFINITION
Class:PasswordXGuessing
Method:howMany
Parameters:vector <string>
Returns:long long
Method signature:long long howMany(vector <string> guesses)


NOTES
-The result is guaranteed to fit in a 64-bit signed 
integer data type.


CONSTRAINTS
-guesses will contain between 1 and 50 elements, inclusive.
-Each element of guesses will contain between 1 and 50 
characters, inclusive.
-All elements of guesses will contain the same number of 
characters.
-Each character of each element of guesses will be one of 
'0'-'9'.


EXAMPLES

0)
{"58", "47"}

Returns: 2

The two possible passwords are "57" and "48".

1)
{"539", "540", "541"}

Returns: 1

The only possible password is "549".

2)
{"12", "34", "56", "78"}

Returns: 0

There is no possible password. Ms. Ciel must have 
forgotten her own password.

3)
{"2", "3", "5"}

Returns: 7



4)
{"4747", "4747", "4747", "4747"}

Returns: 36



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
		cout << "Testing PasswordXGuessing (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1397717559;
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
		PasswordXGuessing _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string guesses[] = {"58", "47"};
				_expected = 2LL;
				_received = _obj.howMany(vector <string>(guesses, guesses+sizeof(guesses)/sizeof(string))); break;
			}
			case 1:
			{
				string guesses[] = {"539", "540", "541"};
				_expected = 1LL;
				_received = _obj.howMany(vector <string>(guesses, guesses+sizeof(guesses)/sizeof(string))); break;
			}
			case 2:
			{
				string guesses[] = {"12", "34", "56", "78"};
				_expected = 0LL;
				_received = _obj.howMany(vector <string>(guesses, guesses+sizeof(guesses)/sizeof(string))); break;
			}
			case 3:
			{
				string guesses[] = {"2", "3", "5"};
				_expected = 7LL;
				_received = _obj.howMany(vector <string>(guesses, guesses+sizeof(guesses)/sizeof(string))); break;
			}
			case 4:
			{
				string guesses[] = {"4747", "4747", "4747", "4747"};
				_expected = 36LL;
				_received = _obj.howMany(vector <string>(guesses, guesses+sizeof(guesses)/sizeof(string))); break;
			}
			/*case 5:
			{
				string guesses[] = ;
				_expected = LL;
				_received = _obj.howMany(vector <string>(guesses, guesses+sizeof(guesses)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string guesses[] = ;
				_expected = LL;
				_received = _obj.howMany(vector <string>(guesses, guesses+sizeof(guesses)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string guesses[] = ;
				_expected = LL;
				_received = _obj.howMany(vector <string>(guesses, guesses+sizeof(guesses)/sizeof(string))); break;
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
