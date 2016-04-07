#include <stdio.h>
#include <string.h>
#define MAXL 2000

int occ[200];
char in[MAXL];

inline int min(int a,int b) { return a<b?a:b; }

inline int solve() {
   //ACCEHKPRU
   return min(occ['A'],
          min(occ['C']/2,
          min(occ['E'],
          min(occ['H'],
          min(occ['K'],
          min(occ['P'],
          min(occ['R'],
              occ['U'])))))));
}

int main(void)
{
   int t,casenum=1;
   scanf("%d",&t);
   gets(in);
   while(t--) {
      gets(in);
      memset(occ,0,sizeof(occ));
      for(int i=0;in[i];i++)
         occ[in[i]]++;
      printf("Case #%d: %d\n",casenum++,solve());
   }
   return 0;
}
