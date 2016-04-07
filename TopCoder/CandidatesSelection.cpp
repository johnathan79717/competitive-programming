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
#define ALL(x) (x).begin(),(x).end()
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define PB push_back
#define V(T) vector<T >

struct CandidatesSelection {
  string possible(vector <string> score, vector <int> result) {
  	string p = "Possible", np = "Impossible";
  	int n = score.size(), m = score[0].size();
  	V(int) cut = {0, n};

  	V(bool) used(m);
  	while(true) {
	  	bool sorted = true;
	  	REP(i, cut.size()-1) {
	  		REP1(j, cut[i], cut[i+1]-2)
	  			if(result[j] > result[j+1])
	  				sorted = false;
	  	}
	  	if(sorted) return p;
	  	bool change = false;
	  	REP(sk, m) {
	  		if(used[sk]) continue;
		  	bool sorted = true;
		  	REP(i, cut.size()-1) {
		  		REP1(j, cut[i], cut[i+1]-2) {
		  			if(score[result[j]][sk] > score[result[j+1]][sk]) {
		  				sorted = false;
		  				break;
		  			}
		  		}
		  		if(!sorted) break;
		  	}
		  	if(!sorted) continue;
		  	change = true;
	  		used[sk] = true;
		  	REP(i, cut.size()-1)
		  		REP1(j, cut[i], cut[i+1]-2)
		  			if(score[result[j]][sk] < score[result[j+1]][sk])
		  				cut.PB(j+1);
		  }
		  if(!change) return np;
	  	sort(ALL(cut));
	  	cut.resize(unique(ALL(cut)) - cut.begin());
  	}
  }
};

// BEGIN CUT HERE
/*
PROBLEM STATEMENT
Fox Ciel wants to hire a new maid.
There are n candidates for the position.
There are m different skills a maid should have, such as 
cooking, cleaning, or discreetness.
Ciel numbered the candidates 0 through n-1 and the skills 
0 through m-1.



Ciel evaluated the level each candidate has in each of the 
skills.
You are given this information encoded in a vector 
<string> score with n elements, each consisting of m 
characters.
For each i and j, the character score[i][j] represents the 
level candidate i has in skill j.
Said character will always be between 'A' and 'Z', 
inclusive, where 'A' means the best possible and 'Z' the 
worst possible candidate.



Immediately after the reviews, the order of the candidates 
was {0, 1, ..., n-1}.
Then, Ciel spent several days thinking about whom to hire.
On each day, she chose one skill and reordered the 
candidates according to their level in that skill, from 
the best to the worst one.
Whenever two candidates had the same level in the 
currently considered skill, she kept them in the order in 
which they were after the previous day.
(Formally, the sorting algorithm she used was stable.)



You are given a vector <int> result containing a 
permutation of 0 through n-1.
Return "Possible" (quotes for clarity) if it is possible 
that after zero or more days the order of candidates was 
precisely the one given in result.
Otherwise, return "Impossible".

DEFINITION
Class:CandidatesSelection
Method:possible
Parameters:vector <string>, vector <int>
Returns:string
Method signature:string possible(vector <string> score, 
vector <int> result)


CONSTRAINTS
-n will be between 1 and 50, inclusive.
-m will be between 1 and 50, inclusive.
-score will contain exactly n elements.
-Each element of score will contain exactly m characters.
-Each character in each element of score will be an 
uppercase English letter ('A'-'Z').
-result will be a permutation of 0 through n-1.


EXAMPLES

0)
{"CC", "AA", "BB"}
{1,2,0}

Returns: "Possible"

You can sort them by any skill to get the result.

1)
{"BAB", "ABB", "AAB", "ABA"}
{2,0,1,3}

Returns: "Possible"

We can first sort them by skill 0 to get {1, 2, 3, 0}, 
then sort them by skill 1 to get {2, 0, 1, 3}.

2)
{"BAB", "ABB", "AAB", "ABA"}
{0, 1, 3, 2}

Returns: "Impossible"



3)
{"AAA", "ZZZ"}
{1, 0}

Returns: "Impossible"



4)
{"ZZZ", "AAA"}
{0, 1}

Returns: "Possible"

Ciel can do no operation at all.

5)
{"ZYYYYX","YXZYXY","ZZZZXX","XZXYYX","ZZZYYZ","ZZXXYZ","
ZYZZXZ","XZYYZX"}
{3,7,1,0,2,5,6,4}

Returns: "Possible"



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
		cout << "Testing CandidatesSelection (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1399738302;
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
		CandidatesSelection _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string score[] = {"CC", "AA", "BB"};
				int result[] = {1,2,0};
				_expected = "Possible";
				_received = _obj.possible(vector <string>(score, score+sizeof(score)/sizeof(string)), vector <int>(result, result+sizeof(result)/sizeof(int))); break;
			}
			case 1:
			{
				string score[] = {"BAB", "ABB", "AAB", "ABA"};
				int result[] = {2,0,1,3};
				_expected = "Possible";
				_received = _obj.possible(vector <string>(score, score+sizeof(score)/sizeof(string)), vector <int>(result, result+sizeof(result)/sizeof(int))); break;
			}
			case 2:
			{
				string score[] = {"BAB", "ABB", "AAB", "ABA"};
				int result[] = {0, 1, 3, 2};
				_expected = "Impossible";
				_received = _obj.possible(vector <string>(score, score+sizeof(score)/sizeof(string)), vector <int>(result, result+sizeof(result)/sizeof(int))); break;
			}
			case 3:
			{
				string score[] = {"AAA", "ZZZ"};
				int result[] = {1, 0};
				_expected = "Impossible";
				_received = _obj.possible(vector <string>(score, score+sizeof(score)/sizeof(string)), vector <int>(result, result+sizeof(result)/sizeof(int))); break;
			}
			case 4:
			{
				string score[] = {"ZZZ", "AAA"};
				int result[] = {0, 1};
				_expected = "Possible";
				_received = _obj.possible(vector <string>(score, score+sizeof(score)/sizeof(string)), vector <int>(result, result+sizeof(result)/sizeof(int))); break;
			}
			case 5:
			{
				string score[] = {"ZYYYYX","YXZYXY","ZZZZXX","XZXYYX","ZZZYYZ","ZZXXYZ","ZYZZXZ","XZYYZX"};
				int result[] = {3,7,1,0,2,5,6,4};
				_expected = "Possible";
				_received = _obj.possible(vector <string>(score, score+sizeof(score)/sizeof(string)), vector <int>(result, result+sizeof(result)/sizeof(int))); break;
			}
			/*case 6:
			{
				string score[] = ;
				int result[] = ;
				_expected = ;
				_received = _obj.possible(vector <string>(score, score+sizeof(score)/sizeof(string)), vector <int>(result, result+sizeof(result)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				string score[] = ;
				int result[] = ;
				_expected = ;
				_received = _obj.possible(vector <string>(score, score+sizeof(score)/sizeof(string)), vector <int>(result, result+sizeof(result)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				string score[] = ;
				int result[] = ;
				_expected = ;
				_received = _obj.possible(vector <string>(score, score+sizeof(score)/sizeof(string)), vector <int>(result, result+sizeof(result)/sizeof(int))); break;
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
