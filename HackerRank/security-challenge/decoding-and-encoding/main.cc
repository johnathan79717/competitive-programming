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

int msg[1000000];
char base32[1000000];

char dict64[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
char dict32[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ234567";

int main() {
    DRI(T);
    while(T--) {
        MS0(msg);
        MS0(base32);
        RS(base32);
        int l = strlen(base32);
        assert(l % 8 == 0);
        int L = 5 * l;
        REPL(i, base32) {
            if (base32[i] == '=') {
                if (i == l-1) {
                    L -= 8;
                } else if (i == l-3) {
                    L -= 16;
                } else if (i == l-4) {
                    L -= 24;
                } else {
                    assert(i == l - 6);
                    L -= 32;
                }
                break;
            }
            int b = find(dict32, dict32+32, base32[i]) - dict32;
            assert(b >= 0 && b < 32);
            REP(j, 5) {
                msg[5 * i + j] = ((b >> (4-j)) & 1);
            }
        }
        for (int i = 0; i < L; i += 6) {
            int byte = 0;
            REP(j, 6) {
                byte <<= 1;
                byte ^= msg[i + j];
            }
            printf("%c", dict64[byte]);
        }
        if (L % 6 == 2) {
            puts("==");
        } else if (L % 6 == 4) {
            puts("=");
        } else {
            assert(L % 6 == 0);
            puts("");
        }
    }
  return 0;
}