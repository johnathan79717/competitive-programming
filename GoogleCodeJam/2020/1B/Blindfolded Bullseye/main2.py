from __future__ import print_function
import sys
import random

def eprint(*args, **kwargs):
    pass
    print(*args, file=sys.stderr, **kwargs)

T, A, B = (int(x) for x in input().split())

eprint(T, A, B)

def query(x, y):
    print(x, y)
    v = input()
    # eprint(x, y, v)
    assert(v != 'WRONG')
    return v

def solve():
    L = 10 ** 9
    x_in, y_in = None, None
    for x in [-L // 4, L // 4]:
        for y in [-L // 4, L // 4]:
            v = query(x, y)
            if v == 'CENTER':
                return
            if v == 'HIT':
                x_in = x
                y_in = y
    eprint('in', x_in, y_in)
    assert(x_in is not None and y_in is not None)
    
    def search(hit, miss, x, y):
        while abs(hit - miss) > 1:
            mid = (hit + miss) // 2
            if x is None:
                v = query(mid, y)
            else:
                v = query(x, mid)
            if v == 'CENTER':
                return
            if v == 'HIT':
                hit = mid
            else:
                assert(v == 'MISS')
                miss = mid
        eprint(hit, miss)
        return hit

    r = search(x_in, L+1, None, y_in)
    l = search(x_in, -L-1, None, y_in)
    u = search(y_in, L+1, x_in, None)
    d = search(y_in, -L-1, x_in, None)

    v = query((r + l) // 2, (u + d) // 2)
    assert(v == 'CENTER')

for t in range(T):
    solve()
