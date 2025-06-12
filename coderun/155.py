_ = int(input())
unique, other = set(), set() 
for num in list(map(int, input().split())):
    if num in unique:
        unique.remove(num)
        other.add(num)
    elif num not in other:
        unique.add(num)

print(len(unique))
