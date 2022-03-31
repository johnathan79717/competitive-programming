#line 2 "EllysRansom.cpp"
#include <string>
#include <vector>
#include <climits>
#include <cstring>
#include <map>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <cassert>
#include <deque>
#include <stack>
#include <functional>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define FOR(I, A, B) for (int I = (A); I <= (B); ++I)
#define FORS(I, S) for (int I = 0; S[I]; ++I)
#define RS(X) scanf("%s", (X))
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define GET_POS(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
#define CASET int ___T; scanf("%d", &___T); for(int cs=1;cs<=___T;cs++)
#define MP make_pair
#define PB emplace_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define F first
#define S second
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII> VPII;
typedef pair<LL,LL> PLL;
typedef vector<PLL> VPLL;
int MOD = 1e9+7;
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}


#include <algorithm>

#include <vector>

namespace atcoder {

namespace internal {

template <class T> struct simple_queue {
    std::vector<T> payload;
    int pos = 0;
    void reserve(int n) { payload.reserve(n); }
    int size() const { return int(payload.size()) - pos; }
    bool empty() const { return pos == int(payload.size()); }
    void push(const T& t) { payload.push_back(t); }
    T& front() { return payload[pos]; }
    void clear() {
        payload.clear();
        pos = 0;
    }
    void pop() { pos++; }
};

}  // namespace internal

}  // namespace atcoder

#include <cassert>
#include <limits>
#include <queue>
#include <vector>

namespace atcoder {

template <class Cap> struct mf_graph {
  public:
    mf_graph() : _n(0) {}
    mf_graph(int n) : _n(n), g(n) {}

    int add_edge(int from, int to, Cap cap) {
        assert(0 <= from && from < _n);
        assert(0 <= to && to < _n);
        assert(0 <= cap);
        int m = int(pos.size());
        pos.push_back({from, int(g[from].size())});
        g[from].push_back(_edge{to, int(g[to].size()), cap});
        g[to].push_back(_edge{from, int(g[from].size()) - 1, 0});
        return m;
    }

    struct edge {
        int from, to;
        Cap cap, flow;
    };

    edge get_edge(int i) {
        int m = int(pos.size());
        assert(0 <= i && i < m);
        auto _e = g[pos[i].first][pos[i].second];
        auto _re = g[_e.to][_e.rev];
        return edge{pos[i].first, _e.to, _e.cap + _re.cap, _re.cap};
    }
    std::vector<edge> edges() {
        int m = int(pos.size());
        std::vector<edge> result;
        for (int i = 0; i < m; i++) {
            result.push_back(get_edge(i));
        }
        return result;
    }
    void change_edge(int i, Cap new_cap, Cap new_flow) {
        int m = int(pos.size());
        assert(0 <= i && i < m);
        assert(0 <= new_flow && new_flow <= new_cap);
        auto& _e = g[pos[i].first][pos[i].second];
        auto& _re = g[_e.to][_e.rev];
        _e.cap = new_cap - new_flow;
        _re.cap = new_flow;
    }

    Cap flow(int s, int t) {
        return flow(s, t, std::numeric_limits<Cap>::max());
    }
    Cap flow(int s, int t, Cap flow_limit) {
        assert(0 <= s && s < _n);
        assert(0 <= t && t < _n);

        std::vector<int> level(_n), iter(_n);
        internal::simple_queue<int> que;

        auto bfs = [&]() {
            std::fill(level.begin(), level.end(), -1);
            level[s] = 0;
            que.clear();
            que.push(s);
            while (!que.empty()) {
                int v = que.front();
                que.pop();
                for (auto e : g[v]) {
                    if (e.cap == 0 || level[e.to] >= 0) continue;
                    level[e.to] = level[v] + 1;
                    if (e.to == t) return;
                    que.push(e.to);
                }
            }
        };
        function<Cap(int, Cap)> dfs = [&](int v, Cap up) {
            if (v == s) return up;
            Cap res = 0;
            int level_v = level[v];
            for (int& i = iter[v]; i < int(g[v].size()); i++) {
                _edge& e = g[v][i];
                if (level_v <= level[e.to] || g[e.to][e.rev].cap == 0) continue;
                Cap d =
                    dfs(e.to, std::min(up - res, g[e.to][e.rev].cap));
                if (d <= 0) continue;
                g[v][i].cap += d;
                g[e.to][e.rev].cap -= d;
                res += d;
                if (res == up) break;
            }
            return res;
        };

        Cap flow = 0;
        while (flow < flow_limit) {
            bfs();
            if (level[t] == -1) break;
            std::fill(iter.begin(), iter.end(), 0);
            while (flow < flow_limit) {
                Cap f = dfs(t, flow_limit - flow);
                if (!f) break;
                flow += f;
            }
        }
        return flow;
    }

    std::vector<bool> min_cut(int s) {
        std::vector<bool> visited(_n);
        internal::simple_queue<int> que;
        que.push(s);
        while (!que.empty()) {
            int p = que.front();
            que.pop();
            visited[p] = true;
            for (auto e : g[p]) {
                if (e.cap && !visited[e.to]) {
                    visited[e.to] = true;
                    que.push(e.to);
                }
            }
        }
        return visited;
    }

  private:
    int _n;
    struct _edge {
        int to, rev;
        Cap cap;
    };
    std::vector<std::pair<int, int>> pos;
    std::vector<std::vector<_edge>> g;
};

}  // namespace atcoder


