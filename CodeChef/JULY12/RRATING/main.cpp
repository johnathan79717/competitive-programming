#include <cstdio>
#include <queue>

using namespace std;

priority_queue<int> bad;
priority_queue<int, vector<int>, greater<int> > good;

int main() {
    int N;
    int ans = 0;
    int size = 0;
    scanf("%d", &N);
    while(N--) {
        int type;
        scanf("%d", &type);
        if(type == 2) {
            if(ans) printf("%d\n", ans);
            else puts("No reviews yet");
        } else {
            int x;
            scanf("%d", &x);
            switch(size) {
                case 0: 
                case 1: bad.push(x); break;
                case 2: bad.push(x); ans = bad.top(); bad.pop(); break;
                default: {
                    if (x > ans) {
                        good.push(x);
                        if(size % 3 != 2) {
                            bad.push(ans);
                            ans = good.top();
                            good.pop();
                        }
                    }
                    else {
                        bad.push(x);
                        if(size % 3 == 2) {
                            good.push(ans);
                            ans = bad.top();
                            bad.pop();
                        }
                    }
                }
            }
            ++size;
        }
    }
}