import heapq

n = int(input())
h = []

for i in map(int, input().split()): #우선 맨 처음 n개의 배열로 만들어주기
    heapq.heappush(h, i)

for _ in range(1, n):
    
    for i in map(int, input().split()):
        heapq.heappush(h, i)
        heapq.heappop(h) #가장 작은 원소 삭제
    
print(h[0])
