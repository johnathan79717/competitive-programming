#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>

using namespace std;
#define MAX_N 100000

vector<int> adj[MAX_N];
int parent[MAX_N], heavy[MAX_N], depth[MAX_N], size[MAX_N], chain[MAX_N], head[MAX_N];
int color[MAX_N]; // 0 -> BLACK, 1 -> WHITE
vector<vector<int> > num[2], child[2];

int q[MAX_N], *qf, *qb; // BFS queue
 
void heavylight_BFS(int N)
{
    qf = qb = q;
    parent[0] = -1;
    depth[0] = 0;
    *qb++ = 0;
    while (qf < qb)
        for (int i=*qf++, k=0; k<adj[i].size(); ++k)
        {
            int j = adj[i][k];
            if (j == parent[i]) continue;
            parent[j] = i;
            depth[j] = depth[i] + 1;
            *qb++ = j;
        }
 
    memset(size, 0, sizeof(size));
    memset(heavy, -1, sizeof(heavy));
    for (int k=N-1; k>0; --k)   
    {
        int j = q[k], i = parent[q[k]];
        size[j]++;
        size[i] += size[j];
        if (heavy[i] == -1 || size[j] > size[heavy[i]])
            heavy[i] = j;
    }
    size[0]++;
 
    int c = 0;
    for (int i=0; i<N; ++i)
        if (parent[i] == -1 || heavy[parent[i]] != i)
        {
            for (int k = i; k != -1; k = heavy[k])
                chain[k] = c, head[k] = i;
            c++;
        }
}

int sum(vector<int> &bit, int i) {
  int s = 0;
  while(i > 0) {
    s += bit[i];
    i &= i - 1;
  }
  return s;
}

int sum(vector<int> &bit, int i, int j) {
  return sum(bit, j) - sum(bit, i - 1);
}

void add(vector<int> &bit, int i, int x) {
  int n = bit.size() - 1;
  while(i <= n) {
    bit[i] += x;
    i += i & -i;
  }
}

int query(int u) {
  int cn = chain[u], l = depth[u] - depth[head[u]] + 1, cr = color[u];
  if(sum(num[1-cr][cn], l) == 0 && head[u] != 0 && color[parent[head[u]]] == cr)
    return query(parent[head[u]]);
  int lb = 0, ub = l;
  while(ub - lb > 1) {
    int mid = lb + (ub - lb) / 2;
    if(sum(num[1-cr][cn], mid, l) == 0)
      ub = mid;
    else
      lb = mid;
  }
  int high = ub;
  lb = l, ub = num[0][cn].size();
  while(ub - lb > 1) {
    int mid = lb + (ub - lb) / 2;
    if(sum(num[1-cr][cn], l, mid) == 0)
      lb = mid;
    else
      ub = mid;
  }
  int low = lb;
  return low - high + 1 + sum(child[cr][cn], high, low);
}

void update(int u, int change) {
  int cr = color[u], cn = chain[u], l = depth[u] - depth[head[u]] + 1;
  // if more than one color on this chain
  if(sum(num[1-cr][cn], l) > 0 || head[u] == 0)
    return;
  int p = parent[head[u]];
  add(child[cr][chain[p]], depth[p] - depth[head[p]] + 1, change);
  if(cr == color[p])
    update(p, change);
}

void toggle(int u) {
  int &cr = color[u], cn = chain[u], l = depth[u] - depth[head[u]] + 1;
  add(num[cr][cn], l, -1);
  cr ^= 1;
  add(num[cr][cn], l, 1);
  int change[2] = { 1 + sum(child[0][cn], l, l), 1 + sum(child[1][cn], l, l) };
  if(heavy[u] >= 0) {
    int c = color[heavy[u]];
    int lb = l + 1, ub = child[0][cn].size();
    while(ub - lb > 1) {
      int mid = lb + (ub - lb) / 2;
      if(sum(num[1-c][cn], l+1, mid) == 0)
        lb = mid;
      else
        ub = mid;
    }
    change[c] += lb - l + sum(child[c][cn], l + 1, lb);
  }
  change[1-cr] *= -1;
  if((sum(num[0][cn], l - 1) > 0 && sum(num[1][cn], l - 1) > 0) || head[u] == 0)
    return;
  int p = parent[head[u]], c = color[head[u]];
  add(child[c][chain[p]], depth[p] - depth[head[p]] + 1, change[c]);
  if(u == head[u]) {
    add(child[1-c][chain[p]], depth[p] - depth[head[p]] + 1, change[1-c]);
    update(p, change[color[p]]);
  } else if(c == color[p])
    update(p, change[c]);
}

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 1; i < n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    --u; --v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  heavylight_BFS(n);

  for(int i = 0; i < n; i++)
    if(heavy[i] < 0) {
      int l = depth[i] - depth[head[i]] + 1;
      int c = chain[i];
      if(c >= num[0].size()) {
        num[0].resize(c + 1);
        num[1].resize(c + 1);
        child[0].resize(c + 1);
        child[1].resize(c + 1);
      }
      num[0][c].resize(l + 1);
      num[1][c].resize(l + 1);
      child[0][c].resize(l + 1);
      child[1][c].resize(l + 1);
      int h = head[i];
      for(int k = 1; k <= l; k++) {
        add(num[0][c], k, 1);
        add(child[0][c], k, size[h] - 1 - (heavy[h] < 0 ? 0 : size[heavy[h]]));
        h = heavy[h];
      }
    }
  int m;
  scanf("%d", &m);
  while(m--) {
    int t, u;
    scanf("%d%d", &t, &u);
    --u;
    if(t == 0)
      printf("%d\n", query(u));
    else
      toggle(u);
  }
}