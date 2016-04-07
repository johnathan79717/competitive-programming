from itertools import permutations
from collections import defaultdict

n = int(raw_input())

g = defaultdict(int)

for x in permutations(xrange(n)):
  y = [0]
  for i in xrange(1, n):
    if x[y[-1]] not in y:
      y.append(x[y[-1]])
    else:
      for j in xrange(n):
        if j not in y:
          y.append(j)
          break
  g[''.join(map(str, y))] += 1

cnt = defaultdict(int)
for v in g.itervalues():
  cnt[v] += 1

print cnt