T = int(input())

for t in range(T):
    n1, n2, m = map(int, input().split())
    print(max(abs(n1 - n2), n1 + n2 - m * (m+1)))

