#include <iostream>

using namespace std;

char b[18][18];
bool t[18][18];
int di[] = {1, 0, -1, 0, 1, -1, 1, -1, 2, 1, -1, -2, -2, -1, 1, 2};
int dj[] = {0, 1, 0, -1, 1, 1, -1, -1, 1, 2, 2, 1, -1, -2, -2, -1};

bool in(int i, int j) {
  return 1 <= i && i <= 16 && 1 <= j && j <= 16;
}

int main() {
  int N;
  cin >> N;
  while(N--) {
    int P;
    cin >> P;
    memset(b, 0, sizeof(b));
    memset(t, false, sizeof(t));
    while(P--) {
      char C;
      int R, F;
      cin >> C >> R >> F;
      b[R][F] = C;
    }
    for(int i = 1; i <= 16; i++)
      for(int j = 1; j <= 16; j++)
        switch(b[i][j]) {
          case 'K':
            for(int k = 0; k < 8; k++)
              t[i+di[k]][j+dj[k]] = true;
            break;
          case 'Q':
            for(int k = 0; k < 8; k++)
              for(int l = 1; in(i+l*di[k], j+l*dj[k]); l++)
                if(b[i+l*di[k]][j+l*dj[k]]) {
                  t[i+l*di[k]][j+l*dj[k]] = true;
                  break;
                }
            break;
          case 'R':
            for(int k = 0; k < 4; k++)
              for(int l = 1; in(i+l*di[k], j+l*dj[k]); l++)
                if(b[i+l*di[k]][j+l*dj[k]]) {
                  t[i+l*di[k]][j+l*dj[k]] = true;
                  break;
                }
            break;
          case 'B':
            for(int k = 4; k < 8; k++)
              for(int l = 1; in(i+l*di[k], j+l*dj[k]); l++)
                if(b[i+l*di[k]][j+l*dj[k]]) {
                  t[i+l*di[k]][j+l*dj[k]] = true;
                  break;
                }
            break;
          case 'N':
            for(int k = 8; k < 16; k++)
              if(in(i+di[k], j+dj[k]))
                t[i+di[k]][j+dj[k]] = true;
            break;
          case 'S':
            for(int k = 8; k < 16; k++)
              for(int l = 1; in(i+l*di[k], j+l*dj[k]); l++)
                if(b[i+l*di[k]][j+l*dj[k]]) {
                  t[i+l*di[k]][j+l*dj[k]] = true;
                  break;
                }
            break;
          case 'A':
            for(int k = 4; k < 8; k++)
              for(int l = 1; in(i+l*di[k], j+l*dj[k]); l++)
                if(b[i+l*di[k]][j+l*dj[k]]) {
                  t[i+l*di[k]][j+l*dj[k]] = true;
                  break;
                }
            for(int k = 8; k < 16; k++)
              if(in(i+di[k], j+dj[k]))
                t[i+di[k]][j+dj[k]] = true;
            break;
          case 'E':
            for(int ii = 1; ii <= 16; ii++)
              for(int jj = 1; jj <= 16; jj++)
                if(ii != i || jj != j)
                  t[ii][jj] = true;
            break;
          default: break;
        }
    int ans = 0;
    for(int i = 1; i <= 16; i++)
      for(int j = 1; j <= 16; j++)
        if(b[i][j] && t[i][j])
          ans++;
    cout << ans << endl;
  }
}