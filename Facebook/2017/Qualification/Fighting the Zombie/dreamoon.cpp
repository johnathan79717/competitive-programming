#include <functional>
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
#include <deque>
#include <stack>
#include <cassert>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define DRI(X) int (X); scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define RS(X) scanf("%s", (X))
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define MP make_pair
#define PB push_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define PII pair<int,int>
#define VI vector<int>
#define VPII vector<pair<int,int> >
#define PLL pair<long long,long long>
#define VPLL vector<pair<long long,long long> >
#define F first
#define S second
typedef long long LL;
using namespace std;
double dp[401];
double f(int x,int y,int z,int H){
    MS0(dp);
    dp[0]=1;
    REP(k,x){
        for(int j=400-y;j>=0;j--){
            REPP(i,1,y+1)dp[j+i]+=dp[j]/y;
            dp[j]=0;
        }
    }
    double res=0;
    REPP(i,1,401){
        if(i+z>=H)res+=dp[i];
    }
    return res;
}
int main(){
    CASET{
        double an=0;
        DRII(H,S);
        REP(i,S){
            char s[24];
            RS(s);
            int d=0;
            while(s[d]!='d')d++;
            s[d]=0;
            int x=atoi(s);
            int z=0;
            int nxt=d+1;
            while(s[nxt]&&s[nxt]!='-'&&s[nxt]!='+')nxt++;
            if(s[nxt])z=atoi(s+nxt);
            s[nxt]=0;
            int y=atoi(s+d+1);
            an=max(an,f(x,y,z,H));
        }
        printf("Case #%d: %.6f\n",case_n++,an);
    }
    return 0;
}
