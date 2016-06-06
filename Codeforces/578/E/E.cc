// Create your own template by modifying this file!
#include <list>
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
#define MAX(x, a) x = max(x, a)
#define MIN(x, a) x = min(x, a)
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define SZ(X) ((int)(X).size())
#define LEN(X) strlen(X)
#define FOR(i,c) for(auto &i: c)
#define ALL(x) (x).begin(),(x).end()
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define REPL(i,x) for(int i=0;x[i];i++)
#define PER(i,n) for(int i=(n)-1;i>=0;i--)
#define PER1(i,a,b) for(int i=(a);i>=(b);i--)
#define GET_4TH(_1, _2, _3, NAME, ...) NAME
#define RI(argv...) GET_4TH(argv, RI3, RI2, RI1)(argv)
#define RI1(x) scanf("%d",&x)
#define RI2(x,y) RI1(x), RI1(y)
#define RI3(x,y,z) RI1(x), RI2(y, z)
#define DRI(argv...) int argv;RI(argv)
#define RS(x) scanf("%s",x)
#define PI(x) printf("%d\n",x)
#define PIS(x) printf("%d ",x)
#define DRL(x) LL x; RL(x)
#ifdef ONLINE_JUDGE
    #define PL(x) printf("%I64d\n",x)
    #define RL(x) scanf("%I64d\n",&x)
#else
    #define PL(x) printf("%lld\n",x)
    #define RL(x) scanf("%lld\n",&x)
#endif
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define BG begin()
#define ED end()
#define PQ priority_queue
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,-1,sizeof(x))
#define SEP(x) ((x)?'\n':' ')
#define V(x) vector<x>
#define DRA(A, N) VI A(N); REP(i, N) RI(A[i])
using namespace std;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long LL;
const int INF = 1000000000;

#ifdef DEBUG
     #define debug(args...)            {dbg,args; cerr<<endl;}
#else
    #define debug(args...)              // Just strip off all debug tokens
#endif

struct debugger
{
    template<typename T> debugger& operator , (const T& v)
    {    
        cerr<<v<<" ";    
        return *this;    
    }
} dbg;

#define X first
#define Y second
typedef list<pair<char,int>> LI;
typedef pair<int, LI::iterator> P;
struct Comp {
    bool operator()(const P& p1, const P& p2) {
        return p1.X > p2.X;
    }
};
char S[100005];
int main() 
{
    RS(S);
    int N = LEN(S);
    list<pair<bool, int>> list;
    //priority_queue<pair<int, LI::iterator>, vector<P>, Comp> que;
    int l = 0, r = 0;
    while (l < N) {
        while (r < N && S[r] == S[l]) r++;
        list.emplace_back(S[l] == 'L', r-l);
        //que.push(MP(r-l, --list.end()));
        l = r;
    }
    int ans = 0;
    bool foot = list.begin()->X;
    while (SZ(list)) {
        auto it = list.begin();
        while (it != list.end()) {
            if (it->X != foot) {
                continue;
            }
            it->Y--; 
            foot = !foot;
            if (it->Y == 0) {
                auto it1 = it, it2 = it;
                it2++;
                if (it != list.begin() && it2 != list.end()) {
                    it1--;
                    it2->Y += it1->Y;
                    list.erase(it);
                    list.erase(it1);
                    it = it2;
                } else {
                    list.erase(it);
                    it = it2;
                }
            } else {
                it++;
            }
        }
        if (SZ(list)) {
            ans++;
        }
    }
    PI(ans);
}

