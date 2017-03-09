#include <cstdio>
#include <cstring>
#include <queue>
#include <utility>
using namespace std;

char s1[2010], s2[2010];
bool vs[2010][2010];

queue<pair<int, int> > q;

void enqueue(int x1, int x2){
  if(!vs[x1][x2]){ q.push({x1, x2}); vs[x1][x2] = true; }
}

int main(){
  int T; scanf("%d", &T);
  for(int tt = 1; tt <= T; tt++){
    scanf("%s%s", s1 + 1, s2 + 1);
    int l1 = strlen(s1 + 1), l2 = strlen(s2 + 1);

    for(int i = 0; i <= l1; i++){
      for(int j = 0; j <= l2; j++) vs[i][j] = false;
    }
    while(!q.empty()) q.pop();

    enqueue(0, 0);

    while(!q.empty()){
      int x1 = q.front().first, x2 = q.front().second;
      q.pop();

      if(x1 < l1){ // match with s1[x1 + 1]
        if(s1[x1 + 1] == '*'){
          enqueue(x1 + 1, x2);
          for(int x2_ = x2 + 1, c = 0; x2_ <= l2; x2_++){
            if(s2[x2_] == '*') enqueue(x1 + 1, x2_);
            else{
              if(c == 4) break;
              else{ enqueue(x1 + 1, x2_); c++; }
            }
          }
        }
        else{
          for(int x2_ = x2 + 1; x2_ <= l2; x2_++){
            if(s2[x2_] == '*') enqueue(x1 + 1, x2_);
            else{
              if(s2[x2_] == s1[x1 + 1]) enqueue(x1 + 1, x2_);
              break;
            }
          }
        }
      }
      if(x2 < l2){ // match with s2[x2 + 1]
        if(s2[x2 + 1] == '*'){
          enqueue(x1, x2 + 1);
          for(int x1_ = x1 + 1, c = 0; x1_ <= l1; x1_++){
            if(s1[x1_] == '*') enqueue(x1_, x2 + 1);
            else{
              if(c == 4) break;
              else{ enqueue(x1_, x2 + 1); c++; }
            }
          }
        }
        else{
          for(int x1_ = x1 + 1; x1_ <= l1; x1_++){
            if(s1[x1_] == '*') enqueue(x1_, x2 + 1);
            else{
              if(s1[x1_] == s2[x2 + 1]) enqueue(x1_, x2 + 1);
              break;
            }
          }
        }
      }
    }

    printf("Case #%d: %s\n", tt, (vs[l1][l2] ? "TRUE" : "FALSE"));
  }
  return 0;
}
