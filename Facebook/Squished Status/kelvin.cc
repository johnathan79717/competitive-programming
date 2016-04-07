#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#define MAXL 1055

using std::cout;
using std::endl;

const long long mod=4207849484ll;

int m,len;
char s[MAXL];
long long dp[MAXL];

inline long long add(long long a,long long b) {
   return a+b<mod?a+b:a+b-mod;
}

inline bool valid(int x) {
   return 1<=x && x<=m;
}

inline long long solve() {
   memset(dp,0,sizeof(dp));
   dp[0]=1;
   len=strlen(s);
   for(int i=0;i<len;i++) {
      if(s[i]=='0') continue;
      int val=0;
      for(int j=0;j<=2&&i+j<len;j++) {
         val=val*10+s[i+j]-'0';
         if(valid(val)) dp[i+j+1]=add(dp[i+j+1],dp[i]);
      }
   }
   return dp[len];
}

int main(void)
{
   int t,cas=1;
   scanf("%d",&t);
   while(t--) {
      scanf("%d %s",&m,s);
      cout << "Case #" << cas++ << ": " << solve() << endl;
   }
   return 0;
}
