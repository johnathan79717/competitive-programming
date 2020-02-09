from math import gcd

T = int(input())

for t in range(T):
    N, L = (int(x) for x in input().split())
    values = [int(x) for x in input().split()]
    p = [0] * (L+1)
    for i in range(L-1):
        if values[i] != values[i+1]:
            p[i+1] = gcd(values[i], values[i+1])
            for j in range(i, -1, -1):
                p[j] = values[j] // p[j+1]
            for j in range(i+2, L+1):
                p[j] = values[j-1] // p[j-1]
            break
    m = { p : c for p, c in zip(sorted(list(set(p))), 'ABCDEFGHIJKLMNOPQRSTUVWXYZ') }
    print('Case #{}:'.format(t+1), ''.join([m[p] for p in p]))

