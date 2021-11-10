n, k = map(int, input().split())
cnt = 0

def Calc(b):
	for a in b:
		if a == str(k):
			return True

for i in range(n+1):
	for j in range(60):
		for x in range(60):
			if i < 10: s1 = '0' + str(i)
			else: s1 = str(i)

			if j < 10: s2 = '0' + str(j)	
			else: s2 = str(j)
				
			if x < 10: s3 = '0' + str(x)
			else: s3 = str(x)
				
			s = s1 + s2 + s3
			if Calc(s): cnt += 1

print(cnt)			