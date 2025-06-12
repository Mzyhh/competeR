N, M = map(int, input().split())
table = []
for i in range(N):
    table += [list(map(int, input().split()))]
    for j in range(M):
        if i == 0 and j == 0:
            continue
        if i == 0:
            table[i][j] += table[i][j - 1]
        elif j == 0:
            table[i][j] += table[i - 1][j]
        else:
            table[i][j] += max(table[i - 1][j], table[i][j - 1])

# way reconstruction
i, j = N - 1, M - 1
way = ""
for waylen in range(N + M - 2, 0, -1):
    if i == 0:
        way = "R " * waylen + way
        break
    if j == 0:
        way = "D " * waylen + way
        break
    if table[i - 1][j] > table[i][j - 1]:
        way = "D " + way
        i -= 1
    else:
        way = "R " + way
        j -= 1

print(table[N - 1][M - 1])
print(way)
