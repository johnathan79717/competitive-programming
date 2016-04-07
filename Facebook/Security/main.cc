#include <iostream>
#include <vector>
using namespace std;

#define MAX_V 100

int m, l;
string k1, k2, impossible("IMPOSSIBLE");

int V; // number of vertices
vector<int> G[MAX_V]; // adjacency list
int match[MAX_V]; // matched pairs
bool used[MAX_V]; // has been visited by dfs

void add_edge(int u, int v) {
  G[u].push_back(v);
  G[v].push_back(u);
}

bool dfs(int v) {
  used[v] = true;
  for(int i = 0; i < G[v].size(); i++) {
    int u = G[v][i], w = match[u];
    if(w < 0 || (!used[w] && dfs(w))) {
      match[v] = u;
      match[u] = v;
      return true;
    }
  }
  return false;
}

int bipartite_matching() {
  int res = 0;
  memset(match, -1, sizeof(match));
  for(int v = 0; v < V; v++) {
    if(match[v] < 0) {
      memset(used, 0, sizeof(used));
      if(dfs(v)) {
        res++;
      }
    }
  }
  return res;
}

bool adj(int p1, int p2) {
  for(int i = 0; i < l; i++)
    if(k1[p1*l+i] != '?' && k2[p2*l+i] != '?' && k1[p1*l+i] != k2[p2*l+i])
      return false;
  return true;
}

bool possible() {
  for(int v = 0; v < V; v++)
    G[v].clear();
  for(int i = 0; i < m; i++)
    for(int j = 0; j < m; j++)
      if(adj(i, j))
        add_edge(i, j + m);
  return bipartite_matching() == m;
}

string& solve() {
  V = m * 2;
  if(!possible())
    return impossible;
  for(char &c : k1) {
    if(c != '?') continue;
    for(c = 'a'; c <= 'f'; c++)
      if(possible())
        break;
  }
  return k1;
}

int main() {
  int T, cas = 1;
  cin >> T;
  while(T--) {
    cin >> m >> k1 >> k2;
    l = k1.size() / m;
    cout << "Case #" << cas++ << ": " << solve() << endl;
  }
}