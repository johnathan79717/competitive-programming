N, M, X = map(int, input().split())

for a in range(1, X+2):
    b = X + 2 - a
    n = a * b
    if N <= n <= M:
        m = X * n // 2
        print(n, m)
        cnt = 0
        for i in range(0, n):
            for j in range(0, i):
                if i % a == j % a or i // a == j // a:
                    print(i+1, j+1)
                    cnt += 1
        assert m == cnt
        break        
else:
    if X == 2 and N <= 4 <= M:
        print('4 4\n1 2\n2 4\n1 3\n3 4')
    elif N <= X+1 <= M:
        print(X+1, X*(X+1)//2)
        for i in range(1, X+2):
            for j in range(1, i):
                print(i, j)
    else:
        print(-1, -1)
