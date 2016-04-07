import sys

def make_palin(s, odd):
  if odd:
    return long(s + s[-2::-1])
  else:
    return long(s + s[-1::-1])

n, k = input().split()
k = int(k)

if n[0] == '-' and k < 0:
  print(-1)
  sys.exit(0)

l = len(n)
odd = len(n) % 2 == 1

p = n[:(l+1)//2]
print(make_palin(p, odd))