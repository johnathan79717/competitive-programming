#include <string>
#include <cassert>
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
#define MP make_pair
#define V(T) vector<T >

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;
// #line 40 "Moneymanager.cpp"
#include <string>
#include <vector>
#define a first
#define b second
class Moneymanager {
public:
    int getbest(vector <int> a, vector <int> b, int X) {
        int N = a.size();
        V(PII) p(N);
        REP(i, N) {
            p[i] = MP(a[i], b[i]);
        }
        sort(ALL(p), [X](const PII &p0, const PII &p1) {
                return p1.b * (X + p0.a) > p0.b * (X + p1.a);
                });
        auto cmp = [](const PII &p0, const PII &p1) {
            return p1.b * p0.a > p0.b * p1.a;
        };
        sort(p.begin(), p.begin() + N/2, cmp);
        sort(p.begin()+N/2, p.end(), cmp);
        int E = 0, ans = 0;
        REP(i, N) {
            if (i == N/2) E += X;
            E += p[i].a;
            ans += p[i].b * E;
        }
        return ans;
    }
};
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// One day Hero realized that he has zero experience with practical projects.
Thus, he decided to spend one whole year on projects, gaining some experience and making some money along the way.

Hero already chose which projects he is going to do.
All that remains is to choose the order in which he'll do them.

Each project can be described by two positive integers a[i] and b[i].
More precisely, when Hero works on project i, the following two things happen, in order:

First, his work on the project increases his experience by a[i].
Then, when the project is done, he earns money for the project. The amount earned is (b[i] * E), where E is his total amount of experience at the moment of finishing the project.


The number of projects Hero has planned is even.
In addition to the projects, Hero has one extra plan: after finishing exactly one half of the projects, he wants to attend a training camp.
The training camp will increase his experience by X.
He will not earn any money at the training camp.

At the beginning, Hero has no experience and no money.
You are given the vector <int>s a and b (both with the same number of elements; that number is even) and the int X.
Find and return the maximum total amount of money Hero can earn during the year.

DEFINITION
Class:Moneymanager
Method:getbest
Parameters:vector <int>, vector <int>, int
Returns:int
Method signature:int getbest(vector <int> a, vector <int> b, int X)


CONSTRAINTS
-Number of elements in a will be between 2 and 50, inclusive.
-Number of elements in a will be even.
-a and b will contain the same number of elements.
-Each element in a will be between 1 and 100,000, inclusive.
-Each element in b will be between 1 and 10, inclusive.
-X will be between 0 and 100,000, inclusive.


EXAMPLES

0)
{1,1}
{2,1}
0

Returns: 5

An optimal solution:

Hero works on project #1 (zero-based index). He first gains 1 experience and then he makes 1*1 = 1 money.
Hero goes to the training camp and gains X=0 experience.
Hero works on project #0. He first gains 1 experience and then he makes 2*2 = 4 money.

The total amount of money earned during this solution is 1 + 4 = 5.

1)
{1,1}
{1,5}
10

Returns: 61

An optimal solution:

Hero works on project #0. He first gains 1 experience and then he makes 1*1 = 1 money.
Hero goes to the training camp and gains 10 experience.
Hero works on project #1. He first gains 1 experience and then he makes 5*12 = 60 money.

The total amount of money earned during this solution is 1 + 60 = 61.

2)
{4,4,6,6}
{2,2,3,3}
100

Returns: 726

One optimal solution: project #0, project #1, training camp, project #3, project #2.

3)
{30,13,28,59,26,62,48,75,6,69,94,51}
{4,6,4,5,4,3,1,5,6,5,2,2}
62

Returns: 22096



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
		cout << "Testing Moneymanager (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1464623792;
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
		Moneymanager _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int a[] = {1,1};
				int b[] = {2,1};
				int X = 0;
				_expected = 5;
				_received = _obj.getbest(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), X); break;
			}
			case 1:
			{
				int a[] = {1,1};
				int b[] = {1,5};
				int X = 10;
				_expected = 61;
				_received = _obj.getbest(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), X); break;
			}
			case 2:
			{
				int a[] = {4,4,6,6};
				int b[] = {2,2,3,3};
				int X = 100;
				_expected = 726;
				_received = _obj.getbest(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), X); break;
			}
			case 3:
			{
				int a[] = {30,13,28,59,26,62,48,75,6,69,94,51};
				int b[] = {4,6,4,5,4,3,1,5,6,5,2,2};
				int X = 62;
				_expected = 22096;
				_received = _obj.getbest(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), X); break;
			}
			/*case 4:
			{
				int a[] = ;
				int b[] = ;
				int X = ;
				_expected = ;
				_received = _obj.getbest(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), X); break;
			}*/
			/*case 5:
			{
				int a[] = ;
				int b[] = ;
				int X = ;
				_expected = ;
				_received = _obj.getbest(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), X); break;
			}*/
			/*case 6:
			{
				int a[] = ;
				int b[] = ;
				int X = ;
				_expected = ;
				_received = _obj.getbest(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), X); break;
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
