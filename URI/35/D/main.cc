#include <string>
#include <vector>
#include <climits>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <stack>
#include <deque>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
using namespace std;
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
#define RI(x) scanf("%d",&x)
#define RL(x) scanf("%lld",&x)
#define DRI(x) int x;RI(x)
#define DRL(x) LL x;RL(x)
#define RII(x,y) scanf("%d%d",&x,&y)
#define DRII(x,y) int x,y;RII(x,y)
#define RIII(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define DRIII(x,y,z) int x,y,z;RIII(x,y,z)
#define RS(x) scanf("%s",x)
#define PI(x) printf("%d\n",x)
#define PL(x) printf("%lld\n",x)
#define PIS(x) printf("%d ",x)
#define MP make_pair
#define PB push_back
#define PQ priority_queue
#define E emplace
#define EB emplace_back
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,-1,sizeof(x))
#define SEP(x) ((x)?'\n':' ')
#define F first
#define S second
#define V(x) vector<x >

typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long LL;
typedef unsigned long long ULL;
const int INF = 2000000000;

char str[100];
int main() {
    gets(str);
    int Y = atoi(str);
    while (Y--) {
        map<string, double> mp;
        // DRI(T);
        gets(str);
        int T = atoi(str);
        while (T--) {
            gets(str);
            string name(str);
            // getline(cin, name);
            double w;
            scanf("%lf\n", &w);
            mp[string(name)] += w;
        }
        gets(str);
        double M = atof(str);
        double ans = 0;
        vector<string> missing;
        while (true) {
            gets(str);
            string name(str);
            gets(str);
            int J = atoi(str);
            // RI(J);
            if (!J) break;
            if (mp.count(name))
                ans += J * mp[name];
            else
                missing.PB(name);
        };
        for (auto &s: missing) {
            printf("NAO LISTADO: %s\n", s.c_str());
        }
        int t = int(ans / M);
        printf("Peso total: %.2f kg\nNumero de trenos: %d\n\n", ans, t * M >= ans ? t : t+1);
        // if (Y > 0) puts("");
    }
    return 0;
}