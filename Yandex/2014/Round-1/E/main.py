from itertools import chain, combinations, combinations_with_replacement
import sys

n = int(raw_input())
a = set(map(int, raw_input().split()))

for ans in xrange(1, 6):
  for comb in combinations_with_replacement(xrange(1, max(a)+1), ans):
    s = set(map(sum, chain(*[combinations(comb, k) for k in xrange(1, ans+1)])))
    # print s
    if a.issubset(s):
      print ans
      sys.exit(0)

print 6
