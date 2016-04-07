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

V(int) parent;
V(int) cost;

int dfs(int u) {
	V(int) children;
	REP(i, parent.size()) {
		if(parent[i] == u) {
			dfs(v);
			
		}
	}
}

struct GoodCompanyDivOne {
  int minimumCost(vector <int> superior, vector <int> training) {
  	parent = superior;
  	dfs(0);
  	cost.resize(superior.size());
  }
};

// BEGIN CUT HERE
/*
PROBLEM STATEMENT

Shiny has a company.
There are N employees in her company.
The employees are numbered 0 through N-1 in order in which 
they joined the company.

Employee 0 is the only employee with no boss.
Every other employee has precisely one direct boss in the 
company.
You are given a vector <int> superior with N elements.
Element 0 of superior will be -1 to denote that employee 0 
has no boss.
For each i between 1 and N-1, inclusive, element i of 
superior will be the number of the boss of employee i.

For each employee, their boss joined the company before 
them.
Formally, for each i between 1 and N-1, inclusive, superior
[i] will be between 0 and i-1, inclusive.

At the moment, the employees of Shiny's company cannot do 
anything useful.
Shiny would like to change this.
She decided that she will pay for the employees' training.
More precisely, each employee will be trained to do two 
different types of work.
(The two types of work may be different for different 
employees.)

There are K types of work for which training is available.
You are given a vector <int> training with K elements.
For each i, training[i] is the cost of training any single 
employee to do work of type i.
If multiple employees are trained to do the same work 
type, Shiny must pay for each of them separately.

Each employee of the company has their own department.
The department of employee x is formed by employee x and 
all the employees such that x is their boss.
Formally, for any y different from x, employee y belongs 
into the department of employee x if and only if superior
[y]=x.
Note that if superior[z]=y and superior[y]=x, employee z 
does not belong into the department of employee x.

Shiny likes diverse departments.
A department is diverse if:

Each employee in the department is doing something, and
no two employees in the department are doing the same type 
of work.


When Shiny comes to inspect a department, the employees in 
the department try to choose their work so that the 
department will be diverse.
If they can do that, Shiny says that the department is good.

Shiny considers her company good if all N departments are 
good.
(Note that the departments are not required to be diverse 
at the same time. A company is good as soon as each of its 
departments can be diverse at some point in time.)

Shiny now wants to choose, for each employee, the two work 
types they will be trained to do.
Shiny wants to have a good company, and also to spend as 
little money as possible.

If it is possible for Shiny to have a good company, return 
the smallest possible total amount of money spent on 
training the employees.
If it is impossible, return -1 instead.



DEFINITION
Class:GoodCompanyDivOne
Method:minimumCost
Parameters:vector <int>, vector <int>
Returns:int
Method signature:int minimumCost(vector <int> superior, 
vector <int> training)


NOTES
-Each employee must learn to perform exactly two different 
work types (even though they might never need to do one of 
those two types of work).


CONSTRAINTS
-superior will contain between 1 and 30 elements, inclusive.
-superior[0] will be -1.
-For each valid i>0, superior[i] will be between 0 and i-
1, inclusive.
-training will contain between 2 and 30 elements, inclusive.
-Each element of training will be between 1 and 100, 
inclusive.


EXAMPLES

0)
{-1}
{1, 2}

Returns: 3

There is only one employee (employee 0) and two work 
types. Employee 0 has to be trained to do both work types. 
This costs 1+2 = 3. After the training, the company is 
clearly good.

1)
{-1, 0, 0}
{1, 2, 3}

Returns: 10

One optimal solution:

Employee 0 learns work types 0 and 1 which costs 1+2 = 3.
Employee 1 learns work types 0 and 1 which costs 1+2 = 3.
Employee 2 learns work types 0 and 2 which costs 1+3 = 4.

The total cost is 3+3+4 = 10.
The company is now good because:

The department of employee 0 is formed by employees 0, 1, 
and 2. This department is good because they can choose 
work types 0, 1, and 2, respectively.
The department of employee 1 is formed only by employee 1 
and it is clearly good.
The department of employee 2 is formed only by employee 2 
and it is clearly good.



2)
{-1, 0, 0, 0}
{1, 2, 3}

Returns: -1

There are only three work types, but there are four 
employees in employee 0's department.
Therefore, this department can never be good.

3)
{-1, 0, 0, 2, 2, 2, 1, 1, 6, 0, 5, 4, 11, 10, 3, 6, 11, 7, 
0, 2, 13, 14, 2, 10, 9, 11, 22, 10, 3}
{4, 2, 6, 6, 8, 3, 3, 1, 1, 5, 8, 6, 8, 2, 4}

Returns: 71



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
		cout << "Testing GoodCompanyDivOne (600.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1399288326;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 600.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		GoodCompanyDivOne _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int superior[] = {-1};
				int training[] = {1, 2};
				_expected = 3;
				_received = _obj.minimumCost(vector <int>(superior, superior+sizeof(superior)/sizeof(int)), vector <int>(training, training+sizeof(training)/sizeof(int))); break;
			}
			case 1:
			{
				int superior[] = {-1, 0, 0};
				int training[] = {1, 2, 3};
				_expected = 10;
				_received = _obj.minimumCost(vector <int>(superior, superior+sizeof(superior)/sizeof(int)), vector <int>(training, training+sizeof(training)/sizeof(int))); break;
			}
			case 2:
			{
				int superior[] = {-1, 0, 0, 0};
				int training[] = {1, 2, 3};
				_expected = -1;
				_received = _obj.minimumCost(vector <int>(superior, superior+sizeof(superior)/sizeof(int)), vector <int>(training, training+sizeof(training)/sizeof(int))); break;
			}
			case 3:
			{
				int superior[] = {-1, 0, 0, 2, 2, 2, 1, 1, 6, 0, 5, 4, 11, 10, 3, 6, 11, 7, 0, 2, 13, 14, 2, 10, 9, 11, 22, 10, 3};
				int training[] = {4, 2, 6, 6, 8, 3, 3, 1, 1, 5, 8, 6, 8, 2, 4};
				_expected = 71;
				_received = _obj.minimumCost(vector <int>(superior, superior+sizeof(superior)/sizeof(int)), vector <int>(training, training+sizeof(training)/sizeof(int))); break;
			}
			/*case 4:
			{
				int superior[] = ;
				int training[] = ;
				_expected = ;
				_received = _obj.minimumCost(vector <int>(superior, superior+sizeof(superior)/sizeof(int)), vector <int>(training, training+sizeof(training)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int superior[] = ;
				int training[] = ;
				_expected = ;
				_received = _obj.minimumCost(vector <int>(superior, superior+sizeof(superior)/sizeof(int)), vector <int>(training, training+sizeof(training)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int superior[] = ;
				int training[] = ;
				_expected = ;
				_received = _obj.minimumCost(vector <int>(superior, superior+sizeof(superior)/sizeof(int)), vector <int>(training, training+sizeof(training)/sizeof(int))); break;
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
