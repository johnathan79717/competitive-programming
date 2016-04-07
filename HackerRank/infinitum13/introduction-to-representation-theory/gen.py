from math import *
from sys import argv

n = int(argv[1])

print(1, n)
for i in range(n):
    t = pi / n * 2 * i
    print(cos(t), sin(t))
