from collections import Counter
n = int(input())

c = Counter(x * x + y * y + z * z + x * y + y * z + z * x
        for x in range(1, 100) for y in range(1, 100) for z in range(1, 100))

for i in range(1, n+1):
    print(c[i])
