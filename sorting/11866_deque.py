from collections import deque

n, k = map(int, input().split())
dq = deque()
answer = []

for i in range(1, n+1):
    dq.append(i)
    

while dq:
    for i in range(0, k-1):
        dq.append(dq[0])
        dq.popleft()
    
    answer.append(dq[0])
    dq.popleft()
    
print('<' + ', '.join(map(str, answer)) + '>')
