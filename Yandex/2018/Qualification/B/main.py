n = int(input())

seqs = [ input().split() for _ in range(n*2) ]
a = [ [0] * n for _ in range(n) ]

for i in range(n*2):
    for j in range(i):
        if seqs[i][0] == seqs[j][0]:
            for k in range(n):
                a[0][k] = seqs[j][k]
                a[k][0] = seqs[i][k]
            for k in range(n*2):
                if k == i or k == j:
                    continue
                for l in range(n):
                    if a[0][l] == seqs[k][0]:
                        for m in range(n):
                            a[m][l] = seqs[k][m]
                    if a[l][0] == seqs[k][0]:
                        for m in range(n):
                            a[l][m] = seqs[k][m]

print(' '.join(' '.join(row) for row in a))
