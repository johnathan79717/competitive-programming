N = int(input())

def f(v):
    ans = 1
    for i in range(len(v)-1):
        if v[i] + 1 != v[i+1]:
            ans += 1
    return ans

for n in range(N):
    ans = 0
    for x in range(N):
        v = []
        for i in range(n):
            v.append(x ^ i)
        v.sort()
        if ans < f(v):
            ans = f(v)
    print(bin(n), ans)
