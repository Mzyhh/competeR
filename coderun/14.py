mat = [list(map(int, input().split())) for _ in range(int(input()))]
u, v = map(lambda x: int(x) - 1, input().split())
q = [(u, 0)]
visited = set()
while q:
    u, l = q.pop(0)
    if u == v:
        print(l)
        break
    for i in range(len(mat)):
        if i in visited or mat[u][i] == 0:
            continue
        visited.add(i)
        q.append((i, l + 1))
else:
    print(-1)
