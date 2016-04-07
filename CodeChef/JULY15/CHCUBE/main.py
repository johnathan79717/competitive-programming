from itertools import product

for t in range(int(input())):
    color = input().split()

    fb, lr, tb = color[:2], color[2:-2], color[-2:]

    for a, b, c in product(fb, lr, tb):
        if a == b == c:
            print("YES")
            break
    else:
        print("NO")