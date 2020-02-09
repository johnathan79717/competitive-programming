from collections import defaultdict
import sys

def dbg(*args, **kwargs):
    return
    print(*args, file=sys.stderr, **kwargs)

T, F = map(int, input().split())

for t in range(T):
    ans = ''

    l = range(119)
    j = 5
    n = 120
    s = set('ABCDE')

    while j >= 1:
        d = defaultdict(list)
        for i in l:
            print(i * 5 + j)
            k = input()
            d[k].append(i)
            if k == 'N': exit()

        n //= j
        for k in s:
            if len(d[k]) < n:
                break

        s.remove(k)
        l = d[k]
        ans = k + ans
        j -= 1

    print(ans)
    k = input()
    if k == 'N': exit()
