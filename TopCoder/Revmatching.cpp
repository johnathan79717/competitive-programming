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
#define MS0(x) memset(x,0,sizeof(x))
class Revmatching {
	public:
	int smallest(vector <string> A) {
		int N = A.size();
		int ans = 1e9;
		REP1(mask, 1, (1 << N) - 1) {
			int cnt = 0;
			int c[30];
			MS0(c);
			REP(i, N) {
				if ((mask >> i) & 1) {
					cnt++;
					REP(j, N) {
						if (A[i][j]) {
							c[j] += A[i][j] - '0';
						}
					}
				}
			}
			sort(c, c + N);
			int w = 0;
			REP(i, N-cnt+1) {
				w += c[i];
			}
			ans = min(ans, w);
		}	
		return ans;
	}
};
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// You have a weighted bipartite graph.
Each partition contains n vertices numbered 0 through n-1.
You are given the weights of all edges encoded into a vector <string> A with n elements, each containing n characters.
For each i and j, A[i][j] is '0' if there is no edge between vertex i in the first partition and vertex j in the second partition.
Otherwise, A[i][j] is between '1' and '9', inclusive, and the digit represents the weight of the corresponding edge.

A perfect matching is a permutation p of 0 through n-1 such that for each i there is an edge (of any positive weight) between vertex i in the first partition and vertex p[i] in the second partition.

Your goal is to have a graph that does not contain any perfect matching.
You are allowed to delete edges from your current graph.
You do not care about the number of edges you delete, only about their weights.
More precisely, you want to reach your goal by deleting a subset of edges with the smallest possible total weight.
Compute and return the total weight of deleted edges in an optimal solution.

DEFINITION
Class:Revmatching
Method:smallest
Parameters:vector <string>
Returns:int
Method signature:int smallest(vector <string> A)


CONSTRAINTS
-A will contain exactly n elements.
-Each element in A will be n characters long.
-n will be between 1 and 20, inclusive.
-Each character in A will be between '0' and '9', inclusive.


EXAMPLES

0)
{"1"}

Returns: 1

There is a single edge. You have to delete it.

1)
{"0"}

Returns: 0

There are no edges and therefore there is no perfect matching.

2)
{"44","44"}

Returns: 8



3)
{"861","870","245"}

Returns: 6



4)
{"01000","30200","11102","10001","11001"}

Returns: 0



5)
{"0111101100","0001101001","1001001000","1000100001","0110011111","0011110100","1000001100","0001100000","1000100001","0101110010"}

Returns: 1



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
		cout << "Testing Revmatching (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1428769527;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 1000.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		Revmatching _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string A[] = {"1"};
				_expected = 1;
				_received = _obj.smallest(vector <string>(A, A+sizeof(A)/sizeof(string))); break;
			}
			case 1:
			{
				string A[] = {"0"};
				_expected = 0;
				_received = _obj.smallest(vector <string>(A, A+sizeof(A)/sizeof(string))); break;
			}
			case 2:
			{
				string A[] = {"44","44"};
				_expected = 8;
				_received = _obj.smallest(vector <string>(A, A+sizeof(A)/sizeof(string))); break;
			}
			case 3:
			{
				string A[] = {"861","870","245"};
				_expected = 6;
				_received = _obj.smallest(vector <string>(A, A+sizeof(A)/sizeof(string))); break;
			}
			case 4:
			{
				string A[] = {"01000","30200","11102","10001","11001"};
				_expected = 0;
				_received = _obj.smallest(vector <string>(A, A+sizeof(A)/sizeof(string))); break;
			}
			case 5:
			{
				string A[] = {"0111101100","0001101001","1001001000","1000100001","0110011111","0011110100","1000001100","0001100000","1000100001","0101110010"};
				_expected = 1;
				_received = _obj.smallest(vector <string>(A, A+sizeof(A)/sizeof(string))); break;
			}
			/*case 6:
			{
				string A[] = ;
				_expected = ;
				_received = _obj.smallest(vector <string>(A, A+sizeof(A)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string A[] = ;
				_expected = ;
				_received = _obj.smallest(vector <string>(A, A+sizeof(A)/sizeof(string))); break;
			}*/
			/*case 8:
			{
				string A[] = ;
				_expected = ;
				_received = _obj.smallest(vector <string>(A, A+sizeof(A)/sizeof(string))); break;
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
