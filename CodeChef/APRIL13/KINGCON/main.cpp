#include <cstdio>
#include <algorithm>

using namespace std;

bool adj[3000][3000];
int dis[3000];
int low[3000]; // 紀錄該點子孫們用back edge連到的最高祖先（的遍歷順序），
            // 也就是遍歷順序盡量小的點，故取名為low。
            // 例如第4點的子孫們，
            // 有back edge連到遍歷順序為low[4]的祖先。
int t = 0;
bool isap[3000];
int N;

void reset() {
    for(int i = 0; i < N; ++i) {
        dis[i] = low[i] = isap[i] = 0;
        for(int j = 0; j < N; ++j) {
            adj[i][j] = 0;
        }
    }
}

void DFS(int p, int i)
{
    dis[i] = low[i] = ++t;
 
    int child = 0;
    bool ap = false;
 
    for (int j=0; j<N; ++j)
        if (adj[i][j] && j != p)
            if (dis[j]) // back edge
            {
                // 紀錄遍歷順序較小的，即是最高祖先。
                low[i] = min(low[i], dis[j]);
            }
            else        // tree edge
            {
                child++;
                DFS(i, j);
 
                // 紀錄遍歷順序較小的，即是最高祖先。
                low[i] = min(low[i], low[j]);
                if (low[j] >= dis[i]) ap = true;
            }
 
    if (i == p && child > 1 || i != p && ap)
        isap[i] = true;
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int M, K, i, ans = 0;
        scanf("%d%d%d", &N, &M, &K);
        for(i = 0; i < M; ++i) {
            int A, B;
            scanf("%d%d", &A, &B);
            adj[A][B] = adj[B][A] = true;
        }
        DFS(0, 0);
        for(i = 0; i < N; ++i)
            if(isap[i])
                ans += K;
        printf("%d\n", ans);
        reset();
    }
}