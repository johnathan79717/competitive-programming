#include <unordered_set>
#include <unordered_map>
#define EB emplace_back
#define RL(x) scanf("%lld", &(x))
#define PL(x) printf("%lld\n", x)
#define DRL(x) LL x; RL(x)
#include ""
#ifdef LOCAL
void Receive(int) {}
int GetInt(int) {}
char GetChar(int) {}
LL GetLL(int) {}
void Send(int) {}
void PutInt(int,int) {}
void PutChar(int,char) {}
void PutLL(int,LL) {}
int NumberOfNodes() { return 1; }
int MyNodeId() { return 0; }
#else
#include <message.h>
#endif

#define LOG(x, ...) fprintf(stderr, x, ##__VA_ARGS__)
//#define LOG(x...)

int main() {
    int M = NumberOfNodes(), id = MyNodeId();

    return 0;
}
