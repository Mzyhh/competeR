N = int(input())
sh, si, sj = -1, -1, -1
cave = [[[] for _ in range(N)] for _ in range(N)]
for h in range(N):
    input()
    for i in range(N):
        row = input()
        for j in range(N):
            if row[j] == 'S':
                sh, si, sj = h, i, j
            cave[h][i].append(0 if row[j] == '#' else 1)

q = [(sh, si, sj, 0)]
visited = set()
while q:
    h, i, j, l = q.pop(0)
    if h < 0 or i < 0 or j < 0 or h >= N or i >= N or j >= N:
        continue
    if cave[h][i][j] == 0:
        continue
    if (h, i, j) in visited:
        continue
    visited.add((h, i, j))
    if h == 0:
        print(l)
        break
    for dh, di, dj in [(1, 0, 0), (0, 1, 0), (0, 0, 1)]:
        q.append((h + dh, i + di, j + dj, l + 1))
        q.append((h - dh, i - di, j - dj, l + 1))
