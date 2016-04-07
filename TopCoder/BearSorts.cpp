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

class BearSorts {
	public:
	int index(vector <int> sortedSequence) {
		
	}
};
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Bear Limak was chilling in the forest when he suddenly found a computer program.
The program was a correct implementation of MergeSort.
Below you can find the program in pseudocode.

# mergeSort(left,right) sorts elements left, left+1, ..., right-1 of a global array T
function mergeSort(left,right):
    # if there is at most one element, we are done
    if left+1 >= right: return

    # otherwise, split the sequence into halves, sort each half separately
    mid = (left + right) div 2
    mergeSort(left,mid)
    mergeSort(mid,right)

    # then merge the two halves together
    merged = []    # an empty sequence
    p1 = left
    p2 = mid
    while (p1 < mid) or (p2 < right):
        if p1 == mid:
            merged.append( T[p2] )
            p2 += 1
        else if p2 == right:
            merged.append( T[p1] )
            p1 += 1
        else:
            if LESS( T[p1], T[p2] ):
                merged.append( T[p1] )
                p1 += 1
            else:
                merged.append( T[p2] )
                p2 += 1

    # finally, move the merged elements back into the original array
    for i from left to right-1 inclusive:
        T[i] = merged[i-left]

Limak noticed that one part of the implementation was missing: the function LESS.
You can probably guess that the function is supposed to return a boolean value stating whether the first argument is less than the second argument.
However, Limak is a bear and he didn't know that.
Instead he implemented his own version of this function.
Limak's function uses a true random number generator.
Each of the two possible return values (true, false) is returned with probability 50 percent.

The random values generated in different calls to Limak's function LESS are mutually independent.
Note that even if you call LESS twice with the same arguments, the two return values may differ.

After implementing LESS, Limak decided to run his brand new program.
He initialized the global array T to contain N elements.
Then, he filled the values 1 through N into the array: for each valid i, he set T[i] to i+1.
Finally, he executed the function mergeSort(0,N).

Even with Limak's new LESS function, the program never crashes.
On the other hand, it does not necessarily produce a sorted sequence when it terminates.
In general, when the program terminates, the array T will contain some permutation of the numbers 1 through N.

After running the program many times, Limak has noticed that different output permutations are produced with different probabilities.
Your task is to help him learn more about these probabilities.

Imagine a list of all N! permutations of numbers 1 through N.
For each such permutation P we have computed the probability prob(P) that Limak's program outputs P.
We will now order all those N! permutations according to that probability in descending order.
(I.e., the most probable permutations are at the beginning of the list.)
Ties are broken using lexicographic order.
(I.e., if two permutations have exactly the same probability, the lexicographically smaller one is sooner in the list.)

You are given a vector <int> sortedSequence with N elements, containing a permutation of 1 through N.
Let X be the 1-based index of this permutation in the list defined above.
Compute and return the value (X modulo 1,000,000,007).

DEFINITION
Class:BearSorts
Method:index
Parameters:vector <int>
Returns:int
Method signature:int index(vector <int> sortedSequence)


NOTES
-Given two different permutations of 1 through N, the lexicographically smaller one is the one with the smaller element at the first index where they differ.


CONSTRAINTS
-sortedSequence will contain exactly N elements.
-N will be between 1 and 40, inclusive.
-Elements of sortedSequence will be between 1 and N, inclusive.
-Elements of sortedSequence will be pairwise distinct.


EXAMPLES

0)
{1,3,2}

Returns: 2

Some of the 3! = 6 possible permutations are more likely than others.
However, in this specific case it just happens that the correct sorted order of permutations is the same as their lexicographic order.
Hence, the 1-based index of the permutation {1,3,2} is 2.

1)
{1,3,2,4}

Returns: 9

For N = 4, the correct sorted order of permutations is not the same as their lexicographic order.
The given permutation {1,3,2,4} is third in lexicographic order but only ninth in the order according to their probability.
More precisely:

There are 8 permutations such that each of them will appear with a strictly greater probability.
There are some other permutations that have the same probability as {1,3,2,4}, but all of these are lexicographically greater than {1,3,2,4}.


2)
{5,4,3,2,1}

Returns: 72



3)
{1,2,4,3,5,6,7}

Returns: 33



4)
{40,39,38,37,36,35,20,33,32,31,30,29,2,27,26,17,24,23,22,21,19,34,18,6,3,15,14,13,12,11,10,9,8,7,25,5,4,16,28,1}

Returns: 984023422



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
		cout << "Testing BearSorts (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1438446636;
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
		BearSorts _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int sortedSequence[] = {1,3,2};
				_expected = 2;
				_received = _obj.index(vector <int>(sortedSequence, sortedSequence+sizeof(sortedSequence)/sizeof(int))); break;
			}
			case 1:
			{
				int sortedSequence[] = {1,3,2,4};
				_expected = 9;
				_received = _obj.index(vector <int>(sortedSequence, sortedSequence+sizeof(sortedSequence)/sizeof(int))); break;
			}
			case 2:
			{
				int sortedSequence[] = {5,4,3,2,1};
				_expected = 72;
				_received = _obj.index(vector <int>(sortedSequence, sortedSequence+sizeof(sortedSequence)/sizeof(int))); break;
			}
			case 3:
			{
				int sortedSequence[] = {1,2,4,3,5,6,7};
				_expected = 33;
				_received = _obj.index(vector <int>(sortedSequence, sortedSequence+sizeof(sortedSequence)/sizeof(int))); break;
			}
			case 4:
			{
				int sortedSequence[] = {40,39,38,37,36,35,20,33,32,31,30,29,2,27,26,17,24,23,22,21,19,34,18,6,3,15,14,13,12,11,10,9,8,7,25,5,4,16,28,1};
				_expected = 984023422;
				_received = _obj.index(vector <int>(sortedSequence, sortedSequence+sizeof(sortedSequence)/sizeof(int))); break;
			}
			/*case 5:
			{
				int sortedSequence[] = ;
				_expected = ;
				_received = _obj.index(vector <int>(sortedSequence, sortedSequence+sizeof(sortedSequence)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int sortedSequence[] = ;
				_expected = ;
				_received = _obj.index(vector <int>(sortedSequence, sortedSequence+sizeof(sortedSequence)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int sortedSequence[] = ;
				_expected = ;
				_received = _obj.index(vector <int>(sortedSequence, sortedSequence+sizeof(sortedSequence)/sizeof(int))); break;
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
