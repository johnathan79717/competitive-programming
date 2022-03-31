import numpy as np

N = int(input())

C = []

for i in range(N):
  C.append(np.array(map(int, input().split())))

print(C)
