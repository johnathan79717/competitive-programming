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
#include <cassert>
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

#line 41 "AqaAsadiTrains.cpp"
#include <string>
#include <vector>
class AqaAsadiTrains {
public:
    int getMax(vector <int> C, vector <int> A, vector <int> T) {

    }
};

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
There are K football posts (e. g. goalkeeper, defender, left-wing forward).
Aqa Asadi has N students to train.
All students are arranged in a line. 
At any moment, each student is trained to exactly one of the K posts.
The posts are numbered from 0 to K-1 and the students are numbered from 0 to N-1 in the order in which they initially stand in the line.


The training is performed as a sequence of steps.
In each step Aqa Asadi performs one of the following operations:



Call a manager of a team and have them hire one of the students. The student leaves the line and goes away with the manager.  Aqa Asadi receives a commission from the manager for this action. The commission depends on the post for which the player is trained: if the post is x, Aqa Asadi gains C[x] dollars.


Select one student in the line and convert them from a player to a coach. Then, select one of the students adjacent to the new coach and have the coach train that player. Once that is done, the coach will leave the line and go home. The other student will remain in the line but they will now be trained to a possibly different post. The new post of this student is t[x][y], where x is the post of the coach and y is the old post of this student.





Notes:



Some positions may currently be so undesirable that the commission for them is negative. E.g., if C[7] = -3 and Aqa Asadi has a student trained to post 7, if he wants a manager to hire that student, he has to pay the manager 3 dollars.


During the training process Aqa Asadi's bilance may be negative. E.g., the example action described in the previous line can be the very first action of the training process, and after this action Aqa's bilance will be -3 dollars.


In the end there can be some students left unhired by any manager, and for those you will get no money at all, but you also don't have to pay the manager to hire them.
However, you cannot just send a student away from the line during the training process without having them hired.


Due to Aqa Asadi's unique training process, the new post t[x][y] may be different from both x and y.


The training process is not necessarily symmetric: in general, t[x][y] may be different from t[y][x].


Please remember that at each moment each student is only trained to one post. When they are coached, they learn the new post but forget the old one.


Whenever a student leaves the line for any reason, his neighbors now become adjacent in the new line.





The input you are given are the vector <int>s C, A, and T, with the following meanings:



The array C has K elements. C[x] is the commission Aqa Asadi receives from a manager each time they sign a player with post x.


The array A has N elements. A[y] is the original post to which student y is trained.


The array T has K*K elements. The value t[i][j] is equal to T[i * K + j].



Aqa Asadi would like to make as much money as possible on the commissions. Calculate and return his largest possible total profit.


DEFINITION
Class:AqaAsadiTrains
Method:getMax
Parameters:vector <int>, vector <int>, vector <int>
Returns:int
Method signature:int getMax(vector <int> C, vector <int> A, vector <int> T)


CONSTRAINTS
-K and N will each be between 1 and 50, inclusive.
-C will have K elements. 
-Elements of C will be between -1000000 and 1000000 (-10^6 to 10^6), inclusive.
-A will have N elements.
-Elements of A will be between 0 and K-1, inclusive.
-T will have K*K elements.
-Elements of T will be between 0 and K-1, inclusive.


EXAMPLES

0)
{3, 0, -5}
{0, 0}
{2, 0, 0, 2, 1, 1, 1, 2, 2}

Returns: 6

There are three posts. For each student trained to post 0 Aqa Asadi can get a commission of 3 dollars. As he already has two such students, the best solution is to have a manager sign both of them to get 3 + 3 dollars.

1)
{40, -10, -30, 10, 50}
{3, 2}
{0, 1, 2, 2, 4, 4, 3, 2, 3, 1, 3, 0, 0, 2, 3, 2, 0, 3, 1, 3, 4, 2, 4, 4, 3}

Returns: 10


Aqa Asadi has two students. If he has a manager sign both of them, he will get the provisions C[3] + C[2] = 10 + (-30) = (-20). That's worse than doing nothing.


A better solution would be to have a manager sign student 0 and then to just send student 1 away. The commission for doing this is C[3] = 10.


Coaching does not help us here, either.


2)
{40, -10, -30, 10, 50}
{3, 2}
{0, 1, 2, 2, 4, 4, 3, 2, 3, 1, 3, 0, 0, 0, 3, 2, 0, 4, 1, 3, 4, 2, 4, 4, 3}

Returns: 50

The provisions and players are the same as in Example #1 but coaching now works in a different way. If we convert student 1 to a coach and have them re-train student 0, we will get a single student who will now be trained to the post t[2][3] = 0 and we can get the commission C[0] = 40 for signing him up with a team. An even better solution is to convert student 0 to a coach and have them re-train student 1 to the new post t[3][2] = 4. We will then get the commission C[4] = 50.

