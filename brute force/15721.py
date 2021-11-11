a = int(input())
t = int(input())
guho = int(input()) #뻔 0, 데기 1

lst = list()
n = 1 #회차
while(1):
	b = [0, 1, 0, 1]
	lst += b

	for _ in range(n+1):
		lst.append(0)
	for _ in range(n+1):
		lst.append(1)

	if lst.count(guho) >= t:
		break
	
	n += 1

pos = 0
cnt = 0
for i in lst:
	if pos == a: #원을 다 돌아서 다시 차례 리셋
		pos = 0 
		
	if i == guho:
		cnt += 1

	if cnt == t:
		break
		
	pos += 1
	
print(pos)
