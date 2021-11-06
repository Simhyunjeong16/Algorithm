# 유클리드 호제법
t = int(input())

def gcd(a, b):
	while b > 0:
		t = a % b
		a = b
		b = t
	
	return a

def gcf(a, b): #최대공약수
	if b == 0:
		return a
	else:
		return gcd(b, a%b)	

def lcm(a, b): #최소공배수
	return (a * b) // gcf(a, b)
	
for _ in range(t):
	a, b = map(int, input().split())
	print(lcm(a, b),gcf(a, b))