#include <cstdio>
#include <algorithm>
using namespace std;

int N;
int p[2010][4];
bool vs[2010];

bool cover(int xs, int xe, int ys, int ye, int zs, int ze){
  int e = xe - xs;

  for(int i = 1; i <= N; i++){
    if(
        p[i][0] - p[i][3] >= xs
        && p[i][0] + p[i][3] <= xe
        && p[i][1] - p[i][3] >= ys
        && p[i][1] + p[i][3] <= ye
        && p[i][2] - p[i][3] >= zs
        && p[i][2] + p[i][3] <= ze
      ) vs[i] = true;
    else vs[i] = false;
  }

  int minx = 300000000, maxx = -300000000;
  int miny = 300000000, maxy = -300000000;
  int minz = 300000000, maxz = -300000000;

  for(int i = 1; i <= N; i++){
    if(!vs[i]){
      minx = min(minx, p[i][0] - p[i][3]);
      maxx = max(maxx, p[i][0] + p[i][3]);
      miny = min(miny, p[i][1] - p[i][3]);
      maxy = max(maxy, p[i][1] + p[i][3]);
      minz = min(minz, p[i][2] - p[i][3]);
      maxz = max(maxz, p[i][2] + p[i][3]);
    }
  }

  if(maxx - minx <= e && maxy - miny <= e && maxz - minz <= e) return true;
  return false;
}

int main(){
  int T; scanf("%d", &T);
  for(int tt = 1; tt <= T; tt++){
    scanf("%d", &N);
    for(int i = 1; i <= N; i++){
      for(int j = 0; j < 4; j++) scanf("%d", &p[i][j]);
    }

    int minx = 300000000, maxx = -300000000;
    int miny = 300000000, maxy = -300000000;
    int minz = 300000000, maxz = -300000000;

    for(int i = 1; i <= N; i++){
      minx = min(minx, p[i][0] - p[i][3]);
      maxx = max(maxx, p[i][0] + p[i][3]);
      miny = min(miny, p[i][1] - p[i][3]);
      maxy = max(maxy, p[i][1] + p[i][3]);
      minz = min(minz, p[i][2] - p[i][3]);
      maxz = max(maxz, p[i][2] + p[i][3]);
    }

    int rs = 0, re = 500000000;

    while(rs < re){
      int r = (rs + re) / 2;

      if(
          cover(minx, minx + r, miny, miny + r, minz, minz + r)
          || cover(minx, minx + r, miny, miny + r, maxz - r, maxz)
          || cover(minx, minx + r, maxy - r, maxy, minz, minz + r)
          || cover(minx, minx + r, maxy - r, maxy, maxz - r, maxz)
          || cover(maxx - r, maxx, miny, miny + r, minz, minz + r)
          || cover(maxx - r, maxx, miny, miny + r, maxz - r, maxz)
          || cover(maxx - r, maxx, maxy - r, maxy, minz, minz + r)
          || cover(maxx - r, maxx, maxy - r, maxy, maxz - r, maxz)
        ) re = r;
      else rs = r + 1;
    }

    printf("Case #%d: %d\n", tt, rs);
  }
  return 0;
}
