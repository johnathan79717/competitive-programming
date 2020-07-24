from collections import Counter

T = int(input())

for t in range(T):
    print('Case #{}: '.format(t+1), end='')
    U = int(input())
    c = Counter()
    all = set()
    for i in range(10000):
        Q, R = input().split()
        all = all.union(R)
        c[R[0]] += 1
    most_common = ''.join(x[0] for x in c.most_common())
    # print(most_common, all)
    zero = [x for x in all if x not in most_common][0]
    print(zero + most_common)
