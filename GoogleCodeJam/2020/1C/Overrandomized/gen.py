import random
T = 10
print(T)
for t in range(T):
    U = 16
    print(U)
    for i in range(10000):
        M = random.randrange(1, 10**U)
        N = random.randint(1, M)
        print(-1, N)
