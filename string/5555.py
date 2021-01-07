find = input()
n = int(input())
answer = 0

for _ in range(n):
    r = input()
    
    if r.count(find) > 0:
        answer += 1
    
    else: #한칸씩 뒤로 밀면서 반복
        
        size = len(r)
        for _ in range(size):
            r = r[1 : size] + r[0]
            
            if r.count(find) > 0:
                answer += 1
                break
            
print(answer)
