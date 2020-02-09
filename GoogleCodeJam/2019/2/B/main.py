import sys

def dbg(*args, **kwargs):
    # return
    print(*args, file=sys.stderr, **kwargs)

T = int(input())

dbg(T)

for t in range(T):
    seen = []
    for d in range(100):
        day = int(input())
        if day <= 19:
            print(day, 100)
        elif day == 100:
            print(20, 100)
        else:
            # ans.append(day % 19 + 1)
            print(day % 19 + 1, day)
    # dbg(ans)

