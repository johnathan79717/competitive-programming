# cook your dish here
T = int(input())

def oneOp2(p, q, a, b):
    if p == a or q == b:
        return True
    if p != 0 and (a // p * p, a // p * q) == (a, b):
        return True
    if (a - p + p, a - p + q) == (a, b):
        return True
    return False

for t in range(T):
    p, q, r = (int(x) for x in input().split())
    a, b, c = (int(x) for x in input().split())

    def oneOp3(p, q, r, a, b, c):
        if a == p and oneOp2(q, r, b, c):
            return True
        if b == q and oneOp2(p, r, a, c):
            return True
        if c == r and oneOp2(p, q, a, b):
            return True
        if (a - p + p, a - p + q, a - p + r) == (a, b, c):
            return True
        if p != 0 and (a // p * p, a // p * q, a // p * r) == (a, b, c):
            return True
        return False

    def twoOp3(p, q, r, a, b, c):
        for d in (a - p, b - q, c - r):
            if oneOp3(p+d, q, r, a, b, c) or oneOp3(p, q+d, r, a, b, c) or oneOp3(p, q, r+d, a, b, c)\
                or oneOp3(p+d, q+d, r, a, b, c) or oneOp3(p+d, q, r+d, a, b, c)\
                or oneOp3(p, q+d, r+d, a, b, c) or oneOp3(p+d, q+d, r+d, a, b, c):
                return True
            if oneOp3(p, q, r, a-d, b, c) or oneOp3(p, q, r, a, b-d, c) or oneOp3(p, q, r, a, b, c-d)\
                or oneOp3(p, q, r, a-d, b-d, c) or oneOp3(p, q, r, a-d, b, c-d)\
                or oneOp3(p, q, r, a, b-d, c-d) or oneOp3(p, q, r, a-d, b-d, c-d):
                return True
        for d in (x // y for (x, y) in ((a, p), (b, q), (c, r)) if y != 0 and x % y == 0):
            if oneOp3(p*d, q, r, a, b, c) or oneOp3(p, q*d, r, a, b, c) or oneOp3(p, q, r*d, a, b, c)\
                or oneOp3(p*d, q*d, r, a, b, c) or oneOp3(p*d, q, r*d, a, b, c)\
                or oneOp3(p, q*d, r*d, a, b, c) or oneOp3(p*d, q*d, r*d, a, b, c):
                return True
            if d == 0:
                continue
            if a % d == 0 and oneOp3(p, q, r, a // d, b, c):
                return True
            if b % d == 0 and oneOp3(p, q, r, a, b // d, c):
                return True
            if c % d == 0 and oneOp3(p, q, r, a, b, c // d):
                return True
            if (a % d, b % d) == (0, 0) and oneOp3(p, q, r, a // d, b // d, c):
                return True
            if (a % d, c % d) == (0, 0) and oneOp3(p, q, r, a // d, b, c // d):
                return True
            if (b % d, c % d) == (0, 0) and oneOp3(p, q, r, a, b // d, c // d):
                return True
            if (a % d, b % d, c % d) == (0, 0, 0) and oneOp3(p, q, r, a // d, b // d, c // d):
                return True
        if p != q:
            d1 = (a - b) // (p - q)
            d2 = a - p * d1
            if (d1 * p + d2, d1 * q + d2, d1 * r + d2) == (a, b, c) :
                return True
        if r != q:
            d1 = (c - b) // (r - q)
            d2 = a - q * d1
            if (d1 * p + d2, d1 * q + d2, d1 * r + d2) == (a, b, c):
                return True
        if p != r:
            d1 = (a - c) // (p - r)
            d2 = a - p * d1
            if (d1 * p + d2, d1 * q + d2, d1 * r + d2) == (a, b, c):
                return True

        return False
    
    if (p, q, r) == (a, b, c):
        print(0)
    elif oneOp3(p, q, r, a, b, c):
        print(1)
    elif twoOp3(p, q, r, a, b, c):
        print(2)
    else:
        print(3)


