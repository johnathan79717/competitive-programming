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

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;
#line 39 "BearFair.cpp"
#include <string>
#include <vector>
#include <cassert>
class BearFair {
public:
    string isFair(int n, int b, vector <int> upTo, vector <int> quantity) {
        string unfair = "unfair", fair = "fair";
        upTo.PB(b); quantity.PB(n);
        upTo.PB(0); quantity.PB(0);
        int Q = upTo.size();
        set<int> used;
        int M = 0, m = 0;
        REP(i, Q) {
            int u = upTo[i], q = quantity[i];
            if (used.count(u)) {
                continue;
            }
            used.insert(u);
            if (u == 0) continue;
            int best = Q-1;
            REP(j, Q) {
                if (upTo[j] == u && quantity[j] != q || upTo[j] > u && quantity[j] < q) {
                    return unfair;
                }
                if (upTo[j] < u && upTo[j] > upTo[best]) {
                    best = j;
                }
            }
            int u2 = upTo[best] + 1;
            assert(u2 <= u);
            int qq = q - quantity[best];
            if (qq > u - u2 + 1) return unfair;
            int odd = (u - u2 + 1) / 2 + (u % 2 && u2 % 2), even = u - u2 + 1 - odd;
            M += min(odd, qq);
            m += max(qq - even, 0);
        }
        if (m <= n/2 && n/2 <= M) {
            return fair;
        } else {
            return unfair;
        }
    }
};
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
Limak is a grizzly bear.
He is big and dreadful.
You were chilling in the forest when you suddenly met him.
It's very unfortunate for you.
He will eat all your cookies unless you can demonstrate your mathematical skills.
To test you, Limak is going to give you a puzzle to solve.



It's a well-known fact that Limak, as every bear, owns a set of numbers.
You know some information about the set:

The elements of the set are distinct positive integers.
The number of elements in the set is n. The number n is even.
All elements are between 1 and b, inclusive: bears don't know numbers greater than b.
The set contains exactly n/2 even elements and exactly n/2 odd elements, because grizzly bears only like sets with this property.




Limak smiles mysteriously and gives you q hints about his set.
The hints are numbered 0 through q-1.
For each valid i, the hint number i is the following sentence:
"If you only look at elements that are between 1 and upTo[i], inclusive, you will find exactly quantity[i] such elements in my set."



In a moment Limak will tell you the actual puzzle, but something doesn't seem right...
That smile was very strange.
You start to think about a possible reason.
Maybe Limak cheated you?
Or is he a fair grizzly bear?



You are given the ints n and b.
You are also given the vector <int>s upTo and quantity.
Return "fair" (quotes for clarity) if there exists at least one set that has all the required properties and matches all the given hints.
Otherwise, return "unfair".


DEFINITION
Class:BearFair
Method:isFair
Parameters:int, int, vector <int>, vector <int>
Returns:string
Method signature:string isFair(int n, int b, vector <int> upTo, vector <int> quantity)


CONSTRAINTS
-n will be between 2 and 50, inclusive.
-n will be even.
-b will be between n and 1000, inclusive.
-q will be between 1 and 50, inclusive.
-upTo will have exactly q elements.
-quantity will have exactly q elements.
-Each element in upTo will be between 1 and b, inclusive.
-Each element in quantity will be between 0 and n, inclusive.


EXAMPLES

0)
4
6
{3,6}
{2,4}

Returns: "fair"

Limak is a fair bear. Some sets that match his hints are {1,3,4,6} and {1,2,4,5}.

1)
4
6
{3,6}
{2,3}

Returns: "unfair"

The second hint is that exactly 3 elements are between 1 and 6 (inclusive).
But there should be 4 elements in total, all between 1 and 6 (inclusive).
In this situation Limak is clearly being unfair, there is no set that matches these hints.

2)
2
6
{1,2,3}
{1,1,2}

Returns: "unfair"

The only set that matches the hints is the set {1,3}. However, this set violates the constraint that the number of odd elements must be n/2.

