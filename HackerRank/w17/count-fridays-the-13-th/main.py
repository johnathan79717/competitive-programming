import datetime
T = int(input())
for t in range(T):
    D1, M1, Y1, D2, M2, Y2 = map(int, input().split())
    d1 = datetime.date(Y1, M1, D1)
    d2 = datetime.date(Y2, M2, D2)
    t = datetime.timedelta(days=1)
    ans = 0
    while d1 <= d2:
        if d2.day == 13 and d2.weekday() == 4:
            ans += 1
        d2 -= t
    print(ans)
