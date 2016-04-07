#include <iostream>

using namespace std;

#define MOD 747474747

long long d[6666];       // 紀錄目前的MST到圖上各點的距離。
int parent[6666];  // 紀錄各個點在MST上的父親是誰
bool visit[6666];  // 紀錄各個點是不是已在MST之中
long long point[6666][5];
int D;

long long w(int i, int j) {
    long long ans = 0;
    for(int k = 0; k < D; ++k)
        ans += (point[i][k] - point[j][k]) * (point[i][k] - point[j][k]);
    return ans;
}

int main()
{
    int T;
    cin >> T;
    while(T--) {
        int N, i, j, k;
        long long ans = 1;
        cin >> N >> D;
        for(i = 0; i < N; i++)
            for(j = 0; j < D; j++)
                cin >> point[i][j];
        for (int i=0; i<N; i++) visit[i] = false;
        for (int i=0; i<N; i++) d[i] = -1e18;
        d[0] = 0;   // 可以選定任何點作為樹根，這裡以第零點作為樹根。
        parent[0] = 0;
        visit[0] = true;
        for(int i = 0; i < N; ++i) {
            d[i] = w(i, 0);
            parent[i] = 0;
        }
        for (int i=0; i<N; i++)
        {
            int a = -1, b = -1;
            long long max = -1e18;
            for (int j=0; j<N; j++)
                if (!visit[j] && d[j] > max)
                {
                    a = j;  // 記錄這一條邊
                    max = d[j];
                }
            if (a == -1) break; // 與起點相連通的MST都已找完
            visit[a] = true;
    //      d[a] = 0;           // 註解後，得到MST每條邊權重。
            // cout << parent[a] << ' ' << a << ' ' << w(parent[a], a) << endl;
            if(w(parent[a], a))
                ans = ans * (w(parent[a], a) % MOD) % MOD;
            // cout << ans << endl;
     
            for (b=0; b<N; b++)
                // 以下與Dijkstra's Algorithm略有不同
                if  (!visit[b] && w(a, b) > d[b])
                {
                    d[b] = w(a, b); // 離樹最近，不是離根最近。
                    parent[b] = a;
                }
        }
        cout << ans << endl;
    }
 
    return 0;
 
}