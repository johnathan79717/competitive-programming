#include <iostream>
#include <vector>
using namespace std;
#define MAX_P 100000000
#define MAX_N 10000
bool isprime[MAX_P];
bool adj[MAX_N][MAX_N];

int cat(int a, int b) {
  int e = 10;
  while(e <= b) e *= 10;
  return a * e + b;
}

struct Triple { int fst, snd, trd; };
struct Quad { int a, b, c, d; };

int main() {
  memset(isprime, true, sizeof(isprime));
  isprime[0] = isprime[1] = false;
  vector<int> prime;
  for(int i = 2; i < MAX_P; i++) {
    if(!isprime[i]) continue;
    prime.push_back(i);
    for(int j = i+i; j < MAX_P; j+=i)
      isprime[j] = false;
  }

  vector<pair<int, int> > v2;
  for(int i = 0; prime[i] < MAX_N; i++)
    for(int j = 0; j < i; j++)
      if(isprime[cat(prime[i], prime[j])] && isprime[cat(prime[j], prime[i])])
        adj[i][j] = adj[j][i] = true, v2.push_back(make_pair(j, i));

  vector<Triple> v3;
  for(auto &pi : v2)
    for(int i = 0; i < pi.first; i++)
      if(adj[i][pi.first] && adj[i][pi.second])
        v3.push_back(Triple({i, pi.first, pi.second}));
  
  vector<Quad> v4;
  for(auto &t : v3)
    for(int i = 0; i < t.fst; i++)
      if(adj[i][t.fst] && adj[i][t.snd] && adj[i][t.trd])
        v4.push_back(Quad({i, t.fst, t.snd, t.trd}));

  for(auto &q : v4)
    for(int i = 0; i < q.a; i++)
      if(adj[i][q.a] && adj[i][q.b] && adj[i][q.c] && adj[i][q.d])
        cout << prime[i] << ' ' << prime[q.a] << ' ' << prime[q.b] << ' ' << prime[q.c] << ' ' << prime[q.d] << endl;
}