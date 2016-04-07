N = int(input())

ans = (N-1) * (N-1)
arr = []

for a in range(2, N+1):
    for b in range(2, N+1):
        arr.append(a**b)

print(len(set(arr)))