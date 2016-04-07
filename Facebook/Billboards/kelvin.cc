#include <stdio.h>
#include <string.h>
#include <vector>
#define MAXL 2050

using namespace std;

int w,h,maxl;
vector<int> text;
char in[MAXL],voc[MAXL];

inline int min(int a,int b) { return a<b?a:b; }
inline int max(int a,int b) { return a>b?a:b; }

inline bool valid(int sz) {
   int rn=h/sz,cn=w/sz;
   int r=0,c=0;
   for(int i=0;i<text.size();i++) {
      if(text[i]>cn) return 0;
      if(c+(c?1:0)+text[i]<=cn) {
         c+=(c?1:0)+text[i];
      } else {
         r++;
         c=0;
         i--;
         continue;
      }
   }
   return r<rn;
}

inline int solve() {
   int l=0,r=h+1;
   while(l<r-1) {
      int m=(l+r)/2;
      if(valid(m)) l=m;
      else r=m;
   }
   return l;
}

int main(void)
{
   int t,casenum=1;
   scanf("%d",&t);
   while(t--) {
      scanf("%d %d",&w,&h);
      text.clear();
      gets(in);
      char *pt=strtok(in," ");
      while(pt) {
         sscanf(pt,"%s",voc);
         pt=strtok(NULL," ");
         text.push_back(strlen(voc));
      }
      printf("Case #%d: %d\n",casenum++,solve());
   }
   return 0;
}
