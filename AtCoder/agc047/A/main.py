from collections import defaultdict
N = int(input())

def gcd(a, b):
  return b if a == 0 else gcd(b % a, a)

def get25(p):
  n2 = 0
  n5 = 0
  while p % 2 == 0:
    n2 += 1
    p //= 2
  while p % 5 == 0:
    n5 += 1
    p //= 5
  return (n2, n5)

d = defaultdict(int)

for i in range(N):
  s = input()
  for i, c in enumerate(s):
    if c == '.':
      q = int(s[:i] + s[i+1:])
      p = 10 ** (len(s) - i - 1)
      break
  else:
    q = int(s)
    p = 1
  g = gcd(p, q)
  p, q = p // g, q // g
  p2, p5 = get25(p)
  q2, q5 = get25(q)
  

  d[(q2 - p2, q5 - p5)] += 1
  # print(q, p, q2, p2, q5, p5)

# print(d)

d = list(d.items())

ans = 0

# print(d)

for j in range(len(d)):
  if d[j][0][0] >= 0 and d[j][0][1] >= 0:
    ans += d[j][1] * (d[j][1] - 1) // 2
  for i in range(j):
    if d[i][0][0] + d[j][0][0] >= 0 and d[i][0][1] + d[j][0][1] >= 0:
      # print(d[i], d[j])
      ans += d[i][1] * d[j][1]

print(ans)
