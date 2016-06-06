k = 997

print(997*997)
for i in range(997):
    for j in range(997):
        x = 997*i
        y = 997*j
        if i % 2 == 1:
            x += 996
        print(x, y)
