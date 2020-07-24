import random

N = 2 ** 10 - 1
Q = 10000
M = 100

print(N)
for i in range(N):
    print(random.randint(1, M), random.randint(1, M))

print(Q)
for i in range(Q):
    print(random.randint(1, N), random.randint(1, M))

