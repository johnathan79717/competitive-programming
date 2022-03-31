from collections import Counter
N, M = (int(x) for x in input().split())

a = [0, 0]
for i in range(N):
  S = input()
  a[Counter(S)['1'] % 2] += 1

print(a[0] * a[1])
