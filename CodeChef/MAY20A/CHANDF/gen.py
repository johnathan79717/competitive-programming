import random

T = 1000
N = 1000

print(T)
for t in range(T):
    X, Y, L, R = (random.randrange(N) for i in range(4))
    if L > R:
        L, R = R, L
    print(X, Y, L, R)
