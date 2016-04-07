// Create your own template by modifying this file!

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
using namespace std;
#define FOR(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define ALL(x) (x).begin(),(x).end()
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define SZ(X) ((int)(X).size())
#define LEN(X) strlen(X)
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define REPL(i,x) for(int i=0;x[i];i++)
#define PER(i,n) for(int i=(n)-1;i>=0;i--)
#define PER1(i,a,b) for(int i=(a);i>=(b);i--)
#define RI(x) scanf("%d",&x)
#define DRI(x) int x;RI(x)
#define RII(x,y) scanf("%d%d",&x,&y)
#define DRII(x,y) int x,y;RII(x,y)
#define RIII(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define DRIII(x,y,z) int x,y,z;RIII(x,y,z)
#define RS(x) scanf("%s",x)
#define PI(x) printf("%d\n",x)
#define PIS(x) printf("%d ",x)
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define BG begin()
#define ED end()
#define PQ priority_queue
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,-1,sizeof(x))
#define SEP(x) ((x)?'\n':' ')
#define F first
#define S second
#define V(x) vector<x >

typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long LL;
const int INF = 1000000000;

void flip(int *s, int n) {
    REP(i, n) {
        s[i] ^= 1;
    }
}

void add(int *c, int *a, int *b) {
    int carry = 0;
    REP(i, 105) {
        c[i] = a[i] + b[i] + carry;
        if (c[i] > 1) {
            carry = 1;
            c[i] -= 2;
        } else {
            carry = 0;
        }
    }
}

int main() {
    CASET {
        char A[105], B[105];
        int a[105], b[105];
        int AA[105], AB[105], BB[105], BA[105];
        MS0(AA);
        MS0(AB);
        MS0(BA);
        MS0(BB);
        MS0(a);
        MS0(b);
        RS(A); RS(B);
        int la = strlen(A), lb = strlen(B);
        REPL(i, A) {
            AA[i] = A[i] - '0';
            AB[i] = A[i] - '0';
        }
        REPL(i, B) {
            BB[i] = B[i] - '0';
            BA[i] = B[i] - '0';
        }
        if (A[0] == '0') {
            flip(AA, la);
            flip(BA, lb);
        }
        if (B[0] == '0') {
            flip(BB, lb);
            flip(AB, la);
        }
        reverse(AA, AA + la);
        reverse(AB, AB + la);
        reverse(BA, BA + lb);
        reverse(BB, BB + lb);
        add(a, AA, BA);
        add(b, BB, AB);
        reverse(a, a+104);
        reverse(b, b+104);
        REP(i, 104) {
            A[i] = '0' + a[i];
            B[i] = '0' + b[i];
        }
        A[104] = B[104] = 0;
        // PI(strcmp(A, B));
        int c = strcmp(A, B);
        if (c > 0) {
            puts("B");
        } else if (c < 0) {
            puts("A");
        } else {
            puts("Fair");
        }
    }
    return 0;
}
