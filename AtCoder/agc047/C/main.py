N = int(input())

A = [int(x) for x in input().split()]

s1 = 0
s2 = 0

MOD = 200003

for a in A:
  s1 += a
  s2 += a * a

f = [0] * MOD

