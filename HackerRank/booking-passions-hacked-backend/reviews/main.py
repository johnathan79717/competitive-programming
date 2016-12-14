from collections import defaultdict
import re

n, m = map(int, input().split())
passions = []
for i in range(n):
    passions.append(input().lower())

reviews = []
for i in range(m):
    r = {}
    r['id'], r['t'] = map(int, input().split())
    r['body'] = input().lower()
    reviews.append(r)

for passion in passions:
    scores = defaultdict(int)
    # print(passion)
    for r in reviews:
        # print(r)
        b = r['body']
        if passion in b:
            score = 20
            if len(b) >= 100:
                score += 10
            if 1465920000 <= r['t'] < 1468598400:
                score += 10
            scores[r['id']] += score
    if len(scores):
        ans = (0, 0)
        for id in scores:
            ans = min(ans, (-scores[id], id))
        print(ans[1])
    else:
        print(-1)
