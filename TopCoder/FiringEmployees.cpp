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
#define ALL(x) (x).begin(),(x).end()
#define FOR(i, c) for(auto &i: c)
#define PER(i,n) for(int i=(n)-1;i>=0;i--)
#define PER1(i,a,b) for(int i=(a);i>=(b);i--)
#define MP make_pair
#define PB push_back
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,-1,sizeof(x))
#define V(T) vector<T >
#define EB emplace_back
#define MAX(x, a) x = max(x, a)
#define MIN(x, a) x = min(x, a)

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;
#line 39 "FiringEmployees.cpp"
#include <string>
#include <vector>
class FiringEmployees {
public:
    int fire(vector <int> manager, vector <int> salary, vector <int> productivity) {
        
    }
};
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// BottomCoder has a CEO and N employees.
The CEO has number 0, the employees are numbered 1 through N.
Each employee can be described by three numbers: their salary, their productivity, and the number of their direct manager.
For each employee E, employee E's manager has a number smaller than E.
Hence, the company has a tree-like hierarchy.

You are given the description of BottomCoder in the vector <int>s manager, salary, and productivity.
For each i between 1 and N, inclusive, employee i is described by the values manager[i-1], salary[i-1], and productivity[i-1].

The profit from an employee can be computed as the employee's productivity minus their salary.
Note that the profit from an employee can be negative.
The total profit of the company is the sum of profits of its employees.

The CEO would like to increase the total profit of the company by firing some of its employees.
However, if he fires an employee E, he must also fire all employees who reported to E.
For example, if he fires your manager, he must fire you as well.
As another example, if he fires the manager of your manager, he must fire your manager and therefore he must also fire you.

Find a valid way of firing some (possibly none, possibly all) employees that maximizes the profit of the resulting company.
Return the total profit after the selected employees are fired.

DEFINITION
Class:FiringEmployees
Method:fire
Parameters:vector <int>, vector <int>, vector <int>
Returns:int
Method signature:int fire(vector <int> manager, vector <int> salary, vector <int> productivity)


NOTES
-The CEO of BottomCoder has both salary and productivity equal to zero. The CEO cannot be fired.


CONSTRAINTS
-manager, salary and productivity will contain N elements each.
-manager will contain between 1 and 2500 elements inclusive.
-Each element of salary will be between 1 and 10,000 inclusive.
-Each element of productivity will be between 1 and 10,000 inclusive.
-The i-th element of manager will be between 0 and i inclusive.


EXAMPLES

0)
{0,0,0}
{1,2,3}
{3,2,1}

Returns: 2

The CEO has three direct employees.
The first one has a salary of 1 and a productivity of 3.
The second one has a salary of 2 and a productivity of 2.
The third one has a salary of 3 and a productivity of 1.
The CEO should fire employee 3.
The CEO can also fire employee 2, but it does not matter: here, firing is equally good as keeping.

1)
{0,1,2,3}
{4,3,2,1}
{2,3,4,5}

Returns: 4

Employee 1 has a negative profit: 2-4 = (-2).
The other three employees have nonnegative profits: 0, 2, and 4.

It would seem that the CEO should fire employee 1.
However, if he does that, he would have to fire all four employees, because 1 is (either directly or indirectly) the manager of each of them.
This would leave the CEO with an empty company that has profit 0.

The optimal strategy is not to fire anyone.
The total profit in this case will be (-2) + 0 + 2 + 4 = 4.

2)
{0,1}
{1,10}
{5,5}

Returns: 4

In this case the best choice is to fire employee number 2 and keep employee number 1.

3)
{0,1,2,1,2,3,4,2,3}
{5,3,6,8,4,2,4,6,7}
{2,5,7,8,5,3,5,7,9}

Returns: 6



4)
{0,0,1,1,2,2}
{1,1,1,2,2,2}
{2,2,2,1,1,1}

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
		cout << "Testing FiringEmployees (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1453948604;
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
		FiringEmployees _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int manager[] = {0,0,0};
				int salary[] = {1,2,3};
				int productivity[] = {3,2,1};
				_expected = 2;
				_received = _obj.fire(vector <int>(manager, manager+sizeof(manager)/sizeof(int)), vector <int>(salary, salary+sizeof(salary)/sizeof(int)), vector <int>(productivity, productivity+sizeof(productivity)/sizeof(int))); break;
			}
			case 1:
			{
				int manager[] = {0,1,2,3};
				int salary[] = {4,3,2,1};
				int productivity[] = {2,3,4,5};
				_expected = 4;
				_received = _obj.fire(vector <int>(manager, manager+sizeof(manager)/sizeof(int)), vector <int>(salary, salary+sizeof(salary)/sizeof(int)), vector <int>(productivity, productivity+sizeof(productivity)/sizeof(int))); break;
			}
			case 2:
			{
				int manager[] = {0,1};
				int salary[] = {1,10};
				int productivity[] = {5,5};
				_expected = 4;
				_received = _obj.fire(vector <int>(manager, manager+sizeof(manager)/sizeof(int)), vector <int>(salary, salary+sizeof(salary)/sizeof(int)), vector <int>(productivity, productivity+sizeof(productivity)/sizeof(int))); break;
			}
			case 3:
			{
				int manager[] = {0,1,2,1,2,3,4,2,3};
				int salary[] = {5,3,6,8,4,2,4,6,7};
				int productivity[] = {2,5,7,8,5,3,5,7,9};
				_expected = 6;
				_received = _obj.fire(vector <int>(manager, manager+sizeof(manager)/sizeof(int)), vector <int>(salary, salary+sizeof(salary)/sizeof(int)), vector <int>(productivity, productivity+sizeof(productivity)/sizeof(int))); break;
			}
			case 4:
			{
				int manager[] = {0,0,1,1,2,2};
				int salary[] = {1,1,1,2,2,2};
				int productivity[] = {2,2,2,1,1,1};
				_expected = 3;
				_received = _obj.fire(vector <int>(manager, manager+sizeof(manager)/sizeof(int)), vector <int>(salary, salary+sizeof(salary)/sizeof(int)), vector <int>(productivity, productivity+sizeof(productivity)/sizeof(int))); break;
			}
			/*case 5:
			{
				int manager[] = ;
				int salary[] = ;
				int productivity[] = ;
				_expected = ;
				_received = _obj.fire(vector <int>(manager, manager+sizeof(manager)/sizeof(int)), vector <int>(salary, salary+sizeof(salary)/sizeof(int)), vector <int>(productivity, productivity+sizeof(productivity)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int manager[] = ;
				int salary[] = ;
				int productivity[] = ;
				_expected = ;
				_received = _obj.fire(vector <int>(manager, manager+sizeof(manager)/sizeof(int)), vector <int>(salary, salary+sizeof(salary)/sizeof(int)), vector <int>(productivity, productivity+sizeof(productivity)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int manager[] = ;
				int salary[] = ;
				int productivity[] = ;
				_expected = ;
				_received = _obj.fire(vector <int>(manager, manager+sizeof(manager)/sizeof(int)), vector <int>(salary, salary+sizeof(salary)/sizeof(int)), vector <int>(productivity, productivity+sizeof(productivity)/sizeof(int))); break;
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
