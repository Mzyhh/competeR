n, q = map(float, input().split())
n = int(n)
q = round(1000*q)**2
for i in range(n):
    x0, y0, x, y = map(int, input().split())
    if q * (x0**2 + y0**2) < 1000000 * (x**2 + y**2):
        print("No")
        break
else:
    print("Yes")
