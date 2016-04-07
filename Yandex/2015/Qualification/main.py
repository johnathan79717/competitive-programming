request = input().split()
input()
dictionary = set(input().split())

for r in request:
    if r not in dictionary:
        print('Misspell')
        break
else:
    print('Correct')