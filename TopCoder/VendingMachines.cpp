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
// #line 40 "VendingMachines.cpp"
#include <string>
#include <vector>
class VendingMachines {
public:
    double expectedValue(int tickets, vector <int> luck, vector <int> value) {
        
    }
};
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// This problem has a non-standard time limit: 6 seconds.
This problem also has a non-standard precision limit: 1e-4.


Yesterday, Cat Noku has spent a long day at the arcade.
You are given the int tickets: the number of tickets he won by playing the games.
This morning he is the first customer to enter the arcade.
He now wants to exchange his tickets for prizes.



There are multiple vending machines at the arcade.
All vending machines have just been reset into their initial state.
The vending machines are probabilistic.
Each vending machine has two parameters: its luck factor L and its value V.
A vending machine with luck factor L and value V operates as follows:

A person inserts exactly one ticket into the machine.
The machine computes K: the number of tickets inserted into the machine since it last gave out a prize. (This includes the ticket inserted in the previous step. If the machine didn't give out any prizes yet, K is simply the total number of tickets inserted into the machine today.)
With probability min(K^2,L^2)/L^2, the machine gives out a prize with value V. Otherwise, the machine does nothing.





You are given the description of the vending machines: vector <int>s luck and value.
For each valid i, there is a vending machine with luck factor luck[i] and prize value value[i].
Each machine can be used arbitrarily many times and contains a sufficient supply of prizes (each of the same value).



Cat Noku is very stubborn.
Whenever he chooses a vending machine, he keeps on inserting tickets into the machine until he either wins a prize or runs out of tickets.
Additionally, Noku likes variety: whenever he gets a prize from a vending machine, he goes to a different machine.
In other words, Noku will never claim two consecutive prizes from the same machine.



Given the above constraint, Cat Noku wants to maximize the sum of values of prizes he gets.
More precisely, he is interested in the strategy that maximizes the expected value of that sum.
Find that strategy and return that expected value.


DEFINITION
Class:VendingMachines
Method:expectedValue
Parameters:int, vector <int>, vector <int>
Returns:double
Method signature:double expectedValue(int tickets, vector <int> luck, vector <int> value)


NOTES
-Your return value must have absolute or relative error less than 1e-4.


CONSTRAINTS
-tickets will be between 1 and 40,000, inclusive.
-n will be between 2 and 15, inclusive.
-luck,value will have exactly n elements.
-Each element of luck will be between 1 and 1,000,000,000, inclusive.
-Each element of value will be between 1 and 1,000,000,000, inclusive.


EXAMPLES

0)
2
{1,1}
{2,3}

Returns: 5.0

Cat Noku has 2 tickets.
There are two vending machines.
Each of them has luck factor 1, which means that the machine always gives out a prize.
Since Noku doesn't want to claim two consecutive prizes from the same machine, he will use each machine exactly once.
Thus, he is guaranteed to get a prize worth 2 and a prize worth 3, which means that the answer is 2+3 = 5.

1)
3
{1,1,1}
{2,3,4}

Returns: 11.0

Cat Noku can use a particular machine multiple times, he just has to switch machines each time he gets a prize.
Here, the optimal strategy is to use machine 2 (0-based index), then machine 1, and then machine 2 again.
This leaves Noku with prizes worth 4+3+4 = 11.

2)
100
{1, 1, 1}
{100,100,100}

Returns: 9999.99999999991



3)
4
{2,3}
{4,5}

Returns: 7.693072702331962

In this case, Noku has 4 tickets and there are two machines.
Machine 0 has luck factor 2 and gives out prizes with value 4.
Machine 1 has luck factor 3 and gives out prizes with value 5.

One example of how Cat Noku can spend his tickets:

Cat Noku chooses to put his first ticket into machine 0.
This machine computes that K=1. This means that Noku will get the prize with probability (1^2)/(2^2) = 1/4 = 0.25. Suppose he is unlucky and doesn't get the prize.
Due to his stubbornness, Noku must continue by putting his second ticket into machine 0.
The machine now computes that K=2, which means that Noku is guaranteed to get the prize with value 4.
Now, Noku must switch machines. He therefore moves to machine 1.
Noku puts the next ticket (his third one) into machine 1.
This machine computes that K=1. This means that Noku will only get its prize with probability 1/9. Suppose this time he's lucky and gets the prize (with value 5).
Noku switches machines again, returning back to machine 0.
Noku puts his last ticket into machine 0.
This is the first ticket that was put into this machine since it last gave out a prize. Hence, we are now back to having K=1, and therefore the probability of getting the next prize is 1/4. Suppose he does not win this prize.

