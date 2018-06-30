#include <unordered_set>
#include <unordered_map>
#define EB emplace_back
#define RL(x) scanf("%lld", &(x))
#define PL(x) printf("%lld\n", x)
#define DRL(x) LL x; RL(x)
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
//#define DEBUG

void receive(int i) {
    Receive(i);
#ifdef DEBUG
    //cout << "receive from " << i << endl;
#endif
}

void send(int i) {
    Send(i);
#ifdef DEBUG
    //cout << "send to " << i << endl;
#endif
}

int getInt(int i) {
    int x = GetInt(i);
#ifdef DEBUG
    cout << "getInt " << x << " from " << i << endl; 
#endif
    return x;
}
char getChar(int i) {
    char c = GetChar(i);
#ifdef DEBUG
    cout << "getChar " << c << " from " << i << endl;
#endif
    return c;
}
LL getLL(int i) {
    LL x = GetLL(i);
#ifdef DEBUG
    cout << "getLL " << x << " from " << i << endl; 
#endif
    return x;
}
void putInt(int i, int x) {
    PutInt(i, x);
#ifdef DEBUG
    cout << "putInt " << x << " to " << i << endl;
#endif
}
void putChar(int i, char c) {
    PutChar(i, c);
#ifdef DEBUG
    cout << "putChar " << c << " to " << i << endl;
#endif
}
void putLL(int i, LL x) {
    PutLL(i, x);
#ifdef DEBUG
    cout << "putLL " << x << " to " << i << endl;
#endif
}

#include ""

#define LOG(x, ...) fprintf(stderr, x, ##__VA_ARGS__)
//#define LOG(x...)

int main() {
    int M = NumberOfNodes(), id = MyNodeId();

    return 0;
}
