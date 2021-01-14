from math import sqrt
N = int(input())

A = [int(x) for x in input().split()]

print(sum(abs(x) for x in A))
print(sqrt(sum(x*x for x in A)))
print(max(abs(x) for x in A))
