#include <array>
#include <unordered_set>
#include <unordered_map>
#define EB emplace_back
#define RL(x) scanf("%lld", &(x))
#define PL(x) printf("%lld\n", x)
#define DRL(x) LL x; RL(x)

void dbg() {
    cerr << endl;
}

template<typename T, typename... Args>
void dbg(T t, Args... args) // recursive variadic function
{
    cerr << t << ' ';
    dbg(args...);
}

int main() {
    DRI(T);
    REP1(t, 1, T) {
        printf("Case #%d: ", t);

    }
    return 0;
}
