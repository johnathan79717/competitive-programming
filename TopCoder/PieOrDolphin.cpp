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
#include <cassert>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define MS0(x) memset(x,0,sizeof(x))

struct E
{
	int to, num;
};

vector<E> p[50], n[50];
// int p[50][50], n[50][50];
int val[50];
int visited[50];

struct PieOrDolphin {
  vector<int> ans;
	bool dfs(int c, vector<E> *e, int target) {
		visited[c] = true;
		if(val[c] == target) {
			val[c] = -target;
			return true;
		}
		for(auto it = e[c].begin(); it != e[c].end(); it++) {
			if(visited[it->to]) continue;
			if(dfs(it->to, e, target)) {
				vector<E> *other = (e == p) ? n : p;
				other[it->to].push_back({c, it->num});
				ans[it->num] = 3 - ans[it->num];
				e[c].erase(it);
				other[c].erase(it-e[c].begin()+other[c].begin());				
				return true;
			}
		}
		return false;
	}

  vector <int> Distribute(vector <int> choice1, vector <int> choice2) {
  	int N = choice1.size();
  	ans.resize(N);
  	REP(i, N) {
  		int c1 = choice1[i], c2 = choice2[i];
  		assert(abs(val[c1]) <= 1 && abs(val[c2]) <= 1);
  		if(val[c1] != val[c2] || (val[c1] == 0 && val[c2] == 0)) {
  			if(val[c1] == 1 || val[c2] == -1 || (val[c1] == 0 && val[c2] == 0)) {
  				val[c1]--;
  				val[c2]++;
  				// p[c2][c1]++;
  				// n[c1][c2]++;
  				p[c2].push_back({c1, i});
  				n[c1].push_back({c2, i});
  				ans[i] = 2;
  			} else {
  				val[c1]++;
  				val[c2]--;
  				// p[c1][c2]++;
  				// n[c2][c1]++;
  				n[c2].push_back({c1, i});
  				p[c1].push_back({c2, i});
  				ans[i] = 1;
  			}
  		} else {
  			MS0(visited);
  			if(val[c1] == 1)
  				dfs(c1, n, -1);
  			else
  				dfs(c1, p, 1);
  			val[c1] = -val[c1];
  		}
  	}
  	return ans;
  }
};

