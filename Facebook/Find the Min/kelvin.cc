#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>
#define MAXK 105000

using namespace std;

int n,k;
int m0,c1,c0,mod;
int m[MAXK*2];
int occ[MAXK];

int solve() {
   m[0]=m0;
   for(int i=1;i<k;i++)
      m[i]=(c1*(long long)m[i-1]+c0)%mod;
   for(int i=0;i<=k;i++)
      occ[i]=0;
   for(int i=0;i<k;i++)
      if(m[i]<=k) occ[m[i]]++;
   priority_queue<int,vector<int>,greater<int> > pq;
   for(int i=0;i<=k;i++)
      if(!occ[i]) pq.push(i);
   for(int i=k;i<=2*k;i++) {
      int x;
      x=pq.top();
      pq.pop();
      occ[x]++;
      m[i]=x;
      if(m[i-k]<=k) {
         occ[m[i-k]]--;
         if(!occ[m[i-k]]) pq.push(m[i-k]);
      }
   }
   /*for(int i=0;i<=2*k;i++)
      printf("%d ",m[i]); puts("");*/
   return m[k+(n-k-1)%(k+1)];
}

int main(void)
{
   int t,cas=1;
   scanf("%d",&t);
   while(t--) {
      scanf("%d %d",&n,&k);
      scanf("%d %d %d %d",&m0,&c1,&c0,&mod);
      printf("Case #%d: %d\n",cas++,solve());
   }
   return 0;
}
