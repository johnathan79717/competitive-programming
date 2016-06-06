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
#include <sstream>
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
// #line 40 "Library.cpp"
#include <string>
#include <vector>
class Library {
public:
    int documentAccess(vector <string> records, vector <string> userGroups, vector <string> roomRights) {
        set<string> u(userGroups.begin(), userGroups.end()), r(roomRights.begin(), roomRights.end()), ans;
        for (auto &s: records) {
            istringstream iss(s);
            string doc, user, room;
            iss >> doc >> room >> user;
            if (u.count(user) && r.count(room)) {
                ans.insert(doc);
            }
        }
        return ans.size();
    }
};
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Mr. Agent has entered a government library where secret documents are stored.  Documents are stored in different rooms, and each document has a list of user groups that can access it.  In order to access a document, a person must have access to the room in which the document is stored and also be a member of at least one user group with access to the document.  Your task is to determine the number of documents Mr. Agent can access.

You are given a vector <string> userGroups, each element of which is the name of a user group in which Mr. Agent is a member.  You are also given a String[] roomRights, each element of which is the name of a room to which Mr. Agent has access.  The documents are given in the vector <string> records.  Each element of records is formatted "document_name room user_group" (quotes for clarity), where document_name is the name of a document, room is the name of the room where the document is located, and user_group is the name of a user group that has access to the document.  If multiple user groups have access to a document, there will be an entry in records for each group.  All documents have distinct names, all rooms have distinct names, and all user groups have distinct names.  Return the number of documents Mr. Agent can access.


DEFINITION
Class:Library
Method:documentAccess
Parameters:vector <string>, vector <string>, vector <string>
Returns:int
Method signature:int documentAccess(vector <string> records, vector <string> userGroups, vector <string> roomRights)


CONSTRAINTS
-records, userGroups and roomRights will each contain between 0 and 50 elements, inclusive.
-Each element of userGroups and roomRights will contain between 1 and 15 lowercase letters ('a'-'z').
-Each element of records will be formatted as "document_name room user_group" (quotes for clarity), where document_name, room and user_group each contain between 1 and 15 lowercase letters ('a'-'z').
-All elements of records with the same document_name will contain the same room.
-All elements of records will be distinct.
-All elements of userGroups will be distinct.
-All elements of roomRights will be distinct.


EXAMPLES

0)
{"diary computers editor","fairytale gardening editor","comix cars author","comix cars librarian"}
{"employee","editor","author"}
{"history","cars","computers"}

Returns: 2

Mr. Agent only has access to the documents "diary" and "comix".

1)
{"diary computers editor","fairytale gardening editor","comix cars author","comix cars librarian"}
{"employee","editor","author","librarian"}
{"history","cars","computers"}

Returns: 2

Three elements of records satisfy the conditions, but two of them are for the same document (comix).

2)
{"diary computers editor","fairytale gardening editor","comix cars author","comix cars librarian"}
{"employee","editor","author","librarian"}
{}

Returns: 0

Mr. Agent can not access any rooms.

3)
{"a b c","a b d","b b c","b b d","e c d","e c b","e c c","t d e"}
{"c","d","x"}
{"a","b","c"}

Returns: 3



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
		cout << "Testing Library (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1463328850;
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
		Library _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string records[] = {"diary computers editor","fairytale gardening editor","comix cars author","comix cars librarian"};
				string userGroups[] = {"employee","editor","author"};
				string roomRights[] = {"history","cars","computers"};
				_expected = 2;
				_received = _obj.documentAccess(vector <string>(records, records+sizeof(records)/sizeof(string)), vector <string>(userGroups, userGroups+sizeof(userGroups)/sizeof(string)), vector <string>(roomRights, roomRights+sizeof(roomRights)/sizeof(string))); break;
			}
			case 1:
			{
				string records[] = {"diary computers editor","fairytale gardening editor","comix cars author","comix cars librarian"};
				string userGroups[] = {"employee","editor","author","librarian"};
				string roomRights[] = {"history","cars","computers"};
				_expected = 2;
				_received = _obj.documentAccess(vector <string>(records, records+sizeof(records)/sizeof(string)), vector <string>(userGroups, userGroups+sizeof(userGroups)/sizeof(string)), vector <string>(roomRights, roomRights+sizeof(roomRights)/sizeof(string))); break;
			}
			case 2:
			{
				string records[] = {"diary computers editor","fairytale gardening editor","comix cars author","comix cars librarian"};
				string userGroups[] = {"employee","editor","author","librarian"};
				string roomRights[] = {};
				_expected = 0;
				_received = _obj.documentAccess(vector <string>(records, records+sizeof(records)/sizeof(string)), vector <string>(userGroups, userGroups+sizeof(userGroups)/sizeof(string)), vector <string>(roomRights, roomRights+sizeof(roomRights)/sizeof(string))); break;
			}
			case 3:
			{
				string records[] = {"a b c","a b d","b b c","b b d","e c d","e c b","e c c","t d e"};
				string userGroups[] = {"c","d","x"};
				string roomRights[] = {"a","b","c"};
				_expected = 3;
				_received = _obj.documentAccess(vector <string>(records, records+sizeof(records)/sizeof(string)), vector <string>(userGroups, userGroups+sizeof(userGroups)/sizeof(string)), vector <string>(roomRights, roomRights+sizeof(roomRights)/sizeof(string))); break;
			}
			/*case 4:
			{
				string records[] = ;
				string userGroups[] = ;
				string roomRights[] = ;
				_expected = ;
				_received = _obj.documentAccess(vector <string>(records, records+sizeof(records)/sizeof(string)), vector <string>(userGroups, userGroups+sizeof(userGroups)/sizeof(string)), vector <string>(roomRights, roomRights+sizeof(roomRights)/sizeof(string))); break;
			}*/
			/*case 5:
			{
				string records[] = ;
				string userGroups[] = ;
				string roomRights[] = ;
				_expected = ;
				_received = _obj.documentAccess(vector <string>(records, records+sizeof(records)/sizeof(string)), vector <string>(userGroups, userGroups+sizeof(userGroups)/sizeof(string)), vector <string>(roomRights, roomRights+sizeof(roomRights)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string records[] = ;
				string userGroups[] = ;
				string roomRights[] = ;
				_expected = ;
				_received = _obj.documentAccess(vector <string>(records, records+sizeof(records)/sizeof(string)), vector <string>(userGroups, userGroups+sizeof(userGroups)/sizeof(string)), vector <string>(roomRights, roomRights+sizeof(roomRights)/sizeof(string))); break;
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
