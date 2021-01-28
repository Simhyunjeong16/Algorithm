from itertools import combinations

n = int(input())
arr = [list(map(int, input().split())) for _ in range(n)]
answer = 1000000001
taste = []

for i in range(1, n+1):
    taste.append(combinations(arr, i)) #i의 개수
    
    
for t in taste:
    for k in t:
        s = 1 #곱셈이니까
        b = 0 #덧셈이니까
        
        for i in k:
            s *= i[0]
            b += i[1]
            
        answer = min(answer, abs(s - b))
    
print(answer)
