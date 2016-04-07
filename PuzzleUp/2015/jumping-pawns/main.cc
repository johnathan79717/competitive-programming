#include <cstdlib>
#include <queue>

using namespace std;

#define N 20
int dis[1<<N], last1[1<<N], last2[1<<N];

template<class T, class S>
bool has_bit(T mask, S i) { return (mask >> i) & 1; }
long long shift(int i) { return 1ll << i; }

queue<int> q;

void print(int mask) {
    for (int i = 0; i < N; i++) {
        printf("%d", (mask >> i) & 1);
    }
    puts("");
}

void check(int d, int mask, int i, int j) {
    if (dis[mask] < 0) {
        q.push(mask);
        dis[mask] = d+1;
        last1[mask] = i;
        last2[mask] = j;
        if (mask == shift(N) - shift(N/2)) {
            printf("%d\n", d+1);
            while (mask != shift(N/2) - 1) {
                i = last1[mask], j = last2[mask];
                //printf("%d %d\n", i, j);
                print(mask);
                mask ^= (shift(i) + shift(j));
            }
            exit(0);
        }
    }
}

int main() {
    memset(dis, -1, sizeof dis);
    q.push(shift(N/2) - 1);
    dis[shift(N/2)-1] = 0;
    while (q.size()) {
        int mask = q.front();
        q.pop();
        int d = dis[mask];
        for (int i = 0; i < N-1; i++) {
            if (has_bit(mask, i)) {
                if (!has_bit(mask, i+1)) {
                    check(d, mask ^ shift(i) ^ shift(i+1), i, i+1);
                } else {
                    int j = i;
                    while (j + 2 < N && has_bit(mask, j+1) && !has_bit(mask, j+2)) {
                        j += 2;
                        check(d, mask ^ shift(i) ^ shift(j), i, j);
                    }
                    check(d, mask ^ shift(i) ^ shift(j), i, j);
                }
                }
            }
    }
}
