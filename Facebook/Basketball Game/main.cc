#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct Player {
  int minutes;
  string name;
  int shot_percentage;
  int height;
};

bool lessMinutes(const Player &p1, const Player &p2) {
  if(p1.minutes != p2.minutes)
    return p1.minutes < p2.minutes;
  if(p1.shot_percentage != p2.shot_percentage)
    return p1.shot_percentage > p2.shot_percentage;
  return p1.height > p2.height;
}

int main() {
  int T, cas = 1;
  cin >> T;
  while(T--) {
    cout << "Case #" << cas++ << ":";
    int N, M, P;
    cin >> N >> M >> P;
    vector<Player> player(N);
    for(int i = 0; i < N; i++) {
      player[i].minutes = 0;
      cin >> player[i].name >> player[i].shot_percentage >> player[i].height;
    }
    sort(player.begin(), player.end(), lessMinutes);
    vector<Player> team[2], bench[2];
    for(int i = 0; i < 2*P; i++)
      team[i%2].push_back(player[i]);
    for(int i = 2*P; i < N; i++)
      bench[i%2].push_back(player[i]);
    for(int j = 0; j < M; j++) {
      for(int i = 0; i < 2; i++) {
        if(bench[i].empty()) continue;
        for(int k = 0; k < P; k++)
          team[i][k].minutes++;
        int leave = 0;
        for(int k = 1; k < P; k++)
          if(lessMinutes(team[i][leave], team[i][k]))
            leave = k;
        int join = 0;
        for(int k = 1; k < bench[i].size(); k++)
          if(lessMinutes(bench[i][k], bench[i][join]))
            join = k;
        team[i].push_back(bench[i][join]);
        bench[i].push_back(team[i][leave]);
        team[i].erase(team[i].begin() + leave);
        bench[i].erase(bench[i].begin() + join);
      }
    }
    vector<string> ans;
    for(int i = 0; i < P; i++) {
      ans.push_back(team[0][i].name);
      ans.push_back(team[1][i].name);
    }
    sort(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); i++)
      cout << ' ' << ans[i];
    cout << endl;
  }
}