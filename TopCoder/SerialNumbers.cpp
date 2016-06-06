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
// #line 40 "SerialNumbers.cpp"
#include <string>
#include <vector>
class SerialNumbers {
public:
    int sum(const string s) {
        int a = 0;
        for (int c: s) {
            if (isdigit(c)) a += c - '0';
        }
        return a;
    }
    vector <string> sortSerials(vector <string> serialNumbers) {
        sort(serialNumbers.begin(), serialNumbers.end(), [&](const string &s1, const string &s2) {
            if (s1.size() != s2.size()) {
                return s1.size() < s2.size();
            }
            if (sum(s1) != sum(s2)) {
                return sum(s1) < sum(s2);
            }
            return s1 < s2;
        });
        return serialNumbers;
    }
};
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// You own a lot of guitars, and each guitar has a unique serial number.  You want to be able to  look up serial numbers quickly, so you decide to sort the entire list as follows.

Each serial number consists of uppercase letters ('A' - 'Z') and digits ('0' - '9'). To see if serial number A comes before serial number B, use the following steps:

   If A and B have a different length, the one with the shortest length comes first.
   Else if sum_of_digits(A) differs from sum_of_digits(B) (where sum_of_digits(X) returns the sum of all digits in string X), the one with the lowest sum comes first.
   Else compare them alphabetically, where digits come before letters.

Given a vector <string> serialNumbers, return a vector <string> with the ordered list of serial numbers in increasing order.

DEFINITION
Class:SerialNumbers
Method:sortSerials
Parameters:vector <string>
Returns:vector <string>
Method signature:vector <string> sortSerials(vector <string> serialNumbers)


CONSTRAINTS
-serialNumbers will contain between 1 and 50 elements, inclusive.
-Each element of serialNumbers will contain between 1 and 50 characters, inclusive.
-serialNumbers will only contain uppercase letters ('A' - 'Z') and digits ('0' - '9').
-All elements of serialNumbers will be distinct.


EXAMPLES

0)
{"ABCD","145C","A","A910","Z321"}

Returns: {"A", "ABCD", "Z321", "145C", "A910" }

The first serial is "A" because it has the shortest length. All others have length 4, but "ABCD" has the lowest sum. Next lowest is "Z321", and finally "A910" comes before "145C" because "A" comes before the "1" (they both have sum = 10)

1)
{"Z19", "Z20"}

Returns: {"Z20", "Z19" }

1+9 > 2+0, so "Z20" comes first.

2)
{"34H2BJS6N","PIM12MD7RCOLWW09","PYF1J14TF","FIPJOTEA5"}

Returns: {"FIPJOTEA5", "PYF1J14TF", "34H2BJS6N", "PIM12MD7RCOLWW09" }



3)
{"ABCDE", "BCDEF", "ABCDA", "BAAAA", "ACAAA"}

Returns: {"ABCDA", "ABCDE", "ACAAA", "BAAAA", "BCDEF" }



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
		cout << "Testing SerialNumbers (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1463329368;
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
		SerialNumbers _obj;
		vector <string> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string serialNumbers[] = {"ABCD","145C","A","A910","Z321"};
				string __expected[] = {"A", "ABCD", "Z321", "145C", "A910" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.sortSerials(vector <string>(serialNumbers, serialNumbers+sizeof(serialNumbers)/sizeof(string))); break;
			}
			case 1:
			{
				string serialNumbers[] = {"Z19", "Z20"};
				string __expected[] = {"Z20", "Z19" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.sortSerials(vector <string>(serialNumbers, serialNumbers+sizeof(serialNumbers)/sizeof(string))); break;
			}
			case 2:
			{
				string serialNumbers[] = {"34H2BJS6N","PIM12MD7RCOLWW09","PYF1J14TF","FIPJOTEA5"};
				string __expected[] = {"FIPJOTEA5", "PYF1J14TF", "34H2BJS6N", "PIM12MD7RCOLWW09" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.sortSerials(vector <string>(serialNumbers, serialNumbers+sizeof(serialNumbers)/sizeof(string))); break;
			}
			case 3:
			{
				string serialNumbers[] = {"ABCDE", "BCDEF", "ABCDA", "BAAAA", "ACAAA"};
				string __expected[] = {"ABCDA", "ABCDE", "ACAAA", "BAAAA", "BCDEF" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.sortSerials(vector <string>(serialNumbers, serialNumbers+sizeof(serialNumbers)/sizeof(string))); break;
			}
			/*case 4:
			{
				string serialNumbers[] = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.sortSerials(vector <string>(serialNumbers, serialNumbers+sizeof(serialNumbers)/sizeof(string))); break;
			}*/
			/*case 5:
			{
				string serialNumbers[] = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.sortSerials(vector <string>(serialNumbers, serialNumbers+sizeof(serialNumbers)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string serialNumbers[] = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.sortSerials(vector <string>(serialNumbers, serialNumbers+sizeof(serialNumbers)/sizeof(string))); break;
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
			cout << "           Expected: {";
			for (unsigned i = 0; i < _expected.size(); i++)
			{
				if (i) cout << ",";
				cout << " \"" << _expected[i] << "\"";
			}
			cout << " }" << endl;
			cout << "           Received: {";
			for (unsigned i = 0; i < _received.size(); i++)
			{
				if (i) cout << ",";
				cout << " \"" << _received[i] << "\"";
			}
			cout << " }" << endl;
		}
	}
}

// END CUT HERE
