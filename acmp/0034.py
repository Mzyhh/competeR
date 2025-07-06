n, k = map(int, input().split())
code = input()
unique = set()
for i in range(len(code) - k + 1):
    if code[i:i + k] in unique:
        print("YES")
        break
    unique.add(code[i:i + k])
else:
    print("NO")
