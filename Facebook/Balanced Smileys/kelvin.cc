#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>
#define MAXL 105000

using namespace std;

int len;
char s[MAXL];


bool solve() {
   len=strlen(s);
   int mi=0,ma=0;
   for(int i=0;i<len;i++) {
      if(s[i]=='(') {
         mi++;
         ma++;
      } else if(s[i]==')') {
         mi--;
         ma--;
         mi=max(mi,0);
         if(mi>ma) return 0;
      } else if(s[i]==':') {
         if(i+1<len&&(s[i+1]=='('||s[i+1]==')')) {
            if(s[i+1]=='(') {
               ma++;
            } else {
               mi--;
               mi=max(mi,0);
            }
            i++;
         }
      }
   }
   if(mi>0) return 0;
   return 1;
}

int main(void)
{
   int t,cas=1;
   gets(s);
   t=atoi(s);
   while(t--) {
      gets(s);
      printf("Case #%d: %s\n",cas++,solve()?"YES":"NO");
   }
   return 0;
}
