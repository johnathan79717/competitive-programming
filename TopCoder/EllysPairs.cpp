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

struct EllysPairs {
  int getDifference(vector <int> knowledge) {
  	int N = knowledge.size();
  	sort(ALL(knowledge));
  	int m = INT_MAX, M = INT_MIN;
  	REP(i, knowledge.size()) {
  		m = min(m, knowledge[i] + knowledge[N-1-i]);
  		M = max(M, knowledge[i] + knowledge[N-1-i]);
  	}
  	return M - m;
  }
};

// BEGIN CUT HERE
/*
PROBLEM STATEMENT
In one of her subjects at the university, Elly and her classmates have to prepare projects. The professor wants the students to work in pairs (groups of two). Each student must belong to exactly one pair and each pair should produce one project. You may assume that the number of people in the class is even.

You are given a vector <int> knowledge. Each element of knowledge is the amount of knowledge of one of the students. The quality of a project is the total knowledge of the students that work on it. That is, if students i and j form one of the pairs, the quality of their project will be knowledge[i] + knowledge[j].

This creates some problems. If there is a really strong group, their project will be of really high quality. The professor will then compare the other projects to it and will be disappointed by them, giving low grades to the other pairs. Thus, the students want to form the groups in such way that the difference between the quality of the best project and the quality of the worst project is as small as possible.

Return that minimal difference in the quality between the best and the worst project if the students split into pairs in the best possible way.

DEFINITION
Class:EllysPairs
Method:getDifference
Parameters:vector <int>
Returns:int
Method signature:int getDifference(vector <int> knowledge)


CONSTRAINTS
-knowledge will contain between 2 and 50 elements, inclusive.
-The number of elements of knowledge will be even.
-Each element of knowledge will be between 1 and 1000, inclusive.


EXAMPLES

0)
{2, 6, 4, 3}

Returns: 1

Here obviously grouping the two best people in the class (with knowledge 6 and 4) doesn't make sense.
If 6 pairs with 3 and 4 pairs with 2 they will get qualities of 9 and 6, respectively, leading to difference 3.
However, there is an even better grouping: 2 with 6 and 4 with 3 for qualities of 8 and 7, respectively. The difference then would be only 1.


1)
{1, 1, 1, 1, 1, 1}

Returns: 0

Some or even all students can have the same knowledge.

2)
{4, 2, 4, 2, 1, 3, 3, 7}

Returns: 2



3)
{5, 1, 8, 8, 13, 7, 6, 2, 1, 9, 5, 11, 3, 4}

Returns: 3



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
		cout << "Testing EllysPairs (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1396416637;
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
		EllysPairs _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int knowledge[] = {2, 6, 4, 3};
				_expected = 1;
				_received = _obj.getDifference(vector <int>(knowledge, knowledge+sizeof(knowledge)/sizeof(int))); break;
			}
			case 1:
			{
				int knowledge[] = {1, 1, 1, 1, 1, 1};
				_expected = 0;
				_received = _obj.getDifference(vector <int>(knowledge, knowledge+sizeof(knowledge)/sizeof(int))); break;
			}
			case 2:
			{
				int knowledge[] = {4, 2, 4, 2, 1, 3, 3, 7};
				_expected = 2;
				_received = _obj.getDifference(vector <int>(knowledge, knowledge+sizeof(knowledge)/sizeof(int))); break;
			}
			case 3:
			{
				int knowledge[] = {5, 1, 8, 8, 13, 7, 6, 2, 1, 9, 5, 11, 3, 4};
				_expected = 3;
				_received = _obj.getDifference(vector <int>(knowledge, knowledge+sizeof(knowledge)/sizeof(int))); break;
			}
			/*case 4:
			{
				int knowledge[] = ;
				_expected = ;
				_received = _obj.getDifference(vector <int>(knowledge, knowledge+sizeof(knowledge)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int knowledge[] = ;
				_expected = ;
				_received = _obj.getDifference(vector <int>(knowledge, knowledge+sizeof(knowledge)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int knowledge[] = ;
				_expected = ;
				_received = _obj.getDifference(vector <int>(knowledge, knowledge+sizeof(knowledge)/sizeof(int))); break;
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
