T = int(input())

def shuffle(d, a, b):
    return d[a:a+b] + d[0:a] + d[a+b:]

for t in range(T):
    print('Case #{}: '.format(t+1), end='')

    R, S = (int(x) for x in input().split())

    initial = ''.join(str(i) * S for i in range(1, R+1))
    target = ''.join(str(i) for i in range(1, R+1)) * S

    # print(initial, target)

    L = R*S

    last_move = {}
    last_move[initial] = None

    def bfs():
        q = [initial]

        while True:
            # print(len(last_move))
            d = q[0]
            q = q[1:]

            # print(d)

            for a in range(1, L):
                for b in range(1, L - a):
                    dd = shuffle(d, a, b)
                    if dd not in last_move:
                        last_move[dd] = (b, a)
                        q.append(dd)
                    if dd == target:
                        return

    bfs()
  
    ans = []
    while target != initial:
        a, b = last_move[target]
        target = shuffle(target, a, b)
        ans.append((a, b))
  
    print(len(ans))
    for line in ans:
        print(' '.join(str(i) for i in line))