class EllysRansom {
public:
    string getRansom(string A, string B, string T) {
	int N = SZ(A);

	atcoder::mf_graph<int> graph(2 + N + 26);
	int s = 0, t = 1;

	REP(i, N) {
	    graph.add_edge(s, 2 + i, 1);
	    graph.add_edge(2 + i, 2 + N + A[i] - 'A', 1);
	    graph.add_edge(2 + i, 2 + N + B[i] - 'A', 1);
	}

	int f[26] = {};
	for (char c : T) {
	    f[c-'A']++;
	}

	int full = 0;
	REP(i, 26) {
	    full += f[i];
	    if (f[i]) {
		graph.add_edge(2 + N + i, t, f[i]);
	    }
	}

	if (graph.flow(s, t) != full) {
	    return "NO SOLUTION";
	}

	string ans(N, '_');
	REP(i, N) {
	    if (graph.get_edge(3 * i + 1).flow) {
		ans[i] = A[i];
	    } else if (graph.get_edge(3 * i + 2).flow) {
		ans[i] = B[i];
	    }
	}
	return ans;
    }
};

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
Elly wants to send a ransom note.
And everybody knows how to produce a proper ransom note: by cutting out letters from a newspaper and pasting them to a sheet of paper.



Elly has one page from a newspaper as her source of letters.
Her page has text on both sides and she can use letters from both sides in the ransom note.
But, of course, once she cuts out a letter and glues it to the ransom note, she can no longer use the letter that was on the other side of that piece of paper.


The letters in Elly's newspaper are perfectly aligned: whenever she cuts out a letter from the page, the cutout will have exactly one letter on the other side as well.



The girl has asked you to help her find one possible way in which she can produce the desired ransom note.


You will be given the strings A, B and T.


The strings A and B both have the same length N.
These strings describe the newspaper page: A are the letters on the front side and B are the corresponding letters on the back side of the page.
The order of letters in A and B is such that for each index i the letters A[i] and B[i] are opposite each other.


The string T is the text of the ransom note Elly wants to write.



Return a string of N characters.
For each i, character i of the returned string must be one of A[i], B[i] and '_' (underscore).
Here, A[i] and B[i] mean that you are using that character somewhere in the ransom note and '_' means that this character will remain unused.


