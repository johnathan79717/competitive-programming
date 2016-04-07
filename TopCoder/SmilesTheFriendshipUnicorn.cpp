#include <cassert>
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
#define PB push_back
#define V(T) vector<T >

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;
#line 39 "SmilesTheFriendshipUnicorn.cpp"
#include <string>
#include <vector>
bool d[2002][2002];
class SmilesTheFriendshipUnicorn {
public:
    string hasFriendshipChain(int N, vector <int> A, vector <int> B) {
        VI deg(N);
        V(VI) adj(N);
        int M = A.size();
        REP(i, M) {
            deg[A[i]]++;
            deg[B[i]]++;
            d[A[i]][B[i]] = d[B[i]][A[i]] = true;
            adj[A[i]].PB(B[i]);
            adj[B[i]].PB(A[i]);
        }
        REP(i, N) {
            int cnt = 0;
            for (int a: adj[i]) {
                if (deg[a] >= 2) {
                    cnt++;
                }
            }
            if (cnt < 2) continue;
            if (cnt > 2) {
                return "Yay!";
            }
            VI C;
            for (int a: adj[i]) {
                if (deg[a] >= 2) {
                    C.PB(a);
                }
            }
            assert(C.size() == 2);
            if (d[C[0]][C[1]] && (deg[C[0]] == 2 || deg[C[1]] == 2)) {
                continue;
            } else {
                return "Yay!";
            }
        }
        return ":(";
    }
};
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Smiles the Friendship Unicorn lives in the Friendship Kingdom. There are N people in the Friendship Kingdom, numbered from 0 to N-1. Some of them are friends with each other: you are given these pairs in the vector <int> A and the vector <int> B. For each valid i, the person numbered A[i] is friends with the person numbered B[i]. Friendship is two-way, so the person numbered B[i] is also friends with the person numbered A[i]. For every group containing between 1 and N-1 people (inclusive), at least one person in the group is friends with someone outside the group.

Smiles would like to know whether there exists a friendship chain. A friendship chain is a sequence of 5 distinct people A, B, C, D, and E such that:

A is friends with B.
B is friends with C.
C is friends with D.
D is friends with E.

(In the language of graph theory: a friendship chain is a simple path of length 4.)

If a friendship chain exists, output "Yay!". Otherwise, output ":(". (All quotes are for clarity only.)

DEFINITION
Class:SmilesTheFriendshipUnicorn
Method:hasFriendshipChain
Parameters:int, vector <int>, vector <int>
Returns:string
Method signature:string hasFriendshipChain(int N, vector <int> A, vector <int> B)


CONSTRAINTS
-N will be between 5 and 2000, inclusive.
-A will contain between 1 and 2000 elements, inclusive.
-A and B will contain the same number of elements.
-Each element of A and B will be between 0 and N-1, inclusive.
-No one will be friends with themselves.
-The same friendship will not be given twice in the input.
-For every group containing between 1 and N-1 people (inclusive), at least one person in the group is friends with someone outside the group.


EXAMPLES

0)
5
{0, 1, 2, 3}
{1, 2, 3, 4}

Returns: "Yay!"

A friendship chain is formed by:

Person 0
Person 1
Person 2
Person 3
Person 4

in that order. (The reverse order 4-3-2-1-0 is also a valid friendship chain.)

1)
5
{0, 1, 2, 3, 1}
{1, 2, 3, 0, 4}

Returns: "Yay!"

One example of a valid friendship chain is:

Person 4
Person 1
Person 2
Person 3
Person 0


2)
6
{0, 0, 0, 0, 0}
{1, 2, 3, 4, 5}

Returns: ":("



3)
8
{1, 3, 4, 3, 4, 3, 0, 2}
{7, 7, 7, 4, 6, 5, 4, 7}

Returns: "Yay!"



4)
7
{0, 1, 1, 5, 4, 5}
{5, 2, 3, 6, 1, 1}

Returns: ":("



5)
42
{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41}

{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 0}

Returns: "Yay!"



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
		cout << "Testing SmilesTheFriendshipUnicorn (300.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1456193085;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 300.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		SmilesTheFriendshipUnicorn _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 5;
				int A[] = {0, 1, 2, 3};
				int B[] = {1, 2, 3, 4};
				_expected = "Yay!";
				_received = _obj.hasFriendshipChain(N, vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int))); break;
			}
			case 1:
			{
				int N = 5;
				int A[] = {0, 1, 2, 3, 1};
				int B[] = {1, 2, 3, 0, 4};
				_expected = "Yay!";
				_received = _obj.hasFriendshipChain(N, vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int))); break;
			}
			case 2:
			{
				int N = 6;
				int A[] = {0, 0, 0, 0, 0};
				int B[] = {1, 2, 3, 4, 5};
				_expected = ":(";
				_received = _obj.hasFriendshipChain(N, vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int))); break;
			}
			case 3:
			{
				int N = 8;
				int A[] = {1, 3, 4, 3, 4, 3, 0, 2};
				int B[] = {7, 7, 7, 4, 6, 5, 4, 7};
				_expected = "Yay!";
				_received = _obj.hasFriendshipChain(N, vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int))); break;
			}
			case 4:
			{
				int N = 7;
				int A[] = {0, 1, 1, 5, 4, 5};
				int B[] = {5, 2, 3, 6, 1, 1};
				_expected = ":(";
				_received = _obj.hasFriendshipChain(N, vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int))); break;
			}
			case 5:
			{
				int N = 42;
				int A[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41};
				int B[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 0};
				_expected = "Yay!";
				_received = _obj.hasFriendshipChain(N, vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int))); break;
			}
			/*case 6:
			{
				int N = ;
				int A[] = ;
				int B[] = ;
				_expected = ;
				_received = _obj.hasFriendshipChain(N, vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int N = ;
				int A[] = ;
				int B[] = ;
				_expected = ;
				_received = _obj.hasFriendshipChain(N, vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int N = ;
				int A[] = ;
				int B[] = ;
				_expected = ;
				_received = _obj.hasFriendshipChain(N, vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int))); break;
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
