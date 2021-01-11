n = int(input())
file = dict()

for _ in range(n):
    f = list(map(str, input().split('.')))

    if f[1] not in file:
        file[f[1]] = 1
    else:
        file[f[1]] += 1
        
for k, v in sorted(file.items()):
    print(k, v)
