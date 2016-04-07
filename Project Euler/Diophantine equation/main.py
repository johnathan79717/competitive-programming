from math import sqrt

def cf(v):
  p = 0
  q = 1
  for i in reversed(v):
    p, q = q, p + q*i
  # print p, q
  return (p, q)

def cycle(D):
  # print "D = ", D
  m = 0
  d = 1
  a = int(sqrt(D))
  a0 = a
  if a * a == D:
    return 0
  v = [a0]
  # k = 0
  while True:
    # k += 1
    # if k == 5:
    #   return 0
    p, q = cf(v)
    if q*q == D*p*p + 1:
      return q
    m = d * a - m
    d = (D - m * m) / d
    a = (a0 + m) / d
    v.append(a)

ans = 1
best = 0

for D in xrange(1, 1001):
  x = cycle(D)
  print x
  assert x >= 0
  if x > best:
    ans = D
    best = x

print ans