import sys

def dbg(*args, **kwargs):
    return
    print(*args, file=sys.stderr, **kwargs)

T, W = (int(x) for x in input().split())
dbg(T, W)

for t in range(T):
    print(224)
    n = int(input())
    dbg(n)
    R4 = n >> 56
    R5 = (n % (1 << 56)) >> 44
    R6 = (n % (1 << 44)) >> 37

    print(56)
    n = int(input())
    dbg(n)
    n -= (R4 << 14) + (R5 << 11) + (R6 << 9)
    R1 = n >> 56
    R2 = (n % (1 << 56)) >> 28
    R3 = (n % (1 << 28)) >> 18

    print(R1, R2, R3, R4, R5, R6)
    v = int(input())
    if v == -1:
        dbg(R1, R2, R3, R4, R5, R6)
        exit(v)
