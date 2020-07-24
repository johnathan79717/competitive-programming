from collections import Counter

for t in range(int(input())):
    N = int(input())
    S = input()
    for a, b in Counter(S).items():
        # print(b)
        if b % 2:
            print('NO')
            break
    else:
        print('YES')
