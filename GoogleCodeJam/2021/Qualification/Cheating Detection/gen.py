import random as r
import math as m
T = 100
P = 86
print(T)

def f(S, Q):
    return 1 / (1 + m.exp(Q - S))

for t in range(T):
    print(P)
    Q = [r.random() * 6 - 3 for i in range(10000)]    
    for i in range(100):
        S = r.random()
        print(''.join('1' if (i == 0 and r.random() > 0.5) or f(S, q) > 0.5 else '0' for q in Q))
