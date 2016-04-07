#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Square {
  int r;
  int c;
  Square() {}
  Square(int r, int c) : r(r), c(c) {}
};

int R, C;
char s[101][101];
vector<Square> color[9];
int d[101][101];
int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};
queue<Square> q;

void visit(int r, int c, int dd) {
  if(0 <= r && r < R && 0 <= c && c < C && d[r][c] < 0 && s[r][c] != 'W') {
    d[r][c] = dd;
    q.push(Square(r, c));
  }
}

int solve() {
  Square start, end;
  fill(color, color + 9, vector<Square>());
  for(int i = 0; i < R; i++) {
    for(int j = 0; j < C; j++) {
      d[i][j] = -1;
      if('1' <= s[i][j] && s[i][j] <= '9')
        color[s[i][j] - '1'].push_back(Square(i, j));
      else if(s[i][j] == 'S')
        start = Square(i, j);
      else if(s[i][j] == 'E')
        end = Square(i, j);
    }
  }
  d[start.r][start.c] = 0;
  q.push(start);
  while(!q.empty()) {
    int r = q.front().r, c = q.front().c;
    q.pop();
    for(int i = 0; i < 4; i++)
      visit(r+dr[i], c+dc[i], d[r][c] + 1);
    if('1' <= s[r][c] && s[r][c] <= '9') {
      vector<Square> &v = color[s[r][c] - '1'];
      for(int i = 0; i < v.size(); i++)
        visit(v[i].r, v[i].c, d[r][c] + 1);
    }
  }
  // cout << endl;
  // for(int i = 0; i < R; i++) {
  //   for(int j = 0; j < C; j++)
  //     printf("%3d", d[i][j]);
  //   cout << endl;
  // }
  return d[end.r][end.c];
}

int main() {
  int N, cas = 1;
  cin >> N;
  while(N--) {
    cin >> R >> C;
    for(int i = 0; i < R; i++)
      cin >> s[i];
    cout << solve() << endl;
  }
}