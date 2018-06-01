#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    int Nx, Ny, Kx, Ky, Cx, Cy;
    scanf("%d%d%d%d%d%d", &Nx, &Ny, &Kx, &Ky, &Cx, &Cy);
    int x = abs(Cx - Kx), y = abs(Cy - Ky);
    if (x < y) swap(x, y);
    int ans = max((x + y + 2) / 3, (x + 1) / 2);
    if ((x + y) % 2 != ans % 2) {
        ans++;
    }
    if (x == 1 && y == 0) {
        ans = 3;
    }
    if (x == 2 && y == 2) {
        ans = 4;
    }
    if (x == 1 && y == 1) {
        if (((Kx == 0 || Kx+1 == Nx) && (Ky == 0 || Ky+1 == Ny)) ||
            ((Cx == 0 || Cx+1 == Nx) && (Cy == 0 || Cy+1 == Ny))) {
            ans = 4;
        }
    }
    printf("%d\n", ans);
}
