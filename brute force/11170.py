t = int(input())

for i in range(t):
    n, m = map(int, input().split())
    cnt = 0

    for i in range(n, m+1):
        s = str(i)
        cnt += s.count('0') #문자열에서 0의 개수 세기
    
    print(cnt)
