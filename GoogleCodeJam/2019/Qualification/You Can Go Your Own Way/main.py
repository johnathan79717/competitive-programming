def other_move(move):
    if move == 'S':
        return 'E'
    else:
        return 'S'

T = int(input())

for t in range(T):
    print('Case #{}: '.format(t+1), end='')
    N = int(input())
    path = input()
    ans = ''.join([other_move(x) for x in path])
    print(ans)

