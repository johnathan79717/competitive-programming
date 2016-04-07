#include <cstdio>
#include <algorithm>
#include <vector>
#define MAXN 10005

using namespace std;

const int mod=1000000007;

int n,k;
int s[MAXN];
int cm[MAXN][MAXN];

inline int modit(int x) {
   if(x<0) x+=mod;
   if(x>=mod) x-=mod;
   return x;
}

void pre() {
   for(int i=0;i<MAXN;i++) {
      cm[i][0]=cm[i][i]=1;
      for(int j=1;j<i;j++)
         cm[i][j]=modit(cm[i-1][j-1]+cm[i-1][j]);
   }
}

int solve() {
   sort(s,s+n);
   int sol=0;
   for(int i=k-1;i<n;i++)
      sol=(sol+(long long)s[i]*cm[i][k-1])%mod;
   return sol;
}

int main(void) {
   int t,cas=1;
   pre();
   scanf("%d",&t);
   while(t--) {
      scanf("%d %d",&n,&k);
      for(int i=0;i<n;i++)
         scanf("%d",s+i);
      printf("Case #%d: %d\n",cas++,solve());
   }
   return 0;
}
