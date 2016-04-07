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

struct Wolf
{
	int a, b;
	Wolf() {}
	Wolf(int a, int b): a(a), b(b) {}
};

struct NarrowPassage {
	int L;
	V(int) a, b, o;
	int solve(int n, int k, bool right) {
		int largest = -1;
		REP(i, n) if(o[i] < k && b[i] > b[n-1]) larger = i;
		if(larger < 0) {
			return min(
				abs(a[i]-b[i]) + solve(n-1, false),
				(L - a[i]) + (L - b[i]) + solve(n-1, true)
				);
		} else {

		}
	}

  int minDist(int L, vector <int> a, vector <int> b) {
  	this->L = L;
  	this->a = a;
  	this->b = b;
  	auto b1 = b;
  	sort(ALL(b1));
  	int N = a.size();
  	o.resize(N);
  	REP(i, N) o[i] = lower_bound(ALL(b1), b[i]) - b1.begin();
  	int N = a.size();
  	return min(solve(N, false), solve(N, true));
  }
};

// BEGIN CUT HERE
/*
PROBLEM STATEMENT
There is a narrow passage of length L.
We will use a coordinate system where 0 and L are the ends 
of the passage.


Inside the passage there are some wolves.
You are given two vector <int>s a and b with the same 
number of elements.
The elements of a are the current coordinates of all wolves.
For each wolf, the corresponding element of b is the 
coordinate where the wolf wants to go.
That is, for each valid i, wolf i wants to move from a[i] 
to b[i].


The passage is so narrow that wolves cannot pass by each 
other.
In other words, the relative order of the wolves cannot 
change while they are in the passage.
Luckily, there is a lot of empty space on each end of the 
passage.
If some wolves reach the same end of the passage, they can 
change their order arbitrarily before reentering the 
passage.


All wolves must finish at their desired coordinates.
Return the minimum total distance the wolves have to 
travel within the passage in order to reach their final 
configuration.
Note that the distance traveled while they are reordering 
at the ends of the passage does not count.

DEFINITION
Class:NarrowPassage
Method:minDist
Parameters:int, vector <int>, vector <int>
Returns:int
Method signature:int minDist(int L, vector <int> a, vector 
<int> b)


CONSTRAINTS
-L will be between 2 and 1,000,000, inclusive.
-a and b will each contain between 1 and 50 elements, 
inclusive.
-a and b will contain the same number of elements.
-Each element of a and b will be between 1 and L-1, 
inclusive.
-Elements in a will be pairwise distinct.
-Elements in b will be pairwise distinct.


EXAMPLES

0)
5
{1, 2}
{3, 4}

Returns: 4

We have two wolves.
One of them wants to go from 1 to 3, the other one from 2 
to 4.
They can do this without passing each other.
(For example, they can both move simultaneously. 
Alternately, wolf 1 can move before wolf 0 does.
There are no restrictions on the movement of wolves other 
than they cannot pass each other within the passage.)
The total distance traveled in this case is |1-3| + |2-4| 
= 4.

1)
10
{3, 9}
{8, 6}

Returns: 14

One of the optimal ways looks as follows:

Wolf 1 moves from 9 to 10.
Wolf 0 moves from 3 to 10.
Wolf 1 moves from 10 to 6.
Wolf 0 moves from 10 to 8.



2)
265467
{133548, 103861, 29821, 199848, 92684, 219824, 215859, 
62821, 172409, 109235,
38563, 148854, 24742, 174068, 205005, 75922, 87316, 5542, 
57484, 40792,
25229, 152216, 21547, 22203, 84712, 231522, 235703, 
184895, 100787, 174440,
156904, 84898, 185568, 108732, 260098, 89488, 221604, 
104555, 165775, 90444,
81952, 149671, 209674, 22185, 45420, 41928, 16098, 65324, 
90870, 35243}
{150289, 135139, 69841, 227226, 177427, 230314, 199175, 
81572, 220468, 151049,
40009, 145963, 115246, 252932, 263651, 38434, 120096, 
69576, 29789, 115046,
33310, 260771, 5723, 80733, 107864, 142447, 235490, 
242149, 124564, 134602,
245962, 7078, 215816, 219864, 190499, 210237, 212894, 
142760, 126472, 201935,
119308, 120211, 235235, 19446, 87314, 17286, 61990, 
102050, 261812, 257}

Returns: 7148670



3)
1000000
{706292, 756214, 490048, 228791, 567805, 353900, 640393, 
562496, 217533, 934149,
938644, 127480, 777134, 999144, 41485, 544051, 417987, 
767415, 971662, 959022,
670563, 34065, 518183, 750574, 546576, 207758, 159932, 
429345, 670513, 271901,
476062, 392721, 774733, 502586, 915436, 120280, 951729, 
699859, 581770, 268966,
79392, 888601, 378829, 350198, 939459, 644983, 605862, 
721305, 269232, 137587}
{322468, 673534, 83223, 551733, 341310, 485064, 885415, 
927526, 159402, 28144,
441619, 305530, 883149, 413745, 932694, 214862, 677401, 
104356, 836580, 300580,
409942, 748444, 744205, 119051, 999286, 462508, 984346, 
887773, 856655, 245559,
418763, 840266, 999775, 962927, 779570, 488394, 760591, 
326325, 206948, 13999,
285467, 401562, 786209, 169847, 171326, 2901, 296531, 
572035, 364920, 939046}

Returns: 45670501



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
		cout << "Testing NarrowPassage (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1400343495;
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
		NarrowPassage _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int L = 5;
				int a[] = {1, 2};
				int b[] = {3, 4};
				_expected = 4;
				_received = _obj.minDist(L, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 1:
			{
				int L = 10;
				int a[] = {3, 9};
				int b[] = {8, 6};
				_expected = 14;
				_received = _obj.minDist(L, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 2:
			{
				int L = 265467;
				int a[] = {133548, 103861, 29821, 199848, 92684, 219824, 215859, 62821, 172409, 109235,
				          38563, 148854, 24742, 174068, 205005, 75922, 87316, 5542, 57484, 40792,
				          25229, 152216, 21547, 22203, 84712, 231522, 235703, 184895, 100787, 174440,
				          156904, 84898, 185568, 108732, 260098, 89488, 221604, 104555, 165775, 90444,
				          81952, 149671, 209674, 22185, 45420, 41928, 16098, 65324, 90870, 35243};
				int b[] = {150289, 135139, 69841, 227226, 177427, 230314, 199175, 81572, 220468, 151049,
				          40009, 145963, 115246, 252932, 263651, 38434, 120096, 69576, 29789, 115046,
				          33310, 260771, 5723, 80733, 107864, 142447, 235490, 242149, 124564, 134602,
				          245962, 7078, 215816, 219864, 190499, 210237, 212894, 142760, 126472, 201935,
				          119308, 120211, 235235, 19446, 87314, 17286, 61990, 102050, 261812, 257};
				_expected = 7148670;
				_received = _obj.minDist(L, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 3:
			{
				int L = 1000000;
				int a[] = {706292, 756214, 490048, 228791, 567805, 353900, 640393, 562496, 217533, 934149,
				          938644, 127480, 777134, 999144, 41485, 544051, 417987, 767415, 971662, 959022,
				          670563, 34065, 518183, 750574, 546576, 207758, 159932, 429345, 670513, 271901,
				          476062, 392721, 774733, 502586, 915436, 120280, 951729, 699859, 581770, 268966,
				          79392, 888601, 378829, 350198, 939459, 644983, 605862, 721305, 269232, 137587};
				int b[] = {322468, 673534, 83223, 551733, 341310, 485064, 885415, 927526, 159402, 28144,
				          441619, 305530, 883149, 413745, 932694, 214862, 677401, 104356, 836580, 300580,
				          409942, 748444, 744205, 119051, 999286, 462508, 984346, 887773, 856655, 245559,
				          418763, 840266, 999775, 962927, 779570, 488394, 760591, 326325, 206948, 13999,
				          285467, 401562, 786209, 169847, 171326, 2901, 296531, 572035, 364920, 939046};
				_expected = 45670501;
				_received = _obj.minDist(L, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			/*case 4:
			{
				int L = ;
				int a[] = ;
				int b[] = ;
				_expected = ;
				_received = _obj.minDist(L, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int L = ;
				int a[] = ;
				int b[] = ;
				_expected = ;
				_received = _obj.minDist(L, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int L = ;
				int a[] = ;
				int b[] = ;
				_expected = ;
				_received = _obj.minDist(L, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
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
