import random

def rand():
    return random.randint(-10, 10)

T = 1000
print(T)

for t in range(T):
    p, q, r = rand(), rand(), rand()

    print(p, q, r)

    def f(p, q, r):
        op = random.randrange(2)
        d = rand()
        pos = random.randrange(8)

        if op == 0:
            while d == 0:
                d = rand()
            return (p + (d if pos & 1 else 0), q + (d if pos & 2 else 0), r + (d if pos & 4 else 0))
        else:
            while d == 1:
                d = rand()
            return (p * (d if pos & 1 else 1), q * (d if pos & 2 else 1), r * (d if pos & 4 else 1))

    for i in range(2):
        p, q, r = f(p, q, r)

    print(p, q, r)
