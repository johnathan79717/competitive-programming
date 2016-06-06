#include <iostream>
#include <queue>
#include <stack>
using namespace std;

struct Match {
  int number;
  int l;
  int r;
  int winner;
  Match(int n, int l, int r, int w) : number(n), l(l), r(r), winner(w) {}
};

struct ReverseL {
  bool operator() (const Match &m1, const Match &m2) {
    return m1.l > m2.l;
  }
};

struct ReverseN {
  bool operator() (const Match &m1, const Match &m2) {
    return m1.number > m2.number;
  }
};

vector<Match> vm;
int ans[300001];
priority_queue<Match, vector<Match>, ReverseL> pq_l;
priority_queue<Match, vector<Match>, ReverseN> pq_n;

int solve(int i) {
  while(!pq_n.empty() && pq_n.top().r < i)
    pq_n.pop();
  
  while(!pq_l.empty() && pq_l.top().l == i) {
    pq_n.push(pq_l.top());
    pq_l.pop();
  }

  stack<Match> temp;
  // cout << i << ' ' << pq_n.size() << endl;
  while(!pq_n.empty() && pq_n.top().winner == i) {
    temp.push(pq_n.top());
    do {
      pq_n.pop();
    } while(pq_n.top().r < i);
  }
  int ans;
  if(pq_n.empty())
    ans = 0;
  else
    ans = pq_n.top().winner;
  
  while(!temp.empty()) {
    pq_n.push(temp.top());
    temp.pop();
  }
  return ans;
}


int main() {
  int n, m;
  cin >> n >> m;
  for(int i = 0; i < m; i++) {
    int l, r, x;
    cin >> l >> r >> x;
    pq_l.push(Match(i, l, r, x));
  }

  for(int i = 1; i < n; i++)
    cout << solve(i) << ' ';
  cout << solve(n) << endl;
}