s = str(input())

cnt = [0 for _ in range(26)]

for i in s:
    cnt[ord(i) - 65] += 1 #A=65, ord = 특정한 한 문자를 아스키 코드 값으로 변환

odd = 0 #1개만 나와야 함
odd_a = ""
a = ""

for i in range(26):
    if cnt[i] % 2 == 1:# 홀수
        odd += 1
        odd_a += chr(i+65)#아스키 코드 값을 문자로 변환해주는 함수
    
    a += chr(i+65) * (cnt[i] // 2)
    

if odd > 1:
    print("I'm Sorry Hansoo")
else:
    print(a + odd_a + a[::-1])
    