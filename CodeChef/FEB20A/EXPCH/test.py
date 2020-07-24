import random

N = 10

print(1)
print(N)
print(''.join(['()*'[random.randint(0, 2)] for i in range(N)]))
