from __future__ import print_function
import sys

def eprint(*args, **kwargs):
    pass
    # print(*args, file=sys.stderr, **kwargs)

T, B = (int(x) for x in input().split())

def flip(bit):
    if bit == '0':
        return '1'
    if bit == '1':
        return '0'
    return '*'

def flipAll(bits):
    return [flip(b) for b in bits]

def query(i):
    print(i+1)
    ans = input()
    eprint('query', i+1, ans)
    return ans

for t in range(T):
    ans = ['*'] * B
    l, r = 0, B-1

    eq, ne = None, None
    while True:
        cnt = 10
        eprint('eq', eq, 'ne', ne)
        if eq is not None:
            cnt -= 1
            bit = query(eq)
            if bit != ans[eq]:
                eprint('flip')
                ans = flipAll(ans)
        if ne is not None:
            cnt -= 1
            bit = query(ne)
            if bit != ans[ne]:
                ans = ans[::-1]
                eprint('reverse')
        while l < r and cnt >= 2:
            cnt -= 2
            ans[l] = query(l)
            ans[r] = query(r)
            if eq is None and ans[l] == ans[r]:
                eq = l
            if ne is None and ans[l] != ans[r]:
                ne = l
            l += 1
            r -= 1

        if l >= r:
            break
        if cnt:
            query(0)
        eprint('current ans', ''.join(ans))
    print(''.join(ans))
    input()
