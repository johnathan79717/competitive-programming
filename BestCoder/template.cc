#define DRL(x) LL x; RL(x)
#ifndef LOCAL
    #define PL(x) printf("%I64d\n",x)
    #define RL(x) scanf("%I64d\n",&x)
#else
    #define PL(x) printf("%lld\n",x)
    #define RL(x) scanf("%lld\n",&x)
#endif

int main() {
#ifdef CPP11
    static_assert(false, "CPP11");
#endif
    return 0;
}
