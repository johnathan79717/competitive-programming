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
#define MP make_pair
#define PB push_back
#define F first
#define S second
 
typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;

struct InverseRMQ {
  string possible(int n, vector <int> A, vector <int> B, vector <int> ans) {
  	vector<pair<int, pair<int,int>>> v;
  	REP(i, A.size()) v.PB(MP(ans[i], MP(A[i], B[i])));
  	sort(ALL(v));
  	int l = 0;
  	while(l < v.size()) {
  		int r = l;
  		while(r < v.size() && v[r].F == v[l].F) r++;
  		REP1(i, l, r-1) {
  			auto check = [&](int k) {
  				if(k < v[i].S.F || k > v[i].S.S) return false;
  				REP(j, r) {
  					if(k >= v[j].S.F && k <= v[j].S.S) return false;
  				}
  				return true;
  			};
  			bool success = check(v[i].S.F);
  			REP(j, r) {
  				success = success || check(v[j].S.F-1);
  				success = success || check(v[j].S.S+1);
  			}
  			if(!success) return "Impossible";
  		}
  	}
  	return "Possible";
  }
};

// BEGIN CUT HERE
/*
PROBLEM STATEMENT
The range maximum query (RMQ) problem looks as follows:
You are given a permutation P of the numbers 1 through n, 
and a sequence of queries.
Each query is a pair of integers (L,R) such that 1 <= L <= 
R <= n.
The answer to the query is the maximum of the values that 
occur in P at (1-based) positions L through R, inclusive.


For example, if P is the permutation (3,1,4,2,5), then:

The answer to the query (1,2) is max(3,1)=3.
The answer to the query (2,4) is max(1,4,2)=4.
The answer to the query (4,5) is max(2,5)=5.



In this problem, we ask you to solve the inverse problem.
You are given the int n, and three vector <int>s A, B, and 
ans, each containing the same number of elements.
We are looking for a permutation P of numbers 1 through n 
with the following property:
For each valid i, the answer to the query (A[i], B[i]) 
must be ans[i].
Return "Possible" (quotes for clarity) if at least one 
such permutation P exists, and "Impossible" otherwise.

DEFINITION
Class:InverseRMQ
Method:possible
Parameters:int, vector <int>, vector <int>, vector <int>
Returns:string
Method signature:string possible(int n, vector <int> A, 
vector <int> B, vector <int> ans)


CONSTRAINTS
-n will be between 1 and 1,000,000,000, inclusive.
-A will contain between 1 and 50 elements, inclusive.
-A, B, and ans will each contain the same number of 
elements.
-Each element in A will be between 1 and n, inclusive.
-Each element in B will be between 1 and n, inclusive.
-For all i, A[i] will be less than or equal to B[i].
-Each element in ans will be between 1 and n, inclusive.


EXAMPLES

0)
5
{1,2,4}
{2,4,5}
{3,4,5}

Returns: "Possible"

This is the example from the problem statement. One valid 
permutation is (3,1,4,2,5). There are also some other 
valid permutations.

1)
3
{1,2,3}
{1,2,3}
{3,3,3}

Returns: "Impossible"

The only sequence that corresponds to these queries is 
(3,3,3), but that is not a permutation.

2)
600
{1,101,201,301,401,501}
{100,200,300,400,500,600}
{100,200,300,400,500,600}

Returns: "Possible"

One valid permutation is the permutation (1,2,3,...,600).

3)
1000000000
{1234,1234}
{5678,5678}
{10000,20000}

Returns: "Impossible"

There is no permutation such that two identical queries 
have different answers.

4)
8
{1,2,3,4,5,6,7,8}
{1,2,3,4,5,6,7,8}
{4,8,2,5,6,3,7,1}

Returns: "Possible"

The only valid permutation is clearly (4,8,2,5,6,3,7,1).

5)
1000000000
{1}
{1000000000}
{19911120}

Returns: "Impossible"

Obviously, for n=1,000,000,000 the maximum of the entire 
permutation must be 1,000,000,000.

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
		cout << "Testing InverseRMQ (900.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1404578205;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 900.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		InverseRMQ _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 5;
				int A[] = {1,2,4};
				int B[] = {2,4,5};
				int ans[] = {3,4,5};
				_expected = "Possible";
				_received = _obj.possible(n, vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(ans, ans+sizeof(ans)/sizeof(int))); break;
			}
			case 1:
			{
				int n = 3;
				int A[] = {1,2,3};
				int B[] = {1,2,3};
				int ans[] = {3,3,3};
				_expected = "Impossible";
				_received = _obj.possible(n, vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(ans, ans+sizeof(ans)/sizeof(int))); break;
			}
			case 2:
			{
				int n = 600;
				int A[] = {1,101,201,301,401,501};
				int B[] = {100,200,300,400,500,600};
				int ans[] = {100,200,300,400,500,600};
				_expected = "Possible";
				_received = _obj.possible(n, vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(ans, ans+sizeof(ans)/sizeof(int))); break;
			}
			case 3:
			{
				int n = 1000000000;
				int A[] = {1234,1234};
				int B[] = {5678,5678};
				int ans[] = {10000,20000};
				_expected = "Impossible";
				_received = _obj.possible(n, vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(ans, ans+sizeof(ans)/sizeof(int))); break;
			}
			case 4:
			{
				int n = 8;
				int A[] = {1,2,3,4,5,6,7,8};
				int B[] = {1,2,3,4,5,6,7,8};
				int ans[] = {4,8,2,5,6,3,7,1};
				_expected = "Possible";
				_received = _obj.possible(n, vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(ans, ans+sizeof(ans)/sizeof(int))); break;
			}
			case 5:
			{
				int n = 1000000000;
				int A[] = {1};
				int B[] = {1000000000};
				int ans[] = {19911120};
				_expected = "Impossible";
				_received = _obj.possible(n, vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(ans, ans+sizeof(ans)/sizeof(int))); break;
			}
			/*case 6:
			{
				int n = ;
				int A[] = ;
				int B[] = ;
				int ans[] = ;
				_expected = ;
				_received = _obj.possible(n, vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(ans, ans+sizeof(ans)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int n = ;
				int A[] = ;
				int B[] = ;
				int ans[] = ;
				_expected = ;
				_received = _obj.possible(n, vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(ans, ans+sizeof(ans)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int n = ;
				int A[] = ;
				int B[] = ;
				int ans[] = ;
				_expected = ;
				_received = _obj.possible(n, vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(ans, ans+sizeof(ans)/sizeof(int))); break;
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
			cout << "           Expected: " << "\"" << _expected << "\"" << endl;
			cout << "           Received: " << "\"" << _received << "\"" << endl;
		}
	}
}

// END CUT HERE
