#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int choice[5][4][6][3] = {
    {},
    {},
    {{}, {{0}, {1}}, },
    {{}, {{0}, {1}, {2}}, {{0, 1}, {0, 2}, {1, 2}}},
    {{}, {{0}, {1}, {2}, {3}}, {{0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 3}, {2, 3}}, {{0, 1, 2}, {0, 1, 3}, {0, 2, 3}, {1, 2, 3}}},
};

int choose[5][5] = {
    {1},
    {1, 1},
    {1, 2, 1},
    {1, 3, 3, 1},
    {1, 4, 6, 4, 1},
};

void get(int n, int *A) {
    int i = 0;
    while(n) {
        A[i++] = n % 10;
        n /= 10;
    }
}

void del(int &n, int i) {
    if(i == 3) n = n % 1000;
    else if(i == 2) n = n / 1000 * 100 + n % 100;
    else if(i == 1) n = n / 100 * 10 + n % 10;
    else n /= 10;
}

int main() {
    // int tmp = 995;
    // del(tmp, 0);
    // cout << tmp << endl;
    int N, K;
    scanf("%d%d", &N, &K);
    int ub = 1;
    for(int i = 0; i < N; i++) ub *= 10;
    int lb = ub / 10;
    // cerr << lb << ' ' << ub << endl;
    // set<pair<int, int> > ans;
    long long denSum = 0, numSum = 0;
    for (int den = ub-1; den >= lb; den--) {
        int arr1[4];
        get(den, arr1);
        for (int num = lb; num < den; num++) {
            int arr2[4];
            get(num, arr2);
            bool success = false;
            for (int c1 = 0; c1 < choose[N][K]; c1++) {
                int cand1[3], p = 0;
                bool fail = false;
                int newDen = den;
                for (int i = K-1; i >= 0; i--) {
                    cand1[p++] = arr1[choice[N][K][c1][i]];
                    del(newDen, choice[N][K][c1][i]);
                    if(cand1[p-1] == 0) {
                        fail = true;
                        break;
                    }
                }
                if(newDen == 0) continue;
                if(fail) continue;
                sort(cand1, cand1 + p);
                for (int c2 = 0; c2 < choose[N][K]; c2++) {
                    int cand2[3], p = 0, newNum = num;
                    bool fail = false;
                    for (int i = K-1; i >= 0; i--) {
                        cand2[p++] = arr2[choice[N][K][c2][i]];
                        del(newNum, choice[N][K][c2][i]);
                        if(cand2[p-1] == 0) {
                            fail = true;
                            break;
                        }
                    }
                    if(newNum == 0) continue;
                    if(fail) continue;
                    if(num * newDen != den * newNum) continue;
                    sort(cand2, cand2 + p);
                    for (int i = 0; i < p; i++) {
                        if(cand1[i] != cand2[i]) {
                            fail = true;
                            break;
                        }
                    }
                    if(fail) continue;
                    success = true;
                    // cout << newDen << ' ' << newNum << endl;
                    break;
                }
                if(success) break;
            }
            if(success) {
                // ans.emplace(den, num);
                // cout << den << ' ' << num << endl;
                denSum += den;
                numSum += num;
            }
        }
    }
    // for(auto &pr: ans) {
    //     denSum += pr.first;
    //     numSum += pr.second;
    // }
    cout << numSum << ' ' << denSum << endl;
}