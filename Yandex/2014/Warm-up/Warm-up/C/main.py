from collections import defaultdict

def gcd(a, b):
  while a != 0:
    a, b = b%a, a
  return b

n = int(raw_input())
d = defaultdict(int)
for i in xrange(n):
  a, b, c = map(int, raw_input().split())
  num = (a+b-c)*(a-b+c)*(b+c-a)
  den = a+b+c
  g = gcd(num, den)
  d[(num / g, den / g)]+=1

print max(d.itervalues())