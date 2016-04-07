from numpy import *

tt = input()
for case in xrange(tt):
  s = raw_input().split()
  r = float128(s[0])
  t = float128(s[1])
  n = long(2 * t / (sqrt((2 * r - 1)**2 + 8 * t) + (2 * r - 1)))
  if n * (2 * long(r) + 2 * n - 1) > long(t):
    n = n + 1
  if (n + 1) * (2 * long(r) + 2 * n + 1) <= long(t):
    n = n - 1

  print ('Case #%d:' % (case + 1)), n