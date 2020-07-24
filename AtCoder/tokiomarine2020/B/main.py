A, V = (int(x) for x in input().split())
B, W = (int(x) for x in input().split())
T = int(input())

print('YES' if V > W and abs(A - B) <= (V - W) * T else 'NO')
