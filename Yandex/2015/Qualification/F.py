M = int(input())

# road = []
# for m in range(M):
#     road.append([int(x) for x in input().split()])
road = [[int(x) for x in input().split()] for m in range(M)]

N = int(input())
a = [int(x) for x in input().split()]

d = [0] * M;
for i in range(N):
    d[a[i]-1] += 1

for i in range(M):
    if d[i] < road[i][0]:
        print("Green")
    elif d[i] > road[i][1]:
        print("Red")
    else:
        print("Orange")
