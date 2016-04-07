#include <cstdio> 
#include <iostream> 
#include <cmath> 
#include <string> 
#include <list> 
#include <vector> 
#include <algorithm> 
#include <functional> 
#include <utility> 
#include <set> 
#include <map> 
#include <complex> 
#include <queue> 
#include <stack> 
#include <cstdlib> 
#include <ctime> 
#include <cstring> 
#include <string.h> 
 
using namespace std; 
 
typedef unsigned int uint; 
typedef long long int64; 
typedef unsigned long long uint64; 
typedef unsigned short ushort; 
typedef unsigned char uchar; 
typedef pair<int,int> ipair; 
typedef vector<int> VI; 
typedef vector<string> VS; 
typedef vector<double> VD; 
#define SIZE(A) ((int)(A.size()))
#define LENGTH(A) ((int)(A.length()))
#define MP(A,B) make_pair(A,B)
const double pi=acos(-1.0); 
const double eps=1e-11; 
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,a) for(int i=0;i<(a);++i)
#define ALL(a) (a).begin(),(a).end()
 
template<class T> T sqr(const T &x) { return x*x; } 
template<class T> T lowbit(const T &x) { return (x^(x-1))&x; } 
template<class T> int countbit(const T &n) { return (n==0)?0:(1+countbit(n&(n-1))); } 
template<class T> void ckmin(T &a,const T &b) { if (b<a) a=b; } 
template<class T> void ckmax(T &a,const T &b) { if (b>a) a=b; } 
 
const int maxn=1024;
 
int n,m;
char sa[maxn],sb[maxn];
int f[maxn][maxn],g[maxn][maxn];
int a[maxn],b[maxn];
int next_a[maxn][26],next_b[maxn][26];
 
void prepare(int a[],int next[][26])
{
    for (int i=n;i>=0;i--) REP(j,26) if (i>=n) next[i][j]=-1; else next[i][j]=(a[i]==j?i:next[i+1][j]);
}
int main()
{
#ifdef _MSC_VER
    FILE *stream;
    freopen_s(&stream,"input.txt","r",stdin);
#endif
    std::ios_base::sync_with_stdio(false);
    cin>>n>>m>>sa>>sb;
    REP(i,n) a[i]=sa[i]-'a';
    REP(i,n) b[i]=sb[i]-'a';
    prepare(a,next_a);
    prepare(b,next_b);
    for (int i=n;i>=0;i--) for (int j=n;j>=0;j--)
    {               
        if (i==n || j==n) { f[i][j]=0; g[i][j]=1; continue; }
        int w=0,c=1;
        REP(k,26)
        {
            int pa=next_a[i][k];
            if (pa<0) continue;
            int pb=next_b[j][k];
            if (pb<0) continue;
            int x=f[pa+1][pb+1]+1;
            if (x<w) continue;
            if (x>w) { w=x; c=g[pa+1][pb+1]; }
            else { c+=g[pa+1][pb+1]; if (c>m) c=m+1; }
        }
        f[i][j]=w;
        g[i][j]=c;
    }
    int pa=0,pb=0;
    int L=0;
    char ret[maxn];
    while (f[pa][pb]>0)
    {
        bool ok=false;
        REP(k,26)
        {
            int xa=next_a[pa][k];
            if (xa<0) continue;
            int xb=next_b[pb][k];
            if (xb<0) continue;
            int x=f[xa+1][xb+1]+1;
            if (x!=f[pa][pb]) continue;
            int y=g[xa+1][xb+1];
            if (y>=m) { ret[L++]='a'+k; pa=xa+1; pb=xb+1; ok=true; break; }
            m-=y;
        }
        if (!ok) { L=-1; break; }
    }
    if (L<0)
        printf("-1\n");
    else
    {
        ret[L]=0;
        printf("%s\n",ret);
    }
    return 0;
} 


