#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <cassert>

using namespace std;

#define ZERO 3000000

class Pt{
public:
    int X;
    int Y;
    int num1;
    int num2;
    int num3;
    // double slope;
    void set(int x, int y, int n1, int n2, int n3) {
        X = x;
        Y = y;
        num1 = n1;
        num2 = n2;
        num3 = n3;
        // if (x == 0) slope = (y > 0) ? 1e9 : -1e9;
        // else slope = double(y)/x;
    }
    Pt() {}
    Pt(const Pt& p){        
        X = p.X;
        Y = p.Y;
        num1 = p.num1;
        num2 = p.num2;
        num3 = p.num3;
    }
    Pt& operator=(const Pt& p) {
        X = p.X;
        Y = p.Y;
        num1 = p.num1;
        num2 = p.num2;
        num3 = p.num3;
        return (*this);
    }
    bool operator==(const Pt& p) const {
        // puts("==");
        return (Y == p.Y);
    }
    bool operator!=(const Pt& p) const {
        return (Y != p.Y);
    }
    bool operator<(const Pt& p) const {
        // puts("<");
        return (Y < p.Y);
    }
    Pt operator-() {
        Pt p;
        p.set(X, -Y, 0, 0, 0);
    }
};

// bool comp1(const Pt& a, const Pt& b) {
//     return a.Y < b.Y;
// }

// multiset<Pt> a[6000001];
int N, X[155], Y[155];
Pt p[600000];
long long ans = 0;

bool comp(int c, int d) {
    // printf("compare %d %d\n", c, d);
    if ( ((X[c] >= 0  && X[d] >= 0) || (X[c] < 0 && X[d] < 0)) && ((Y[c] >= 0  && Y[d] >= 0) || (Y[c] < 0 && Y[d] < 0)) ) {// same 
        double sc, sd;
        if (X[c] == 0) sc = (Y[c] > 0) ? 1e9 : -1e9;
        else sc = Y[c]/(double)X[c];
        if (X[d] == 0) sd = (Y[d] > 0) ? 1e9 : -1e9;
        else sd = Y[d]/(double)X[d];
        return sc < sd;
    }
    // puts("not the same");
    if (X[c] >= 0 && Y[c] >= 0) return true;
    if (X[d] >= 0 && Y[d] >= 0) return false;
    if (X[c] < 0 && Y[c] >= 0) return true;
    if (X[d] < 0 && Y[d] >= 0) return false;
    if (X[c] < 0 && Y[c] < 0) return true;
    return false;
}

long long area(int p1, int p2, int p3, int p4, int p5, int p6) {
    printf("%d %d %d %d %d %d\n", p1, p2, p3, p4, p5, p6);
    int cnt = 0;
    int poly[6];
    assert(X[p1]+X[p2]+X[p3]+X[p4]+X[p5]+X[p6] == 0 && Y[p1]+Y[p2]+Y[p3]+Y[p4]+Y[p5]+Y[p6] == 0);
    if (p1 >= 0) poly[cnt++] = p1;
    if (p2 >= 0) poly[cnt++] = p2;
    if (p3 >= 0) poly[cnt++] = p3;
    if (p4 >= 0) poly[cnt++] = p4;
    if (p5 >= 0) poly[cnt++] = p5;
    if (p6 >= 0) poly[cnt++] = p6;
    sort(poly, poly+cnt, comp);
    // for (int i = 0; i < cnt; ++i)
    //     printf("%d\n", poly[i]);
    long long x = X[poly[0]];
    long long y = Y[poly[0]];
    long long ar = 0;
    for (int i = 1; i < cnt-1; ++i) {
        ar += abs(x*(long long)Y[poly[i]]-y*(long long)X[poly[i]]);
        x += X[poly[i]];
        y += Y[poly[i]];
    }
    return ar;
}

bool com(Pt p1, Pt p2) {
    // if (p1.slope != p2.slope) return p1.slope < p2.slope;
    if (p1.X != p2.X) return p1.X < p2.X;
    if (p1.Y != p2.Y) return p1.Y < p2.Y;
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i)
        scanf("%d%d", X+i, Y+i);
    int cnt = 0;
    for (int i = 0; i < N; ++i) {
        p[cnt++].set(X[i], Y[i], -1, -1, i);
        for (int j = i; j < N; ++j) {
            p[cnt++].set(X[i]+X[j], Y[i]+Y[j], -1, i, j);
            for (int k = j; k < N; ++k) {   
                p[cnt++].set(X[i]+X[j]+X[k], Y[i]+Y[j]+Y[k], i, j, k);
            }
        }
    }
    sort(p, p+cnt, com);
    int l = 0;
    int u = cnt-1;
    do {
        while(l <= u && p[l].X + p[u].X)
            (p[l].X + p[u].X < 0) ? ++l : --u;
        if (l > u) break;
        while(l <= u && p[l].X + p[u].X == 0 && p[l].Y + p[u].Y)
            (p[l].Y + p[u].Y < 0) ? ++l : --u;
        if (l > u) break;
        if (p[l].X+p[u].X) continue;
        int l1 = l+1;
        int u1 = u-1;
        while (l1 < u && p[l1].X == p[l].X && p[l1].Y == p[l].Y)
            ++l1;
        while (l < u1 && p[u1].X == p[u].X && p[u1].Y == p[u].Y)
            --u1;
        // printf("%d %d %d %d\n", l, u, l1, u1);
        // printf("%d %d %d %d\n", p[l].X, p[l].Y, p[u].X, p[u].Y);
        for (int i = l; i < l1; ++i) {
            for (int j = u; j > u1; --j) {
                long long a = area(p[i].num1, p[i].num2, p[i].num3, p[j].num1, p[j].num2, p[j].num3);
                printf("%.1f\n", double(a)/2);
                ans = max(ans, a);
            }
        }
        l = l1;
        u = u1;
    } while(l < u);

    // for (int i = 0; i < cnt; ++i) {    
    //     a[p[i].X+ZERO].insert(p[i]);
    //     multiset<Pt>& v = a[-p[i].X+ZERO];
    //     // if (!v.empty()) { int j = 0;
    //     // pair<multiset<Pt>::iterator, multiset<Pt>::iterator> pr = v.equal_range(-p[i]);
    //     // for (multiset<Pt>::iterator j = pr.first; j != pr.second; ++j) {
    //     if (v.lower_bound(-p[i])->Y+p[i].Y == 0)
    //     for (multiset<Pt>::iterator j = v.lower_bound(-p[i]); j != v.upper_bound(-p[i]); ++j) {
    //         // if (p[i].Y+(p[v[j]]).Y == 0) {
    //             printf("%d %d %d %d %d %d\n", p[i].num1, p[i].num2, p[i].num3, j->num1, j->num2, j->num3);
    //             // printf("%lld\n", area(p[i].num1, p[i].num2, p[i].num3, p[v[j]].num1, p[v[j]].num2, p[v[j]].num3));
    //             ans = max(ans, area(p[i].num1, p[i].num2, p[i].num3, j->num1, j->num2, j->num3));
    //         // }
    //     }
    // }
    printf("%.1f\n", double(ans)/2);
}