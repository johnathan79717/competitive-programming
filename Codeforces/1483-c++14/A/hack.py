import random

N = 100000
M = 100000

print(1)
print(N, M)

random.seed(0)
for i in range(M):
  f1 = random.randint(2, N)
  print(2, f1, random.randint(1, f1-1))