In this scenario, Noku's total value of prizes is 4 + 5 = 9.

4)
11
{2,3,4}
{55,58,60}

Returns: 292.20826703848974



5)
1001
{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
{1, 4, 9, 29, 35, 40, 49, 55, 63, 72}

Returns: 12321.244694733025



6)
40000
{1000000000, 1}
{1000000000, 1}

Returns: 21333.928554321847



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
		cout << "Testing VendingMachines (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1463065205;
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
		VendingMachines _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int tickets = 2;
				int luck[] = {1,1};
				int value[] = {2,3};
				_expected = 5.0;
				_received = _obj.expectedValue(tickets, vector <int>(luck, luck+sizeof(luck)/sizeof(int)), vector <int>(value, value+sizeof(value)/sizeof(int))); break;
			}
			case 1:
			{
				int tickets = 3;
				int luck[] = {1,1,1};
				int value[] = {2,3,4};
				_expected = 11.0;
				_received = _obj.expectedValue(tickets, vector <int>(luck, luck+sizeof(luck)/sizeof(int)), vector <int>(value, value+sizeof(value)/sizeof(int))); break;
			}
			case 2:
			{
				int tickets = 100;
				int luck[] = {1, 1, 1};
				int value[] = {100,100,100};
				_expected = 9999.99999999991;
				_received = _obj.expectedValue(tickets, vector <int>(luck, luck+sizeof(luck)/sizeof(int)), vector <int>(value, value+sizeof(value)/sizeof(int))); break;
			}
			case 3:
			{
				int tickets = 4;
				int luck[] = {2,3};
				int value[] = {4,5};
				_expected = 7.693072702331962;
				_received = _obj.expectedValue(tickets, vector <int>(luck, luck+sizeof(luck)/sizeof(int)), vector <int>(value, value+sizeof(value)/sizeof(int))); break;
			}
			case 4:
			{
				int tickets = 11;
				int luck[] = {2,3,4};
				int value[] = {55,58,60};
				_expected = 292.20826703848974;
				_received = _obj.expectedValue(tickets, vector <int>(luck, luck+sizeof(luck)/sizeof(int)), vector <int>(value, value+sizeof(value)/sizeof(int))); break;
			}
			case 5:
			{
				int tickets = 1001;
				int luck[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
				int value[] = {1, 4, 9, 29, 35, 40, 49, 55, 63, 72};
				_expected = 12321.244694733025;
				_received = _obj.expectedValue(tickets, vector <int>(luck, luck+sizeof(luck)/sizeof(int)), vector <int>(value, value+sizeof(value)/sizeof(int))); break;
			}
			case 6:
			{
				int tickets = 40000;
				int luck[] = {1000000000, 1};
				int value[] = {1000000000, 1};
				_expected = 21333.928554321847;
				_received = _obj.expectedValue(tickets, vector <int>(luck, luck+sizeof(luck)/sizeof(int)), vector <int>(value, value+sizeof(value)/sizeof(int))); break;
			}
			/*case 7:
			{
				int tickets = ;
				int luck[] = ;
				int value[] = ;
				_expected = ;
				_received = _obj.expectedValue(tickets, vector <int>(luck, luck+sizeof(luck)/sizeof(int)), vector <int>(value, value+sizeof(value)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int tickets = ;
				int luck[] = ;
				int value[] = ;
				_expected = ;
				_received = _obj.expectedValue(tickets, vector <int>(luck, luck+sizeof(luck)/sizeof(int)), vector <int>(value, value+sizeof(value)/sizeof(int))); break;
			}*/
			/*case 9:
			{
				int tickets = ;
				int luck[] = ;
				int value[] = ;
				_expected = ;
				_received = _obj.expectedValue(tickets, vector <int>(luck, luck+sizeof(luck)/sizeof(int)), vector <int>(value, value+sizeof(value)/sizeof(int))); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (abs(_expected-_received) < 1e-9 || (_received > min(_expected*(1.0-1e-9), _expected*(1.0+1e-9)) && _received < max(_expected*(1.0-1e-9), _expected*(1.0+1e-9))))
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout.precision(10);
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
