#include <cstdio>
#include <algorithm>

using namespace std;

unsigned int d;
double P[50001], N[50001];
unsigned int B[50001];

double mergeSort(int* const a, int n, int *const b) {
    if(n == 1) {
        b[0] = a[0];
        return 0;
    }
    int n1 = n/2, n2 = n-n/2;
    double ans = 0;
    int *a1 = new int[n1];
    ans += mergeSort(a, n1, a1);
    int *a2 = new int[n2];
    ans += mergeSort(a+n1, n2, a2);

    //merge
    int i1 = 0, i2 = 0, j1 = 0, j2 = 0, i = 0;
    double s1 = 0, s2 = 0;
    while(i1 < n1 && i2 < n2) {
        if(B[a1[i1]] > B[a2[i2]]) {
            while(j1 < n1 && B[a1[j1]] <= B[a2[i2]] + d) 
                s1 += N[a1[j1++]];
            ans += (n1-i1);
            ans -= s1 * P[a2[i2]];
            s2 -= N[a2[i2]];
            b[i++] = a2[i2++];
        } else { // B[a1[i1]] <= B[a2[i2]]
            while(j2 < n2 && B[a1[i1]] + d > B[a2[j2]])
                s2 += N[a2[j2++]];
            ans += s2 * P[a1[i1]];
            s1 -= N[a1[i1]];
            b[i++] = a1[i1++];
        }
    }
    while(i1 < n1)
        b[i++] = a1[i1++];
    while(i2 < n2)
        b[i++] = a2[i2++];
    delete[] a1;
    delete[] a2;
    // printf("%lld\n", ans);
    return ans;
}

int main() {
    int T;
    scanf("%d", &T);
    int n;
    while(T--) {
        scanf("%d%u", &n, &d);
        int i;
        for(i = 0; i < n; ++i)
            scanf("%u", B + i);
        for(i = 0; i < n; ++i) {
            int temp;
            scanf("%d", &temp);
            P[i] = temp / 100.0;
            N[i] = 1 - P[i];
        }
        // for(i = 0; i < n; ++i)
        //     for(int j = 0; j < i; ++j)
        //         if(B[j] > B[i]) {
        //             puts("10000");
        //             if(B[j] <= B[i] + d)
        //                 printf("-%d\n", N[j]*P[i]);
        //         } else {
        //             puts("0");
        //             if(B[j] + d > B[i])
        //                 printf("%d\n", P[j]*N[i]);
        //         }
        int a[50001], b[50001];
        for(i = 0; i < n; ++i)
            a[i] = i;
        printf("%.4f\n", mergeSort(a, n, b));
        // for(i = 0; i < n; ++i)
        //     printf("%d\n", b[i]);
    }
}