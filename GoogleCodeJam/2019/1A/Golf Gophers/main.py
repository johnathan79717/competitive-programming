import sys

def dbg(*args, **kwargs):
    return
    print(*args, file=sys.stderr, **kwargs)

ps = [5, 7, 9, 11, 13, 16, 17]
T, N, M = (int(x) for x in input().split())

dbg(T, N, M)

for t in range(T):
    results = {}
    for p in ps:
        print(' '.join([str(p)] * 18))
        s = sum([int(x) for x in input().split()])
        dbg(s)
        results[p] = s % p
    for i in range(1, M+1):
        for p in results:
            if i % p != results[p]:
                break
        else:
            print(i)
            break
    s = int(input())
    if s != 1: exit(0)
