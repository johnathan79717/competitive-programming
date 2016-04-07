#include <bits/stdc++.h>
using namespace std;

const int
  MAXV = 250005;

int V;
int p[MAXV];
set< int > S;
int L[MAXV];
int R[MAXV];
int P[MAXV];

bool seen[MAXV];
vector< int > childs;
int depth[MAXV];
int size[MAXV];
vector< int > G[MAXV];
long long ans;
int root;

void computeSizes(int u)
{
  seen[u] = 1;
  size[u] = 1;

  for (int v : G[u]) if (!seen[v])
  {
    computeSizes(v);
    size[u] += size[v];
  }

  seen[u] = 0;
}

void dfs(int u)
{
  seen[u] = 1;
  childs.push_back(u);

  for (int v : G[u]) if (!seen[v])
  {
    depth[v] = depth[u] + 1;
    dfs(v);
  }

  seen[u] = 0;
}

int findCenter(int u)
{
  bool isCenter = ((size[root] - size[u]) * 2 <= size[root]);

  for (int v : G[u]) if (!seen[v])
    isCenter &= (size[v] * 2 <= size[root]);

  if (isCenter)
    return u;

  seen[u] = 1;
  
  for (int v : G[u]) if (!seen[v])
  {
    int c = findCenter(v);
    if (c != -1)
    {
      seen[u] = 0;
      return c;
    }
  }

  seen[u] = 0;
  
  return -1;
}

void solve(int u)
{
  computeSizes(u);
  
  if (size[u] == 1)
    return ;

  root = u;
  u = findCenter(u);

  //cout << "center " << (u + 1) << endl;

  long long nodeCount = 1; // u
  long long distancesSum = 0;

  seen[u] = 1;

  for (int v : G[u]) if (!seen[v])
  {
    childs.clear();
    depth[v] = 1;
    dfs(v);

    for (int c : childs)
    {
      ans += nodeCount * depth[c] + distancesSum;
    }

    for (int c : childs)
    {
      distancesSum += depth[c];
      nodeCount++;
    }
  }

  for (int v : G[u]) if (!seen[v])
    solve(v);

  seen[u] = 0;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> V;
  memset(L, -1, sizeof(L));
  memset(R, -1, sizeof(R));
  
  for (int i = 0; i < V; ++i)
  {
    cin >> p[i];
    --p[i];
      
    auto lb = S.lower_bound(p[i]);
    if (lb != S.end())
    {
      if (L[*lb] < 0) {
        L[*lb] = p[i];
        //cout << (*lb + 1) << " " << (p[i] + 1) << endl;
        G[*lb].push_back(p[i]);
        G[p[i]].push_back(*lb);
      }
    }
      
    if (lb != S.begin()) {
      --lb;
      if (R[*lb] < 0) {
        R[*lb] = p[i];
        G[*lb].push_back(p[i]);
        G[p[i]].push_back(*lb);
        //cout << (*lb + 1) << " " << (p[i] + 1) << endl;
      } 
    }

    ans = 0;
    solve(p[0]);

    cout << ans << endl;


    S.insert(p[i]);
  }
  
  
  return 0;
}