// BEGIN CUT HERE
/*
PROBLEM STATEMENT
In this problem, some test cases have more than one 
correct output. We are using a special checker to verify 
that the output of your program is correct.

In a far away land, there are 50 programmers who work 
together in an office.
As it is usual among programmers, they are numbered 0 
through 49.

Mr. Ivan is the town's celebrity.
The programmers like Mr. Ivan very much, so they invited 
him to the office.
Flattered, Ivan decided to visit the office each day for 
the next N days.
(We will number those days 0 through N-1, in order.)

Each day, Ivan brought two new toys with him to the 
office: one dolphin toy and one pie toy.
And each day, the programmers held a meeting in which two 
programmers were selected as the most productive ones that 
day.
One of them received a dolphin from Ivan, and the other 
one received a pie.
(Ivan made the choice who gets which toy.)

Today was the day of Ivan's last visit to the office.
After he handed over the last dolphin and the last pie, 
the programmers invited him to a farewell dinner.
During the dinner, each programmer calculated the absolute 
difference between the number of dolphins and the number 
of pies he or she received.
Then, they computed the sum of those differences.
Amazingly, it turned out to be the case that the sum of 
all those differences was the smallest sum possible (given 
the particular set of choices of pairs of programmers on 
each day).
The programmers were very amazed by Ivan's skill, but when 
they asked him about this, he modestly claimed that he 
just got lucky.

You are given two vector <int>s choice1 and choice2, each 
with N elements.
For each i, the programmers who received toys on day i 
were the programmers choice1[i] and choice2[i].

Find one way how to distribute the toys in such a way that 
the sum defined above is minimized.
Return a vector <int> with N elements.
For each i, element i of the returned vector <int> should 
be either 1 or 2.
The value 1 means that on day i the programmer choice1[i] 
should get the dolphin and the programmer choice2[i] 
should get the pie.
The value 2 is the opposite assignment of toys.

If there are multiple optimal distributions, you may 
return any of them.

DEFINITION
Class:PieOrDolphin
Method:Distribute
Parameters:vector <int>, vector <int>
Returns:vector <int>
Method signature:vector <int> Distribute(vector <int> 
choice1, vector <int> choice2)


CONSTRAINTS
-choice1 will contain between 1 and 1000 elements, 
inclusive.
-Each element in choice1 will be between 0 and 49, 
inclusive.
-choice2 will contain the same number of elements as 
choice1.
-Each element in choice2 will be between 0 and 49, 
inclusive.
-For each i, choice1[i] will not be equal to choice2[i].


EXAMPLES

0)
{10, 20, 10}
{20, 30, 20}

Returns: {2, 2, 1 }

According to the return value shown in the example, the 
toys were distributed as follows:

Day 0: programmer 10 gets a pie, programmer 20 gets a 
dolphin.
Day 1: programmer 20 gets a pie, programmer 30 gets a 
dolphin.
Day 2: programmer 10 gets a dolphin, programmer 20 gets a 
pie.

Here is what the programmers compute during the farewell 
dinner:

Programmer 10 got 1 dolphin and 1 pie. The absolute 
difference is |1-1| = 0.
Programmer 20 got 1 dolphin and 2 pies. The absolute 
difference is |1-2| = 1.
Programmer 30 got just 1 dolphin. The absolute difference 
is |1-0| = 1.
Each of the other 47 programmers did not receive anything, 
so they compute |0-0| = 0.

At the end of the dinner, they sum all those results and 
obtain the sum 2. This is the smallest possible sum for 
the given input, hence the return value is correct.

1)
{0, 0}
{1, 1}

Returns: {2, 1 }



2)
{0, 1, 2, 3, 5, 6, 7, 8}
{8, 7, 6, 5, 3, 2, 1, 0}

Returns: {2, 2, 2, 2, 2, 2, 2, 2 }



3)
{49, 0, 48, 1}
{3, 4, 5, 6}

Returns: {2, 2, 2, 2 }



4)
{21,4,14,0,31,46,1,34,2,3,27,19,47,46,17,11,41,12,31,0,34,18,8,14,23,40,0,18,48,35,42,24,25,32,25,44,17,6,44,34,12,39,43,39,26,

34,10,6,13,2,40,15,16,32,32,29,1,23,8,10,49,22,10,15,40,20,0,30,1,43,33,42,28,39,28,4,38,11,5,1,47,12,0,22,20,33,33,34,18,8,23,6}

{25,5,39,20,44,47,11,49,42,17,25,15,23,11,32,17,24,4,11,47,27,41,40,0,49,27,5,28,6,11,18,0,17,1,0,32,45,28,17,5,13,40,40,25,33,

7,8,32,12,0,39,30,8,39,23,9,8,34,34,37,5,1,24,23,0,29,11,42,29,40,24,18,37,1,21,0,31,47,23,33,45,48,31,11,40,45,24,22,19,26,37,39}


Returns: {2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 1, 2, 1, 
2, 1, 1, 1, 2, 2, 2, 1, 2, 2, 2, 1, 2, 2, 1, 1, 2, 2, 1, 
2, 1, 2, 1, 1, 2, 2, 1, 1, 2, 1, 2, 2, 2, 2, 1, 2, 2, 2, 
2, 2, 1, 1, 1, 2, 2, 1, 1, 1, 2, 2, 1, 2, 1, 2, 2, 2, 1, 
2, 2, 1, 2, 1, 2, 2, 1, 2, 1, 1, 1, 2, 1, 1, 2, 2, 2, 1 }



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
		cout << "Testing PieOrDolphin (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1398082198;
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
		PieOrDolphin _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int choice1[] = {10, 20, 10};
				int choice2[] = {20, 30, 20};
				int __expected[] = {2, 2, 1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.Distribute(vector <int>(choice1, choice1+sizeof(choice1)/sizeof(int)), vector <int>(choice2, choice2+sizeof(choice2)/sizeof(int))); break;
			}
			case 1:
			{
				int choice1[] = {0, 0};
				int choice2[] = {1, 1};
				int __expected[] = {2, 1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.Distribute(vector <int>(choice1, choice1+sizeof(choice1)/sizeof(int)), vector <int>(choice2, choice2+sizeof(choice2)/sizeof(int))); break;
			}
			case 2:
			{
				int choice1[] = {0, 1, 2, 3, 5, 6, 7, 8};
				int choice2[] = {8, 7, 6, 5, 3, 2, 1, 0};
				int __expected[] = {2, 2, 2, 2, 2, 2, 2, 2 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.Distribute(vector <int>(choice1, choice1+sizeof(choice1)/sizeof(int)), vector <int>(choice2, choice2+sizeof(choice2)/sizeof(int))); break;
			}
			case 3:
			{
				int choice1[] = {49, 0, 48, 1};
				int choice2[] = {3, 4, 5, 6};
				int __expected[] = {2, 2, 2, 2 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.Distribute(vector <int>(choice1, choice1+sizeof(choice1)/sizeof(int)), vector <int>(choice2, choice2+sizeof(choice2)/sizeof(int))); break;
			}
			case 4:
			{
				int choice1[] = {21,4,14,0,31,46,1,34,2,3,27,19,47,46,17,11,41,12,31,0,34,18,8,14,23,40,0,18,48,35,42,24,25,32,25,44,17,6,44,34,12,39,43,39,26,
				                34,10,6,13,2,40,15,16,32,32,29,1,23,8,10,49,22,10,15,40,20,0,30,1,43,33,42,28,39,28,4,38,11,5,1,47,12,0,22,20,33,33,34,18,8,23,6};
				int choice2[] = {25,5,39,20,44,47,11,49,42,17,25,15,23,11,32,17,24,4,11,47,27,41,40,0,49,27,5,28,6,11,18,0,17,1,0,32,45,28,17,5,13,40,40,25,33,
				                7,8,32,12,0,39,30,8,39,23,9,8,34,34,37,5,1,24,23,0,29,11,42,29,40,24,18,37,1,21,0,31,47,23,33,45,48,31,11,40,45,24,22,19,26,37,39};
				int __expected[] = {2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 1, 2, 1, 2, 1, 1, 1, 2, 2, 2, 1, 2, 2, 2, 1, 2, 2, 1, 1, 2, 2, 1, 2, 1, 2, 1, 1, 2, 2, 1, 1, 2, 1, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 1, 1, 1, 2, 2, 1, 1, 1, 2, 2, 1, 2, 1, 2, 2, 2, 1, 2, 2, 1, 2, 1, 2, 2, 1, 2, 1, 1, 1, 2, 1, 1, 2, 2, 2, 1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.Distribute(vector <int>(choice1, choice1+sizeof(choice1)/sizeof(int)), vector <int>(choice2, choice2+sizeof(choice2)/sizeof(int))); break;
			}
			/*case 5:
			{
				int choice1[] = ;
				int choice2[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.Distribute(vector <int>(choice1, choice1+sizeof(choice1)/sizeof(int)), vector <int>(choice2, choice2+sizeof(choice2)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int choice1[] = ;
				int choice2[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.Distribute(vector <int>(choice1, choice1+sizeof(choice1)/sizeof(int)), vector <int>(choice2, choice2+sizeof(choice2)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int choice1[] = ;
				int choice2[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.Distribute(vector <int>(choice1, choice1+sizeof(choice1)/sizeof(int)), vector <int>(choice2, choice2+sizeof(choice2)/sizeof(int))); break;
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
			cout << "           Expected: {";
			for (unsigned i = 0; i < _expected.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _expected[i];
			}
			cout << " }" << endl;
			cout << "           Received: {";
			for (unsigned i = 0; i < _received.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _received[i];
			}
			cout << " }" << endl;
		}
	}
}

// END CUT HERE
