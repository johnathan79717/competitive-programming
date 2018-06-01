org = input().split()
N = int(input())
for _ in range(N):
    cnt = 0
    for num in input().split():
        if num in org:
            cnt += 1
    print('Lucky' if cnt >= 3 else 'Unlucky')
