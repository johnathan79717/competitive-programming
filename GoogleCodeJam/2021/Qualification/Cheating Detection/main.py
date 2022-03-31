import math
T = int(input())

def inv_f(y):
    # print(y)
    y = min(max(y, 1), 99)
    return -math.log(100 / y - 1)

for t in range(T):
    P = int(input())
    A = [[int(x) for x in input()] for i in range(100)]

    Q = [inv_f(sum(A[j][i] for j in range(100))) for i in range(10000)]
    # print(Q)

    def solve(y):
        def mse(m):
            return sum(1 / (1 + math.exp(Q[i] - m)) - y[i] for i in range(10000))
        lb, ub = -3, 3
        for k in range(10):
            m1 = (2 * lb + ub) / 3
            m2 = (lb + ub * 2) / 3
            if mse(m1) < mse(m2):
                ub = m2
            else:
                lb = m1
        return mse(lb)
    errors = [solve(A[i]) for i in range(100)]
    print('Case #{}: {}'.format(t+1, errors.index(min(errors)) + 1))
