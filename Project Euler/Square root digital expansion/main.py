from math import sqrt

def digit_sum(p):
  ans = 0
  while p > 0:
    ans += p % 10
    p /= 10
  return ans

def my_sqrt(n):
  p = 0
  for k in xrange(100):
    for x in xrange(9, -1, -1):
      if x * (20*p + x) <= n:
        break
    n -= x * (20*p + x)
    p = 10 * p + x
    n *= 100
  return digit_sum(p)

ans = 0
for n in xrange(1, 101):
  if(int(sqrt(n)) * int(sqrt(n)) == n):
    continue;
  ans += my_sqrt(n)

print ans