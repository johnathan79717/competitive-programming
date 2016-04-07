from itertools import permutations

best = ""

for p in permutations(xrange(1, 11)):
  if p[0] > p[1] or p[0] > p[2] or p[0] > p[3] or p[0] > p[4]:
    continue
  s = p[0] + p[5] + p[6]
  if s != p[1] + p[6] + p[7]:
    continue
  if s != p[2] + p[7] + p[8]:
    continue
  if s != p[3] + p[8] + p[9]:
    continue
  if s != p[4] + p[9] + p[5]:
    continue
  sol = ''.join(map(str, [p[0], p[5], p[6], p[1], p[6], p[7], p[2], p[7], p[8], p[3], p[8], p[9], p[4], p[9], p[5]]))
  if sol > best:
    best = sol

print best