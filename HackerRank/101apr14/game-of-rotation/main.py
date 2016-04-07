N = int(raw_input())
a = map(int, raw_input().split())

sum = 0
pmean = 0

for i, v in enumerate(a):
  sum += v
  pmean += (i+1) * v

ans = pmean

for v in a:
  pmean = pmean - sum + N * v
  ans = max(ans, pmean)

print ans