3)
50
1000
{736,205,264,235,273,40,901,37,900,424,122,517,820,402,669,279,455,921,774,923,107,936,484,171,248,
186,970,231,321,902,606,24,451,585,823,270,361,292,128,521,689,683,270,726,980,652,996,909,196,357}
{35,9,9,9,9,3,46,3,46,18,7,25,39,18,32,9,20,49,37,49,7,49,24,8,9,8,49,9,12,46,29,2,20,29,39,9,16,11,7,27,33,32,9,34,49,32,50,47,8,16}

Returns: "fair"



4)
4
1000
{400,600}
{4,0}

Returns: "unfair"



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
		cout << "Testing BearFair (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1453996802;
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
		BearFair _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 4;
				int b = 6;
				int upTo[] = {3,6};
				int quantity[] = {2,4};
				_expected = "fair";
				_received = _obj.isFair(n, b, vector <int>(upTo, upTo+sizeof(upTo)/sizeof(int)), vector <int>(quantity, quantity+sizeof(quantity)/sizeof(int))); break;
			}
			case 1:
			{
				int n = 4;
				int b = 6;
				int upTo[] = {3,6};
				int quantity[] = {2,3};
				_expected = "unfair";
				_received = _obj.isFair(n, b, vector <int>(upTo, upTo+sizeof(upTo)/sizeof(int)), vector <int>(quantity, quantity+sizeof(quantity)/sizeof(int))); break;
			}
			case 2:
			{
				int n = 2;
				int b = 6;
				int upTo[] = {1,2,3};
				int quantity[] = {1,1,2};
				_expected = "unfair";
				_received = _obj.isFair(n, b, vector <int>(upTo, upTo+sizeof(upTo)/sizeof(int)), vector <int>(quantity, quantity+sizeof(quantity)/sizeof(int))); break;
			}
			case 3:
			{
				int n = 50;
				int b = 1000;
				int upTo[] = {736,205,264,235,273,40,901,37,900,424,122,517,820,402,669,279,455,921,774,923,107,936,484,171,248,
				             186,970,231,321,902,606,24,451,585,823,270,361,292,128,521,689,683,270,726,980,652,996,909,196,357};
				int quantity[] = {35,9,9,9,9,3,46,3,46,18,7,25,39,18,32,9,20,49,37,49,7,49,24,8,9,8,49,9,12,46,29,2,20,29,39,9,16,11,7,27,33,32,9,34,49,32,50,47,8,16};
				_expected = "fair";
				_received = _obj.isFair(n, b, vector <int>(upTo, upTo+sizeof(upTo)/sizeof(int)), vector <int>(quantity, quantity+sizeof(quantity)/sizeof(int))); break;
			}
			case 4:
			{
				int n = 4;
				int b = 1000;
				int upTo[] = {400,600};
				int quantity[] = {4,0};
				_expected = "unfair";
				_received = _obj.isFair(n, b, vector <int>(upTo, upTo+sizeof(upTo)/sizeof(int)), vector <int>(quantity, quantity+sizeof(quantity)/sizeof(int))); break;
			}
			/*case 5:
			{
				int n = ;
				int b = ;
				int upTo[] = ;
				int quantity[] = ;
				_expected = ;
				_received = _obj.isFair(n, b, vector <int>(upTo, upTo+sizeof(upTo)/sizeof(int)), vector <int>(quantity, quantity+sizeof(quantity)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int n = ;
				int b = ;
				int upTo[] = ;
				int quantity[] = ;
				_expected = ;
				_received = _obj.isFair(n, b, vector <int>(upTo, upTo+sizeof(upTo)/sizeof(int)), vector <int>(quantity, quantity+sizeof(quantity)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int n = ;
				int b = ;
				int upTo[] = ;
				int quantity[] = ;
				_expected = ;
				_received = _obj.isFair(n, b, vector <int>(upTo, upTo+sizeof(upTo)/sizeof(int)), vector <int>(quantity, quantity+sizeof(quantity)/sizeof(int))); break;
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
