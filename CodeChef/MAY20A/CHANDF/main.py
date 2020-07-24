T = int(input())

# def bf(X, Y, L, R):
    # ans = L
    # F = (X & L) * (Y & L)
    # for Z in range(L, R+1):
        # f = (X & Z) * (Y & Z)
        # if f > F:
            # ans = Z
            # F = f
    # return (ans, F)
        

for t in range(T):
    X, Y, L, R = (int(x) for x in input().split())
    d = 0
    ans = R
    F = (X & R) * (Y & R)
    while (1 << d) <= R:
        if R & (1 << d):
            Z = (R & ~((1 << (d+1)) - 1)) | (((1 << d) - 1) & (X | Y))
            dd = d-1
            while Z < L and dd >= 0:
                if (L & (1<<dd)) and not (Z & (1<<dd)):
                    Z = Z | (1 << dd)
                dd -= 1
            
            if Z < L or Z > R:
                break

            f = (X & Z) * (Y & Z)
            # print(R, d, Z, f)
            if f >= F:
                F = f
                ans = Z
        d += 1
    if (X & L) * (Y & L) >= F:
        ans = L
    # b = bf(X, Y, L, R)
    # print(X, Y, L, R, ans, F, b)
    # assert(ans == b[0])
    print(ans)
