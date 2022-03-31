A, B, C = (int(x) for x in input().split())

a, b, c = A, B, C

if B % 2:
  C = C % 2 + 2
  B = (B % 4) ** C % 4 + 4
elif B % 4 == 0 or B % 2 == 0 and C > 1:
  B = 4
else :
  B = 2

A = (A % 10) ** B % 10
# print(A, B, C)
print(A)

# assert(a ** (b ** c) % 10 == A)

