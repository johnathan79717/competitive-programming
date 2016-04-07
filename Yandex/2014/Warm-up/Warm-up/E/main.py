n, k = map(int, raw_input().split())

ans = 1
f = 1

for i in xrange(1, n+1):
  f *= i
  ans += (f ** k)

while ans % 10 == 0:
  ans /= 10

print ans % 10