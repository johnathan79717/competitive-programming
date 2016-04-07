import re

r = re.compile(r'[a-zA-Z]+')
A = r.findall(raw_input().lower())
B = r.findall(raw_input().lower())
S = raw_input().lower()
K = long(raw_input())

A = A.count(S)
B = B.count(S)

if A == K:
  print 0
elif B == K:
  print 1
else:
  ans = 1
  while B < K:
    ans += 1
    A, B = B, A+B
  if B == K:
    print ans
  else:
    print "Impossible"
