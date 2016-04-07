#include <string>
#include <algorithm>
#include <climits>
#include <vector>
using namespace std;
#define ALL(x) (x).begin(),(x).end()
 
class FoxConnection {
public:
  vector<int> G[50];
  string haveFox;

  pair<int, vector<int> >dfs(int root, int from=-1) {
    int cost = 0; vector<int> path;
    for(int u : G[root]) {
      if(u == from) continue;
      pair<int, vector<int> > p = dfs(u, root);
      if(p.second.empty()) continue;
      cost += p.first;
      path.insert(path.end(), ALL(p.second));
    }
    if(!path.empty()) {
      for(int &p : path) p++;
      sort(ALL(path));
      if(haveFox[root] == 'N') {
        cost += (--path[0]);
        if(path[0] == 0) path.erase(path.begin());
      }
    } else if(haveFox[root] == 'Y')
      path.push_back(1);
    return make_pair(cost, path);
  }

  
  int minimalDistance(vector <int> A, vector <int> B, string haveFox) {
    int N = A.size() + 1;
    this->haveFox = haveFox;
    for(auto v : G) v.clear();
    for(int i = 0; i < A.size(); i++) {
      A[i]--; B[i]--;
      G[A[i]].push_back(B[i]);
      G[B[i]].push_back(A[i]);
    }
    int ans = INT_MAX;
    for(int root = 0; root < N; root++) {
      ans = min(ans, dfs(root).first);
    }
    return ans;
  }
};
