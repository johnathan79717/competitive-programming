#include <string>
#include <vector>
#include <climits>
#include <cstring>
#include <map>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <stack>
#include <deque>
#include <list>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <cassert>
#include <sstream>
#include <bitset>
using namespace std;
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define SZ(X) ((int)(X).size())
#define LEN(X) strlen(X)
#define BG begin()
#define ED end()
#define FOR(i,c) for(auto &i: c)
#define ALL(x) (x).begin(),(x).end()
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define REPL(i,x) for(int i=0;x[i];i++)
#define PER(i,n) for(int i=(n)-1;i>=0;i--)
#define PER1(i,a,b) for(int i=(a);i>=(b);i--)
#define RI(x) scanf("%d",&x)
#define RL(x) scanf("%lld",&x)
#define DRI(x) int x;RI(x)
#define DRL(x) LL x;RL(x)
#define RII(x,y) scanf("%d%d",&x,&y)
#define DRII(x,y) int x,y;RII(x,y)
#define RIII(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define DRIII(x,y,z) int x,y,z;RIII(x,y,z)
#define RS(x) scanf("%s",x)
#define PI(x) printf("%d\n",x)
#define PL(x) printf("%lld\n",x)
#define PIS(x) printf("%d ",x)
#define MP make_pair
#define PB push_back
#define PQ priority_queue
#define E emplace
#define EB emplace_back
#define LB lower_bound
#define UB upper_bound
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,-1,sizeof(x))
#define SEP(x) ((x)?'\n':' ')
#define F first
#define S second
#define V(x) vector<x >

typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long LL;
typedef unsigned long long ULL;
const int INF = 1000000000;

int arr[10000000];

struct Node;
Node *getNode();

// struct Node {
//     Node *child[2];
//     int cnt;

//     void insert(int x) {
//         Node *p = this;
//         PER(i, 19) {
//             int j = (x>>i)&1;
//             if (!p->child[j]) {
//                 p->child[j] = getNode();
//             }
//             p = p->child[j];
//             p->cnt++;
//         }
//     }
//     void erase(int x) {
//         Node *p = this;
//         PER(i, 19) {
//             int j = (x>>i)&1;
//             if (!p->child[j]) {
//                 p->child[j] = getNode();
//             }
//             p = p->child[j];
//             p->cnt--;
//         }
//     }
//     int countLeq(int x) {
//         Node *p = this;
//         int ans = 0;
//         PER(i, 19) {
//             int j = (x>>i)&1;
//             if (j && p->child[0]) {
//                 ans += p->child[0]->cnt;
//             }
//             if (!p->child[j]) {
//                 p->child[j] = getNode();
//             }
//             p = p->child[j];
//         }
//         return ans + p->cnt;
//     }
//     int maxor(int x) {
//         int ans = 0;
//         Node *p = this;
//         PER(i, 19) {
//             if (!p) return 0;
//             int j = (x >> i) & 1;
//             ans <<= 1;
//             int target;
//             if (p->child[1-j] && p->child[1-j]->cnt) {
//                 target = 1-j;
//             } else {
//                 target = j;
//             }
//             p = p->child[target];
//             x ^= (target << i);
//         }
//         return x;
//     }
// } pool1[80000000];

