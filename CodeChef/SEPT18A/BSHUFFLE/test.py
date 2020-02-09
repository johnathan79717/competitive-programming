from collections import defaultdict
import random

N, K = [int(x) for x in raw_input().split()]

d = defaultdict(int)

for k in xrange(K):
    p = range(1, N+1)
    for i in xrange(N):
        j = random.randrange(N)
        p[i], p[j] = p[j], p[i]

    d[str(p)] += 1

a = sorted(d.items(), key=lambda x: x[1])
print(a[0])
print(a[-1])
