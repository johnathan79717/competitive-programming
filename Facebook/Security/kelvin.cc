#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <vector>
#define MAXN 55
#define MAXL 105
#define MAXV 150

using namespace std;

const int mod=1000000007;

int nseg,len;
char in[MAXL];
char s1[MAXN][MAXL];
char s2[MAXN][MAXL];

int vn,src,sink;
int res[MAXV][MAXV];
int vis[MAXV],visid=0;

bool match(char *s1,char *s2) {
   for(int i=0;i<len;i++)
      if(s1[i]!='?'&&s2[i]!='?'&&s1[i]!=s2[i]) return 0;
   return 1;
}

inline int v1(int x) { return x+1; }
inline int v2(int x) { return x+nseg+1; }

void construct() {
   src=0;
   sink=nseg*2+1;
   vn=sink+1;
   for(int i=0;i<vn;i++)
      for(int j=0;j<vn;j++)
         res[i][j]=0;
   for(int i=0;i<nseg;i++)
      res[src][v1(i)]=1;
   for(int i=0;i<nseg;i++)
      res[v2(i)][sink]=1;
   for(int i=0;i<nseg;i++) {
      for(int j=0;j<nseg;j++) {
         if(match(s1[i],s2[j])) res[v1(i)][v2(j)]=1;
      }
   }
}

bool dfs(int v) {
   vis[v]=visid;
   if(v==sink) return 1;
   for(int u=0;u<vn;u++) {
   //for(int i=0;i<adj[v].size();i++) {
      //int u=adj[v][i];
      if(vis[u]==visid) continue;
      if(!res[v][u]) continue;
      if(dfs(u)) {
         res[v][u]--;
         res[u][v]++;
         return 1;
      }
   }
   return 0;
}

bool match() {
   construct();
   int f=0;
   while(1) {
      ++visid;
      if(dfs(src)) f++;
      else break;
   }
   return f==nseg;
}

bool solve() {
   if(!match()) return 0;
   for(int i=0;i<nseg;i++) {
      for(int j=0;j<len;j++) {
         if(s1[i][j]!='?') continue;
         bool flag=0;
         for(char c='a';c<='f';c++) {
            s1[i][j]=c;
            if(match()) {
               flag=1;
               break;
            }
         }
         assert(flag);
      }
   }
   for(int i=0;i<nseg;i++)
      for(int j=0;j<len;j++)
         printf("%c",s1[i][j]); puts("");
   return 1;
}

int main(void) {
   int t,cas=1;
   scanf("%d",&t);
   while(t--) {
      scanf("%d",&nseg);
      scanf("%s",in);
      len=strlen(in)/nseg;
      for(int i=0;i<nseg;i++)
         for(int j=0;j<len;j++)
            s1[i][j]=in[i*len+j];
      scanf("%s",in);
      for(int i=0;i<nseg;i++)
         for(int j=0;j<len;j++)
            s2[i][j]=in[i*len+j];
      printf("Case #%d: ",cas++);
      if(!solve()) puts("IMPOSSIBLE");
   }
   return 0;
}