A solution is valid if T can be obtained by rearranging the letters that appear in the returned string.
Any valid solution will be accepted.
If no valid solution exists, return "NO SOLUTION" instead (quotes for clarity).


DEFINITION
Class:EllysRansom
Method:getRansom
Parameters:string, string, string
Returns:string
Method signature:string getRansom(string A, string B, string T)


CONSTRAINTS
-A and B will each contain between 1 and 1000 characters, inclusive.
-A and B will contain the same number of characters.
-T will contain between 1 and N characters, inclusive, where N is the number of characters in A.
-All strings will contain only uppercase letters from the English alphabet ({'A'-'Z'}).


EXAMPLES

0)
"GOODLUCKANDHAVEFUNN"
"RPSETSUJMITITUOHTIW"
"TOPCODER"

Returns: "RPOET_C___D___O____"


The answer "RPOET_C___D___O____" is one of multiple valid answers for this test case.


According to this answer, we take the letters 'R' and 'P' from the back side of the page, 'O' from the front, 'E' and 'T' from the back, then we skip a letter, then we take 'C' from the front, skip 3 more letters, take a 'D' from the front, skip 3 more letters, and finally we take an 'O' from the back of the page.


In total, we have cut out exactly eight letters: R, P, O, E, T, C, D, O. These can be rearranged to spell "TOPCODER" exactly.


1)
"HELP"
"ELLY"
"HELL"

Returns: "NO SOLUTION"


The last letter is useless: we do not need 'P' or 'Y' for our ransom note.
The other three letters are not enough to form a four-letter ransom note.



2)
"NEVERMINDTHENOISEYOUHEARD"
"DEBRUOYREDNUTSAEBATSUJSTI"
"ENTERSANDMANYEAH"

Returns: "NE_ERMYNDTHENSA__A____A__"



3)
"THISWASATRIUMPHIMMAKINANOTEHEREHUGE"
"EVILALLITSERAOHWELPOEPEHTROFSSECCUS"
"APERTURESCIENCEPORTALHASEVILTESTS"

Returns: "TVISALSATRERAPHIELPOENE_TTE_SRECCUS"



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
		cout << "Testing EllysRansom (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1618676484;
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
		EllysRansom _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string A = "GOODLUCKANDHAVEFUNN";
				string B = "RPSETSUJMITITUOHTIW";
				string T = "TOPCODER";
				_expected = "RPOET_C___D___O____";
				_received = _obj.getRansom(A, B, T); break;
			}
			case 1:
			{
				string A = "HELP";
				string B = "ELLY";
				string T = "HELL";
				_expected = "NO SOLUTION";
				_received = _obj.getRansom(A, B, T); break;
			}
			case 2:
			{
				string A = "NEVERMINDTHENOISEYOUHEARD";
				string B = "DEBRUOYREDNUTSAEBATSUJSTI";
				string T = "ENTERSANDMANYEAH";
				_expected = "NE_ERMYNDTHENSA__A____A__";
				_received = _obj.getRansom(A, B, T); break;
			}
			case 3:
			{
				string A = "THISWASATRIUMPHIMMAKINANOTEHEREHUGE";
				string B = "EVILALLITSERAOHWELPOEPEHTROFSSECCUS";
				string T = "APERTURESCIENCEPORTALHASEVILTESTS";
				_expected = "TVISALSATRERAPHIELPOENE_TTE_SRECCUS";
				_received = _obj.getRansom(A, B, T); break;
			}
			/*case 4:
			{
				string A = ;
				string B = ;
				string T = ;
				_expected = ;
				_received = _obj.getRansom(A, B, T); break;
			}*/
			/*case 5:
			{
				string A = ;
				string B = ;
				string T = ;
				_expected = ;
				_received = _obj.getRansom(A, B, T); break;
			}*/
			/*case 6:
			{
				string A = ;
				string B = ;
				string T = ;
				_expected = ;
				_received = _obj.getRansom(A, B, T); break;
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
