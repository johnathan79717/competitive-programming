#include <iostream>

using namespace std;

int main() {
  int T;
  cin >> T;
  while(T--) {
    int N, i, j, k;
    char map[200][201];
    cin >> N;
    for(i = 0; i < N; i++)
      cin >> map[i];

    int d[200][200];
    for(i = 0; i < N; i++)
      for(j = 0; j < N; j++)
        if(i == j) d[i][j] = 0;
        else d[i][j] = map[i][j] == 'Y' ? 1 : 300;

    for(k = 0; k < N; k++)
      for(i = 0; i < N; i++)
        for(j = 0; j < N; j++)
          d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

    // for(i = 0; i < N; i++) {
    //   for(j = 0; j < N; j++)
    //     cout << d[i][j] << ' ';
    //   cout << endl;
    // }

    int Q;
    cin >> Q;
    while(Q--) {
      int A, B;
      cin >> A >> B;
      cout << d[A][B] << endl;
    }
  }
}