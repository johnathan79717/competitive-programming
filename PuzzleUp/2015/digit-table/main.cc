#include <cstdio>
#include <cassert>
#include <initializer_list>

//const int N = 5;
//char table[N][N+1] = {
    //"11111",
    //"12221",
    //"12121",
    //"12221",
    //"11111",
//};

const int N = 9;
char table[N][N+1] = {
    "111111111",
    "122222221",
    "123333321",
    "123222321",
    "123212321",
    "123222321",
    "123333321",
    "122222221",
    "111111111",
};

//char target[] = "121";
char target[] = "12321";

int ans = 0;

void dfs(int i, int j, int k) {
    assert(k < N);
    if (i < 0 || j < 0 || i >= N || j >= N || table[i][j] != target[k]) {
        return;
    }
    k++;
    if (!target[k]) {
        ans++;
    } else {
        for (int dx: {-1, 0, 1}) {
            for (int dy: {-1, 0, 1}) {
                dfs(i+dx, j+dy, k);
            }
        }
    }        
}

int main() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            dfs(i, j, 0);
        }
    }
    printf("%d\n", ans);
}
