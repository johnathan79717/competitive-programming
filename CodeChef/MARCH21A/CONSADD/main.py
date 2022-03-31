T = int(input())

for t in range(T):
    R, C, X = (int(x) for x in input().split())
    A = [[int(x) for x in input().split()] for i in range(R)]
    B = [[int(x) for x in input().split()] for i in range(R)]
    d1 = [[0] * C for i in range(R)]
    d2 = [[0] * C for i in range(R)]
    for i in range(R):
        for j in range(C):
            if i:
                d1[i][j] += d1[i-1][j]
            if j:
                d2[i][j] += d2[i][j-1]
            d = B[i][j] - (A[i][j] + d1[i][j] + d2[i][j])
            if i + X-1 < R:
                d1[i][j] += d
                if i + X < R:
                    d1[i+X][j] -= d
            elif j + X-1 < C:
                d2[i][j] += d
                if j + X < C:
                    d2[i][j+X] -= d
            A[i][j] += d1[i][j] + d2[i][j]

    print('Yes' if (all(A[i][j] == B[i][j] for i in range(R-X+1, R) for j in range(C-X+1, C))) else 'No')
