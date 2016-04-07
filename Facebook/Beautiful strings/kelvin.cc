#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>
#define MAXL 105000

using namespace std;

char s[MAXL];
int occ[26];

int solve() {
   memset(occ,0,sizeof(occ));
   for(int i=0;s[i];i++) {
      if(s[i]>='a'&&s[i]<='z') occ[s[i]-'a']++;
      else if(s[i]>='A'&&s[i]<='Z') occ[s[i]-'A']++;
   }
   sort(occ,occ+26);
   int r=0;
   for(int i=0;i<26;i++)
      r+=occ[i]*(i+1);
   return r;
}

int main(void)
{
   int t,cas=1;
   gets(s);
   t=atoi(s);
   while(t--) {
      gets(s);
      printf("Case #%d: %d\n",cas++,solve());
   }
   return 0;
}