struct Node {
    int value, height, size;
    Node *child[2];
    Node(): height(19), size(1) {}
    void insert(const int x) {
        int j = (x >> 18) & 1;
        if (!child[j]) {
            child[j] = getNode();
            child[j]->value = x;
            child[j]->height = 0;
            return;
        }
        Node *p = this;
        while (p->height) {
            int j = (x >> (p->height - 1)) & 1;
            if ((x >> p->child[j]->height) == p->child[j]->value) {
                p = p->child[j];
                p->size++;
            } else {
                Node *node = getNode();
                node->height = p->child[j]->height;
                node->value = p->child[j]->value;
                do {
                    node->height++;
                    node->value >>= 1;
                } while ((x >> node->height) != node->value);
                node->child[0] = p->child[j];
                p->child[j] = node;
                node->child[1] = getNode();
                node->child[1]->value = x;
                node->child[1]->height = 0;
                node->size++;
                if (node->child[0]->value > node->child[1]->value) {
                    swap(node->child[0], node->child[1]);
                }
                // assert(((node->child[0]->value >> (node->height - node->child[0]->height - 1)) & 1) == 0);
                // assert(((node->child[1]->value >> (node->height - node->child[1]->height - 1)) & 1) == 1);
                // assert((node->child[0]->value == x && node->child[0]->height == 0) || (node->child[1]->value == x && node->child[1]->height == 0));
                return;
            }
        }
    }
    void erase(const int x) {
        Node *p = this;
        while (p->height) {
            // assert((x >> p->height) == p->value);
            int j = (x >> (p->height - 1)) & 1;
            p = p->child[j];
            p->size--;
        }
        // assert(p->value == x);
    }
    int countLeq(int x) {
        Node *p = this;
        int ans = 0;
        while (p->height) {
            int j = (x >> (p->height - 1)) & 1;
            if (!p->child[j]) {
                if (j == 0) return 0;
                return p->child[0]->size;
            }
            if ((x >> p->child[j]->height) == p->child[j]->value) {
                if (j == 1 && p->child[0]) ans += p->child[0]->size;
                p = p->child[j];
            } else {
                if (p->child[0] && (x >> p->child[0]->height) > p->child[0]->value) {
                    ans += p->child[0]->size;
                    if (p->child[1] && (x >> p->child[1]->height) > p->child[1]->value) {
                        ans += p->child[1]->size;
                    }
                }
                return ans;
            }
        }
        return ans + p->size;
    }
} pool1[20000000];

int memory = 0;
Node *getNode() {
    return &pool1[memory++];
}

struct SegmentTree {
    // static T identity;
    int n;
    Node dat[2000000];

    SegmentTree(int n_) {
        n = 1;
        while(n < n_) n *= 2;
    }

    void insert(int k, int x) {
        k += n-1;
        do {
            dat[k].insert(x);
            k = (k-1)/2;
        } while(k);
    }

    void erase(int k, int x) {
        k += n-1;
        do {
            dat[k].erase(x);
            k = (k-1)/2;
        } while(k);
    }

    int countLeq(int a, int b, int x) {
        return countLeq(a, b, 0, 0, n, x);
    }

    int countLeq(int a, int b, int k, int l, int r, int x) {
        // if [a, b) and [l, r) are disjoint
        if(r <= a || b <= l) return 0;
        // if [l, r) contains [a, b)
        if(a <= l && r <= b) return dat[k].countLeq(x);
        return countLeq(a, b, k * 2 + 1, l, (l + r) / 2, x)
             + countLeq(a, b, k * 2 + 2, (l + r) / 2, r, x);
    }

    // int maxor(int a, int b, int x) {
    //     return maxor(a, b, 0, 0, n, x);
    // }

    // int maxor(int a, int b, int k, int l, int r, int x) {
    //     // if [a, b) and [l, r) are disjoint
    //     if(r <= a || b <= l) return -1;
    //     // if [l, r) contains [a, b)
    //     if(a <= l && r <= b) return dat[k].maxor(x);
    //     return max(maxor(a, b, k * 2 + 1, l, (l + r) / 2, x),
    //                maxor(a, b, k * 2 + 2, (l + r) / 2, r, x));
    // }
};

SegmentTree st(500000);
int main() {
    int N = 0;
    DRI(T);
    REP(t, T) {
        DRI(type);
        switch(type) {
            case 0: {
                DRI(x);
                if (arr[N]) {
                    // st.erase(N, arr[N]);
                }
                st.insert(N, arr[N] = x);
                N++;
                break;
            }
            case 1: {
                // XOR
                DRIII(L, R, x);
                // PI(st.maxor(L-1, R, x) ^ x);
                break;
            }
            case 2: {
                // delete
                DRI(k);
                // N -= k;
                break;
            }
            case 3: {
                // count <= x
                DRIII(L, R, x);
                PI(st.countLeq(L-1, R, x));
                break;
            }
            case 4: {
                // find kth integer
                DRIII(L, R, k);
                // int lb = 0, ub = 500000;
                // while (ub - lb > 1) {
                //     int m = (ub + lb) / 2;
                //     int c = st.countLeq(L-1, R, m);
                //     if (k > c) {
                //         lb = m;
                //     } else {
                //         ub = m;
                //     }
                // }
                // PI(ub);
                break;
            }
            default: //assert(false);
                break;
        }
    }
    PI(memory);
    return 0;
}
