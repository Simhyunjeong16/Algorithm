n = int(input())
s_taste = []
b_taste = []
answer = 1000000001
chk = [False] * n

def DFS(i, ss, bb):
    global answer
    
    if answer > abs(ss - bb):
        answer = abs(ss - bb)
    
    for j in range(i+1, n):
        if chk[j] == True: continue
        
        chk[j] = True
        DFS(j, ss * s_taste[j], bb + b_taste[j])
        chk[j] = False
    
for _ in range(n):
    s, b = map(int, input().split()) #s신맛, b쓴맛
    s_taste.append(s)
    b_taste.append(b)
    
for i in range(n):
    chk[i] = True
    DFS(i, s_taste[i], b_taste[i])
    
print(answer)
