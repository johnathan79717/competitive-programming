#include <stdio.h>
#define MAXN 20000
#define MAXL 10000000

int n,dptr;
int s[MAXN],orig[MAXN];
char debug[MAXL];
int tmp[MAXN];

inline int hash() {
   int ret=1;
   for(int i=0;i<n;i++)
      ret=(31*ret+orig[i])%1000003;
   return ret;
}

inline void merge(int *l,int ln,int *r,int rn,int *t) {
   int tn=0;
   int li=0,ri=0;
   while(li<ln&&ri<rn) {
      if(debug[dptr++]=='1') t[tn++]=l[li++];
      else t[tn++]=r[ri++];
   }
   while(li<ln) t[tn++]=l[li++];
   while(ri<rn) t[tn++]=r[ri++];
}

inline void merge_sort(int *s,int n) {
   if(n==1) return;
   int m=n/2;
   int *l=s,*r=s+m;
   int ln=m,rn=n-m;
   merge_sort(l,ln);
   merge_sort(r,rn);
   merge(l,ln,r,rn,tmp);
   for(int i=0;i<n;i++)
      s[i]=tmp[i];
}

inline void solve() {
   dptr=0;
   for(int i=0;i<n;i++)
      s[i]=i;
   merge_sort(s,n);
   for(int i=0;i<n;i++)
      orig[s[i]]=i+1;
}

int main(void)
{
   int t,cas=1;
   scanf("%d",&t);
   while(t--) {
      scanf("%d",&n);
      scanf("%s",debug);
      solve();
      printf("Case #%d: %d\n",cas++,hash());
   }
   return 0;
}
