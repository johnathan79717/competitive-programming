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
typedef long long LL;

#define MAX_P 5000000
bool p[MAX_P];

void Eratosthenes() {
  memset(p, true, sizeof p);
  for(int i = 2; i <= MAX_P; i++)
    if(p[i]) {
      if((LL)i*i <= MAX_P) 
        for(int j = i*i; j <= MAX_P; j+=i)
          p[j] = false;
    }
}

struct SumAndProductPuzzle {
  long long getSum(int A, int B) {
  	Eratosthenes();
  	long long ans = 0;
  	REP1(i, A, B) {
  		if(i % 2 == 0) {
  			if(!p[i-1]) {
  				bool fail = false;
  				for(int pr = 2; pr * pr <= i-1; pr++) {
  					if((i-1) % pr) continue;
  					if(!p[pr + (i-1) / pr - 1])
  						fail = true;
  				}
  				if(!fail) ans += i;
  			}
  		}
  	}
  	int b = 2;
  	while((1<<b) + 1 < A) b++;
  	while((1<<b) + 1 <= B) {
  		bool fail = false;
  		REP1(j, 1, b-1) {
  			if(!p[(1<<j) + (1<<(b-j)) - 1])
  				fail = true;
  		}
  		if(!fail)
  			ans += (1<<b) + 1;
  		b++;
  	}
  	return ans;
  }
};

// BEGIN CUT HERE
/*
PROBLEM STATEMENT

Consider the following story.



STORY STARTS HERE.



There were three mathematicians: Susan, Priscilla, and Bob.
Bob picked two positive integers x and y such that x <= y.
He then told their sum to Susan and their product to 
Priscilla.
Susan and Priscilla both knew all the facts listed above.
Then, Susan and Priscilla made the following statements:

Susan: "I am certain that you cannot determine my number."
Priscilla: "Thanks for telling me that. Now I'm sure that 
your number is S."




STORY ENDS HERE.



My friends Baska and Olivia are fond of puzzles.
Recently, Baska told Olivia the above story.
When telling the story, Baska used some specific positive 
integer (for example, 9) instead of S.
Then, she asked Olivia to determine x and y.
Olivia easily came up with the unique solution.



Of course, you don't know the integer Baska used instead 
of S.
Instead, you are given two ints A and B.
Find all S between A and B, inclusive, such that the above 
discussion between Baska and Olivia could have happened.
Return the sum of all such S.


DEFINITION
Class:SumAndProductPuzzle
Method:getSum
Parameters:int, int
Returns:long long
Method signature:long long getSum(int A, int B)


NOTES
-Watch out for overflow. The return value may overflow a 
32-bit integer variable.


CONSTRAINTS
-A will be between 1 and 5,000,000, inclusive.
-B will be between A and 5,000,000, inclusive.


EXAMPLES

0)
30
33

Returns: 33

The only valid S in this range is 33.
The unique pair (x,y) that corresponds to S=33 is (1,32).

1)
8
11

Returns: 19



2)
40
43

Returns: 0

Sometimes the given range doesn't contain any valid S. In 
such case the correct return value is 0.

3)
47
74

Returns: 168



4)
1
2

Returns: 0



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
		cout << "Testing SumAndProductPuzzle (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1402158274;
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
		SumAndProductPuzzle _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int A = 30;
				int B = 33;
				_expected = 33LL;
				_received = _obj.getSum(A, B); break;
			}
			case 1:
			{
				int A = 8;
				int B = 11;
				_expected = 19LL;
				_received = _obj.getSum(A, B); break;
			}
			case 2:
			{
				int A = 40;
				int B = 43;
				_expected = 0LL;
				_received = _obj.getSum(A, B); break;
			}
			case 3:
			{
				int A = 47;
				int B = 74;
				_expected = 168LL;
				_received = _obj.getSum(A, B); break;
			}
			case 4:
			{
				int A = 1;
				int B = 2;
				_expected = 0LL;
				_received = _obj.getSum(A, B); break;
			}
			/*case 5:
			{
				int A = ;
				int B = ;
				_expected = LL;
				_received = _obj.getSum(A, B); break;
			}*/
			/*case 6:
			{
				int A = ;
				int B = ;
				_expected = LL;
				_received = _obj.getSum(A, B); break;
			}*/
			/*case 7:
			{
				int A = ;
				int B = ;
				_expected = LL;
				_received = _obj.getSum(A, B); break;
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