3)
{10, -47}
{1, 0, 1}
{1, 1, 1, 0}

Returns: 20


There are two player types: type 0 is a good player (worth 10) and type 1 is a bad player (worth -47).


The optimal solution for Aqa Asadi is to first sell the middle player, which leaves two bad players who are now adjacent.
Now he can have one of them train the other one, producing a second good player.


4)
{10, -47}
{1, 1, 1, 1, 1, 1, 1}
{1, 1, 1, 0}

Returns: 30

The optimal solution is to create three pairs of students. In each pair one of the students will coach the other one. In this way we can produce three good players. One bad player will be left over.

5)
{-30, 10, -10, -40, -30}
{1, 1, 3, 1, 3}
{4, 4, 1, 2, 1, 2, 1, 0, 3, 0, 2, 0, 0, 0, 4, 1, 3, 3, 2, 0, 0, 0, 2, 0, 2}

Returns: 30

The optimal solution is to have a manager hire students 0, 1, 3, and to leave the other two students unhired.

*/
// END CUT HERE

// BEGIN CUT HERE
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
		cout << "Testing AqaAsadiTrains (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1592756878;
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
		AqaAsadiTrains _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int C[] = {3, 0, -5};
				int A[] = {0, 0};
				int T[] = {2, 0, 0, 2, 1, 1, 1, 2, 2};
				_expected = 6;
				_received = _obj.getMax(vector <int>(C, C+sizeof(C)/sizeof(int)), vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(T, T+sizeof(T)/sizeof(int))); break;
			}
			case 1:
			{
				int C[] = {40, -10, -30, 10, 50};
				int A[] = {3, 2};
				int T[] = {0, 1, 2, 2, 4, 4, 3, 2, 3, 1, 3, 0, 0, 2, 3, 2, 0, 3, 1, 3, 4, 2, 4, 4, 3};
				_expected = 10;
				_received = _obj.getMax(vector <int>(C, C+sizeof(C)/sizeof(int)), vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(T, T+sizeof(T)/sizeof(int))); break;
			}
			case 2:
			{
				int C[] = {40, -10, -30, 10, 50};
				int A[] = {3, 2};
				int T[] = {0, 1, 2, 2, 4, 4, 3, 2, 3, 1, 3, 0, 0, 0, 3, 2, 0, 4, 1, 3, 4, 2, 4, 4, 3};
				_expected = 50;
				_received = _obj.getMax(vector <int>(C, C+sizeof(C)/sizeof(int)), vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(T, T+sizeof(T)/sizeof(int))); break;
			}
			case 3:
			{
				int C[] = {10, -47};
				int A[] = {1, 0, 1};
				int T[] = {1, 1, 1, 0};
				_expected = 20;
				_received = _obj.getMax(vector <int>(C, C+sizeof(C)/sizeof(int)), vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(T, T+sizeof(T)/sizeof(int))); break;
			}
			case 4:
			{
				int C[] = {10, -47};
				int A[] = {1, 1, 1, 1, 1, 1, 1};
				int T[] = {1, 1, 1, 0};
				_expected = 30;
				_received = _obj.getMax(vector <int>(C, C+sizeof(C)/sizeof(int)), vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(T, T+sizeof(T)/sizeof(int))); break;
			}
			case 5:
			{
				int C[] = {-30, 10, -10, -40, -30};
				int A[] = {1, 1, 3, 1, 3};
				int T[] = {4, 4, 1, 2, 1, 2, 1, 0, 3, 0, 2, 0, 0, 0, 4, 1, 3, 3, 2, 0, 0, 0, 2, 0, 2};
				_expected = 30;
				_received = _obj.getMax(vector <int>(C, C+sizeof(C)/sizeof(int)), vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(T, T+sizeof(T)/sizeof(int))); break;
			}
			/*case 6:
			{
				int C[] = ;
				int A[] = ;
				int T[] = ;
				_expected = ;
				_received = _obj.getMax(vector <int>(C, C+sizeof(C)/sizeof(int)), vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(T, T+sizeof(T)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int C[] = ;
				int A[] = ;
				int T[] = ;
				_expected = ;
				_received = _obj.getMax(vector <int>(C, C+sizeof(C)/sizeof(int)), vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(T, T+sizeof(T)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int C[] = ;
				int A[] = ;
				int T[] = ;
				_expected = ;
				_received = _obj.getMax(vector <int>(C, C+sizeof(C)/sizeof(int)), vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(T, T+sizeof(T)/sizeof(int))); break;
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
