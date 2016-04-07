#include <stdio.h>
#include <map>
#define MAXVAL 10000050

using std::map;

const int inf=1000000000;

int ways;
int cm[2][MAXVAL+1];

int cmap[MAXVAL+1]={0};

inline void pre() {
   cmap[1]=1;
   for(int i=0;i<=MAXVAL;i++) {
      int ii=i&1;
      int pi=!ii;
      cm[ii][0]=cm[ii][i]=1;
      for(int j=1;j<i;j++) {
         cm[ii][j]=cm[pi][j]+cm[pi][j-1];
         if(cm[ii][j]>MAXVAL) {
            cm[ii][j]=MAXVAL+1;
            break;
         }
         if(!cmap[cm[ii][j]]) cmap[cm[ii][j]]=i;
      }
   }
}

inline int solve() {
   int opt=inf;
   for(int i=1;i*i<=ways;i++) {
      if(ways%i) continue;
      int j=ways/i;
      int d=cmap[i]+cmap[j];
      if(d<opt) opt=d;
   }
   return opt;
}

int main(void)
{
   int t,cas=1;
   pre();
   scanf("%d",&t);
   while(t--) {
      scanf("%d",&ways);
      printf("Case #%d: %d\n",cas++,solve());
   }
   return 0;
}
