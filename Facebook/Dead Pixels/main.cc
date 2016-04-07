#include <iostream>

using namespace std;

#define MAX_L 40005

int W, H, P, Q, N, X, Y, a, b, c, d;
int p[MAX_L][MAX_L];

int solve() {
  for(int i = 0; i < W; i++)
    for(int j = 0; j < H; j++)
      p[i][j] = 1;

  int x = X, y = Y;
  for(int i = 0; i < N; i++) {
    // cout << x << ' ' << y << endl;
    p[x][y] = 0;
    int temp = (x * a + y * b + 1) % W;
    y = (x * c + y * d + 1) % H;
    x = temp;
  }

  for(int i = 1; i < W; i++)
    for(int j = 1; j < H; j++)
      if(p[i][j])
        p[i][j] = min(p[i-1][j-1], min(p[i][j-1], p[i-1][j])) + 1;

  // puts("");
  // for(int i = 0; i < W; i++) {
  //   for(int j = 0; j < H; j++)
  //     printf("%2d ", p[i][j]);
  //   puts("");
  // }

  int ans = 0;
  if(P < Q) {
    for(int i = 0; i < W; i++)
      for(int j = 1; j < H; j++)
        if(p[i][j] >= P && p[i][j-1] >= P) {
          p[i][j] = p[i][j-1] + 1;
          if(p[i][j] >= Q)
            ans++;
        }
  } else if(P > Q) {
    for(int i = 1; i < W; i++)
      for(int j = 0; j < H; j++)
        if(p[i][j] >= Q && p[i-1][j] >= Q) {
          p[i][j] = p[i-1][j] + 1;
          if(p[i][j] >= P)
            ans++;
        }
  } else {
    for(int i = P-1; i < W; i++)
      for(int j = Q-1; j < H; j++)
        if(p[i][j] >= P)
          ans++;
  }

  // puts("");
  // for(int i = 0; i < W; i++) {
  //   for(int j = 0; j < H; j++)
  //     printf("%2d ", p[i][j]);
  //   puts("");
  // }


  return ans;
}

int main() {
  int T, cas = 1;
  cin >> T;
  while(T--) {
    cin >> W >> H >> P >> Q >> N >> X >> Y >> a >> b >> c >> d;
    cout << "Case #" << cas++ << ": " << solve() << endl;
  }
}