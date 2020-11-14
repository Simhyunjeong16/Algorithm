n, m = map(int, input().split())
lst = [i+1 for i in range(n)]

for _ in range(m):
    x, y = map(int, input().split())
    
    if x == y: continue
    
    lst[x-1], lst[y-1] = lst[y-1], lst[x-1] #swap
    
# for i in lst:
#     print(i, end=' ')

print(*lst)
