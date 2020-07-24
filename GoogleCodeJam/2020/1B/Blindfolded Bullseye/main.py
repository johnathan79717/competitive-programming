from __future__ import print_function
import sys
import random

def eprint(*args, **kwargs):
    pass
    # print(*args, file=sys.stderr, **kwargs)

T, A, B = (int(x) for x in input().split())

eprint(T, A, B)

if A == 999999995 and B == 999999995:
    def solve():
        for a in range(-5, 6):
            for b in range(-5, 6):
                print(a, b)
                # eprint(a, b)
                v = input()
                # eprint(v)
                if v == 'CENTER':
                    return

    for t in range(T):
        solve()
else:
    def solve():
        L = 1000000000
        R = L - 50
        x = L
        miss = L + 1
        hit = None
        while hit is None:
            print(x, 0)
            v = input()
            if v == 'MISS':
                miss = x
            else:
                assert(v == 'HIT')
                hit = x
            x -= 1

        eprint(hit, miss)
        for x in range(-50, 51):
            for y in range(-50, 51):
                if (x - miss) ** 2 + y ** 2 > R ** 2 and (x - hit) ** 2 + y ** 2 <= R ** 2:
                    print(x, y)
                    v = input()
                    eprint(x, y, v)
                    if v == 'CENTER':
                        return
        assert(False)
    for t in range(T):
        solve()

